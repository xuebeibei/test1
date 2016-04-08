#include "pharmacymanagement.h"
#include "pharmacycheck.h"
#include "pharmacyinventory.h"
#include "pharmacyreceipt.h"
#include "pharmacystatistics.h"
PharmacyManagement::PharmacyManagement(QWidget *parent)
	: FTabWidget(parent)
{
	initUI();
	getButtons().at(0)->click();
}
void PharmacyManagement::initUI()
{
	Receipt();
	Check();
	Inventory();
	Statistics();
}
void PharmacyManagement::Receipt()
{
	QString strText = QString::fromLocal8Bit("调拨收货");
	PharmacyReceipt*receipt = new PharmacyReceipt;
	addWidget(strText, QString(""), receipt,19);
}
void PharmacyManagement::Check()
{
	QString strText = QString::fromLocal8Bit("药房盘点");
	PharmacyCheck*check = new PharmacyCheck;
	addWidget(strText, QString(""), check,20);
}
void PharmacyManagement::Inventory()
{
	QString strText = QString::fromLocal8Bit("药房库存");
	PharmacyInventory*inventory = new PharmacyInventory;
	addWidget(strText, QString(""), inventory,21);
}
void PharmacyManagement::Statistics()
{
	QString strText = QString::fromLocal8Bit("统计查询");
	PharmacyStatistics*statistics = new PharmacyStatistics;
	addWidget(strText, QString(""), statistics,22);
}