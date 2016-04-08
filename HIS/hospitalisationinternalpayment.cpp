#include "hospitalisationinternalpayment.h"
#include <QtGui>
#include "connectsql.h"
#include "odbcexcel.h"
#include "capital.h"
extern ConnectSql sql;
HospitalisationInternalPayment::HospitalisationInternalPayment(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	initUI();
	ui.tableWidget->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
	ui.tableWidget->setStyleSheet("QTableWidget{border: 2px solid gray;	background-color: transparent;	selection-color: white;}");
	ui.tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section {background-color:white;color: black;padding-left: 4px;border: 1px solid #6c6c6c;};"
		"color: white;padding-left: 4px;border: 1px solid #6c6c6c;}"
		"QHeaderView::section:checked{background-color: white;color: black;}");	
}
void HospitalisationInternalPayment::initUI()
{
	QDateTime current_date_time = QDateTime::currentDateTime();
	ui.dateTimeEdit->setDateTime(current_date_time);
	QTime time= QTime::fromString("00:00:00", "hh:mm:ss");
	ui.dateTimeEdit->setTime(time);
	ui.dateTimeEdit_2->setDateTime(current_date_time);
	time= QTime::fromString("23:59:59", "hh:mm:ss");
	ui.dateTimeEdit_2->setTime(time);
}
void HospitalisationInternalPayment::on_printButton_clicked()
{
	QPrinter       printer( QPrinter::PrinterResolution );
	QPrintDialog   dialog( &printer, this );
	if ( dialog.exec() == QDialog::Accepted ) print( &printer );
}
void HospitalisationInternalPayment::on_previewButton_clicked()
{
	filePrintPreview();
}
void HospitalisationInternalPayment::on_excelButton_clicked()
{
	QAbstractItemModel* model=ui.tableWidget->model();
	if (model->rowCount()==0||model==NULL)
	{
		QString str = str.fromLocal8Bit("提示");
		QString str2 = str.fromLocal8Bit("无数据");
		QMessageBox box(QMessageBox::Warning,QString::fromLocal8Bit("警告"),str2);
		box.setStandardButtons (QMessageBox::Ok);
		box.setButtonText (QMessageBox::Ok,QString::fromLocal8Bit("确 定"));
		box.exec();
		return;
	}

	QFileDialog dlg;
	dlg.setAcceptMode(QFileDialog::AcceptSave);

	dlg.setDirectory(QDesktopServices::storageLocation(QDesktopServices::DesktopLocation));
	dlg.setNameFilter("*.xls");
	dlg.selectFile(QDate::currentDate().toString("yyyy-MM-dd.xls"));
	if(dlg.exec()!= QDialog::Accepted)
		return;
	QString filePath=dlg.selectedFiles()[0];
	if(OdbcExcel::saveFromTable(filePath,ui.tableWidget,"")) {
		QString str = str.fromLocal8Bit("提示");
		QString str2 = str.fromLocal8Bit("保存成功");
		QMessageBox box(QMessageBox::Warning,QString::fromLocal8Bit("警告"),str2);
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
void HospitalisationInternalPayment::on_queryButton_clicked()
{
	QString startDate = ui.dateTimeEdit->dateTime().toString("yyyy-MM-dd hh:mm:ss");
	QString endDate = ui.dateTimeEdit_2->dateTime().toString("yyyy-MM-dd hh:mm:ss");
	
	QStringList typelist;
	typelist.append(QString::fromLocal8Bit("01-床位费B"));
	typelist.append(QString::fromLocal8Bit("02-诊查费C"));
	typelist.append(QString::fromLocal8Bit("03-护理费F"));
	typelist.append(QString::fromLocal8Bit("04-手术费G"));
	typelist.append(QString::fromLocal8Bit("05-挂号费A"));
	typelist.append(QString::fromLocal8Bit("06-治疗费E"));
	typelist.append(QString::fromLocal8Bit("09-西药费"));
	typelist.append(QString::fromLocal8Bit("10-检查费D"));
	typelist.append(QString::fromLocal8Bit("12-其他费I"));
	typelist.append(QString::fromLocal8Bit("13-中成药费"));
	typelist.append(QString::fromLocal8Bit("14-化验费H"));
	typelist.append(QString::fromLocal8Bit("17-材料费"));

	QSqlQuery query(*sql.db);
	QString strsql;
	double tempfee=0.0;
	for (int i = 0;i<typelist.count();i++)
	{
		QString strType = typelist.at(i);
		strsql ="select * from zy_chargedetail where itemtype='"+strType+"'and date between  TIMESTAMP '"+startDate+"' and TIMESTAMP '"+endDate+"'";
		query.exec(strsql);
		double totalfee=0.0;
		while(query.next())
		{
			totalfee+=query.value(8).toDouble();	
		}
		tempfee+=totalfee;
		ui.tableWidget->setItem(i,1,new QTableWidgetItem(QString::number(totalfee)));
	}
	ui.tableWidget->setItem(12,1,new QTableWidgetItem(QString::number(tempfee)));
}
void HospitalisationInternalPayment::filePrintPreview()
{
	// 打印预览对话框
	QPrinter             printer( QPrinter::PrinterResolution );
	QPrintPreviewDialog  preview( &printer, this );
	preview.setWindowTitle("preview");
	connect( &preview, SIGNAL(paintRequested(QPrinter*)), SLOT(print(QPrinter*)) );
	preview.exec();
}
void HospitalisationInternalPayment::print( QPrinter* printer )
{
	QPainter painter( printer );
	int      w = printer->pageRect().width();
	int      h = printer->pageRect().height();
	QRect    page( 0, h/70, w, h );
	QRect    page2(0, h/35, w, h );
	QFont    font = painter.font();
	font.setPointSize(9);
	painter.setFont( font );
	painter.drawText( page, Qt::AlignTop    | Qt::AlignHCenter, QString::fromLocal8Bit("三河市燕郊镇卫生院住院内部缴款单") );
    QString str =QString::fromLocal8Bit("日期:")+ ui.dateTimeEdit->dateTime().toString("yyyy-MM-dd hh:mm:ss")+"-"+ui.dateTimeEdit_2 ->dateTime().toString("yyyy-MM-dd hh:mm:ss");
	painter.drawText( page2, Qt::AlignTop    | Qt::AlignHCenter, str );

	painter.begin(this);
	painter.setPen(QPen(Qt::black,4,Qt::SolidLine));//设置画笔形式 
	painter.setBrush(QBrush(Qt::white,Qt::SolidPattern));//设置画刷形式 
	int row = ui.tableWidget->rowCount();
	int col = ui.tableWidget->columnCount();
	double cellwidth;
	double cellheight;
	double upmargin;
	if(sql.windowsFlag==QSysInfo::WV_5_1||sql.windowsFlag==QSysInfo::WV_5_0||sql.windowsFlag==QSysInfo::WV_5_2||sql.windowsFlag==QSysInfo::WV_4_0)//判断当前系统
	{
		cellwidth=400;
		cellheight=45;
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
			painter.drawRect(leftmargin+j*cellwidth,upmargin+cellheight*(i+1),cellwidth,cellheight);
			QRect rect(leftmargin+j*cellwidth,upmargin+cellheight*(i+1),cellwidth,cellheight);
			painter.drawText( rect, Qt::AlignVCenter    | Qt::AlignHCenter, list.at(i*col+j) );//ui.billtableWidget->item(i,j)->text()
		}
	}
	painter.drawRect(leftmargin,upmargin+cellheight*(row+2),cellwidth*col,cellheight);
	QRect rect(leftmargin,upmargin+cellheight*(row+2),cellwidth*col,cellheight);

	Capital*capital = new Capital;
	if (ui.tableWidget->item(row-1,1)==NULL)
	{
		return;
	}
	double sum = ui.tableWidget->item(row-1,1)->text().toDouble();
	
	painter.drawText( rect, Qt::AlignVCenter    | Qt::AlignLeft, QString::fromLocal8Bit("大写：")+capital->NumToChineseStr(sum));//ui.billtableWidget->item(i,j)->text()
	
	QRect rect2(leftmargin,upmargin+cellheight*(row+3),cellwidth*col,cellheight);
	painter.drawText( rect2, Qt::AlignVCenter    | Qt::AlignLeft, QString::fromLocal8Bit("会计主管：")+"                "+ QString::fromLocal8Bit("收费负责人：")+"                "+ QString::fromLocal8Bit("药房负责人："));//ui.billtableWidget->item(i,j)->text()

	painter.end();
}
HospitalisationInternalPayment::~HospitalisationInternalPayment()
{

}
