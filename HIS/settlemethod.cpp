#include "settlemethod.h"
#include "connectsql.h"
#include <QTreeWidgetItem>
#include <QTextCodec>
extern ConnectSql sql;
Settlemethod::Settlemethod(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	ui.treeWidget->setColumnCount(1);
	ui.tableWidget->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
	ui.tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui.tableWidget->setStyleSheet("QTableWidget{border: 1px solid gray;	background-color: transparent;	selection-color: grey;}");
	ui.tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section {background-color:white;color: black;padding-left: 4px;border: 1px solid #6c6c6c;};"
		"color: white;padding-left: 4px;border: 1px solid #6c6c6c;}"
		"QHeaderView::section:checked{background-color: white;color: black;}");	
	ui.treeWidget->setStyleSheet("QTreeWidget{border: 1px solid gray;color: black;	background-color: white;selection-color: grey;}");
	//connect(ui.treeWidget,SIGNAL(itemClicked(QTreeWidgetItem*,int)),this,SLOT(showTable(QTreeWidgetItem*,int)));
	initUI();
}
void Settlemethod::initUI()
{
	ui.treeWidget->clear();
	ui.tableWidget->setRowCount(0);
	QStringList headers;
	headers << QString::fromLocal8Bit("���㷽ʽ");
	ui.treeWidget->setHeaderLabels(headers);

	QTextCodec::setCodecForTr(QTextCodec::codecForName("GBK"));
	QTextCodec::setCodecForLocale(QTextCodec::codecForName("GBK"));

	QString strsql;
	strsql = "select * from sys_settlingmethod order by id";
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
		row++;
	}
	ui.treeWidget->expandAll();
	ui.saveButton->setEnabled(false);
	//ui.deleteButton->setEnabled(false);
}
void Settlemethod::showTable(QTreeWidgetItem*item,int column)
{
	ui.tableWidget->setRowCount(0);
	QString strText = item->text(0);
	QString strsql;
	strsql = "select * from sys_settlingmethod where name  = '"+strText+"' order by id";//  
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
		row++;
	}
}
void Settlemethod::on_addButton_clicked()
{
	initUI();
	ui.saveButton->setEnabled(true);
	ui.tableWidget->setEditTriggers(QAbstractItemView::AllEditTriggers);
	int row = ui.tableWidget->rowCount();
	ui.tableWidget->insertRow(row);
	ui.tableWidget->setItem(row,0,new QTableWidgetItem(QString::number(row+1)));
}
void Settlemethod::on_deleteButton_clicked()
{
	QMessageBox box(QMessageBox::Warning,QString::fromLocal8Bit("����"),QString::fromLocal8Bit("ȷ��ɾ����"));
	box.setStandardButtons (QMessageBox::Ok|QMessageBox::Cancel);
	box.setButtonText (QMessageBox::Ok,QString::fromLocal8Bit("ȷ ��"));
	box.setButtonText (QMessageBox::Cancel,QString::fromLocal8Bit("ȡ ��"));
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
		query.exec("delete  from sys_settlingmethod where name = '"+strName+"'");
		initUI();
	}
}
void Settlemethod::on_editButton_clicked()
{
	ui.tableWidget->setEditTriggers(QAbstractItemView::AllEditTriggers);
	ui.saveButton->setEnabled(true);
	ui.editButton->setEnabled(true);
	ui.deleteButton->setEnabled(true);
}
void Settlemethod::on_saveButton_clicked()
{

	QMessageBox box(QMessageBox::Warning,QString::fromLocal8Bit("����"),QString::fromLocal8Bit("�Ƿ񱣴棿"));
	box.setStandardButtons (QMessageBox::Ok|QMessageBox::Cancel);
	box.setButtonText (QMessageBox::Ok,QString::fromLocal8Bit("ȷ ��"));
	box.setButtonText (QMessageBox::Cancel,QString::fromLocal8Bit("ȡ ��"));
	if(box.exec()==QMessageBox::Ok)
	{
		QSqlQuery query(*sql.db);		
		QString strsql = "delete from sys_department"; 
		query.exec(strsql);
		int row = ui.tableWidget->model()->rowCount();
		for (int i= 0;i<row;i++)
		{
			query.prepare("INSERT INTO sys_department VALUES (?,?, ?, ?)");
			query.bindValue(0, ui.tableWidget->item(i,0)->text().toInt());
			query.bindValue(1, ui.tableWidget->item(i,1)->text());
			query.bindValue(2, ui.tableWidget->item(i,2)->text());
			query.bindValue(3, ui.tableWidget->item(i,3)->text());
			query.exec();
		}
		initUI();
		ui.saveButton->setEnabled(false);
		ui.editButton->setEnabled(true);
		ui.tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
	}
}
void Settlemethod::on_exitButton_clicked()
{

	QMessageBox box(QMessageBox::Warning,QString::fromLocal8Bit("����"),QString::fromLocal8Bit("ȷ���˳���"));
	box.setStandardButtons (QMessageBox::Ok|QMessageBox::Cancel);
	box.setButtonText (QMessageBox::Ok,QString::fromLocal8Bit("ȷ ��"));
	box.setButtonText (QMessageBox::Cancel,QString::fromLocal8Bit("ȡ ��"));
	if(box.exec()==QMessageBox::Ok)
	{
		this->close();
	}
}
Settlemethod::~Settlemethod()
{

}
