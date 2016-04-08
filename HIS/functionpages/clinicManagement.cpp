
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
	char *string = "门诊收费";
	QString strText = codec->toUnicode(string);
	ClinicCharge*charge = new ClinicCharge;
	addWidget(strText, QString(""), charge,1);

}

void ClinicManagement::SourceInfoManagement()
{
	QString str = str.fromLocal8Bit("收费查询");

}


void ClinicManagement::DailyReport()
{
	QString strText = QString::fromLocal8Bit("门诊日结");
	ClinicDailyReport*dailyReport = new ClinicDailyReport;
	addWidget(strText, QString(""), dailyReport,2);
}
void ClinicManagement::Statistics()
{
	QString strText = QString::fromLocal8Bit("统计查询");
	ClinicStatistics*statistics = new ClinicStatistics;
	addWidget(strText, QString(""), statistics,3);

}
void ClinicManagement::InternalPayment()
{
	QString strText = QString::fromLocal8Bit("内部缴款表");
	ClinicInternalPayment*internalPayment = new ClinicInternalPayment;
	addWidget(strText, QString(""), internalPayment,4);

}
void ClinicManagement::ComponentInfoManagement4()
{
	QString str = str.fromLocal8Bit("项目查询表");

}
void ClinicManagement::Pharmacystorage()
{
	QString strText = QString::fromLocal8Bit("药房库存");
	PharmacyInventory*inventory = new PharmacyInventory;
	addWidget(strText, QString(""), inventory,5);

}
