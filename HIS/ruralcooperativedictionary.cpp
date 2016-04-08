#include "ruralcooperativedictionary.h"
#include "ruralcooperativequery.h"
#include "connectsql.h"
#include "QThread"
extern ConnectSql sql;
QThread visuaThread;
Ruralcooperativedictionary::Ruralcooperativedictionary(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	initUI();
	dictionary = new Cooperativedictionary;
	connect(dictionary,SIGNAL(getno(QString)),this,SLOT(setNo(QString)));
}
void Ruralcooperativedictionary::initUI()
{
	ui.tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui.tableWidget->setStyleSheet("QTableWidget{border: 1px solid gray;	background-color: transparent;	selection-color: grey;}");
	ui.tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section {background-color:white;color: black;padding-left: 4px;border: 1px solid #6c6c6c;};"
		"color: white;padding-left: 4px;border: 1px solid #6c6c6c;}"
		"QHeaderView::section:checked{background-color: white;color: black;}");	

	ui.tableWidget_2->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui.tableWidget_2->setStyleSheet("QTableWidget{border: 1px solid gray;	background-color: transparent;	selection-color: grey;}");
	ui.tableWidget_2->horizontalHeader()->setStyleSheet("QHeaderView::section {background-color:white;color: black;padding-left: 4px;border: 1px solid #6c6c6c;};"
		"color: white;padding-left: 4px;border: 1px solid #6c6c6c;}"
		"QHeaderView::section:checked{background-color: white;color: black;}");	
	ui.tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);  
	ui.tableWidget_2->setSelectionBehavior(QAbstractItemView::SelectRows);  
	connect(ui.tableWidget,SIGNAL(cellDoubleClicked(int,int)),this,SLOT(getItem(int,int)));
	connect(ui.tableWidget_2,SIGNAL(cellDoubleClicked(int,int)),this,SLOT(getItem2(int,int)));
	ui.radioButton_14->setChecked(true);
	ui.radioButton->setChecked(true);

	QSettings setting("sqlserver.ini",QSettings::IniFormat);//读配置文件
	setting.beginGroup("config");
	ui.lineEdit_4->setText(setting.value("server").toString());
	ui.lineEdit_5->setText(setting.value("username").toString());
	ui.lineEdit_6->setText(setting.value("password").toString());
	ui.lineEdit_7->setText(setting.value("databasename").toString());
	setting.endGroup();
}
void Ruralcooperativedictionary::on_browseButton_clicked()
{
	ui.tableWidget->setRowCount(0);
	QSqlQuery query(*sql.db);		
	if (ui.comboBox->currentIndex()==0)
	{		
		query.exec("select * from sys_drugdictionary");
	}
	if (ui.comboBox->currentIndex()==1)
	{
		QString strCode = ui.lineEdit->text();
		if (strCode==NULL||strCode=="")
		{
			QMessageBox box(QMessageBox::Warning,QString::fromLocal8Bit("警告"),QString::fromLocal8Bit("输入药品简称"));
			box.setStandardButtons (QMessageBox::Ok);
			box.setButtonText (QMessageBox::Ok,QString::fromLocal8Bit("确 定"));
			box.exec();
			return;
		}	
		QString str =QString("select * from sys_drugdictionary where abbr like '%%1%'or name like'%%2%'  ").arg(strCode).arg(strCode);
		query.exec(str);
	}
	int row= 0;
	while(query.next())
	{	
		if(ui.radioButton_2->isChecked()==true)
		{
			if (query.value(23).toString()==NULL||query.value(23).toString()==""||query.value(23).toString()=="0")
			{
				continue;
			}
		}
		if(ui.radioButton_3->isChecked()==true)
		{
			if (query.value(23).toString()!=NULL&&query.value(23).toString()!=""&&query.value(23).toString()!="0")
			{
				continue;
			}
		}
		ui.tableWidget->insertRow(row);
		ui.tableWidget->setItem(row,0,new QTableWidgetItem(query.value(22).toString()));
		ui.tableWidget->setItem(row,1,new QTableWidgetItem(query.value(1).toString()));
		ui.tableWidget->setItem(row,2,new QTableWidgetItem(query.value(4).toString()));
		ui.tableWidget->setItem(row,3,new QTableWidgetItem(query.value(5).toString()));
		ui.tableWidget->setItem(row,4,new QTableWidgetItem(query.value(6).toString()));
		ui.tableWidget->setItem(row,5,new QTableWidgetItem(query.value(7).toString()));
		ui.tableWidget->setItem(row,6,new QTableWidgetItem(query.value(8).toString()));
		ui.tableWidget->setItem(row,7,new QTableWidgetItem(query.value(12).toString()));
		ui.tableWidget->setItem(row,8,new QTableWidgetItem(query.value(23).toString()));
		row++;
		QCoreApplication::processEvents();
	}
}
void Ruralcooperativedictionary::on_clearButton_clicked()
{
	ui.tableWidget->setRowCount(0);
}
void Ruralcooperativedictionary::on_checkButton_clicked()
{

}
void Ruralcooperativedictionary::on_browseButton_2_clicked()
{
	this->moveToThread(&visuaThread);
	visuaThread.start();
	ui.tableWidget_2->setRowCount(0);
	QStringList header;
	sql.connect2();
	QSqlQuery query(sql.db2);		
	int row= 0; 
	if (ui.radioButton_14->isChecked()==true)
	{
		header<<QString::fromLocal8Bit("药品代码")<<QString::fromLocal8Bit("化学名称")<<QString::fromLocal8Bit("常用名称")<<QString::fromLocal8Bit("常用名称拼音")<<QString::fromLocal8Bit("剂型名称")<<QString::fromLocal8Bit("药品属性");
		ui.tableWidget_2->setHorizontalHeaderLabels(header);
		if (ui.comboBox_2->currentIndex()==0)
		{		
			query.exec("select * from HIS.t_dic1");
		}
		if (ui.comboBox_2->currentIndex()==1)
		{
			QString strCode = ui.lineEdit_2->text();
			if (strCode==NULL||strCode=="")
			{
				QMessageBox box(QMessageBox::Warning,QString::fromLocal8Bit("警告"),QString::fromLocal8Bit("输入药品简称"));
				box.setStandardButtons (QMessageBox::Ok);
				box.setButtonText (QMessageBox::Ok,QString::fromLocal8Bit("确 定"));
				box.exec();
				return;
			}	
			QString str = QString("select * from HIS.t_dic1 where  py like '%%1%' or mc1 like '%%2%' ").arg(strCode).arg(strCode);
			
			query.exec(str);
		}
		while(query.next())
		{	
			ui.tableWidget_2->insertRow(row);
			ui.tableWidget_2->setItem(row,0,new QTableWidgetItem(query.value(0).toString()));
			ui.tableWidget_2->setItem(row,1,new QTableWidgetItem(query.value(1).toString()));
			ui.tableWidget_2->setItem(row,2,new QTableWidgetItem(query.value(2).toString()));
			ui.tableWidget_2->setItem(row,3,new QTableWidgetItem(query.value(3).toString()));
			ui.tableWidget_2->setItem(row,4,new QTableWidgetItem(query.value(4).toString()));
			ui.tableWidget_2->setItem(row,5,new QTableWidgetItem(query.value(5).toString()));
			row++;
		}
	}
	if (ui.radioButton_15->isChecked()==true)
	{
		header<<QString::fromLocal8Bit("项目代码")<<QString::fromLocal8Bit("项目名称")<<QString::fromLocal8Bit("项目拼音")<<QString::fromLocal8Bit("财务分类代码")<<QString::fromLocal8Bit("计价单位");
		ui.tableWidget_2->setHorizontalHeaderLabels(header);  
		

		if (ui.comboBox_2->currentIndex()==0)
		{		
			query.exec("select * from HIS.t_dic2");
		}
		if (ui.comboBox_2->currentIndex()==1)
		{
			QString strCode = ui.lineEdit_2->text();
			if (strCode==NULL||strCode=="")
			{
				QMessageBox box(QMessageBox::Warning,QString::fromLocal8Bit("警告"),QString::fromLocal8Bit("输入药品简称"));
				box.setStandardButtons (QMessageBox::Ok);
				box.setButtonText (QMessageBox::Ok,QString::fromLocal8Bit("确 定"));
				box.exec();
				return;
			}	
			QString str = QString("select * from HIS.t_dic2 where py like '%%1%'or Mc like '%%2%' ").arg(strCode).arg(strCode);
			query.exec(str);
		}

		while(query.next())
		{	
			ui.tableWidget_2->insertRow(row);
			ui.tableWidget_2->setItem(row,0,new QTableWidgetItem(query.value(0).toString()));
			ui.tableWidget_2->setItem(row,1,new QTableWidgetItem(query.value(1).toString()));
			ui.tableWidget_2->setItem(row,2,new QTableWidgetItem(query.value(2).toString()));
			ui.tableWidget_2->setItem(row,3,new QTableWidgetItem(query.value(3).toString()));
			ui.tableWidget_2->setItem(row,4,new QTableWidgetItem(query.value(4).toString()));
			row++;
		}
	}
	if (ui.radioButton_16->isChecked()==true)
	{
		header<<QString::fromLocal8Bit("材料代码")<<QString::fromLocal8Bit("材料名称")<<QString::fromLocal8Bit("项目拼音")<<QString::fromLocal8Bit("规格")<<QString::fromLocal8Bit("包装")<<QString::fromLocal8Bit("计价单位");
		ui.tableWidget_2->setHorizontalHeaderLabels(header);  

		if (ui.comboBox_2->currentIndex()==0)
		{		
			query.exec("select * from HIS.t_dic3");
		}
		if (ui.comboBox_2->currentIndex()==1)
		{
			QString strCode = ui.lineEdit_2->text();
			if (strCode==NULL||strCode=="")
			{
				QMessageBox box(QMessageBox::Warning,QString::fromLocal8Bit("警告"),QString::fromLocal8Bit("输入药品简称"));
				box.setStandardButtons (QMessageBox::Ok);
				box.setButtonText (QMessageBox::Ok,QString::fromLocal8Bit("确 定"));
				box.exec();
				return;
			}
			QString str = QString("select * from HIS.t_dic3 where py like '%%1%'or Mc like '%%2%' ").arg(strCode).arg(strCode);
			query.exec(str);
		}

		while(query.next())
		{	
			ui.tableWidget_2->insertRow(row);
			ui.tableWidget_2->setItem(row,0,new QTableWidgetItem(query.value(0).toString()));
			ui.tableWidget_2->setItem(row,1,new QTableWidgetItem(query.value(1).toString()));
			ui.tableWidget_2->setItem(row,2,new QTableWidgetItem(query.value(2).toString()));
			ui.tableWidget_2->setItem(row,3,new QTableWidgetItem(query.value(3).toString()));
			ui.tableWidget_2->setItem(row,4,new QTableWidgetItem(query.value(4).toString()));
			ui.tableWidget_2->setItem(row,5,new QTableWidgetItem(query.value(5).toString()));
			row++;
		}
	}
	sql.disconnect2();
}
void Ruralcooperativedictionary::on_clearButton_2_clicked()
{
	ui.tableWidget_2->setRowCount(0);
}
void Ruralcooperativedictionary::getItem(int row,int column)
{
	if (strNo=="")
	{
		QMessageBox box(QMessageBox::Warning,QString::fromLocal8Bit("提示"),QString::fromLocal8Bit("请先获取农合码！"));
		box.setStandardButtons (QMessageBox::Ok);
		box.setButtonText (QMessageBox::Ok,QString::fromLocal8Bit("确 定"));
		box.exec();
		return;
	}
	QMessageBox box(QMessageBox::Warning,QString::fromLocal8Bit("警告"),QString::fromLocal8Bit("是否生成农合码？"));
	box.setStandardButtons (QMessageBox::Ok|QMessageBox::Cancel);
	box.setButtonText (QMessageBox::Ok,QString::fromLocal8Bit("确 定"));
	box.setButtonText (QMessageBox::Cancel,QString::fromLocal8Bit("取 消"));
	if(box.exec()==QMessageBox::Ok)
	{
		QString strDrugName = ui.tableWidget->item(row,1)->text();
		ui.tableWidget->setItem(row,8,new QTableWidgetItem(strNo));
		QSqlQuery query(*sql.db);	
		query.prepare("UPDATE sys_drugdictionary SET cooperativecode= ? WHERE name = '"+strDrugName+"'");
		query.bindValue(0,strNo);
		if(query.exec())
		{
			QMessageBox box(QMessageBox::Warning,QString::fromLocal8Bit("提示"),QString::fromLocal8Bit("已生成！"));
			box.setStandardButtons (QMessageBox::Ok);
			box.setButtonText (QMessageBox::Ok,QString::fromLocal8Bit("确 定"));
			box.exec();
		}
		query.prepare("UPDATE sys_drugdictionary SET cooperativecode= ? WHERE name = '"+strDrugName+"'");
		query.bindValue(0,strNo);

		QString strtype;
		query.prepare("select * from sys_drugdictionary  WHERE name = '"+strDrugName+"'");
		query.exec();
		while(query.next())
		{
			strtype = query.value(14).toString();
		}
		int row2=ui.tableWidget_2->currentRow();
		if (strtype == QString::fromLocal8Bit("西药")||strtype == QString::fromLocal8Bit("中成药")||strtype ==QString::fromLocal8Bit("中草药"))
		{
			//写入对应关系表 先判断是否存在，如果存在替换，不存在加一行
			query.prepare("select * from sys_drugcorrespondence  WHERE yymc = '"+strDrugName+"'");
			query.exec();
			if(query.next())
			{
				query.prepare("UPDATE sys_drugcorrespondence SET nhbm= ? WHERE yymc = '"+strDrugName+"'");
				query.bindValue(0,strNo);
				query.exec();
			}
			else
			{
				int count =0;
				query.exec("select* from sys_drugcorrespondence");
				while(query.next())
				{
					count++;
				}
				count++;
				query.prepare("INSERT INTO sys_drugcorrespondence VALUES (?,?, ?, ?, ?, ?, ?, ?, ?, ?)");
				query.bindValue(0,count);
				query.bindValue(1,strNo);
				query.bindValue(2,ui.tableWidget_2->item(row2,1)->text());
				query.bindValue(3, ui.tableWidget->item(row,0)->text());
				query.bindValue(4, ui.tableWidget->item(row,1)->text());
				query.bindValue(5, ui.tableWidget_2->item(row2,4)->text());
				query.bindValue(6,ui.tableWidget->item(row,4)->text());
				query.bindValue(7,ui.tableWidget->item(row,2)->text());
				query.bindValue(8,ui.tableWidget->item(row,3)->text());
				query.bindValue(9,NULL);
				query.exec();
			}
		}
		if (strtype == QString::fromLocal8Bit("医疗项目"))
		{
			query.prepare("select * from sys_projectcorrespondence  WHERE yymc = '"+strDrugName+"'");
			query.exec();
			if(query.next())
			{
				query.prepare("UPDATE sys_projectcorrespondence SET nhbm= ? WHERE yymc = '"+strDrugName+"'");
				query.bindValue(0,strNo);
				query.exec();
			}
			else
			{
				int count =0;
				query.exec("select *from sys_projectcorrespondence");
				while(query.next())
				{
					count++;
				}
				count++;
				query.prepare("INSERT INTO sys_projectcorrespondence VALUES (?,?, ?, ?, ?, ?, ?, ?)");
				query.bindValue(0,count);
				query.bindValue(1,strNo);
				query.bindValue(2,ui.tableWidget_2->item(row2,1)->text());
				query.bindValue(3, ui.tableWidget->item(row,0)->text());
				query.bindValue(4, ui.tableWidget->item(row,1)->text());
				query.bindValue(5, ui.tableWidget->item(row,4)->text());//单位
				query.bindValue(6,ui.tableWidget_2->item(row2,3)->text());
				query.bindValue(7,ui.tableWidget_2->item(row2,4)->text());
				query.exec();
			}
		}
		if (strtype == QString::fromLocal8Bit("卫生材料"))
		{
			query.prepare("select * from sys_materialcorrespondence  WHERE yymc = '"+strDrugName+"'");
			query.exec();
			if(query.next())
			{
				query.prepare("UPDATE sys_materialcorrespondence SET nhbm= ? WHERE yymc = '"+strDrugName+"'");
				query.bindValue(0,strNo);
				query.exec();
			}
			else
			{
				int count =0;
				query.exec("select *from sys_materialcorrespondence");
				while(query.next())
				{
					count++;
				}
				count++;
				query.prepare("INSERT INTO sys_materialcorrespondence VALUES (?,?, ?, ?, ?, ?, ?, ?, ?)");
				query.bindValue(0,count);
				query.bindValue(1,strNo);
				query.bindValue(2,ui.tableWidget_2->item(row2,1)->text());
				query.bindValue(3, ui.tableWidget->item(row,0)->text());
				query.bindValue(4, ui.tableWidget->item(row,1)->text());
				query.bindValue(5, ui.tableWidget->item(row,4)->text());//单位

				query.bindValue(6,ui.tableWidget_2->item(row2,4)->text());
				query.bindValue(7,ui.tableWidget_2->item(row2,3)->text());
				query.bindValue(8,NULL);
				query.exec();
			}
		}
	}
}
void Ruralcooperativedictionary::getItem2(int row,int column)
{

	dictionary->setWindowModality(Qt::WindowModal);
	dictionary->initUI(ui.tableWidget_2->item(row,0)->text(),ui.tableWidget_2->item(row,1)->text());

	dictionary->show();
}
void Ruralcooperativedictionary::setNo(QString strno)
{
	strNo = strno;
}
void Ruralcooperativedictionary::on_checkButton_2_clicked()
{

}
void Ruralcooperativedictionary::on_queryButton_clicked()
{
	Ruralcooperativequery* query = new Ruralcooperativequery;
	query->setWindowModality(Qt::WindowModal);
	query->show();
}
void Ruralcooperativedictionary::on_outButton_clicked()
{

}
void Ruralcooperativedictionary::on_saveButton_clicked()
{
	QSettings settings("sqlserver.ini", QSettings::IniFormat);
    settings.beginGroup("config");
    settings.setValue("server", ui.lineEdit_4->text().trimmed());
    settings.setValue("username", ui.lineEdit_5->text().trimmed());
	settings.setValue("password", ui.lineEdit_6->text().trimmed());
	settings.setValue("databasename", ui.lineEdit_7->text().trimmed());
    settings.endGroup();

}
Ruralcooperativedictionary::~Ruralcooperativedictionary()
{

}
