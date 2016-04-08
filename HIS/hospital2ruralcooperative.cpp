#include "hospital2ruralcooperative.h"
#include <QtGui>
#include "connectsql.h"
extern ConnectSql sql;
Hospital2ruralcooperative::Hospital2ruralcooperative(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	connect(ui.listWidget,SIGNAL(itemClicked(QListWidgetItem*)),this,SLOT(showinfo(QListWidgetItem*)));
	initUI();
	ui.tableWidget->setStyleSheet("QTableWidget{border: 1px solid gray;	background-color: transparent;	selection-color: white;}");
	ui.tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section {background-color:white;color: black;padding-left: 4px;border: 1px solid #6c6c6c;};"
		"color: white;padding-left: 4px;border: 1px solid #6c6c6c;}"
		"QHeaderView::section:checked{background-color: white;color: black;}");	
}
void Hospital2ruralcooperative::initUI()
{
	QSqlQuery query(*sql.db);		
	query.exec("select * from zy_patientinfo  order by id ASC ");
	QStringList list;
	while(query.next())
	{
		QString str =query.value(1).toString();
		str+="-"+query.value(4).toString();

		list.append(str);
		//QListWidgetItem *elem1 = new QListWidgetItem(str, ui.listWidget);
		//elem1->setFlags(Qt::ItemIsEnabled|Qt::ItemIsUserCheckable);
		//elem1->setCheckState(Qt::Checked);
	}
	//ui.listWidget->clear();
	ui.listWidget->addItems(list);
	ui.radioButton->setChecked(true);
	ui.radioButton_3->setChecked(true);
	ui.radioButton_7->setChecked(true);
}
void Hospital2ruralcooperative::on_inputButton_clicked()
{
	/*QString strNo=ui.listWidget->item(0)->text();*/
	if (ui.radioButton_6->isChecked()==true)
	{

		QString strNo=ui.listWidget->currentItem()->text();
		QStringList list =strNo.split("-");
		strNo=list.at(0);
		writeindb(strNo);
		QMessageBox box(QMessageBox::Warning,QString::fromLocal8Bit("提示"),QString::fromLocal8Bit("保存成功！"));
		box.setStandardButtons (QMessageBox::Ok);
		box.setButtonText (QMessageBox::Ok,QString::fromLocal8Bit("确 定"));
		box.exec();
		if (ui.checkBox->isChecked())
		{
			int r = ui.listWidget->row(ui.listWidget->currentItem());  
			ui.listWidget->takeItem(r);  
			//ui.listWidget->takeItem(ui.listWidget->currentItem()->);
		}
	}
	if (ui.radioButton_7->isChecked()==true)
	{
		for (int i=0;i<ui.listWidget->count();i++)
		{
			QString strNo=ui.listWidget->item(i)->text();
			QStringList list =strNo.split("-");
			strNo=list.at(0);
			writeindb(strNo);
			
		}
		QMessageBox box(QMessageBox::Warning,QString::fromLocal8Bit("提示"),QString::fromLocal8Bit("保存成功！"));
		box.setStandardButtons (QMessageBox::Ok);
		box.setButtonText (QMessageBox::Ok,QString::fromLocal8Bit("确 定"));
		box.exec();
		if (ui.checkBox->isChecked())
		{
			ui.listWidget->clear();
		}
		
	}

}
void Hospital2ruralcooperative::on_refreshButton_clicked()
{
	ui.listWidget->clear();
	QSqlQuery query(*sql.db);	
	QStringList list;
	if (ui.radioButton_5->isChecked())
	{	
		query.exec("select * from zy_patientinfo where out2cooperativeflag = 0  order by id");
	}
	if (ui.radioButton_3->isChecked())
	{	
		query.exec("select * from zy_patientinfo  order by id");
	}
	if (ui.radioButton_4->isChecked())
	{		
		query.exec("select * from zy_patientinfo where out2cooperativeflag = 1  order by id");
	}
	while(query.next())
	{
		QString str =query.value(1).toString();
		str+="-"+query.value(4).toString();
		list.append(str);
	}
	ui.listWidget->addItems(list);
}
void Hospital2ruralcooperative::on_radioButton_6_clicked()
{

}
void Hospital2ruralcooperative::on_radioButton_7_clicked()
{

}
void Hospital2ruralcooperative::showinfo(QListWidgetItem *item)
{
	QString strNo=item->text();
	QStringList list =strNo.split("-");
	strNo=list.at(0);
	QSqlQuery query(*sql.db);		
	query.exec("select * from t_con1");
	int icount=0;
	while(query.next())
	{
		icount++;
	}
	int itotalcount=icount+1;
	QDateTime date = QDateTime::currentDateTime();

	query.exec("select * from zy_patientinfo where hospitalisationno= '"+strNo+"'");
	while(query.next())
	{
		ui.lineEdit->setText(query.value(1).toString());
		ui.lineEdit_6->setText(query.value(4).toString());
		ui.lineEdit_3->setText(query.value(2).toDateTime().toString("yyyy-MM-dd hh:mm:ss"));
		ui.lineEdit_8->setText(query.value(2).toDateTime().toString("yyyy-MM-dd hh:mm:ss"));

		ui.lineEdit_5->setText(query.value(10).toString());
		ui.lineEdit_16->setText(query.value(7).toString());
		ui.lineEdit_17->setText(query.value(20).toString());
		ui.lineEdit_11->setText(query.value(5).toString());
		ui.lineEdit_2->setText(query.value(12).toString());
		ui.lineEdit_15->setText(query.value(27).toString());
		ui.lineEdit_10->setText(query.value(3).toString());
		ui.lineEdit_4->setText(query.value(25).toString());
		ui.lineEdit_13->setText(query.value(23).toDateTime().toString("yyyy-MM-dd hh:mm:ss"));
	}
	ui.tableWidget->setRowCount(0);
	QSqlQuery query2(*sql.db);		
	query2.exec("select * from zy_chargedetail where hospitalisationno= '"+strNo+"'");
	int row = ui.tableWidget->rowCount();
	while(query2.next())
	{
		ui.tableWidget->insertRow(row);
		ui.tableWidget->setItem(row,0,new QTableWidgetItem(strNo));
		ui.tableWidget->setItem(row,1,new QTableWidgetItem(query2.value(1).toString()));
		ui.tableWidget->setItem(row,2,new QTableWidgetItem(query2.value(4).toString()));
		ui.tableWidget->setItem(row,3,new QTableWidgetItem(query2.value(5).toString()));
		ui.tableWidget->setItem(row,4,new QTableWidgetItem(query2.value(7).toString()));
		ui.tableWidget->setItem(row,5,new QTableWidgetItem(query2.value(6).toString()));
		ui.tableWidget->setItem(row,6,new QTableWidgetItem(query2.value(8).toString()));
		ui.tableWidget->setItem(row,7,new QTableWidgetItem(query2.value(9).toString()));
		query.exec("select * from sys_drugdictionary where name= '"+query2.value(4).toString()+"'");//如果农合码为空
		while(query.next())
		{
			if (query.value(23).toString()!="0")
			{
				ui.tableWidget->setItem(row,8,new QTableWidgetItem(QString::fromLocal8Bit("是")));
			}
			else
			{
				ui.tableWidget->setItem(row,8,new QTableWidgetItem(QString::fromLocal8Bit("否")));
			}
	
		}
		row++;
	}
	query.exec("select * from zy_pay where hospitalisationno= '"+strNo+"'");
	double totalpay=0;
	while(query.next())
	{
		totalpay +=query.value(8).toDouble();
	}
	ui.lineEdit_14->setText(QString::number(totalpay));
}
void Hospital2ruralcooperative::writeindb(QString strNo)
{
	sql.connect2();
	QSqlQuery query(*sql.db);	
	QSqlQuery query2(sql.db2);	
	query2.exec("select * from HIS.t_con1");
	int icount=0;
	while(query2.next())
	{
		icount++;
	}
	int itotalcount=icount+1;
	query2.prepare("delete from HIS.t_con1 where Zyh1 = '"+strNo+"'");
	query2.exec();
	query2.prepare("delete from HIS.t_con2 where Zyh = '"+strNo+"'");
	query2.exec();
	query.exec("select * from zy_patientinfo where hospitalisationno= '"+strNo+"'");
	while(query.next())
	{
		//QSqlQuery query2(*sql.db);
		query2.prepare("insert into HIS.t_con1 values (?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?)");
		//QString strsign = query.value(0).toString();
		//if (strsign.length()==1)
		//{
		//	strsign = "00000"+strsign;
		//}
		//if (strsign.length()==2)
		//{
		//	strsign = "0000"+strsign;
		//}
		//if (strsign.length()==3)
		//{
		//	strsign = "000"+strsign;
		//}
		//if (strsign.length()==4)
		//{
		//	strsign = "00"+strsign;
		//}
		//if (strsign.length()==5)
		//{
		//	strsign = "0"+strsign;
		//}
		query2.bindValue(0, query.value(27).toString());//标识住院号
		query2.bindValue(1, query.value(1).toString());
		query2.bindValue(2, query.value(25).toString());
		query2.bindValue(3, query.value(26).toDateTime());
		query2.bindValue(4, 5);
		query2.bindValue(5, query.value(4).toString());
		QString strgender = query.value(5).toString();
		if (strgender==QString::fromLocal8Bit("男"))
		{
			query2.bindValue(6, 1);
		}
		if (strgender==QString::fromLocal8Bit("女"))
		{
			query2.bindValue(6, 2);
		}

		query2.bindValue(7,  query.value(7).toString());

		query2.bindValue(8, NULL);//出生日期
		query2.bindValue(9,  query.value(2).toDateTime());

		QSqlQuery query3(*sql.db);
		query3.exec("select * from zy_pay where hospitalisationno= '"+strNo+"'");
		double totalpay=0;
		while(query3.next())
		{
			totalpay +=query3.value(8).toDouble();
		}
		query2.bindValue(10, totalpay);


		query2.bindValue(11, query.value(2).toDateTime());
		query2.bindValue(12, query.value(23).toDateTime());
		query2.bindValue(13, query.value(20).toString());

		query2.bindValue(14, 0);
		query2.bindValue(15, NULL);

		query2.bindValue(16, NULL);
		query2.bindValue(17, NULL);
		query2.bindValue(18, NULL);
		query2.bindValue(19, NULL);
		query2.bindValue(20, NULL);
		query2.bindValue(21, NULL);
		query2.bindValue(22, NULL);


		query2.bindValue(23, NULL);
		query2.bindValue(24, NULL);

		query2.bindValue(25, NULL);
		query2.bindValue(26, NULL);

		query2.bindValue(27, NULL);
		query2.bindValue(28, NULL);

		query2.bindValue(29, NULL);
		query2.bindValue(30, NULL);


		query2.bindValue(31, NULL);
		query2.bindValue(32,query.value(18).toString());

		query2.bindValue(33, NULL);

		query2.bindValue(34, query.value(17).toString());
		query2.bindValue(35, query.value(14).toString());
		query2.bindValue(36, query.value(13).toString());
		query2.bindValue(37, query.value(10).toString());

		if(query2.exec())
		{
			//QMessageBox::information(this,QString ::fromLocal8Bit("提示"),QString::fromLocal8Bit("保存成功！"));
		}
	}
	int count=0;
	query2.exec("select * from HIS.t_con2");
	while(query2.next())
	{
		count++;
	}
	query.exec("select * from zy_chargedetail where hospitalisationno= '"+strNo+"'");
	while(query.next())
	{
		/*QSqlQuery query2(*sql.db);*/
		count++;
		query2.prepare("insert into HIS.t_con2 values ( ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)");
		query2.bindValue(0, count);
		query2.bindValue(1, NULL);
		query2.bindValue(2, query.value(10).toString());
		query2.bindValue(3,query.value(9).toDateTime());
		query2.bindValue(4, "");

		int drugflag = query.value(11).toInt();
		query2.bindValue(5,drugflag);//医药分类
		query2.bindValue(6,NULL);
		query2.bindValue(8,NULL);
		QString strdrug =query.value(4).toString();
		if (drugflag==1)
		{
			QSqlQuery query3(*sql.db);	
			
			query3.exec("select * from sys_drugcorrespondence where yymc= '"+strdrug+"'");
			while (query3.next())
			{
				query2.bindValue(6, query3.value(1).toString());
				query2.bindValue(7, query3.value(3).toString());
				query2.bindValue(8, query3.value(2).toString());
				query2.bindValue(9, query3.value(4).toString());

				query2.bindValue(20, NULL);//医疗项目分类
			}
		}
		if (drugflag==2)
		{
			QSqlQuery query3(*sql.db);	
			QString strdrugtype,nhcode,nhname,hiscode,hisname;
			query3.exec("select * from sys_projectcorrespondence where yymc= '"+strdrug+"'");
			while (query3.next())
			{
				query2.bindValue(6, query3.value(1).toString());
				query2.bindValue(7, query3.value(3).toString());
				query2.bindValue(8, query3.value(2).toString());
				query2.bindValue(9, query3.value(4).toString());
				query2.bindValue(20, query3.value(7).toString());//医疗项目分类
			}
		}
		if (drugflag==3)
		{
			QSqlQuery query3(*sql.db);		
			QString strdrugtype,nhcode,nhname,hiscode,hisname;
			query3.exec("select * from sys_materialcorrespondence where yymc= '"+strdrug+"'");
			while (query3.next())
			{
				query2.bindValue(6, query3.value(1).toString());
				query2.bindValue(7, query3.value(3).toString());
				query2.bindValue(8, query3.value(2).toString());
				query2.bindValue(9, query3.value(4).toString());
				query2.bindValue(20, NULL);//医疗项目分类
			}
		}
		//
		//query2.bindValue(6, 6);
		//query2.bindValue(7, 7);
		//query2.bindValue(8, "");
		//query2.bindValue(9, query.value(4).toString());

		query2.bindValue(10, query.value(7).toDouble());
		query2.bindValue(11, query.value(6).toDouble());
		query2.bindValue(12, query.value(8).toDouble());//金额
		QSqlQuery query3(*sql.db);	
		query3.exec("select * from sys_drugdictionary where name= '"+query.value(4).toString()+"'");
		while (query3.next())
		{
			QString strdrugtype = query3.value(14).toString();
			if (strdrugtype==QString::fromLocal8Bit("西药"))
			{
				query2.bindValue(13, 1);
			}
			else if (strdrugtype==QString::fromLocal8Bit("中成药"))
			{
				query2.bindValue(13, 2);
			}
			else if (strdrugtype==QString::fromLocal8Bit("中草药"))
			{
				query2.bindValue(13, 3);
			}
		}
		query2.bindValue(14, 1);//药品属性
		query2.bindValue(15, NULL);
		query2.bindValue(16, NULL);
		query2.bindValue(18, NULL);

		query2.bindValue(19, NULL);
		////医疗项目分类
		query2.bindValue(21, NULL);
		query2.bindValue(22, NULL);
		query2.bindValue(23, NULL);
		query2.bindValue(24, NULL);
		query2.bindValue(25, NULL);
		query2.bindValue(26, NULL);
		query2.bindValue(27, NULL);
		query2.bindValue(28, NULL);
		query2.bindValue(29, NULL);
		query2.bindValue(30, NULL);
		query2.bindValue(31, NULL);
		query2.bindValue(32, NULL);
		if(query2.exec())
		{
			//QMessageBox::information(this,QString ::fromLocal8Bit("提示"),QString::fromLocal8Bit("保存成功！"));
		}
	}


	query.prepare("UPDATE zy_patientinfo SET out2cooperativeflag= ? WHERE hospitalisationno = '"+strNo+"'");
	query.bindValue(0,1);
	query.exec();
	sql.disconnect2();
}
Hospital2ruralcooperative::~Hospital2ruralcooperative()
{

}
