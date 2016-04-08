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
		QString str = str.fromLocal8Bit("��ʾ");
		QString str2 = str.fromLocal8Bit("������");
		QMessageBox box(QMessageBox::Warning,QString::fromLocal8Bit("����"),str2);
		box.setStandardButtons (QMessageBox::Ok);
		box.setButtonText (QMessageBox::Ok,QString::fromLocal8Bit("ȷ ��"));
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
		QString str = str.fromLocal8Bit("��ʾ");
		QString str2 = str.fromLocal8Bit("����ɹ�");
		QMessageBox box(QMessageBox::Warning,QString::fromLocal8Bit("����"),str2);
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
void HospitalisationInternalPayment::on_queryButton_clicked()
{
	QString startDate = ui.dateTimeEdit->dateTime().toString("yyyy-MM-dd hh:mm:ss");
	QString endDate = ui.dateTimeEdit_2->dateTime().toString("yyyy-MM-dd hh:mm:ss");
	
	QStringList typelist;
	typelist.append(QString::fromLocal8Bit("01-��λ��B"));
	typelist.append(QString::fromLocal8Bit("02-����C"));
	typelist.append(QString::fromLocal8Bit("03-�����F"));
	typelist.append(QString::fromLocal8Bit("04-������G"));
	typelist.append(QString::fromLocal8Bit("05-�Һŷ�A"));
	typelist.append(QString::fromLocal8Bit("06-���Ʒ�E"));
	typelist.append(QString::fromLocal8Bit("09-��ҩ��"));
	typelist.append(QString::fromLocal8Bit("10-����D"));
	typelist.append(QString::fromLocal8Bit("12-������I"));
	typelist.append(QString::fromLocal8Bit("13-�г�ҩ��"));
	typelist.append(QString::fromLocal8Bit("14-�����H"));
	typelist.append(QString::fromLocal8Bit("17-���Ϸ�"));

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
	// ��ӡԤ���Ի���
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
	painter.drawText( page, Qt::AlignTop    | Qt::AlignHCenter, QString::fromLocal8Bit("�������ོ������ԺסԺ�ڲ��ɿ") );
    QString str =QString::fromLocal8Bit("����:")+ ui.dateTimeEdit->dateTime().toString("yyyy-MM-dd hh:mm:ss")+"-"+ui.dateTimeEdit_2 ->dateTime().toString("yyyy-MM-dd hh:mm:ss");
	painter.drawText( page2, Qt::AlignTop    | Qt::AlignHCenter, str );

	painter.begin(this);
	painter.setPen(QPen(Qt::black,4,Qt::SolidLine));//���û�����ʽ 
	painter.setBrush(QBrush(Qt::white,Qt::SolidPattern));//���û�ˢ��ʽ 
	int row = ui.tableWidget->rowCount();
	int col = ui.tableWidget->columnCount();
	double cellwidth;
	double cellheight;
	double upmargin;
	if(sql.windowsFlag==QSysInfo::WV_5_1||sql.windowsFlag==QSysInfo::WV_5_0||sql.windowsFlag==QSysInfo::WV_5_2||sql.windowsFlag==QSysInfo::WV_4_0)//�жϵ�ǰϵͳ
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
	
	painter.drawText( rect, Qt::AlignVCenter    | Qt::AlignLeft, QString::fromLocal8Bit("��д��")+capital->NumToChineseStr(sum));//ui.billtableWidget->item(i,j)->text()
	
	QRect rect2(leftmargin,upmargin+cellheight*(row+3),cellwidth*col,cellheight);
	painter.drawText( rect2, Qt::AlignVCenter    | Qt::AlignLeft, QString::fromLocal8Bit("������ܣ�")+"                "+ QString::fromLocal8Bit("�շѸ����ˣ�")+"                "+ QString::fromLocal8Bit("ҩ�������ˣ�"));//ui.billtableWidget->item(i,j)->text()

	painter.end();
}
HospitalisationInternalPayment::~HospitalisationInternalPayment()
{

}
