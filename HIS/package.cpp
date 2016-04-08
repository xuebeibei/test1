#include "package.h"
#include "connectsql.h"
#include <QTreeWidgetItem>
#include <QTextCodec>
extern ConnectSql sql;
Package::Package(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	initUI();
}
void Package::initUI()
{
	ui.tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui.tableWidget->setStyleSheet("QTableWidget{border: 1px solid gray;	background-color: transparent;	selection-color: grey;}");
	ui.tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section {background-color:white;color: black;padding-left: 4px;border: 1px solid #6c6c6c;};"
		"color: white;padding-left: 4px;border: 1px solid #6c6c6c;}"
		"QHeaderView::section:checked{background-color: white;color: black;}");	
	ui.treeWidget->setStyleSheet("QTreeWidget{border: 1px solid gray;color: black;	background-color: white;selection-color: grey;}");
	connect(ui.treeWidget,SIGNAL(itemClicked(QTreeWidgetItem*,int)),this,SLOT(showTable(QTreeWidgetItem*,int)));

	ui.treeWidget->clear();
	ui.tableWidget->setRowCount(0);
	QStringList headers;
	headers << QString::fromLocal8Bit("套餐列表");
	ui.treeWidget->setHeaderLabels(headers);

	QTextCodec::setCodecForTr(QTextCodec::codecForName("GBK"));
	QTextCodec::setCodecForLocale(QTextCodec::codecForName("GBK"));

	QString strsql;
	strsql = "select * from sys_package";
	QSqlQuery query(*sql.db);	
	query.exec(strsql);
	int row = 0;
	while(query.next())
	{	
		QStringList strlist;
		strlist <<query.value(1).toString();
		QTreeWidgetItem *item = new QTreeWidgetItem(ui.treeWidget, strlist);
		ui.treeWidget->addTopLevelItem(item);
		
		strsql = "select * from sys_package_detail where name = '"+query.value(1).toString()+"'";
		QSqlQuery query2(*sql.db);	
		query2.exec(strsql);
		while(query2.next())
		{	
			ui.tableWidget->insertRow(row);
			ui.tableWidget->setItem(row,0,new QTableWidgetItem(query2.value(2).toString()));
			ui.tableWidget->setItem(row,1,new QTableWidgetItem(query2.value(3).toString()));
			ui.tableWidget->setItem(row,2,new QTableWidgetItem(query2.value(4).toString()));
			ui.tableWidget->setItem(row,3,new QTableWidgetItem(query2.value(5).toString()));
			ui.tableWidget->setItem(row,4,new QTableWidgetItem(query2.value(6).toString()));
			ui.tableWidget->setItem(row,5,new QTableWidgetItem(query2.value(7).toString()));
			ui.tableWidget->setItem(row,6,new QTableWidgetItem(query2.value(8).toString()));
			row++;
		}
	}
	ui.treeWidget->expandAll();
}
void Package::showTable(QTreeWidgetItem*item, int column)
{
	ui.tableWidget->setRowCount(0);
	QString strText = item->text(0);
	QString strsql;
	strsql = "select * from sys_package_detail where name  = '"+strText+"' ";
	QSqlQuery query(*sql.db);	
	query.exec(strsql);
	int row = 0;
	while(query.next())
	{	
		ui.tableWidget->insertRow(row);
		ui.tableWidget->setItem(row,0,new QTableWidgetItem(query.value(2).toString()));
		ui.tableWidget->setItem(row,1,new QTableWidgetItem(query.value(3).toString()));
		ui.tableWidget->setItem(row,2,new QTableWidgetItem(query.value(4).toString()));
		ui.tableWidget->setItem(row,3,new QTableWidgetItem(query.value(5).toString()));
		ui.tableWidget->setItem(row,4,new QTableWidgetItem(query.value(6).toString()));
		ui.tableWidget->setItem(row,5,new QTableWidgetItem(query.value(7).toString()));
		ui.tableWidget->setItem(row,6,new QTableWidgetItem(query.value(8).toString()));
		row++;
	}
}
void Package::on_okButton_clicked()
{
	 QList<QTreeWidgetItem*> list = ui.treeWidget->selectedItems();
	 QTreeWidgetItem*item = list.at(0);
	 QString strText = item->text(0);
	 if (strText==""||strText==NULL)
	 {
		 QMessageBox box(QMessageBox::Warning,QString::fromLocal8Bit("警告"),QString::fromLocal8Bit("请选择套餐"));
		 box.setStandardButtons (QMessageBox::Ok);
		 box.setButtonText (QMessageBox::Ok,QString::fromLocal8Bit("确 定"));
		 box.exec();
		 return;
	 }
	 emit showPackage(strText);
	 this->close();
}
void Package::on_exitButton_clicked()
{

	this->close();
}
Package::~Package()
{

}
