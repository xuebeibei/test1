#include "hospitalisationprint.h"
#include "connectsql.h"
#include "capital.h"
extern ConnectSql sql;
Hospitalisationprint::Hospitalisationprint(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}
//ƽ������ж�// 
int leap(int year) 
{ 
	if ( year%4==0&&year%100!=0||year % 400 ==0) 
		return 1; 
	else
		return 0; 
}
//��������// 
int count_day ( int year, int month, int day, int flag ) 
{ 
	static int day_tab[2][12] = {{31,28,31,30,31,30,31,31,30,31,30,31},{31,29,31,30,31,30,31,31,30,31,30,31}};
	//��ά����������
	int p, i, s; 
	if (leap(year))                                                                                //����Ϊ1ѡ��������
		p = 1; 
	else   //ƽ��Ϊ0ѡ��ǰ�����
		p = 0; 
	if (flag) 
	{ 
		s = day; 
		for ( i = 1; i < month; i++ ) 
			s += day_tab[p][i-1];//��ѯ�����ۼ�����
	} 
	else
	{ 
		s = day_tab[p][month] - day; 
		for ( i = month + 1; i <= 12; i++ ) 
			s += day_tab[p][i-1]; 
	} 
	return ( s );//��������
} 
int delta_day(int startYear,int startMonth,int startDay,int endYear,int endMonth,int endDay)
{

	long deltadate,year, day1, day2; 
	if ( startYear < endYear ) 
	{ 
		deltadate = count_day ( startYear, startMonth, startDay , 0 ); 
		for (year=startYear+1;year<endYear; year++ )//����ۼ�
			if (leap(year))//��������
				deltadate += 366; 
			else   //ƽ��
				deltadate += 365; 
		deltadate += count_day (endYear, endMonth, endDay, 1); 

	} 
	//ͬһ���ʱ���ж�
	else if ( startYear == endYear ) 
	{ 
		day1 = count_day ( startYear, startMonth, startDay, 1 ); 
		day2 = count_day ( endYear, endMonth, endDay, 1 ); 
		deltadate = day2-day1;//��ı���������
	} 
	else
		deltadate = -1; //��ʶ
	return deltadate;
}
void Hospitalisationprint::initUI(QString strNo)
{
	QSqlQuery query(*sql.db);		
	query.exec("select * from zy_patientinfo where hospitalisationno= '"+strNo+"'");
	QString strstatus;
	while(query.next())
	{
		ui.hospitallabel->setText(QString::fromLocal8Bit("�������ོ������Ժ"));
		ui.departmentlabel->setText(query.value(13).toString());
		ui.sheetmakerlabel->setText(sql.struser);
		ui.hospitalisationNolabel->setText(strNo);
		ui.genderlabel->setText(query.value(5).toString());
		ui.insurancenolabel->setText(query.value(12).toString());
		ui.insurancetypelabel->setText(query.value(15).toString());
		ui.namelabel->setText(query.value(4).toString());

		QDateTime strdatetime = query.value(2).toDateTime();
		int startyear = strdatetime.date().year();
		int startmonth= strdatetime.date().month();
		int startday= strdatetime.date().day();
		QString stryear =QString::number(strdatetime.date().year());
		QString strmonth =QString::number( strdatetime.date().month());
		QString strday =QString::number( strdatetime.date().day());
		ui.startyearlabel->setText(stryear);
		ui.startmonthlabel->setText(strmonth);
		ui.startdaylabel->setText(strday);


		QDateTime strenddatetime = query.value(23).toDateTime();
		int endyear = strenddatetime.date().year();
		int endmonth= strenddatetime.date().month();
		int endday= strenddatetime.date().day();
		stryear =QString::number(strenddatetime.date().year());
		strmonth =QString::number( strenddatetime.date().month());
		strday =QString::number( strenddatetime.date().day());
		ui.endyearlabel->setText(stryear);
		ui.endmonthlabel->setText(strmonth);
		ui.enddaylabel->setText(strday);
		int deltaday = delta_day(startyear,startmonth,startday,endyear,endmonth,endday);
		ui.deltadaylabel->setText(QString::number(deltaday));

	}

	QStringList typelist;
	typelist.append(QString::fromLocal8Bit("01-��λ��B"));
	typelist.append(QString::fromLocal8Bit("03-�����F"));
	typelist.append(QString::fromLocal8Bit("09-��ҩ��"));
	typelist.append(QString::fromLocal8Bit("13-�г�ҩ��"));
	typelist.append(QString::fromLocal8Bit("17-���Ϸ�"));
	typelist.append(QString::fromLocal8Bit("12-������I"));
	QString strsql;
	double tempfee=0.0;
	for (int i = 0;i<typelist.count();i++)
	{
		QString strType = typelist.at(i);
		query.exec("select * from zy_chargedetail where  itemtype='"+strType+"'and  hospitalisationno='"+strNo+"'");
		double totalfee=0.0;
		while(query.next())
		{
			totalfee+=query.value(8).toDouble();	
		}
		tempfee+=totalfee;
		ui.tableWidget->setItem(i,1,new QTableWidgetItem(QString::number(totalfee)));
	}
	QStringList typelist2;
	typelist2.append(QString::fromLocal8Bit("04-������G"));
	typelist2.append(QString::fromLocal8Bit("05-�Һŷ�A"));
	typelist2.append(QString::fromLocal8Bit("06-���Ʒ�E"));
	typelist2.append(QString::fromLocal8Bit("10-����D"));
	typelist2.append(QString::fromLocal8Bit("14-�����H"));
	typelist2.append(QString::fromLocal8Bit("02-����C"));
	for (int i = 0;i<typelist2.count();i++)
	{
		QString strType = typelist2.at(i);
		query.exec("select * from zy_chargedetail where  itemtype='"+strType+"'and  hospitalisationno='"+strNo+"'");
		double totalfee=0.0;
		while(query.next())
		{
			totalfee+=query.value(8).toDouble();	
		}
		tempfee+=totalfee;
		ui.tableWidget_2->setItem(i,1,new QTableWidgetItem(QString::number(totalfee)));
	}

	QString strcaptial;//=QString::fromLocal8Bit(NumToChineseStr(tempfee).c_str());
	ui.feeblocklabel->setText(strcaptial);
	ui.totalfeelabel->setText(QString::number(tempfee));
	QString stryear =QString::number( QDate::currentDate().year());
	QString strmonth =QString::number( QDate::currentDate().month());
	QString strday =QString::number( QDate::currentDate().day());
	ui.currentyearlabel->setText(stryear);
	ui.currentmonthlabel->setText(strmonth);
	ui.currentdaylabel->setText(strday);

}
void Hospitalisationprint::on_printButton_clicked()
{
	QPrinter       printer( QPrinter::PrinterResolution );
	QPrintDialog   dialog( &printer, this );
	if ( dialog.exec() == QDialog::Accepted ) print( &printer );
}
void Hospitalisationprint::on_previewButton_clicked()
{
	filePrintPreview();
}
void Hospitalisationprint::filePrintPreview()
{
	// ��ӡԤ���Ի���
	QPrinter             printer( QPrinter::PrinterResolution );
	printer.setPageSize(QPrinter::Custom);
	QPrintPreviewDialog  preview( &printer, this );
	preview.setWindowTitle(QString::fromLocal8Bit("Ԥ��"));
	connect( &preview, SIGNAL(paintRequested(QPrinter*)), SLOT(print(QPrinter*)) );
	preview.exec();
}
void Hospitalisationprint::filePrint()
{
	// ��ӡ�Ի���
	QPrinter       printer( QPrinter::PrinterResolution );
	printer.setPageSize(QPrinter::Custom);
	QPrintDialog   dialog( &printer, this );

	if ( dialog.exec() == QDialog::Accepted ) print( &printer );
}
void Hospitalisationprint::print( QPrinter* printer )
{
	QPainter painter( printer );
	int      w = printer->pageRect().width();
	int      h = printer->pageRect().height();
	QRect    page2( 36*w/210, 17*h/297, w, h );
	QRect    page3( 35*w/210, 23*h/297, w, h );
	QRect    page4( 34*w/210, 28*h/297, 5*w/6, h/8);
	QRect    page5( 30*w/210, 35*h/297, 5*w/6, h/4);
	QRect    page6(110*w/210, 35*h/297, 5*w/6, h/4);
	QRect    page7( 42*w/210, 72*h/297,  5*w/6, h/8);
	QRect    page8( 115*w/210, 98*h/297, 5*w/6, h/8);
	QFont    font = painter.font();
	font.setPointSize(8);
	painter.setFont( font );
	QString str =QString::fromLocal8Bit("�������ོ������Ժ")+"                     "+ui.departmentlabel->text()+"                 "+ui.sheetnolabel->text();
	painter.drawText(page2, Qt::AlignTop    | Qt::AlignLeft, str);
	str =ui.hospitalisationNolabel->text()+"                    "+ui.startyearlabel->text()+"  "+ui.startmonthlabel->text()+"   "+ui.startdaylabel->text() +  "               "+ui.endyearlabel->text()+"  "+ui.endmonthlabel->text()+"   "+ui.enddaylabel->text()+"              "+ui.deltadaylabel->text();
	painter.drawText( page3, Qt::AlignTop    | Qt::AlignLeft, str);
	str =ui.namelabel->text()+"                    "+ui.genderlabel->text()+"                     "+ui.insurancetypelabel->text()+"                                "+ui.insurancenolabel->text();
	painter.drawText( page4, Qt::AlignTop    | Qt::AlignLeft, str);
	int row = ui.tableWidget->rowCount();
	str="";
	for (int i =0;i<row;i++)
	{
		str =str+ui.tableWidget->item(i,0)->text()+"               "+ui.tableWidget->item(i,1)->text()+"\n";

	}
	//	str =ui.dueincomeEdit->text()+"\n"+ui.dateTimeEdit->time().toString();
	painter.drawText( page5, Qt::AlignTop    | Qt::AlignLeft, str);

	row = ui.tableWidget_2->rowCount();
	str="";
	for (int i =0;i<row;i++)
	{
		str =str+ui.tableWidget_2->item(i,0)->text()+"               "+ui.tableWidget_2->item(i,1)->text()+"\n";

	}
	//	str =ui.dueincomeEdit->text()+"\n"+ui.dateTimeEdit->time().toString();
	painter.drawText( page6, Qt::AlignTop    | Qt::AlignLeft, str);

	double amount=ui.totalfeelabel->text().toDouble();
	Capital*capital = new Capital;
	QString strcaptial=capital->NumToChineseStr(amount);//=QString::fromLocal8Bit(.c_str());;
	str="";
	str=strcaptial+"                                 "+ui.totalfeelabel->text();
	painter.drawText( page7, Qt::AlignTop    | Qt::AlignLeft, str);
	str=ui.sheetmakerlabel->text()+"                                "+ui.currentyearlabel->text()+"  "+ui.currentmonthlabel->text()+"  "+ui.currentdaylabel->text();
	painter.drawText( page8, Qt::AlignTop    | Qt::AlignLeft, str);

}

Hospitalisationprint::~Hospitalisationprint()
{

}
