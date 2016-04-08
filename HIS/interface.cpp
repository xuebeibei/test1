#include "interface.h"
#include "clinic2ruralcooperative.h"
#include "hospital2ruralcooperative.h"
#include "ruralcooperativedictionary.h"
Interface::Interface(QWidget *parent)
	: FTabWidget(parent)
{
	initUI();
}

void Interface::initUI()
{
	dictionary();
	clinic();
	hospitalisation();
}
void Interface::dictionary()
{
	QString strText = QString::fromLocal8Bit("参数设置");
	Ruralcooperativedictionary *ruralcooperativedictionary = new Ruralcooperativedictionary;
	addWidget(strText, QString(""), ruralcooperativedictionary,28);
}
void Interface::clinic()
{
	QString strText = QString::fromLocal8Bit("门诊信息导出农合");
	Clinic2ruralcooperative *clinicruralcooperative = new Clinic2ruralcooperative;
	addWidget(strText, QString(""), clinicruralcooperative,29);
}
void Interface::hospitalisation()
{
	QString strText = QString::fromLocal8Bit("住院信息导出农合");
	Hospital2ruralcooperative *hospitalruralcooperative = new Hospital2ruralcooperative;
	addWidget(strText, QString(""), hospitalruralcooperative,30);
}
