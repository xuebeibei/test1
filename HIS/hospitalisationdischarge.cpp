#include "hospitalisationdischarge.h"
#include "hospitalisationpay.h"
#include "connectsql.h"
#include "hospitalisationprint.h"
extern ConnectSql sql;
HospitalisationPay*supplementpay;
HospitalisationPay*refundpay;
HospitalisationDischarge::HospitalisationDischarge(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	supplementpay = new HospitalisationPay();
	refundpay= new HospitalisationPay();
	initUI();
	ui.patientEdit->installEventFilter(this);
	ui.patientEdit_2->installEventFilter(this);
	connect(ui.hospitalisationNoEdit, SIGNAL(textChanged(const QString &)), this, SLOT(showinfo(const QString &)));
	connect(ui.hospitalisationNoEdit_2, SIGNAL(textChanged(const QString &)), this, SLOT(showinfo2(const QString &)));
	connect(supplementpay->ui.saveButton, SIGNAL(clicked()), this, SLOT(refresh()));
	connect(refundpay->ui.saveButton, SIGNAL(clicked()), this, SLOT(refresh()));
}
void HospitalisationDischarge::initUI()
{
	QSqlQuery query(*sql.db);		
	query.exec("select * from zy_patientinfo  order by id");//order by ID ASC
	QStringList list;
	while(query.next())
	{
		QString str = query.value(1).toString();
		list.append(str);
	}
	QDateTime current_date_time = QDateTime::currentDateTime();
	ui.outTimeEdit->setDateTime(current_date_time);		
	//query.exec("select * from zy_patientinfo where hospitalisationno= '"+ui.hospitalisationNocomboBox->currentText()+"'");
	//QString strstatus;
	//while(query.next())
	//{
	//	ui.patientEdit->setText(query.value(4).toString());
	//	ui.registrydateEdit->setText(query.value(2).toString());
	//	/*	ui.bedEdit->setText(query.value(17).toString());*/
	//	ui.recordNoEdit->setText(query.value(3).toString());
	//	ui.genderEdit->setText(query.value(5).toString());
	//	ui.ageEdit->setText(query.value(6).toString());
	//	ui.departmentEdit->setText(query.value(13).toString());
	//	ui.doctorEdit->setText(query.value(14).toString());
	//	ui.typeEdit->setText(query.value(15).toString());
	//	ui.nursinglevelEdit->setText(query.value(16).toString());
	//	ui.sheetmakerEdit->setText(query.value(20).toString());
	//	strstatus=query.value(22).toString();
	//}

	//query.exec("select * from zy_patientinfo where hospitalisationno= '"+ui.hospitalisationNocomboBox_2->currentText()+"'");
	//while(query.next())
	//{
	//	ui.patientEdit_2->setText(query.value(4).toString());
	//	ui.registrydateEdit_2->setText(query.value(2).toString());
	//	ui.genderEdit_2->setText(query.value(5).toString());
	//	ui.ageEdit_2->setText(query.value(6).toString());
	//	ui.departmentEdit_2->setText(query.value(13).toString());
	//	ui.doctorEdit_2->setText(query.value(14).toString());
	//	ui.typeEdit_2->setText(query.value(15).toString());
	//	ui.nursinglevelEdit_2->setText(query.value(16).toString());
	//}
}
void HospitalisationDischarge::on_applyButton_clicked()
{
	QString strNo = ui.hospitalisationNoEdit->text();
	if(strNo=="") return;

	QMessageBox box(QMessageBox::Warning,QString::fromLocal8Bit("警告"),QString::fromLocal8Bit("确认允许该病人出院？"));
	box.setStandardButtons (QMessageBox::Ok|QMessageBox::Cancel);
	box.setButtonText (QMessageBox::Ok,QString::fromLocal8Bit("确 定"));
	box.setButtonText (QMessageBox::Cancel,QString::fromLocal8Bit("取 消"));
	if(box.exec()==QMessageBox::Ok)
	{
		double balance = ui.balanceEdit->text().toDouble();
		if (balance>0)
		{
			QMessageBox box(QMessageBox::Warning,QString::fromLocal8Bit("警告"),QString::fromLocal8Bit("请先退款"));
			box.setStandardButtons (QMessageBox::Ok);
			box.setButtonText (QMessageBox::Ok,QString::fromLocal8Bit("确 定"));
			box.exec();
			return;
		}
		if (balance<0)
		{
			QMessageBox box(QMessageBox::Warning,QString::fromLocal8Bit("警告"),QString::fromLocal8Bit("请先补款"));
			box.setStandardButtons (QMessageBox::Ok);
			box.setButtonText (QMessageBox::Ok,QString::fromLocal8Bit("确 定"));
			box.exec();
			return;
		}
		QSqlQuery query(*sql.db);
		query.prepare("UPDATE zy_patientinfo SET outdate= ? WHERE hospitalisationno = '"+strNo+"'");
		query.bindValue(0,ui.outTimeEdit->dateTime());
		query.exec();

		query.prepare("UPDATE zy_patientinfo SET hospitalizationstatus= ? WHERE hospitalisationno = '"+strNo+"'");
		query.bindValue(0,QString::fromLocal8Bit("出院-已结算"));
		if(query.exec())
		{
			QMessageBox box(QMessageBox::Warning,QString::fromLocal8Bit("提示"),QString::fromLocal8Bit("已出院！"));
			box.setStandardButtons (QMessageBox::Ok);
			box.setButtonText (QMessageBox::Ok,QString::fromLocal8Bit("确 定"));
			box.exec();

			return;
		}

	}
}
void HospitalisationDischarge::on_quitButton_clicked()
{
	ui.hospitalisationNoEdit->clear();
	ui.patientEdit->clear();
	ui.registrydateEdit->clear();
	ui.recordNoEdit->clear();
	ui.genderEdit->clear();
	ui.ageEdit->clear();
	ui.departmentEdit->clear();
	ui.doctorEdit->clear();
	ui.typeEdit->clear();
	ui.nursinglevelEdit->clear();
	ui.sheetmakerEdit->clear();
	ui.totalfeeEdit->clear();
	ui.totalpayEdit->clear();
	ui.balanceEdit->clear();
	ui.hintlabel->setText("");
}
void HospitalisationDischarge::on_refundButton_clicked()
{
	refundpay->setWindowTitle(QString::fromLocal8Bit("出院退款"));
	refundpay->setWindowModality(Qt::WindowModal);
	refundpay->showNormal();
	QString strNo= ui.hospitalisationNoEdit->text();
	double amount= ui.balanceEdit->text().toDouble();
	refundpay->Isrefund=true;
	refundpay->refund(strNo,amount);
}
void HospitalisationDischarge::on_supplementButton_clicked()
{
	supplementpay->setWindowTitle(QString::fromLocal8Bit("出院补款"));
	supplementpay->setWindowModality(Qt::WindowModal);
	supplementpay->showNormal();
	QString strNo= ui.hospitalisationNoEdit->text();
	double amount= ui.balanceEdit->text().toDouble();
	refundpay->Isrefund=false;
	supplementpay->refund(strNo,amount);
}
void HospitalisationDischarge::on_recallButton_clicked()
{
	QSqlQuery query(*sql.db);		
	QString strNo = ui.hospitalisationNoEdit_2->text();
	if(strNo==""||strNo==NULL) return;
	query.exec("select * from zy_patientinfo where hospitalisationno= '"+strNo+"'");
	while(query.next())
	{
		if (query.value(22).toString()==QString::fromLocal8Bit("住院中"))
		{
			QMessageBox box(QMessageBox::Warning,QString::fromLocal8Bit("提示"),QString::fromLocal8Bit("尚未出院！"));
			box.setStandardButtons (QMessageBox::Ok);
			box.setButtonText (QMessageBox::Ok,QString::fromLocal8Bit("确 定"));
			box.exec();
			return;
		}
	}
	QMessageBox box(QMessageBox::Warning,QString::fromLocal8Bit("警告"),QString::fromLocal8Bit("确认召回该病人？"));
	box.setStandardButtons (QMessageBox::Ok|QMessageBox::Cancel);
	box.setButtonText (QMessageBox::Ok,QString::fromLocal8Bit("确 定"));
	box.setButtonText (QMessageBox::Cancel,QString::fromLocal8Bit("取 消"));
	if(box.exec()==QMessageBox::Ok)
	{
		QString strNo = ui.hospitalisationNoEdit_2->text();
		QSqlQuery query(*sql.db);
		query.prepare("UPDATE zy_patientinfo SET hospitalizationstatus= ? WHERE hospitalisationno = '"+strNo+"'");
		query.bindValue(0,QString::fromLocal8Bit("住院中"));
		if(query.exec())
		{
			QMessageBox box(QMessageBox::Warning,QString::fromLocal8Bit("提示"),QString::fromLocal8Bit("已召回！"));
			box.setStandardButtons (QMessageBox::Ok);
			box.setButtonText (QMessageBox::Ok,QString::fromLocal8Bit("确 定"));
			box.exec();
			return;
		}
	}
}
void HospitalisationDischarge::on_cancelButton_clicked()
{
	ui.hospitalisationNoEdit_2->clear();
	ui.patientEdit_2->clear();
	ui.registrydateEdit_2->clear();
	ui.genderEdit_2->clear();
	ui.ageEdit_2->clear();
	ui.departmentEdit_2->clear();
	ui.doctorEdit_2->clear();
	ui.typeEdit_2->clear();
	ui.nursinglevelEdit_2->clear();
}
void HospitalisationDischarge::on_printButton_clicked()
{
	Hospitalisationprint*print = new Hospitalisationprint;
	print->setWindowModality(Qt::WindowModal);
	QString strNo= ui.hospitalisationNoEdit->text();
	print->initUI(strNo);
	print->show();
}
void HospitalisationDischarge::showinfo(const QString &text)
{
	ui.patientEdit->clear();
	ui.registrydateEdit->clear();
	ui.recordNoEdit->clear();
	ui.genderEdit->clear();
	ui.ageEdit->clear();
	ui.departmentEdit->clear();
	ui.doctorEdit->clear();
	ui.typeEdit->clear();
	ui.nursinglevelEdit->clear();
	ui.sheetmakerEdit->clear();
	ui.totalpayEdit->clear();
	ui.totalfeeEdit->clear();
	ui.sheetmakerEdit->clear();
	ui.balanceEdit->clear();
	ui.hintlabel->clear();

	QSqlQuery query(*sql.db);		
	query.exec("select * from zy_patientinfo where hospitalisationno= '"+text+"'");
	QString strstatus;
	while(query.next())
	{
		ui.patientEdit->setText(query.value(4).toString());
		ui.registrydateEdit->setText(query.value(2).toDateTime().toString("yyyy-MM-dd hh:mm:ss"));
	/*	ui.bedEdit->setText(query.value(17).toString());*/
		ui.recordNoEdit->setText(query.value(3).toString());
		ui.genderEdit->setText(query.value(5).toString());
		ui.ageEdit->setText(query.value(6).toString());
		ui.departmentEdit->setText(query.value(13).toString());
		ui.doctorEdit->setText(query.value(14).toString());
		ui.typeEdit->setText(query.value(15).toString());
		ui.nursinglevelEdit->setText(query.value(16).toString());
		ui.sheetmakerEdit->setText(query.value(20).toString());
		strstatus=query.value(22).toString();
	}
	if (strstatus==QString::fromLocal8Bit("出院-已结算"))
	{
		QMessageBox box(QMessageBox::Warning,QString::fromLocal8Bit("提示"),QString::fromLocal8Bit("该病人已出院！"));
		box.setStandardButtons (QMessageBox::Ok);
		box.setButtonText (QMessageBox::Ok,QString::fromLocal8Bit("确 定"));
		box.exec();
		ui.refundButton->setEnabled(false);
		ui.supplementButton->setEnabled(false);
		ui.applyButton->setEnabled(false);
		return;
	}

	double totalpay=0.0;
	double totalfee=0.0;
	query.exec("select * from zy_pay where hospitalisationno= '"+text+"'");
	while(query.next())
	{
		totalpay +=query.value(8).toDouble();
	}
	query.exec("select * from zy_chargedetail where hospitalisationno= '"+text+"'");
	while(query.next())
	{
		totalfee +=query.value(8).toDouble();
	}
	ui.totalpayEdit->setText(QString::number(totalpay));
	ui.totalfeeEdit->setText(QString::number(totalfee));
	ui.balanceEdit->setText(QString::number(totalpay-totalfee));
	QString strremark;
	if(totalpay-totalfee>0)
	{
		strremark=QString::fromLocal8Bit("请进行退款!") ;
		ui.refundButton->setEnabled(true);
		ui.applyButton->setEnabled(false);
		ui.supplementButton->setEnabled(false);
		ui.printButton->setEnabled(false);
	}
	else if(totalpay-totalfee<0)
	{
		strremark=QString::fromLocal8Bit("请进行补交款!") ;
		ui.supplementButton->setEnabled(true);
		ui.applyButton->setEnabled(false);
		ui.refundButton->setEnabled(false);
		ui.printButton->setEnabled(false);
	}
	else
	{
		ui.supplementButton->setEnabled(false);
		ui.refundButton->setEnabled(false);
		ui.applyButton->setEnabled(true);
		ui.cancelButton->setEnabled(true);
		ui.printButton->setEnabled(true);
	}
	ui.hintlabel->setText(strremark);
}
void HospitalisationDischarge::showinfo2(const QString &text)
{
	ui.patientEdit_2->clear();
	ui.registrydateEdit_2->clear();
	ui.genderEdit_2->clear();
	ui.ageEdit_2->clear();
	ui.departmentEdit_2->clear();
	ui.doctorEdit_2->clear();
	ui.typeEdit_2->clear();
	ui.nursinglevelEdit_2->clear();

	QSqlQuery query(*sql.db);		
	query.exec("select * from zy_patientinfo where hospitalisationno= '"+text+"'");
	while(query.next())
	{
		ui.patientEdit_2->setText(query.value(4).toString());
		ui.registrydateEdit_2->setText(query.value(2).toDateTime().toString("yyyy-MM-dd hh:mm:ss"));
		ui.genderEdit_2->setText(query.value(5).toString());
		ui.ageEdit_2->setText(query.value(6).toString());
		ui.departmentEdit_2->setText(query.value(13).toString());
		ui.doctorEdit_2->setText(query.value(14).toString());
		ui.typeEdit_2->setText(query.value(15).toString());
		ui.nursinglevelEdit_2->setText(query.value(16).toString());
		if (query.value(22).toString()==QString::fromLocal8Bit("住院中"))
		{
			QMessageBox box(QMessageBox::Warning,QString::fromLocal8Bit("提示"),QString::fromLocal8Bit("尚未出院！"));
			box.setStandardButtons (QMessageBox::Ok);
			box.setButtonText (QMessageBox::Ok,QString::fromLocal8Bit("确 定"));
			box.exec();
			return;
		}
	}
}
bool HospitalisationDischarge::eventFilter(QObject*obj,QEvent*event)
{
	if(obj == ui.patientEdit)
	{
		if(event->type() == QEvent::KeyPress)
		{
			QKeyEvent*keyEvent=static_cast<QKeyEvent*>(event);
			if(keyEvent->key() == Qt::Key_Return)
			{

				QString strname = ui.patientEdit->text();
				QSqlQuery query(*sql.db);		
				query.exec("select * from zy_patientinfo where patientname= '"+strname+"'");
				while(query.next())
				{
					ui.patientEdit->setText(query.value(4).toString());
					ui.registrydateEdit->setText(query.value(2).toString());
					/*	ui.bedEdit->setText(query.value(17).toString());*/
					ui.recordNoEdit->setText(query.value(3).toString());
					ui.genderEdit->setText(query.value(5).toString());
					ui.ageEdit->setText(query.value(6).toString());
					ui.departmentEdit->setText(query.value(13).toString());
					ui.doctorEdit->setText(query.value(14).toString());
					ui.typeEdit->setText(query.value(15).toString());
					ui.nursinglevelEdit->setText(query.value(16).toString());
					ui.sheetmakerEdit->setText(query.value(20).toString());
					ui.hospitalisationNoEdit->setText(query.value(1).toString());
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

	}
	if(obj == ui.patientEdit_2)
	{
		if(event->type() == QEvent::KeyPress)
		{
			QKeyEvent*keyEvent=static_cast<QKeyEvent*>(event);
			if(keyEvent->key() == Qt::Key_Return)
			{

				QString strname = ui.patientEdit_2->text();
				QSqlQuery query(*sql.db);		
				query.exec("select * from zy_patientinfo where patientname= '"+strname+"'");
				while(query.next())
				{
					ui.patientEdit_2->setText(query.value(4).toString());
					ui.registrydateEdit_2->setText(query.value(2).toString());
					ui.genderEdit_2->setText(query.value(5).toString());
					ui.ageEdit_2->setText(query.value(6).toString());
					ui.departmentEdit_2->setText(query.value(13).toString());
					ui.doctorEdit_2->setText(query.value(14).toString());
					ui.typeEdit_2->setText(query.value(15).toString());
					ui.nursinglevelEdit_2->setText(query.value(16).toString());
					ui.hospitalisationNoEdit_2->setText(query.value(1).toString());
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

	}
}
void HospitalisationDischarge::refresh()
{
	QString text =ui.hospitalisationNoEdit->text();
	double totalpay=0.0;
	double totalfee=0.0;
	QSqlQuery query(*sql.db);	
	query.exec("select * from zy_pay where hospitalisationno= '"+text+"'");
	while(query.next())
	{
		totalpay +=query.value(8).toDouble();
	}
	query.exec("select * from zy_chargedetail where hospitalisationno= '"+text+"'");
	while(query.next())
	{
		totalfee +=query.value(8).toDouble();
	}
	ui.totalpayEdit->setText(QString::number(totalpay));
	ui.totalfeeEdit->setText(QString::number(totalfee));
	ui.balanceEdit->setText(QString::number(totalpay-totalfee));
	QString strremark;
	if(totalpay-totalfee>0)
	{
		strremark=QString::fromLocal8Bit("请进行退款!") ;
		ui.refundButton->setEnabled(true);
		ui.applyButton->setEnabled(false);
		ui.supplementButton->setEnabled(false);
		ui.printButton->setEnabled(false);
	}
	else if(totalpay-totalfee<0)
	{
		strremark=QString::fromLocal8Bit("请进行补交款!") ;
		ui.supplementButton->setEnabled(true);
		ui.applyButton->setEnabled(false);
		ui.refundButton->setEnabled(false);
		ui.printButton->setEnabled(false);
	}
	else
	{
		ui.supplementButton->setEnabled(false);
		ui.refundButton->setEnabled(false);
		ui.applyButton->setEnabled(true);
		ui.cancelButton->setEnabled(true);
		ui.printButton->setEnabled(true);
	}
	ui.hintlabel->setText(strremark);
}
HospitalisationDischarge::~HospitalisationDischarge()
{

}
