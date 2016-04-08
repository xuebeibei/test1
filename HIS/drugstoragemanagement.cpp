#include "drugstoragemanagement.h"
#include "drugallot.h"
#include "drugcheck.h"
#include "drugpricing.h"
#include "drugstatistics.h"
#include "drugstorage.h"
#include "druginventory.h"

DrugStorageManagement::DrugStorageManagement(QWidget *parent)
	: FTabWidget(parent)
{

	initUI();
	getButtons().at(0)->click();
}

void DrugStorageManagement::initUI()
{
	
    Storage();
    Allot();
	Inventory();
	Check();
	Pricing();
	Statistics();
}
void DrugStorageManagement::Storage()
{

	QString strText = QString::fromLocal8Bit("ҩƷ���");
	DrugStorage*storage = new DrugStorage;
	addWidget(strText, QString(""), storage,13);

}

void DrugStorageManagement::Allot()
{
	QString strText = QString::fromLocal8Bit("ҩƷ����");
	DrugAllot*allot = new DrugAllot;
	addWidget(strText, QString(""), allot,14);
}
void DrugStorageManagement::Inventory()
{
	QString strText = QString::fromLocal8Bit("ҩƷ���");
	DrugInventory*inventory = new DrugInventory;
	addWidget(strText, QString(""), inventory,15);
}
void DrugStorageManagement::Check()
{
	QString strText = QString::fromLocal8Bit("ҩƷ�̴�");
	DrugCheck*check = new DrugCheck;
	addWidget(strText, QString(""), check,16);
}
void DrugStorageManagement::Pricing()
{
	QString strText = QString::fromLocal8Bit("ҩƷ����");
	DrugPricing*pricing = new DrugPricing;
	addWidget(strText, QString(""), pricing,17);
}
void DrugStorageManagement::Statistics()
{
	QString strText = QString::fromLocal8Bit("ͳ�Ʋ�ѯ");
	DrugStatistics*statistics = new DrugStatistics;
	addWidget(strText, QString(""), statistics,18);
}