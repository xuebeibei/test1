#include "drugallot.h"
#include <QtGui>
#include "connectsql.h"
#include "clinicdrugfilter.h"
#include "package.h"

static int icount_sale;
static int icount_store;
extern ConnectSql sql;
DrugAllot::DrugAllot(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	initUI();
	ui.tableWidget_SaleAllot->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
	ui.tableWidget_SaleAllot->setStyleSheet("QTableWidget{border: 1px solid gray;	background-color: transparent;	selection-color: grey;}");
	ui.tableWidget_SaleAllot->horizontalHeader()->setStyleSheet("QHeaderView::section {background-color:white;color: black;padding-left: 4px;border: 1px solid #6c6c6c;};"
		"color: white;padding-left: 4px;border: 1px solid #6c6c6c;}"
		"QHeaderView::section:checked{background-color: white;color: black;}");	

	ui.tableWidget_StoreAllot->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
	ui.tableWidget_StoreAllot->setStyleSheet("QTableWidget{border: 1px solid gray;	background-color: transparent;	selection-color: grey;}");
	ui.tableWidget_StoreAllot->horizontalHeader()->setStyleSheet("QHeaderView::section {background-color:white;color: black;padding-left: 4px;border: 1px solid #6c6c6c;};"
		"color: white;padding-left: 4px;border: 1px solid #6c6c6c;}"
		"QHeaderView::section:checked{background-color: white;color: black;}");	

	ui.tableWidget_SaleAllot->installEventFilter(this);//注册事件过滤器
	ui.tableWidget_StoreAllot->installEventFilter(this);//注册事件过滤器
	
	list_widget = new QListWidget(this);
	list_widget->setWindowFlags(Qt::FramelessWindowHint);
	list_widget->close();
	installEventFilter(list_widget);

	list_widget2 = new QListWidget(this);
	list_widget2->setWindowFlags(Qt::FramelessWindowHint);
	list_widget2->close();
	installEventFilter(list_widget2);

	connect(ui.tableWidget_SaleAllot,SIGNAL(cellChanged(int,int)),this,SLOT(getItem_Sale(int,int)));
	connect(ui.tableWidget_StoreAllot,SIGNAL(cellChanged(int,int)),this,SLOT(getItem_Store(int,int)));
	//connect(ui.radioButton_Sellout,SIGNAL(clicked()),this,SLOT());
	connect(ui.lineEdit_Paid,SIGNAL(textChanged(const QString &)),this,SLOT(pay(const QString &)));
}

void DrugAllot::on_radioButton_Sellout_clicked()
{
	if(ui.radioButton_Sellout->isChecked() && !ui.radioButton_Back->isChecked())
	{
		ui.label_14->setText(QObject::tr("本次应付："));
		ui.label_15->setText(QObject::tr("实际付款："));
	}

	if(!ui.radioButton_Sellout->isChecked() && ui.radioButton_Back->isChecked())
	{
		ui.label_14->setText(QObject::tr("本次应收："));
		ui.label_15->setText(QObject::tr("实际收取："));
	}
	ui.tableWidget_SaleAllot->setRowCount(0);
	ui.tableWidget_SaleAllot->clearContents();
	ui.tableWidget_SaleAllot->insertRow(0);
	ui.lineEdit_Payable->setText("0");
	ui.lineEdit_Paid->setText("0");
	ui.lineEdit_Debt->setText("0");	
		
}
void DrugAllot::on_radioButton_Back_clicked()
{
	if(ui.radioButton_Sellout->isChecked() && !ui.radioButton_Back->isChecked())
	{
		ui.label_14->setText(QObject::tr("本次应付："));
		ui.label_15->setText(QObject::tr("实际付款："));
	}

	if(!ui.radioButton_Sellout->isChecked() && ui.radioButton_Back->isChecked())
	{
		ui.label_14->setText(QObject::tr("本次应收："));
		ui.label_15->setText(QObject::tr("实际收取："));
	}

	ui.tableWidget_SaleAllot->setRowCount(0);
	ui.tableWidget_SaleAllot->clearContents();
	ui.tableWidget_SaleAllot->insertRow(0);
	ui.lineEdit_Payable->setText("0");
	ui.lineEdit_Paid->setText("0");
	ui.lineEdit_Debt->setText("0");		
}

void DrugAllot::on_radioButton_ToYF_clicked()
{
	//int rows = ui.tableWidget_SaleAllot->model()->rowCount();   //行总数
	ui.tableWidget_SaleAllot->setRowCount(0);
	ui.tableWidget_SaleAllot->clearContents();
	ui.tableWidget_SaleAllot->insertRow(0);
}

void DrugAllot::on_radioButton_ToYK_clicked()
{
//	int rows = ui.tableWidget_SaleAllot->model()->rowCount();   //行总数
	ui.tableWidget_SaleAllot->setRowCount(0);
	ui.tableWidget_SaleAllot->clearContents();
	ui.tableWidget_SaleAllot->insertRow(0);
}

void DrugAllot::initUI()
{
	iRow_Sale=0;
	iRow_Store=0;
	QSqlQuery query(*sql.db);		
	QDateTime current_date_time = QDateTime::currentDateTime();
	ui.dateTimeEdit_Date_Sale->setDateTime(current_date_time);
	ui.dateTimeEdit_Date_Store->setDateTime(current_date_time);
	ui.saveButton->setEnabled(false);
	ui.saveButton_2->setEnabled(false);
	ui.editButton->setEnabled(false);
	ui.editButton_2->setEnabled(false);
	ui.discardButton->setEnabled(false);
	ui.discardButton_2->setEnabled(false);
	ui.deleteButton->setEnabled(false);
	ui.deleteButton_2->setEnabled(false);
	ui.tableWidget_StoreAllot->setEnabled(false);
	ui.tableWidget_SaleAllot->setEnabled(false);
	ui.addRowButton->setEnabled(false);
	ui.deleteRowButton->setEnabled(false);
	ui.addRowButton_2->setEnabled(false);
	ui.deleteRowButton_2->setEnabled(false);

	QTextCodec::setCodecForTr(QTextCodec::codecForName("gb18030"));
	//ui.tableWidget_SaleAllot->setSelectionBehavior(QAbstractItemView::SelectRows);  //整行选中的方式
	//ui.tableWidget_StoreAllot->setSelectionBehavior(QAbstractItemView::SelectRows);  //整行选中的方式

	//ui.tableWidget_SaleAllot->setEditTriggers(QAbstractItemView::AllEditTriggers);
	ui.tableWidget_SaleAllot->setAlternatingRowColors(true); 

	//ui.tableWidget_StoreAllot->setEditTriggers(QAbstractItemView::AllEditTriggers);
	ui.tableWidget_StoreAllot->setAlternatingRowColors(true); 

	query.exec("select * from sys_customer");
	QStringList list;
	while(query.next())
	{
		QString str = query.value(2).toString();
		list.append(str);
	}
	ui.comboBox_Customer->addItems(list);

	ui.lineEdit_Payable->setText("0");
	ui.lineEdit_Paid->setText("0");
	ui.lineEdit_Debt->setText("0");
	int rows1 = ui.tableWidget_SaleAllot->model()->rowCount();   //行总数
	int rows2 = ui.tableWidget_StoreAllot->model()->rowCount();   //行总数
	iRow_Sale=rows1-1;
	iRow_Store=rows2-1;

	ui.tableWidget_SaleAllot->setRowCount(0);
	ui.tableWidget_SaleAllot->clearContents();
	ui.tableWidget_SaleAllot->insertRow(0);
	
	ui.tableWidget_StoreAllot->setRowCount(0);
	ui.tableWidget_StoreAllot->clearContents();
	ui.tableWidget_StoreAllot->insertRow(0);
}

DrugAllot::~DrugAllot()
{

}
double DrugAllot::TotalPrice_sale()
{
	int i;
	int rows = ui.tableWidget_SaleAllot->model()->rowCount();
	double icurrentamount = 0.0;

	for(i=0;i<rows;i++)
	{
		if(ui.tableWidget_SaleAllot->item(i,6)==NULL||(ui.tableWidget_SaleAllot->item(i,6)&& ui.tableWidget_SaleAllot->item(i,6)->text()==tr("")))
			continue;
		int icount = ui.tableWidget_SaleAllot->item(i,6)->text().toInt();
		double unitprice = ui.tableWidget_SaleAllot->item(i,6+2)->text().toDouble();
		double amount = icount*unitprice;
		QString stramount = QString::number(amount);
		icurrentamount+=amount;
		
	}
	return icurrentamount;
}
void DrugAllot::on_addRowButton_clicked()
{
	//表格增加一行
	int rows = ui.tableWidget_SaleAllot->model()->rowCount();   //行总数
	ui.tableWidget_SaleAllot->insertRow(rows);
	iRow_Sale=rows;
}
void DrugAllot::on_addRowButton_2_clicked()
{
	//表格增加一行
	int rows = ui.tableWidget_StoreAllot->model()->rowCount();   //行总数
	ui.tableWidget_StoreAllot->insertRow(rows);
	iRow_Store=rows;
}
void DrugAllot::on_deleteRowButton_clicked()
{
	//表格增加一行
	int rows = ui.tableWidget_SaleAllot->currentRow(); //行总数
	if(ui.tableWidget_SaleAllot->item(rows,7)==NULL||(ui.tableWidget_SaleAllot->item(rows,7)&& ui.tableWidget_SaleAllot->item(rows,7)->text()==tr("")))
	{	
		ui.tableWidget_SaleAllot->removeRow(rows);
		iRow_Sale--;
		return;
	}
	int icount = ui.tableWidget_SaleAllot->item(rows,7)->text().toInt();
	double unitprice = ui.tableWidget_SaleAllot->item(rows,7+1)->text().toDouble();
	double amount = icount*unitprice;
	QString stramount = QString::number(amount);
	
	double icurrentamount = ui.lineEdit_Payable->text().toInt();
	if(ui.radioButton_Sellout->isChecked() && !ui.radioButton_Back->isChecked())
		icurrentamount-=amount;
	if(!ui.radioButton_Sellout->isChecked() && ui.radioButton_Back->isChecked())
		icurrentamount+=amount;
	QString strcurrentamount = QString::number(icurrentamount);
		 
		//累加
	ui.lineEdit_Payable->setText(strcurrentamount);
		
	double iamount = ui.lineEdit_Paid->text().toInt();
	if(ui.radioButton_Sellout->isChecked() && !ui.radioButton_Back->isChecked())
		iamount = iamount - icurrentamount;
	if(!ui.radioButton_Sellout->isChecked() && ui.radioButton_Back->isChecked())
		iamount = iamount + icurrentamount;
	strcurrentamount = QString::number(iamount);
	ui.lineEdit_Debt->setText(strcurrentamount);

	ui.tableWidget_SaleAllot->removeRow(rows);
	iRow_Sale--;
}
void DrugAllot::on_deleteRowButton_2_clicked()
{

	//表格增加一行
	int rows = ui.tableWidget_StoreAllot->currentRow(); //行总数
	ui.tableWidget_StoreAllot->removeRow(rows);
	iRow_Store--;
}
void DrugAllot::SetEdit(bool IsEdit)
{
	if (IsEdit==true)
	{
		ui.lineEdit_SaleNo->setEnabled(true);
		ui.comboBox_Customer->setEnabled(true);
		ui.tableWidget_SaleAllot->setEnabled(true);
		ui.lineEdit_Payable->setEnabled(true);
		ui.lineEdit_Paid->setEnabled(true);
		ui.lineEdit_Debt->setEnabled(true);

		ui.lineEdit_StoreAllotNo->setEnabled(true);
		ui.tableWidget_StoreAllot->setEnabled(true);
		ui.radioButton_Sellout->setEnabled(true);
		ui.radioButton_Back->setEnabled(true);
		ui.dateTimeEdit_Date_Sale->setEnabled(true);
		ui.dateTimeEdit_Date_Store->setEnabled(true);
	}
	else
	{
		ui.lineEdit_SaleNo->setEnabled(false);
		ui.comboBox_Customer->setEnabled(false);
		ui.tableWidget_SaleAllot->setEnabled(false);
		ui.lineEdit_Payable->setEnabled(false);
		ui.lineEdit_Paid->setEnabled(false);
		ui.lineEdit_Debt->setEnabled(false);

		ui.lineEdit_StoreAllotNo->setEnabled(false);
		ui.tableWidget_StoreAllot->setEnabled(false);
		ui.radioButton_Sellout->setEnabled(false);
		ui.radioButton_Back->setEnabled(false);
		ui.dateTimeEdit_Date_Sale->setEnabled(false);
		ui.dateTimeEdit_Date_Store->setEnabled(false);
	}
}
void DrugAllot::on_addButton_clicked()
{
	SetEdit(true);
	ui.saveButton->setEnabled(true);
	ui.discardButton->setEnabled(true);
	ui.editButton->setEnabled(false);
	ui.deleteButton->setEnabled(false);
	ui.addRowButton->setEnabled(true);
	ui.deleteRowButton->setEnabled(true);

	ui.tableWidget_SaleAllot->setRowCount(0);
	ui.tableWidget_SaleAllot->clearContents();
	ui.tableWidget_SaleAllot->insertRow(0);
	iRow_Sale = 0;
	icount_sale = 0;
	//ui.tableWidget_SaleAllot->setEditTriggers(QAbstractItemView::DoubleClicked);
	int isheetcount=PublicInfoSheetNo_Sale();
	isheetcount++;
	QString strSheetNo= "XSDB"+QString::number(isheetcount, 10);
	ui.lineEdit_SaleNo->setText(strSheetNo);
	ui.lineEdit_Payable->setText("0");
	ui.lineEdit_Paid->setText("0");
	ui.lineEdit_Debt->setText("0");
}
void DrugAllot::on_addButton_2_clicked()
{
	SetEdit(true);
	ui.saveButton_2->setEnabled(true);
	ui.discardButton_2->setEnabled(true);
	ui.editButton_2->setEnabled(false);
	ui.deleteButton_2->setEnabled(false);
	ui.addRowButton_2->setEnabled(true);
	ui.deleteRowButton_2->setEnabled(true);
	ui.radioButton_ToYF->setEnabled(true);
	ui.radioButton_ToYK->setEnabled(true);
	ui.tableWidget_StoreAllot->setRowCount(0);
	ui.tableWidget_StoreAllot->clearContents();
	ui.tableWidget_StoreAllot->insertRow(0);
	iRow_Store = 0;
	icount_store = 0;
	//ui.tableWidget_StoreAllot->setEditTriggers(QAbstractItemView::DoubleClicked);
	int isheetcount=PublicInfoSheetNo_Store();
	isheetcount++;
	QString strSheetNo= "CKDB"+QString::number(isheetcount, 10);
	ui.lineEdit_StoreAllotNo->setText(strSheetNo);
}
int  DrugAllot::PublicInfoSheetNo_Sale()
{
	QSqlQuery query(*sql.db);		
	query.exec("select * from yk_saleallot_public_info");
	int isheetcount=0;
	while(query.next())
	{ 
		isheetcount++;
	}
	return isheetcount;
}
int  DrugAllot::SheetNo_Sale()
{
	QSqlQuery query(*sql.db);		
	query.exec("select * from yk_saleallot");
	int isheetcount=0;
	while(query.next())
	{ 
		isheetcount++;
	}
	return isheetcount;
}
int  DrugAllot::PublicInfoSheetNo_Store()
{
	QSqlQuery query(*sql.db);		
	query.exec("select * from yk_warehouseallot_public_info");
	int isheetcount=0;
	while(query.next())
	{ 
		isheetcount++;
	}
	return isheetcount;
}
int  DrugAllot::SheetNo_Store()
{
	QSqlQuery query(*sql.db);		
	query.exec("select * from yk_warehouseallot");
	int isheetcount=0;
	while(query.next())
	{ 
		isheetcount++;
	}
	return isheetcount;
}
void DrugAllot::on_deleteButton_clicked()//存在问题
{

	int i=0,amount;
	int rows = ui.tableWidget_SaleAllot->model()->rowCount();   //行总数
		
	QMessageBox box(QMessageBox::Warning,QString::fromLocal8Bit("警告"),QString::fromLocal8Bit("确认删除本单？"));
	box.setStandardButtons (QMessageBox::Ok|QMessageBox::Cancel);
	box.setButtonText (QMessageBox::Ok,QString::fromLocal8Bit("确 定"));
	box.setButtonText (QMessageBox::Cancel,QString::fromLocal8Bit("取 消"));
	if(box.exec()==QMessageBox::Ok)
	{

		QSqlQuery query(*sql.db);		
		QString strSheetNo=ui.lineEdit_SaleNo->text();
		QString strsql = "delete from yk_saleallot where sheetno ='"+strSheetNo+"'"; //where ID > 1
		query.exec(strsql);
		strsql = "delete from yk_saleallot_public_info where sheetno ='"+strSheetNo+"'"; //where ID > 1
		query.exec(strsql);
	

		ui.lineEdit_SaleNo->setText("");
		ui.lineEdit_Payable->setText("");
		ui.tableWidget_SaleAllot->clearContents();
		ui.tableWidget_SaleAllot->setRowCount(0);
		ui.tableWidget_SaleAllot->clearContents();
		ui.tableWidget_SaleAllot->insertRow(0);
	}
}
void DrugAllot::on_deleteButton_2_clicked()//存在问题
{
	QMessageBox box(QMessageBox::Warning,QString::fromLocal8Bit("警告"),QString::fromLocal8Bit("确认删除本单？"));
	box.setStandardButtons (QMessageBox::Ok|QMessageBox::Cancel);
	box.setButtonText (QMessageBox::Ok,QString::fromLocal8Bit("确 定"));
	box.setButtonText (QMessageBox::Cancel,QString::fromLocal8Bit("取 消"));
	if(box.exec()==QMessageBox::Ok)
	{
		QSqlQuery query(*sql.db);
		QString strSheetNo=ui.lineEdit_StoreAllotNo->text();
		QString strsql = "delete from yk_warehouseallot where sheetno ='"+strSheetNo+"'"; //where ID > 1
		query.exec(strsql);
		strsql = "delete from yk_warehouseallot_public_info where sheetno ='"+strSheetNo+"'"; //where ID > 1
		query.exec(strsql);
	
		//QSqlQuery query(*sql.db);		
		//QString strSheetNo=ui.lineEdit_StoreAllotNo->text();
		//QString strsql = "delete from yk_warehouseallot where sheetno ='"+strSheetNo+"'"; //where ID > 1
		//query.exec(strsql);

		//strsql = "delete from yk_warehouseallot where sheetno ='"+strSheetNo+"'"; //where ID > 1
		//query.exec(strsql);
		ui.lineEdit_StoreAllotNo->setText("");
		ui.tableWidget_StoreAllot->clearContents();
		ui.tableWidget_StoreAllot->setRowCount(0);
		ui.tableWidget_StoreAllot->clearContents();
		ui.tableWidget_StoreAllot->insertRow(0);
	}
}
void DrugAllot::on_saveButton_clicked()
{
	static int iFlag;
	int i=0;
	int amount;
	double unitprice;
	int rows = ui.tableWidget_SaleAllot->model()->rowCount();   //行总数
	QString str2;
	char strtemp[255]={0};

	QString str = str.fromLocal8Bit("警告");
	unitprice = ui.lineEdit_Debt->text().toDouble();
	if(unitprice<0)
	{
		/*if(ui.radioButton_Sellout->isChecked() && !ui.radioButton_Back->isChecked())
		str2 = str.fromLocal8Bit("付款金额不足，请核对！");
		if(!ui.radioButton_Sellout->isChecked() && ui.radioButton_Back->isChecked())
		str2 = str.fromLocal8Bit("收款金额不足，请核对！");
		QMessageBox::warning(this,str,str2,QMessageBox::Ok);
		return;*/
	}
	
	if(!ui.tableWidget_SaleAllot->isEnabled())
	{	
		QMessageBox box(QMessageBox::Warning,QString::fromLocal8Bit("警告"),QString::fromLocal8Bit("已保存过"));
		box.setStandardButtons (QMessageBox::Ok);
		box.setButtonText (QMessageBox::Ok,QString::fromLocal8Bit("确 定"));
		box.exec();
		return;
	}

	QSqlQuery query(*sql.db);		
	QString strSheetNo=ui.lineEdit_SaleNo->text();
	QString strsql = "select * from yk_saleallot where sheetno ='"+strSheetNo+"'"; //where ID > 1
	query.exec(strsql);
	int num = 0;
	QStringList list;
	int kucun2;
	while(query.next())
	{
		QString strTemp = query.value(8).toString();
		list.append(strTemp);
		num++;
	}
	
	//for(i=0;i<num;i++)
	//{
	//	QString strName = list[i];
	//	strsql = "select * from yk_saleallot where sheetno ='"+strSheetNo+"'and name ='"+strName+"'"; //where ID > 1
	//	query.exec(strsql);
	//	if(query.next())
	//	amount = query.value(13).toInt();	
	//	strsql= "select * from yk_inventory where name ='"+strName+"'";//;//where AbbrName = '"+strName+"'
	//	query.exec(strsql);
	//	int kucun;
	//	if(query.next())
	//		kucun = query.value(7).toInt();	
	//	kucun2 = kucun + amount;
	//	query.prepare("UPDATE yk_inventory SET count= ? WHERE name = '"+strName+"'");
	//	query.bindValue(0,kucun2);
	//	QString strTemp1 = QString::number(kucun2);
	//	ui.tableWidget_SaleAllot->setItem(i,7,new QTableWidgetItem(strTemp1));
	//	query.exec();	
	//}
	if(num>0)
	{
		strsql = "delete from yk_saleallot where sheetno ='"+strSheetNo+"'"; //where ID > 1
		query.exec(strsql);
		strsql = "delete from yk_saleallot_public_info where sheetno ='"+strSheetNo+"'"; //where ID > 1
		query.exec(strsql);
	}

	//QSqlQuery query(*sql.db);		
	//QString strSheetNo=ui.lineEdit_SaleNo->text();
	//QString strsql = "select * from yk_saleallot where sheetno ='"+strSheetNo+"'"; //where ID > 1
	//query.exec(strsql);
	//if(query.next())
	//{
	//	strsql = "delete from yk_saleallot where sheetno ='"+strSheetNo+"'"; //where ID > 1
	//	query.exec(strsql);
	//}
	//添加到收费单基本信息表中
	

	int isheetcount;
	isheetcount=PublicInfoSheetNo_Sale();
	isheetcount++;

	query.prepare("INSERT INTO yk_saleallot_public_info VALUES (?, ?, ?, ?, ?, ?, ?)");
	query.bindValue(0, isheetcount);
	query.bindValue(1, ui.lineEdit_SaleNo->text());
	query.bindValue(2, ui.dateTimeEdit_Date_Sale->dateTime());
	int iInputFlag;
	if(ui.radioButton_Sellout->isChecked() && !ui.radioButton_Back->isChecked())
		iInputFlag = 1;
	else 
		iInputFlag = 0;
	QString strTemp = QString::number(iInputFlag);
	query.bindValue(3, strTemp);
	strTemp = QString::number(1);
	query.bindValue(4, strTemp);
	query.bindValue(5, ui.comboBox_Customer->currentText());
	query.bindValue(6, ui.lineEdit_2->text());
	iFlag = query.exec();


	for (i=0;i< rows ;i++)
	{
		isheetcount=SheetNo_Sale();
		isheetcount++;
		if(ui.tableWidget_SaleAllot->item(i,6)==NULL||(ui.tableWidget_SaleAllot->item(i,6)&& ui.tableWidget_SaleAllot->item(i,6)->text()==tr("")))
		{
			sprintf(strtemp,"第%d行调拨数量为空，请核对！",i+1);
			str2 = str.fromLocal8Bit(strtemp);		
			QMessageBox box(QMessageBox::Warning,QString::fromLocal8Bit("警告"),str2);
			box.setStandardButtons (QMessageBox::Ok);
			box.setButtonText (QMessageBox::Ok,QString::fromLocal8Bit("确 定"));
			box.exec();
			return;
		}

		query.prepare("INSERT INTO yk_saleallot VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)");
		query.bindValue(0, isheetcount);
		query.bindValue(1, ui.lineEdit_SaleNo->text());
		query.bindValue(2, ui.dateTimeEdit_Date_Sale->dateTime());
		if(ui.radioButton_Sellout->isChecked() && !ui.radioButton_Back->isChecked())
			iInputFlag = 1;
		else 
			iInputFlag = 0;
		QString strTemp = QString::number(iInputFlag);
		query.bindValue(3, strTemp);
		strTemp = QString::number(1);
		query.bindValue(4, strTemp);
		query.bindValue(5, ui.comboBox_Customer->currentText());
		query.bindValue(6, ui.lineEdit_2->text());
		for (int j=0;j<6;j++)
		{
			if (ui.tableWidget_SaleAllot->item(i,j)!=NULL)
			{
				query.bindValue(7+j, ui.tableWidget_SaleAllot->item(i,j)->text());
			}
			else
			{
				query.bindValue(7+j, NULL);
			}
		}
		//if(ui.radioButton_Sellout->isChecked() && !ui.radioButton_Back->isChecked())
		//{
		//	amount = ui.tableWidget_SaleAllot->item(i,6)->text().toInt();
		//	unitprice = ui.tableWidget_SaleAllot->item(i,8)->text().toDouble();
		//}else
		//{
		//	amount = -ui.tableWidget_SaleAllot->item(i,6)->text().toInt();
		//	unitprice = -ui.tableWidget_SaleAllot->item(i,8)->text().toDouble();
		//}
		
		amount = ui.tableWidget_SaleAllot->item(i,6)->text().toInt();
		unitprice = ui.tableWidget_SaleAllot->item(i,8)->text().toDouble();

		query.bindValue(13, amount);
		query.bindValue(14, unitprice);
		unitprice = unitprice * amount;
		/*QString strprice= QString::number(unitprice);*/
		query.bindValue(15,unitprice);
		
		iFlag = query.exec();
	}

	for (i=0;i< rows ;i++)
	{	
		QString strName = ui.tableWidget_SaleAllot->item(i,1)->text();
		int kucun = ui.tableWidget_SaleAllot->item(i,7)->text().toInt();
		int kucun1=0;
	//	kucun1 = kucun - amount;
		if(ui.radioButton_Sellout->isChecked() && !ui.radioButton_Back->isChecked())
			kucun1 = kucun - amount;
		if(!ui.radioButton_Sellout->isChecked() && ui.radioButton_Back->isChecked())
			kucun1 = kucun + amount;
		QString strTemp1 = QString::number(kucun1);
		ui.tableWidget_SaleAllot->setItem(i,7,new QTableWidgetItem(strTemp1));

		QString strsql= "select * from yk_inventory where name ='"+strName+"'";//;//where AbbrName = '"+strName+"'
		query.exec(strsql);

		if(query.next())
		{
			query.prepare("UPDATE yk_inventory SET count= ? WHERE name = '"+strName+"'");
			query.bindValue(0,kucun1);
			iFlag = query.exec();
		}
		else
		{
			query.prepare("INSERT INTO yk_inventory VALUES (?, ?, ?, ?, ?, ?, ?, ?)");
			isheetcount=SheetNo_Sale();
			isheetcount ++;
			query.bindValue(0, isheetcount);
			query.bindValue(1, strName);
			query.bindValue(2, strName);
			query.bindValue(3, ui.tableWidget_SaleAllot->item(i,2)->text());
			query.bindValue(4, ui.tableWidget_SaleAllot->item(i,3)->text());
			query.bindValue(6, ui.tableWidget_SaleAllot->item(i,5)->text());
			query.bindValue(7, strTemp1);
			iFlag = query.exec();
			
		}
	}

		
	if(iFlag)
	{
		QString str = str.fromLocal8Bit("提示");
		QString str2 = str.fromLocal8Bit("保存成功！");
		//QMessageBox::information(this,str,str2);
		SetEdit(false);
		ui.saveButton->setEnabled(false);
		ui.discardButton->setEnabled(false);
		ui.editButton->setEnabled(true);
		ui.deleteButton->setEnabled(false);
		ui.addRowButton->setEnabled(false);
		ui.deleteRowButton->setEnabled(false);
		ui.radioButton_Sellout->setEnabled(false);
		ui.radioButton_Back->setEnabled(false);

	}
	else
	{
		QMessageBox box(QMessageBox::Warning,QString::fromLocal8Bit("警告"),QString::fromLocal8Bit("保存失败！"));
		box.setStandardButtons (QMessageBox::Ok);
		box.setButtonText (QMessageBox::Ok,QString::fromLocal8Bit("确 定"));
		box.exec();

	}
	//ui.editButton->setEnabled(true);
	//ui.saveButton->setEnabled(false);
}
void DrugAllot::on_saveButton_2_clicked()
{
	static int iFlag;
	int i=0;
	int amount;
	double unitprice;
	int rows = ui.tableWidget_StoreAllot->model()->rowCount();   //行总数
	//添加到收费单基本信息表中
	QSqlQuery query(*sql.db);

	QString str2;
	char strtemp[255]={0};

	QString str = str.fromLocal8Bit("警告");

	if(!ui.tableWidget_StoreAllot->isEnabled())
	{	

		QMessageBox box(QMessageBox::Warning,QString::fromLocal8Bit("警告"),QString::fromLocal8Bit("已保存过"));
		box.setStandardButtons (QMessageBox::Ok);
		box.setButtonText (QMessageBox::Ok,QString::fromLocal8Bit("确 定"));
		box.exec();
		return;
	}

	QString strSheetNo=ui.lineEdit_StoreAllotNo->text();
	QString strsql = "select * from yk_warehouseallot where sheetno ='"+strSheetNo+"'"; //where ID > 1
	query.exec(strsql);
	int num = 0;
	QStringList list;
	int kucun2;
	while(query.next())
	{
		QString strTemp = query.value(7).toString();
		list.append(strTemp);
		num++;
	}
	int kucun_YK;
	int kucun_YF;
	//for(i=0;i<num;i++)
	//{
	//	QString strName = list[i];
	//	strsql = "select * from yk_warehouseallot where sheetno ='"+strSheetNo+"'and name ='"+strName+"'"; //where ID > 1
	//	query.exec(strsql);
	//	if(query.next())
	//	amount = query.value(12).toInt();	
	//	strsql= "select * from yk_inventory where name ='"+strName+"'";//;//where AbbrName = '"+strName+"'
	//	query.exec(strsql);
	//	if(query.next())
	//		kucun_YK = query.value(7).toInt();	

	//	strsql= "select * from yf_inventory where name ='"+strName+"'";//;//where AbbrName = '"+strName+"'
	//	query.exec(strsql);
	//	if(query.next())
	//		kucun_YF = query.value(7).toInt();	


	//	if(ui.radioButton_ToYF->isChecked() && !ui.radioButton_ToYK->isChecked())
	//	{
	//		kucun_YF = kucun_YF - amount;
	//		kucun_YK = kucun_YK + amount;
	//	}
	//	if(!ui.radioButton_ToYF->isChecked() && ui.radioButton_ToYK->isChecked())
	//	{
	//		kucun_YF = kucun_YF + amount;
	//		kucun_YK = kucun_YK - amount;
	//	}
	//	query.prepare("UPDATE yk_inventory SET count= ? WHERE name = '"+strName+"'");
	//	query.bindValue(0,kucun_YK);
	//	QString strTemp1 = QString::number(kucun_YK);
	//	ui.tableWidget_StoreAllot->setItem(i,8,new QTableWidgetItem(strTemp1));
	//	query.exec();	
	//	query.prepare("UPDATE yf_inventory SET count= ? WHERE name = '"+strName+"'");
	//	query.bindValue(0,kucun_YF);
	//	strTemp1 = QString::number(kucun_YF);
	//	ui.tableWidget_StoreAllot->setItem(i,7,new QTableWidgetItem(strTemp1));
	//	query.exec();
	//}
	if(num>0)
	{
		strsql = "delete from yk_warehouseallot where sheetno ='"+strSheetNo+"'"; //where ID > 1
		query.exec(strsql);
		strsql = "delete from yk_warehouseallot_public_info where sheetno ='"+strSheetNo+"'"; //where ID > 1
		query.exec(strsql);
	}

	//QString strSheetNo=ui.lineEdit_SaleNo->text();
	//QString strsql = "select * from yk_warehouseallot where sheetno ='"+strSheetNo+"'"; //where ID > 1
	//query.exec(strsql);
	//if(query.next())
	//{
	//	strsql = "delete from yk_warehouseallot where sheetno ='"+strSheetNo+"'"; //where ID > 1
	//	query.exec(strsql);
	//}

	int isheetcount=PublicInfoSheetNo_Store();
	isheetcount++;
	query.prepare("INSERT INTO yk_warehouseallot_public_info VALUES (?, ?, ?, ?, ?, ?)");
	query.bindValue(0, isheetcount);
	query.bindValue(1, ui.lineEdit_StoreAllotNo->text());
	query.bindValue(2, ui.dateTimeEdit_Date_Store->dateTime());
	int iInputFlag;
	if(ui.radioButton_ToYF->isChecked() && !ui.radioButton_ToYK->isChecked())
		iInputFlag = 1;
	else 
		iInputFlag = 0;
	QString strTemp = QString::number(iInputFlag);
	query.bindValue(3, strTemp);
	strTemp = QString::number(1);
	query.bindValue(4, strTemp);
	query.bindValue(5, ui.lineEdit_2->text());
	iFlag = query.exec();

	for (i=0;i< rows ;i++)
	{
		int isheetcount=SheetNo_Store();
		isheetcount++;
		if(ui.tableWidget_StoreAllot->item(i,6)==NULL||(ui.tableWidget_StoreAllot->item(i,6)&& ui.tableWidget_StoreAllot->item(i,6)->text()==tr("")))
		{
			sprintf(strtemp,"第%d行调拨数量为空，请核对！",i+1);
			str2 = str.fromLocal8Bit(strtemp);		
			QMessageBox box(QMessageBox::Warning,QString::fromLocal8Bit("警告"),str2);
			box.setStandardButtons (QMessageBox::Ok);
			box.setButtonText (QMessageBox::Ok,QString::fromLocal8Bit("确 定"));
			box.exec();
			return;
		}
		query.prepare("INSERT INTO yk_warehouseallot VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)");
		query.bindValue(0, isheetcount);
		query.bindValue(1, ui.lineEdit_StoreAllotNo->text());
		query.bindValue(2, ui.dateTimeEdit_Date_Store->dateTime());
		int iInputFlag;
		if(ui.radioButton_ToYF->isChecked() && !ui.radioButton_ToYK->isChecked())
			iInputFlag = 1;  
		else 
			iInputFlag = 0;
		QString strTemp = QString::number(iInputFlag);
		query.bindValue(3, strTemp);
		strTemp = QString::number(1);
		query.bindValue(4, strTemp);
		query.bindValue(5, ui.lineEdit_2->text());

		for (int j=0;j<4;j++)
		{
			if (ui.tableWidget_StoreAllot->item(i,j)!=NULL)
			{
				query.bindValue(6+j, ui.tableWidget_StoreAllot->item(i,j)->text());
			}
			else
			{
				query.bindValue(6+j, NULL);
			}
		}

		for (int j=4;j<6;j++)
		{
			if (ui.tableWidget_StoreAllot->item(i,j)!=NULL)
			{
				query.bindValue(6+j, ui.tableWidget_StoreAllot->item(i,j)->text());
			}
			else
			{
				query.bindValue(6+j, NULL);
			}
		}

		//query.bindValue(6, ui.tableWidget_StoreAllot->item(i,0)->text());
		//query.bindValue(7, ui.tableWidget_StoreAllot->item(i,1)->text());
		//query.bindValue(8, ui.tableWidget_StoreAllot->item(i,2)->text());
		//query.bindValue(9, ui.tableWidget_StoreAllot->item(i,3)->text());
		//query.bindValue(11, ui.tableWidget_StoreAllot->item(i,4)->text());
		//query.bindValue(12, ui.tableWidget_StoreAllot->item(i,5)->text());
		//if(ui.radioButton_ToYF->isChecked() && !ui.radioButton_ToYK->isChecked())
		//{
			amount = ui.tableWidget_StoreAllot->item(i,6)->text().toInt();
			unitprice = ui.tableWidget_StoreAllot->item(i,9)->text().toDouble();
		//}else
		//{
		//	amount = -ui.tableWidget_StoreAllot->item(i,6)->text().toInt();
		//	unitprice = -ui.tableWidget_StoreAllot->item(i,9)->text().toDouble();
		//}
		

		query.bindValue(12, amount);
		query.bindValue(13, unitprice);
		unitprice = unitprice * amount;
		/*QString strprice= QString::number(unitprice);*/
		query.bindValue(14,unitprice);
		
		iFlag = query.exec();
	}

	for (i=0;i< rows ;i++)
	{	
		QString strName = ui.tableWidget_StoreAllot->item(i,1)->text();
		int kucun_YF = ui.tableWidget_StoreAllot->item(i,7)->text().toInt();
		int kucun_YK = ui.tableWidget_StoreAllot->item(i,8)->text().toInt();
		int kucun1=0;
//		kucun1 = kucun_YF - amount;
		if(ui.radioButton_ToYF->isChecked() && !ui.radioButton_ToYK->isChecked())
		{
			kucun_YF = kucun_YF + amount;
			kucun_YK = kucun_YK - amount;
		}
		if(!ui.radioButton_ToYF->isChecked() && ui.radioButton_ToYK->isChecked())
		{
			kucun_YF = kucun_YF - amount;
			kucun_YK = kucun_YK + amount;
		}
		QString strTemp1 = QString::number(kucun_YF);
		ui.tableWidget_StoreAllot->setItem(i,7,new QTableWidgetItem(strTemp1));
		strTemp1 = QString::number(kucun_YK);
		ui.tableWidget_StoreAllot->setItem(i,8,new QTableWidgetItem(strTemp1));

		QString strsql= "select * from yk_inventory where name ='"+strName+"'";//;//where AbbrName = '"+strName+"'
		query.exec(strsql);

		if(query.next())
		{
			query.prepare("UPDATE yk_inventory SET count= ? WHERE name = '"+strName+"'");
			query.bindValue(0,kucun_YK);
			iFlag = query.exec();
		}
		else
		{
			query.prepare("INSERT INTO yk_inventory VALUES (?, ?, ?, ?, ?, ?, ?, ?)");
			isheetcount=SheetNo_Store();
			isheetcount ++;
			query.bindValue(0, isheetcount);
			query.bindValue(1, strName);
			query.bindValue(2, strName);
			query.bindValue(3, ui.tableWidget_StoreAllot->item(i,2)->text());
			query.bindValue(4, ui.tableWidget_StoreAllot->item(i,3)->text());
			query.bindValue(6, ui.tableWidget_StoreAllot->item(i,5)->text());
			strTemp1 = QString::number(kucun_YK);
			query.bindValue(8, strTemp1);
			iFlag = query.exec();
			
		}
		//strsql= "select * from yf_inventory where name ='"+strName+"'";//;//where AbbrName = '"+strName+"'
		//query.exec(strsql);

		//if(query.next())
		//{
		//	query.prepare("UPDATE yf_inventory SET count= ? WHERE name = '"+strName+"'");
		//	query.bindValue(0,kucun_YF);
		//	iFlag = query.exec();
		//}
		//else
		//{
		//	query.prepare("INSERT INTO yf_inventory VALUES (?, ?, ?, ?, ?, ?, ?, ?)");
		//	isheetcount=SheetNo_Store();
		//	isheetcount ++;
		//	query.bindValue(0, isheetcount);
		//	query.bindValue(1, strName);
		//	query.bindValue(2, strName);
		//	query.bindValue(3, ui.tableWidget_StoreAllot->item(i,2)->text());
		//	query.bindValue(4, ui.tableWidget_StoreAllot->item(i,3)->text());
		//	query.bindValue(6, ui.tableWidget_StoreAllot->item(i,5)->text());
		//	strTemp1 = QString::number(kucun_YF);
		//	query.bindValue(7, strTemp1);
		//	iFlag = query.exec();
		//	
		//}
	}
	
	if(iFlag)
	{
		QString str = str.fromLocal8Bit("提示");
		QString str2 = str.fromLocal8Bit("保存成功！");
		//QMessageBox::information(this,str,str2);
		SetEdit(false);
		ui.saveButton_2->setEnabled(false);
		ui.discardButton_2->setEnabled(false);
		ui.editButton_2->setEnabled(true);
		ui.deleteButton_2->setEnabled(false);
		ui.addRowButton_2->setEnabled(false);
		ui.deleteRowButton_2->setEnabled(false);
		ui.radioButton_ToYF->setEnabled(false);
		ui.radioButton_ToYK->setEnabled(false);
	}
	else
	{
		QMessageBox box(QMessageBox::Warning,QString::fromLocal8Bit("警告"),QString::fromLocal8Bit("保存失败"));
		box.setStandardButtons (QMessageBox::Ok);
		box.setButtonText (QMessageBox::Ok,QString::fromLocal8Bit("确 定"));
		box.exec();
	}
	//ui.editButton->setEnabled(true);
	//ui.saveButton->setEnabled(false);
}
void DrugAllot::on_discardButton_clicked()
{
	ui.lineEdit_SaleNo->setText("");
	ui.lineEdit_Debt->setText("");
	ui.lineEdit_Payable->setText("");
	ui.tableWidget_SaleAllot->setRowCount(0);
	ui.tableWidget_SaleAllot->clearContents();
	ui.tableWidget_SaleAllot->insertRow(0);
	ui.addRowButton->setEnabled(false);
	ui.deleteRowButton->setEnabled(false);
	
}
void DrugAllot::on_discardButton_2_clicked()
{
	ui.lineEdit_StoreAllotNo->setText("");
	ui.tableWidget_StoreAllot->setRowCount(0);
	ui.tableWidget_StoreAllot->clearContents();
	ui.tableWidget_StoreAllot->insertRow(0);
	ui.addRowButton->setEnabled(false);
	ui.deleteRowButton->setEnabled(false);
	
}
void DrugAllot::on_editButton_clicked()
{
	int i=0,amount;
	int rows = ui.tableWidget_SaleAllot->model()->rowCount();   //行总数
	QSqlQuery query(*sql.db);

	SetEdit(true);
	ui.deleteButton->setEnabled(true);
	ui.saveButton->setEnabled(true);
	ui.discardButton->setEnabled(true);
	ui.addRowButton->setEnabled(true);
	ui.deleteRowButton->setEnabled(true);
	ui.deleteButton->setEnabled(true);

	for (i=0;i< rows ;i++)
	{
		QString strName = ui.tableWidget_SaleAllot->item(i,1)->text();
		if(ui.radioButton_Sellout->isChecked() && !ui.radioButton_Back->isChecked())
			amount = ui.tableWidget_SaleAllot->item(i,6)->text().toInt();	
		else
			amount = -ui.tableWidget_SaleAllot->item(i,6)->text().toInt();
			
		
		
		int kucun = ui.tableWidget_SaleAllot->item(i,7)->text().toInt();
		int kucun1=0;
			kucun1 = kucun + amount;

		query.bindValue(0,kucun1);
		QString strTemp1 = QString::number(kucun1);
		ui.tableWidget_SaleAllot->setItem(i,7,new QTableWidgetItem(strTemp1));

		QString strsql= "select * from yk_inventory where name ='"+strName+"'";//;//where AbbrName = '"+strName+"'
		query.exec(strsql);

		if(query.next())
		{
			query.prepare("UPDATE yk_inventory SET count= ? WHERE name = '"+strName+"'");
			query.bindValue(0,kucun1);
			query.exec();
		}
	}
}
void DrugAllot::on_editButton_2_clicked()
{
	int i=0,amount;
	int rows = ui.tableWidget_StoreAllot->model()->rowCount();   //行总数
	QSqlQuery query(*sql.db);	

	SetEdit(true);
	ui.saveButton_2->setEnabled(true);
	ui.discardButton_2->setEnabled(true);
	ui.deleteButton_2->setEnabled(true);
	ui.addRowButton_2->setEnabled(true);
	ui.deleteRowButton_2->setEnabled(true);
	ui.radioButton_ToYF->setEnabled(true);
	ui.radioButton_ToYK->setEnabled(true);
	ui.deleteButton_2->setEnabled(true);
	for (i=0;i< rows ;i++)
	{
		QString strName = ui.tableWidget_StoreAllot->item(i,1)->text();
		//if(ui.radioButton_ToYF->isChecked() && !ui.radioButton_ToYK->isChecked())
			amount = ui.tableWidget_StoreAllot->item(i,6)->text().toInt();	
		//else
		//	amount = -ui.tableWidget_StoreAllot->item(i,6)->text().toInt();
				
		int kucun_YF = ui.tableWidget_StoreAllot->item(i,7)->text().toInt();
		int kucun_YK = ui.tableWidget_StoreAllot->item(i,8)->text().toInt();

		if(ui.radioButton_ToYF->isChecked() && !ui.radioButton_ToYK->isChecked())
		{
			kucun_YF = kucun_YF - amount;
			kucun_YK = kucun_YK + amount;
		}
		if(!ui.radioButton_ToYF->isChecked() && ui.radioButton_ToYK->isChecked())
		{
			kucun_YF = kucun_YF + amount;
			kucun_YK = kucun_YK - amount;
		}
		query.bindValue(0,kucun_YK);
		QString strTemp1 = QString::number(kucun_YK);
		ui.tableWidget_StoreAllot->setItem(i,8,new QTableWidgetItem(strTemp1));
		strTemp1 = QString::number(kucun_YF);
		ui.tableWidget_StoreAllot->setItem(i,7,new QTableWidgetItem(strTemp1));

		QString strsql= "select * from yk_inventory where name ='"+strName+"'";//;//where AbbrName = '"+strName+"'
		query.exec(strsql);

		if(query.next())
		{
			query.prepare("UPDATE yk_inventory SET count= ? WHERE name = '"+strName+"'");
			query.bindValue(0,kucun_YK);
			query.exec();
		}

		//strsql= "select * from yf_inventory where name ='"+strName+"'";//;//where AbbrName = '"+strName+"'
		//query.exec(strsql);

		//if(query.next())
		//{
		//	query.prepare("UPDATE yf_inventory SET count= ? WHERE name = '"+strName+"'");
		//	query.bindValue(0,kucun_YF);
		//	query.exec();
		//}
	}
}
void DrugAllot::edit_sale(QString strNo)
{
	ui.tab->raise();
	ui.tableWidget_SaleAllot->installEventFilter(this);
	SetEdit(false);
	ui.addButton->setEnabled(false);
	ui.editButton->setEnabled(true);
	ui.radioButton_Sellout->setEnabled(false);
	ui.radioButton_Back->setEnabled(false);
	QSqlQuery query(*sql.db);	
	query.exec("select * from yk_saleallot where sheetno='"+strNo+"'");
	while(query.next())
	{
		ui.lineEdit_SaleNo->setText(query.value(1).toString());
		ui.dateTimeEdit_Date_Sale->setDateTime(query.value(2).toDateTime());
		int iInputFlag=query.value(3).toString().toInt();
		if(iInputFlag == 1)
			ui.radioButton_Sellout->setChecked(true);
		else 
			ui.radioButton_Back->setChecked(true);
		

		ui.comboBox_Customer->setEditText(query.value(5).toString());
		ui.lineEdit_2->setText(query.value(6).toString());		
	}
	ui.tableWidget_SaleAllot->setRowCount(0);
	QSqlQuery query2(*sql.db);	
	query2.exec("select * from yk_saleallot where sheetno='"+strNo+"'");
	int row= 0;
	while(query2.next())
	{
		int Num;
		ui.tableWidget_SaleAllot->insertRow(row);
		ui.tableWidget_SaleAllot->setItem(row,1,new QTableWidgetItem(query2.value(4).toString()));
		QString strName=query2.value(8).toString();
		QString strsql= "select * from sys_drugdictionary where name='"+strName+"'";
		query.exec(strsql);
		while(query.next())
		{
			ui.tableWidget_SaleAllot->setItem(row,1,new QTableWidgetItem(query.value(1).toString()));
			ui.tableWidget_SaleAllot->setItem(row,2,new QTableWidgetItem(query.value(4).toString()));
			ui.tableWidget_SaleAllot->setItem(row,3,new QTableWidgetItem(query.value(5).toString()));
			ui.tableWidget_SaleAllot->setItem(row,5,new QTableWidgetItem(query.value(6).toString()));
			ui.tableWidget_SaleAllot->setItem(row,8,new QTableWidgetItem(query.value(15).toString()));
			ui.tableWidget_SaleAllot->setItem(row,9,new QTableWidgetItem(query.value(16).toString()));//
			ui.tableWidget_SaleAllot->setItem(row,10,new QTableWidgetItem(query.value(10).toString()));//
		//	Num = query.value(10).toString().toInt();
		}

		Num = query2.value(13).toString().toInt();
		strsql= "select * from yk_inventory where name='"+strName+"'";
		query.exec(strsql);
		if(query.next())
		{
			int kucun1 = query.value(7).toString().toInt();
			kucun1 = kucun1 + Num;
			QString strTemp = QString::number(kucun1);
			ui.tableWidget_SaleAllot->setItem(row,7,new QTableWidgetItem(strTemp));  //有问题
		}
		ui.tableWidget_SaleAllot->setItem(row,6,new QTableWidgetItem(query2.value(13).toString()));
		row++;
	}
}
void DrugAllot::edit_store(QString strNo)
{
	ui.tableWidget_StoreAllot->installEventFilter(this);
	ui.tab_2->raise();
	SetEdit(false);
	ui.addButton_2->setEnabled(false); 
	ui.editButton_2->setEnabled(true);
	ui.deleteButton_2->setEnabled(true);
	ui.radioButton_ToYF->setEnabled(false);
	ui.radioButton_ToYK->setEnabled(false);
	QSqlQuery query(*sql.db);	
	query.exec("select * from yk_warehouseallot where sheetno='"+strNo+"'");
	while(query.next())
	{
		ui.lineEdit_StoreAllotNo->setText(query.value(1).toString());
		ui.dateTimeEdit_Date_Store->setDateTime(query.value(2).toDateTime());
		int iInputFlag=query.value(3).toString().toInt();
		if(iInputFlag == 1)
			ui.radioButton_ToYF->setChecked(true);
		else 
			ui.radioButton_ToYK->setChecked(true);

		//ui.comboBox_Customer->setEditText(query.value(5).toString());
		ui.lineEdit_2->setText(query.value(5).toString());		
	}
	ui.tableWidget_StoreAllot->setRowCount(0);
	QSqlQuery query2(*sql.db);	
	query2.exec("select * from yk_warehouseallot where sheetno='"+strNo+"'");
	int row= 0;
	while(query2.next())
	{
		int Num;
		ui.tableWidget_StoreAllot->insertRow(row);
		//ui.tableWidget_StoreAllot->setItem(row,1,new QTableWidgetItem(query2.value(4).toString()));
		QString strName=query2.value(7).toString();
		QString strsql= "select * from sys_drugdictionary where name='"+strName+"'";
		query.exec(strsql);
		while(query.next())
		{
			ui.tableWidget_StoreAllot->setItem(row,1,new QTableWidgetItem(query.value(1).toString()));
			ui.tableWidget_StoreAllot->setItem(row,2,new QTableWidgetItem(query.value(4).toString()));
			ui.tableWidget_StoreAllot->setItem(row,3,new QTableWidgetItem(query.value(5).toString()));
			ui.tableWidget_StoreAllot->setItem(row,5,new QTableWidgetItem(query.value(6).toString()));
			ui.tableWidget_StoreAllot->setItem(row,9,new QTableWidgetItem(query.value(15).toString()));
			ui.tableWidget_StoreAllot->setItem(row,10,new QTableWidgetItem(query.value(16).toString()));//
			ui.tableWidget_StoreAllot->setItem(row,11,new QTableWidgetItem(query.value(10).toString()));//
			//Num = query.value(10).toString().toInt();
		}

		Num = query2.value(12).toString().toInt();
		strsql= "select * from yk_inventory where name='"+strName+"'";
		query.exec(strsql);
		if(query.next())
		{
			int kucun1 = query.value(7).toString().toInt();
			kucun1 = kucun1 + Num;
			QString strTemp = QString::number(kucun1);
			ui.tableWidget_StoreAllot->setItem(row,8,new QTableWidgetItem(strTemp));  //有问题
		}
		strsql= "select * from yf_inventory where name='"+strName+"'";
		query.exec(strsql);
		if(query.next())
		{
			int kucun1 = query.value(7).toString().toInt();
			//kucun1 = kucun1 - Num;
			QString strTemp = QString::number(kucun1);
			ui.tableWidget_StoreAllot->setItem(row,7,new QTableWidgetItem(strTemp));  //有问题
		}
		ui.tableWidget_StoreAllot->setItem(row,6,new QTableWidgetItem(query2.value(12).toString()));
		row++;
	}
}
void DrugAllot::on_printButton_clicked()
{
	QPrinter       printer( QPrinter::PrinterResolution );
	QPrintDialog   dialog( &printer, this );
	if ( dialog.exec() == QDialog::Accepted ) print_XSDB( &printer );
}
void DrugAllot::on_printButton_2_clicked()
{
	QPrinter       printer( QPrinter::PrinterResolution );
	QPrintDialog   dialog( &printer, this );
	if ( dialog.exec() == QDialog::Accepted ) print_CKDB( &printer );
}
void DrugAllot::on_previewButton_clicked()
{
	filePrintPreview();
}
void DrugAllot::on_previewButton_2_clicked()
{
	filePrintPreview_2();
}
void DrugAllot::filePrintPreview()
{
	// 打印预览对话框
	QPrinter             printer( QPrinter::PrinterResolution );
	QPrintPreviewDialog  preview( &printer, this );
	preview.setWindowTitle("preview");
	preview.setMinimumSize(1000,900);
	connect( &preview, SIGNAL(paintRequested(QPrinter*)), SLOT(print_XSDB(QPrinter*)) );
	preview.exec();
}
void DrugAllot::filePrintPreview_2()
{
	// 打印预览对话框
	QPrinter             printer( QPrinter::PrinterResolution );
	QPrintPreviewDialog  preview( &printer, this );
	preview.setWindowTitle("preview");
	preview.setMinimumSize(1000,900);
	connect( &preview, SIGNAL(paintRequested(QPrinter*)), SLOT(print_CKDB(QPrinter*)) );
	preview.exec();
}
void DrugAllot::print_XSDB( QPrinter* printer )
{
	//// 创建打印页面的绘制对象
	QPainter painter( printer );
	int      w = printer->pageRect().width();
	int      h = printer->pageRect().height();
	QRect    page( w/5, h/15, w, h );
	QRect    page2( w/4, h/8, w, h );
	QRect    page3( w/4, h/6, w, h );
	QRect    page4( 0, h/10, w, h );
	// 根据页面大小设置适当的字体大小
	QFont    font = painter.font();
	font.setPixelSize( (w+h) / 100 );
	painter.setFont( font );

	// 在页面角落绘制标签
	painter.drawText( page, Qt::AlignTop    | Qt::AlignLeft, QString::fromLocal8Bit("                  三河市燕郊镇卫生院") );
	/*painter.drawText( page2, Qt::AlignTop    | Qt::AlignLeft, QString::fromLocal8Bit("周文军") );
	painter.drawText( page3, Qt::AlignTop    | Qt::AlignLeft, QString::fromLocal8Bit("一般针疗费     次   1  10.00") );
	painter.drawText( page4, Qt::AlignTop | Qt::AlignLeft,  QString::fromLocal8Bit("六十九元九角整"));
	painter.drawText( page, Qt::AlignBottom | Qt::AlignLeft,
		QDateTime::currentDateTime().toString( Qt::DefaultLocaleShortDate ) );*/

	// 绘制模拟数据
	page.adjust( w/20, h/20, -w/20, -h/20 );

	QPixmap image;
	image=image.grabWidget(ui.tableWidget_SaleAllot,-35,0,900, 1000);
	painter.drawPixmap(page4,image);

	//printTableWidget(ui.tableWidget,"preview",printer);
}
void DrugAllot::print_CKDB( QPrinter* printer )
{
	//// 创建打印页面的绘制对象
	QPainter painter( printer );
	int      w = printer->pageRect().width();
	int      h = printer->pageRect().height();
	QRect    page( w/5, h/15, w, h );
	QRect    page2( w/4, h/8, w, h );
	QRect    page3( w/4, h/6, w, h );
	QRect    page4( 0, h/10, w, h );
	// 根据页面大小设置适当的字体大小
	QFont    font = painter.font();
	font.setPixelSize( (w+h) / 100 );
	painter.setFont( font );

	// 在页面角落绘制标签
	painter.drawText( page, Qt::AlignTop    | Qt::AlignLeft, QString::fromLocal8Bit("                  三河市燕郊镇卫生院") );
	/*painter.drawText( page2, Qt::AlignTop    | Qt::AlignLeft, QString::fromLocal8Bit("周文军") );
	painter.drawText( page3, Qt::AlignTop    | Qt::AlignLeft, QString::fromLocal8Bit("一般针疗费     次   1  10.00") );
	painter.drawText( page4, Qt::AlignTop | Qt::AlignLeft,  QString::fromLocal8Bit("六十九元九角整"));
	painter.drawText( page, Qt::AlignBottom | Qt::AlignLeft,
		QDateTime::currentDateTime().toString( Qt::DefaultLocaleShortDate ) );*/

	// 绘制模拟数据
	page.adjust( w/20, h/20, -w/20, -h/20 );  
	QPixmap image;
	image=image.grabWidget(ui.tableWidget_StoreAllot,-35,0,900, 1000);
	painter.drawPixmap(page4,image);

	//printTableWidget(ui.tableWidget,"preview",printer);
}
void DrugAllot::pay(const QString &)
{
	double iamount = ui.lineEdit_Paid->text().toInt();
	double icurrentamount = ui.lineEdit_Payable->text().toDouble();
	iamount = iamount - icurrentamount;
	QString strcurrentamount = QString::number(iamount);
	ui.lineEdit_Debt->setText(strcurrentamount);

}
void DrugAllot::getItem_Sale(int row,int column)//计算费用
{
	QString str2;
	QString str = str.fromLocal8Bit("警告");
	if (column==6)
	{
		if (ui.tableWidget_SaleAllot->item(row,column)->text()==NULL) return;
		if (ui.tableWidget_SaleAllot->item(row,column+2)->text()==NULL) return;

		int icount = ui.tableWidget_SaleAllot->item(row,column)->text().toInt();
		int kucun =  ui.tableWidget_SaleAllot->item(row,column+1)->text().toInt();
		if(ui.radioButton_Sellout->isChecked()&&icount>kucun)
		{
			str2 = str.fromLocal8Bit("调拨数量大于库存，请核对！");
			QMessageBox box(QMessageBox::Warning,QString::fromLocal8Bit("警告"),str2);
			box.setStandardButtons (QMessageBox::Ok);
			box.setButtonText (QMessageBox::Ok,QString::fromLocal8Bit("确 定"));
			box.exec();
			str = QString::number(0);
			ui.tableWidget_SaleAllot->setItem(row,column,new  QTableWidgetItem(str));
			return;
		}
		if(icount<0)
		{
			str2 = str.fromLocal8Bit("调拨数量不能为负，请核对！");
			QMessageBox box(QMessageBox::Warning,QString::fromLocal8Bit("警告"),str2);
			box.setStandardButtons (QMessageBox::Ok);
			box.setButtonText (QMessageBox::Ok,QString::fromLocal8Bit("确 定"));
			box.exec();
			QString stramount = QString::number(0);
			ui.tableWidget_SaleAllot->setItem(row,column,new QTableWidgetItem(stramount));
			return;
		}
		double unitprice = ui.tableWidget_SaleAllot->item(row,column+2)->text().toDouble();
		double amount = icount*unitprice;
		QString stramount = QString::number(amount);
		ui.tableWidget_SaleAllot->setItem(row,column+3,new QTableWidgetItem(stramount));

		double icurrentamount= TotalPrice_sale();
		QString strcurrentamount = QString::number(icurrentamount);
		 
		//累加
		ui.lineEdit_Payable->setText(strcurrentamount);
		
		double iamount = ui.lineEdit_Paid->text().toInt();
		iamount = iamount - icurrentamount;
		//if(ui.radioButton_Sellout->isChecked() && !ui.radioButton_Back->isChecked())
		//	iamount = iamount - icurrentamount;
		//if(!ui.radioButton_Sellout->isChecked() && ui.radioButton_Back->isChecked())
		//	iamount = iamount + icurrentamount;
		strcurrentamount = QString::number(iamount);
		ui.lineEdit_Debt->setText(strcurrentamount);
	}
	if (column==0)
	{

		list_widget->close();
		QString strText;
		if(ui.tableWidget_SaleAllot->item(row,0)==NULL)  return;

		strText =  ui.tableWidget_SaleAllot->item(row,0)->text();
		if(strText.at(0)== QChar('1')) return;

		//list_widget->setGeometry(103, 160+row*30, 150, 280);
		QPoint GlobalPoint(ui.tableWidget_SaleAllot->mapFrom(ui.tableWidget_SaleAllot,QPoint(0, 0)));//获取控件在窗体中的坐标
		if(row<8)
			list_widget->setGeometry(GlobalPoint.x()+80, GlobalPoint.y()+40*(row+1), 150, 280);
		list_widget->show();
		QSqlQuery query(*sql.db);	

		QString strsql= QString("select * from sys_drugdictionary where abbr like '%%1%'or name like'%%2%'  ").arg(strText).arg(strText);

		query.exec(strsql);
		QStringList list;
		list_widget->clear();
		while(query.next())
		{
			QString str = query.value(1).toString();
			list.append(str);
		}
		list_widget->addItems(list);
	}

}
void DrugAllot::getItem_Store(int row,int column)//计算费用
{
	QString str2;
	QString str = str.fromLocal8Bit("警告");
	if (column==6)
	{
		if (ui.tableWidget_StoreAllot->item(row,column)->text()==NULL) return;
		if (ui.tableWidget_StoreAllot->item(row,column+2)->text()==NULL) return;

		int icount = ui.tableWidget_StoreAllot->item(row,column)->text().toInt();
		int kucun_YK =  ui.tableWidget_StoreAllot->item(row,column+2)->text().toInt();
		if(ui.radioButton_ToYF->isChecked()&&icount>kucun_YK)
		{
			str2 = str.fromLocal8Bit("调拨数量大于库存，请核对！");
			QMessageBox box(QMessageBox::Warning,QString::fromLocal8Bit("警告"),str2);
			box.setStandardButtons (QMessageBox::Ok);
			box.setButtonText (QMessageBox::Ok,QString::fromLocal8Bit("确 定"));
			box.exec();
			str = QString::number(0);
			ui.tableWidget_StoreAllot->setItem(row,column,new  QTableWidgetItem(str));
			return;
		}
		if(icount<0)
		{
			str2 = str.fromLocal8Bit("调拨数量不能为负，请核对！");
			QMessageBox box(QMessageBox::Warning,QString::fromLocal8Bit("警告"),str2);
			box.setStandardButtons (QMessageBox::Ok);
			box.setButtonText (QMessageBox::Ok,QString::fromLocal8Bit("确 定"));
			box.exec();
			QString stramount = QString::number(0);
			ui.tableWidget_StoreAllot->setItem(row,column,new QTableWidgetItem(stramount));
			return;
		}
		int kucun_YF =  ui.tableWidget_StoreAllot->item(row,column+1)->text().toInt();
		if(ui.radioButton_ToYK->isChecked()&&icount>kucun_YF)
		{
			str2 = str.fromLocal8Bit("调拨数量大于库存，请核对！");
			QMessageBox box(QMessageBox::Warning,QString::fromLocal8Bit("警告"),str2);
			box.setStandardButtons (QMessageBox::Ok);
			box.setButtonText (QMessageBox::Ok,QString::fromLocal8Bit("确 定"));
			box.exec();
			str = QString::number(0);
			ui.tableWidget_StoreAllot->setItem(row,column,new  QTableWidgetItem(str));
			return;
		}
		//int kucun_YK =  ui.tableWidget_StoreAllot->item(row,column+2)->text().toInt();
		//kucun_YK =kucun_YK + icount;
		//QString stramount = QString::number(kucun_YK);
		//ui.tableWidget_StoreAllot->setItem(row,column+2,new QTableWidgetItem(stramount));
		double unitprice = ui.tableWidget_StoreAllot->item(row,column+3)->text().toDouble();
		double amount = icount*unitprice;
		QString stramount = QString::number(amount);
		ui.tableWidget_StoreAllot->setItem(row,column+4,new QTableWidgetItem(stramount));
	}
	if (column==0)
	{



		list_widget2->close();
		QString strText;
		if(ui.tableWidget_StoreAllot->item(row,0)==NULL)  return;

		strText =  ui.tableWidget_StoreAllot->item(row,0)->text();
		if(strText.at(0)== QChar('1')) return;

		//list_widget2->setGeometry(103, 160+row*30, 150, 280);
		QPoint GlobalPoint(ui.tableWidget_StoreAllot->mapFrom(ui.tableWidget_StoreAllot,QPoint(0, 0)));//获取控件在窗体中的坐标
		if(row<8)
			list_widget->setGeometry(GlobalPoint.x()+80, GlobalPoint.y()+40*(row+1), 150, 280);
		list_widget2->show();
		QSqlQuery query(*sql.db);	

		

		QString strsql= QString("select * from sys_drugdictionary where abbr like '%%1%'or name like'%%2%'  ").arg(strText).arg(strText);

		query.exec(strsql);
		QStringList list;
		list_widget2->clear();
		while(query.next())
		{
			QString str = query.value(1).toString();
			list.append(str);
		}
		list_widget2->addItems(list);
	}
}
void DrugAllot::keyPressEvent(QKeyEvent *e) {
	QString str2;
	QString str = str.fromLocal8Bit("警告");
	if (!ui.tab->isHidden())
	{
		list_widget->setFocus();
	}
	if (!ui.tab_2->isHidden())
	{
		list_widget2->setFocus();
	}

	if (!list_widget->isHidden()) {
		int key = e->key();
		int count = list_widget->model()->rowCount();
		QModelIndex currentIndex = list_widget->currentIndex();

		if (Qt::Key_Down == key) {
			int row = currentIndex.row() + 1;
			if (row >= count) {
				row = 0;
			}

			QModelIndex index = list_widget->model()->index(row, 0);
			list_widget->setCurrentIndex(index);
		} else if (Qt::Key_Up == key) {
			int row = currentIndex.row() - 1;
			if (row < 0) {
				row = count - 1;
			}

			QModelIndex index = list_widget->model()->index(row, 0);
			list_widget->setCurrentIndex(index);
		} else if (Qt::Key_Escape == key) {
			list_widget->hide();
		} else if (Qt::Key_Enter == key || Qt::Key_Return == key) {
			if (currentIndex.isValid()) {
				QString strName = list_widget->currentIndex().data().toString();

				QSqlQuery query(*sql.db);
				QString strsql1= "select * from yk_inventory where name='"+strName+"'";//;//where AbbrName = '"+strName+"'
				query.exec(strsql1);
				if(!query.next())
				{
					str2 = str.fromLocal8Bit("药库库存中没有该药品，请核对！");
					QMessageBox box(QMessageBox::Warning,QString::fromLocal8Bit("警告"),str2);
					box.setStandardButtons (QMessageBox::Ok);
					box.setButtonText (QMessageBox::Ok,QString::fromLocal8Bit("确 定"));
					box.exec();
					return;
				}

				int row = ui.tableWidget_SaleAllot->currentRow();
					
				QString strsql= "select * from sys_drugdictionary where name='"+strName+"'";//;//where AbbrName = '"+strName+"'
				query.exec(strsql);
				while(query.next())
				{
					ui.tableWidget_SaleAllot->setItem(row,0,new QTableWidgetItem(query.value(22).toString()));
					ui.tableWidget_SaleAllot->setItem(row,1,new QTableWidgetItem(query.value(1).toString()));
					ui.tableWidget_SaleAllot->setItem(row,2,new QTableWidgetItem(query.value(4).toString()));
					ui.tableWidget_SaleAllot->setItem(row,3,new QTableWidgetItem(query.value(5).toString()));
					ui.tableWidget_SaleAllot->setItem(row,5,new QTableWidgetItem(query.value(6).toString()));
					ui.tableWidget_SaleAllot->setItem(row,8,new QTableWidgetItem(query.value(15).toString()));
					ui.tableWidget_SaleAllot->setItem(row,9,new QTableWidgetItem(query.value(16).toString()));//
					ui.tableWidget_SaleAllot->setItem(row,10,new QTableWidgetItem(query.value(10).toString()));//


					ui.tableWidget_SaleAllot->setFocus();
					ui.tableWidget_SaleAllot->setCurrentCell(row, 0, QItemSelectionModel::Deselect);
					ui.tableWidget_SaleAllot->setCurrentCell(row,6, QItemSelectionModel::Select);
				}

				strsql= "select * from yk_inventory where name='"+strName+"'";//;//where AbbrName = '"+strName+"'
				query.exec(strsql);

				if(query.next())
				{
					ui.tableWidget_SaleAllot->setItem(row,7,new QTableWidgetItem(query.value(7).toString()));
				}
				else 
				{
					QString strTemp = QString::number(0);
					ui.tableWidget_SaleAllot->setItem(row,7,new QTableWidgetItem(strTemp));
				}


				
			}

			list_widget->hide();
		} else {
			list_widget->hide();
			//QLineEdit::keyPressEvent(e);
		}
	}
	else
	{
		if (!ui.tab_2->isHidden())
			return;
		int key = e->key();
		if (Qt::Key_Enter == key || Qt::Key_Return == key) {
			int row = ui.tableWidget_SaleAllot->currentRow();
			int count = ui.tableWidget_SaleAllot->rowCount();
			ui.tableWidget_SaleAllot->insertRow(count);
			ui.tableWidget_SaleAllot->setCurrentCell(row, 6, QItemSelectionModel::Deselect);
			ui.tableWidget_SaleAllot->setCurrentCell(row+1, 0, QItemSelectionModel::Select);
			//QCursor cursorAction;
			//ui.tableWidget->setCursor(cursorAction);
		}
		if (Qt::Key_F5 == key ) {
			on_saveButton_clicked();
		}

	}

	if (!list_widget2->isHidden()) {
		int key = e->key();
		int count = list_widget2->model()->rowCount();
		QModelIndex currentIndex = list_widget2->currentIndex();

		if (Qt::Key_Down == key) {
			int row = currentIndex.row() + 1;
			if (row >= count) {
				row = 0;
			}

			QModelIndex index = list_widget2->model()->index(row, 0);
			list_widget2->setCurrentIndex(index);
		} else if (Qt::Key_Up == key) {
			int row = currentIndex.row() - 1;
			if (row < 0) {
				row = count - 1;
			}

			QModelIndex index = list_widget2->model()->index(row, 0);
			list_widget2->setCurrentIndex(index);
		} else if (Qt::Key_Escape == key) {
			list_widget2->hide();
		} else if (Qt::Key_Enter == key || Qt::Key_Return == key) {
			if (currentIndex.isValid()) {
				QString strName = list_widget2->currentIndex().data().toString();
				QSqlQuery query(*sql.db);

				if(ui.radioButton_ToYF->isChecked())
				{
					QString strsql1= "select * from yk_inventory where name='"+strName+"'";//;//where AbbrName = '"+strName+"'
					query.exec(strsql1);
					if(!query.next())
					{
						str2 = str.fromLocal8Bit("药库库存中没有该药品，请核对！");
						QMessageBox box(QMessageBox::Warning,QString::fromLocal8Bit("警告"),str2);
						box.setStandardButtons (QMessageBox::Ok);
						box.setButtonText (QMessageBox::Ok,QString::fromLocal8Bit("确 定"));
						box.exec();
						return;
					}
				}
				if(ui.radioButton_ToYK->isChecked())
				{
					QString strsql1= "select * from yf_inventory where name='"+strName+"'";//;//where AbbrName = '"+strName+"'
					query.exec(strsql1);
					if(!query.next())
					{
						str2 = str.fromLocal8Bit("药房库存中没有该药品，请核对！");
						QMessageBox box(QMessageBox::Warning,QString::fromLocal8Bit("警告"),str2);
						box.setStandardButtons (QMessageBox::Ok);
						box.setButtonText (QMessageBox::Ok,QString::fromLocal8Bit("确 定"));
						box.exec();
						return;
					}
				}

				int row = ui.tableWidget_StoreAllot->currentRow();
			
				QString strsql= "select * from sys_drugdictionary where name='"+strName+"'";//;//where AbbrName = '"+strName+"'
				query.exec(strsql);
				while(query.next())
				{
					ui.tableWidget_StoreAllot->setItem(row,0,new QTableWidgetItem(query.value(22).toString()));
					ui.tableWidget_StoreAllot->setItem(row,1,new QTableWidgetItem(query.value(1).toString()));
					ui.tableWidget_StoreAllot->setItem(row,2,new QTableWidgetItem(query.value(4).toString()));
					ui.tableWidget_StoreAllot->setItem(row,3,new QTableWidgetItem(query.value(5).toString()));
					ui.tableWidget_StoreAllot->setItem(row,5,new QTableWidgetItem(query.value(6).toString()));
					ui.tableWidget_StoreAllot->setItem(row,9,new QTableWidgetItem(query.value(15).toString()));
					ui.tableWidget_StoreAllot->setItem(row,10,new QTableWidgetItem(query.value(16).toString()));//
					ui.tableWidget_StoreAllot->setItem(row,11,new QTableWidgetItem(query.value(10).toString()));//

					ui.tableWidget_StoreAllot->setFocus();
					ui.tableWidget_StoreAllot->setCurrentCell(row, 0, QItemSelectionModel::Deselect);
					ui.tableWidget_StoreAllot->setCurrentCell(row,6, QItemSelectionModel::Select);
				}
				QString strsql1= "select * from yk_inventory where name='"+strName+"'";//;//where AbbrName = '"+strName+"'
				query.exec(strsql1);

				if(query.next())
				{
					ui.tableWidget_StoreAllot->setItem(row,8,new QTableWidgetItem(query.value(7).toString()));
				}
				else 
				{
					QString strTemp = QString::number(0);
					ui.tableWidget_StoreAllot->setItem(row,8,new QTableWidgetItem(strTemp));
				}
				strsql1= "select * from yf_inventory where name='"+strName+"'";//;//where AbbrName = '"+strName+"'
				query.exec(strsql1);

				if(query.next())
				{
					ui.tableWidget_StoreAllot->setItem(row,7,new QTableWidgetItem(query.value(7).toString()));
				}
				else 
				{
					QString strTemp = QString::number(0);
					ui.tableWidget_StoreAllot->setItem(row,7,new QTableWidgetItem(strTemp));
				}



			}

			list_widget2->hide();
		} else {
			list_widget2->hide();
			//QLineEdit::keyPressEvent(e);
		}
	} 
	else
	{
		if (!ui.tab->isHidden())
		return;
		int key = e->key();
		if (Qt::Key_Enter == key || Qt::Key_Return == key) {
			int row = ui.tableWidget_StoreAllot->currentRow();
			int count = ui.tableWidget_StoreAllot->rowCount();
			ui.tableWidget_StoreAllot->insertRow(count);
			ui.tableWidget_StoreAllot->setCurrentCell(row, 6, QItemSelectionModel::Deselect);
			ui.tableWidget_StoreAllot->setCurrentCell(row+1, 0, QItemSelectionModel::Select);
			//QCursor cursorAction;
			//ui.tableWidget->setCursor(cursorAction);
		}
		if (Qt::Key_F5 == key ) {
			on_saveButton_2_clicked();
		}

	}
}