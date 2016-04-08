#include "cliniccharge.h"
#include "connectsql.h"
#include "clinicdrugfilter.h"
#include "package.h"
#include "getdoctor.h"
#include "capital.h"
extern ConnectSql sql;
Package*package;
bool IsEdit;
ClinicCharge::ClinicCharge(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	initUI();
	doctorlist = new QListView(this);
	model = new QStringListModel(this);
	doctorlist->setWindowFlags(Qt::ToolTip);

	departmentlist = new QListView(this);
	departmentmodel = new QStringListModel(this);
	departmentlist->setWindowFlags(Qt::ToolTip);

	package= new Package;

	connect(doctorlist, SIGNAL(clicked(const QModelIndex &)), this, SLOT(completeText(const QModelIndex &)));
	connect(departmentlist, SIGNAL(clicked(const QModelIndex &)), this, SLOT(completedepartmentText(const QModelIndex &)));
	list_widget = new QListWidget(this);
	list_widget->setWindowFlags(Qt::FramelessWindowHint);
	list_widget->close();
	//installEventFilter(list_widget);
	list_widget->installEventFilter(this);
	//installEventFilter(ui.tableWidget);
	ui.tableWidget->installEventFilter(this);
	//installEventFilter(doctorlist);
	//installEventFilter(departmentlist);

	ui.tableWidget->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
	ui.tableWidget->setStyleSheet("QTableWidget{border: 1px solid gray;	background-color: transparent;	selection-color: grey;}");
	ui.tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section {background-color:white;color: black;padding-left: 4px;border: 1px solid #6c6c6c;};"
		"color: white;padding-left: 4px;border: 1px solid #6c6c6c;}"
		"QHeaderView::section:checked{background-color: white;color: black;}");	
	ui.tableWidget->horizontalHeader()->resizeSection(2,80);
	connect(ui.tableWidget,SIGNAL(cellChanged(int,int)),this,SLOT(getItem(int,int)));
	//connect(list_widget,SIGNAL(itemClicked(QListWidgetItem *)),this,SLOT(selectItem(QListWidgetItem *)));//
	connect(ui.doctorEdit, SIGNAL(textChanged(const QString &)), this, SLOT(setCompleter(const QString &)));
	connect(ui.doctorEdit, SIGNAL(textChanged(const QString &)), this, SLOT(showDepartment(const QString &)));
	connect(package,SIGNAL(showPackage(QString)),this,SLOT(addPackage(QString)));
	//ui.tableWidget->setFocusPolicy(Qt::NoFocus);
	//ui.tableWidget->unsetCursor();
}
void ClinicCharge::initUI()
{
	QSqlQuery query(*sql.db);		
	query.exec("select * from sys_department");
	QStringList list;
	while(query.next())
	{
		QString str = query.value(1).toString();
		list.append(str);
	}
	//ui.departmentcomboBox->addItems(list);

	query.exec("select * from sys_insurancetype");
	QStringList list2;
	while(query.next())
	{
		QString str = query.value(2).toString();
		list2.append(str);
	}
	ui.insurancetypecomboBox->addItems(list2);

//	setEdit(false);
	QDateTime current_date_time = QDateTime::currentDateTime();
	ui.dateTimeEdit->setDateTime(current_date_time);
	ui.saveButton->setEnabled(false);
	ui.editButton->setEnabled(false);
	ui.discardButton->setEnabled(false);
	ui.deleteButton->setEnabled(false);
	ui.addrowButton->setEnabled(false);
	ui.deleterowButton->setEnabled(false);
	ui.sheetmakerEdit->setEnabled(false);
	ui.sheetmakerEdit->setText(sql.struser);
	ui.dueincomeEdit->setText("0");
	ui.realincomeEdit->setText("0");
    ui.warehouseEdit->setEnabled(false);
	ui.customerEdit->setEnabled(false);
	ui.packageButton->setEnabled(false);
	Isupdate=false;
}
void ClinicCharge::on_addButton_clicked()
{
	list_widget->close();
	on_discardButton_clicked();
	setEdit(true);
	ui.editButton->setEnabled(false);
	ui.deleteButton->setEnabled(false);
	ui.saveButton->setEnabled(true);
	ui.discardButton->setEnabled(true);
	ui.addrowButton->setEnabled(true);
	ui.deleterowButton->setEnabled(true);
	ui.packageButton->setEnabled(true);
	Isupdate=false;
	ui.tableWidget->setRowCount(0);
	ui.tableWidget->clearContents();
	ui.tableWidget->insertRow(0);
	int isheetcount=sheetNo();
	isheetcount++;
	QString strSheetNo= "MZSF"+QString::number(isheetcount, 10);
	ui.sheetNoEdit->setText(strSheetNo);
	//ui.tableWidget->installEventFilter(this);
	ui.doctorEdit->installEventFilter(this);
	installEventFilter(this);
}
void ClinicCharge::on_saveButton_clicked()
{
	QSqlQuery query(*sql.db);		
	QString strNo=ui.sheetNoEdit->text();
	int isheetcount;
	if(Isupdate)
	{
		QString strsql = "select *from mz_chargesheet where sheetno ='"+strNo+"'"; 
		query.exec(strsql);
		while(query.next())
		{
			isheetcount=query.value(0).toInt();
		}
	}
	QString strsql = "delete from mz_chargesheet where sheetno ='"+strNo+"'"; 
	query.exec(strsql);
	strsql = "delete from mz_chargedetail where sheetno ='"+strNo+"'"; 
	query.exec(strsql);

	if (ui.nameEdit->text()=="")
	{
		QMessageBox box(QMessageBox::Warning,QString::fromLocal8Bit("警告"),QString::fromLocal8Bit("请填写病人姓名"));
		box.setStandardButtons (QMessageBox::Ok);
		box.setButtonText (QMessageBox::Ok,QString::fromLocal8Bit("确 定"));
		box.exec();
		return;
	}
	/*
	if (ui.ageEdit->text()=="")
	{
		QMessageBox::information(this,QString::fromLocal8Bit("警告"),QString::fromLocal8Bit("请填写病人年龄"));
		return;
	}
	if (ui.doctorEdit->text()=="")
	{
		QMessageBox::information(this,QString::fromLocal8Bit("警告"),QString::fromLocal8Bit("请选择医生"));
		return;
	}*/
	int irows = ui.tableWidget->model()->rowCount();   //行总数
	for (int i=0;i<irows;i++)
	{
		QTableWidgetItem*item = ui.tableWidget->item(i,0);
		if( ui.tableWidget->item(i,0)==NULL) continue;

		if( ui.tableWidget->item(i,0)==NULL||ui.tableWidget->item(i,0)->text()=="")
		{
			//QMessageBox::information(this,QString::fromLocal8Bit("警告"),QString::fromLocal8Bit("请选择药品"));
			//return;
		}
		if( ui.tableWidget->item(i,7)==NULL||ui.tableWidget->item(i,7)->text()=="")
		{
			QMessageBox box(QMessageBox::Warning,QString::fromLocal8Bit("警告"),QString::fromLocal8Bit("请填写数量"));
			//QMessageBox box(QMessageBox::information(this,QString::fromLocal8Bit("警告"),QString::fromLocal8Bit("请填写数量")));
			box.setStandardButtons (QMessageBox::Ok);
			box.setButtonText (QMessageBox::Ok,QString::fromLocal8Bit("确 定"));
			box.exec();
			return;
		}
	}
	//添加到收费单基本信息表中
	query.prepare("INSERT INTO mz_chargesheet VALUES (?,?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)");
	if (!Isupdate)
	{
		isheetcount=sheetNo();
		isheetcount++;
	}
	query.bindValue(0, isheetcount);
	query.bindValue(1, ui.sheetNoEdit->text());
	query.bindValue(2, ui.dateTimeEdit->dateTime());
	query.bindValue(3, ui.warehouseEdit->text());
	query.bindValue(4, ui.customerEdit->text());
	query.bindValue(5, ui.nameEdit->text());
	query.bindValue(6, ui.gendercomboBox->currentText());
	QString strage = ui.ageEdit->text();
	query.bindValue(7, strage.toInt());
	query.bindValue(8, ui.doctorEdit->text());
	query.bindValue(9, ui.departmentEdit->text());
	query.bindValue(10, ui.insurancetypecomboBox->currentText());
	query.bindValue(11, ui.IDEdit->text());
	query.bindValue(12, ui.insuranceNoEdit->text());
	query.bindValue(13, ui.dueincomeEdit->text().toDouble());
	query.bindValue(14, ui.realincomeEdit->text().toDouble());
	query.bindValue(15, ui.sheetmakerEdit->text());
	query.bindValue(16, 0);
	query.bindValue(17,ui.sheetNoEdit->text());//发票号同门诊号
	bool issuccess=query.exec();

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
	query.exec("select * from mz_chargedetail");
	int temp=0;
	while(query.next())
	{
		temp++;
	}
	for (int i=0;i<rows;i++)
	{
		if (ui.tableWidget->item(i,1)==NULL&&ui.tableWidget->item(i,0)==NULL) continue;

		if (ui.tableWidget->item(i,1)!=NULL)
		{
			stritemname = ui.tableWidget->item(i,1)->text();
		}

		if (ui.tableWidget->item(i,6)!=NULL)
		{
			strunit = ui.tableWidget->item(i,6)->text();
		}

		if (ui.tableWidget->item(i,7)!=NULL)
		{
			icount= ui.tableWidget->item(i,7)->text().toInt();
		}

		if (ui.tableWidget->item(i,8)!=NULL)
		{
			unitprice = ui.tableWidget->item(i,8)->text().toDouble();
		}

		if (ui.tableWidget->item(i,9)!=NULL)
		{
			amount= ui.tableWidget->item(i,9)->text().toDouble();
		}
		if (ui.tableWidget->item(i,10)!=NULL)
		{
			strtype=ui.tableWidget->item(i,10)->text();
		}
		query.prepare("INSERT INTO mz_chargedetail VALUES (?,?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)");
		query.bindValue(0, temp+i+1);
		query.bindValue(1,ui.sheetNoEdit->text());
		query.bindValue(2, strsheetmaker);
		query.bindValue(3, strtype);
		query.bindValue(4, stritemname);  
		query.bindValue(5, strunit);
		query.bindValue(6, icount);
		query.bindValue(7, unitprice);
		query.bindValue(8, amount);
		query.bindValue(9, ui.dateTimeEdit->dateTime());
		QString strdrugtype;
		if (ui.tableWidget->item(i,11)!=NULL)
		{
			strdrugtype= ui.tableWidget->item(i,11)->text();
		}
		if (strdrugtype==QString::fromLocal8Bit("西药")||strdrugtype==QString::fromLocal8Bit("中成药")||strdrugtype==QString::fromLocal8Bit("中草药"))
		{
			query.bindValue(10, 1);
		}
		else if (strdrugtype==QString::fromLocal8Bit("医疗项目"))
		{
			query.bindValue(10, 2);
		}
		else if (strdrugtype==QString::fromLocal8Bit("卫生材料"))
		{
			query.bindValue(10, 3);
		}
		else
		{
			query.bindValue(10, NULL);
		}
		if(ui.tableWidget->item(i,12)!=NULL)
			query.bindValue(11, ui.tableWidget->item(i,12)->text());
		else
			query.bindValue(11, NULL);
		issuccess = query.exec();
	}
	if(!issuccess) return;
	setEdit(false);
	ui.editButton->setEnabled(true);
	ui.saveButton->setEnabled(false);
	ui.deleteButton->setEnabled(false);
	ui.addrowButton->setEnabled(false);
	ui.deleterowButton->setEnabled(false);
	ui.discardButton->setEnabled(false);
	ui.packageButton->setEnabled(false);

	QMessageBox box(QMessageBox::Warning,QString::fromLocal8Bit("警告"),QString::fromLocal8Bit("是否打印发票？"));
	box.setStandardButtons (QMessageBox::Ok|QMessageBox::Cancel);
	box.setButtonText (QMessageBox::Ok,QString::fromLocal8Bit("确 定"));
	box.setButtonText (QMessageBox::Cancel,QString::fromLocal8Bit("取 消"));
	if(box.exec()==QMessageBox::Ok)
	{
		on_printButton_clicked();
	}
}
void ClinicCharge::on_checkButton_clicked()
{
	
}
void ClinicCharge::on_discardButton_clicked()
{
	ui.sheetNoEdit->setText("");
	ui.ageEdit->setText("");
	ui.nameEdit->setText("");
	ui.dueincomeEdit->setText("");
	ui.insuranceNoEdit->setText("");
	ui.realincomeEdit->setText("");
	ui.doctorEdit->setText("");
	ui.IDEdit->setText("");
	ui.tableWidget->setRowCount(0);
	ui.tableWidget->clearContents();
	//ui.tableWidget->insertRow(0);
}
void ClinicCharge::on_editButton_clicked()
{
	setEdit(true);
	ui.deleteButton->setEnabled(true);
	ui.saveButton->setEnabled(true);
	ui.addrowButton->setEnabled(true);
	ui.deleterowButton->setEnabled(true);
	ui.discardButton->setEnabled(true);
	ui.packageButton->setEnabled(true);
}
void ClinicCharge::on_deleteButton_clicked()
{
	QMessageBox box(QMessageBox::Warning,QString::fromLocal8Bit("警告"),QString::fromLocal8Bit("确认从数据库中删除该单？"));
	box.setStandardButtons (QMessageBox::Ok|QMessageBox::Cancel);
	box.setButtonText (QMessageBox::Ok,QString::fromLocal8Bit("确 定"));
	box.setButtonText (QMessageBox::Cancel,QString::fromLocal8Bit("取 消"));
	if(box.exec()==QMessageBox::Ok)
	{
		QSqlQuery query(*sql.db);		
		QString strSheetNo=ui.sheetNoEdit->text();

		query.exec("select* from mz_chargesheet"); 
		int count=0;
		QString lastNo;
		while (query.next())
		{
			lastNo=query.value(1).toString();
		}
		if (lastNo!=strSheetNo) 
		{
			QMessageBox box(QMessageBox::Warning,QString::fromLocal8Bit("警告"),QString::fromLocal8Bit("删除该单会造成重复！"));
			box.setStandardButtons (QMessageBox::Ok);
			box.setButtonText (QMessageBox::Ok,QString::fromLocal8Bit("确 定"));
			box.exec ();
			return;
		}

		QString strsql = "delete from mz_chargesheet where sheetno ='"+strSheetNo+"'"; //where ID > 1
		query.exec(strsql);

		strsql = "delete from mz_chargedetail where sheetno ='"+strSheetNo+"'"; //where ID > 1
		query.exec(strsql);
		on_discardButton_clicked();
		ui.saveButton->setEnabled(false);
		ui.editButton->setEnabled(false);
		ui.discardButton->setEnabled(false);
		ui.deleteButton->setEnabled(false);
		ui.addrowButton->setEnabled(false);
		ui.deleterowButton->setEnabled(false);
	}
}
void ClinicCharge::on_packageButton_clicked()
{	
	package->setWindowModality(Qt::WindowModal);
	package->show();
}
void ClinicCharge::on_addrowButton_clicked()
{
	//表格增加一行
	int irows = ui.tableWidget->model()->rowCount();
	if(irows>0)
	{
		if( ui.tableWidget->item(irows-1,0)==NULL) return;
		if( ui.tableWidget->item(irows-1,7)==NULL||ui.tableWidget->item(irows-1,7)->text()=="")
		{
			QMessageBox box(QMessageBox::Warning,QString::fromLocal8Bit("警告"),QString::fromLocal8Bit("请填写数量！"));
			box.setStandardButtons (QMessageBox::Ok);
			box.setButtonText (QMessageBox::Ok,QString::fromLocal8Bit("确 定"));
			box.exec ();
			return;
		}
	}
	ui.tableWidget->insertRow(irows);
}
void ClinicCharge::on_deleterowButton_clicked()
{
	QMessageBox box(QMessageBox::Warning,QString::fromLocal8Bit("警告"),QString::fromLocal8Bit("确认删除选择行？"));
	box.setStandardButtons (QMessageBox::Ok|QMessageBox::Cancel);
	box.setButtonText (QMessageBox::Ok,QString::fromLocal8Bit("确 定"));
	box.setButtonText (QMessageBox::Cancel,QString::fromLocal8Bit("取 消"));
	if(box.exec()==QMessageBox::Ok)
	{
		int row = ui.tableWidget->currentRow();  
		ui.tableWidget->removeRow(row);
		//自动改变应收金额
		int rows = ui.tableWidget->rowCount();
		double currentamount=0.0;
		for (int i=0;i<rows;i++)
		{
			if(ui.tableWidget->item(i,9)==NULL)
				continue;
			currentamount+=ui.tableWidget->item(i,9)->text().toDouble();
		}
		QString strcurrentamount = QString::number(currentamount);
		ui.dueincomeEdit->setText(strcurrentamount);
	}
}
void ClinicCharge::setEdit(bool IsEdit)
{
	if (IsEdit==true)
	{
		ui.sheetNoEdit->setEnabled(true);
		ui.nameEdit->setEnabled(true);
		ui.ageEdit->setEnabled(true);
		ui.realincomeEdit->setEnabled(true);
		ui.insurancetypecomboBox->setEnabled(true);
		ui.insuranceNoEdit->setEnabled(true);
		ui.gendercomboBox->setEnabled(true);
		ui.insurancetypecomboBox->setEnabled(true);
		ui.departmentEdit->setEnabled(true);
		ui.dateTimeEdit->setEnabled(true);
		ui.tableWidget->setEnabled(true);
		ui.doctorEdit->setEnabled(true);
		ui.IDEdit->setEnabled(true);
	}
	else
	{
		ui.sheetNoEdit->setEnabled(false);
		ui.nameEdit->setEnabled(false);
		ui.ageEdit->setEnabled(false);
		ui.dueincomeEdit->setEnabled(false);
		ui.realincomeEdit->setEnabled(false);
		ui.insurancetypecomboBox->setEnabled(false);
		ui.insuranceNoEdit->setEnabled(false);
		ui.gendercomboBox->setEnabled(false);
		ui.insurancetypecomboBox->setEnabled(false);
		ui.departmentEdit->setEnabled(false);
		ui.dateTimeEdit->setEnabled(false);
		ui.tableWidget->setEnabled(false);
		ui.doctorEdit->setEnabled(false);
		ui.IDEdit->setEnabled(false);
	}
}
void ClinicCharge::getItem(int row,int column)
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

		//自动改变应收金额
		int rows = ui.tableWidget->model()->rowCount();
		double currentamount=0.0;
		for (int i=0;i<rows;i++)
		{
			if(ui.tableWidget->item(i,9)==NULL)
				continue;
			currentamount+=ui.tableWidget->item(i,9)->text().toDouble();
		}
		QString strcurrentamount = QString::number(currentamount);
		ui.dueincomeEdit->setText(strcurrentamount);
	
	}
	if (column==0)
	{
		list_widget->close();
		QString strText;
		if(ui.tableWidget->item(row,0)==NULL)  return;

		strText =  ui.tableWidget->item(row,0)->text();
		if(strText.at(0)== QChar('1')) return;
		
		QPoint GlobalPoint(ui.tableWidget->mapToParent(QPoint(0, 0)));//获取控件在窗体中的坐标+row*30
		if(row<8)
			list_widget->setGeometry(GlobalPoint.x(), GlobalPoint.y()+40*(row+1), 150, 280);
		//list_widget->move(GlobalPoint.x(), GlobalPoint.y());
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
		if (list.count()==0) return;
		list_widget->show();
		list_widget->setWindowFlags(Qt::FramelessWindowHint);
		list_widget->addItems(list);
	}
}
void ClinicCharge::selectDoctor(QString strDoctor)
{
	GetDoctor getdoctor = new GetDoctor;
	getdoctor.initData(strDoctor);
	if(getdoctor.exec())
	{
		ui.doctorEdit->setText(getdoctor.strDoctorName);
	}
}
int  ClinicCharge::sheetNo()
{
	QSqlQuery query(*sql.db);		
	query.exec("select * from mz_chargesheet");
	int isheetcount=0;
	while(query.next())
	{
		isheetcount++;
	}
	return isheetcount;
}
void ClinicCharge::filePrint()
{
	// 打印对话框
	QPrinter       printer( QPrinter::PrinterResolution );
	printer.setPageSize(QPrinter::Custom);
	printer.setOrientation(QPrinter::Landscape);
	printer.setPaperSize(QSizeF(120,180),QPrinter::Point);

	QPrintDialog   dialog( &printer, this );
	
	if ( dialog.exec() == QDialog::Accepted ) print( &printer );
}
void ClinicCharge::on_previewButton_clicked()
{
	filePrintPreview();
}
void ClinicCharge::filePrintPreview()
{
	// 打印预览对话框
	QPrinter             printer( QPrinter::PrinterResolution );
	printer.setPageSize(QPrinter::A4);
	QPrintPreviewDialog  preview( &printer, this );
	preview.setWindowTitle(QString::fromLocal8Bit("预览"));
	connect( &preview, SIGNAL(paintRequested(QPrinter*)), SLOT(print(QPrinter*)) );
	preview.exec();
}
void ClinicCharge::on_printButton_clicked()
{
	QPrinter       printer( QPrinter::PrinterResolution );
	QPrintDialog   dialog( &printer, this );
	if ( dialog.exec() == QDialog::Accepted ) print( &printer );
}
void ClinicCharge::print( QPrinter* printer )
{
	QPainter painter( printer );
	int      w = printer->pageRect().width();
	int      h = printer->pageRect().height();
	QRect    page2( 38*w/210, 20*h/297, w, h );
	QRect    page3( 35*w/210, 24*h/297, 5*w/6, h/8);
	QRect    page4( 28*w/210, 35*h/297, 5*w/6, h/4);
	QRect    page5( 45*w/210, 93*h/297,  5*w/6, h/8);
	QRect    page6( 45*w/210, 105*h/297,  5*w/6, h/8);
	QRect    page7( 115*w/210, 122*h/297, 5*w/6, h/8);
	QFont    font = painter.font();
	font.setPointSize(8);
	painter.setFont( font );
	QString str =QString::fromLocal8Bit("三河市燕郊镇卫生院")+"                       "+ui.departmentEdit->text()+"                     "+ui.sheetNoEdit->text();
	painter.drawText( page2, Qt::AlignTop    | Qt::AlignLeft, str);
	str =ui.nameEdit->text()+"                    "+ui.gendercomboBox->currentText()+"               "+ui.insurancetypecomboBox->currentText()+"                                   "+ui.insuranceNoEdit->text();
	painter.drawText( page3, Qt::AlignTop    | Qt::AlignLeft, str);
	int row = ui.tableWidget->rowCount();
	str="";
	bool Isnormal = false;
	for (int i =0;i<row;i++)
	{
		if (ui.tableWidget->item(i,0)==NULL)
		{
			continue;
		}
		if(ui.tableWidget->item(i,1)->text()==QString::fromLocal8Bit("一般诊疗费")) 
			Isnormal=true;
		str =str+ui.tableWidget->item(i,1)->text()+"               "+ui.tableWidget->item(i,6)->text()+"   "+ui.tableWidget->item(i,7)->text()+"   "+ui.tableWidget->item(i,9)->text()+"\n";
	
	}
//	str =ui.dueincomeEdit->text()+"\n"+ui.dateTimeEdit->time().toString();
	painter.drawText( page4, Qt::AlignTop    | Qt::AlignLeft, str);

	double amount=ui.dueincomeEdit->text().toDouble();
	Capital*capital = new Capital;
	QString strcaptial=capital->NumToChineseStr(amount);
	str=strcaptial+"                                   "+ui.dueincomeEdit->text();
	painter.drawText( page5, Qt::AlignTop    | Qt::AlignLeft, str);
	str="10.0                                                                            "+QString::number(amount-10);
	if(Isnormal)
		painter.drawText( page6, Qt::AlignTop    | Qt::AlignLeft, str);
	str=ui.sheetmakerEdit->text()+"                               "+QString::number(ui.dateTimeEdit->date().year())+"   "+QString::number(ui.dateTimeEdit->date().month())+"   "+QString::number(ui.dateTimeEdit->date().day());
	painter.drawText( page7, Qt::AlignTop    | Qt::AlignLeft, str);

}
void ClinicCharge::printString(const QString &htmlString) {

	QPrinter p;
	QTextDocument doc;
	//doc.setHtml(htmlString);

	QFont font = doc.defaultFont();
	font.setBold(true);
	font.setPointSize(font.pointSize() + 1);
	doc.setDefaultFont(font);

	QSizeF s = QSizeF(p.logicalDpiX() * (58 / 25.4), p.logicalDpiY() * (297 / 25.4));
	doc.setPageSize(s);

	p.setOutputFormat(QPrinter::NativeFormat);

	doc.print(&p);
}
void ClinicCharge::keyPressEvent(QKeyEvent *e) {
	list_widget->setFocus();
	int key = e->key();
	if (Qt::Key_Up == key) {
		int row = ui.tableWidget->currentRow();
		ui.tableWidget->setCurrentCell(row, 0, QItemSelectionModel::Deselect);
		for (int i = 0;i<row;i++)
		{
			ui.tableWidget->setCurrentCell(i, 0, QItemSelectionModel::Deselect);
		}
	}

	if (!doctorlist->isHidden()) {
		int key = e->key();
		int count = doctorlist->model()->rowCount();
		QModelIndex currentIndex = doctorlist->currentIndex();

		if (Qt::Key_Down == key) {
			// 按向下方向键时，移动光标选中下一个完成列表中的项
			int row = currentIndex.row() + 1;
			if (row >= count) {
				row = 0;
			}

			QModelIndex index = doctorlist->model()->index(row, 0);
			doctorlist->setCurrentIndex(index);
		} else if (Qt::Key_Up == key) {
			// 按向下方向键时，移动光标选中上一个完成列表中的项
			int row = currentIndex.row() - 1;
			if (row < 0) {
				row = count - 1;
			}

			QModelIndex index = doctorlist->model()->index(row, 0);
			doctorlist->setCurrentIndex(index);
		} else if (Qt::Key_Escape == key) {
			// 按下Esc键时，隐藏完成列表
			doctorlist->hide();
		} else if (Qt::Key_Enter == key || Qt::Key_Return == key) {
			// 按下回车键时，使用完成列表中选中的项，并隐藏完成列表
			if (currentIndex.isValid()) {
				QString text = doctorlist->currentIndex().data().toString();
				ui.doctorEdit->setText(text);
			
			}

			doctorlist->hide();
			return;
		} else {
			// 其他情况，隐藏完成列表，并使用QLineEdit的键盘按下事件
			doctorlist->hide();
			//QLineEdit::keyPressEvent(e);
		}
	} else {
		//QLineEdit::keyPressEvent(e);
	}
	if (!departmentlist->isHidden()) {
		int key = e->key();
		int count = departmentlist->model()->rowCount();
		QModelIndex currentIndex = departmentlist->currentIndex();

		if (Qt::Key_Down == key) {
			int row = currentIndex.row() + 1;
			if (row >= count) {
				row = 0;
			}
			QModelIndex index = departmentlist->model()->index(row, 0);
			doctorlist->setCurrentIndex(index);
		} else if (Qt::Key_Up == key) {
			int row = currentIndex.row() - 1;
			if (row < 0) {
				row = count - 1;
			}
			QModelIndex index = departmentlist->model()->index(row, 0);
			departmentlist->setCurrentIndex(index);
		} else if (Qt::Key_Escape == key) {
			// 按下Esc键时，隐藏完成列表
			departmentlist->hide();
		} else if (Qt::Key_Enter == key || Qt::Key_Return == key) {
			if (currentIndex.isValid()) {
				QString text = departmentlist->currentIndex().data().toString();
				//ui.departmentEdit->setText(text);
				return;
			}

			departmentlist->hide();
		} else {
			// 其他情况，隐藏完成列表，并使用QLineEdit的键盘按下事件
			departmentlist->hide();
			//QLineEdit::keyPressEvent(e);
		}
	} else {
		//QLineEdit::keyPressEvent(e);
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

				int row = ui.tableWidget->currentRow();
				QSqlQuery query(*sql.db);	
				QString strsql= "select * from sys_drugdictionary where name='"+strName+"'";
				bool isexist = query.exec(strsql);
				while(query.next())
				{
					ui.tableWidget->setItem(row,0,new QTableWidgetItem(query.value(22).toString()));
					ui.tableWidget->setItem(row,1,new QTableWidgetItem(query.value(1).toString()));
					ui.tableWidget->setItem(row,2,new QTableWidgetItem(query.value(4).toString()));
					ui.tableWidget->setItem(row,3,new QTableWidgetItem(query.value(5).toString()));
					//ui.tableWidget->setItem(iRow,4,new QTableWidgetItem(query.value(6).toString()));//批号
					//ui.tableWidget->setItem(iRow,5,new QTableWidgetItem(query.value(6).toString()));//库存
					ui.tableWidget->setItem(row,6,new QTableWidgetItem(query.value(6).toString()));
					ui.tableWidget->setItem(row,8,new QTableWidgetItem(query.value(15).toString()));
					ui.tableWidget->setItem(row,10,new QTableWidgetItem(query.value(10).toString()));
					ui.tableWidget->setItem(row,11,new QTableWidgetItem(query.value(14).toString()));
					ui.tableWidget->setItem(row,12,new QTableWidgetItem(query.value(12).toString()));

					ui.tableWidget->setFocus();
					ui.tableWidget->setCurrentCell(row, 0, QItemSelectionModel::Deselect);
					ui.tableWidget->setCurrentCell(row, 7, QItemSelectionModel::Select);

					//QCursor cursorAction;
					//ui.tableWidget->setCursor(cursorAction);
				}
				//if(isexist)
				//{
				//	int count = ui.tableWidget->rowCount();
				//	ui.tableWidget->insertRow(count);
				//}

				strsql= "select * from yf_inventory where name='"+strName+"'";
				query.exec(strsql);
				while(query.next())
				{
					ui.tableWidget->setItem(row,5,new QTableWidgetItem(query.value(7).toString()));
				}
			}

			list_widget->hide();


		} else {
			list_widget->hide();
			//QLineEdit::keyPressEvent(e);
		}
	} else {

		int key = e->key();
		if (Qt::Key_Enter == key || Qt::Key_Return == key) {
			int row = ui.tableWidget->currentRow();
			int count = ui.tableWidget->rowCount();
			ui.tableWidget->insertRow(count);
			ui.tableWidget->setCurrentCell(row, 7, QItemSelectionModel::Deselect);
			ui.tableWidget->setCurrentCell(row+1, 0, QItemSelectionModel::Select);
			//QCursor cursorAction;
			//ui.tableWidget->setCursor(cursorAction);
			list_widget->setFocus();
		}
		if (Qt::Key_F5 == key ) {
			on_saveButton_clicked();
		}

	}

}
void ClinicCharge::edit(QString strNo)
{
	list_widget->close();

	setEdit(false);
	ui.tableWidget->installEventFilter(this);
	ui.doctorEdit->installEventFilter(this);
	//installEventFilter(this);
	Isupdate=true;
	ui.addButton->setEnabled(false);
	ui.editButton->setEnabled(true);
	QSqlQuery query(*sql.db);	
	query.exec("select * from mz_chargesheet where sheetno='"+strNo+"' order by id");
	while(query.next())
	{
		ui.sheetNoEdit->setText(query.value(1).toString());
		ui.dateTimeEdit->setDateTime(query.value(2).toDateTime());
		ui.warehouseEdit->setText(query.value(3).toString());
		ui.customerEdit->setText(query.value(4).toString());
		ui.nameEdit->setText(query.value(5).toString());
		QString strgender = query.value(6).toString();
		if (strgender==QString::fromLocal8Bit("男"))
		{
			ui.gendercomboBox->setCurrentIndex(0);
		}
		if (strgender==QString::fromLocal8Bit("女"))
		{
			ui.gendercomboBox->setCurrentIndex(1);
		}
		ui.ageEdit->setText(query.value(7).toString());
		ui.doctorEdit->setText(query.value(8).toString());
		QString strdepartment = query.value(9).toString();

		 ui.departmentEdit->setText(strdepartment);
		//ui.departmentcomboBox->setEditText(query.value(9).toString());
		QString strinsurancetype = query.value(10).toString();
		if (strinsurancetype==QString::fromLocal8Bit("自费"))
		{
			ui.insurancetypecomboBox->setCurrentIndex(0);
		}
		if (strinsurancetype==QString::fromLocal8Bit("新农合"))
		{
			ui.insurancetypecomboBox->setCurrentIndex(1);
		}
		if (strinsurancetype==QString::fromLocal8Bit("医保"))
		{
			ui.insurancetypecomboBox->setCurrentIndex(2);
		}
		
		ui.IDEdit->setText(query.value(11).toString());
		ui.insuranceNoEdit->setText(query.value(12).toString());
		ui.dueincomeEdit->setText(query.value(13).toString());
		ui.realincomeEdit->setText(query.value(14).toString());	
	}
//	ui.tableWidget->setRowCount(0);
	QSqlQuery query2(*sql.db);	
	query2.exec("select * from mz_chargedetail where sheetno='"+strNo+"' order by id");
	int rowcount= 0;
	while(query2.next())
	{
		ui.tableWidget->insertRow(rowcount);
		ui.tableWidget->setItem(rowcount,1,new QTableWidgetItem(query2.value(4).toString()));
		QString strName=query2.value(4).toString();
		QString strsql= "select * from sys_drugdictionary where name='"+strName+"'";
		query.exec(strsql);
		while(query.next())
		{
			ui.tableWidget->setItem(rowcount,0,new QTableWidgetItem(query.value(22).toString()));
			ui.tableWidget->setItem(rowcount,1,new QTableWidgetItem(query.value(1).toString()));
			ui.tableWidget->setItem(rowcount,2,new QTableWidgetItem(query.value(4).toString()));
			ui.tableWidget->setItem(rowcount,3,new QTableWidgetItem(query.value(5).toString()));
			//ui.tableWidget->setItem(iRow,4,new QTableWidgetItem(query.value(6).toString()));//批号
			//ui.tableWidget->setItem(iRow,5,new QTableWidgetItem(query.value(6).toString()));//库存
			ui.tableWidget->setItem(rowcount,6,new QTableWidgetItem(query.value(6).toString()));
			ui.tableWidget->setItem(rowcount,8,new QTableWidgetItem(query.value(15).toString()));
			ui.tableWidget->setItem(rowcount,10,new QTableWidgetItem(query.value(10).toString()));//
			ui.tableWidget->setItem(rowcount,11,new QTableWidgetItem(query.value(14).toString()));//
			ui.tableWidget->setItem(rowcount,12,new QTableWidgetItem(query.value(12).toString()));//
		}

		ui.tableWidget->setItem(rowcount,7,new QTableWidgetItem(query2.value(6).toString()));
		ui.tableWidget->setItem(rowcount,8,new QTableWidgetItem(query2.value(7).toString()));
		ui.tableWidget->setItem(rowcount,9,new QTableWidgetItem(query2.value(8).toString()));
		ui.tableWidget->setItem(rowcount,10,new QTableWidgetItem(query2.value(3).toString()));

		//int count = ui.tableWidget->rowCount();
		//ui.tableWidget->removeRow(count-1);

		strsql= "select * from yf_inventory where name='"+strName+"'";
		query.exec(strsql);
		while(query.next())
		{
			ui.tableWidget->setItem(rowcount,5,new QTableWidgetItem(query.value(7).toString()));
		}
		rowcount++;
	}
	doctorlist->hide();
}
void ClinicCharge::indexchange(int index)
{
	//ui.tableWidget->item(0,0)->setText(combox->itemText(index));
	QString strName = combox->itemText(index);
	QSqlQuery query(*sql.db);	
	QString strsql= "select * from sys_drugdictionary where name='"+strName+"'";
	query.exec(strsql);
	while(query.next())
	{
		ui.tableWidget->setItem(0,0,new QTableWidgetItem(query.value(22).toString()));
		ui.tableWidget->setItem(0,1,new QTableWidgetItem(query.value(1).toString()));
		ui.tableWidget->setItem(0,2,new QTableWidgetItem(query.value(4).toString()));
		ui.tableWidget->setItem(0,3,new QTableWidgetItem(query.value(5).toString()));
		//ui.tableWidget->setItem(iRow,4,new QTableWidgetItem(query.value(6).toString()));//批号
		//ui.tableWidget->setItem(iRow,5,new QTableWidgetItem(query.value(6).toString()));//库存
		ui.tableWidget->setItem(0,6,new QTableWidgetItem(query.value(6).toString()));
		ui.tableWidget->setItem(0,8,new QTableWidgetItem(query.value(15).toString()));
		ui.tableWidget->setItem(0,10,new QTableWidgetItem(query.value(10).toString()));//
	}
	combox->hidePopup();
	ui.tableWidget->removeCellWidget(0,0);
}
void ClinicCharge::selectItem(QListWidgetItem *item)
{
	int row = ui.tableWidget->currentRow();
	QString strName = item->text();
	QSqlQuery query(*sql.db);	
	QString strsql= "select * from sys_drugdictionary where name='"+strName+"'";
	query.exec(strsql);
	while(query.next())
	{
		ui.tableWidget->setItem(row,0,new QTableWidgetItem(query.value(22).toString()));
		ui.tableWidget->setItem(row,1,new QTableWidgetItem(query.value(1).toString()));
		ui.tableWidget->setItem(row,2,new QTableWidgetItem(query.value(4).toString()));
		ui.tableWidget->setItem(row,3,new QTableWidgetItem(query.value(5).toString()));
		//ui.tableWidget->setItem(iRow,4,new QTableWidgetItem(query.value(6).toString()));//批号
		//ui.tableWidget->setItem(iRow,5,new QTableWidgetItem(query.value(6).toString()));//库存
		ui.tableWidget->setItem(row,6,new QTableWidgetItem(query.value(6).toString()));
		ui.tableWidget->setItem(row,8,new QTableWidgetItem(query.value(15).toString()));
		ui.tableWidget->setItem(row,10,new QTableWidgetItem(query.value(10).toString()));
		ui.tableWidget->setItem(row,11,new QTableWidgetItem(query.value(14).toString()));
		int count = ui.tableWidget->rowCount();
		ui.tableWidget->insertRow(count);
	}
	strsql= "select * from yf_inventory where name='"+strName+"'";
	query.exec(strsql);
	while(query.next())
	{
		ui.tableWidget->setItem(row,5,new QTableWidgetItem(query.value(7).toString()));
	}
	list_widget->close();
}
void ClinicCharge::completeText(const QModelIndex &index) {
	QString strName = index.data().toString();
	ui.doctorEdit->setText(strName);
	doctorlist->hide();
}
void ClinicCharge::focusOutEvent(QFocusEvent *e) {
	doctorlist->hide();
}
void ClinicCharge::setCompleter(const QString &text) {
	doctorlist->hide();
	if (text.isEmpty()) {
		doctorlist->hide();
		return;
	}

	if ((text.length() > 1) && (!doctorlist->isHidden())) {
		return;
	}

	QSqlQuery query(*sql.db);	

	QString strsql=QString("select * from sys_personnel where jianpin like'%%1%' or name like'%%1%'").arg(text).arg(text);
	query.exec(strsql);
	QStringList list;
	while(query.next())
	{
		QString str = query.value(2).toString();
		list.append(str);
	}

	model->setStringList(list);
//	model->setStringList(sl);
	doctorlist->setModel(model);

	if (model->rowCount() == 0) {
		return;
	}

	// Position the text edit
	doctorlist->setMinimumWidth(width());
	doctorlist->setMaximumWidth(width());

	QPoint p(0, height());
	int x = mapToGlobal(p).x();
	int y = mapToGlobal(p).y() + 1;

	QPoint GlobalPoint(ui.doctorEdit->mapToGlobal(QPoint(0, 0)));
	doctorlist->setGeometry(GlobalPoint.x(), GlobalPoint.y()+ui.doctorEdit->height(), 50, 100);
	doctorlist->resize(100,200);	doctorlist->setFixedWidth(ui.doctorEdit->width());
	doctorlist->show();
}
void ClinicCharge::showDepartment(const QString &text)
{
	QSqlQuery query(*sql.db);
	query.exec("select* from sys_personnel where name = '"+text+"'");
	while(query.next())
	{
		ui.departmentEdit->setText(query.value(1).toString());
	}
}
void ClinicCharge::addPackage(QString strName)
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
		ui.tableWidget->setItem(row,6,new QTableWidgetItem(query.value(6).toString()));

		ui.tableWidget->setItem(row,8,new QTableWidgetItem(query.value(8).toString()));
		ui.tableWidget->setItem(row,7,new QTableWidgetItem(query.value(7).toString()));

		QSqlQuery query2(*sql.db);	
		strsql= "select * from sys_drugdictionary where name='"+strdrug+"'";
		query2.exec(strsql);
		while(query2.next())
		{
			ui.tableWidget->setItem(row,8,new QTableWidgetItem(query2.value(15).toString()));
			ui.tableWidget->setItem(row,10,new QTableWidgetItem(query2.value(10).toString()));
			ui.tableWidget->setItem(row,11,new QTableWidgetItem(query2.value(14).toString()));
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
//bool ClinicCharge::eventFilter(QObject *obj, QEvent *event)
//{
//	 QKeyEvent *e = static_cast<QKeyEvent*>(event);
//
//	 //if (Qt::Key_Enter == key || Qt::Key_Return == key) {
//		// // 按下回车键时，使用完成列表中选中的项，并隐藏完成列表
//		// focusNextChild();
//		// int row = ui.tableWidget->currentRow();
//		// ui.tableWidget->setCurrentCell(row, 7, QItemSelectionModel::Deselect);
//		// ui.tableWidget->setCurrentCell(row+1, 0, QItemSelectionModel::Select);
//		// QCursor cursorAction;
//		// ui.tableWidget->setCursor(cursorAction);
//	 //}
//	 //if (Qt::Key_F5 == key ) {
//		// on_saveButton_clicked();
//	 //}
//	  if (obj == ui.tableWidget) 
//	  {
//		  ui.addButton->setFocus();
//		  int key = e->key();
//		  if (Qt::Key_Up == key) {
//			  //QMessageBox box(QMessageBox::Warning,QString::fromLocal8Bit("警告"),QString::fromLocal8Bit("请输入用户名"));
//			  //box.setStandardButtons (QMessageBox::Ok);
//			  //box.setButtonText (QMessageBox::Ok,QString::fromLocal8Bit("确 定"));
//			  //box.exec();
//			  return false;
//		  }
//		  if (Qt::Key_Down == key) {
//			  //QMessageBox box(QMessageBox::Warning,QString::fromLocal8Bit("警告"),QString::fromLocal8Bit("请输入用户名"));
//			  //box.setStandardButtons (QMessageBox::Ok);
//			  //box.setButtonText (QMessageBox::Ok,QString::fromLocal8Bit("确 定"));
//			  //box.exec();
//			  return false;
//		  }
//		  if (Qt::Key_Left == key) {
//			  //QMessageBox box(QMessageBox::Warning,QString::fromLocal8Bit("警告"),QString::fromLocal8Bit("请输入用户名"));
//			  //box.setStandardButtons (QMessageBox::Ok);
//			  //box.setButtonText (QMessageBox::Ok,QString::fromLocal8Bit("确 定"));
//			  //box.exec();
//			  return false;
//		  }
//		  if (Qt::Key_Right == key) {
//			  //QMessageBox box(QMessageBox::Warning,QString::fromLocal8Bit("警告"),QString::fromLocal8Bit("请输入用户名"));
//			  //box.setStandardButtons (QMessageBox::Ok);
//			  //box.setButtonText (QMessageBox::Ok,QString::fromLocal8Bit("确 定"));
//			  //box.exec();
//			  return false;
//		  }
//		  if (Qt::Key_Enter == key )
//		  {
//			  //QMessageBox box(QMessageBox::Warning,QString::fromLocal8Bit("警告"),QString::fromLocal8Bit("请输入用户名"));
//			  //box.setStandardButtons (QMessageBox::Ok);
//			  //box.setButtonText (QMessageBox::Ok,QString::fromLocal8Bit("确 定"));
//			  //box.exec();
//			  return false;
//		  }
//		return false;
//	  }
//	   if (!list_widget->isHidden()) {
//		int key = e->key();
//		int count = list_widget->model()->rowCount();
//		QModelIndex currentIndex = list_widget->currentIndex();
//
//		if (Qt::Key_Down == key) {
//			int row = currentIndex.row() + 1;
//			if (row >= count) {
//				row = 0;
//			}
//
//			QModelIndex index = list_widget->model()->index(row, 0);
//			list_widget->setCurrentIndex(index);
//		} else if (Qt::Key_Up == key) {
//			int row = currentIndex.row() - 1;
//			if (row < 0) {
//				row = count - 1;
//			}
//
//			QModelIndex index = list_widget->model()->index(row, 0);
//			list_widget->setCurrentIndex(index);
//		} else if (Qt::Key_Escape == key) {
//			//list_widget->hide();
//		} else if (Qt::Key_Enter == key || Qt::Key_Return == key) {
//			if (currentIndex.isValid()) {
//				QString strName = list_widget->currentIndex().data().toString();
//
//				int row = ui.tableWidget->currentRow();
//				QSqlQuery query(*sql.db);	
//				QString strsql= "select * from sys_drugdictionary where name='"+strName+"'";
//				bool isexist = query.exec(strsql);
//				while(query.next())
//				{
//					ui.tableWidget->setItem(row,0,new QTableWidgetItem(query.value(22).toString()));
//					ui.tableWidget->setItem(row,1,new QTableWidgetItem(query.value(1).toString()));
//					ui.tableWidget->setItem(row,2,new QTableWidgetItem(query.value(4).toString()));
//					ui.tableWidget->setItem(row,3,new QTableWidgetItem(query.value(5).toString()));
//					//ui.tableWidget->setItem(iRow,4,new QTableWidgetItem(query.value(6).toString()));//批号
//					//ui.tableWidget->setItem(iRow,5,new QTableWidgetItem(query.value(6).toString()));//库存
//					ui.tableWidget->setItem(row,6,new QTableWidgetItem(query.value(6).toString()));
//					ui.tableWidget->setItem(row,8,new QTableWidgetItem(query.value(15).toString()));
//					ui.tableWidget->setItem(row,10,new QTableWidgetItem(query.value(10).toString()));
//					ui.tableWidget->setItem(row,11,new QTableWidgetItem(query.value(14).toString()));
//					ui.tableWidget->setItem(row,12,new QTableWidgetItem(query.value(12).toString()));
//					/*			ui.tableWidget->openPersistentEditor(ui.tableWidget->itemAt(row,10));
//					ui.tableWidget->editItem(ui.tableWidget->itemAt(row,10));*/
//				
//					/*	QModelIndex index = ui.tableWidget->model()->index(row, 10);
//					ui.tableWidget->setCurrentIndex(index);*/
//					ui.tableWidget->setCurrentCell(row, 0, QItemSelectionModel::Deselect);
//					ui.tableWidget->setCurrentCell(row, 7, QItemSelectionModel::Select);
//
//					QCursor cursorAction;
//					ui.tableWidget->setCursor(cursorAction);
//				}
//				if(isexist)
//				{
//					int count = ui.tableWidget->rowCount();
//					ui.tableWidget->insertRow(count);
//				}
//
//				strsql= "select * from yf_inventory where name='"+strName+"'";
//				query.exec(strsql);
//				while(query.next())
//				{
//					ui.tableWidget->setItem(row,5,new QTableWidgetItem(query.value(7).toString()));
//				}
//			}
//
//			list_widget->hide();
//
//
//		} else {
//			//list_widget->hide();
//			//QLineEdit::keyPressEvent(e);
//		}
//	 if (Qt::Key_Enter == key || Qt::Key_Return == key) {
//		 int row = ui.tableWidget->currentRow();
//		 ui.tableWidget->setCurrentCell(row, 7, QItemSelectionModel::Deselect);
//		 ui.tableWidget->setCurrentCell(row+1, 0, QItemSelectionModel::Select);
//		 QCursor cursorAction;
//		 ui.tableWidget->setCursor(cursorAction);
//	 }
//	 	  }
//	 return true;
//}


ClinicCharge::~ClinicCharge()
{

}
