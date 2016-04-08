#include "systemadmin.h"
#include "department.h"
#include "departmentfile.h"
#include "personnel.h"
#include "drugdictionary.h"
#include "supplier.h"
#include "hospitalisationreceipt.h"
#include "hospitalisationclassification.h"
#include "clinicreceipt.h"
#include "clinicclassification.h"
#include "combination.h"
#include "settlemethod.h"
#include "user.h"
#include "villageclinic.h"
#include "insurancetype.h"
#include "dictionarytype.h"
#include "drugtype.h"
#include "ruralcooperatecorrespondence.h"
#include "financetype.h"
SystemAdmin::SystemAdmin(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	setStyleSheet("QPushButton{background-color: rgb(240,240,240);color: black;border-style: outset;border-width:0.5px;border-radius: 2px;}"
		"QPushButton:pressed{background-color: rgb(50, 77, 92);color: white;}"
		"QPushButton:hover{	background-color: rgb(3,110,184);color: white;}"
		"QLabel{ background-color: transparent;color: black;qproperty-alignment: AlignCenter;border-color:rgb(27, 118, 150);border-width: 1px;border-radius: 5px;}"
		"QTextBrowser{ background-color: transparent;black: white;border-color:rgb(27, 118, 150);border-width: 1px;border-radius: 5px;}");
}
void SystemAdmin::on_commandLinkButton_clicked()
{
	personnel*person = new personnel;
	person->setWindowModality(Qt::WindowModal);
	person->show();
}
void SystemAdmin::on_commandLinkButton_2_clicked()
{

	Department*department = new Department;
	department->setWindowModality(Qt::WindowModal);
	department->show();
}
void SystemAdmin::on_commandLinkButton_3_clicked()
{
	Drugdictionary*drugdictionary = new Drugdictionary;
	drugdictionary->setWindowModality(Qt::WindowModal);
	drugdictionary->show();
}
void SystemAdmin::on_commandLinkButton_4_clicked()
{
	Hospitalisationreceipt*receipt = new Hospitalisationreceipt;
	receipt->setWindowModality(Qt::WindowModal);
	receipt->show();
}
void SystemAdmin::on_commandLinkButton_5_clicked()
{
	Clinicclassification*classification = new Clinicclassification;
	classification->setWindowModality(Qt::WindowModal);
	classification->show();
}
void SystemAdmin::on_commandLinkButton_6_clicked()
{
	Hospitalisationclassification*classification = new Hospitalisationclassification;
	classification->setWindowModality(Qt::WindowModal);
	classification->show();
}
void SystemAdmin::on_commandLinkButton_7_clicked()
{
	Supplier*supplier = new Supplier;
	supplier->setWindowModality(Qt::WindowModal);
	supplier->show();

}
void SystemAdmin::on_commandLinkButton_8_clicked()
{
	Clinicreceipt*receipt = new Clinicreceipt;
	receipt->setWindowModality(Qt::WindowModal);
	receipt->show();

}
void SystemAdmin::on_commandLinkButton_9_clicked()
{
	Settlemethod*settlemethod = new Settlemethod;
	settlemethod->setWindowModality(Qt::WindowModal);
	settlemethod->show();

}
void SystemAdmin::on_commandLinkButton_10_clicked()
{
	Combination*combination = new Combination;
	combination->setWindowModality(Qt::WindowModal);
	combination->show();

}
void SystemAdmin::on_commandLinkButton_11_clicked()
{
	ruralcooperatecorrespondence*correspondence = new ruralcooperatecorrespondence;
	correspondence->setWindowModality(Qt::WindowModal);
	correspondence->show();

}
void SystemAdmin::on_commandLinkButton_12_clicked()
{
	Financetype*type = new Financetype;
	type->setWindowModality(Qt::WindowModal);
	type->show();

}
void SystemAdmin::on_commandLinkButton_13_clicked()
{
	Settlemethod*settlemethod = new Settlemethod;
	settlemethod->setWindowModality(Qt::WindowModal);
	settlemethod->show();

}
void SystemAdmin::on_commandLinkButton_14_clicked()
{
	Settlemethod*settlemethod = new Settlemethod;
	settlemethod->setWindowModality(Qt::WindowModal);
	settlemethod->show();

}
void SystemAdmin::on_commandLinkButton_15_clicked()
{
	Settlemethod*settlemethod = new Settlemethod;
	settlemethod->setWindowModality(Qt::WindowModal);
	settlemethod->show();

}
void SystemAdmin::on_userButton_clicked()
{
	User*user = new User;
	user->setWindowModality(Qt::WindowModal);
	user->show();

}
void SystemAdmin::on_villageclinicButton_clicked()
{
	Villageclinic*clinic = new Villageclinic;
	clinic->setWindowModality(Qt::WindowModal);
	clinic->show();
}
void SystemAdmin::on_insurancetypeButton_clicked()
{
	Insurancetype*insurance = new Insurancetype;
	insurance->setWindowModality(Qt::WindowModal);
	insurance->show();
}
void SystemAdmin::on_dictionarytypeButton_clicked()
{
	Dictionarytype*dictionary = new Dictionarytype;
	dictionary->setWindowModality(Qt::WindowModal);
	dictionary->show();
}
void SystemAdmin::on_drugtypeButton_clicked()
{
	Drugtype*type = new Drugtype;
	type->setWindowModality(Qt::WindowModal);
	type->show();
}
SystemAdmin::~SystemAdmin()
{

}
