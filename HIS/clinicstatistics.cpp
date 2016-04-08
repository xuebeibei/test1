#include "clinicstatistics.h"
#include "connectsql.h"
#include "cliniccharge.h"
#include "connectdb.h"
extern ConnectSql sql;
ClinicStatistics::ClinicStatistics(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	listView = new QListView(this);
	model = new QStringListModel(this);
	listView->setWindowFlags(Qt::ToolTip);

	ui.tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);  
	ui.tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows); 
	ui.tableWidget->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
	ui.tableWidget->setStyleSheet("QTableWidget{border: 1px solid gray;	background-color: transparent;	selection-color: grey;}");
	ui.tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section {background-color:white;color: black;padding-left: 4px;border: 1px solid #6c6c6c;};"
		"color: white;padding-left: 4px;border: 1px solid #6c6c6c;}"
		"QHeaderView::section:checked{background-color: white;color: black;}");	
	ui.tableWidget_2->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
	ui.tableWidget_2->setStyleSheet("QTableWidget{border: 1px solid gray;	background-color: transparent;	selection-color: grey;}");
	ui.tableWidget_2->horizontalHeader()->setStyleSheet("QHeaderView::section {background-color:white;color: black;padding-left: 4px;border: 1px solid #6c6c6c;};"
		"color: white;padding-left: 4px;border: 1px solid #6c6c6c;}"
		"QHeaderView::section:checked{background-color: white;color: black;}");	
	ui.tableWidget_5->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
	ui.tableWidget_5->setStyleSheet("QTableWidget{border: 1px solid gray;	background-color: transparent;	selection-color: grey;}");
	ui.tableWidget_5->horizontalHeader()->setStyleSheet("QHeaderView::section {background-color:white;color: black;padding-left: 4px;border: 1px solid #6c6c6c;};"
		"color: white;padding-left: 4px;border: 1px solid #6c6c6c;}"
		"QHeaderView::section:checked{background-color: white;color: black;}");	
	initUI();
	connect(ui.tableWidget,SIGNAL(cellDoubleClicked(int,int)),this,SLOT(getItem(int,int)));
	connect(ui.patientEdit, SIGNAL(textChanged(const QString &)), this, SLOT(setCompleter(const QString &)));
	connect(listView, SIGNAL(clicked(const QModelIndex &)), this, SLOT(completeText(const QModelIndex &)));
}
void ClinicStatistics::initUI()
{
	QDateTime current_date_time = QDateTime::currentDateTime();
	ui.dateTimeEdit->setDateTime(current_date_time);
	ui.dateTimeEdit_2->setDateTime(current_date_time);

	ui.dateTimeEdit_3->setDateTime(current_date_time);
	QTime time= QTime::fromString("00:00:00", "hh:mm:ss");
	ui.dateTimeEdit_3->setTime(time);
	ui.dateTimeEdit_4->setDateTime(current_date_time);
	time= QTime::fromString("23:59:59", "hh:mm:ss");
	ui.dateTimeEdit_4->setTime(time);

	ui.dateTimeEdit_5->setDateTime(current_date_time);
	ui.dateTimeEdit_6->setDateTime(current_date_time);

	QSqlQuery query(*sql.db);		
	query.exec("select * from sys_department");
	QStringList list;
	while(query.next())
	{
		QString str = query.value(1).toString();
		list.append(str);
	}
//	ui.departmentcomboBox->addItems(list);

	query.exec("select * from sys_personnel");
	list.clear();
	while(query.next())
	{
		QString str = query.value(2).toString();
		list.append(str);
	}
//	ui.doctorcomboBox->addItems(list);

	query.exec("select * from sys_users");
	list.clear();
	while(query.next())
	{
		QString str = query.value(1).toString();
		list.append(str);
	}
//	ui.comboBox_2->addItems(list);

}
void ClinicStatistics::on_radioButton_clicked()
{
	if(!ui.radioButton->isChecked())
	{
		ui.dateTimeEdit_3->setEnabled(false);
		ui.dateTimeEdit_4->setEnabled(false);
	}
	if(ui.radioButton->isChecked())
	{
		ui.dateTimeEdit_3->setEnabled(true);
		ui.dateTimeEdit_4->setEnabled(true);
	}

}
void ClinicStatistics::on_queryButton_clicked()
{

	ui.tableWidget->setRowCount(0);
	QString startDate = ui.dateTimeEdit_3->dateTime().toString("yyyy-MM-dd hh:mm:ss");
	QString endDate = ui.dateTimeEdit_4->dateTime().toString("yyyy-MM-dd hh:mm:ss");

	QString strPatientName = ui.patientEdit->text();
	QSqlQuery query(*sql.db);	
	if (ui.patientEdit->text()!=""&&ui.patientEdit->text()!=NULL)
	{
		if (ui.radioButton->isChecked())
		{
			query.exec("select * from mz_chargesheet where   date between  TIMESTAMP '"+startDate+"' and TIMESTAMP '"+endDate+"' and  patientname='"+strPatientName+"'");
		}
		else
		{
			query.exec("select * from mz_chargesheet where  patientname='"+strPatientName+"'");
		}
	}
	else
	{
		if (ui.radioButton->isChecked())
		{
			query.exec("select * from mz_chargesheet where   date between  TIMESTAMP '"+startDate+"' and TIMESTAMP '"+endDate+"'");
		}
		else
		{
			query.exec("select * from mz_chargesheet");
		}
	}

	while(query.next())
	{	
		QString strsheetNo = query.value(1).toString();
		QSqlQuery query2(*sql.db);	
		query2.exec("select * from mz_chargedetail where sheetno='"+strsheetNo+"'");
		int row= 0;
		while(query2.next())
		{
			ui.tableWidget->insertRow(row);
			ui.tableWidget->setItem(row,0,new QTableWidgetItem(query2.value(3).toString()));
			ui.tableWidget->setItem(row,1,new QTableWidgetItem(query.value(2).toDateTime().toString("yyyy-MM-dd hh:mm:ss")));

			ui.tableWidget->setItem(row,2,new QTableWidgetItem(query2.value(4).toString()));
			ui.tableWidget->setItem(row,3,new QTableWidgetItem(query2.value(6).toString()));
			ui.tableWidget->setItem(row,4,new QTableWidgetItem(query2.value(5).toString()));
			ui.tableWidget->setItem(row,5,new QTableWidgetItem(query2.value(7).toString()));
			ui.tableWidget->setItem(row,6,new QTableWidgetItem(query2.value(8).toString()));

			ui.tableWidget->setItem(row,7,new QTableWidgetItem(query.value(5).toString()));
			ui.tableWidget->setItem(row,8,new QTableWidgetItem(query.value(8).toString()));

			ui.tableWidget->setItem(row,9,new QTableWidgetItem(query2.value(2).toString()));
			ui.tableWidget->setItem(row,10,new QTableWidgetItem(query.value(1).toString()));
			row++;
		}
	}
}
void ClinicStatistics::on_clearButton_clicked()
{
	ui.tableWidget->setRowCount(0);
	ui.patientEdit->clear();
	ui.lineEdit->clear();
	ui.lineEdit_2->clear();
}
void ClinicStatistics::on_radioButton_2_clicked()
{
	if(!ui.radioButton_2->isChecked())
	{
		ui.dateTimeEdit->setEnabled(false);
		ui.dateTimeEdit_2->setEnabled(false);
//		ui.comboBox_2->setEnabled(true);
	}
	if(ui.radioButton_2->isChecked())
	{
		ui.dateTimeEdit->setEnabled(true);
		ui.dateTimeEdit_2->setEnabled(true);
//		ui.comboBox_2->setEnabled(false);
	}

}
void ClinicStatistics::on_radioButton_3_clicked()
{
	//if(!ui.radioButton_3->isChecked())
	//{
	//	ui.dateTimeEdit->setEnabled(true);
	//	ui.dateTimeEdit_2->setEnabled(true);
	//	ui.comboBox_2->setEnabled(false);
	//}
	//if(ui.radioButton_3->isChecked())
	//{
	//	ui.comboBox_2->setEnabled(true);
	//	ui.dateTimeEdit->setEnabled(false);
	//	ui.dateTimeEdit_2->setEnabled(false);
	//}

}
void ClinicStatistics::on_queryButton_2_clicked()//门诊日结查询
{
	ui.tableWidget_2->setRowCount(0);
	QString startDate = ui.dateTimeEdit->dateTime().toString("yyyy-MM-dd hh:mm:ss");
	QString endDate = ui.dateTimeEdit_2->dateTime().toString("yyyy-MM-dd hh:mm:ss");

	QSqlQuery query(*sql.db);		
	if(!ui.radioButton_2->isChecked())
	{
		query.exec("select * from mz_dailysummary ");
	}
	if(ui.radioButton_2->isChecked())
	{
		query.exec("select * from mz_dailysummary where makedate between  TIMESTAMP '"+startDate+"' and TIMESTAMP '"+endDate+"'");
	}
	int row= 0;
	while(query.next())
	{	
		ui.tableWidget_2->insertRow(row);
		ui.tableWidget_2->setItem(row,0,new QTableWidgetItem(query.value(1).toString()));
		ui.tableWidget_2->setItem(row,1,new QTableWidgetItem(query.value(2).toDateTime().toString("yyyy-MM-dd hh:mm:ss")));
		ui.tableWidget_2->setItem(row,2,new QTableWidgetItem(query.value(7).toString()));
		ui.tableWidget_2->setItem(row,3,new QTableWidgetItem(query.value(11).toString()));
		ui.tableWidget_2->setItem(row,4,new QTableWidgetItem(query.value(12).toString()));
		row++;
	}
}
void ClinicStatistics::on_clearButton_2_clicked()
{
	ui.tableWidget_2->setRowCount(0);
}
void ClinicStatistics::on_radioButton_4_clicked()
{
	if(!ui.radioButton_4->isChecked())
	{
		ui.dateTimeEdit_5->setEnabled(false);
		ui.dateTimeEdit_6->setEnabled(false);
	}
	if(ui.radioButton_4->isChecked())
	{
		ui.dateTimeEdit_5->setEnabled(true);
		ui.dateTimeEdit_6->setEnabled(true);
	}

}
void ClinicStatistics::on_queryButton_3_clicked()//添加时间约束 项目查询
{
	ui.tableWidget_5->setRowCount(0);
	ui.tableWidget_5->clear();
	QString startDate = ui.dateTimeEdit_5->dateTime().toString("yyyy-MM-dd hh:mm:ss");
	QString endDate = ui.dateTimeEdit_6->dateTime().toString("yyyy-MM-dd hh:mm:ss");


	QDateTime current_date_time = QDateTime::currentDateTime();
	QString strtime = current_date_time.toString("yyyy-MM-dd hh:mm:ss");

	QStringList typelist;
	typelist.append(QString::fromLocal8Bit("名称"));
	QSqlQuery query(*sql.db);
	query.exec("select * from mz_receipt");
	while(query.next())
	{
		typelist.append(query.value(1).toString()+"-"+query.value(2).toString());
	}
	ui.tableWidget_5->setColumnCount(typelist.count());
	ui.tableWidget_5->setHorizontalHeaderLabels(typelist);

	if (ui.comboBox_9->currentIndex()==0)
	{
		ui.tableWidget_5->insertRow(0);
		ui.tableWidget_5->setItem(0,0,new QTableWidgetItem(QString::fromLocal8Bit("门诊收据")));
		for (int i = 1;i<typelist.count();i++)
		{
			QString strType = typelist.at(i);
			QString strsql;
			if (ui.radioButton_4->isChecked())
			{
				strsql ="select * from mz_chargedetail where itemtype='"+strType+"'and date between  TIMESTAMP '"+startDate+"' and TIMESTAMP '"+endDate+"'";
			}
			else
			{
				strsql ="select * from mz_chargedetail where itemtype='"+strType+"' ";
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
	if (ui.comboBox_9->currentIndex()==1)
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
			QString strType = QString::fromLocal8Bit("01-西药费");

			for (int i = 1;i<typelist.count();i++)
			{
				QString strType = typelist.at(i);
				if (ui.radioButton_4->isChecked())
				{
					strsql ="select * from mz_chargedetail where itemtype='"+strType+"'and date between  TIMESTAMP '"+startDate+"' and TIMESTAMP '"+endDate+"'";
				}
				else
				{
					strsql ="select * from mz_chargedetail where itemtype='"+strType+"' ";
				}
				QSqlQuery query(*sql.db);
				query.exec(strsql);
				double totalfee=0.0;
				while(query.next())
				{
					QSqlQuery query2(*sql.db);
					QString strsheetno = query.value(1).toString();
					query2.exec("select * from mz_chargesheet where sheetno ='"+strsheetno+"' and department ='"+strdepartment+"'");
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
	if (ui.comboBox_9->currentIndex()==2)
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
			QString strType = QString::fromLocal8Bit("01-西药费");
			for (int i = 1;i<typelist.count();i++)
			{
				QString strType = typelist.at(i);
				if (ui.radioButton_4->isChecked())
				{
					strsql ="select * from mz_chargedetail where itemtype='"+strType+"'and date between  TIMESTAMP '"+startDate+"' and TIMESTAMP '"+endDate+"'";
				}
				else
				{
					strsql ="select * from mz_chargedetail where itemtype='"+strType+"' ";
				}
				QSqlQuery query(*sql.db);
				query.exec(strsql);
				double totalfee=0.0;
				while(query.next())
				{
					QSqlQuery query2(*sql.db);
					QString strsheetno = query.value(1).toString();
					query2.exec("select * from mz_chargesheet where sheetno ='"+strsheetno+"' and doctor ='"+strpersonnel+"'");
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
	if (ui.comboBox_9->currentIndex()==3)
	{
		typelist.clear();
		QSqlQuery query0(*sql.db);
		ui.tableWidget_5->clear();
		typelist.append(QString::fromLocal8Bit("名称"));
		query0.exec("select * from mz_classification");
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
			ui.tableWidget_5->insertRow(row);
			QString strpersonnel= query0.value(1).toString();
			ui.tableWidget_5->setItem(row,0,new QTableWidgetItem(strpersonnel));
			QString strType = QString::fromLocal8Bit("01-西药费");
			for (int i = 1;i<typelist.count();i++)
			{
				QString strType = typelist.at(i);
				if (ui.radioButton_4->isChecked())
				{
					strsql ="select * from mz_chargedetail where itemclass='"+strType+"'and date between  TIMESTAMP '"+startDate+"' and TIMESTAMP '"+endDate+"'";
				}
				else
				{
					strsql ="select * from mz_chargedetail where itemclass='"+strType+"' ";
				}
				QSqlQuery query(*sql.db);
				query.exec(strsql);
				double totalfee=0.0;
				while(query.next())
				{
					QSqlQuery query2(*sql.db);
					QString strsheetno = query.value(1).toString();
					query2.exec("select * from mz_chargesheet where sheetno ='"+strsheetno+"' and sheetmaker ='"+strpersonnel+"'");
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
void ClinicStatistics::on_clearButton_3_clicked()
{
	ui.tableWidget_5->setRowCount(0);
}
void ClinicStatistics::getItem(int row,int column)
{
	ClinicCharge *charge = new ClinicCharge();
	QString strNo= ui.tableWidget->item(row,10)->text();
	charge->resize(943,575);
	charge->show();
	charge->edit(strNo);
}
void ClinicStatistics::completeText(const QModelIndex &index) {
	QString strName = index.data().toString();
	ui.patientEdit->setText(strName);
	QSqlQuery query(*sql.db);	
	QStringList list;
	QString strsql= QString("select * from mz_chargesheet where patientname = '%1'").arg(strName);
	query.exec(strsql);
	bool Isexist  =false;
	while(query.next())
	{
		ui.lineEdit->setText(query.value(8).toString());
		ui.lineEdit_2->setText(query.value(9).toString());
	}
	listView->hide();
}
void ClinicStatistics::setCompleter(const QString &text) {

	listView->hide();
	if (text.isEmpty()) {
		listView->hide();
		return;
	}

	if ((text.length() > 1) && (!listView->isHidden())) {
		return;
	}

	ui.lineEdit->clear();
	ui.lineEdit_2->clear();
	QSqlQuery query(*sql.db);	
	QStringList list;
	QString strsql= QString("select * from mz_chargesheet where patientname like '%%1%'").arg(text);
	query.exec(strsql);
	bool Isexist  =false;
	while(query.next())
	{

		QString str = query.value(5).toString();
		for (int i=0;i<list.count();i++)
		{
			if(list.at(i)==query.value(5).toString()) 
			{
				Isexist= true;
			}
		}
		if(!Isexist)
			list.append(str);
		Isexist =false;
	}
	model->setStringList(list);
	listView->setModel(model);

	if (model->rowCount() == 0) {
		return;
	}

	// Position the text edit
	listView->setMinimumWidth(width());
	listView->setMaximumWidth(width());

	QPoint p(0, height());
	int x = mapToGlobal(p).x();
	int y = mapToGlobal(p).y() + 1;

	//listView->move(x, y);
	QPoint GlobalPoint(ui.patientEdit->mapToGlobal(QPoint(0, 0)));
	listView->setGeometry(GlobalPoint.x(), GlobalPoint.y()+ui.patientEdit->height(), 50, 100);
	listView->resize(100,200);
	listView->setFixedWidth(ui.patientEdit->width());
	listView->show();
}
void ClinicStatistics::keyPressEvent(QKeyEvent *e) {
	if (!listView->isHidden()) {
		int key = e->key();
		int count = listView->model()->rowCount();
		QModelIndex currentIndex = listView->currentIndex();

		if (Qt::Key_Down == key) {
			// 按向下方向键时，移动光标选中下一个完成列表中的项
			int row = currentIndex.row() + 1;
			if (row >= count) {
				row = 0;
			}

			QModelIndex index = listView->model()->index(row, 0);
			listView->setCurrentIndex(index);
		} else if (Qt::Key_Up == key) {
			// 按向下方向键时，移动光标选中上一个完成列表中的项
			int row = currentIndex.row() - 1;
			if (row < 0) {
				row = count - 1;
			}

			QModelIndex index = listView->model()->index(row, 0);
			listView->setCurrentIndex(index);
		} else if (Qt::Key_Escape == key) {
			// 按下Esc键时，隐藏完成列表
			listView->hide();
		} else if (Qt::Key_Enter == key || Qt::Key_Return == key) {
			// 按下回车键时，使用完成列表中选中的项，并隐藏完成列表
			if (currentIndex.isValid()) {
				QString text = listView->currentIndex().data().toString();
				ui.patientEdit->setText(text);

				QSqlQuery query(*sql.db);	
				QStringList list;
				QString strsql= QString("select * from mz_chargesheet where patientname = '%1'").arg(text);
				query.exec(strsql);
				bool Isexist  =false;
				while(query.next())
				{
					ui.lineEdit->setText(query.value(8).toString());
					ui.lineEdit_2->setText(query.value(9).toString());
				}
			}

			listView->hide();
		} else {
			// 其他情况，隐藏完成列表，并使用QLineEdit的键盘按下事件
			listView->hide();
			//QLineEdit::keyPressEvent(e);
		}
	} else {
		//QLineEdit::keyPressEvent(e);
	}
}
void ClinicStatistics::on_previewButton_clicked()
{
	filePrintPreview();
}
void ClinicStatistics::filePrintPreview()
{
	// 打印预览对话框
	QPrinter             printer( QPrinter::PrinterResolution );
	QPrintPreviewDialog  preview( &printer, this );
	preview.setWindowTitle(QString::fromLocal8Bit("预览"));
	preview.setMinimumSize(800,600);
	connect( &preview, SIGNAL(paintRequested(QPrinter*)), SLOT(print(QPrinter*)) );
	preview.exec();
}
void ClinicStatistics::on_printButton_clicked()
{
	QPrinter       printer( QPrinter::PrinterResolution );
	QPrintDialog   dialog( &printer, this );
	if ( dialog.exec() == QDialog::Accepted ) print( &printer );
}
void ClinicStatistics::print( QPrinter* printer )
{
	QPainter painter( printer );
	int      w = printer->pageRect().width();
	int      h = printer->pageRect().height();
	QRect    page( w/50, h/70, w, h );
	QFont    font = painter.font();
	font.setPointSize(10);
	painter.setFont( font );
	painter.drawText( page, Qt::AlignTop    | Qt::AlignHCenter, QString::fromLocal8Bit(" 三河市燕郊镇卫生院门诊收费明细") );

	QPixmap image;
	font.setPointSize(7);
	painter.setFont( font );
	painter.begin(this);
	painter.setPen(QPen(Qt::black,4,Qt::SolidLine));//设置画笔形式 
	painter.setBrush(QBrush(Qt::white,Qt::SolidPattern));//设置画刷形式 
	int row = ui.tableWidget->rowCount();
	int col = ui.tableWidget->columnCount();
	double cellwidth = (w-1000)/col;
	double cellheight = 160;
	double upmargin = h/50;
	//计算总页数
	int firstpagerow = (h-upmargin)/160;//第一页上方空白为750,下方为50
	int everypagerow = (h-100)/160;//后面每页的空白为100
	int pagecount = 0;
	//xp系统
	if(sql.windowsFlag==QSysInfo::WV_5_1||sql.windowsFlag==QSysInfo::WV_5_0||sql.windowsFlag==QSysInfo::WV_5_2||sql.windowsFlag==QSysInfo::WV_4_0)//判断当前系统
	{
		cellwidth= (w-300)/col;
		cellheight=60;
		upmargin =  h/50;;
		firstpagerow = (h-upmargin)/cellheight;
		everypagerow = (h-20)/cellheight;
	}
	double leftmargin = (w-cellwidth*col-2*cellwidth)/2;
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
			list.append(ui.tableWidget->horizontalHeaderItem(j)->text());
		}
		for (int i=0;i<row;i++)
		{
			for (int j=0;j<col;j++)
			{
				if (ui.tableWidget->item(i,j)==NULL)
				{
					list.append("");
					continue;
				}
				list.append(ui.tableWidget->item(i,j)->text());
			}
		}
		for (int i=0;i<row+1;i++)
		{
			for (int j=0;j<col;j++)
			{	
				if(j==0)
				{
					QRect rect(leftmargin+j*cellwidth,upmargin+cellheight*(i+1),cellwidth,cellheight);
					painter.drawRect(rect);
					painter.drawText( rect, Qt::AlignVCenter    | Qt::AlignHCenter, list.at(i*col+j) );
				}
				else if(j==1)
				{
					double temp = cellwidth*2;
					QRect rect(leftmargin+j*cellwidth,upmargin+cellheight*(i+1),temp,cellheight);
					painter.drawRect(rect);
					painter.drawText( rect, Qt::AlignVCenter    | Qt::AlignHCenter, list.at(i*col+j) );
				}
				else if(j==2)
				{
					double temp = cellwidth*2;
					QRect rect(leftmargin+cellwidth+temp,upmargin+cellheight*(i+1),temp,cellheight);
					painter.drawRect(rect);
					painter.drawText( rect, Qt::AlignVCenter    | Qt::AlignHCenter, list.at(i*col+j) );
				}
				else
				{
					QRect rect(leftmargin+cellwidth*(j+2),upmargin+cellheight*(i+1),cellwidth,cellheight);
					painter.drawRect(rect);
					painter.drawText( rect, Qt::AlignVCenter    | Qt::AlignHCenter, list.at(i*col+j) );//ui.tableWidget->item(i,j)->text()
				}

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
			list.append(ui.tableWidget->horizontalHeaderItem(j)->text());
		}
		for (int i=0;i<firstpagerow;i++)
		{
			for (int j=0;j<col;j++)
			{
				if (ui.tableWidget->item(i,j)==NULL)
				{
					list.append("");
					continue;
				}
				list.append(ui.tableWidget->item(i,j)->text());
			}
		}
		for (int i=0;i<firstpagerow+1;i++)
		{
			for (int j=0;j<col;j++)
			{	
				if(j==0)
				{
					QRect rect(leftmargin+j*cellwidth,upmargin+cellheight*(i+1),cellwidth,cellheight);
					painter.drawRect(rect);
					painter.drawText( rect, Qt::AlignVCenter    | Qt::AlignHCenter, list.at(i*col+j) );
				}
				else if(j==1)
				{
					double temp = cellwidth*2;
					QRect rect(leftmargin+j*cellwidth,upmargin+cellheight*(i+1),temp,cellheight);
					painter.drawRect(rect);
					painter.drawText( rect, Qt::AlignVCenter    | Qt::AlignHCenter, list.at(i*col+j) );
				}
				else if(j==2)
				{
					double temp = cellwidth*2;
					QRect rect(leftmargin+cellwidth+temp,upmargin+cellheight*(i+1),temp,cellheight);
					painter.drawRect(rect);
					painter.drawText( rect, Qt::AlignVCenter    | Qt::AlignHCenter, list.at(i*col+j) );
				}
				else
				{
					QRect rect(leftmargin+cellwidth*(j+2),upmargin+cellheight*(i+1),cellwidth,cellheight);
					painter.drawRect(rect);
					painter.drawText( rect, Qt::AlignVCenter    | Qt::AlignHCenter, list.at(i*col+j) );//ui.tableWidget->item(i,j)->text()
				}
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
					if (ui.tableWidget->item(i,j)==NULL)
					{
						list.append("");
						continue;
					}
					list.append(ui.tableWidget->item(i,j)->text());
				}
			}
			for (int i=0;i<everypagerow;i++)
			{
				for (int j=0;j<col;j++)
				{				
					if(j==0)
					{
						QRect rect(leftmargin+j*cellwidth,upmargin+cellheight*(i+1),cellwidth,cellheight);
						painter.drawRect(rect);
						painter.drawText( rect, Qt::AlignVCenter    | Qt::AlignHCenter, list.at(i*col+j) );
					}
					else if(j==1)
					{
						double temp = cellwidth*2;
						QRect rect(leftmargin+j*cellwidth,upmargin+cellheight*(i+1),temp,cellheight);
						painter.drawRect(rect);
						painter.drawText( rect, Qt::AlignVCenter    | Qt::AlignHCenter, list.at(i*col+j) );
					}
					else if(j==2)
					{
						double temp = cellwidth*2;
						QRect rect(leftmargin+cellwidth+temp,upmargin+cellheight*(i+1),temp,cellheight);
						painter.drawRect(rect);
						painter.drawText( rect, Qt::AlignVCenter    | Qt::AlignHCenter, list.at(i*col+j) );
					}
					else
					{
						QRect rect(leftmargin+cellwidth*(j+2),upmargin+cellheight*(i+1),cellwidth,cellheight);
						painter.drawRect(rect);
						painter.drawText( rect, Qt::AlignVCenter    | Qt::AlignHCenter, list.at(i*col+j) );//ui.tableWidget->item(i,j)->text()
					}
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
				if (ui.tableWidget->item(i,j)==NULL)
				{
					list.append("");
					continue;
				}
				list.append(ui.tableWidget->item(i,j)->text());
			}
		}
		for (int i=0;i<row-firstpagerow-(pagecount-2)*everypagerow;i++)
		{
			for (int j=0;j<col;j++)
			{		
				if(j==0)
				{
					QRect rect(leftmargin+j*cellwidth,upmargin+cellheight*(i+1),cellwidth,cellheight);
					painter.drawRect(rect);
					painter.drawText( rect, Qt::AlignVCenter    | Qt::AlignHCenter, list.at(i*col+j) );
				}
				else if(j==1)
				{
					double temp = cellwidth*2;
					QRect rect(leftmargin+j*cellwidth,upmargin+cellheight*(i+1),temp,cellheight);
					painter.drawRect(rect);
					painter.drawText( rect, Qt::AlignVCenter    | Qt::AlignHCenter, list.at(i*col+j) );
				}
				else if(j==2)
				{
					double temp = cellwidth*2;
					QRect rect(leftmargin+cellwidth+temp,upmargin+cellheight*(i+1),temp,cellheight);
					painter.drawRect(rect);
					painter.drawText( rect, Qt::AlignVCenter    | Qt::AlignHCenter, list.at(i*col+j) );
				}
				else
				{
					QRect rect(leftmargin+cellwidth*(j+2),upmargin+cellheight*(i+1),cellwidth,cellheight);
					painter.drawRect(rect);
					painter.drawText( rect, Qt::AlignVCenter    | Qt::AlignHCenter, list.at(i*col+j) );//ui.tableWidget->item(i,j)->text()
				}
			}
		}
		painter.end();
	}
}
void ClinicStatistics::on_previewButton_2_clicked()
{
	filePrintPreview_2();
}
void ClinicStatistics::filePrintPreview_2()
{
	// 打印预览对话框
	QPrinter             printer( QPrinter::PrinterResolution );
	QPrintPreviewDialog  preview( &printer, this );
	preview.setWindowTitle(QString::fromLocal8Bit("预览"));
	preview.setMinimumSize(800,600);
	connect( &preview, SIGNAL(paintRequested(QPrinter*)), SLOT(print_2(QPrinter*)) );
	preview.exec();
}
void ClinicStatistics::on_printButton_2_clicked()
{
	QPrinter       printer( QPrinter::PrinterResolution );
	QPrintDialog   dialog( &printer, this );
	if ( dialog.exec() == QDialog::Accepted ) print_2( &printer );
}
void ClinicStatistics::print_2( QPrinter* printer )
{
	QPainter painter( printer );
	int      w = printer->pageRect().width();
	int      h = printer->pageRect().height();
	QRect    page( w/50, h/70, w, h );
	QFont    font = painter.font();
	font.setPointSize( 9 );
	painter.setFont( font );
	painter.drawText( page, Qt::AlignTop    | Qt::AlignHCenter, QString::fromLocal8Bit(" 三河市燕郊镇卫生院门诊日结统计") );

	QPixmap image;
	image=image.grabWidget(ui.tableWidget_2,0,0,1000, 1000);
	//	painter.drawPixmap(page4,image);

	painter.begin(this);
	painter.setPen(QPen(Qt::black,4,Qt::SolidLine));//设置画笔形式 
	painter.setBrush(QBrush(Qt::white,Qt::SolidPattern));//设置画刷形式 
	int row = ui.tableWidget_2->rowCount();
	int col = ui.tableWidget_2->columnCount();
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
		upmargin = h/50;
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
			list.append(ui.tableWidget_2->horizontalHeaderItem(j)->text());
		}
		for (int i=0;i<row;i++)
		{
			for (int j=0;j<col;j++)
			{
				if (ui.tableWidget_2->item(i,j)==NULL)
				{
					list.append("");
					continue;
				}
				list.append(ui.tableWidget_2->item(i,j)->text());
			}
		}
		for (int i=0;i<row+1;i++)
		{
			for (int j=0;j<col;j++)
			{
				QRect rect(leftmargin+j*cellwidth,upmargin+cellheight*(i+1),cellwidth,cellheight);
				painter.drawRect(rect);
				painter.drawText( rect, Qt::AlignVCenter    | Qt::AlignHCenter, list.at(i*col+j) );//ui.tableWidget->item(i,j)->text()
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
			list.append(ui.tableWidget_2->horizontalHeaderItem(j)->text());
		}
		for (int i=0;i<firstpagerow;i++)
		{
			for (int j=0;j<col;j++)
			{
				if (ui.tableWidget_2->item(i,j)==NULL)
				{
					list.append("");
					continue;
				}
				list.append(ui.tableWidget_2->item(i,j)->text());
			}
		}
		for (int i=0;i<firstpagerow+1;i++)
		{
			for (int j=0;j<col;j++)
			{
				QRect rect(leftmargin+j*cellwidth,upmargin+cellheight*(i+1),cellwidth,cellheight);
				painter.drawRect(rect);
				painter.drawText( rect, Qt::AlignVCenter    | Qt::AlignHCenter, list.at(i*col+j) );//ui.tableWidget->item(i,j)->text()
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
					if (ui.tableWidget_2->item(i,j)==NULL)
					{
						list.append("");
						continue;
					}
					list.append(ui.tableWidget_2->item(i,j)->text());
				}
			}
			for (int i=0;i<everypagerow;i++)
			{
				for (int j=0;j<col;j++)
				{
					QRect rect(leftmargin+j*cellwidth,50+cellheight*(i),cellwidth,cellheight);
					painter.drawRect(rect);
					painter.drawText( rect, Qt::AlignVCenter    | Qt::AlignHCenter, list.at(i*col+j) );//ui.tableWidget->item(i,j)->text()
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
				if (ui.tableWidget->item(i,j)==NULL)
				{
					list.append("");
					continue;
				}
				list.append(ui.tableWidget_2->item(i,j)->text());
			}
		}
		for (int i=0;i<row-firstpagerow-(pagecount-2)*everypagerow;i++)
		{
			for (int j=0;j<col;j++)
			{
				
				QRect rect(leftmargin+j*cellwidth,50+cellheight*(i+1),cellwidth,cellheight);
				painter.drawRect(rect);
				painter.drawText( rect, Qt::AlignVCenter    | Qt::AlignHCenter, list.at(i*col+j) );//ui.tableWidget->item(i,j)->text()
			}
		}
		painter.end();
	}
}
void ClinicStatistics::on_previewButton_3_clicked()
{
	filePrintPreview_3();
}
void ClinicStatistics::filePrintPreview_3()
{
	// 打印预览对话框
	QPrinter             printer( QPrinter::PrinterResolution );
	QPrintPreviewDialog  preview( &printer, this );
	preview.setWindowTitle(QString::fromLocal8Bit("预览"));
	preview.setMinimumSize(800,600);
	connect( &preview, SIGNAL(paintRequested(QPrinter*)), SLOT(print_3(QPrinter*)) );
	preview.exec();
}
void ClinicStatistics::on_printButton_3_clicked()
{
	QPrinter       printer( QPrinter::PrinterResolution );
	QPrintDialog   dialog( &printer, this );
	if ( dialog.exec() == QDialog::Accepted ) print_3( &printer );
}
void ClinicStatistics::print_3( QPrinter* printer )
{
	QPainter painter( printer );
	int      w = printer->pageRect().width();
	int      h = printer->pageRect().height();
	QRect    page( w/50, h/70, w, h );
	QFont    font = painter.font();
	font.setPointSize( 9 );
	painter.setFont( font );
	painter.drawText( page, Qt::AlignTop    | Qt::AlignHCenter, QString::fromLocal8Bit(" 三河市燕郊镇卫生院项目统计") );

	QPixmap image;
	image=image.grabWidget(ui.tableWidget_2,0,0,1000, 1000);
	//	painter.drawPixmap(page4,image);

	painter.begin(this);
	painter.setPen(QPen(Qt::black,4,Qt::SolidLine));//设置画笔形式 
	painter.setBrush(QBrush(Qt::white,Qt::SolidPattern));//设置画刷形式 
	int row = ui.tableWidget_5->rowCount();
	int col = ui.tableWidget_5->columnCount();
	double cellwidth = (w-100)/col;
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
		upmargin = h/50;
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
			list.append(ui.tableWidget_5->horizontalHeaderItem(j)->text());
		}
		for (int i=0;i<row;i++)
		{
			for (int j=0;j<col;j++)
			{
				if (ui.tableWidget_5->item(i,j)==NULL)
				{
					list.append("");
					continue;
				}
				list.append(ui.tableWidget_5->item(i,j)->text());
			}
		}
		for (int i=0;i<row+1;i++)
		{
			for (int j=0;j<col;j++)
			{
				
				QRect rect(leftmargin+j*cellwidth,upmargin+cellheight*(i+1),cellwidth,cellheight);
				painter.drawRect(rect);
				painter.drawText( rect, Qt::AlignVCenter    | Qt::AlignHCenter, list.at(i*col+j) );//ui.tableWidget->item(i,j)->text()
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
			list.append(ui.tableWidget_5->horizontalHeaderItem(j)->text());
		}
		for (int i=0;i<firstpagerow;i++)
		{
			for (int j=0;j<col;j++)
			{
				if (ui.tableWidget_5->item(i,j)==NULL)
				{
					list.append("");
					continue;
				}
				list.append(ui.tableWidget_5->item(i,j)->text());
			}
		}
		for (int i=0;i<firstpagerow+1;i++)
		{
			for (int j=0;j<col;j++)
			{
				QRect rect(leftmargin+j*cellwidth,50+cellheight*(i),cellwidth,cellheight);
				painter.drawRect(rect);
				painter.drawText( rect, Qt::AlignVCenter    | Qt::AlignHCenter, list.at(i*col+j) );//ui.tableWidget->item(i,j)->text()
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
					if (ui.tableWidget_5->item(i,j)==NULL)
					{
						list.append("");
						continue;
					}
					list.append(ui.tableWidget_5->item(i,j)->text());
				}
			}
			for (int i=0;i<everypagerow;i++)
			{
				for (int j=0;j<col;j++)
				{
					QRect rect(leftmargin+j*cellwidth,50+cellheight*(i),cellwidth,cellheight);
					painter.drawRect(rect);
					painter.drawText( rect, Qt::AlignVCenter    | Qt::AlignHCenter, list.at(i*col+j) );//ui.tableWidget->item(i,j)->text()
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
				if (ui.tableWidget->item(i,j)==NULL)
				{
					list.append("");
					continue;
				}
				list.append(ui.tableWidget_5->item(i,j)->text());
			}
		}
		for (int i=0;i<row-firstpagerow-(pagecount-2)*everypagerow;i++)
		{
			for (int j=0;j<col;j++)
			{
				QRect rect(leftmargin+j*cellwidth,50+cellheight*(i+1),cellwidth,cellheight);
				painter.drawRect(rect);
				painter.drawText( rect, Qt::AlignVCenter    | Qt::AlignHCenter, list.at(i*col+j) );//ui.tableWidget->item(i,j)->text()
			}
		}
		painter.end();
	}
}
ClinicStatistics::~ClinicStatistics()
{

}
