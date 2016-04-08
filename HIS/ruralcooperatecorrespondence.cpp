#include "ruralcooperatecorrespondence.h"
#include "connectsql.h"
#include "odbcexcel.h"
#include <QDesktopServices>
#include <QTreeWidgetItem>
#include <QTextCodec>
#include <QDate>
//#include "excelengine.h"
#include "qaxobject.h"
#include <QVariant>
#include <QAxBase>
#include <QAxObject>
extern ConnectSql sql;
ruralcooperatecorrespondence::ruralcooperatecorrespondence(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	ui.tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

	ui.tableWidget->setStyleSheet("QTableWidget{border: 1px solid gray;	background-color: transparent;	selection-color: grey;}");
	ui.tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section {background-color:white;color: black;padding-left: 4px;border: 1px solid #6c6c6c;};"
		"color: white;padding-left: 4px;border: 1px solid #6c6c6c;}"
		"QHeaderView::section:checked{background-color: white;color: black;}");	
	
	connect(ui.treeWidget,SIGNAL(itemClicked(QTreeWidgetItem*,int)),this,SLOT(showTable(QTreeWidgetItem*,int)));
	initUI();
}
void ruralcooperatecorrespondence::initUI()
{
	ui.treeWidget->clear();
	ui.tableWidget->setRowCount(0);
	QStringList headers;
	headers << QString::fromLocal8Bit("农合对应关系");
	ui.treeWidget->setHeaderLabels(headers);

	QTextCodec::setCodecForTr(QTextCodec::codecForName("GBK"));
	QTextCodec::setCodecForLocale(QTextCodec::codecForName("GBK"));

	QStringList strlist;
	strlist <<QString::fromLocal8Bit("药品");
	QTreeWidgetItem *item = new QTreeWidgetItem(ui.treeWidget, strlist);
	ui.treeWidget->addTopLevelItem(item);
	ui.treeWidget->setItemSelected(item,true);
	strlist.clear();
	strlist <<QString::fromLocal8Bit("医疗项目");
	item = new QTreeWidgetItem(ui.treeWidget, strlist);
	ui.treeWidget->addTopLevelItem(item);
	strlist.clear();
	strlist <<QString::fromLocal8Bit("卫生材料");
	item = new QTreeWidgetItem(ui.treeWidget, strlist);
	ui.treeWidget->addTopLevelItem(item);
	sql.connect2();
	QStringList header;
	ui.tableWidget->setColumnCount(6); 
	header<<QString::fromLocal8Bit("药品代码 ")<<QString::fromLocal8Bit("化学名称")<<QString::fromLocal8Bit("常用名称")<<QString::fromLocal8Bit("常用名称拼音")<<QString::fromLocal8Bit("剂型名称")<<QString::fromLocal8Bit("药品属性");
	ui.tableWidget->setHorizontalHeaderLabels(header);  
	QSqlQuery query(sql.db2);
	query.exec("select * from HIS.t_dic1");
	int row =ui.tableWidget->rowCount();
	while (query.next())
	{
		ui.tableWidget->insertRow(row);
		ui.tableWidget->setItem(row,0,new QTableWidgetItem(query.value(0).toString()));
		ui.tableWidget->setItem(row,1,new QTableWidgetItem(query.value(1).toString()));
		ui.tableWidget->setItem(row,2,new QTableWidgetItem(query.value(2).toString()));
		ui.tableWidget->setItem(row,3,new QTableWidgetItem(query.value(3).toString()));
		ui.tableWidget->setItem(row,4,new QTableWidgetItem(query.value(4).toString()));
		ui.tableWidget->setItem(row,5,new QTableWidgetItem(query.value(5).toString()));
		row++;
	}
	sql.disconnect2();
}
void ruralcooperatecorrespondence::on_inputButton_clicked()
{
	
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
	QList<QTreeWidgetItem*> list= ui.treeWidget->selectedItems();
	QTreeWidgetItem*item = list.at(0);
	QString strText = item->text(0);
	sql.connect2();
	QSqlQuery query2(sql.db2);	
	if (strText==QString::fromLocal8Bit("药品"))
	{
		QStringList header;
		ui.tableWidget->setColumnCount(6); 
		header<<QString::fromLocal8Bit("药品代码 ")<<QString::fromLocal8Bit("化学名称")<<QString::fromLocal8Bit("常用名称")<<QString::fromLocal8Bit("常用名称拼音")<<QString::fromLocal8Bit("剂型名称")<<QString::fromLocal8Bit("药品属性");
		ui.tableWidget->setHorizontalHeaderLabels(header);  

		int row =ui.tableWidget->rowCount();
		while (query.next())
		{
			ui.tableWidget->insertRow(row);
			ui.tableWidget->setItem(row,0,new QTableWidgetItem(query.value(0).toString()));
			ui.tableWidget->setItem(row,1,new QTableWidgetItem(query.value(1).toString()));
			ui.tableWidget->setItem(row,2,new QTableWidgetItem(query.value(2).toString()));
			ui.tableWidget->setItem(row,3,new QTableWidgetItem(query.value(3).toString()));
			ui.tableWidget->setItem(row,4,new QTableWidgetItem(query.value(4).toString()));
			ui.tableWidget->setItem(row,5,new QTableWidgetItem(query.value(5).toString()));

		
			query2.prepare("INSERT INTO HIS.t_dic1 VALUES (?,?, ?, ?, ?, ?)");
			for(int i=0;i<6;i++)
			{
				query2.bindValue(i,query.value(i));
			}
			query2.exec();

			row++;
		}


	}
	
	if (strText==QString::fromLocal8Bit("医疗项目"))
	{
		QStringList header;
		ui.tableWidget->setColumnCount(5); 
		header<<QString::fromLocal8Bit("项目代码")<<QString::fromLocal8Bit("项目名称")<<QString::fromLocal8Bit("拼音")<<QString::fromLocal8Bit("财务分类代码")<<QString::fromLocal8Bit("计价单位")<<QString::fromLocal8Bit("计价单位");
		ui.tableWidget->setHorizontalHeaderLabels(header);  

		int row =ui.tableWidget->rowCount();
		while (query.next())
		{
			ui.tableWidget->insertRow(row);
			ui.tableWidget->setItem(row,0,new QTableWidgetItem(query.value(0).toString()));
			ui.tableWidget->setItem(row,1,new QTableWidgetItem(query.value(1).toString()));
			ui.tableWidget->setItem(row,2,new QTableWidgetItem(query.value(2).toString()));
			ui.tableWidget->setItem(row,3,new QTableWidgetItem(query.value(3).toString()));
			ui.tableWidget->setItem(row,4,new QTableWidgetItem(query.value(4).toString()));
			ui.tableWidget->setItem(row,5,new QTableWidgetItem(query.value(5).toString()));
			
			query2.prepare("INSERT INTO HIS.t_dic2 VALUES (?,?, ?, ?, ?)");
			for(int i=0;i<5;i++)
			{
				query2.bindValue(i,query.value(i));
			}
			query2.exec();

			row++;
		}
	}

	if (strText==QString::fromLocal8Bit("卫生材料"))
	{
		QStringList header;
		ui.tableWidget->setColumnCount(6); 
		header<<QString::fromLocal8Bit("材料代码")<<QString::fromLocal8Bit("材料名称")<<QString::fromLocal8Bit("项名拼音")<<QString::fromLocal8Bit("规格")<<QString::fromLocal8Bit("包装")<<QString::fromLocal8Bit("计价单位");
		ui.tableWidget->setHorizontalHeaderLabels(header);  

		int row =ui.tableWidget->rowCount();
		while (query.next())
		{
			ui.tableWidget->insertRow(row);
			ui.tableWidget->setItem(row,0,new QTableWidgetItem(query.value(0).toString()));
			ui.tableWidget->setItem(row,1,new QTableWidgetItem(query.value(1).toString()));
			ui.tableWidget->setItem(row,2,new QTableWidgetItem(query.value(2).toString()));
			ui.tableWidget->setItem(row,3,new QTableWidgetItem(query.value(3).toString()));
			ui.tableWidget->setItem(row,4,new QTableWidgetItem(query.value(4).toString()));
			ui.tableWidget->setItem(row,5,new QTableWidgetItem(query.value(5).toString()));
			
			query2.prepare("INSERT INTO HIS.t_dic3 VALUES (?,?, ?, ?, ?, ?)");
			for(int i=0;i<6;i++)
			{
				query2.bindValue(i,query.value(i));
			}
			query2.exec();
			row++;
		}
	}
	db.close();
	QMessageBox box(QMessageBox::Warning,QString::fromLocal8Bit("提示"),QString::fromLocal8Bit("导入成功！"));
	box.setStandardButtons (QMessageBox::Ok);
	box.setButtonText (QMessageBox::Ok,QString::fromLocal8Bit("确 定"));
	box.exec();
	sql.disconnect2();
}
void ruralcooperatecorrespondence::on_outputButton_clicked()
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
		QString msg=str.fromLocal8Bit("保存失败！\n\r")+OdbcExcel::getError();
		QMessageBox box(QMessageBox::Warning,QString::fromLocal8Bit("警告"),msg);
		box.setStandardButtons (QMessageBox::Ok);
		box.setButtonText (QMessageBox::Ok,QString::fromLocal8Bit("确 定"));
		box.exec();
	}
}
void ruralcooperatecorrespondence::showTable(QTreeWidgetItem*item, int column)
{
	ui.tableWidget->clear();
	ui.tableWidget->setRowCount(0);
	QString strText = item->text(0);
	sql.connect2();
	if (strText==QString::fromLocal8Bit("药品"))
	{
		QStringList header;
		ui.tableWidget->setColumnCount(6); 
		header<<QString::fromLocal8Bit("药品代码 ")<<QString::fromLocal8Bit("化学名称")<<QString::fromLocal8Bit("常用名称")<<QString::fromLocal8Bit("常用名称拼音")<<QString::fromLocal8Bit("剂型名称")<<QString::fromLocal8Bit("药品属性");
		ui.tableWidget->setHorizontalHeaderLabels(header);  
		QSqlQuery query(sql.db2);
		query.exec("select * from HIS.t_dic1");
		int row =ui.tableWidget->rowCount();
		while (query.next())
		{
			ui.tableWidget->insertRow(row);
			ui.tableWidget->setItem(row,0,new QTableWidgetItem(query.value(0).toString()));
			ui.tableWidget->setItem(row,1,new QTableWidgetItem(query.value(1).toString()));
			ui.tableWidget->setItem(row,2,new QTableWidgetItem(query.value(2).toString()));
			ui.tableWidget->setItem(row,3,new QTableWidgetItem(query.value(3).toString()));
			ui.tableWidget->setItem(row,4,new QTableWidgetItem(query.value(4).toString()));
			ui.tableWidget->setItem(row,5,new QTableWidgetItem(query.value(5).toString()));
			row++;
		}
	}
	if (strText==QString::fromLocal8Bit("医疗项目"))
	{
		QStringList header;
		ui.tableWidget->setColumnCount(5); 
		header<<QString::fromLocal8Bit("项目代码")<<QString::fromLocal8Bit("项目名称")<<QString::fromLocal8Bit("项目名称")<<QString::fromLocal8Bit("财务分类代码")<<QString::fromLocal8Bit("计价单位")<<QString::fromLocal8Bit("计价单位");
		ui.tableWidget->setHorizontalHeaderLabels(header);  
		QSqlQuery query(sql.db2);
		query.exec("select * from HIS.t_dic2");
		int row =ui.tableWidget->rowCount();
		while (query.next())
		{
			ui.tableWidget->insertRow(row);
			ui.tableWidget->setItem(row,0,new QTableWidgetItem(query.value(0).toString()));
			ui.tableWidget->setItem(row,1,new QTableWidgetItem(query.value(1).toString()));
			ui.tableWidget->setItem(row,2,new QTableWidgetItem(query.value(2).toString()));
			ui.tableWidget->setItem(row,3,new QTableWidgetItem(query.value(3).toString()));
			ui.tableWidget->setItem(row,4,new QTableWidgetItem(query.value(4).toString()));
			row++;
		}
	}
	if (strText==QString::fromLocal8Bit("卫生材料"))
	{
		QStringList header;
		ui.tableWidget->setColumnCount(6); 
		header<<QString::fromLocal8Bit("材料代码")<<QString::fromLocal8Bit("材料名称")<<QString::fromLocal8Bit("项名拼音")<<QString::fromLocal8Bit("规格")<<QString::fromLocal8Bit("包装")<<QString::fromLocal8Bit("计价单位");
		ui.tableWidget->setHorizontalHeaderLabels(header);  
		QSqlQuery query(sql.db2);
		query.exec("select * from HIS.t_dic3");
		int row =ui.tableWidget->rowCount();
		while (query.next())
		{
			ui.tableWidget->insertRow(row);
			ui.tableWidget->setItem(row,0,new QTableWidgetItem(query.value(0).toString()));
			ui.tableWidget->setItem(row,1,new QTableWidgetItem(query.value(1).toString()));
			ui.tableWidget->setItem(row,2,new QTableWidgetItem(query.value(2).toString()));
			ui.tableWidget->setItem(row,3,new QTableWidgetItem(query.value(3).toString()));
			ui.tableWidget->setItem(row,4,new QTableWidgetItem(query.value(4).toString()));
			ui.tableWidget->setItem(row,5,new QTableWidgetItem(query.value(5).toString()));
			row++;
		}
	}
	sql.disconnect2();
}
void ruralcooperatecorrespondence::on_exitButton_clicked()
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
void ruralcooperatecorrespondence::on_deleteButton_clicked()
{
	QMessageBox box(QMessageBox::Warning,QString::fromLocal8Bit("警告"),QString::fromLocal8Bit("确认从数据库中删除该行？"));
	box.setStandardButtons (QMessageBox::Ok|QMessageBox::Cancel);
	box.setButtonText (QMessageBox::Ok,QString::fromLocal8Bit("确 定"));
	box.setButtonText (QMessageBox::Cancel,QString::fromLocal8Bit("取 消"));
	if(box.exec()==QMessageBox::Ok)
	{
		int row = ui.tableWidget->currentRow();
		QString strName = ui.tableWidget->item(row,1)->text().trimmed();
		QList<QTreeWidgetItem*> list= ui.treeWidget->selectedItems();
		QTreeWidgetItem*item = list.at(0);
		QString strText = item->text(0);
		sql.connect2();
		QSqlQuery query2(sql.db2);	
		QString strsql;
		if (strText==QString::fromLocal8Bit("药品"))
		{
			strsql = QString("delete from HIS.t_dic1 where mc1  = '"+strName+"'");
		}
		if (strText==QString::fromLocal8Bit("医疗项目"))
		{
			strsql = QString("delete from HIS.t_dic2 where Mc = '"+strName+"'");
		}
		if (strText==QString::fromLocal8Bit("卫生材料"))
		{
			strsql = QString("delete from HIS.t_dic3 where Mc = '"+strName+"'");	
		}
		if (query2.exec(strsql))
		{
			QMessageBox box(QMessageBox::Warning,QString::fromLocal8Bit("提示"),QString::fromLocal8Bit("删除成功！"));
			box.setStandardButtons (QMessageBox::Ok);
			box.setButtonText (QMessageBox::Ok,QString::fromLocal8Bit("确 定"));
			box.exec();
		}
		sql.disconnect2();
	}
}
ruralcooperatecorrespondence::~ruralcooperatecorrespondence()
{

}
