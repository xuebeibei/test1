#include "supplier.h"
#include "connectsql.h"
#include <QTreeWidgetItem>
#include <QTextCodec>
#include "QDate"
extern ConnectSql sql;
Supplier::Supplier(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	ui.treeWidget->setColumnCount(1);

	ui.tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui.tableWidget->setStyleSheet("QTableWidget{border: 1px solid gray;	background-color: transparent;	selection-color: grey;}");
	ui.tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section {background-color:white;color: black;padding-left: 4px;border: 1px solid #6c6c6c;};"
		"color: white;padding-left: 4px;border: 1px solid #6c6c6c;}"
		"QHeaderView::section:checked{background-color: white;color: black;}");	
	ui.treeWidget->setStyleSheet("QTreeWidget{border: 1px solid gray;color: black;	background-color: white;selection-color: grey;}");
	//connect(ui.treeWidget,SIGNAL(itemClicked(QTreeWidgetItem*,int)),this,SLOT(showTable(QTreeWidgetItem*,int)));
	initUI();
}
void Supplier::initUI()
{
	ui.treeWidget->clear();
	ui.tableWidget->setRowCount(0);
	QStringList headers;
	headers << QString::fromLocal8Bit("供应商列表");
	ui.treeWidget->setHeaderLabels(headers);

	QTextCodec::setCodecForTr(QTextCodec::codecForName("GBK"));
	QTextCodec::setCodecForLocale(QTextCodec::codecForName("GBK"));

	QString strsql;
	strsql = "select * from sys_supplier order by id";
	QSqlQuery query(*sql.db);	
	query.exec(strsql);
	int row = 0;
	while(query.next())
	{	
		QStringList strlist;
		strlist <<query.value(1).toString();
		QTreeWidgetItem *item = new QTreeWidgetItem(ui.treeWidget, strlist);
		ui.treeWidget->addTopLevelItem(item);
		ui.tableWidget->insertRow(row);
		ui.tableWidget->setItem(row,0,new QTableWidgetItem(query.value(0).toString()));
		ui.tableWidget->setItem(row,1,new QTableWidgetItem(query.value(1).toString()));
		ui.tableWidget->setItem(row,2,new QTableWidgetItem(query.value(2).toString()));
		ui.tableWidget->setItem(row,3,new QTableWidgetItem(query.value(3).toString()));
		ui.tableWidget->setItem(row,4,new QTableWidgetItem(query.value(4).toString()));
		ui.tableWidget->setItem(row,5,new QTableWidgetItem(query.value(5).toString()));
		ui.tableWidget->setItem(row,6,new QTableWidgetItem(query.value(6).toString()));
		ui.tableWidget->setItem(row,7,new QTableWidgetItem(query.value(7).toString()));
		row++;
	}
	ui.treeWidget->expandAll();
	ui.saveButton->setEnabled(false);
	//ui.deleteButton->setEnabled(false);
}
void Supplier::showTable(QTreeWidgetItem*item,int column)
{
	ui.tableWidget->setRowCount(0);
	QString strText = item->text(0);
	QString strsql;
	strsql = "select * from sys_supplier where name  = '"+strText+"' order by id";//  
	QSqlQuery query(*sql.db);	
	query.exec(strsql);
	int row = 0;
	while(query.next())
	{	
		ui.tableWidget->insertRow(row);
		ui.tableWidget->setItem(row,0,new QTableWidgetItem(query.value(0).toString()));
		ui.tableWidget->setItem(row,1,new QTableWidgetItem(query.value(1).toString()));
		ui.tableWidget->setItem(row,2,new QTableWidgetItem(query.value(2).toString()));
		ui.tableWidget->setItem(row,3,new QTableWidgetItem(query.value(3).toString()));
		ui.tableWidget->setItem(row,4,new QTableWidgetItem(query.value(4).toString()));
		ui.tableWidget->setItem(row,5,new QTableWidgetItem(query.value(5).toString()));
		ui.tableWidget->setItem(row,6,new QTableWidgetItem(query.value(6).toString()));
		ui.tableWidget->setItem(row,7,new QTableWidgetItem(query.value(7).toString()));
		row++;
	}
}
void Supplier::on_addButton_clicked()
{
	initUI();
	ui.saveButton->setEnabled(true);
	ui.tableWidget->setEditTriggers(QAbstractItemView::AllEditTriggers);
	int row = ui.tableWidget->rowCount();
	ui.tableWidget->insertRow(row);
	ui.tableWidget->setItem(row,0,new QTableWidgetItem(QString::number(row+1)));

}
void Supplier::on_deleteButton_clicked()
{
	QMessageBox box(QMessageBox::Warning,QString::fromLocal8Bit("警告"),QString::fromLocal8Bit("确认删除？"));
	box.setStandardButtons (QMessageBox::Ok|QMessageBox::Cancel);
	box.setButtonText (QMessageBox::Ok,QString::fromLocal8Bit("确 定"));
	box.setButtonText (QMessageBox::Cancel,QString::fromLocal8Bit("取 消"));
	if(box.exec()==QMessageBox::Ok)
	{
		QList<QTableWidgetItem*> list =  ui.tableWidget->selectedItems();
		if (list.at(0)==NULL)
		{
			return;
		}
		QString strName = ui.tableWidget->item(list.at(0)->row(),1)->text();
		if (strName==NULL)
		{
			return;
		}
		QSqlQuery query(*sql.db);
		query.exec("delete  from sys_supplier where name = '"+strName+"'");
		initUI();
	}
}
void Supplier::on_editButton_clicked()
{
	ui.tableWidget->setEditTriggers(QAbstractItemView::AllEditTriggers);
	ui.saveButton->setEnabled(true);
	ui.deleteButton->setEnabled(true);
}
void Supplier::on_saveButton_clicked()
{
	QMessageBox box(QMessageBox::Warning,QString::fromLocal8Bit("警告"),QString::fromLocal8Bit("是否保存？"));
	box.setStandardButtons (QMessageBox::Ok|QMessageBox::Cancel);
	box.setButtonText (QMessageBox::Ok,QString::fromLocal8Bit("确 定"));
	box.setButtonText (QMessageBox::Cancel,QString::fromLocal8Bit("取 消"));
	if(box.exec()==QMessageBox::Ok)
	{
		QSqlQuery query(*sql.db);		
		QString strsql = "delete from sys_supplier"; 
		query.exec(strsql);
		int row = ui.tableWidget->model()->rowCount();
		for (int i= 0;i<row;i++)
		{
			query.prepare("INSERT INTO sys_supplier VALUES (?,?, ?, ?, ?, ?, ?, ?)");
			query.bindValue(0, ui.tableWidget->item(i,0)->text().toInt());
			for (int j=1;j<6;j++)
			{
				if (ui.tableWidget->item(i,j)==NULL) 
					query.bindValue(j, NULL);
				else
					query.bindValue(j, ui.tableWidget->item(i,j)->text());
			}
			if (ui.tableWidget->item(i,6)==NULL) 
				query.bindValue(6, NULL);
			else
				query.bindValue(6, QDate::fromString(ui.tableWidget->item(i,6)->text()));
			if (ui.tableWidget->item(i,7)==NULL) 
				query.bindValue(7, NULL);
			else
				query.bindValue(7, ui.tableWidget->item(i,7)->text());
			query.exec();
		}
		initUI();
		ui.saveButton->setEnabled(false);
		ui.editButton->setEnabled(true);
		ui.tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
	}
}
void Supplier::on_exitButton_clicked()
{
	QMessageBox box(QMessageBox::Warning,QString::fromLocal8Bit("警告"),QString::fromLocal8Bit("确认退出？"));
	box.setStandardButtons (QMessageBox::Ok|QMessageBox::Cancel);
	box.setButtonText (QMessageBox::Ok,QString::fromLocal8Bit("确 定"));
	box.setButtonText (QMessageBox::Cancel,QString::fromLocal8Bit("取 消"));
	if(box.exec()==QMessageBox::Ok)
	{
		this->close();
	}
}
Supplier::~Supplier()
{

}
