#include "drugdictionary.h"
#include "connectsql.h"
#include "odbcexcel.h"
#include "drugdictionaryadd.h"
#include <QTreeWidgetItem>
#include <QTextCodec>
#include <QDesktopServices>
extern ConnectSql sql;
Drugdictionary::Drugdictionary(QWidget *parent)
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
	connect(ui.treeWidget,SIGNAL(itemClicked(QTreeWidgetItem*,int)),this,SLOT(showTable(QTreeWidgetItem*,int)));
	initUI();
}
void Drugdictionary::initUI()
{
	ui.treeWidget->clear();
	ui.tableWidget->setRowCount(0);
	QStringList headers;
	headers << QString::fromLocal8Bit("字典分类");
	ui.treeWidget->setHeaderLabels(headers);

	QTextCodec::setCodecForTr(QTextCodec::codecForName("GBK"));
	QTextCodec::setCodecForLocale(QTextCodec::codecForName("GBK"));
	QStringList strlist;
	strlist <<QString::fromLocal8Bit("西药");
	QTreeWidgetItem *item = new QTreeWidgetItem(ui.treeWidget, strlist);
	ui.treeWidget->addTopLevelItem(item);
	strlist.clear();
	strlist <<QString::fromLocal8Bit("中成药");
	item = new QTreeWidgetItem(ui.treeWidget, strlist);
	ui.treeWidget->addTopLevelItem(item);
	strlist.clear();
	strlist <<QString::fromLocal8Bit("医疗项目");
	item = new QTreeWidgetItem(ui.treeWidget, strlist);
	ui.treeWidget->addTopLevelItem(item);
	strlist.clear();
	strlist <<QString::fromLocal8Bit("卫生材料");
	item = new QTreeWidgetItem(ui.treeWidget, strlist);
	ui.treeWidget->addTopLevelItem(item);
	ui.treeWidget->expandAll();
	ui.tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

	//ui.saveButton->setEnabled(false);
	connect(ui.tableWidget,SIGNAL(cellDoubleClicked(int,int)),this,SLOT(getItem(int,int)));

	QString strsql;
	strsql = "select * from sys_drugdictionary  order by id";//
	QSqlQuery query(*sql.db);	
	query.exec(strsql);
	int row = 0;
	while(query.next())
	{	
		ui.tableWidget->insertRow(row);
		ui.tableWidget->setItem(row,0,new QTableWidgetItem(query.value(0).toString()));
		//ui.tableWidget->setItem(row,1,new QTableWidgetItem(query.value(1).toString()));
		//ui.tableWidget->setItem(row,2,new QTableWidgetItem(query.value(2).toString()));
		//ui.tableWidget->setItem(row,3,new QTableWidgetItem(query.value(3).toString()));
		//ui.tableWidget->setItem(row,4,new QTableWidgetItem(query.value(4).toString()));
		//ui.tableWidget->setItem(row,5,new QTableWidgetItem(query.value(5).toString()));
		//ui.tableWidget->setItem(row,6,new QTableWidgetItem(query.value(6).toString()));
		//ui.tableWidget->setItem(row,7,new QTableWidgetItem(query.value(7).toString()));
		//ui.tableWidget->setItem(row,8,new QTableWidgetItem(query.value(8).toString()));
		//ui.tableWidget->setItem(row,9,new QTableWidgetItem(query.value(9).toString()));
		ui.tableWidget->setItem(row,1,new QTableWidgetItem(query.value(22).toString()));
		for (int i =2;i<23;i++)
		{
			ui.tableWidget->setItem(row,i,new QTableWidgetItem(query.value(i-1).toString()));
		}
		row++;
	}
	//ui.deleteButton->setEnabled(false);
}
void Drugdictionary::showTable(QTreeWidgetItem*item,int column)
{
	ui.tableWidget->setRowCount(0);
	QString strText = item->text(0);
	QString strsql;
	strsql = "select * from sys_drugdictionary where dictionary_classification  = '"+strText+"'   order by id";//
	QSqlQuery query(*sql.db);	
	query.exec(strsql);
	int row = 0;
	while(query.next())
	{	
		ui.tableWidget->insertRow(row);
		ui.tableWidget->setItem(row,0,new QTableWidgetItem(query.value(0).toString()));
		//ui.tableWidget->setItem(row,1,new QTableWidgetItem(query.value(1).toString()));
		//ui.tableWidget->setItem(row,2,new QTableWidgetItem(query.value(2).toString()));
		//ui.tableWidget->setItem(row,3,new QTableWidgetItem(query.value(3).toString()));
		//ui.tableWidget->setItem(row,4,new QTableWidgetItem(query.value(4).toString()));
		//ui.tableWidget->setItem(row,5,new QTableWidgetItem(query.value(5).toString()));
		//ui.tableWidget->setItem(row,6,new QTableWidgetItem(query.value(6).toString()));
		//ui.tableWidget->setItem(row,7,new QTableWidgetItem(query.value(7).toString()));
		//ui.tableWidget->setItem(row,8,new QTableWidgetItem(query.value(8).toString()));
		//ui.tableWidget->setItem(row,9,new QTableWidgetItem(query.value(9).toString()));
		ui.tableWidget->setItem(row,1,new QTableWidgetItem(query.value(22).toString()));
		for (int i =2;i<23;i++)
		{
			ui.tableWidget->setItem(row,i,new QTableWidgetItem(query.value(i-1).toString()));
		}
		row++;
		QCoreApplication::processEvents();
	}
}
void Drugdictionary::on_addButton_clicked()
{
// 	initUI();
// 	ui.saveButton->setEnabled(true);
// 	ui.tableWidget->setEditTriggers(QAbstractItemView::AllEditTriggers);
// 	int row = ui.tableWidget->rowCount();
// 	ui.tableWidget->insertRow(row);
// 	ui.tableWidget->setItem(row,0,new QTableWidgetItem(QString::number(row+1)));
	Drugdictionaryadd*add = new Drugdictionaryadd;
	add->setWindowModality(Qt::WindowModal);
	add->show();
}
void Drugdictionary::on_deleteButton_clicked()
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
		QString strName = ui.tableWidget->item(list.at(0)->row(),2)->text();
		if (strName==NULL)
		{
			return;
		}
		QSqlQuery query(*sql.db);
		query.exec("delete  from sys_drugdictionary where name = '"+strName+"'");
		initUI();
	}
}
void Drugdictionary::on_editButton_clicked()
{
	ui.tableWidget->setEditTriggers(QAbstractItemView::AllEditTriggers);
	//ui.saveButton->setEnabled(true);
	ui.deleteButton->setEnabled(true);
}
void Drugdictionary::on_saveButton_clicked()
{

}
void Drugdictionary::on_exitButton_clicked()
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
void Drugdictionary::on_inputButton_clicked()
{
	ui.tableWidget->setRowCount(0);
	QFileDialog fileSelect;
	fileSelect.setWindowTitle(QString::fromLocal8Bit("请选择读取数据xls文件"));
	fileSelect.exec();
	QStringList fileList = fileSelect.selectedFiles();
	if (fileList.count() == 0)
		return;
	QString dbfile = fileList.first();  //指定excel文件

	//打开输入数据xls
	QSqlDatabase db = QSqlDatabase::addDatabase("QODBC", "input_source");
	QString dbName = "Driver={Microsoft Excel Driver (*.xls)};Dbq=" + dbfile;
	db.setDatabaseName(dbName);
	if (!db.open())
	{
		return;
	}
	QSqlQuery query(db);
	if (! query.exec("select * from [" + QString("Sheet1") + "$]"))
	{
		return;
	}
	//读取输入文件并写入结果文件
	//QList<QTreeWidgetItem*> list= ui.treeWidget->selectedItems();
	//QTreeWidgetItem*item = list.at(0);
	//QString strText = item->text(0);
	QSqlQuery query2(*sql.db);	
	int count =0;
	query2.exec("select * from sys_drugdictionary");
	while(query2.next())
	{
		count++;
	}
	int row =ui.tableWidget->rowCount();
	while (query.next())
	{
		ui.tableWidget->insertRow(row);
		ui.tableWidget->setItem(row,0,new QTableWidgetItem(query.value(0).toString()));
		ui.tableWidget->setItem(row,1,new QTableWidgetItem(query.value(1).toString()));
		ui.tableWidget->setItem(row,2,new QTableWidgetItem(query.value(2).toString()));
		ui.tableWidget->setItem(row,3,new QTableWidgetItem(query.value(3).toString()));
		//ui.tableWidget->setItem(iRow,4,new QTableWidgetItem(query.value(6).toString()));//批号
		//ui.tableWidget->setItem(iRow,5,new QTableWidgetItem(query.value(6).toString()));//库存
		ui.tableWidget->setItem(row,4,new QTableWidgetItem(query.value(4).toString()));
		ui.tableWidget->setItem(row,5,new QTableWidgetItem(query.value(5).toString()));
		ui.tableWidget->setItem(row,6,new QTableWidgetItem(query.value(6).toString()));//
		ui.tableWidget->setItem(row,7,new QTableWidgetItem(query.value(7).toString()));//
		ui.tableWidget->setItem(row,8,new QTableWidgetItem(query.value(8).toString()));
		ui.tableWidget->setItem(row,9,new QTableWidgetItem(query.value(9).toString()));
		ui.tableWidget->setItem(row,10,new QTableWidgetItem(query.value(10).toString()));//
		ui.tableWidget->setItem(row,11,new QTableWidgetItem(query.value(11).toString()));
		ui.tableWidget->setItem(row,12,new QTableWidgetItem(query.value(12).toString()));
		ui.tableWidget->setItem(row,13,new QTableWidgetItem(query.value(13).toString()));
		ui.tableWidget->setItem(row,14,new QTableWidgetItem(query.value(14).toString()));
		ui.tableWidget->setItem(row,15,new QTableWidgetItem(query.value(15).toString()));
		ui.tableWidget->setItem(row,16,new QTableWidgetItem(query.value(16).toString()));
		ui.tableWidget->setItem(row,17,new QTableWidgetItem(query.value(17).toString()));
		ui.tableWidget->setItem(row,18,new QTableWidgetItem(query.value(18).toString()));
		ui.tableWidget->setItem(row,19,new QTableWidgetItem(query.value(19).toString()));
		ui.tableWidget->setItem(row,20,new QTableWidgetItem(query.value(20).toString()));
		ui.tableWidget->setItem(row,21,new QTableWidgetItem(query.value(21).toString()));
		ui.tableWidget->setItem(row,22,new QTableWidgetItem(query.value(22).toString()));
	//	ui.tableWidget->setItem(row,23,new QTableWidgetItem(query.value(23).toString()));

		count++;
		query2.prepare("INSERT INTO sys_drugdictionary VALUES (?,?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)");
		query2.bindValue(0, count);
		//query2.bindValue(1, query.value(2).toString());
		//query2.bindValue(2, query.value(3).toString());
		for(int i=1;i<22;i++)
		{
			if (i==15||i==16||i==17)
			{
				query2.bindValue(i, query.value(i+1).toDouble());
			}
			else
			{
				query2.bindValue(i, query.value(i+1).toString());
			}
			
		}	
		query2.bindValue(22, query.value(1).toString());
		query2.bindValue(23, NULL);
		query2.exec();
		row++;
		QCoreApplication::processEvents();
	}
	db.close();
	QMessageBox box(QMessageBox::Warning,QString::fromLocal8Bit("提示"),QString::fromLocal8Bit("导入成功！"));
	box.setStandardButtons (QMessageBox::Ok);
	box.setButtonText (QMessageBox::Ok,QString::fromLocal8Bit("确 定"));
	box.exec();
}
void Drugdictionary::on_outputButton_clicked()
{
	QFileDialog dlg;
	dlg.setAcceptMode(QFileDialog::AcceptSave);
	//  Qt 5
	//dlg.setDirectory(QStandardPaths::writableLocation(QStandardPaths::DesktopLocation));
	//  Qt 4
	dlg.setDirectory(QDesktopServices::storageLocation(QDesktopServices::DesktopLocation));
	dlg.setNameFilter("*.xls");
	QList<QTreeWidgetItem*> list= ui.treeWidget->selectedItems();
	QTreeWidgetItem*item = list.at(0);
	QString strText = item->text(0);

	dlg.selectFile(strText);

	if(dlg.exec()!= QDialog::Accepted)
		return;
	QString filePath=dlg.selectedFiles()[0];
	if(OdbcExcel::saveFromTable(filePath,ui.tableWidget,"")) {
		QString str = str.fromLocal8Bit("提示");
		QString str2 = str.fromLocal8Bit("保存成功");
		QMessageBox box(QMessageBox::Warning,QString::fromLocal8Bit("提示"),str2);
		box.setStandardButtons (QMessageBox::Ok);
		box.setButtonText (QMessageBox::Ok,QString::fromLocal8Bit("确 定"));
		box.exec();
	}
	else{
		QString str = str.fromLocal8Bit("错误");
		QString str2=str.fromLocal8Bit("保存失败！\n\r")+OdbcExcel::getError();
		QMessageBox box(QMessageBox::Warning,QString::fromLocal8Bit("提示"),str2);
		box.setStandardButtons (QMessageBox::Ok);
		box.setButtonText (QMessageBox::Ok,QString::fromLocal8Bit("确 定"));
		box.exec();
	}
}
void Drugdictionary::getItem(int row ,int col)
{
	int cols = ui.tableWidget->columnCount();
	QStringList list;
	for (int i=0;i<cols;i++)
	{
		list.append(ui.tableWidget->item(row,i)->text());
	}
	Drugdictionaryadd*add = new Drugdictionaryadd;
	add->setWindowModality(Qt::WindowModal);
	add->edit(list);
	add->show();
}
void Drugdictionary::on_deleteAllButton_clicked()
{
	QMessageBox box(QMessageBox::Warning,QString::fromLocal8Bit("警告"),QString::fromLocal8Bit("确认全部删除？"));
	box.setStandardButtons (QMessageBox::Ok|QMessageBox::Cancel);
	box.setButtonText (QMessageBox::Ok,QString::fromLocal8Bit("确 定"));
	box.setButtonText (QMessageBox::Cancel,QString::fromLocal8Bit("取 消"));
	if(box.exec()==QMessageBox::Ok)
	{
		QSqlQuery query(*sql.db);
		query.exec("delete  from sys_drugdictionary");
		initUI();
	}
}
Drugdictionary::~Drugdictionary()
{

}
