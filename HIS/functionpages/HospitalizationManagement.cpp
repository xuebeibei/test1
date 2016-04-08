#include "HospitalizationManagement.h"
#include "QFramer/ftabwidget.h"
#include "QFramer/futil.h"
#include <QtCore/QTextCodec>

#include <iostream>
HospitalizationManagement::HospitalizationManagement(QWidget *parent):
	 FTabWidget(parent)
{
	initUI();
	getButtons().at(0)->click();
	connect(registry->ui.saveButton,SIGNAL(clicked()),this,SLOT(refresh()));
	connect(registry->ui.deleteButton,SIGNAL(clicked()),this,SLOT(refresh()));
}

void HospitalizationManagement::initUI()
{
    Registry();
    Pay();
	Charge();
	Discharge();
	InternalPayment();
	Dailyreport();
	Statistics();
}
void HospitalizationManagement::Registry()
{
	QTextCodec *codec = QTextCodec::codecForName("GBK");
	char *string = "סԺ�Ǽ�";
	QString strText = codec->toUnicode(string);

	registry = new HospitalisationRegistry;
    addWidget(strText, QString(""), registry,6);
}
void HospitalizationManagement::Query()
{
	QTextCodec *codec = QTextCodec::codecForName("GBK");
	char *string = "סԺ��ѯ";
	QString strText = codec->toUnicode(string);

	query = new HospitalisationQuery;
	addWidget(strText, QString(""), query,7);
}
void HospitalizationManagement::Pay()
{
	QTextCodec *codec = QTextCodec::codecForName("GBK");
	char *string = "סԺ��Ѻ��";
	QString strText = codec->toUnicode(string);

	pay = new HospitalisationPay;
	addWidget(strText, QString(""), pay,8);
}
void HospitalizationManagement::Charge()
{
	QTextCodec *codec = QTextCodec::codecForName("GBK");
	char *string = "סԺ�շ�";
	QString strText = codec->toUnicode(string);

	charge = new HospitalisationCharge;
	addWidget(strText, QString(""), charge,9);

}
void HospitalizationManagement::Statistics()
{
	QTextCodec *codec = QTextCodec::codecForName("GBK");
	char *string = "ͳ�Ʋ�ѯ";
	QString strText = codec->toUnicode(string);

	statistics = new HospitalisationStatistics;
	addWidget(strText, QString(""), statistics,10);
}
void HospitalizationManagement::InternalPayment()
{
	QTextCodec *codec = QTextCodec::codecForName("GBK");
	char *string = "�ڲ��ɿ��";
	QString strText = codec->toUnicode(string);

	internalpayment = new HospitalisationInternalPayment;
	addWidget(strText, QString(""), internalpayment,4);
}
void HospitalizationManagement::Transference()
{
	QTextCodec *codec = QTextCodec::codecForName("GBK");
	char *string = "ת��ת��תҽ��";
	QString strText = codec->toUnicode(string);

	HospitalisationTransference*transference = new HospitalisationTransference;
	addWidget(strText, QString(""), transference,11);
}
void HospitalizationManagement::Discharge()
{
	QTextCodec *codec = QTextCodec::codecForName("GBK");
	char *string = "��Ժ";
	QString strText = codec->toUnicode(string);

	discharge = new HospitalisationDischarge;
	addWidget(strText, QString(""), discharge,12);
}
void HospitalizationManagement::Dailyreport()
{
	QTextCodec *codec = QTextCodec::codecForName("GBK");
	char *string = "סԺ�ս�";
	QString strText = codec->toUnicode(string);

	dailyreport = new Hospitalisationdailyreport;
	addWidget(strText, QString(""), dailyreport,2);
}
void HospitalizationManagement::refresh()
{
	pay->initUI();
	discharge->initUI();
}