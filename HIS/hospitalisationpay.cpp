#include "hospitalisationpay.h"
#include <QtGui>
#include "connectsql.h"
#include "capital.h"
extern ConnectSql sql;
HospitalisationPay::HospitalisationPay(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	initUI();
	ui.tableWidget->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
	ui.tableWidget->setStyleSheet("QTableWidget{border: 1px solid gray;	background-color: transparent;	selection-color: white;}");
	ui.tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section {background-color:white;color: black;padding-left: 4px;border: 1px solid #6c6c6c;};"
		"color: white;padding-left: 4px;border: 1px solid #6c6c6c;}"
		"QHeaderView::section:checked{background-color: white;color: black;}");	
	ui.tableWidget->installEventFilter(this);
	/*ui.nameEdit->installEventFilter(this);*/
	Isrefund=false;
	connect(ui.hospitalNocomboBox,SIGNAL(currentIndexChanged(QString)),this,SLOT(getInfo(QString)));
	connect(ui.remarkEdit->document(),SIGNAL(contentsChanged()),this,SLOT(textAreaChanged()));
}
void HospitalisationPay::initUI()
{
	QSqlQuery query(*sql.db);		
	query.exec("select * from zy_patientinfo ORDER BY id ASC");
	QStringList list;
	while(query.next())
	{
		QString str = query.value(1).toString();
		list.append(str);
	}
	ui.hospitalNocomboBox->clear();
	ui.hospitalNocomboBox->addItems(list);

	query.exec("select * from sys_settlingmethod");
	list.clear();
	while(query.next())
	{
		QString str = query.value(1).toString();
		list.append(str);
	}
	ui.chargemethodcomboBox->clear();
	ui.chargemethodcomboBox->addItems(list);


	QDateTime current_date_time = QDateTime::currentDateTime();
	ui.dateTimeEdit->setDateTime(current_date_time);

	ui.remarkEdit->clear();
	ui.tableWidget->setRowCount(0);
	ui.saveButton->setEnabled(false);
	ui.editButton->setEnabled(false);
	ui.discardButton->setEnabled(false);
	ui.deleteButton->setEnabled(false);
	//setEdit(false);

	ui.sheetmakerEdit->setEnabled(false);
	ui.sheetmakerEdit->setText(sql.struser);
	Isupdate=false;
}
void HospitalisationPay::on_addButton_clicked()
{
	on_discardButton_clicked();
	initUI();
	//installEventFilter(this);
	setEdit(true);
	QSqlQuery query(*sql.db);		
	query.exec("select * from zy_pay");
	int icount=0;
	while(query.next())
	{
		icount++;
	}
	itotalcount=icount+1;
	QString strNo= "ZYSK"+QString::number(itotalcount, 10);
	ui.sheetNoEdit->setText(strNo);
	ui.saveButton->setEnabled(true);
	ui.discardButton->setEnabled(true);

	strNo = ui.hospitalNocomboBox->currentText();
	getInfo(strNo);
}
void HospitalisationPay::on_saveButton_clicked()
{
	QSqlQuery query(*sql.db);		
	QString strNo=ui.sheetNoEdit->text();

	if(Isupdate)
	{
		QString strsql = "select *from zy_pay where sheetno ='"+strNo+"'"; 
		query.exec(strsql);
		while(query.next())
		{
			itotalcount=query.value(0).toInt();
		}
	}

	QString strsql = "delete from zy_pay where sheetno ='"+strNo+"'"; 
	query.exec(strsql);
	if (ui.nameEdit->text()=="")
	{
		QMessageBox box(QMessageBox::Warning,QString::fromLocal8Bit("警告"),QString::fromLocal8Bit("请填写病人姓名"));
		box.setStandardButtons (QMessageBox::Ok);
		box.setButtonText (QMessageBox::Ok,QString::fromLocal8Bit("确 定"));
		box.exec();
		return;
	}
	if (ui.amountEdit->text()=="")
	{
		if (Isrefund)
		{
			QMessageBox box(QMessageBox::Warning,QString::fromLocal8Bit("警告"),QString::fromLocal8Bit("请填写退款金额"));
			box.setStandardButtons (QMessageBox::Ok);
			box.setButtonText (QMessageBox::Ok,QString::fromLocal8Bit("确 定"));
			box.exec();
		}
		else
		{
			QMessageBox box(QMessageBox::Warning,QString::fromLocal8Bit("警告"),QString::fromLocal8Bit("请填写交款金额"));
			box.setStandardButtons (QMessageBox::Ok);
			box.setButtonText (QMessageBox::Ok,QString::fromLocal8Bit("确 定"));
			box.exec();
		}
		return;
	}

	query.prepare("INSERT INTO zy_pay VALUES (?,?, ?, ?, ?, ?, ?, ?, ?, ?)");//, ?
	query.bindValue(0, itotalcount);
	query.bindValue(1, ui.sheetNoEdit->text());
	query.bindValue(2, ui.dateTimeEdit->dateTime());
	query.bindValue(3, ui.hospitalNocomboBox->currentText());
	query.bindValue(4, ui.nameEdit->text());
	query.bindValue(5, ui.registrydateEdit->text());
	query.bindValue(6, ui.bedEdit->text());
	query.bindValue(7, ui.chargemethodcomboBox->currentText());
	if(Isrefund)
		query.bindValue(8, ui.amountEdit->text().toDouble()*(-1));
	else
		query.bindValue(8, ui.amountEdit->text().toDouble());
	query.bindValue(9, ui.remarkEdit->document()->toPlainText());
	//query.bindValue(10, ui.payerEdit->text());
	if(query.exec())
	{
		ui.editButton->setEnabled(true);
		ui.saveButton->setEnabled(false);
		ui.discardButton->setEnabled(false);
		setEdit(false);
		strNo = ui.hospitalNocomboBox->currentText();
		getInfo(strNo);
		QMessageBox box(QMessageBox::Warning,QString::fromLocal8Bit("警告"),QString::fromLocal8Bit("是否打印押金条？"));
		box.setStandardButtons (QMessageBox::Ok|QMessageBox::Cancel);
		box.setButtonText (QMessageBox::Ok,QString::fromLocal8Bit("确 定"));
		box.setButtonText (QMessageBox::Cancel,QString::fromLocal8Bit("取 消"));
		if(box.exec()==QMessageBox::Ok)
		{
			on_printButton_clicked();
		}
	}
	else
	{
		QMessageBox box(QMessageBox::Warning,QString::fromLocal8Bit("警告"),QString::fromLocal8Bit("保存失败！"));
		box.setStandardButtons (QMessageBox::Ok);
		box.setButtonText (QMessageBox::Ok,QString::fromLocal8Bit("确 定"));
		box.exec();
	}
}
void HospitalisationPay::on_discardButton_clicked()
{
	ui.sheetNoEdit->clear();
	ui.nameEdit->clear();
	ui.registrydateEdit->clear();
	ui.amountEdit->clear();
	ui.bedEdit->clear();
	ui.remarkEdit->clear();
	ui.sheetmakerEdit->clear();
	ui.tableWidget->setRowCount(0);
}
void HospitalisationPay::on_editButton_clicked()
{
	ui.deleteButton->setEnabled(true);
	ui.saveButton->setEnabled(true);
	setEdit(true);
}
void HospitalisationPay::on_deleteButton_clicked()
{
	QSqlQuery query(*sql.db);		
	QString strNo=ui.sheetNoEdit->text();
	QString strsql = "delete from zy_pay where sheetno ='"+strNo+"'"; 
	if(query.exec(strsql))
	{
		QMessageBox box(QMessageBox::Warning,QString ::fromLocal8Bit("提示"),QString::fromLocal8Bit("删除成功！"));
		box.setStandardButtons (QMessageBox::Ok);
		box.setButtonText (QMessageBox::Ok,QString::fromLocal8Bit("确 定"));
		box.exec();
		on_discardButton_clicked();
	}
}
void HospitalisationPay::on_previewButton_clicked()
{
	filePrintPreview();
}
void HospitalisationPay::on_printButton_clicked()
{
	QPrinter       printer( QPrinter::PrinterResolution );
	QPrintDialog   dialog( &printer, this );
	if ( dialog.exec() == QDialog::Accepted ) print( &printer );
}
void HospitalisationPay::filePrintPreview()
{
	// 打印预览对话框
	QPrinter             printer( QPrinter::PrinterResolution );
	QPrintPreviewDialog  preview( &printer, this );
	preview.setWindowTitle(QString::fromLocal8Bit("预览"));
	connect( &preview, SIGNAL(paintRequested(QPrinter*)), SLOT(print(QPrinter*)) );
	preview.exec();
}
void HospitalisationPay::print( QPrinter* printer )
{
	QPainter painter( printer );
	int      w = printer->pageRect().width();
	int      h = printer->pageRect().height();
	QRect    page( w/5, h/15-h/20, w, h );
	QRect    page2( w/9, h/9-h/20, w, h );
	QRect    page3( w/11, h/10-h/20, 5*w/6, h/8);
	QRect    page4( w/11, 9*h/40-h/20, 5*w/6, h/16);
	QRect    page5(  w/9, 9*h/40-h/20, w, h/10);
	QRect    page6( w/11, 23*h/80-h/20, 5*w/6, h/20);
	QRect    page7(  w/9, 24*h/80-h/20, w, h/10);
	QFont    font = painter.font();
	font.setPixelSize( (w+h) / 100 );
	painter.setFont( font );
	if (Isrefund)
	{
		painter.drawText( page, Qt::AlignTop    | Qt::AlignLeft, QString::fromLocal8Bit("          三河市燕郊镇卫生院退款单") );
		double amount=ui.amountEdit->text().toDouble();
		Capital*capital = new Capital;

		QString strcaptial =capital->NumToChineseStr(amount);//;
		QString str =QString::fromLocal8Bit("退款单号：")+ui.sheetNoEdit->text()+" "+QString::fromLocal8Bit("住院号：")+ui.hospitalNocomboBox->currentText()+" "+QString::fromLocal8Bit("退款日期：")+ui.dateTimeEdit->text()+"     \n\n"+QString::fromLocal8Bit("姓名：")+ui.nameEdit->text()+"     "+QString::fromLocal8Bit("票号：")+"     "+QString::fromLocal8Bit("住院日期：")+ui.registrydateEdit->text()+"\n\n"+QString::fromLocal8Bit("退款方式：")+ui.chargemethodcomboBox->currentText()+"     "+QString::fromLocal8Bit("金额：")+"-"+ui.amountEdit->text()+"     "+QString::fromLocal8Bit("大写：")+QString::fromLocal8Bit("负")+strcaptial;
		painter.drawText( page2, Qt::AlignTop    | Qt::AlignLeft, str);
		painter.drawText( page, Qt::AlignBottom | Qt::AlignLeft,
			QDateTime::currentDateTime().toString( Qt::DefaultLocaleShortDate ) );
		painter.drawRect(page3);
		painter.drawRect(page4);
		str ="\n"+QString::fromLocal8Bit("制单：")+ui.sheetmakerEdit->text()+"     "+QString::fromLocal8Bit("打印时间：")+QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss")+"     "+QString::fromLocal8Bit("收款人：")+ui.payerEdit->text();
		painter.drawText( page5, Qt::AlignTop    | Qt::AlignLeft, str);
		painter.drawRect(page6);
		str =QString::fromLocal8Bit("此乃临时收据，不作报销凭证，请妥善保存，出院结算时交回。");
		painter.drawText( page7, Qt::AlignTop    | Qt::AlignLeft, str);
		page.adjust( w/20, h/20, -w/20, -h/20 );
		return;
	}
	painter.drawText( page, Qt::AlignTop    | Qt::AlignLeft, QString::fromLocal8Bit("          三河市燕郊镇卫生院收款单") );
	double amount=ui.amountEdit->text().toDouble();
	//string strtemp="";
	Capital*capital = new Capital;

	QString strcaptial =capital->NumToChineseStr(amount);//;
	QString str =QString::fromLocal8Bit("收款单号：")+ui.sheetNoEdit->text()+" "+QString::fromLocal8Bit("住院号：")+ui.hospitalNocomboBox->currentText()+" "+QString::fromLocal8Bit("收费日期：")+ui.dateTimeEdit->text()+"     \n\n"+QString::fromLocal8Bit("姓名：")+ui.nameEdit->text()+"     "+QString::fromLocal8Bit("票号：")+"     "+QString::fromLocal8Bit("住院日期：")+ui.registrydateEdit->text()+"\n\n"+QString::fromLocal8Bit("收款方式：")+ui.chargemethodcomboBox->currentText()+"     "+QString::fromLocal8Bit("金额：")+ui.amountEdit->text()+"     "+QString::fromLocal8Bit("大写：")+strcaptial;
	painter.drawText( page2, Qt::AlignTop    | Qt::AlignLeft, str);
	painter.drawText( page, Qt::AlignBottom | Qt::AlignLeft,
		QDateTime::currentDateTime().toString( Qt::DefaultLocaleShortDate ) );
	painter.drawRect(page3);
	painter.drawRect(page4);
	str ="\n"+QString::fromLocal8Bit("制单：")+ui.sheetmakerEdit->text()+"     "+QString::fromLocal8Bit("打印时间：")+QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss")+"     "+QString::fromLocal8Bit("交款人：")+ui.payerEdit->text();
	painter.drawText( page5, Qt::AlignTop    | Qt::AlignLeft, str);
	painter.drawRect(page6);
	str =QString::fromLocal8Bit("此乃临时收据，不作报销凭证，请妥善保存，出院结算时交回。");
	painter.drawText( page7, Qt::AlignTop    | Qt::AlignLeft, str);
	page.adjust( w/20, h/20, -w/20, -h/20 );

}
void HospitalisationPay::getInfo(QString strinfo)
{
	ui.tableWidget->setRowCount(0);
	ui.tableWidget->clear();
	QStringList header;
	header<<QString::fromLocal8Bit("单号")<<QString::fromLocal8Bit("日期")<<QString::fromLocal8Bit("金额")<<QString::fromLocal8Bit("票号")<<QString::fromLocal8Bit("备注")<<QString::fromLocal8Bit("制单");
	ui.tableWidget->setHorizontalHeaderLabels(header);
	QSqlQuery query(*sql.db);		
	query.exec("select * from zy_patientinfo where hospitalisationno= '"+strinfo+"'");
	QString strnursinglevel,strdepartment,strdoctor;
	while(query.next())
	{
		ui.nameEdit->setText(query.value(4).toString());
		ui.registrydateEdit->setText(query.value(2).toDateTime().toString("yyyy-MM-dd hh:mm:ss"));
		ui.bedEdit->setText(query.value(17).toString());
		strnursinglevel=query.value(16).toString();
		strdepartment=query.value(13).toString();
		strdoctor=query.value(14).toString();
	}

	query.exec("select * from zy_pay where hospitalisationno= '"+strinfo+"'");
	int row= 0;
	while(query.next())
	{
		ui.tableWidget->insertRow(row);
		ui.tableWidget->setItem(row,0,new QTableWidgetItem(query.value(1).toString()));
		ui.tableWidget->setItem(row,1,new QTableWidgetItem(query.value(2).toDateTime().toString("yyyy-MM-dd hh:mm:ss")));
		ui.tableWidget->setItem(row,2,new QTableWidgetItem(query.value(8).toString()));
		row++;
	}
//	ui.tableWidget->show();
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
	ui.remarkEdit->setText(strremark);
}
void HospitalisationPay::textAreaChanged()
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
void HospitalisationPay::setEdit(bool IsEdit)
{
	if (IsEdit==true)
	{
		ui.amountEdit->setEnabled(true);
		//ui.bedEdit->setEnabled(true);
		ui.dateTimeEdit->setEnabled(true);
		ui.nameEdit->setEnabled(true);
		//ui.registrydateEdit->setEnabled(true);
		//ui.remarkEdit->setEnabled(true);
		//ui.sheetmakerEdit->setEnabled(true);
		ui.sheetNoEdit->setEnabled(true);
		ui.lineEdit_6->setEnabled(true);
		ui.chargemethodcomboBox->setEnabled(true);
		ui.hospitalNocomboBox->setEnabled(true);
		ui.payerEdit->setEnabled(true);
		ui.tableWidget->setEnabled(true);
	}
	else
	{
		ui.amountEdit->setEnabled(false);
		ui.bedEdit->setEnabled(false);
		ui.dateTimeEdit->setEnabled(false);
		ui.nameEdit->setEnabled(false);
		ui.registrydateEdit->setEnabled(false);
		ui.remarkEdit->setEnabled(false);
		ui.sheetmakerEdit->setEnabled(false);
		ui.sheetNoEdit->setEnabled(false);
		ui.lineEdit_6->setEnabled(false);
		ui.chargemethodcomboBox->setEnabled(false);
		ui.hospitalNocomboBox->setEnabled(false);
		ui.tableWidget->setEnabled(false);
		ui.payerEdit->setEnabled(false);
	}
}
bool HospitalisationPay::eventFilter(QObject*obj,QEvent*event)
{
	/* if(obj == ui.nameEdit)
	{
	if(event->type() == QEvent::KeyPress)
	{
	QKeyEvent*keyEvent=static_cast<QKeyEvent*>(event);
	if(keyEvent->key() == Qt::Key_Return)
	{

	QString strname = ui.nameEdit->text();
	QSqlQuery query(*sql.db);		
	query.exec("select * from zy_patientinfo where patientname= '"+strname+"'");
	while(query.next())
	{
	ui.nameEdit->setText(query.value(4).toString());
	ui.registrydateEdit->setText(query.value(2).toString());
	ui.bedEdit->setText(query.value(17).toString());
	ui.hospitalNocomboBox->setCurrentIndex(query.value(0).toInt()-1);
	}
	return  true;
	}
	else
	{
	return  false;
	}
	}
	else
	{
	return  false;
	}

	}*/
	 if(obj == this)
	 {
		 if(event->type() == QEvent::KeyPress)
		 {
			 QKeyEvent*keyEvent=static_cast<QKeyEvent*>(event);
			 if(keyEvent->key() == Qt::Key_Return)
			 {
				 focusNextChild();
				 return true;
			 }
		 }
	 }
}
void HospitalisationPay::edit(QString strNo)
{
	ui.addButton->setEnabled(false);
	ui.editButton->setEnabled(true);
	setEdit(false);
	Isupdate=true;
	QSqlQuery query(*sql.db);	
	query.exec("select * from zy_pay where sheetno='"+strNo+"'");
	while(query.next())
	{
		ui.sheetNoEdit->setText(query.value(1).toString());
		QDateTime date = QDateTime::fromString(query.value(2).toString(),"yyyy-MM-dd hh:mm:ss");
		ui.dateTimeEdit->setDateTime(date);

		QString strhospitalNo = query.value(3).toString();
		for (int i =0;i<ui.hospitalNocomboBox->count();i++)
		{
			if (ui.hospitalNocomboBox->itemText(i)==strhospitalNo)
			{
				ui.hospitalNocomboBox->setCurrentIndex(i);
			}
		}
		getInfo(strhospitalNo);
		//ui.hospitalNocomboBox->setEditText(query.value(3).toString());
		ui.nameEdit->setText(query.value(4).toString());
		ui.registrydateEdit->setText(query.value(5).toDateTime().toString("yyyy-MM-dd hh:mm:ss"));
		ui.bedEdit->setText(query.value(6).toString());

		QString strchargemethod = query.value(7).toString();
		for (int i =0;i<ui.chargemethodcomboBox->count();i++)
		{
			if (ui.chargemethodcomboBox->itemText(i)==strchargemethod)
			{
				ui.chargemethodcomboBox->setCurrentIndex(i);
			}
		}
	//	ui.chargemethodcomboBox->setEditText(query.value(7).toString());
		ui.amountEdit->setText(query.value(8).toString());
		//ui.remarkEdit->setText(query.value(9).toString());
		ui.payerEdit->setText(query.value(10).toString());
	}
	
}
void HospitalisationPay::refund(QString strNo,double amount)
{
	on_addButton_clicked();
	for (int i =0;i<ui.hospitalNocomboBox->count();i++)
	{
		if (ui.hospitalNocomboBox->itemText(i)==strNo)
		{
			ui.hospitalNocomboBox->setCurrentIndex(i);
		}
	}
	if(!Isrefund) amount = amount*(-1);
	ui.amountEdit->setText(QString::number(amount));
}
HospitalisationPay::~HospitalisationPay()
{

}
