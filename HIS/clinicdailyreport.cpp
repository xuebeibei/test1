#include "clinicdailyreport.h"
#include "connectsql.h"
extern ConnectSql sql;
ClinicDailyReport::ClinicDailyReport(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	ui.tableWidget->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
	ui.tableWidget->setStyleSheet("QTableWidget{border: 1px solid gray;	background-color: transparent;	selection-color: white;}");
	ui.tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section {background-color:white;color: black;padding-left: 4px;border: 1px solid #6c6c6c;};"
		"color: white;padding-left: 4px;border: 1px solid #6c6c6c;}"
		"QHeaderView::section:checked{background-color: white;color: black;}");	
	ui.tableWidget->installEventFilter(this);
	installEventFilter(this);
	initUI();
}
void ClinicDailyReport::initUI()
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
	ui.queryButton->setEnabled(false);
	ui.saveButton->setEnabled(false);
	ui.deleteButton->setEnabled(false);
	ui.editButton->setEnabled(false);
}
int  ClinicDailyReport::sheetNo()
{
	QSqlQuery query(*sql.db);		
	query.exec("select * from mz_dailysummary");
	int isheetcount=0;
	isheetcount=0;
	while(query.next())
	{
		isheetcount=query.value(0).toInt();
	}
	return isheetcount;
}
void ClinicDailyReport::on_saveButton_clicked()
{
	QSqlQuery query(*sql.db);
	int rows = ui.tableWidget->model()->rowCount();   //������

	if ( ui.tableWidget->item(0,0)==NULL) return;
	int isheetcount=sheetNo();
	isheetcount++;
	query.prepare("INSERT INTO mz_dailysummary VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)");
	query.bindValue(0, isheetcount);
	query.bindValue(1, ui.sheetNoEdit->text());
	query.bindValue(2, ui.makedateTimeEdit->dateTime());
	query.bindValue(3, NULL);//ui.casherEdit->text()
	query.bindValue(4,ui.startdateTimeEdit->dateTime());
	query.bindValue(5, ui.endateTimeEdit->dateTime() );
	query.bindValue(6,"");//
	query.bindValue(7, ui.sheetmakerEdit->text());
	query.bindValue(8, "");//���
	query.bindValue(9, "");//��Ʊ����
	query.bindValue(10, "");
	query.bindValue(11, ui.tableWidget->item(rows-1,2)->text().toDouble());
	query.bindValue(12, ui.tableWidget->item(rows-1,3)->text().toDouble());
	query.bindValue(13, ui.tableWidget->item(rows-1,4)->text().toDouble());	
	if(query.exec())
	{
		QMessageBox box(QMessageBox::Warning,QString::fromLocal8Bit("��ʾ"),QString::fromLocal8Bit("����ɹ�"));
		box.setStandardButtons (QMessageBox::Ok);
		box.setButtonText (QMessageBox::Ok,QString::fromLocal8Bit("ȷ ��"));
		box.exec();
		ui.discardButton->setEnabled(false);
		ui.queryButton->setEnabled(false);
		ui.saveButton->setEnabled(false);
		ui.editButton->setEnabled(true);
	}
}
void ClinicDailyReport::on_discardButton_clicked()
{
	ui.sheetNoEdit->setText("");
	ui.tableWidget->setRowCount(0);
	ui.tableWidget->clearContents();
}
void ClinicDailyReport::on_addButton_clicked()
{
	ui.discardButton->setEnabled(true);
	ui.queryButton->setEnabled(true);
	ui.saveButton->setEnabled(true);
	int isheetcount=sheetNo();
	isheetcount++;
	QString strSheetNo= "MZRJ"+QString::number(isheetcount, 10);
	ui.sheetNoEdit->setText(strSheetNo);
}
void ClinicDailyReport::on_queryButton_clicked()
{
	ui.tableWidget->setRowCount(0);
	ui.tableWidget->clearContents();
	QString startDate = ui.startdateTimeEdit->dateTime().toString("yyyy-MM-dd hh:mm:ss");
	QString endDate = ui.endateTimeEdit->dateTime().toString("yyyy-MM-dd hh:mm:ss");
	QSqlQuery query(*sql.db);		
	query.exec("select * from mz_chargesheet where date between  TIMESTAMP '"+startDate+"' and TIMESTAMP '"+endDate+"'");
	QStringList list;
	int irowCount=0;
	double totaldueincome=0.0;
	double totalrealincome=0.0;
	double dueincome=0.0;
	double realincome=0.0;
	while(query.next())
	{
		ui.tableWidget->insertRow(irowCount);
		QString str = query.value(1).toString();
		ui.tableWidget->setItem(irowCount,0,new QTableWidgetItem(str));
		str = query.value(2).toDateTime().toString("yyyy-MM-dd hh:mm:ss");
		ui.tableWidget->setItem(irowCount,1,new QTableWidgetItem(str));
		str = query.value(13).toString();
		totaldueincome+=query.value(13).toDouble();
		dueincome=query.value(13).toDouble();
		ui.tableWidget->setItem(irowCount,2,new QTableWidgetItem(str));
		str = query.value(14).toString();
		totalrealincome+=query.value(14).toDouble();
		realincome=query.value(14).toDouble();
		ui.tableWidget->setItem(irowCount,3,new QTableWidgetItem(str));
		ui.tableWidget->setItem(irowCount,4,new QTableWidgetItem(QString::number(dueincome-realincome)));
		ui.tableWidget->setItem(irowCount,5,new QTableWidgetItem(query.value(13).toString()));
		irowCount++;
	}
	ui.tableWidget->insertRow(irowCount);
	ui.tableWidget->setItem(irowCount,0,new QTableWidgetItem(QString::fromLocal8Bit("�ϼ�")));
	ui.tableWidget->setItem(irowCount,2,new QTableWidgetItem(QString::number(totaldueincome)));
	ui.tableWidget->setItem(irowCount,3,new QTableWidgetItem(QString::number(totalrealincome)));
	ui.tableWidget->setItem(irowCount,4,new QTableWidgetItem(QString::number(totaldueincome-totalrealincome)));
}
void ClinicDailyReport::on_editButton_clicked()
{
	ui.deleteButton->setEnabled(true);
	ui.saveButton->setEnabled(true);
	ui.discardButton->setEnabled(true);
}
void ClinicDailyReport::on_deleteButton_clicked()
{
	QSqlQuery query(*sql.db);		
	QString strSheetNo=ui.sheetNoEdit->text();
	QString strsql = "delete from mz_dailysummary where sheetno ='"+strSheetNo+"'"; 
	query.exec(strsql);
	on_discardButton_clicked();
	ui.saveButton->setEnabled(false);
	ui.editButton->setEnabled(false);
	ui.discardButton->setEnabled(false);
	ui.deleteButton->setEnabled(false);
}
bool ClinicDailyReport::eventFilter(QObject*obj,QEvent*event)
{
	if(obj == this)
	{
		if(event->type() == QEvent::KeyPress)
		{
			QKeyEvent*keyEvent=static_cast<QKeyEvent*>(event);//���¼�ת��Ϊ�����¼�
			if(keyEvent->key() == Qt::Key_Return)
			{
				focusNextChild();
				return true;
			}
		}
	}
}
void ClinicDailyReport::filePrintPreview()
{
	// ��ӡԤ���Ի���
	QPrinter             printer( QPrinter::PrinterResolution );
	QPrintPreviewDialog  preview( &printer, this );
	preview.setWindowTitle(QString::fromLocal8Bit("Ԥ��"));
	connect( &preview, SIGNAL(paintRequested(QPrinter*)), SLOT(print(QPrinter*)) );
	preview.exec();
}
void ClinicDailyReport::print( QPrinter* printer )
{
	QPainter painter( printer );
	int      w = printer->pageRect().width();
	int      h = printer->pageRect().height();
	QRect    page( 0, h/70, w, h );
	QRect    page2(0, h/35, w, h );
	QFont    font = painter.font();
	font.setPointSize(9);
	painter.setFont( font );
	painter.drawText( page, Qt::AlignTop    | Qt::AlignHCenter, QString::fromLocal8Bit("�������ོ������Ժ�����սᵥ") );
	QString str =QString::fromLocal8Bit("����:")+ ui.startdateTimeEdit->dateTime().toString("yyyy-MM-dd hh:mm:ss")+"-"+ui.endateTimeEdit ->dateTime().toString("yyyy-MM-dd hh:mm:ss")+QString::fromLocal8Bit("     �Ƶ�:")+ ui.sheetmakerEdit->text();
	painter.drawText( page2, Qt::AlignTop    | Qt::AlignHCenter, str );

	painter.begin(this);
	painter.setPen(QPen(Qt::black,4,Qt::SolidLine));//���û�����ʽ 
	painter.setBrush(QBrush(Qt::white,Qt::SolidPattern));//���û�ˢ��ʽ 
	int row = ui.tableWidget->rowCount();
	int col = ui.tableWidget->columnCount();
	double cellwidth = (w-100)/col;
	double cellheight = 160;
	double upmargin = h/30;

	//������ҳ��
	int firstpagerow = (h-upmargin)/160;
	int everypagerow = (h-100)/160;
	int pagecount = 0;
	if(sql.windowsFlag==QSysInfo::WV_5_1||sql.windowsFlag==QSysInfo::WV_5_0||sql.windowsFlag==QSysInfo::WV_5_2||sql.windowsFlag==QSysInfo::WV_4_0)//�жϵ�ǰϵͳ
	{
		cellwidth= (w-100)/col;
		cellheight=60;
		upmargin = h/35;
		firstpagerow = (h-upmargin)/cellheight;//��һҳ�Ϸ��հ�Ϊ750,�·�Ϊ50
		everypagerow = (h-50)/cellheight;//����ÿҳ�Ŀհ�Ϊ100
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
				QRect rect(leftmargin+j*cellwidth,upmargin+cellheight*(i+1),cellwidth,cellheight);
				painter.drawRect(rect);
				painter.drawText( rect, Qt::AlignVCenter    | Qt::AlignHCenter, list.at(i*col+j) );//ui.tableWidget->item(i,j)->text()
			}
		}
		painter.end();
	}
	else
	{
		//��ҳ
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
				QRect rect(leftmargin+j*cellwidth,upmargin+cellheight*(i+1),cellwidth,cellheight);
				painter.drawRect(rect);
				painter.drawText( rect, Qt::AlignVCenter    | Qt::AlignHCenter, list.at(i*col+j) );//ui.tableWidget->item(i,j)->text()
			}
		}
		printer->newPage();
		//ռ����ҳ��
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
				list.append(ui.tableWidget->item(i,j)->text());
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
void ClinicDailyReport::on_printButton_clicked()
{
	QPrinter       printer( QPrinter::PrinterResolution );
	QPrintDialog   dialog( &printer, this );
	if ( dialog.exec() == QDialog::Accepted ) print( &printer );
}
void ClinicDailyReport::on_previewButton_clicked()
{
	filePrintPreview();
}
ClinicDailyReport::~ClinicDailyReport()
{

}
