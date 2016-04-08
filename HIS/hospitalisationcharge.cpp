#include "hospitalisationcharge.h"
#include <QtGui>
#include "connectsql.h"
#include "clinicdrugfilter.h"
#include "getdoctor.h"

extern ConnectSql sql;

HospitalisationCharge::HospitalisationCharge(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	initUI();

	package= new Package;

	list_widget = new QListWidget(this);
	list_widget->setWindowFlags(Qt::FramelessWindowHint);
	list_widget->close();
	installEventFilter(list_widget);
	ui.tableWidget->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
	ui.tableWidget->setStyleSheet("QTableWidget{border: 1px solid gray;	background-color: transparent;	selection-color: grey;}");
	ui.tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section {background-color:white;color: black;padding-left: 4px;border: 1px solid #6c6c6c;};"
		"color: white;padding-left: 4px;border: 1px solid #6c6c6c;}"
		"QHeaderView::section:checked{background-color: white;color: black;}");	
	connect(ui.tableWidget,SIGNAL(cellChanged(int,int)),this,SLOT(getItem(int,int)));
	connect(ui.hospitalisationNocomboBox,SIGNAL(currentIndexChanged(QString)),this,SLOT(getInfo(QString)));
	connect(ui.hintEdit->document(),SIGNAL(contentsChanged()),this,SLOT(textAreaChanged()));
	connect(package,SIGNAL(showPackage(QString)),this,SLOT(addPackage(QString)));
	ui.tableWidget->installEventFilter(this);
	ui.doctorEdit->installEventFilter(this);
	
}
void HospitalisationCharge::initUI()
{
	QSqlQuery query(*sql.db);		
	query.exec("select * from zy_patientinfo ORDER BY id ASC");
	QStringList list;
	while(query.next())
	{
		QString str = query.value(1).toString();
		list.append(str);
	}
	ui.hospitalisationNocomboBox->clear();
	ui.hospitalisationNocomboBox->addItems(list);

	QDateTime current_date_time = QDateTime::currentDateTime();
	ui.dateTimeEdit->setDateTime(current_date_time);
	iRow=0;
	ui.saveButton->setEnabled(false);
	ui.editButton->setEnabled(false);
	ui.discardButton->setEnabled(false);
	ui.deleteButton->setEnabled(false);
	ui.addrowButton->setEnabled(false);
	ui.deleterowButton->setEnabled(false);
	ui.packageButton->setEnabled(false);
	dueincome=0.0;
//	setEdit(false);
	ui.sheetmakerEdit->setEnabled(false);
	ui.sheetmakerEdit->setText(sql.struser);
	Isupdate=false;
}
void HospitalisationCharge::on_addButton_clicked()
{
	on_discardButton_clicked();
	initUI();
	installEventFilter(this);
	setEdit(true);
	QSqlQuery query(*sql.db);		
	query.exec("select * from zy_chargesheet");
	int icount=0;
	while(query.next())
	{
		icount++;
	}
	itotalcount=icount+1;
	QString strSheetNo= "ZYSF"+QString::number(itotalcount, 10);
	ui.sheetNoEdit->setText(strSheetNo);
	ui.saveButton->setEnabled(true);
	ui.addrowButton->setEnabled(true);
	ui.deleterowButton->setEnabled(true);
	ui.editButton->setEnabled(false);
	ui.deleteButton->setEnabled(false);
	ui.discardButton->setEnabled(true);
	ui.packageButton->setEnabled(true);
	QString strNo = ui.hospitalisationNocomboBox->currentText();
	getInfo(strNo);
	ui.tableWidget->insertRow(0);
}
void HospitalisationCharge::on_saveButton_clicked()
{
	QSqlQuery query(*sql.db);		
	QString strNo=ui.sheetNoEdit->text();

	if(Isupdate)
	{
		QString strsql = "select *from zy_chargesheet where sheetno ='"+strNo+"'"; 
		query.exec(strsql);
		while(query.next())
		{
			itotalcount=query.value(0).toInt();
		}
	}
	QString strsql = "delete from zy_chargesheet where sheetno ='"+strNo+"'"; 
	query.exec(strsql);
	strsql = "delete from zy_chargedetail where sheetno ='"+strNo+"'"; 
	query.exec(strsql);

	int irows = ui.tableWidget->model()->rowCount();
	for (int i=0;i<irows;i++)
	{
		if( ui.tableWidget->item(i,0)==NULL) continue;
		if( ui.tableWidget->item(i,0)==NULL||ui.tableWidget->item(i,0)->text()=="")
		{
			/*QMessageBox::information(this,QString::fromLocal8Bit("警告"),QString::fromLocal8Bit("请选择药品"));
			return;*/
		}
		if( ui.tableWidget->item(i,7)==NULL||ui.tableWidget->item(i,7)->text()=="")
		{
			QMessageBox box(QMessageBox::Warning,QString::fromLocal8Bit("警告"),QString::fromLocal8Bit("请填写数量"));
			box.setStandardButtons (QMessageBox::Ok);
			box.setButtonText (QMessageBox::Ok,QString::fromLocal8Bit("确 定"));
			box.exec();
			return;
		}
	}
	//添加到收费单基本信息表中
	query.prepare("INSERT INTO zy_chargesheet VALUES (?,?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)");
	query.bindValue(0, itotalcount);
	query.bindValue(1, ui.sheetNoEdit->text());
	query.bindValue(2, ui.dateTimeEdit->dateTime());
	query.bindValue(3, ui.warehouseEdit->text());
	query.bindValue(4, ui.hospitalisationNocomboBox->currentText());
	query.bindValue(5, ui.nameEdit->text());
	query.bindValue(6, ui.genderEdit->text());
	QString strage = ui.ageEdit->text();
	query.bindValue(7, strage.toInt());
	query.bindValue(8, ui.doctorEdit->text());
	query.bindValue(9, ui.departmentEdit->text());
	query.bindValue(10, "");
	query.bindValue(11, ui.bedEdit->text());
	query.bindValue(12, ui.sheetmakerEdit->text());//制单
	query.bindValue(13, ui.remarkEdit->text());
	query.bindValue(14, dueincome);
	query.exec();
	//添加到收费单明细表中
	int rows = ui.tableWidget->model()->rowCount();   //行总数
	QString strtype;
	QString strsheetmaker;
	QString stritemname;
	QString strunit;
	int icount;
	double unitprice;
	double amount;

	strsheetmaker=ui.sheetmakerEdit->text();
	query.exec("select * from zy_chargedetail");
	int temp=0;
	while(query.next())
	{
		temp++;
	}
	bool issuccess =false;
	for (int i=0;i<rows;i++)
	{
		if(ui.tableWidget->item(i,1)==NULL||ui.tableWidget->item(i,7)==NULL) continue;
		stritemname = ui.tableWidget->item(i,1)->text();
		strunit = ui.tableWidget->item(i,5)->text();
		icount= ui.tableWidget->item(i,7)->text().toInt();
		unitprice = ui.tableWidget->item(i,8)->text().toDouble();
		amount= ui.tableWidget->item(i,9)->text().toDouble();
		if (ui.tableWidget->item(i,10)!=NULL)
		{
			strtype=ui.tableWidget->item(i,10)->text();
		}		
		query.prepare("INSERT INTO zy_chargedetail VALUES (?,?,?,?,?,?,?,?,?,?,?,?,?)");
		query.bindValue(0, temp+i+1);
		query.bindValue(1, ui.sheetNoEdit->text());
		query.bindValue(2, strsheetmaker);//制单
		query.bindValue(3, strtype);
		query.bindValue(4, stritemname);  
		query.bindValue(5, strunit);
		query.bindValue(6, icount);
		query.bindValue(7, unitprice);
		query.bindValue(8, amount);
		query.bindValue(9, ui.dateTimeEdit->dateTime());
		query.bindValue(10, ui.hospitalisationNocomboBox->currentText());
		QString strdrugtype;
		if (ui.tableWidget->item(i,11)!=NULL)
		{
			strdrugtype= ui.tableWidget->item(i,11)->text();
		}
		 
		if (strdrugtype==QString::fromLocal8Bit("西药")||strdrugtype==QString::fromLocal8Bit("中成药")||strdrugtype==QString::fromLocal8Bit("中草药"))
		{
			query.bindValue(11, 1);
		}
		else if (strdrugtype==QString::fromLocal8Bit("医疗项目"))
		{
			query.bindValue(11, 2);
		}
		else if (strdrugtype==QString::fromLocal8Bit("卫生材料"))
		{
			query.bindValue(11, 3);
		}
		else
		{
			query.bindValue(11, NULL);
		}
		if(ui.tableWidget->item(i,12)!=NULL)
			query.bindValue(12, ui.tableWidget->item(i,12)->text());
		else
			query.bindValue(12, NULL);
		issuccess = query.exec();
	}
	if (issuccess)
	{
		QMessageBox box(QMessageBox::Warning,QString::fromLocal8Bit("提示"),QString::fromLocal8Bit("保存成功"));
		box.setStandardButtons (QMessageBox::Ok);
		box.setButtonText (QMessageBox::Ok,QString::fromLocal8Bit("确 定"));
		box.exec();
	}
	ui.editButton->setEnabled(true);
	ui.saveButton->setEnabled(false);
	ui.addrowButton->setEnabled(false);
	ui.deleterowButton->setEnabled(false);
	ui.discardButton->setEnabled(false);
	ui.deleteButton->setEnabled(false);
	ui.packageButton->setEnabled(false);
	setEdit(false);
	ui.sheetmakerEdit->setEnabled(false);
	ui.sheetmakerEdit->setText(sql.struser);

	strNo = ui.hospitalisationNocomboBox->currentText();
	getInfo(strNo);
}
void HospitalisationCharge::on_discardButton_clicked()
{
	ui.sheetNoEdit->clear();
	ui.nameEdit->clear();
	ui.ageEdit->clear();
	ui.genderEdit->clear();
	ui.bedEdit->clear();
	ui.departmentEdit->clear();
	ui.doctorEdit->clear();
	ui.hintEdit->clear();
	ui.remarkEdit->clear();
	ui.tableWidget->setRowCount(0);
}
void HospitalisationCharge::on_editButton_clicked()
{
	ui.deleteButton->setEnabled(true);
	ui.addrowButton->setEnabled(true);
	ui.deleterowButton->setEnabled(true);
	ui.saveButton->setEnabled(true);
	ui.packageButton->setEnabled(true);
	ui.discardButton->setEnabled(true);
	ui.packageButton->setEnabled(true);
	setEdit(true);
}
void HospitalisationCharge::on_deleteButton_clicked()
{
	QSqlQuery query(*sql.db);		
	QString strSheetNo=ui.sheetNoEdit->text();

	query.exec("select* from zy_chargesheet"); 
	int count=0;
	QString lastNo;
	while (query.next())
	{
		lastNo=query.value(1).toString();
	}
	if (lastNo!=strSheetNo) 
	{
		QMessageBox box(QMessageBox::Warning,QString::fromLocal8Bit("警告"),QString::fromLocal8Bit("删除该单会造成重复"));
		box.setStandardButtons (QMessageBox::Ok);
		box.setButtonText (QMessageBox::Ok,QString::fromLocal8Bit("确 定"));
		box.exec();
		return;
	}

	QMessageBox box(QMessageBox::Warning,QString::fromLocal8Bit("警告"),QString::fromLocal8Bit("确认删除该单？"));
	box.setStandardButtons (QMessageBox::Ok|QMessageBox::Cancel);
	box.setButtonText (QMessageBox::Ok,QString::fromLocal8Bit("确 定"));
	box.setButtonText (QMessageBox::Cancel,QString::fromLocal8Bit("取 消"));
	if(box.exec()==QMessageBox::Ok)
	{
		QString strsql = "delete from zy_chargesheet where sheetno ='"+strSheetNo+"'"; //where ID > 1
		query.exec(strsql);

		strsql = "delete from zy_chargedetail where sheetno ='"+strSheetNo+"'"; //where ID > 1
		query.exec(strsql);
		on_discardButton_clicked();
	}
}
void HospitalisationCharge::on_previewButton_clicked()
{
	filePrintPreview();
}
void HospitalisationCharge::on_printButton_clicked()
{
	QPrinter       printer( QPrinter::PrinterResolution );
	QPrintDialog   dialog( &printer, this );
	if ( dialog.exec() == QDialog::Accepted ) print( &printer );
}
void HospitalisationCharge::on_addrowButton_clicked()
{
	//表格增加一行
	int irows = ui.tableWidget->model()->rowCount();
	if(irows>0)
	{
		if( ui.tableWidget->item(irows-1,0)==NULL) return;
		if( ui.tableWidget->item(irows-1,7)==NULL||ui.tableWidget->item(irows-1,7)->text()=="")
		{
			QMessageBox box(QMessageBox::Warning,QString::fromLocal8Bit("警告"),QString::fromLocal8Bit("请填写数量"));
			box.setStandardButtons (QMessageBox::Ok);
			box.setButtonText (QMessageBox::Ok,QString::fromLocal8Bit("确 定"));
			box.exec();
			return;
		}
	}
	ui.tableWidget->insertRow(irows);
	iRow=irows;
}
void HospitalisationCharge::on_deleterowButton_clicked()
{

	QMessageBox box(QMessageBox::Warning,QString::fromLocal8Bit("警告"),QString::fromLocal8Bit("确认删除选择行？"));
	box.setStandardButtons (QMessageBox::Ok|QMessageBox::Cancel);
	box.setButtonText (QMessageBox::Ok,QString::fromLocal8Bit("确 定"));
	box.setButtonText (QMessageBox::Cancel,QString::fromLocal8Bit("取 消"));
	if(box.exec()==QMessageBox::Ok)
	{
		int row = ui.tableWidget->currentRow();  
		ui.tableWidget->removeRow(row);
	}
}
void HospitalisationCharge::on_packageButton_clicked()
{	
	package->setWindowModality(Qt::WindowModal);
	package->show();
}
void HospitalisationCharge::filePrintPreview()
{
	// 打印预览对话框
	QPrinter             printer( QPrinter::PrinterResolution );
	QPrintPreviewDialog  preview( &printer, this );
	preview.setWindowTitle(QString::fromLocal8Bit("预览"));
	preview.setMinimumSize(800,600);
	connect( &preview, SIGNAL(paintRequested(QPrinter*)), SLOT(print(QPrinter*)) );
	preview.exec();
}
void HospitalisationCharge::print( QPrinter* printer )
{
	QPainter painter( printer );
	int      w = printer->pageRect().width();
	int      h = printer->pageRect().height();
	QRect    page( w/50, h/50, w, h );
	QRect    page4( w/30, h/10, w, h );
	QFont    font = painter.font();
	font.setPointSize(8);
	painter.setFont( font );
	painter.drawText( page, Qt::AlignTop    | Qt::AlignHCenter, QString::fromLocal8Bit(" 三河市燕郊镇卫生院住院收费") );
	
	QRect    rect( w/60, h/31, w, h );
	QString str = QString::fromLocal8Bit("住院号：")+ui.hospitalisationNocomboBox->currentText()+ QString::fromLocal8Bit("   姓名：")+ui.nameEdit->text()+ QString::fromLocal8Bit("   住院科室：")+ui.departmentEdit->text()+ QString::fromLocal8Bit("   主治医生：")+ui.doctorEdit->text()+ QString::fromLocal8Bit("   单号：")+ui.sheetNoEdit->text()+QString::fromLocal8Bit("   时间：")+ui.dateTimeEdit->dateTime().toString("yyyy-MM-dd hh:mm:ss")+ QString::fromLocal8Bit("   制单人：")+ui.sheetmakerEdit->text();
	painter.drawText( rect, Qt::AlignTop    | Qt::AlignHCenter,str);

	QPixmap image;
	image=image.grabWidget(ui.tableWidget,0,0,1000, 1000);
	//	painter.drawPixmap(page4,image);

	painter.begin(this);
	painter.setPen(QPen(Qt::black,4,Qt::SolidLine));//设置画笔形式 
	painter.setBrush(QBrush(Qt::white,Qt::SolidPattern));//设置画刷形式 
	int row = ui.tableWidget->rowCount();
	int col = ui.tableWidget->columnCount();
	double cellwidth = (w-40)/col;
	double cellheight = 160;
	double upmargin = h/30;
	//计算总页数
	int firstpagerow = (h-upmargin)/160;//第一页上方空白为750,下方为50
	int everypagerow = (h-100)/160;//后面每页的空白为100
	int pagecount = 0;

	//xp系统
	if(sql.windowsFlag==QSysInfo::WV_5_1||sql.windowsFlag==QSysInfo::WV_5_0||sql.windowsFlag==QSysInfo::WV_5_2||sql.windowsFlag==QSysInfo::WV_4_0)//判断当前系统
	{
		cellwidth= (w-100)/col;
		cellheight=60;
		upmargin = h/30;
		firstpagerow = (h-upmargin)/cellheight;
		everypagerow = (h-20)/cellheight;
	}
	double leftmargin = (w-cellwidth*col)/2;

	if (row>firstpagerow)
	{
		pagecount = (row -firstpagerow)/everypagerow;
		int remain  = (row -firstpagerow)%everypagerow;
		if (remain!=0)
		{
			pagecount+=2;
		}
		else
		{
			pagecount+=1;
		}
	}
	else
	{
		pagecount=1;
	}
	if (pagecount == 1)
	{

		QStringList list;
		for (int j =0;j<col;j++)
		{
			list.append(ui.tableWidget->horizontalHeaderItem(j)->text());
		}
		for (int i=0;i<row;i++)
		{
			for (int j=0;j<col;j++)
			{
				if (ui.tableWidget->item(i,j)==NULL)
				{
					list.append("");
					continue;
				}
				list.append(ui.tableWidget->item(i,j)->text());
			}
		}
		for (int i=0;i<row+1;i++)
		{
			for (int j=0;j<col;j++)
			{
				painter.drawRect(leftmargin+j*cellwidth,upmargin+cellheight*(i+1),cellwidth,cellheight);
				QRect rect(leftmargin+j*cellwidth,upmargin+cellheight*(i+1),cellwidth,cellheight);
				painter.drawText( rect, Qt::AlignVCenter    | Qt::AlignHCenter, list.at(i*col+j) );//ui.tableWidget->item(i,j)->text()
			}
		}
		painter.end();
	}
	else
	{
		//首页
		QStringList list;
		for (int j =0;j<col;j++)
		{
			list.append(ui.tableWidget->horizontalHeaderItem(j)->text());
		}
		for (int i=0;i<firstpagerow;i++)
		{
			for (int j=0;j<col;j++)
			{
				if (ui.tableWidget->item(i,j)==NULL)
				{
					list.append("");
					continue;
				}
				list.append(ui.tableWidget->item(i,j)->text());
			}
		}
		for (int i=0;i<firstpagerow+1;i++)
		{
			for (int j=0;j<col;j++)
			{
				painter.drawRect(leftmargin+j*cellwidth,upmargin+cellheight*(i+1),cellwidth,cellheight);
				QRect rect(leftmargin+j*cellwidth,upmargin+cellheight*(i+1),cellwidth,cellheight);
				painter.drawText( rect, Qt::AlignVCenter    | Qt::AlignHCenter, list.at(i*col+j) );//ui.tableWidget->item(i,j)->text()
			}
		}
		printer->newPage();
		//占满的页面
		for (int k = 0;k<pagecount-2;k++)
		{
			list.clear();
			for (int i=firstpagerow+k*everypagerow;i<firstpagerow+(k+1)*everypagerow;i++)
			{
				for (int j=0;j<col;j++)
				{
					if (ui.tableWidget->item(i,j)==NULL)
					{
						list.append("");
						continue;
					}
					list.append(ui.tableWidget->item(i,j)->text());
				}
			}
			for (int i=0;i<everypagerow;i++)
			{
				for (int j=0;j<col;j++)
				{
					painter.drawRect(leftmargin+j*cellwidth,50+cellheight*(i),cellwidth,cellheight);
					QRect rect(leftmargin+j*cellwidth,50+cellheight*(i),cellwidth,cellheight);
					painter.drawText( rect, Qt::AlignVCenter    | Qt::AlignHCenter, list.at(i*col+j) );//ui.tableWidget->item(i,j)->text()
				}
			}
			printer->newPage();
		}
		//
		list.clear();
		for (int i=firstpagerow+(pagecount-2)*everypagerow;i<row;i++)
		{
			for (int j=0;j<col;j++)
			{
				if (ui.tableWidget->item(i,j)==NULL)
				{
					list.append("");
					continue;
				}
				list.append(ui.tableWidget->item(i,j)->text());
			}
		}
		for (int i=0;i<row-firstpagerow-(pagecount-2)*everypagerow;i++)
		{
			for (int j=0;j<col;j++)
			{
				painter.drawRect(leftmargin+j*cellwidth,50+cellheight*(i+1),cellwidth,cellheight);
				QRect rect(leftmargin+j*cellwidth,50+cellheight*(i+1),cellwidth,cellheight);
				painter.drawText( rect, Qt::AlignVCenter    | Qt::AlignHCenter, list.at(i*col+j) );//ui.tableWidget->item(i,j)->text()
			}
		}
		painter.end();
	}
}
void HospitalisationCharge::getInfo(QString strinfo)
{
	QSqlQuery query(*sql.db);		
	query.exec("select * from zy_patientinfo where hospitalisationno= '"+strinfo+"'");
	QString strnursinglevel,strdepartment,strdoctor;
	while(query.next())
	{
		ui.nameEdit->setText(query.value(4).toString());
		ui.genderEdit->setText(query.value(5).toString());
		ui.ageEdit->setText(query.value(6).toString());
		ui.doctorEdit->setText(query.value(14).toString());
		ui.departmentEdit->setText(query.value(13).toString());
		ui.bedEdit->setText(query.value(17).toString());

		strnursinglevel=query.value(16).toString();
		strdepartment=query.value(13).toString();
		strdoctor=query.value(14).toString();
	}

	double totalpay=0.0;
	double totalfee=0.0;
	query.exec("select * from zy_pay where hospitalisationno= '"+strinfo+"'");
	while(query.next())
	{
		totalpay +=query.value(8).toDouble();
	}
	query.exec("select * from zy_chargedetail where hospitalisationno= '"+strinfo+"'");
	while(query.next())
	{
		totalfee +=query.value(8).toDouble();
	}
	QString strpay = QString::fromLocal8Bit("累计交款：")+QString::number(totalpay)+"           ";
	QString strfee = QString::fromLocal8Bit("累计消费：")+QString::number(totalfee)+"\n";
	QString strremain = QString::fromLocal8Bit("最新余额：")+QString::number(totalpay-totalfee);
	QString strremark = strpay+strfee+strremain+"           "+QString::fromLocal8Bit("费用类型：")+"   "+"\n"+QString::fromLocal8Bit("护理级别：")+strnursinglevel+"   "+QString::fromLocal8Bit("住院科室：")+strdepartment+"\n"+QString::fromLocal8Bit("主治医生：")+strdoctor;
	ui.hintEdit->setText(strremark);
}
void HospitalisationCharge::getItem(int row,int column)//计算费用
{
	if (column==7)
	{
		if (ui.tableWidget->item(row,column)==NULL) return;
		if (ui.tableWidget->item(row,column+1)==NULL) return;

		int icount = ui.tableWidget->item(row,column)->text().toInt();
		double unitprice = ui.tableWidget->item(row,column+1)->text().toDouble();
		double amount = icount*unitprice;
		QString stramount = QString::number(amount);
		ui.tableWidget->setItem(row,column+2,new QTableWidgetItem(stramount));
		
		int rows = ui.tableWidget->model()->rowCount();   //行总数
		dueincome=0.0;
		for (int i=0;i<rows;i++)
		{
			if(ui.tableWidget->item(i,9)==NULL)
				continue;
			dueincome+=ui.tableWidget->item(i,9)->text().toDouble();
		}

		//int row = ui.tableWidget->rowCount();
		//if (ui.tableWidget->itemAt(row,0)==NULL) return;
		//ui.tableWidget->insertRow(row);
	}
	if (column==0)
	{
		list_widget->close();
		QString strText;
		if(ui.tableWidget->item(row,0)==NULL)  return;

		strText =  ui.tableWidget->item(row,0)->text();
		if(strText.at(0)== QChar('1')) return;

		//list_widget->setGeometry(103, 280+row*30, 150, 250);
		QPoint GlobalPoint(ui.addButton->mapToGlobal(QPoint(0, 0)));//获取控件在窗体中的坐标
		list_widget->setGeometry(GlobalPoint.x(), GlobalPoint.y(), 150, 280);
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
void HospitalisationCharge::textAreaChanged()
{
	QTextDocument *document=qobject_cast<QTextDocument*>(sender());  
	document->adjustSize();  
	if(document){  
		QTextEdit *editor=qobject_cast<QTextEdit*>(document->parent()->parent());  
		if (editor){  
			int newheight = document->size().rheight()+10;  
			if (newheight != editor->height()){  
				editor->setFixedHeight(newheight);  
			}  
		}  
	} 
}
void HospitalisationCharge::setEdit(bool IsEdit)
{
	if (IsEdit==true)
	{
		//ui.genderEdit->setEnabled(true);
		ui.warehouseEdit->setEnabled(true);
		ui.dateTimeEdit->setEnabled(true);
		//ui.departmentEdit->setEnabled(true);
		//ui.doctorEdit->setEnabled(true);
		//ui.hintEdit->setEnabled(true);
		ui.nameEdit->setEnabled(true);
		ui.sheetNoEdit->setEnabled(true);
		ui.remarkEdit->setEnabled(true);
		ui.tableWidget->setEnabled(true);
		ui.hospitalisationNocomboBox->setEnabled(true);
		//ui.bedEdit->setEnabled(true);
	}
	else
	{
		ui.genderEdit->setEnabled(false);
		ui.warehouseEdit->setEnabled(false);
		ui.dateTimeEdit->setEnabled(false);
		ui.departmentEdit->setEnabled(false);
		ui.doctorEdit->setEnabled(false);
		ui.hintEdit->setEnabled(false);
		ui.nameEdit->setEnabled(false);
		ui.sheetNoEdit->setEnabled(false);
		ui.remarkEdit->setEnabled(false);
		ui.tableWidget->setEnabled(false);
		ui.hospitalisationNocomboBox->setEnabled(false);
		ui.bedEdit->setEnabled(false);
		ui.ageEdit->setEnabled(false);
	}
}
void HospitalisationCharge::edit(QString strNo)
{
	ui.addButton->setEnabled(false);
	ui.editButton->setEnabled(true);
	QString strhospitalNo;
	setEdit(false);
	Isupdate=true;
	QSqlQuery query(*sql.db);	
	query.exec("select * from zy_chargesheet where sheetno='"+strNo+"' order by id");
	while(query.next())
	{
		ui.sheetNoEdit->setText(query.value(1).toString());
		ui.dateTimeEdit->setDateTime(query.value(2).toDateTime());
		ui.warehouseEdit->setText(query.value(3).toString());

		strhospitalNo = query.value(4).toString();
		for (int i =0;i<ui.hospitalisationNocomboBox->count();i++)
		{
			if (ui.hospitalisationNocomboBox->itemText(i)==strhospitalNo)
			{
				ui.hospitalisationNocomboBox->setCurrentIndex(i);
			}
		}
		//ui.hospitalisationNocomboBox->setEditText(query.value(4).toString());
		ui.nameEdit->setText(query.value(5).toString());
		ui.genderEdit->setText(query.value(6).toString());
		ui.ageEdit->setText(query.value(7).toString());
		ui.doctorEdit->setText(query.value(8).toString());
		ui.departmentEdit->setText(query.value(9).toString());
		ui.bedEdit->setText(query.value(11).toString());
		ui.sheetmakerEdit->setText(query.value(12).toString());
		ui.remarkEdit->setText(query.value(13).toString());
	}
	ui.tableWidget->setRowCount(0);
	QSqlQuery query2(*sql.db);	
	query2.exec("select * from zy_chargedetail where sheetno='"+strNo+"'order by id");
	int row= 0;
	while(query2.next())
	{
		ui.tableWidget->insertRow(row);
		ui.tableWidget->setItem(row,1,new QTableWidgetItem(query2.value(4).toString()));
		QString strName=query2.value(4).toString();
		QString strsql= "select * from sys_drugdictionary where name='"+strName+"'";
		query.exec(strsql);
		while(query.next())
		{
			ui.tableWidget->setItem(row,0,new QTableWidgetItem(query.value(22).toString()));
			ui.tableWidget->setItem(row,1,new QTableWidgetItem(query.value(1).toString()));
			ui.tableWidget->setItem(row,2,new QTableWidgetItem(query.value(4).toString()));
			ui.tableWidget->setItem(row,3,new QTableWidgetItem(query.value(5).toString()));
			//ui.tableWidget->setItem(iRow,4,new QTableWidgetItem(query.value(6).toString()));//批号
			ui.tableWidget->setItem(row,5,new QTableWidgetItem(query.value(6).toString()));
			ui.tableWidget->setItem(row,8,new QTableWidgetItem(query.value(15).toString()));
			ui.tableWidget->setItem(row,10,new QTableWidgetItem(query.value(10).toString()));//
			ui.tableWidget->setItem(row,11,new QTableWidgetItem(query.value(14).toString()));//
			ui.tableWidget->setItem(row,12,new QTableWidgetItem(query.value(13).toString()));//
		}
		ui.tableWidget->setItem(row,7,new QTableWidgetItem(query2.value(6).toString()));
		ui.tableWidget->setItem(row,8,new QTableWidgetItem(query2.value(7).toString()));
		ui.tableWidget->setItem(row,9,new QTableWidgetItem(query2.value(8).toString()));
		ui.tableWidget->setItem(row,10,new QTableWidgetItem(query2.value(3).toString()));
	//	ui.tableWidget->setItem(row,11,new QTableWidgetItem(query2.value(11).toString()));

		strsql= "select * from yf_inventory where name='"+strName+"'";
		query.exec(strsql);
		while(query.next())
		{
			ui.tableWidget->setItem(row,6,new QTableWidgetItem(query.value(7).toString()));
		}

		row++;
	}

	query.exec("select * from zy_patientinfo where hospitalisationno= '"+strhospitalNo+"'");
	QString strnursinglevel,strdepartment,strdoctor;
	while(query.next())
	{
		strnursinglevel=query.value(16).toString();
		strdepartment=query.value(13).toString();
		strdoctor=query.value(14).toString();
	}

	double totalpay=0.0;
	double totalfee=0.0;
	query.exec("select * from zy_pay where hospitalisationno= '"+strhospitalNo+"'");
	while(query.next())
	{
		totalpay +=query.value(8).toDouble();
	}
	query.exec("select * from zy_chargedetail where hospitalisationno= '"+strhospitalNo+"'");
	while(query.next())
	{
		totalfee +=query.value(8).toDouble();
	}
	QString strpay = QString::fromLocal8Bit("累计交款：")+QString::number(totalpay)+"           ";
	QString strfee = QString::fromLocal8Bit("累计消费：")+QString::number(totalfee)+"\n";
	QString strremain = QString::fromLocal8Bit("最新余额：")+QString::number(totalpay-totalfee);
	QString strremark = strpay+strfee+strremain+"           "+QString::fromLocal8Bit("费用类型：")+"   "+"\n"+QString::fromLocal8Bit("护理级别：")+strnursinglevel+"   "+QString::fromLocal8Bit("住院科室：")+strdepartment+"\n"+QString::fromLocal8Bit("主治医生：")+strdoctor;
	ui.hintEdit->setText(strremark);
}
void HospitalisationCharge::keyPressEvent(QKeyEvent *e) 
{
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
				QString strsql= "select * from sys_drugdictionary where name='"+strName+"'";
				bool isexist =query.exec(strsql);
				while(query.next())
				{
					ui.tableWidget->setItem(row,0,new QTableWidgetItem(query.value(22).toString()));
					ui.tableWidget->setItem(row,1,new QTableWidgetItem(query.value(1).toString()));
					ui.tableWidget->setItem(row,2,new QTableWidgetItem(query.value(4).toString()));
					ui.tableWidget->setItem(row,3,new QTableWidgetItem(query.value(5).toString()));
				//	ui.tableWidget->setItem(row,4,new QTableWidgetItem(query.value(6).toString()));//批号
					ui.tableWidget->setItem(row,5,new QTableWidgetItem(query.value(6).toString()));
					//ui.tableWidget->setItem(row,6,new QTableWidgetItem(query.value(5).toString()));//库存
					ui.tableWidget->setItem(row,8,new QTableWidgetItem(query.value(17).toString()));
					ui.tableWidget->setItem(row,10,new QTableWidgetItem(query.value(11).toString()));//
					ui.tableWidget->setItem(row,11,new QTableWidgetItem(query.value(14).toString()));//
					ui.tableWidget->setItem(row,12,new QTableWidgetItem(query.value(12).toString()));

					ui.tableWidget->setFocus();
					ui.tableWidget->setCurrentCell(row, 0, QItemSelectionModel::Deselect);
					ui.tableWidget->setCurrentCell(row, 7, QItemSelectionModel::Select);

					QCursor cursorAction;
					ui.tableWidget->setCursor(cursorAction);
				}
				//if (isexist)
				//{
				//	int count = ui.tableWidget->rowCount();
				//	ui.tableWidget->insertRow(count);
				//}
				strsql= "select * from yf_inventory where name='"+strName+"'";
				query.exec(strsql);
				while(query.next())
				{
					ui.tableWidget->setItem(row,6,new QTableWidgetItem(query.value(7).toString()));
				}
			}

			list_widget->hide();
		} else {
			list_widget->hide();
			//QLineEdit::keyPressEvent(e);
		}
	} else {
		//QLineEdit::keyPressEvent(e);
		int key = e->key();
		if (Qt::Key_Enter == key || Qt::Key_Return == key) {
			// 按下回车键时，使用完成列表中选中的项，并隐藏完成列表
			//focusNextChild();
			int row = ui.tableWidget->currentRow();
			int count = ui.tableWidget->rowCount();
			ui.tableWidget->insertRow(count);
			ui.tableWidget->setCurrentCell(row, 7, QItemSelectionModel::Deselect);
			ui.tableWidget->setCurrentCell(row+1, 0, QItemSelectionModel::Select);
			QCursor cursorAction;
			ui.tableWidget->setCursor(cursorAction);
		}
		if (Qt::Key_F5 == key ) {
			on_saveButton_clicked();
		}
	}
}
void HospitalisationCharge::addPackage(QString strName)
{
	int row = ui.tableWidget->rowCount();
	QSqlQuery query(*sql.db);	
	QString strsql= "select * from sys_package_detail where name='"+strName+"'";
	query.exec(strsql);
	while(query.next())
	{
		QString strdrug = query.value(3).toString();
		if (ui.tableWidget->item(row-1,0)==NULL)
		{
			row--;
		}
		ui.tableWidget->insertRow(row);
		ui.tableWidget->setItem(row,0,new QTableWidgetItem(query.value(2).toString()));
		ui.tableWidget->setItem(row,1,new QTableWidgetItem(query.value(3).toString()));
		ui.tableWidget->setItem(row,2,new QTableWidgetItem(query.value(4).toString()));
		ui.tableWidget->setItem(row,3,new QTableWidgetItem(query.value(5).toString()));
		ui.tableWidget->setItem(row,5,new QTableWidgetItem(query.value(6).toString()));

		ui.tableWidget->setItem(row,8,new QTableWidgetItem(query.value(9).toString()));
		ui.tableWidget->setItem(row,7,new QTableWidgetItem(query.value(7).toString()));

		QSqlQuery query2(*sql.db);	
		strsql= "select * from sys_drugdictionary where name='"+strdrug+"'";
		query2.exec(strsql);
		while(query2.next())
		{
			ui.tableWidget->setItem(row,8,new QTableWidgetItem(query2.value(15).toString()));
			ui.tableWidget->setItem(row,10,new QTableWidgetItem(query2.value(11).toString()));//
			ui.tableWidget->setItem(row,11,new QTableWidgetItem(query2.value(14).toString()));//
		}
		strsql= "select * from yf_inventory where name='"+strdrug+"'";
		query2.exec(strsql);
		while(query2.next())
		{
			ui.tableWidget->setItem(row,5,new QTableWidgetItem(query2.value(7).toString()));
		}

		row++;
	}
}
HospitalisationCharge::~HospitalisationCharge()
{

}
