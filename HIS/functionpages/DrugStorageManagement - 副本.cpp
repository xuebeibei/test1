#include "DrugStorageManagement.h"
#include "QFramer/ftabwidget.h"
#include "QFramer/futil.h"
#include <QGridLayout>
#include <QGroupBox>
#include <QLabel>
#include <QPushButton>
#include <QRadioButton>
#include <QCheckBox>
#include <QTreeWidget>
#include <QTabWidget>
#include <QSplitter>
#include <QHeaderView>
#include <QProgressBar>
#include <QTimer>
#include <QGraphicsScene>
#include <QTimer>
#include <QApplication>
#include <QGridLayout>
#include <QWidget>
#include <QtGui/QIcon>
#include <QtCore/QTextCodec>
#include <QtGui/QMenuBar>
#include <QtGui/QMenu>
#include <QtGui/QFileDialog>
#include <QtGui/QColorDialog>
#include <osgQt/GraphicsWindowQt>
#include "drugallot.h"
#include "drugcheck.h"
#include "drugpricing.h"
#include "drugstatistics.h"
#include "drugstorage.h"
#include <iostream>
DrugStorageManagement::DrugStorageManagement(QWidget *parent):
	 FTabWidget(parent)
{
	initUI();
}

void DrugStorageManagement::initUI()
{
	
    Storage();
    Allot();
	Check();
	Pricing();
	Statistics();
	/*getButtons().at(1)->click();
	getButtons().at(0)->click();*/
}

void DrugStorageManagement::Storage()
{
  
	QString strText = QString::fromLocal8Bit("药品入库");
	DrugStorage*storage = new DrugStorage;
	addWidget(strText, QString(""), storage,13);

}

void DrugStorageManagement::Allot()
{
	QString strText = QString::fromLocal8Bit("药品调拨");
	DrugAllot*allot = new DrugAllot;
	addWidget(strText, QString(""), allot,14);
}

void DrugStorageManagement::Check()
{
	QString strText = QString::fromLocal8Bit("药品盘存");
	DrugCheck*check = new DrugCheck;
	addWidget(strText, QString(""), check,15);
}
void DrugStorageManagement::Pricing()
{
	QString strText = QString::fromLocal8Bit("药品调价");
	DrugPricing*pricing = new DrugPricing;
	addWidget(strText, QString(""), pricing,16);
}
void DrugStorageManagement::Statistics()
{
	QString strText = QString::fromLocal8Bit("统计查询");
	DrugStatistics*statistics = new DrugStatistics;
	addWidget(strText, QString(""), statistics,17);
}