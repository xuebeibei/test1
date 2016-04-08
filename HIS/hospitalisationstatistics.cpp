#include "hospitalisationstatistics.h"
#include "hospitalisationregistry.h"
#include "hospitalisationpay.h"
#include "hospitalisationcharge.h"
#include "connectsql.h"
#include "capital.h"
extern ConnectSql sql;
HospitalisationStatistics::HospitalisationStatistics(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	initUI();
	setStyleSheet("QTableWidget{border: 1px solid gray;	background-color: transparent;	selection-color: grey;}");
	ui.tableView->setStyleSheet("border: 1px solid gray;	background-color: transparent;	selection-color: grey;");
	ui.tableView->horizontalHeader()->setStyleSheet("QHeaderView::section {background-color:white;color: black;padding-left: 4px;border: 1px solid #6c6c6c;};"
		"color: white;padding-left: 4px;border: 1px solid #6c6c6c;}"
		"QHeaderView::section:checked{background-color: white;color: black;}");	
	ui.tableWidget_6->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
	ui.tableWidget_6->horizontalHeader()->setStyleSheet("QHeaderView::section {background-color:white;color: black;padding-left: 4px;border: 1px solid #6c6c6c;};"
		"color: white;padding-left: 4px;border: 1px solid #6c6c6c;}"
		"QHeaderView::section:checked{background-color: white;color: black;}");	
	ui.tableWidget_5->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
	ui.tableWidget_5->horizontalHeader()->setStyleSheet("QHeaderView::section {background-color:white;color: black;padding-left: 4px;border: 1px solid #6c6c6c;};"
		"color: white;padding-left: 4px;border: 1px solid #6c6c6c;}"
		"QHeaderView::section:checked{background-color: white;color: black;}");	
	ui.paytableView->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
	ui.paytableView->horizontalHeader()->setStyleSheet("QHeaderView::section {background-color:white;color: black;padding-left: 4px;border: 1px solid #6c6c6c;};"
		"color: white;padding-left: 4px;border: 1px solid #6c6c6c;}"
		"QHeaderView::section:checked{background-color: white;color: black;}");	
	ui.chargetableView->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
	ui.chargetableView->horizontalHeader()->setStyleSheet("QHeaderView::section {background-color:white;color: black;padding-left: 4px;border: 1px solid #6c6c6c;};"
		"color: white;padding-left: 4px;border: 1px solid #6c6c6c;}"
		"QHeaderView::section:checked{background-color: white;color: black;}");	
	ui.balancetableWidget->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
	ui.balancetableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section {background-color:white;color: black;padding-left: 4px;border: 1px solid #6c6c6c;};"
		"color: white;padding-left: 4px;border: 1px solid #6c6c6c;}"
		"QHeaderView::section:checked{background-color: white;color: black;}");	
	ui.billtableWidget->horizontalHeader()->setResizeMode(QHeaderView::Stretch);

	ui.billtableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section {background-color:white;color: black;padding-left: 4px;border: 1px solid #6c6c6c;};"
		"color: white;padding-left: 4px;border: 1px solid #6c6c6c;}"
		"QHeaderView::section:checked{background-color: white;color: black;}");	

	ui.tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);  
	ui.tableView->setSelectionBehavior(QAbstractItemView::SelectRows); 
	connect(ui.tableView,SIGNAL(doubleClicked(const QModelIndex &)),this,SLOT(edit(const QModelIndex &)));
	ui.paytableView->setEditTriggers(QAbstractItemView::NoEditTriggers);  
	ui.paytableView->setSelectionBehavior(QAbstractItemView::SelectRows); 
	connect(ui.paytableView,SIGNAL(doubleClicked(const QModelIndex &)),this,SLOT(payedit(const QModelIndex &)));
	ui.chargetableView->setEditTriggers(QAbstractItemView::NoEditTriggers);  
	ui.chargetableView->setSelectionBehavior(QAbstractItemView::SelectRows); 
	connect(ui.chargetableView,SIGNAL(doubleClicked(const QModelIndex &)),this,SLOT(getItem(const QModelIndex &)));
	connect(ui.hospitalnoEdit, SIGNAL(textChanged(const QString &)), this, SLOT(showinfo(const QString &)));
	connect(ui.lineEdit_10, SIGNAL(textChanged(const QString &)), this, SLOT(showinfo2(const QString &)));
	connect(ui.lineEdit_13, SIGNAL(textChanged(const QString &)), this, SLOT(showinfo3(const QString &)));
	connect(ui.lineEdit_4, SIGNAL(textChanged(const QString &)), this, SLOT(showinfo4(const QString &)));
	connect(ui.lineEdit_6, SIGNAL(textChanged(const QString &)), this, SLOT(showinfo5(const QString &)));
}
void HospitalisationStatistics::initUI()
{
	QSqlQuery query(*sql.db);		
	query.exec("select * from zy_patientinfo ORDER BY id ASC ");
	QStringList list;
	while(query.next())
	{
		QString str = query.value(1).toString();
		list.append(str);
	}
	//ui.hospitalisationNocomboBox->addItems(list);
	//ui.comboBox_9->addItems(list);

	QDateTime current_date_time = QDateTime::currentDateTime();

	ui.dateTimeEdit->setDateTime(current_date_time);
	QTime time= QTime::fromString("00:00:00", "hh:mm:ss");
	ui.dateTimeEdit->setTime(time);
	ui.dateTimeEdit_2->setDateTime(current_date_time);
	time= QTime::fromString("23:59:59", "hh:mm:ss");
	ui.dateTimeEdit_2->setTime(time);


	ui.dateTimeEdit_5->setDateTime(current_date_time);
	time= QTime::fromString("00:00:00", "hh:mm:ss");
	ui.dateTimeEdit_5->setTime(time);
	ui.dateTimeEdit_6->setDateTime(current_date_time);
	time= QTime::fromString("23:59:59", "hh:mm:ss");
	ui.dateTimeEdit_6->setTime(time);

	ui.dateTimeEdit_7->setDateTime(current_date_time);
	time= QTime::fromString("00:00:00", "hh:mm:ss");
	ui.dateTimeEdit_7->setTime(time);
	ui.dateTimeEdit_8->setDateTime(current_date_time);
	time= QTime::fromString("23:59:59", "hh:mm:ss");
	ui.dateTimeEdit_8->setTime(time);

	ui.dateTimeEdit_11->setDateTime(current_date_time);
	time= QTime::fromString("00:00:00", "hh:mm:ss");
	ui.dateTimeEdit_11->setTime(time);
	ui.dateTimeEdit_12->setDateTime(current_date_time);
	time= QTime::fromString("23:59:59", "hh:mm:ss");
	ui.dateTimeEdit_12->setTime(time);

	//ui.dateTimeEdit_11->setDateTime(current_date_time);
	//time= QTime::fromString("00:00:00", "hh:mm:ss");
	//ui.dateTimeEdit_11->setTime(time);
	//ui.dateTimeEdit_12->setDateTime(current_date_time);
	//time= QTime::fromString("23:59:59", "hh:mm:ss");
	//ui.dateTimeEdit_12->setTime(time);

	ui.dateTimeEdit_13->setDateTime(current_date_time);
	time= QTime::fromString("00:00:00", "hh:mm:ss");
	ui.dateTimeEdit_13->setTime(time);
	ui.dateTimeEdit_14->setDateTime(current_date_time);
	time= QTime::fromString("23:59:59", "hh:mm:ss");
	ui.dateTimeEdit_14->setTime(time);


	ui.dateTimeEdit_17->setDateTime(current_date_time);
	time= QTime::fromString("00:00:00", "hh:mm:ss");
	ui.dateTimeEdit_17->setTime(time);
	ui.dateTimeEdit_18->setDateTime(current_date_time);
	time= QTime::fromString("23:59:59", "hh:mm:ss");
	ui.dateTimeEdit_18->setTime(time);
}
#pragma region 住院查询
void HospitalisationStatistics::on_radioButton_clicked()
{
	if(!ui.radioButton->isChecked())
	{
		ui.dateTimeEdit->setEnabled(false);
		ui.dateTimeEdit_2->setEnabled(false);
	}
	if(ui.radioButton->isChecked())
	{
		ui.dateTimeEdit->setEnabled(true);
		ui.dateTimeEdit_2->setEnabled(true);
	}

}
void HospitalisationStatistics:: on_hospitalqueryButton_clicked()
{
	QString startDate = ui.dateTimeEdit->dateTime().toString("yyyy-MM-dd hh:mm:ss");
	QString endDate = ui.dateTimeEdit_2->dateTime().toString("yyyy-MM-dd hh:mm:ss");

	QString strNo = ui.hospitalnoEdit->text();
	QSqlQueryModel *model=new QSqlQueryModel();	
	QString strsql;
	if (ui.comboBox->currentIndex()==0)
	{
		if (strNo!=""&&strNo!=NULL )
		{
			if(ui.radioButton->isChecked())
			{
				strsql="select * from zy_patientinfo where registrydate between  TIMESTAMP '"+startDate+"' and TIMESTAMP '"+endDate+"' and hospitalisationno ='"+strNo+"' order by id";
			}
			else
			{
				strsql="select * from zy_patientinfo where hospitalisationno ='"+strNo+"'order by id";
			}
		}
		else 
		{
			if(ui.radioButton->isChecked())
			{
				strsql="select * from zy_patientinfo where registrydate between  TIMESTAMP '"+startDate+"' and TIMESTAMP '"+endDate+"'order by id";
			}
			else
			{
				strsql="select * from zy_patientinfo order by id";
			}
		}
	}
	if (ui.comboBox->currentIndex()==1)
	{
		QString strstatus = QString::fromLocal8Bit("住院中");
		if (strNo!=""&&strNo!=NULL )
		{
			if(ui.radioButton->isChecked())
			{
				strsql="select * from zy_patientinfo where registrydate between  TIMESTAMP '"+startDate+"' and TIMESTAMP '"+endDate+"' and hospitalisationno ='"+strNo+"' and hospitalizationstatus ='"+strstatus+"'order by id";
			}
			else
			{
				strsql="select * from zy_patientinfo where hospitalisationno ='"+strNo+"'and hospitalizationstatus ='"+strstatus+"'order by id";
			}
		}
		else 
		{
			if(ui.radioButton->isChecked())
			{
				strsql="select * from zy_patientinfo where registrydate between  TIMESTAMP '"+startDate+"' and TIMESTAMP '"+endDate+"'and hospitalizationstatus ='"+strstatus+"'order by id";
			}
			else
			{
				strsql="select * from zy_patientinfo where hospitalizationstatus ='"+strstatus+"'order by id";
			}
		}
	}
	if (ui.comboBox->currentIndex()==2)
	{
		QString strstatus = QString::fromLocal8Bit("出院-已结算");
		if (strNo!=""&&strNo!=NULL )
		{
			if(ui.radioButton->isChecked())
			{
				strsql="select * from zy_patientinfo where registrydate between  TIMESTAMP '"+startDate+"' and TIMESTAMP '"+endDate+"' and hospitalisationno ='"+strNo+"' and hospitalizationstatus ='"+strstatus+"'order by id";
			}
			else
			{
				strsql="select * from zy_patientinfo where hospitalisationno ='"+strNo+"'and hospitalizationstatus ='"+strstatus+"'order by id";
			}
		}
		else 
		{
			if(ui.radioButton->isChecked())
			{
				strsql="select * from zy_patientinfo where registrydate between  TIMESTAMP '"+startDate+"' and TIMESTAMP '"+endDate+"'and hospitalizationstatus ='"+strstatus+"'order by id";
			}
			else
			{
				strsql="select * from zy_patientinfo where hospitalizationstatus ='"+strstatus+"'order by id";
			}
		}
	}
	model->setQuery(strsql,*sql.db);
	model->setHeaderData(0,Qt::Horizontal,tr("ID"));
	model->setHeaderData(1,Qt::Horizontal,QString::fromLocal8Bit("住院号"));
	model->setHeaderData(2,Qt::Horizontal,QString::fromLocal8Bit("登记日期"));
	model->setHeaderData(3,Qt::Horizontal,QString::fromLocal8Bit("病历号"));
	model->setHeaderData(4,Qt::Horizontal,QString::fromLocal8Bit("姓名"));
	model->setHeaderData(5,Qt::Horizontal,QString::fromLocal8Bit("性别"));
	model->setHeaderData(6,Qt::Horizontal,QString::fromLocal8Bit("年龄"));
	model->setHeaderData(7,Qt::Horizontal,QString::fromLocal8Bit("身份证号"));
	model->setHeaderData(8,Qt::Horizontal,QString::fromLocal8Bit("地址"));
	model->setHeaderData(9,Qt::Horizontal,QString::fromLocal8Bit("联系人"));
	model->setHeaderData(10,Qt::Horizontal,QString::fromLocal8Bit("联系电话"));
	model->setHeaderData(11,Qt::Horizontal,QString::fromLocal8Bit("参合证号"));
	model->setHeaderData(12,Qt::Horizontal,QString::fromLocal8Bit("合作医疗证号"));
	model->setHeaderData(13,Qt::Horizontal,QString::fromLocal8Bit("住院科室"));
	model->setHeaderData(14,Qt::Horizontal,QString::fromLocal8Bit("主治医生"));
	model->setHeaderData(15,Qt::Horizontal,QString::fromLocal8Bit("费用类型"));
	model->setHeaderData(16,Qt::Horizontal,QString::fromLocal8Bit("护理级别"));
	model->setHeaderData(17,Qt::Horizontal,QString::fromLocal8Bit("床位"));
	model->setHeaderData(18,Qt::Horizontal,QString::fromLocal8Bit("诊断结果"));
	model->setHeaderData(19,Qt::Horizontal,QString::fromLocal8Bit("最小余额"));
	model->setHeaderData(20,Qt::Horizontal,QString::fromLocal8Bit("制单"));
	model->setHeaderData(21,Qt::Horizontal,QString::fromLocal8Bit("审核"));
	model->setHeaderData(22,Qt::Horizontal,QString::fromLocal8Bit("状态"));
	model->setHeaderData(23,Qt::Horizontal,QString::fromLocal8Bit("出院日期"));
	model->setHeaderData(24,Qt::Horizontal,QString::fromLocal8Bit("导出农合标识"));
	model->setHeaderData(25,Qt::Horizontal,QString::fromLocal8Bit("发票号"));
	model->setHeaderData(26,Qt::Horizontal,QString::fromLocal8Bit("开票时间"));
	model->setHeaderData(27,Qt::Horizontal,QString::fromLocal8Bit("标志住院号"));
	ui.tableView->setModel(model);
}
void HospitalisationStatistics:: on_hospitalclearButton_clicked()
{
	QSqlQueryModel *model=new QSqlQueryModel();	
	ui.tableView->setModel(model);
}

void HospitalisationStatistics::edit(const QModelIndex &index)
{
	HospitalisationRegistry*registry = new HospitalisationRegistry();
	registry->showNormal();
	QAbstractItemModel *model = ui.tableView->model();
	QString strNo=model->data(model->index(index.row(),1)).toString();
	registry->edit(strNo);
}
void HospitalisationStatistics::showinfo(const QString &text)
{
	ui.lineEdit_3->clear();
	ui.lineEdit_2->clear();
	ui.lineEdit->clear();
	QString strsql= "select * from zy_patientinfo where hospitalisationno='"+text+"'";
	QSqlQuery query(*sql.db);	
	query.exec(strsql);
	while(query.next())
	{
		ui.lineEdit_3->setText(query.value(4).toString());
		ui.lineEdit_2->setText(query.value(14).toString());
		ui.lineEdit->setText(query.value(13).toString());	
	}
}
#pragma endregion 住院查询
#pragma region 日结查询
void HospitalisationStatistics::on_radioButton_4_clicked()
{
	if(!ui.radioButton_4->isChecked())
	{
		ui.dateTimeEdit_7->setEnabled(false);
		ui.dateTimeEdit_8->setEnabled(false);
	}
	if(ui.radioButton_4->isChecked())
	{
		ui.dateTimeEdit_7->setEnabled(true);
		ui.dateTimeEdit_8->setEnabled(true);
	}

}
void HospitalisationStatistics::on_clearButton_4_clicked()
{
	ui.tableWidget_6->setRowCount(0);
}
void HospitalisationStatistics::on_dailyqueryButton_clicked()
{
	ui.tableWidget_6->setRowCount(0);
	QString startDate = ui.dateTimeEdit_7->dateTime().toString("yyyy-MM-dd hh:mm:ss");
	QString endDate = ui.dateTimeEdit_8->dateTime().toString("yyyy-MM-dd hh:mm:ss");
	QString strNo = ui.lineEdit_12->text();
	QSqlQuery query(*sql.db);		
	if (strNo!=""&&strNo!=NULL )
	{
		if(ui.radioButton_4->isChecked())
		{
			query.exec("select * from zy_dailysummary where makedate between  TIMESTAMP '"+startDate+"' and TIMESTAMP '"+endDate+"' and sheetno = '"+strNo+"' order by id");
		}
		if(!ui.radioButton_4->isChecked())
		{
			query.exec("select * from zy_dailysummary where sheetno = '"+strNo+"' order by id");
		}
	}
	else
	{
		if(ui.radioButton_4->isChecked())
		{
			query.exec("select * from zy_dailysummary where makedate between  TIMESTAMP '"+startDate+"' and TIMESTAMP '"+endDate+"' order by id");
		}
		if(!ui.radioButton_4->isChecked())
		{
			query.exec("select * from zy_dailysummary order by id");
		}
	}
	int row= 0;
	while(query.next())
	{	
		ui.tableWidget_6->insertRow(row);
		ui.tableWidget_6->setItem(row,0,new QTableWidgetItem(query.value(1).toString()));
		ui.tableWidget_6->setItem(row,1,new QTableWidgetItem(query.value(2).toDateTime().toString("yyyy-MM-dd hh:mm:ss")));
		ui.tableWidget_6->setItem(row,2,new QTableWidgetItem(query.value(7).toString()));
		ui.tableWidget_6->setItem(row,3,new QTableWidgetItem(query.value(11).toString()));
		row++;
	}
}
#pragma endregion 日结查询
#pragma region 交款查询
void HospitalisationStatistics::on_radioButton_2_clicked()
{
	if(!ui.radioButton_2->isChecked())
	{
		ui.dateTimeEdit_5->setEnabled(false);
		ui.dateTimeEdit_6->setEnabled(false);
	}
	if(ui.radioButton_2->isChecked())
	{
		ui.dateTimeEdit_5->setEnabled(true);
		ui.dateTimeEdit_6->setEnabled(true);
	}

}
void HospitalisationStatistics::on_payqueryButton_clicked()
{
	QSqlQueryModel *model=new QSqlQueryModel();	
	QString startDate = ui.dateTimeEdit_5->dateTime().toString("yyyy-MM-dd hh:mm:ss");
	QString endDate = ui.dateTimeEdit_6->dateTime().toString("yyyy-MM-dd hh:mm:ss");
	QString strsql;
	QString strNo = ui.lineEdit_10->text();
	if (ui.comboBox_2->currentIndex()==0)
	{
		if (strNo!=""&&strNo!=NULL )
		{
			if(ui.radioButton_2->isChecked())
			{
				strsql="select a.id,a.sheetno,a.date ,a.hospitalisationno,a.patientname,a.registrydate,a.bedno,a.paymentmethod,a.amount,a.remark from  zy_pay  a,zy_patientinfo b where a.date  between  TIMESTAMP '"+startDate+"' and TIMESTAMP '"+endDate+"' and a.hospitalisationno = '"+strNo+"' and b.hospitalisationno ='"+strNo+"' order by a.id";
				//strsql="select * from  zy_pay  a,zy_patientinfo b where date between  TIMESTAMP '"+startDate+"' and TIMESTAMP '"+endDate+"' and hospitalisationno ='"+strNo+"' order by id";
			}
			else
			{
				strsql="select * from zy_pay where hospitalisationno ='"+strNo+"'order by id";
			}
		}
		else 
		{
			if(ui.radioButton_2->isChecked())
			{
				strsql="select * from zy_pay where date  between  TIMESTAMP '"+startDate+"' and TIMESTAMP '"+endDate+"' order by id";
			}
			else
			{
				strsql="select * from zy_pay order by id";
			}
		}
	}
	if (ui.comboBox_2->currentIndex()==1)
	{
		QString strstatus = QString::fromLocal8Bit("住院中");
		if (strNo!=""&&strNo!=NULL )
		{
			if(ui.radioButton_2->isChecked())
			{
				strsql="select a.id,a.sheetno,a.date ,a.hospitalisationno,a.patientname,a.registrydate,a.bedno,a.paymentmethod,a.amount,a.remark from  zy_pay  a,zy_patientinfo b where a.date  between  TIMESTAMP '"+startDate+"' and TIMESTAMP '"+endDate+"' and a.hospitalisationno = '"+strNo+"' and b.hospitalisationno ='"+strNo+"' and  b.hospitalizationstatus ='"+strstatus+"'order by a.id";
			}
			else
			{
				strsql="select a.id,a.sheetno,a.date ,a.hospitalisationno,a.patientname,a.registrydate,a.bedno,a.paymentmethod,a.amount,a.remark from  zy_pay  a,zy_patientinfo b where  a.hospitalisationno = '"+strNo+"' and b.hospitalisationno ='"+strNo+"' and  b.hospitalizationstatus ='"+strstatus+"'order by a.id";
			}
		}
		else 
		{
			if(ui.radioButton_2->isChecked())
			{
				strsql="select a.id,a.sheetno,a.date ,a.hospitalisationno,a.patientname,a.registrydate,a.bedno,a.paymentmethod,a.amount,a.remark from  zy_pay  a,zy_patientinfo b where a.date  between  TIMESTAMP '"+startDate+"' and TIMESTAMP '"+endDate+"' and a.hospitalisationno = b.hospitalisationno and  b.hospitalizationstatus ='"+strstatus+"'order by a.id";
			}
			else
			{
				strsql="select a.id,a.sheetno,a.date ,a.hospitalisationno,a.patientname,a.registrydate,a.bedno,a.paymentmethod,a.amount,a.remark from  zy_pay  a,zy_patientinfo b where a.hospitalisationno = b.hospitalisationno and  b.hospitalizationstatus ='"+strstatus+"'order by a.id";
			}
		}
	}
	if (ui.comboBox_2->currentIndex()==2)
	{
		QString strstatus = QString::fromLocal8Bit("出院-已结算");
		if (strNo!=""&&strNo!=NULL )
		{
			if(ui.radioButton_2->isChecked())
			{
				strsql="select a.id,a.sheetno,a.date ,a.hospitalisationno,a.patientname,a.registrydate,a.bedno,a.paymentmethod,a.amount,a.remark from  zy_pay  a,zy_patientinfo b where a.date  between  TIMESTAMP '"+startDate+"' and TIMESTAMP '"+endDate+"' and a.hospitalisationno = '"+strNo+"' and b.hospitalisationno ='"+strNo+"' and  b.hospitalizationstatus ='"+strstatus+"'order by a.id";
			}
			else
			{
				strsql="select a.id,a.sheetno,a.date ,a.hospitalisationno,a.patientname,a.registrydate,a.bedno,a.paymentmethod,a.amount,a.remark from  zy_pay  a,zy_patientinfo b where  a.hospitalisationno = '"+strNo+"' and b.hospitalisationno ='"+strNo+"' and  b.hospitalizationstatus ='"+strstatus+"'order by a.id";
			}
		}
		else 
		{
			if(ui.radioButton_2->isChecked())
			{
				strsql="select a.id,a.sheetno,a.date ,a.hospitalisationno,a.patientname,a.registrydate,a.bedno,a.paymentmethod,a.amount,a.remark from  zy_pay  a,zy_patientinfo b where a.date  between  TIMESTAMP '"+startDate+"' and TIMESTAMP '"+endDate+"' and a.hospitalisationno = b.hospitalisationno and  b.hospitalizationstatus ='"+strstatus+"'order by a.id";
			}
			else
			{
				strsql="select a.id,a.sheetno,a.date ,a.hospitalisationno,a.patientname,a.registrydate,a.bedno,a.paymentmethod,a.amount,a.remark from  zy_pay  a,zy_patientinfo b where a.hospitalisationno = b.hospitalisationno and  b.hospitalizationstatus ='"+strstatus+"'order by a.id";
			}
		}
	}

	model->setQuery(strsql,*sql.db);
	model->setHeaderData(0,Qt::Horizontal,tr("ID"));
	model->setHeaderData(1,Qt::Horizontal,QString::fromLocal8Bit("交款单号"));
	model->setHeaderData(2,Qt::Horizontal,QString::fromLocal8Bit("收费日期"));
	model->setHeaderData(3,Qt::Horizontal,QString::fromLocal8Bit("病历号"));
	model->setHeaderData(4,Qt::Horizontal,QString::fromLocal8Bit("姓名"));
	model->setHeaderData(5,Qt::Horizontal,QString::fromLocal8Bit("住院日期"));
	model->setHeaderData(6,Qt::Horizontal,QString::fromLocal8Bit("床位"));
	model->setHeaderData(7,Qt::Horizontal,QString::fromLocal8Bit("付款方式"));
	model->setHeaderData(8,Qt::Horizontal,QString::fromLocal8Bit("金额"));
	model->setHeaderData(9,Qt::Horizontal,QString::fromLocal8Bit("备注"));
	model->setHeaderData(10,Qt::Horizontal,QString::fromLocal8Bit("交款人"));
	ui.paytableView->setModel(model);
}
void HospitalisationStatistics::on_payclearButton_clicked()
{
	QSqlQueryModel *model=new QSqlQueryModel();	
	ui.paytableView->setModel(model);
}
void HospitalisationStatistics::payedit(const QModelIndex &index)
{
	HospitalisationPay*pay = new HospitalisationPay();
	pay->showNormal();
	QAbstractItemModel *model = ui.paytableView->model();
	QString strNo=model->data(model->index(index.row(),1)).toString();
	pay->edit(strNo);
}
void HospitalisationStatistics::showinfo2(const QString &text)
{
	ui.lineEdit_5->clear();
	ui.lineEdit_9->clear();
	ui.lineEdit_7->clear();
	QString strsql= "select * from zy_patientinfo where hospitalisationno='"+text+"'";
	QSqlQuery query(*sql.db);	
	query.exec(strsql);
	while(query.next())
	{
		ui.lineEdit_5->setText(query.value(14).toString());
		ui.lineEdit_9->setText(query.value(4).toString());
		ui.lineEdit_7->setText(query.value(13).toString());	
	}
}
#pragma endregion 交款查询
#pragma region 收费查询
void HospitalisationStatistics::on_radioButton_5_clicked()
{
	if(!ui.radioButton_5->isChecked())
	{
		ui.dateTimeEdit_11->setEnabled(false);
		ui.dateTimeEdit_12->setEnabled(false);
	}
	if(ui.radioButton_5->isChecked())
	{
		ui.dateTimeEdit_11->setEnabled(true);
		ui.dateTimeEdit_12->setEnabled(true);
	}

}
void HospitalisationStatistics::on_chargequeryButton_clicked()
{
	QSqlQueryModel *model=new QSqlQueryModel();	
	QSqlQuery query(*sql.db);		
	QString startDate = ui.dateTimeEdit_11->dateTime().toString("yyyy-MM-dd hh:mm:ss");
	QString endDate = ui.dateTimeEdit_12->dateTime().toString("yyyy-MM-dd hh:mm:ss");

	QString strsql;
	QString strNo = ui.lineEdit_13->text();
	if (ui.comboBox_4->currentIndex()==0)
	{
		if (strNo!=""&&strNo!=NULL )
		{
			if(ui.radioButton_5->isChecked())
			{
				strsql="select a.date, a.hospitalisationno,b.patientname,a.itemtype,a.itemname,a.count,a.amount,a.sheetno from zy_chargedetail a , zy_patientinfo b  where a.date  between  TIMESTAMP '"+startDate+"' and TIMESTAMP '"+endDate+"' and a.hospitalisationno = '"+strNo+"' and b.hospitalisationno ='"+strNo+"' order by a.id";
			}
			else
			{
				strsql="select a.date, a.hospitalisationno,b.patientname,a.itemtype,a.itemname,a.count,a.amount,a.sheetno from zy_chargedetail a , zy_patientinfo b where a.hospitalisationno ='"+strNo+"'and b.hospitalisationno ='"+strNo+"' order by a.id";
			}
		}
		else 
		{
			if(ui.radioButton_5->isChecked())
			{
				strsql="select a.date, a.hospitalisationno,b.patientname,a.itemtype,a.itemname,a.count,a.amount,a.sheetno from zy_chargedetail  a , zy_patientinfo b where a.date  between  TIMESTAMP '"+startDate+"' and TIMESTAMP '"+endDate+"' and a.hospitalisationno = b.hospitalisationno order by a.id";
			}
			else
			{
				strsql="select a.date, a.hospitalisationno,b.patientname,a.itemtype,a.itemname,a.count,a.amount,a.sheetno from zy_chargedetail  a , zy_patientinfo b  where a.hospitalisationno = b.hospitalisationno order by a.id";
			}
		}
	}
	if (ui.comboBox_4->currentIndex()==1)
	{
		QString strstatus = QString::fromLocal8Bit("住院中");
		if (strNo!=""&&strNo!=NULL )
		{
			if(ui.radioButton_5->isChecked())
			{
				strsql="select a.date, a.hospitalisationno,b.patientname,a.itemtype,a.itemname,a.count,a.amount,a.sheetno from zy_chargedetail a , zy_patientinfo b  where a.date  between  TIMESTAMP '"+startDate+"' and TIMESTAMP '"+endDate+"' and a.hospitalisationno = '"+strNo+"' and b.hospitalisationno ='"+strNo+"' and  b.hospitalizationstatus ='"+strstatus+"' order by a.id";
			}
			else
			{
				strsql="select a.date, a.hospitalisationno,b.patientname,a.itemtype,a.itemname,a.count,a.amount,a.sheetno from zy_chargedetail a ,, zy_patientinfo b where a.hospitalisationno ='"+strNo+"'and b.hospitalisationno ='"+strNo+"'  and  b.hospitalizationstatus ='"+strstatus+"' order by a.id";
			}
		}
		else 
		{
			if(ui.radioButton_5->isChecked())
			{
				strsql="select a.date, a.hospitalisationno,b.patientname,a.itemtype,a.itemname,a.count,a.amount,a.sheetno from zy_chargedetail  a , zy_patientinfo b where a.date  between  TIMESTAMP '"+startDate+"' and TIMESTAMP '"+endDate+"' and a.hospitalisationno = b.hospitalisationno  and  b.hospitalizationstatus ='"+strstatus+"'order by a.id";
			}
			else
			{
				strsql="select a.date, a.hospitalisationno,b.patientname,a.itemtype,a.itemname,a.count,a.amount,a.sheetno from zy_chargedetail  a , zy_patientinfo b  where a.hospitalisationno = b.hospitalisationno  and  b.hospitalizationstatus ='"+strstatus+"' order by a.id";
			}
		}
	}
	if (ui.comboBox_4->currentIndex()==2)
	{
		QString strstatus = QString::fromLocal8Bit("出院-已结算");
		if (strNo!=""&&strNo!=NULL )
		{
			if(ui.radioButton_5->isChecked())
			{
				strsql="select a.date, a.hospitalisationno,b.patientname,a.itemtype,a.itemname,a.count,a.amount,a.sheetno from zy_chargedetail a , zy_patientinfo b  where a.date  between  TIMESTAMP '"+startDate+"' and TIMESTAMP '"+endDate+"' and a.hospitalisationno = '"+strNo+"' and b.hospitalisationno ='"+strNo+"' and  b.hospitalizationstatus ='"+strstatus+"' order by a.id";
			}
			else
			{
				strsql="select a.date, a.hospitalisationno,b.patientname,a.itemtype,a.itemname,a.count,a.amount,a.sheetno from zy_chargedetail a ,, zy_patientinfo b where a.hospitalisationno ='"+strNo+"'and b.hospitalisationno ='"+strNo+"'  and  b.hospitalizationstatus ='"+strstatus+"' order by a.id";
			}
		}
		else 
		{
			if(ui.radioButton_5->isChecked())
			{
				strsql="select a.date, a.hospitalisationno,b.patientname,a.itemtype,a.itemname,a.count,a.amount,a.sheetno from zy_chargedetail  a , zy_patientinfo b where a.date  between  TIMESTAMP '"+startDate+"' and TIMESTAMP '"+endDate+"' and a.hospitalisationno = b.hospitalisationno  and  b.hospitalizationstatus ='"+strstatus+"'order by a.id";
			}
			else
			{
				strsql="select a.date, a.hospitalisationno,b.patientname,a.itemtype,a.itemname,a.count,a.amount,a.sheetno from zy_chargedetail  a , zy_patientinfo b  where a.hospitalisationno = b.hospitalisationno  and  b.hospitalizationstatus ='"+strstatus+"' order by a.id";
			}
		}
	}
	model->setQuery(strsql,*sql.db);
	model->setHeaderData(0,Qt::Horizontal,tr("日期"));
	model->setHeaderData(1,Qt::Horizontal,QString::fromLocal8Bit("住院号"));
	model->setHeaderData(2,Qt::Horizontal,QString::fromLocal8Bit("姓名"));
	model->setHeaderData(3,Qt::Horizontal,QString::fromLocal8Bit("住院收据"));
	model->setHeaderData(4,Qt::Horizontal,QString::fromLocal8Bit("名称"));
	model->setHeaderData(5,Qt::Horizontal,QString::fromLocal8Bit("数量"));
	model->setHeaderData(6,Qt::Horizontal,QString::fromLocal8Bit("金额"));
	model->setHeaderData(7,Qt::Horizontal,QString::fromLocal8Bit("单号"));
	ui.chargetableView->setModel(model);
}
void HospitalisationStatistics::on_chargeclearButton_clicked()
{
	QSqlQueryModel *model=new QSqlQueryModel();	
	ui.chargetableView->setModel(model);
}

void HospitalisationStatistics::getItem(const QModelIndex &index)
{
	HospitalisationCharge*charge = new HospitalisationCharge();
	charge->showNormal();
	QAbstractItemModel *model = ui.chargetableView->model();
	QString strNo=model->data(model->index(index.row(),7)).toString();
	charge->edit(strNo);
}
void HospitalisationStatistics::showinfo3(const QString &text)
{
	ui.lineEdit_20->clear();
	ui.lineEdit_8->clear();
	ui.lineEdit_21->clear();
	QString strsql= "select * from zy_patientinfo where hospitalisationno='"+text+"'";
	QSqlQuery query(*sql.db);	
	query.exec(strsql);
	while(query.next())
	{
		ui.lineEdit_20->setText(query.value(4).toString());
		ui.lineEdit_8->setText(query.value(14).toString());
		ui.lineEdit_21->setText(query.value(13).toString());	
	}
}
#pragma endregion 收费查询
#pragma region 余额统计
void HospitalisationStatistics::on_balancequeryButton_clicked()
{
	ui.balancetableWidget->setRowCount(0);
	QString strNo = ui.lineEdit_4->text();
	QSqlQuery query(*sql.db);		
	if (strNo!=""&&strNo!=NULL )
	{
		query.exec("select * from zy_patientinfo where hospitalisationno= '"+strNo+"' ");// );
	}
	else
	{
		query.exec("select * from zy_patientinfo order by id");
	}
	int row= 0;
	while(query.next())
	{	
		strNo = query.value(1).toString();
		ui.balancetableWidget->insertRow(row);
		ui.balancetableWidget->setItem(row,0,new QTableWidgetItem(strNo));
		ui.balancetableWidget->setItem(row,1,new QTableWidgetItem(query.value(4).toString()));
		ui.balancetableWidget->setItem(row,2,new QTableWidgetItem(query.value(2).toDateTime().toString("yyyy-MM-dd hh:mm:ss")));
		ui.balancetableWidget->setItem(row,3,new QTableWidgetItem(query.value(13).toString()));
		ui.balancetableWidget->setItem(row,7,new QTableWidgetItem(query.value(15).toString()));

		double totalpay=0.0;
		double totalfee=0.0;
		QSqlQuery query2(*sql.db);	
		query2.exec("select * from zy_pay where hospitalisationno= '"+strNo+"'");
		while(query2.next())
		{
			totalpay +=query2.value(8).toDouble();
		}
		query2.exec("select * from zy_chargedetail where hospitalisationno= '"+strNo+"'");
		while(query2.next())
		{
			totalfee +=query2.value(8).toDouble();
		}
		ui.balancetableWidget->setItem(row,4,new QTableWidgetItem(QString::number(totalpay)));
		ui.balancetableWidget->setItem(row,5,new QTableWidgetItem(QString::number(totalfee)));
		ui.balancetableWidget->setItem(row,6,new QTableWidgetItem(QString::number(totalpay-totalfee)));
		row++;
	}
}
void HospitalisationStatistics::on_balanceclearButton_clicked()
{
	ui.balancetableWidget->setRowCount(0);
}
void HospitalisationStatistics::showinfo4(const QString &text)
{
	ui.lineEdit_14->clear();
	ui.lineEdit_16->clear();
	ui.lineEdit_15->clear();
	QString strsql= "select * from zy_patientinfo where hospitalisationno='"+text+"'";
	QSqlQuery query(*sql.db);	
	query.exec(strsql);
	while(query.next())
	{
		ui.lineEdit_14->setText(query.value(4).toString());
		ui.lineEdit_16->setText(query.value(14).toString());
		ui.lineEdit_15->setText(query.value(13).toString());	
	}
}
#pragma endregion 余额统计
#pragma region 住院清单
void HospitalisationStatistics::on_radioButton_3_clicked()
{
	if(!ui.radioButton_3->isChecked())
	{
		ui.dateTimeEdit_13->setEnabled(false);
		ui.dateTimeEdit_14->setEnabled(false);
	}
	if(ui.radioButton_3->isChecked())
	{
		ui.dateTimeEdit_13->setEnabled(true);
		ui.dateTimeEdit_14->setEnabled(true);
	}

}
void HospitalisationStatistics::on_printButton_clicked()
{
	QPrinter       printer( QPrinter::PrinterResolution );
	QPrintDialog   dialog( &printer, this );
	if ( dialog.exec() == QDialog::Accepted ) print( &printer );
}
void HospitalisationStatistics::on_previewButton_clicked()
{
	filePrintPreview();
}
void HospitalisationStatistics::filePrintPreview()
{
	// 打印预览对话框
	QPrinter             printer( QPrinter::PrinterResolution );
	QPrintPreviewDialog  preview( &printer, this );
	preview.setWindowTitle(QString::fromLocal8Bit("预览"));
	preview.setMinimumSize(800,600);
	connect( &preview, SIGNAL(paintRequested(QPrinter*)), SLOT(print(QPrinter*)) );
	preview.exec();
}
void HospitalisationStatistics::print( QPrinter* printer )
{

	if(ui.comboBox_5->currentText()==QString::fromLocal8Bit("费用汇总"))
	{
		QString strNo = ui.lineEdit_6->text();
		if (strNo==""&&strNo==NULL )
		{
			QMessageBox box(QMessageBox::Warning,QString::fromLocal8Bit("警告"),QString::fromLocal8Bit("请输入住院号！"));
			box.setStandardButtons (QMessageBox::Ok);
			box.setButtonText (QMessageBox::Ok,QString::fromLocal8Bit("确 定"));
			box.exec();
			return;
		}
		QPainter painter( printer );
		int      w = printer->pageRect().width();
		int      h = printer->pageRect().height();
		QRect    page( 0, h/130, w, h );
		QRect    page2(0, h/50, w, h );
		QRect    page3(0, h/30, w, h );
		QFont    font = painter.font();
		font.setPointSize(9);
		painter.setFont( font );
		painter.drawText( page, Qt::AlignTop    | Qt::AlignHCenter, QString::fromLocal8Bit("三河市燕郊镇卫生院住院清单") );
		QString strHospitalNo = ui.lineEdit_6->text();
		QSqlQuery query(*sql.db);
		QString strRegistryDate,strOutDate,strGender,strAge;
		QString strsql = "select *from zy_patientinfo where hospitalisationno = '"+strHospitalNo+"'";
		query.exec(strsql);
		while(query.next())
		{
			strRegistryDate = query.value(2).toString();
			strGender =  query.value(5).toString();
			strAge =  query.value(6).toString();
			strOutDate= query.value(23).toString();

		}
		strRegistryDate.replace("T"," ");
		strOutDate.replace("T"," ");
		QString str =QString::fromLocal8Bit("住院号:")+ ui.lineEdit_6->text()+QString::fromLocal8Bit("   姓名:")+ ui.lineEdit_17->text()+QString::fromLocal8Bit("   性别:")+strGender+QString::fromLocal8Bit("   年龄:")+strAge;
		painter.drawText( page2, Qt::AlignTop    | Qt::AlignHCenter, str );
		str =QString::fromLocal8Bit("入院日期:")+ strRegistryDate+QString::fromLocal8Bit("   出院日期:")+ strOutDate;
		painter.drawText( page3, Qt::AlignTop    | Qt::AlignHCenter, str );
		painter.begin(this);
		painter.setPen(QPen(Qt::black,4,Qt::SolidLine));//设置画笔形式 
		painter.setBrush(QBrush(Qt::white,Qt::SolidPattern));//设置画刷形式 
		int row = ui.billtableWidget->rowCount();
		int col = ui.billtableWidget->columnCount();
		double cellwidth;
		double cellheight;
		double upmargin;
		if(sql.windowsFlag==QSysInfo::WV_5_1||sql.windowsFlag==QSysInfo::WV_5_0||sql.windowsFlag==QSysInfo::WV_5_2||sql.windowsFlag==QSysInfo::WV_4_0)//判断当前系统
		{
			cellwidth=400;
			cellheight=60;
			upmargin = h/35;
		}
		else
		{
			cellwidth=1600;
			cellheight=160;
			upmargin = h/35;
		}
		double leftmargin = (w-cellwidth*col)/2;
		QStringList list;
		for (int j =0;j<col;j++)
		{
			list.append(ui.billtableWidget->horizontalHeaderItem(j)->text());
		}
		for (int i=0;i<row;i++)
		{
			for (int j=0;j<col;j++)
			{
				if (ui.billtableWidget->item(i,j)==NULL)
				{
					list.append("");
					continue;
				}
				list.append(ui.billtableWidget->item(i,j)->text());
			}
		}
		for (int i=0;i<row+1;i++)
		{
			for (int j=0;j<col;j++)
			{
				painter.drawRect(leftmargin+j*cellwidth,upmargin+cellheight*(i+1),cellwidth,cellheight);
				QRect rect(leftmargin+j*cellwidth,upmargin+cellheight*(i+1),cellwidth,cellheight);
				painter.drawText( rect, Qt::AlignVCenter    | Qt::AlignHCenter, list.at(i*col+j) );//ui.billtableWidget->item(i,j)->text()
			}
		}
		painter.drawRect(leftmargin,upmargin+cellheight*(row+2),cellwidth*col,cellheight);
		QRect rect(leftmargin,upmargin+cellheight*(row+2),cellwidth*col,cellheight);

		Capital*capital = new Capital;
		double sum = ui.billtableWidget->item(row-1,1)->text().toDouble();

		painter.drawText( rect, Qt::AlignVCenter    | Qt::AlignLeft, QString::fromLocal8Bit("大写：")+capital->NumToChineseStr(sum));//ui.billtableWidget->item(i,j)->text()

		QRect rect2(leftmargin,upmargin+cellheight*(row+3),cellwidth*col,cellheight);
		painter.drawText( rect2, Qt::AlignVCenter    | Qt::AlignLeft, QString::fromLocal8Bit("制表：")+sql.struser+"        "+ QString::fromLocal8Bit("打印日期：")+"   "+ QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));//ui.billtableWidget->item(i,j)->text()

		painter.end();
		return;
	}
	QPainter painter( printer );
	int      w = printer->pageRect().width();
	int      h = printer->pageRect().height();
	QRect    page( w/50, h/70, w, h );
	QRect    page4( w/30, h/10, w, h );
	QFont    font = painter.font();
	font.setPointSize(8);
	painter.setFont( font );
	painter.drawText( page, Qt::AlignTop    | Qt::AlignHCenter, QString::fromLocal8Bit(" 三河市燕郊镇卫生院住院明细") );

	QPixmap image;
	image=image.grabWidget(ui.billtableWidget,0,0,1000, 1000);
//	painter.drawPixmap(page4,image);

	painter.begin(this);
	painter.setPen(QPen(Qt::black,4,Qt::SolidLine));//设置画笔形式 
	painter.setBrush(QBrush(Qt::white,Qt::SolidPattern));//设置画刷形式 
	int row = ui.billtableWidget->rowCount();
	int col = ui.billtableWidget->columnCount();
	double cellwidth = (w-40)/col;
	double cellheight = 160;
	double upmargin = h/50;

	//计算总页数
	int firstpagerow = (h-upmargin)/160;//第一页上方空白为750,下方为50
	int everypagerow = (h-100)/160;//后面每页的空白为100
	int pagecount = 0;
	//xp系统
	if(sql.windowsFlag==QSysInfo::WV_5_1||sql.windowsFlag==QSysInfo::WV_5_0||sql.windowsFlag==QSysInfo::WV_5_2||sql.windowsFlag==QSysInfo::WV_4_0)//判断当前系统
	{
		cellwidth= (w-100)/col;
		cellheight=60;
		upmargin = h/50;;
		firstpagerow = (h-upmargin)/cellheight;
		everypagerow = (h-20)/cellheight;
	}
	double leftmargin = (w-cellwidth*col)/2;
	if (row>firstpagerow)
	{
		pagecount = (row -firstpagerow)/everypagerow;
		int remain  = (row -firstpagerow)%everypagerow;
		if (remain!=0)
		{
			pagecount+=2;
		}
		else
		{
			pagecount+=1;
		}
	}
	else
	{
		pagecount=1;
	}
	if (pagecount == 1)
	{

		QStringList list;
		for (int j =0;j<col;j++)
		{
			list.append(ui.billtableWidget->horizontalHeaderItem(j)->text());
		}
		for (int i=0;i<row;i++)
		{
			for (int j=0;j<col;j++)
			{
				if (ui.billtableWidget->item(i,j)==NULL)
				{
					list.append("");
					continue;
				}
				list.append(ui.billtableWidget->item(i,j)->text());
			}
		}
		for (int i=0;i<row+1;i++)
		{
			for (int j=0;j<col;j++)
			{
				painter.drawRect(leftmargin+j*cellwidth,upmargin+cellheight*(i+1),cellwidth,cellheight);
				QRect rect(leftmargin+j*cellwidth,upmargin+cellheight*(i+1),cellwidth,cellheight);
				painter.drawText( rect, Qt::AlignVCenter    | Qt::AlignHCenter, list.at(i*col+j) );//ui.billtableWidget->item(i,j)->text()
			}
		}
		painter.end();
	}
	else
	{
		//首页
		QStringList list;
		for (int j =0;j<col;j++)
		{
			list.append(ui.billtableWidget->horizontalHeaderItem(j)->text());
		}
		for (int i=0;i<firstpagerow;i++)
		{
			for (int j=0;j<col;j++)
			{
				if (ui.billtableWidget->item(i,j)==NULL)
				{
					list.append("");
					continue;
				}
				list.append(ui.billtableWidget->item(i,j)->text());
			}
		}
		for (int i=0;i<firstpagerow+1;i++)
		{
			for (int j=0;j<col;j++)
			{
				painter.drawRect(leftmargin+j*cellwidth,upmargin+cellheight*(i+1),cellwidth,cellheight);
				QRect rect(leftmargin+j*cellwidth,upmargin+cellheight*(i+1),cellwidth,cellheight);
				painter.drawText( rect, Qt::AlignVCenter    | Qt::AlignHCenter, list.at(i*col+j) );//ui.billtableWidget->item(i,j)->text()
			}
		}
		printer->newPage();
		//占满的页面
		for (int k = 0;k<pagecount-2;k++)
		{
			list.clear();
			for (int i=firstpagerow+k*everypagerow;i<firstpagerow+(k+1)*everypagerow;i++)
			{
				for (int j=0;j<col;j++)
				{
					if (ui.billtableWidget->item(i,j)==NULL)
					{
						list.append("");
						continue;
					}
					list.append(ui.billtableWidget->item(i,j)->text());
				}
			}
			for (int i=0;i<everypagerow;i++)
			{
				for (int j=0;j<col;j++)
				{
					painter.drawRect(leftmargin+j*cellwidth,50+cellheight*(i),cellwidth,cellheight);
					QRect rect(leftmargin+j*cellwidth,50+cellheight*(i),cellwidth,cellheight);
					painter.drawText( rect, Qt::AlignVCenter    | Qt::AlignHCenter, list.at(i*col+j) );//ui.billtableWidget->item(i,j)->text()
				}
			}
			printer->newPage();
		}
		//
		list.clear();
		for (int i=firstpagerow+(pagecount-2)*everypagerow;i<row;i++)
		{
			for (int j=0;j<col;j++)
			{
				if (ui.billtableWidget->item(i,j)==NULL)
				{
					list.append("");
					continue;
				}
				list.append(ui.billtableWidget->item(i,j)->text());
			}
		}
		for (int i=0;i<row-firstpagerow-(pagecount-2)*everypagerow;i++)
		{
			for (int j=0;j<col;j++)
			{
				painter.drawRect(leftmargin+j*cellwidth,50+cellheight*(i+1),cellwidth,cellheight);
				QRect rect(leftmargin+j*cellwidth,50+cellheight*(i+1),cellwidth,cellheight);
				painter.drawText( rect, Qt::AlignVCenter    | Qt::AlignHCenter, list.at(i*col+j) );//ui.billtableWidget->item(i,j)->text()
			}
		}
		painter.end();
	}
}
void HospitalisationStatistics::on_billqueryButton_clicked()
{
	ui.billtableWidget->setRowCount(0);
	QString strNo= ui.lineEdit_6->text();
	QSqlQuery query(*sql.db);	
	QString startDate = ui.dateTimeEdit_13->dateTime().toString("yyyy-MM-dd hh:mm:ss");
	QString endDate = ui.dateTimeEdit_14->dateTime().toString("yyyy-MM-dd hh:mm:ss");

	ui.billtableWidget->clear();
	QStringList header;
	//费用清单
	if(ui.comboBox_5->currentIndex()==0)
	{
		ui.billtableWidget->setColumnCount(10);
		header<<QString::fromLocal8Bit("住院号")<<QString::fromLocal8Bit("编码")<<QString::fromLocal8Bit("名称")<<QString::fromLocal8Bit("数量")<<QString::fromLocal8Bit("金额")<<QString::fromLocal8Bit("规格")<<QString::fromLocal8Bit("生产厂商")<<QString::fromLocal8Bit("单位")<<QString::fromLocal8Bit("收费日期")<<QString::fromLocal8Bit("类型");
		ui.billtableWidget->setHorizontalHeaderLabels(header);
		
		QString strNo = ui.lineEdit_6->text();
		if (strNo!=""&&strNo!=NULL )
		{
			if(ui.radioButton_3->isChecked())
			{
				query.exec("select * from zy_chargedetail where  hospitalisationno='"+strNo+"' and date between  TIMESTAMP '"+startDate+"' and TIMESTAMP '"+endDate+"'");		
			}
			if(!ui.radioButton_3->isChecked())
			{
				query.exec("select * from zy_chargedetail where  hospitalisationno='"+strNo+"'");
			}
		}
		else 
		{
			if(ui.radioButton_3->isChecked())
			{
				query.exec("select * from zy_chargedetail where date between  TIMESTAMP '"+startDate+"' and TIMESTAMP '"+endDate+"'");		
			}
			if(!ui.radioButton_3->isChecked())
			{
				query.exec("select * from zy_chargedetail ");
			}
		}
		int row= 0;
		while(query.next())
		{
			ui.billtableWidget->insertRow(row);

			ui.billtableWidget->setItem(row,0,new QTableWidgetItem(query.value(10).toString()));
			ui.billtableWidget->setItem(row,2,new QTableWidgetItem(query.value(4).toString()));
			QString strname=query.value(4).toString();
			QSqlQuery query2(*sql.db);
			query2.exec("select * from sys_drugdictionary where name='"+strname+"'");
			while(query2.next())
			{
				ui.billtableWidget->setItem(row,6,new QTableWidgetItem(query2.value(5).toString()));
				ui.billtableWidget->setItem(row,5,new QTableWidgetItem(query2.value(4).toString()));
				ui.billtableWidget->setItem(row,1,new QTableWidgetItem(query2.value(22).toString()));
			}
			ui.billtableWidget->setItem(row,7,new QTableWidgetItem(query.value(5).toString()));
			ui.billtableWidget->setItem(row,3,new QTableWidgetItem(query.value(6).toString()));
			ui.billtableWidget->setItem(row,4,new QTableWidgetItem(query.value(8).toString()));
			ui.billtableWidget->setItem(row,8,new QTableWidgetItem(query.value(9).toString()));
			ui.billtableWidget->setItem(row,9,new QTableWidgetItem(query.value(3).toString()));
			row++;
	}
	}
	if(ui.comboBox_5->currentText()==QString::fromLocal8Bit("费用汇总"))
	{
		QString strNo = ui.lineEdit_6->text();
		QStringList typelist;
		QSqlQuery query(*sql.db);
		query.exec("select * from zy_receipt");
		while(query.next())
		{
			typelist.append(query.value(1).toString()+"-"+query.value(2).toString());
		}
		typelist.append(QString::fromLocal8Bit("合计"));
		QStringList header;
		header.append(QString::fromLocal8Bit("类型"));
		header.append(QString::fromLocal8Bit("金额"));
		ui.billtableWidget->setHorizontalHeaderLabels(header);
		ui.billtableWidget->setColumnCount(2);

		if (strNo==""&&strNo==NULL )
		{
			QMessageBox box(QMessageBox::Warning,QString::fromLocal8Bit("警告"),QString::fromLocal8Bit("请输入住院号！"));
			box.setStandardButtons (QMessageBox::Ok);
			box.setButtonText (QMessageBox::Ok,QString::fromLocal8Bit("确 定"));
			box.exec();
			return;
		}
		QString strsql;
		double tempfee=0.0;
		int row= 0;
		for (int i = 0;i<typelist.count();i++)
		{
			QString strType = typelist.at(i);

			ui.billtableWidget->insertRow(row);
			if (strNo!=""&&strNo!=NULL )
			{
				if(ui.radioButton_3->isChecked())
				{
					query.exec("select * from zy_chargedetail where  itemtype='"+strType+"' and hospitalisationno='"+strNo+"' and date between  TIMESTAMP '"+startDate+"' and TIMESTAMP '"+endDate+"'");		
				}
				if(!ui.radioButton_3->isChecked())
				{
					query.exec("select * from zy_chargedetail where  itemtype='"+strType+"'and  hospitalisationno='"+strNo+"'");
				}
			}
			else 
			{
				if(ui.radioButton_3->isChecked())
				{
					query.exec("select * from zy_chargedetail where itemtype='"+strType+"'and  date between  TIMESTAMP '"+startDate+"' and TIMESTAMP '"+endDate+"'");		
				}
				if(!ui.radioButton_3->isChecked())
				{
					query.exec("select * from zy_chargedetail where itemtype='"+strType+"'");
				}
			}
			double totalfee=0.0;
			while(query.next())
			{
				totalfee+=query.value(8).toDouble();	
			}
			tempfee+=totalfee;
			ui.billtableWidget->setItem(i,0,new QTableWidgetItem(strType));
			ui.billtableWidget->setItem(i,1,new QTableWidgetItem(QString::number(totalfee)));
			row++;
		}
		ui.billtableWidget->setItem(typelist.count()-1,1,new QTableWidgetItem(QString::number(tempfee)));

	}
}
void HospitalisationStatistics::on_billclearButton_clicked()
{
	ui.billtableWidget->setRowCount(0);
}
void HospitalisationStatistics::showinfo5(const QString &text)
{
	ui.lineEdit_17->clear();
	ui.lineEdit_18->clear();
	ui.lineEdit_19->clear();
	QString strsql= "select * from zy_patientinfo where hospitalisationno='"+text+"'";
	QSqlQuery query(*sql.db);	
	query.exec(strsql);
	while(query.next())
	{
		ui.lineEdit_17->setText(query.value(4).toString());
		ui.lineEdit_18->setText(query.value(14).toString());
		ui.lineEdit_19->setText(query.value(13).toString());	
	}
}
#pragma endregion 住院清单
#pragma region 项目查询
void HospitalisationStatistics::on_radioButton_6_clicked()
{
	if(!ui.radioButton_6->isChecked())
	{
		ui.dateTimeEdit_17->setEnabled(false);
		ui.dateTimeEdit_18->setEnabled(false);
	}
	if(ui.radioButton_6->isChecked())
	{
		ui.dateTimeEdit_17->setEnabled(true);
		ui.dateTimeEdit_18->setEnabled(true);
	}

}
void HospitalisationStatistics::on_projectqueryButton_clicked()
{
	ui.tableWidget_5->setRowCount(0);
	ui.tableWidget_5->clear();
	QString startDate = ui.dateTimeEdit_17->dateTime().toString("yyyy-MM-dd hh:mm:ss");
	QString endDate = ui.dateTimeEdit_18->dateTime().toString("yyyy-MM-dd hh:mm:ss");


	QDateTime current_date_time = QDateTime::currentDateTime();
	QString strtime = current_date_time.toString("yyyy-MM-dd hh:mm:ss");


	QStringList typelist;

	typelist.append(QString::fromLocal8Bit("名称"));
	//typelist.append(QString::fromLocal8Bit("01-床位费B"));
	//typelist.append(QString::fromLocal8Bit("02-诊查费C"));
	//typelist.append(QString::fromLocal8Bit("03-护理费F"));
	//typelist.append(QString::fromLocal8Bit("04-手术费G"));
	//typelist.append(QString::fromLocal8Bit("05-挂号费A"));
	//typelist.append(QString::fromLocal8Bit("06-治疗费E"));
	//typelist.append(QString::fromLocal8Bit("09-西药费"));
	//typelist.append(QString::fromLocal8Bit("10-检查费D"));
	//typelist.append(QString::fromLocal8Bit("12-其他费I"));
	//typelist.append(QString::fromLocal8Bit("13-中成药费"));
	//typelist.append(QString::fromLocal8Bit("14-化验费H"));
	//typelist.append(QString::fromLocal8Bit("17-材料费"));
	QSqlQuery query(*sql.db);
	query.exec("select * from zy_receipt");
	while(query.next())
	{
		typelist.append(query.value(1).toString()+"-"+query.value(2).toString());
	}
	ui.tableWidget_5->setColumnCount(typelist.count());
	ui.tableWidget_5->setHorizontalHeaderLabels(typelist);
	if (ui.comboBox_3->currentIndex()==0)
	{
		ui.tableWidget_5->insertRow(0);
		ui.tableWidget_5->setItem(0,0,new QTableWidgetItem(QString::fromLocal8Bit("住院收据")));
		for (int i = 1;i<typelist.count();i++)
		{
			QString strType = typelist.at(i);
			QString strsql;
			if (ui.radioButton_6->isChecked())
			{
				strsql ="select * from zy_chargedetail where itemtype='"+strType+"'and date between  TIMESTAMP '"+startDate+"' and TIMESTAMP '"+endDate+"'";
			}
			else
			{
				strsql ="select * from zy_chargedetail where itemtype='"+strType+"' ";
			}
			QSqlQuery query(*sql.db);
			query.exec(strsql);
			double totalfee=0.0;
			while(query.next())
			{
				totalfee+=query.value(8).toDouble();	
			}
			ui.tableWidget_5->setItem(0,i,new QTableWidgetItem(QString::number(totalfee)));
		}
	}

	if (ui.comboBox_3->currentIndex()==1)
	{
		QSqlQuery query0(*sql.db);
		query0.exec("select * from sys_department");
		int row = 0;
		QString strsql;
		while(query0.next())
		{	
			ui.tableWidget_5->insertRow(row);
			QString strdepartment = query0.value(1).toString();
			ui.tableWidget_5->setItem(row,0,new QTableWidgetItem(strdepartment));
			for (int i = 1;i<typelist.count();i++)
			{
				QString strType = typelist.at(i);
				if (ui.radioButton_6->isChecked())
				{
					strsql ="select * from zy_chargedetail where itemtype='"+strType+"'and date between  TIMESTAMP '"+startDate+"' and TIMESTAMP '"+endDate+"'";
				}
				else
				{
					strsql ="select * from zy_chargedetail where itemtype='"+strType+"' ";
				}
				QSqlQuery query(*sql.db);
				query.exec(strsql);
				double totalfee=0.0;
				while(query.next())
				{
					QSqlQuery query2(*sql.db);
					QString strsheetno = query.value(1).toString();
					query2.exec("select * from zy_chargesheet where sheetno ='"+strsheetno+"' and department ='"+strdepartment+"'");
					if (query2.next())
					{
						totalfee+=query.value(8).toDouble();
					}		
				}
				ui.tableWidget_5->setItem(row,i,new QTableWidgetItem(QString::number(totalfee)));
			}
			row++;
		}
	}

	if (ui.comboBox_3->currentIndex()==2)
	{
		QSqlQuery query0(*sql.db);
		query0.exec("select * from sys_personnel");
		int row = 0;
		QString strsql;
		while(query0.next())
		{	
			ui.tableWidget_5->insertRow(row);
			QString strpersonnel= query0.value(2).toString();
			ui.tableWidget_5->setItem(row,0,new QTableWidgetItem(strpersonnel));
			for (int i = 1;i<typelist.count();i++)
			{
				QString strType = typelist.at(i);
				if (ui.radioButton_6->isChecked())
				{
					strsql ="select * from zy_chargedetail where itemtype='"+strType+"'and date between  TIMESTAMP '"+startDate+"' and TIMESTAMP '"+endDate+"'";
				}
				else
				{
					strsql ="select * from zy_chargedetail where itemtype='"+strType+"' ";
				}
				QSqlQuery query(*sql.db);
				query.exec(strsql);
				double totalfee=0.0;
				while(query.next())
				{
					QSqlQuery query2(*sql.db);
					QString strsheetno = query.value(1).toString();
					query2.exec("select * from zy_chargesheet where sheetno ='"+strsheetno+"'and doctor ='"+strpersonnel+"'");
					if (query2.next())
					{
						totalfee+=query.value(8).toDouble();
					}		
				}
				ui.tableWidget_5->setItem(row,i,new QTableWidgetItem(QString::number(totalfee)));
			}
			row++;
		}
	}

	if (ui.comboBox_3->currentIndex()==3)
	{
		typelist.clear();
		QSqlQuery query0(*sql.db);
		ui.tableWidget_5->clear();
		typelist.append(QString::fromLocal8Bit("名称"));
		query0.exec("select * from zy_classification");
		while(query0.next())
		{
			typelist.append(query0.value(1).toString()+"-"+query0.value(2).toString());
		}
		ui.tableWidget_5->setColumnCount(typelist.count());
		ui.tableWidget_5->setHorizontalHeaderLabels(typelist);
		query0.exec("select * from sys_users");
		int row = 0;
		QString strsql;
		while(query0.next())
		{	
			
			QString strpersonnel= query0.value(1).toString();
		//	if(strpersonnel=="admin") continue;
			ui.tableWidget_5->insertRow(row);
			ui.tableWidget_5->setItem(row,0,new QTableWidgetItem(strpersonnel));
			for (int i = 1;i<typelist.count();i++)
			{
				QString strType = typelist.at(i);
				if (ui.radioButton_6->isChecked())
				{
					strsql ="select * from zy_chargedetail where itemclass='"+strType+"'and date between  TIMESTAMP '"+startDate+"' and TIMESTAMP '"+endDate+"'";
				}
				else
				{
					strsql ="select * from zy_chargedetail where itemclass='"+strType+"' ";
				}
				QSqlQuery query(*sql.db);
				query.exec(strsql);
				double totalfee=0.0;
				while(query.next())
				{
					QSqlQuery query2(*sql.db);
					QString strsheetno = query.value(1).toString();
					query2.exec("select * from zy_chargesheet where sheetno ='"+strsheetno+"'and sheetmaker ='"+strpersonnel+"'");
					if (query2.next())
					{
						totalfee+=query.value(8).toDouble();
					}		
				}
				ui.tableWidget_5->setItem(row,i,new QTableWidgetItem(QString::number(totalfee)));
			}
			row++;
		}
	}
}
void HospitalisationStatistics::on_projectclearButton_clicked()
{
	ui.tableWidget_5->setRowCount(0);
}
#pragma endregion 项目查询
HospitalisationStatistics::~HospitalisationStatistics()
{

}
