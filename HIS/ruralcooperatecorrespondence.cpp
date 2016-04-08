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
	headers << QString::fromLocal8Bit("ũ�϶�Ӧ��ϵ");
	ui.treeWidget->setHeaderLabels(headers);

	QTextCodec::setCodecForTr(QTextCodec::codecForName("GBK"));
	QTextCodec::setCodecForLocale(QTextCodec::codecForName("GBK"));

	QStringList strlist;
	strlist <<QString::fromLocal8Bit("ҩƷ");
	QTreeWidgetItem *item = new QTreeWidgetItem(ui.treeWidget, strlist);
	ui.treeWidget->addTopLevelItem(item);
	ui.treeWidget->setItemSelected(item,true);
	strlist.clear();
	strlist <<QString::fromLocal8Bit("ҽ����Ŀ");
	item = new QTreeWidgetItem(ui.treeWidget, strlist);
	ui.treeWidget->addTopLevelItem(item);
	strlist.clear();
	strlist <<QString::fromLocal8Bit("��������");
	item = new QTreeWidgetItem(ui.treeWidget, strlist);
	ui.treeWidget->addTopLevelItem(item);
	sql.connect2();
	QStringList header;
	ui.tableWidget->setColumnCount(6); 
	header<<QString::fromLocal8Bit("ҩƷ���� ")<<QString::fromLocal8Bit("��ѧ����")<<QString::fromLocal8Bit("��������")<<QString::fromLocal8Bit("��������ƴ��")<<QString::fromLocal8Bit("��������")<<QString::fromLocal8Bit("ҩƷ����");
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
	fileSelect.setWindowTitle(QString::fromLocal8Bit("��ѡ���ȡ����xls�ļ�"));
	fileSelect.exec();
	QStringList fileList = fileSelect.selectedFiles();
	if (fileList.count() == 0)
		return;
	QString dbfile = fileList.first();  //ָ��excel�ļ�

		//����������xls
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
	//��ȡ�����ļ���д�����ļ�
	QList<QTreeWidgetItem*> list= ui.treeWidget->selectedItems();
	QTreeWidgetItem*item = list.at(0);
	QString strText = item->text(0);
	sql.connect2();
	QSqlQuery query2(sql.db2);	
	if (strText==QString::fromLocal8Bit("ҩƷ"))
	{
		QStringList header;
		ui.tableWidget->setColumnCount(6); 
		header<<QString::fromLocal8Bit("ҩƷ���� ")<<QString::fromLocal8Bit("��ѧ����")<<QString::fromLocal8Bit("��������")<<QString::fromLocal8Bit("��������ƴ��")<<QString::fromLocal8Bit("��������")<<QString::fromLocal8Bit("ҩƷ����");
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
	
	if (strText==QString::fromLocal8Bit("ҽ����Ŀ"))
	{
		QStringList header;
		ui.tableWidget->setColumnCount(5); 
		header<<QString::fromLocal8Bit("��Ŀ����")<<QString::fromLocal8Bit("��Ŀ����")<<QString::fromLocal8Bit("ƴ��")<<QString::fromLocal8Bit("����������")<<QString::fromLocal8Bit("�Ƽ۵�λ")<<QString::fromLocal8Bit("�Ƽ۵�λ");
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

	if (strText==QString::fromLocal8Bit("��������"))
	{
		QStringList header;
		ui.tableWidget->setColumnCount(6); 
		header<<QString::fromLocal8Bit("���ϴ���")<<QString::fromLocal8Bit("��������")<<QString::fromLocal8Bit("����ƴ��")<<QString::fromLocal8Bit("���")<<QString::fromLocal8Bit("��װ")<<QString::fromLocal8Bit("�Ƽ۵�λ");
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
	QMessageBox box(QMessageBox::Warning,QString::fromLocal8Bit("��ʾ"),QString::fromLocal8Bit("����ɹ���"));
	box.setStandardButtons (QMessageBox::Ok);
	box.setButtonText (QMessageBox::Ok,QString::fromLocal8Bit("ȷ ��"));
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
		QString str = str.fromLocal8Bit("��ʾ");
		QString str2 = str.fromLocal8Bit("����ɹ�");
		QMessageBox box(QMessageBox::Warning,QString::fromLocal8Bit("��ʾ"),str2);
		box.setStandardButtons (QMessageBox::Ok);
		box.setButtonText (QMessageBox::Ok,QString::fromLocal8Bit("ȷ ��"));
		box.exec();
	}
	else{
		QString str = str.fromLocal8Bit("����");
		QString msg=str.fromLocal8Bit("����ʧ�ܣ�\n\r")+OdbcExcel::getError();
		QMessageBox box(QMessageBox::Warning,QString::fromLocal8Bit("����"),msg);
		box.setStandardButtons (QMessageBox::Ok);
		box.setButtonText (QMessageBox::Ok,QString::fromLocal8Bit("ȷ ��"));
		box.exec();
	}
}
void ruralcooperatecorrespondence::showTable(QTreeWidgetItem*item, int column)
{
	ui.tableWidget->clear();
	ui.tableWidget->setRowCount(0);
	QString strText = item->text(0);
	sql.connect2();
	if (strText==QString::fromLocal8Bit("ҩƷ"))
	{
		QStringList header;
		ui.tableWidget->setColumnCount(6); 
		header<<QString::fromLocal8Bit("ҩƷ���� ")<<QString::fromLocal8Bit("��ѧ����")<<QString::fromLocal8Bit("��������")<<QString::fromLocal8Bit("��������ƴ��")<<QString::fromLocal8Bit("��������")<<QString::fromLocal8Bit("ҩƷ����");
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
	if (strText==QString::fromLocal8Bit("ҽ����Ŀ"))
	{
		QStringList header;
		ui.tableWidget->setColumnCount(5); 
		header<<QString::fromLocal8Bit("��Ŀ����")<<QString::fromLocal8Bit("��Ŀ����")<<QString::fromLocal8Bit("��Ŀ����")<<QString::fromLocal8Bit("����������")<<QString::fromLocal8Bit("�Ƽ۵�λ")<<QString::fromLocal8Bit("�Ƽ۵�λ");
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
	if (strText==QString::fromLocal8Bit("��������"))
	{
		QStringList header;
		ui.tableWidget->setColumnCount(6); 
		header<<QString::fromLocal8Bit("���ϴ���")<<QString::fromLocal8Bit("��������")<<QString::fromLocal8Bit("����ƴ��")<<QString::fromLocal8Bit("���")<<QString::fromLocal8Bit("��װ")<<QString::fromLocal8Bit("�Ƽ۵�λ");
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
	QMessageBox box(QMessageBox::Warning,QString::fromLocal8Bit("����"),QString::fromLocal8Bit("ȷ���˳���"));
	box.setStandardButtons (QMessageBox::Ok|QMessageBox::Cancel);
	box.setButtonText (QMessageBox::Ok,QString::fromLocal8Bit("ȷ ��"));
	box.setButtonText (QMessageBox::Cancel,QString::fromLocal8Bit("ȡ ��"));
	if(box.exec()==QMessageBox::Ok)
	{
		this->close();
	}
}
void ruralcooperatecorrespondence::on_deleteButton_clicked()
{
	QMessageBox box(QMessageBox::Warning,QString::fromLocal8Bit("����"),QString::fromLocal8Bit("ȷ�ϴ����ݿ���ɾ�����У�"));
	box.setStandardButtons (QMessageBox::Ok|QMessageBox::Cancel);
	box.setButtonText (QMessageBox::Ok,QString::fromLocal8Bit("ȷ ��"));
	box.setButtonText (QMessageBox::Cancel,QString::fromLocal8Bit("ȡ ��"));
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
		if (strText==QString::fromLocal8Bit("ҩƷ"))
		{
			strsql = QString("delete from HIS.t_dic1 where mc1  = '"+strName+"'");
		}
		if (strText==QString::fromLocal8Bit("ҽ����Ŀ"))
		{
			strsql = QString("delete from HIS.t_dic2 where Mc = '"+strName+"'");
		}
		if (strText==QString::fromLocal8Bit("��������"))
		{
			strsql = QString("delete from HIS.t_dic3 where Mc = '"+strName+"'");	
		}
		if (query2.exec(strsql))
		{
			QMessageBox box(QMessageBox::Warning,QString::fromLocal8Bit("��ʾ"),QString::fromLocal8Bit("ɾ���ɹ���"));
			box.setStandardButtons (QMessageBox::Ok);
			box.setButtonText (QMessageBox::Ok,QString::fromLocal8Bit("ȷ ��"));
			box.exec();
		}
		sql.disconnect2();
	}
}
ruralcooperatecorrespondence::~ruralcooperatecorrespondence()
{

}
