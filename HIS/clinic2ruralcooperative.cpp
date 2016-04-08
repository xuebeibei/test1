#include "clinic2ruralcooperative.h"
#include <QtGui>
#include "connectsql.h"
extern ConnectSql sql;
Clinic2ruralcooperative::Clinic2ruralcooperative(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	connect(ui.listWidget,SIGNAL(itemClicked(QListWidgetItem*)),this,SLOT(showinfo(QListWidgetItem*)));
	initUI();
}
void Clinic2ruralcooperative::initUI()
{
	ui.tableWidget->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
	ui.tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui.tableWidget->setStyleSheet("QTableWidget{border: 1px solid gray;	background-color: transparent;	selection-color: grey;}");
	ui.tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section {background-color:white;color: black;padding-left: 4px;border: 1px solid #6c6c6c;};"
		"color: white;padding-left: 4px;border: 1px solid #6c6c6c;}"
		"QHeaderView::section:checked{background-color: white;color: black;}");	

	QSqlQuery query(*sql.db);		
	query.exec("select * from mz_chargesheet order by id");
	QStringList list;
	while(query.next())
	{
		QString str =query.value(1).toString();
		str+="-"+query.value(5).toString();

		list.append(str);
	}
	ui.listWidget->addItems(list);
	ui.radioButton->setChecked(true);
	ui.radioButton_3->setChecked(true);
}
void Clinic2ruralcooperative::on_inputButton_clicked()
{
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
void Clinic2ruralcooperative::showinfo(QListWidgetItem *item)//
{
	QString strNo=item->text();
	QStringList list =strNo.split("-");
	strNo=list.at(0);
	QSqlQuery query(*sql.db);		
	query.exec("select * from mz_chargesheet where sheetno= '"+strNo+"'");
	while(query.next())
	{
		ui.lineEdit_6->setText(query.value(5).toString());
		ui.lineEdit_11->setText(query.value(6).toString());
		ui.lineEdit_16->setText(query.value(11).toString());
		ui.lineEdit_9->setText(query.value(2).toDateTime().toString("yyyy-MM-dd hh:mm:ss"));
		ui.lineEdit_2->setText(query.value(12).toString());
		ui.lineEdit_17->setText(query.value(15).toString());
		ui.lineEdit_4->setText(query.value(1).toString());
		int flag = query.value(16).toInt();
		if (flag==0)
		{
			ui.lineEdit_12->setText(QString::fromLocal8Bit("等待"));
		}

		/*	if (flag==1)
		{
		ui.lineEdit_12->setText(QString::fromLocal8Bit("已结"));
		}
		if (flag==2)
		{
		ui.lineEdit_12->setText(QString::fromLocal8Bit("错误记录"));
		}*/
		ui.tableWidget->setRowCount(0);
		QString strno = query.value(1).toString();
		QSqlQuery query2(*sql.db);		
		query2.exec("select * from mz_chargedetail where sheetno= '"+strno+"'");
		int row = ui.tableWidget->rowCount();
		while(query2.next())
		{
			ui.tableWidget->insertRow(row);
			ui.tableWidget->setItem(row,0,new QTableWidgetItem(strno));
			ui.tableWidget->setItem(row,1,new QTableWidgetItem(query2.value(4).toString()));
			ui.tableWidget->setItem(row,2,new QTableWidgetItem(query2.value(5).toString()));
			ui.tableWidget->setItem(row,3,new QTableWidgetItem(query2.value(6).toString()));
			ui.tableWidget->setItem(row,4,new QTableWidgetItem(query2.value(7).toString()));
			row++;
		}
	}
}
void Clinic2ruralcooperative::writeindb(QString strNo)
{
	sql.connect2();
	QDateTime date = QDateTime::currentDateTime();
	QSqlQuery query(*sql.db);
	QSqlQuery query2(sql.db2);
	QSqlQuery query3(sql.db2);
	QSqlQuery query4(*sql.db);
	QString strsheetNo;

	query2.prepare("delete from HIS.t_con3 where Mzlsh = '"+strNo+"'");
	query2.exec();
	query2.prepare("delete from HIS.t_con4 where Mzlsh = '"+strNo+"'");
	query2.exec();

	query.exec("select * from mz_chargesheet where sheetno= '"+strNo+"'");
	while(query.next())
	{
		strsheetNo=query.value(1).toString();
		QString strpatient=query.value(5).toString();
		QString strgender=query.value(6).toString();
		QString strID=query.value(11).toString();
		QString strsheetmaker=query.value(15).toString();
		query2.prepare("insert into HIS.t_con3 values (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)");
		query2.bindValue(0, strsheetNo);
		query2.bindValue(1,strsheetNo);
		query2.bindValue(2,query.value(12).toString());
		query2.bindValue(3, strpatient);
		if (strgender==QString::fromLocal8Bit("男"))
		{
			query2.bindValue(4, 1);
		}
		if (strgender==QString::fromLocal8Bit("女"))
		{
			query2.bindValue(4, 2);
		}

		query2.bindValue(5, strID);
		query2.bindValue(6,NULL);
		query2.bindValue(7, query.value(2).toDateTime());
		query2.bindValue(8, strsheetmaker);
		query2.bindValue(9, 1);
		query2.bindValue(10, NULL);
		query2.bindValue(11, NULL);
		query2.bindValue(12, NULL);
		query2.bindValue(13, NULL);
		query2.bindValue(14,NULL);
		query2.bindValue(15,NULL);
		query2.bindValue(16, NULL);
		query2.bindValue(17, NULL);
		query2.bindValue(18, NULL);
		query2.bindValue(19, NULL);
		query2.bindValue(20, NULL);
		query2.bindValue(21, NULL);
		query2.bindValue(22, NULL);
		if(query2.exec())
		{

//			QMessageBox::information(this,QString ::fromLocal8Bit("提示"),QString::fromLocal8Bit("保存成功！"));
		}

		int count=0;
		query2.exec("select * from HIS.t_con4");
		while(query2.next())
		{
			count++;
		}

		query4.exec("select * from mz_chargedetail where sheetno= '"+strsheetNo+"'");
		while(query4.next())
		{
			count++;
			query3.prepare("insert into HIS.t_con4 values (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)");
			query3.bindValue(0, count);
			query3.bindValue(1, NULL);
			query3.bindValue(2,query4.value(1).toString());
			query3.bindValue(3, query4.value(9).toDateTime());
			query3.bindValue(4, NULL);

			int drugflag = query.value(10).toInt();

			query3.bindValue(5,drugflag);//医药分类
			query3.bindValue(6,NULL);
			query3.bindValue(8,NULL);
			QString strdrug =query4.value(4).toString();
			if (drugflag==1)
			{
				QSqlQuery query5(*sql.db);	

				query5.exec("select * from sys_drugcorrespondence where yymc= '"+strdrug+"'");
				while (query5.next())
				{
					query3.bindValue(6, query5.value(1).toString());
					query3.bindValue(7, query5.value(3).toString());
					query3.bindValue(8, query5.value(2).toString());
					query3.bindValue(9, query5.value(4).toString());

					query3.bindValue(20, NULL);//医疗项目分类
				}
			}
			if (drugflag==2)
			{
				QSqlQuery query5(*sql.db);	
				QString strdrugtype,nhcode,nhname,hiscode,hisname;
				query5.exec("select * from sys_projectcorrespondence where yymc= '"+strdrug+"'");
				while (query4.next())
				{
					query3.bindValue(6, query5.value(1).toString());
					query3.bindValue(7, query5.value(3).toString());
					query3.bindValue(8, query5.value(2).toString());
					query3.bindValue(9, query5.value(4).toString());
					query3.bindValue(20, query5.value(7).toString());//医疗项目分类
				}
			}
			if (drugflag==3)
			{
				QSqlQuery query5(*sql.db);	
				QString strdrugtype,nhcode,nhname,hiscode,hisname;
				query5.exec("select * from sys_materialcorrespondence where yymc= '"+strdrug+"'");
				while (query4.next())
				{
					query3.bindValue(6, query5.value(1).toString());
					query3.bindValue(7, query5.value(3).toString());
					query3.bindValue(8, query5.value(2).toString());
					query3.bindValue(9, query5.value(4).toString());
					query3.bindValue(20, NULL);//医疗项目分类
				}
			}

			//query3.bindValue(6, 6);
			//query3.bindValue(7, 7);
			//query3.bindValue(8,"8");
			//query3.bindValue(9, "9");

			query3.bindValue(10, query4.value(6).toDouble());
			query3.bindValue(11,query4.value(7).toDouble());
			query3.bindValue(12, query4.value(8).toDouble());

			QSqlQuery query5(*sql.db);	
			query5.exec("select * from sys_drugdictionary where name= '"+query4.value(4).toString()+"'");
			while (query5.next())
			{
				QString strdrugtype = query5.value(14).toString();
				if (strdrugtype==QString::fromLocal8Bit("西药"))
				{
					query3.bindValue(13, 1);
				}
				else if (strdrugtype==QString::fromLocal8Bit("中成药"))
				{
					query3.bindValue(13, 2);
				}
				else if (strdrugtype==QString::fromLocal8Bit("中草药"))
				{
					query3.bindValue(13, 3);
				}
			}
			query3.bindValue(14,1);//药品属性
			query3.bindValue(15, NULL);
			query3.bindValue(16, NULL);
			query3.bindValue(17,NULL);
			query3.bindValue(18, NULL);
			query3.bindValue(19,NULL);
			query3.bindValue(20,NULL);
			//医疗项目的财务分类

			query3.bindValue(21,NULL);
			query3.bindValue(22, NULL);
			query3.bindValue(23,NULL);
			query3.bindValue(24, NULL);
			query3.bindValue(25, NULL);
			query3.bindValue(26,NULL);
			query3.bindValue(27, NULL);
			query3.bindValue(28, NULL);
			query3.bindValue(29,NULL);
			query3.bindValue(30, NULL);
			query3.bindValue(31, NULL);
			query3.exec();

		}
//		QMessageBox::information(this,QString ::fromLocal8Bit("提示"),QString::fromLocal8Bit("保存成功！"));
		query4.prepare("update mz_chargesheet set out2cooperativeflag= ? where sheetno= '"+strsheetNo+"'");
		query4.bindValue(0,1);
		query4.exec();
	}
	sql.disconnect2();
}
void Clinic2ruralcooperative::on_radioButton_6_clicked()
{

}
void Clinic2ruralcooperative::on_radioButton_7_clicked()
{

}
void Clinic2ruralcooperative::on_refreshButton_clicked()
{
	ui.listWidget->clear();

	QSqlQuery query(*sql.db);		
	if (ui.radioButton_5->isChecked())
	{
		query.exec("select * from mz_chargesheet where out2cooperativeflag = 0");
	}
	if (ui.radioButton_3->isChecked())
	{
		query.exec("select * from mz_chargesheet order by id");
	}
	if (ui.radioButton_4->isChecked())
	{
		query.exec("select * from mz_chargesheet where out2cooperativeflag = 1");
	}
	QStringList list;

	while(query.next())
	{
		QString str =query.value(1).toString();
		str+="-"+query.value(5).toString();
		list.append(str);
	}
	ui.listWidget->addItems(list);
}
Clinic2ruralcooperative::~Clinic2ruralcooperative()
{

}
