
#include "ClinicManagement.h"
#include "QFramer/ftabwidget.h"
#include "QFramer/futil.h"
#include <QtGui/QIcon>
#include <QtCore/QTextCodec>
#include <QtGui/QMenuBar>
#include <QtGui/QMenu>
#include <QtGui/QFileDialog>
#include <QtGui/QColorDialog>
#include "ClinicCharge.h"
#include "clinicstatistics.h"
#include "clinicdailyreport.h"
#include "clinicinternalpayment.h"
#include "pharmacyinventory.h"
#include <iostream>

ClinicManagement::ClinicManagement(QWidget *parent) :
    FTabWidget(parent)
{
    initUI();
}

void ClinicManagement::initUI()
{
	
    Charge();
	DailyReport();
	InternalPayment();
	Statistics();
	Pharmacystorage();
	getButtons().at(0)->click();
}

void ClinicManagement::Charge()
{
	QTextCodec *codec = QTextCodec::codecForName("GBK");
	char *string = "�����շ�";
	QString strText = codec->toUnicode(string);
	ClinicCharge*charge = new ClinicCharge;
	addWidget(strText, QString(""), charge,1);

}

void ClinicManagement::SourceInfoManagement()
{
	QString str = str.fromLocal8Bit("�շѲ�ѯ");

}


void ClinicManagement::DailyReport()
{
	QString strText = QString::fromLocal8Bit("�����ս�");
	ClinicDailyReport*dailyReport = new ClinicDailyReport;
	addWidget(strText, QString(""), dailyReport,2);
}
void ClinicManagement::Statistics()
{
	QString strText = QString::fromLocal8Bit("ͳ�Ʋ�ѯ");
	ClinicStatistics*statistics = new ClinicStatistics;
	addWidget(strText, QString(""), statistics,3);

}
void ClinicManagement::InternalPayment()
{
	QString strText = QString::fromLocal8Bit("�ڲ��ɿ��");
	ClinicInternalPayment*internalPayment = new ClinicInternalPayment;
	addWidget(strText, QString(""), internalPayment,4);

}
void ClinicManagement::ComponentInfoManagement4()
{
	QString str = str.fromLocal8Bit("��Ŀ��ѯ��");

}
void ClinicManagement::Pharmacystorage()
{
	QString strText = QString::fromLocal8Bit("ҩ�����");
	PharmacyInventory*inventory = new PharmacyInventory;
	addWidget(strText, QString(""), inventory,5);

}
