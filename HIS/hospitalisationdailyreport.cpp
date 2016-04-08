#include "hospitalisationdailyreport.h"
#include "connectsql.h"
extern ConnectSql sql;
Hospitalisationdailyreport::Hospitalisationdailyreport(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	ui.dailyreporttableWidget->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
	ui.dailyreporttableWidget->setStyleSheet("QTableWidget{border: 1px solid gray;	background-color: transparent;	selection-color: white;}");
	ui.dailyreporttableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section {background-color:white;color: black;padding-left: 4px;border: 1px solid #6c6c6c;};"
		"color: white;padding-left: 4px;border: 1px solid #6c6c6c;}"
		"QHeaderView::section:checked{background-color: white;color: black;}");	
	initUI();
}
void Hospitalisationdailyreport::initUI()
{
	ui.sheetmakerEdit->setEnabled(false);
	ui.sheetmakerEdit->setText(sql.struser);
	QDateTime current_date_time = QDateTime::currentDateTime();
	ui.makedateTimeEdit->setDateTime(current_date_time);

	ui.startdateTimeEdit->setDateTime(current_date_time);
	QTime time= QTime::fromString("00:00:00", "hh:mm:ss");
	ui.startdateTimeEdit->setTime(time);
	ui.endateTimeEdit->setDateTime(current_date_time);
	time= QTime::fromString("23:59:59", "hh:mm:ss");
	ui.endateTimeEdit->setTime(time);

	ui.discardButton->setEnabled(false);
	ui.dailyreportqueryButton->setEnabled(false);
	ui.saveButton->setEnabled(false);
	ui.deleteButton->setEnabled(false);
	ui.editButton->setEnabled(false);
}
void Hospitalisationdailyreport:: on_addButton_clicked()
{
	on_discardButton_clicked();
	ui.discardButton->setEnabled(true);
	ui.dailyreportqueryButton->setEnabled(true);
	ui.saveButton->setEnabled(true);
	QSqlQuery query(*sql.db);		
	query.exec("select * from zy_dailysummary");
	int icount=0;
	while(query.next())
	{
		icount++;
	}
	int itotalcount=icount+1;
	QString strSheetNo= "ZYRJ"+QString::number(itotalcount, 10);
	ui.sheetNoEdit->setText(strSheetNo);
	ui.saveButton->setEnabled(true);
}
void Hospitalisationdailyreport:: on_saveButton_clicked()
{
	if (ui.dailyreporttableWidget->item(0,0)==NULL) return;
	QSqlQuery query(*sql.db);		
	QString strSheetNo=ui.sheetNoEdit->text();
	QString strsql = "delete from zy_dailysummary where sheetno ='"+strSheetNo+"'"; //where ID > 1
	query.exec(strsql);
	int rows = ui.dailyreporttableWidget->model()->rowCount();
	query.exec("select * from zy_dailysummary");
	int isheetcount=0;
	while(query.next())
	{
		isheetcount=query.value(0).toInt();
	}
	isheetcount++;
	query.prepare("INSERT INTO zy_dailysummary VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)");
	query.bindValue(0, isheetcount);
	query.bindValue(1, ui.sheetNoEdit->text());
	query.bindValue(2, ui.makedateTimeEdit->dateTime());
	query.bindValue(3, ui.casherEdit->text());
	query.bindValue(4,ui.startdateTimeEdit->dateTime());
	query.bindValue(5, ui.endateTimeEdit->dateTime() );
	query.bindValue(6,"");//
	query.bindValue(7, ui.sheetmakerEdit->text());
	query.bindValue(8, "");//审核
	query.bindValue(9, "");//开票日期
	query.bindValue(10, "");
	query.bindValue(11, ui.dailyreporttableWidget->item(rows-1,2)->text().toDouble());
	if(query.exec())
	{
	//	QMessageBox::information(this,QString::fromLocal8Bit("提示"),QString::fromLocal8Bit("保存成功！"));
		ui.editButton->setEnabled(true);
		ui.discardButton->setEnabled(false);
		ui.dailyreportqueryButton->setEnabled(false);
		ui.saveButton->setEnabled(false);
	}
}
void Hospitalisationdailyreport:: on_discardButton_clicked()
{
	ui.sheetNoEdit->setText("");
	ui.dailyreporttableWidget->setRowCount(0);
}
void Hospitalisationdailyreport:: on_dailyreportqueryButton_clicked()
{
	ui.dailyreporttableWidget->setRowCount(0);
	QString startDate = ui.startdateTimeEdit->dateTime().toString("yyyy-MM-dd hh:mm:ss");
	QString endDate = ui.endateTimeEdit->dateTime().toString("yyyy-MM-dd hh:mm:ss");
	QSqlQuery query(*sql.db);		
	query.exec("select * from zy_chargesheet where date between  TIMESTAMP '"+startDate+"' and TIMESTAMP '"+endDate+"'");
	int irowCount=0;
	double totaldueincome=0.0;
	while(query.next())
	{
		ui.dailyreporttableWidget->insertRow(irowCount);
		QString str = query.value(1).toString();
		ui.dailyreporttableWidget->setItem(irowCount,0,new QTableWidgetItem(str));
		str = query.value(2).toDateTime().toString("yyyy-MM-dd hh:mm:ss");
		ui.dailyreporttableWidget->setItem(irowCount,1,new QTableWidgetItem(str));
		str = query.value(14).toString();
		ui.dailyreporttableWidget->setItem(irowCount,2,new QTableWidgetItem(str));
		str = query.value(12).toString();
		totaldueincome+=query.value(14).toDouble();
		ui.dailyreporttableWidget->setItem(irowCount,3,new QTableWidgetItem(str));
		irowCount++;
	}
	ui.dailyreporttableWidget->insertRow(irowCount);
	ui.dailyreporttableWidget->setItem(irowCount,0,new QTableWidgetItem(QString::fromLocal8Bit("合计")));
	ui.dailyreporttableWidget->setItem(irowCount,2,new QTableWidgetItem(QString::number(totaldueincome)));
}
void Hospitalisationdailyreport:: on_editButton_clicked()
{
	ui.deleteButton->setEnabled(true);
	ui.saveButton->setEnabled(true);
	ui.discardButton->setEnabled(true);
}
void Hospitalisationdailyreport:: on_deleteButton_clicked()
{
	QSqlQuery query(*sql.db);		
	QString strSheetNo=ui.sheetNoEdit->text();
	QString strsql = "delete from zy_dailysummary where sheetno ='"+strSheetNo+"'"; //where ID > 1
	query.exec(strsql);
	on_discardButton_clicked();
	ui.saveButton->setEnabled(false);
	ui.editButton->setEnabled(false);
	ui.discardButton->setEnabled(false);
	ui.deleteButton->setEnabled(false);
}
void Hospitalisationdailyreport::filePrintPreview()
{
	// 打印预览对话框
	QPrinter             printer( QPrinter::PrinterResolution );
	QPrintPreviewDialog  preview( &printer, this );
	preview.setWindowTitle(QString::fromLocal8Bit("预览"));
	connect( &preview, SIGNAL(paintRequested(QPrinter*)), SLOT(print(QPrinter*)) );
	preview.exec();
}
void Hospitalisationdailyreport::print( QPrinter* printer )
{
	QPainter painter( printer );
	int      w = printer->pageRect().width();
	int      h = printer->pageRect().height();
	QRect    page( 0, h/16, w, h );
	QRect    page2(0, h/12, w, h );
	QRect    page3( w/4, h/6, w, h );
	QRect    page4( 0, h/10, w, h );
	QFont    font = painter.font();
	font.setPixelSize( (w+h) / 100 );
	painter.setFont( font );
	painter.drawText( page, Qt::AlignTop    | Qt::AlignHCenter, QString::fromLocal8Bit("三河市燕郊镇卫生院住院日结单") );
	QString str =QString::fromLocal8Bit("日期:")+ ui.startdateTimeEdit->dateTime().toString("yyyy-MM-dd hh:mm:ss")+"-"+ui.endateTimeEdit ->dateTime().toString("yyyy-MM-dd hh:mm:ss");
	painter.drawText( page2, Qt::AlignTop    | Qt::AlignHCenter, str );

	painter.begin(this);
	painter.setPen(QPen(Qt::black,4,Qt::SolidLine));//设置画笔形式 
	painter.setBrush(QBrush(Qt::white,Qt::SolidPattern));//设置画刷形式 
	int row = ui.dailyreporttableWidget->rowCount();
	int col = ui.dailyreporttableWidget->columnCount();

	double cellwidth = (w-100)/col;
	double cellheight = 160;
	double upmargin = 600;


	//计算总页数
	int firstpagerow = (h-800)/160;//第一页上方空白为750,下方为50
	int everypagerow = (h-100)/160;//后面每页的空白为100
	int pagecount = 0;
	if(sql.windowsFlag==QSysInfo::WV_5_1||sql.windowsFlag==QSysInfo::WV_5_0||sql.windowsFlag==QSysInfo::WV_5_2||sql.windowsFlag==QSysInfo::WV_4_0)//判断当前系统
	{
		cellwidth= (w-100)/col;
		cellheight=60;
		upmargin = 200;
		firstpagerow = (h-200)/cellheight;//第一页上方空白为750,下方为50
		everypagerow = (h-50)/cellheight;//后面每页的空白为100
	}
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
			list.append(ui.dailyreporttableWidget->horizontalHeaderItem(j)->text());
		}
		for (int i=0;i<row;i++)
		{
			for (int j=0;j<col;j++)
			{
				if (ui.dailyreporttableWidget->item(i,j)==NULL)
				{
					list.append("");
					continue;
				}
				list.append(ui.dailyreporttableWidget->item(i,j)->text());
			}
		}
		for (int i=0;i<row+1;i++)
		{
			for (int j=0;j<col;j++)
			{
				QRect rect(20+j*cellwidth,upmargin+cellheight*(i+1),cellwidth,cellheight);
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
			list.append(ui.dailyreporttableWidget->horizontalHeaderItem(j)->text());
		}
		for (int i=0;i<firstpagerow;i++)
		{
			for (int j=0;j<col;j++)
			{
				if (ui.dailyreporttableWidget->item(i,j)==NULL)
				{
					list.append("");
					continue;
				}
				list.append(ui.dailyreporttableWidget->item(i,j)->text());
			}
		}
		for (int i=0;i<firstpagerow+1;i++)
		{
			for (int j=0;j<col;j++)
			{
				QRect rect(20+j*cellwidth,upmargin+cellheight*(i+1),cellwidth,cellheight);
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
					if (ui.dailyreporttableWidget->item(i,j)==NULL)
					{
						list.append("");
						continue;
					}
					list.append(ui.dailyreporttableWidget->item(i,j)->text());
				}
			}
			for (int i=0;i<everypagerow;i++)
			{
				for (int j=0;j<col;j++)
				{
					QRect rect(20+j*cellwidth,50+cellheight*(i),cellwidth,cellheight);
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
				if (ui.dailyreporttableWidget->item(i,j)==NULL)
				{
					list.append("");
					continue;
				}
				list.append(ui.dailyreporttableWidget->item(i,j)->text());
			}
		}
		for (int i=0;i<row-firstpagerow-(pagecount-2)*everypagerow;i++)
		{
			for (int j=0;j<col;j++)
			{

				QRect rect(20+j*cellwidth,50+cellheight*(i+1),cellwidth,cellheight);
				painter.drawRect(rect);
				painter.drawText( rect, Qt::AlignVCenter    | Qt::AlignHCenter, list.at(i*col+j) );//ui.tableWidget->item(i,j)->text()
			}
		}
		painter.end();
	}
}
void Hospitalisationdailyreport::on_printButton_clicked()
{
	QPrinter       printer( QPrinter::PrinterResolution );
	QPrintDialog   dialog( &printer, this );
	if ( dialog.exec() == QDialog::Accepted ) print( &printer );
}
void Hospitalisationdailyreport::on_previewButton_clicked()
{
	filePrintPreview();
}
Hospitalisationdailyreport::~Hospitalisationdailyreport()
{

}
