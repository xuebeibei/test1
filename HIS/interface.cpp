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
	QString strText = QString::fromLocal8Bit("��������");
	Ruralcooperativedictionary *ruralcooperativedictionary = new Ruralcooperativedictionary;
	addWidget(strText, QString(""), ruralcooperativedictionary,28);
}
void Interface::clinic()
{
	QString strText = QString::fromLocal8Bit("������Ϣ����ũ��");
	Clinic2ruralcooperative *clinicruralcooperative = new Clinic2ruralcooperative;
	addWidget(strText, QString(""), clinicruralcooperative,29);
}
void Interface::hospitalisation()
{
	QString strText = QString::fromLocal8Bit("סԺ��Ϣ����ũ��");
	Hospital2ruralcooperative *hospitalruralcooperative = new Hospital2ruralcooperative;
	addWidget(strText, QString(""), hospitalruralcooperative,30);
}
