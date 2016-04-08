#include "drugstorage.h"
#include <QtGui>
#include "connectsql.h"
#include "clinicdrugfilter.h"
#include "package.h"

static int icount;
extern ConnectSql sql;

DrugStorage::DrugStorage(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	initUI();
	ui.tableWidget->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
	ui.tableWidget->setStyleSheet("QTableWidget{border: 1px solid gray;	background-color: transparent;	selection-color: grey;}");
	ui.tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section {background-color:white;color: black;padding-left: 4px;border: 1px solid #6c6c6c;};"
		"color: white;padding-left: 4px;border: 1px solid #6c6c6c;}"
		"QHeaderView::section:checked{background-color: white;color: black;}");	
	ui.tableWidget->installEventFilter(this);//注册事件过滤器	


	list_widget = new QListWidget(this);
	list_widget->setWindowFlags(Qt::FramelessWindowHint);
	list_widget->close();
	installEventFilter(list_widget);


	connect(ui.tableWidget,SIGNAL(cellChanged(int,int)),this,SLOT(getItem(int,int)));
	connect(ui.lineEdit_Paid,SIGNAL(textChanged(const QString &)),this,SLOT(pay(const QString &)));
}

DrugStorage::~DrugStorage()
{

}
void DrugStorage::initUI()
{
	iRow=0;
	QSqlQuery query(*sql.db);		
	QDateTime current_date_time = QDateTime::currentDateTime();
	ui.dateTimeEdit->setDateTime(current_date_time);
	ui.saveButton->setEnabled(false);
	ui.editButton->setEnabled(false);
	ui.addRowButton->setEnabled(false);
	ui.deleteRowButton->setEnabled(false);
	ui.discardButton->setEnabled(false);
	ui.deleteButton->setEnabled(false);
	ui.tableWidget->setEnabled(false);
	//ui.tableWidget->setEditTriggers(QAbstractItemView::AllEditTriggers);
	ui.tableWidget->setAlternatingRowColors(true);  

	QTextCodec::setCodecForTr(QTextCodec::codecForName("gb18030"));

	query.exec("select * from sys_supplier");
	QStringList list;
	while(query.next())
	{
		QString str = query.value(1).toString();
		list.append(str);
	}
	ui.comboBox_supplier->addItems(list);

	ui.lineEdit_Payable->setText("0");
	ui.lineEdit_Paid->setText("0");
	ui.lineEdit_debt->setText("0");
	ui.tableWidget->setRowCount(0);
	ui.tableWidget->clearContents();
	ui.tableWidget->insertRow(0);
}
void DrugStorage::on_radioButton_Minus_clicked()
{
	if(ui.radioButton_Add->isChecked() && !ui.radioButton_Minus->isChecked())
	{
		ui.label_14->setText(QObject::tr("本次应付："));
		ui.label_15->setText(QObject::tr("实际付款："));
	}

	if(!ui.radioButton_Add->isChecked() && ui.radioButton_Minus->isChecked())
	{
		ui.label_14->setText(QObject::tr("本次应收："));
		ui.label_15->setText(QObject::tr("实际收取："));
	}
	ui.tableWidget->setRowCount(0);
	ui.tableWidget->clearContents();
	ui.tableWidget->insertRow(0);
	ui.lineEdit_Payable->setText("0");
	ui.lineEdit_Paid->setText("0");
	ui.lineEdit_debt->setText("0");	
}
void DrugStorage::on_radioButton_Add_clicked()
{

	if(ui.radioButton_Add->isChecked() && !ui.radioButton_Minus->isChecked())
	{
		ui.label_14->setText(QObject::tr("本次应付："));
		ui.label_15->setText(QObject::tr("实际付款："));
	}

	if(!ui.radioButton_Add->isChecked() && ui.radioButton_Minus->isChecked())
	{
		ui.label_14->setText(QObject::tr("本次应收："));
		ui.label_15->setText(QObject::tr("实际收取："));
	}
	ui.tableWidget->setRowCount(0);
	ui.tableWidget->clearContents();
	ui.tableWidget->insertRow(0);
	ui.lineEdit_Payable->setText("0");
	ui.lineEdit_Paid->setText("0");
	ui.lineEdit_debt->setText("0");	
}
void DrugStorage::on_addRowButton_clicked()
{
	//表格增加一行
	int rows = ui.tableWidget->model()->rowCount();   //行总数
	ui.tableWidget->insertRow(rows);
	iRow=rows;
}
double DrugStorage::TotalPrice()
{
	int i;
	int rows = ui.tableWidget->model()->rowCount();
	double icurrentamount = 0.0;

	for(i=0;i<rows;i++)
	{
		if(ui.tableWidget->item(i,6)==NULL||(ui.tableWidget->item(i,6)&& ui.tableWidget->item(i,6)->text()==tr("")))
			continue;
		int icount = ui.tableWidget->item(i,6)->text().toInt();
		double unitprice = ui.tableWidget->item(i,6+2)->text().toDouble();
		double amount = icount*unitprice;
		QString stramount = QString::number(amount);
		//if(ui.radioButton_Add->isChecked() && !ui.radioButton_Minus->isChecked())
			icurrentamount+=amount;
		//if(!ui.radioButton_Add->isChecked() && ui.radioButton_Minus->isChecked())
			//icurrentamount-=amount;
	}
	return icurrentamount;
}
void DrugStorage::on_deleteRowButton_clicked()
{
	int rows = ui.tableWidget->currentRow(); //行总数
	if(ui.tableWidget->item(rows,7)==NULL||(ui.tableWidget->item(rows,7)&& ui.tableWidget->item(rows,7)->text()==tr("")))
	{	
		ui.tableWidget->removeRow(rows);
		iRow--;
		return;
	}

	int icount = ui.tableWidget->item(rows,7)->text().toInt();
	double unitprice = ui.tableWidget->item(rows,7+1)->text().toDouble();
	double amount = icount*unitprice;
	QString stramount = QString::number(amount);
	
	double icurrentamount = ui.lineEdit_Payable->text().toInt();
	if(ui.radioButton_Add->isChecked() && !ui.radioButton_Minus->isChecked())
		icurrentamount-=amount;
	if(!ui.radioButton_Add->isChecked() && ui.radioButton_Minus->isChecked())
		icurrentamount+=amount;
	QString strcurrentamount = QString::number(icurrentamount);
		 
		//累加
	ui.lineEdit_Payable->setText(strcurrentamount);
		
	double iamount = ui.lineEdit_Paid->text().toInt();
	if(ui.radioButton_Add->isChecked() && !ui.radioButton_Minus->isChecked())
		iamount = iamount - icurrentamount;
	if(!ui.radioButton_Add->isChecked() && ui.radioButton_Minus->isChecked())
		iamount = iamount + icurrentamount;
	strcurrentamount = QString::number(iamount);
	ui.lineEdit_debt->setText(strcurrentamount);

	ui.tableWidget->removeRow(rows);
	iRow--;
}
void DrugStorage::SetEdit(bool IsEdit)
{
	if (IsEdit==true)
	{
		ui.lineEdit_No->setEnabled(true);
		ui.comboBox_supplier->setEnabled(true);
		ui.tableWidget->setEnabled(true);
		ui.lineEdit_Payable->setEnabled(true);
		ui.lineEdit_Paid->setEnabled(true);
		ui.lineEdit_debt->setEnabled(true);
		ui.radioButton_Add->setEnabled(true);
		ui.radioButton_Minus->setEnabled(true);
		ui.dateTimeEdit->setEnabled(true);
	}
	else
	{
		ui.lineEdit_No->setEnabled(false);
		ui.comboBox_supplier->setEnabled(false);
		ui.tableWidget->setEnabled(false);
		ui.lineEdit_Payable->setEnabled(false);
		ui.lineEdit_Paid->setEnabled(false);
		ui.lineEdit_debt->setEnabled(false);
		ui.radioButton_Add->setEnabled(false);
		ui.radioButton_Minus->setEnabled(false);
		ui.dateTimeEdit->setEnabled(false);
	}
}
void DrugStorage::on_addButton_clicked()
{
	initUI();
	SetEdit(true);
	ui.saveButton->setEnabled(true);
	ui.discardButton->setEnabled(true);
	ui.addRowButton->setEnabled(true);
	ui.deleteRowButton->setEnabled(true);
	ui.editButton->setEnabled(false);
	ui.deleteButton->setEnabled(false);
	ui.tableWidget->setRowCount(0);
	ui.tableWidget->clearContents();
	ui.tableWidget->insertRow(0);
	//ui.tableWidget->setEditTriggers(QAbstractItemView::DoubleClicked);
	iRow = 0;
	icount = 0;
	ui.tableWidget->setRowCount(0);
	ui.tableWidget->clearContents();
	ui.tableWidget->insertRow(0);
	int isheetcount=PublicInfoSheetNo();
	isheetcount++;
	QString strSheetNo= "YPRK"+QString::number(isheetcount, 10);
	ui.lineEdit_No->setText(strSheetNo);
	ui.lineEdit_Payable->setText("0");
	ui.lineEdit_Paid->setText("0");
	ui.lineEdit_debt->setText("0");
}
int  DrugStorage::PublicInfoSheetNo()
{
	QSqlQuery query(*sql.db);		
	query.exec("select * from yk_instorage_public_info");
	int isheetcount=0;
	while(query.next())
	{ 
		isheetcount++;
	}
	return isheetcount;
}
int  DrugStorage::SheetNo()
{
	QSqlQuery query(*sql.db);		
	query.exec("select * from yk_instorage");
	int isheetcount=0;
	while(query.next())
	{ 
		isheetcount++;
	}
	return isheetcount;
}
int  DrugStorage::InventorySheetNo()
{
	QSqlQuery query(*sql.db);		
	query.exec("select * from yk_inventory");
	int isheetcount=0;
	while(query.next())
	{ 
		isheetcount++;
	}
	return isheetcount;
}
void DrugStorage::on_deleteButton_clicked()//存在问题
{
	int i=0,amount;
	int rows = ui.tableWidget->model()->rowCount();   //行总数

	QMessageBox box(QMessageBox::Warning,QString::fromLocal8Bit("警告"),QString::fromLocal8Bit("确认删除本单？"));
	box.setStandardButtons (QMessageBox::Ok|QMessageBox::Cancel);
	box.setButtonText (QMessageBox::Ok,QString::fromLocal8Bit("确 定"));
	box.setButtonText (QMessageBox::Cancel,QString::fromLocal8Bit("取 消"));
	if(box.exec()==QMessageBox::Ok)
	{
		QSqlQuery query(*sql.db);		
		QString strSheetNo=ui.lineEdit_No->text();
		QString strsql = "delete from yk_instorage where sheetno ='"+strSheetNo+"'"; //where ID > 1
		query.exec(strsql);
		strsql = "delete from yk_instorage_public_info where sheetno ='"+strSheetNo+"'"; //where ID > 1
		query.exec(strsql);
		for (i=0;i< rows ;i++)
		{
			QString strName = ui.tableWidget->item(i,1)->text();
			if(ui.radioButton_Add->isChecked() && !ui.radioButton_Minus->isChecked())
				amount = ui.tableWidget->item(i,6)->text().toInt();	
			else
				amount = -ui.tableWidget->item(i,6)->text().toInt();
		
			int kucun = ui.tableWidget->item(i,7)->text().toInt();
			int kucun1=0;
				kucun1 = kucun - amount;
			strsql= "select * from yk_inventory where name ='"+strName+"'";//;//where AbbrName = '"+strName+"'
			query.exec(strsql);

			if(query.next())
			{
				query.prepare("UPDATE yk_inventory SET count= ? WHERE name = '"+strName+"'");
				query.bindValue(0,kucun1);
				query.exec();
			}
		}
		ui.lineEdit_No->setText("");
		ui.lineEdit_Payable->setText("");
		ui.tableWidget->clearContents();
		ui.tableWidget->setRowCount(0);
		ui.tableWidget->clearContents();
		ui.tableWidget->insertRow(0);
	}
}
void DrugStorage::edit(QString strNo)
{
	ui.tableWidget->installEventFilter(this);
	SetEdit(false);
	ui.addButton->setEnabled(false);
	ui.editButton->setEnabled(true);
	QSqlQuery query(*sql.db);	
	query.exec("select * from yk_instorage where sheetno='"+strNo+"'");
	while(query.next())
	{
		ui.lineEdit_No->setText(query.value(1).toString());
		ui.dateTimeEdit->setDateTime(query.value(2).toDateTime());
		int iInputFlag=query.value(3).toString().toInt();
		if(iInputFlag == 1)
			ui.radioButton_Add->setChecked(true);
		else 
			ui.radioButton_Minus->setChecked(true);

		ui.comboBox_supplier->setEditText(query.value(5).toString());
		ui.lineEdit_2->setText(query.value(6).toString());		
	}
	ui.tableWidget->setRowCount(0);
	QSqlQuery query2(*sql.db);	
	query2.exec("select * from yk_instorage where sheetno='"+strNo+"'");
	int row= 0;
	while(query2.next())
	{
		int Num;
		ui.tableWidget->insertRow(row);
		ui.tableWidget->setItem(row,1,new QTableWidgetItem(query2.value(4).toString()));
		QString strName=query2.value(8).toString();
		QString strsql= "select * from sys_drugdictionary where name='"+strName+"'";
		query.exec(strsql);
		while(query.next())
		{
			ui.tableWidget->setItem(row,1,new QTableWidgetItem(query.value(1).toString()));
			ui.tableWidget->setItem(row,2,new QTableWidgetItem(query.value(4).toString()));
			ui.tableWidget->setItem(row,3,new QTableWidgetItem(query.value(5).toString()));
			ui.tableWidget->setItem(row,5,new QTableWidgetItem(query.value(6).toString()));
			ui.tableWidget->setItem(row,8,new QTableWidgetItem(query.value(15).toString()));
			ui.tableWidget->setItem(row,9,new QTableWidgetItem(query.value(16).toString()));//
			ui.tableWidget->setItem(row,10,new QTableWidgetItem(query.value(10).toString()));//
			//Num = query.value(10).toString().toInt();
		}
		Num = query2.value(13).toString().toInt();
		
		strsql= "select * from yk_inventory where name='"+strName+"'";
		query.exec(strsql);
		if(query.next())
		{
			int kucun1 = query.value(7).toString().toInt();
			kucun1 = kucun1 - Num;
			QString strTemp = QString::number(kucun1);
			ui.tableWidget->setItem(row,7,new QTableWidgetItem(strTemp));  //有问题
		}
		ui.tableWidget->setItem(row,6,new QTableWidgetItem(query2.value(13).toString()));
		row++;
	}
}
void DrugStorage::on_saveButton_clicked()
{
	static int iFlag;
	int i=0;
	int amount;
	double unitprice;
	int rows = ui.tableWidget->model()->rowCount();   //行总数
	QString str2; 
	char strtemp[255]={0};

	QString str = str.fromLocal8Bit("警告");
	unitprice = ui.lineEdit_debt->text().toDouble();
	/*if(unitprice<0)
	{
	if(ui.radioButton_Add->isChecked() && !ui.radioButton_Minus->isChecked())
	str2 = str.fromLocal8Bit("付款金额不足，请核对！");
	if(!ui.radioButton_Add->isChecked() && ui.radioButton_Minus->isChecked())
	str2 = str.fromLocal8Bit("收款金额不足，请核对！");
	QMessageBox::warning(this,str,str2,QMessageBox::Ok);
	return;
	}*/

	if(!ui.tableWidget->isEnabled())
	{	
		str2 = str.fromLocal8Bit("已保存过！");		
		QMessageBox box(QMessageBox::Warning,QString::fromLocal8Bit("警告"),str2);
		box.setStandardButtons (QMessageBox::Ok);
		box.setButtonText (QMessageBox::Ok,QString::fromLocal8Bit("确 定"));
		box.exec();
		return;
	}

	QSqlQuery query(*sql.db);		
	QString strSheetNo=ui.lineEdit_No->text();
	QString strsql = "select * from yk_instorage where sheetno ='"+strSheetNo+"'"; //where ID > 1
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
	int inputflag;
	for(i=0;i<num;i++)
	{
		QString strName = list[i];
		strsql = "select * from yk_instorage where sheetno ='"+strSheetNo+"'and name ='"+strName+"'"; //where ID > 1
		query.exec(strsql);
		if(query.next())
		{
			amount = query.value(13).toInt();
			inputflag = query.value(3).toInt();
		}
		strsql= "select * from yk_inventory where name ='"+strName+"'";//;//where AbbrName = '"+strName+"'
		query.exec(strsql);
		int kucun;
		if(query.next())
			kucun = query.value(7).toInt();	
		if(inputflag == 1)
		   kucun2 = kucun - amount;
		else 
           kucun2 = kucun + amount;
		query.prepare("UPDATE yk_inventory SET count= ? WHERE name = '"+strName+"'");
		query.bindValue(0,kucun2);
		QString strTemp1 = QString::number(kucun2);
		ui.tableWidget->setItem(i,7,new QTableWidgetItem(strTemp1));
		query.exec();	
	}
	if(num>0)
	{
		strsql = "delete from yk_instorage where sheetno ='"+strSheetNo+"'"; //where ID > 1
		query.exec(strsql);
		strsql = "delete from yk_instorage_public_info where sheetno ='"+strSheetNo+"'"; //where ID > 1
		query.exec(strsql);
	}

	//添加到收费单基本信息表中

	int isheetcount=PublicInfoSheetNo();
	isheetcount++;
	query.prepare("INSERT INTO yk_instorage_public_info VALUES (?, ?, ?, ?, ?, ?, ?)");
	query.bindValue(0, isheetcount);
	query.bindValue(1, ui.lineEdit_No->text());
	query.bindValue(2, ui.dateTimeEdit->dateTime());
	int iInputFlag;
	if(ui.radioButton_Add->isChecked() && !ui.radioButton_Minus->isChecked())
		iInputFlag = 1;
	else 
		iInputFlag = 0;
	QString strTemp = QString::number(iInputFlag);
	query.bindValue(3, strTemp);
	strTemp = QString::number(1);
	query.bindValue(4, strTemp);
	query.bindValue(5, ui.comboBox_supplier->currentText());
	query.bindValue(6, ui.lineEdit_2->text());
	iFlag = query.exec();

	for (i=0;i< rows ;i++)
	{

		if(ui.tableWidget->item(i,6)==NULL||(ui.tableWidget->item(i,6)&& ui.tableWidget->item(i,6)->text()==tr("")))
		{
			sprintf(strtemp,"第%d行入库数量为空，请核对！",i+1);
			str2 = str.fromLocal8Bit(strtemp);		
			QMessageBox box(QMessageBox::Warning,QString::fromLocal8Bit("警告"),str2);
			box.setStandardButtons (QMessageBox::Ok);
			box.setButtonText (QMessageBox::Ok,QString::fromLocal8Bit("确 定"));
			box.exec();
			return;
		}

		int isheetcount=SheetNo();
		isheetcount++;
		query.prepare("INSERT INTO yk_instorage VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)");
		query.bindValue(0, isheetcount);
		query.bindValue(1, ui.lineEdit_No->text());
		query.bindValue(2, ui.dateTimeEdit->dateTime());
		iInputFlag;
		if(ui.radioButton_Add->isChecked() && !ui.radioButton_Minus->isChecked())
			iInputFlag = 1;
		else 
			iInputFlag = 0;
		QString strTemp = QString::number(iInputFlag);
		query.bindValue(3, strTemp);
		strTemp = QString::number(1);
		query.bindValue(4, strTemp);
		query.bindValue(5, ui.comboBox_supplier->currentText());
		query.bindValue(6, ui.lineEdit_2->text());
		if(ui.tableWidget->item(i,0)!=NULL)
		{
			query.bindValue(7, ui.tableWidget->item(i,0)->text());
		}
		else
		{
			QString strTemp = tr("");
			query.bindValue(7,strTemp );
		}
		
		query.bindValue(8, ui.tableWidget->item(i,1)->text());
		query.bindValue(9, ui.tableWidget->item(i,2)->text());
		query.bindValue(10, ui.tableWidget->item(i,3)->text());
		//query.bindValue(11, ui.tableWidget->item(i,4)->text());
		//query.bindValue(12, ui.tableWidget->item(i,5)->text());

		//if(ui.radioButton_Add->isChecked() && !ui.radioButton_Minus->isChecked())
		//{
		//	amount = ui.tableWidget->item(i,6)->text().toInt();
		//	unitprice = ui.tableWidget->item(i,8)->text().toDouble();
		//}else
		//{
		//	amount = -ui.tableWidget->item(i,6)->text().toInt();
		//	unitprice = -ui.tableWidget->item(i,8)->text().toDouble();
		//}
		query.bindValue(12, ui.tableWidget->item(i,5)->text());
		amount = ui.tableWidget->item(i,6)->text().toInt();
		unitprice = ui.tableWidget->item(i,8)->text().toDouble();

		if(iInputFlag==0) 
			query.bindValue(13, amount);
		else
			query.bindValue(13, -1*amount);
		query.bindValue(14, unitprice);
		unitprice = unitprice * amount;
		/*QString strprice= QString::number(unitprice);*/
		query.bindValue(15,unitprice);
		
		iFlag = query.exec();
	}

	for (i=0;i< rows ;i++)
	{	
		QString strName = ui.tableWidget->item(i,1)->text();
		int kucun = ui.tableWidget->item(i,7)->text().toInt();
		int kucun1=0;
		//	kucun1 = kucun + amount;

		amount = ui.tableWidget->item(i,6)->text().toInt();
		if(ui.radioButton_Add->isChecked() && !ui.radioButton_Minus->isChecked())
			kucun1 = kucun + amount;
		else
			kucun1 = kucun - amount;
		

		QString strTemp1 = QString::number(kucun1);
		ui.tableWidget->setItem(i,7,new QTableWidgetItem(strTemp1));

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
			isheetcount=InventorySheetNo();
			isheetcount ++;
			query.bindValue(0, isheetcount);
			query.bindValue(1, strName);
			query.bindValue(2, strName);
			query.bindValue(3, ui.tableWidget->item(i,2)->text());
			query.bindValue(4, ui.tableWidget->item(i,3)->text());
			query.bindValue(6, ui.tableWidget->item(i,5)->text());
			query.bindValue(7, strTemp1);
			iFlag = query.exec();
			
		}
	}

		
	if(iFlag)
	{
		QString str = str.fromLocal8Bit("提示");
		QString str2 = str.fromLocal8Bit("保存成功！");
		QMessageBox box(QMessageBox::Warning,QString::fromLocal8Bit("警告"),str2);
		box.setStandardButtons (QMessageBox::Ok);
		box.setButtonText (QMessageBox::Ok,QString::fromLocal8Bit("确 定"));
		box.exec();
		SetEdit(false);
		ui.saveButton->setEnabled(false);
		ui.discardButton->setEnabled(false);
		ui.editButton->setEnabled(true);
		ui.deleteButton->setEnabled(false);
		ui.addRowButton->setEnabled(false);
		ui.deleteRowButton->setEnabled(false);
	}
	else
	{
		QString str = str.fromLocal8Bit("提示");
		QString str2 = str.fromLocal8Bit("保存失败！");
		QMessageBox box(QMessageBox::Warning,QString::fromLocal8Bit("警告"),str2);
		box.setStandardButtons (QMessageBox::Ok);
		box.setButtonText (QMessageBox::Ok,QString::fromLocal8Bit("确 定"));
		box.exec();
	}
	//ui.editButton->setEnabled(true);
	//ui.saveButton->setEnabled(false);
}
void DrugStorage::on_discardButton_clicked()
{
	ui.lineEdit_No->setText("");
	ui.lineEdit_debt->setText("");
	//ui.lineEdit_Buyer->setText("");
	ui.lineEdit_Payable->setText("");
	ui.tableWidget->setRowCount(0);
	ui.tableWidget->clearContents();
	ui.tableWidget->insertRow(0);
	ui.addRowButton->setEnabled(false);
	ui.deleteRowButton->setEnabled(false);
	
}
void DrugStorage::on_editButton_clicked()
{
	SetEdit(true);
	ui.saveButton->setEnabled(true);
	ui.discardButton->setEnabled(true);
	ui.deleteButton->setEnabled(true);
	ui.addRowButton->setEnabled(true);
	ui.deleteRowButton->setEnabled(true);
	ui.deleteButton->setEnabled(true);
}
void DrugStorage::on_printButton_clicked()
{
	QPrinter       printer( QPrinter::PrinterResolution );
	QPrintDialog   dialog( &printer, this );
	if ( dialog.exec() == QDialog::Accepted ) print( &printer );
}
void DrugStorage::on_previewButton_clicked()
{
	filePrintPreview();
}
void DrugStorage::filePrintPreview()
{
	// 打印预览对话框
	QPrinter             printer( QPrinter::PrinterResolution );
	QPrintPreviewDialog  preview( &printer, this );
	preview.setWindowTitle("preview");
	preview.setMinimumSize(1000,900);
	connect( &preview, SIGNAL(paintRequested(QPrinter*)), SLOT(print(QPrinter*)) );
	preview.exec();
}
void DrugStorage::print( QPrinter* printer )
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
	image=image.grabWidget(ui.tableWidget,-35,0,900, 1000);
	painter.drawPixmap(page4,image);

	//printTableWidget(ui.tableWidget,"preview",printer);
}
void DrugStorage::pay(const QString &)
{
	double iamount = ui.lineEdit_Paid->text().toDouble();
	double icurrentamount = ui.lineEdit_Payable->text().toDouble();
	iamount = iamount - icurrentamount;
	QString strcurrentamount = QString::number(iamount);
	ui.lineEdit_debt->setText(strcurrentamount);

}
void DrugStorage::getItem(int row,int column)//计算费用
{
	QString str2;
	QString str = str.fromLocal8Bit("警告");
	if (column==6)
	{
		if (ui.tableWidget->item(row,column)->text()==NULL) return;
		if (ui.tableWidget->item(row,column+2)->text()==NULL) return;

		int icount = ui.tableWidget->item(row,column)->text().toInt();
		if(icount<0)
		{
			str2 = str.fromLocal8Bit("收货数量不能为负，请核对！");
			QMessageBox box(QMessageBox::Warning,QString::fromLocal8Bit("警告"),str2);
			box.setStandardButtons (QMessageBox::Ok);
			box.setButtonText (QMessageBox::Ok,QString::fromLocal8Bit("确 定"));
			box.exec();
			QString stramount = QString::number(0);
			ui.tableWidget->setItem(row,column,new QTableWidgetItem(stramount));
			return;
		}
		double unitprice = ui.tableWidget->item(row,column+2)->text().toDouble();
		double amount = icount*unitprice;
		QString stramount = QString::number(amount);
		ui.tableWidget->setItem(row,column+3,new QTableWidgetItem(stramount));

		double icurrentamount = TotalPrice();
		QString strcurrentamount = QString::number(icurrentamount);
		 
		//累加
		ui.lineEdit_Payable->setText(strcurrentamount);
		
		double iamount = ui.lineEdit_Paid->text().toInt();
		iamount = iamount - icurrentamount;
		strcurrentamount = QString::number(iamount);
		ui.lineEdit_debt->setText(strcurrentamount);

		
	}
	if(column==0)
	{
		list_widget->close();
		QString strText;
		if(ui.tableWidget->item(row,0)==NULL)  return;

		strText =  ui.tableWidget->item(row,0)->text();
		if(strText.at(0)== QChar('1')) return;

		//list_widget->setGeometry(103, 160+row*30, 150, 280);
		QPoint GlobalPoint(ui.tableWidget->mapFrom(ui.tableWidget,QPoint(0, 0)));//获取控件在窗体中的坐标
		if(row<8)
			list_widget->setGeometry(GlobalPoint.x()+80, GlobalPoint.y()+40*(row+1), 150, 280);
		list_widget->show();
		QSqlQuery query(*sql.db);	
		strText =  ui.tableWidget->item(row,0)->text();
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
void DrugStorage::keyPressEvent(QKeyEvent *e) {
	list_widget->setFocus();
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

				int row = ui.tableWidget->currentRow();
				QSqlQuery query(*sql.db);	

				QString strsql= "select * from sys_drugdictionary where name='"+strName+"'";//;//where AbbrName = '"+strName+"'
				query.exec(strsql);
				while(query.next())
				{
					ui.tableWidget->setItem(row,0,new QTableWidgetItem(query.value(22).toString()));
					ui.tableWidget->setItem(row,1,new QTableWidgetItem(query.value(1).toString()));
					ui.tableWidget->setItem(row,2,new QTableWidgetItem(query.value(4).toString()));
					ui.tableWidget->setItem(row,3,new QTableWidgetItem(query.value(5).toString()));
					ui.tableWidget->setItem(row,5,new QTableWidgetItem(query.value(6).toString()));
					ui.tableWidget->setItem(row,8,new QTableWidgetItem(query.value(15).toString()));
					ui.tableWidget->setItem(row,9,new QTableWidgetItem(query.value(16).toString()));//
					ui.tableWidget->setItem(row,10,new QTableWidgetItem(query.value(10).toString()));//

					ui.tableWidget->setFocus();
					ui.tableWidget->setCurrentCell(row, 0, QItemSelectionModel::Deselect);
					ui.tableWidget->setCurrentCell(row,6, QItemSelectionModel::Select);
				}
				QString strsql1= "select * from yk_inventory where name='"+strName+"'";//;//where AbbrName = '"+strName+"'
				query.exec(strsql1);	
				if(query.next())
				{
					ui.tableWidget->setItem(row,7,new QTableWidgetItem(query.value(7).toString()));
				}
				else 
				{
					QString strTemp = QString::number(0);
					ui.tableWidget->setItem(row,7,new QTableWidgetItem(strTemp));
				}
			}

			list_widget->hide();
		} else {
			list_widget->hide();
			//QLineEdit::keyPressEvent(e);
		}
	} 
	else {
			int key = e->key();
			if (Qt::Key_Enter == key || Qt::Key_Return == key) {
				int row = ui.tableWidget->currentRow();
				int count = ui.tableWidget->rowCount();
				ui.tableWidget->insertRow(count);
				ui.tableWidget->setCurrentCell(row, 6, QItemSelectionModel::Deselect);
				ui.tableWidget->setCurrentCell(row+1, 0, QItemSelectionModel::Select);
				//QCursor cursorAction;
				//ui.tableWidget->setCursor(cursorAction);
			}
			if (Qt::Key_F5 == key ) {
				on_saveButton_clicked();
			}

	}
}