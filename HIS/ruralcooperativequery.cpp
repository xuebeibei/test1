#include "ruralcooperativequery.h"
#include <QTreeWidgetItem>
#include <QTextCodec>
#include "connectsql.h"
#include "odbcexcel.h"
extern ConnectSql sql;
Ruralcooperativequery::Ruralcooperativequery(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	initUI();
}
void Ruralcooperativequery::initUI()
{
	ui.treeWidget->setStyleSheet("QTreeWidget{border: 1px solid gray;color: black;	background-color: white;selection-color: grey;}");
	connect(ui.treeWidget,SIGNAL(itemClicked(QTreeWidgetItem*,int)),this,SLOT(showTable(QTreeWidgetItem*,int)));
	
	QStringList headers;
	headers << QString::fromLocal8Bit("ũ�϶�Ӧ��ϵ");
	ui.treeWidget->setHeaderLabels(headers);

	QTextCodec::setCodecForTr(QTextCodec::codecForName("GBK"));
	QTextCodec::setCodecForLocale(QTextCodec::codecForName("GBK"));
	QStringList strlist;
	strlist <<QString::fromLocal8Bit("ҩƷ");
	QTreeWidgetItem *item = new QTreeWidgetItem(ui.treeWidget, strlist);
	ui.treeWidget->addTopLevelItem(item);
	strlist.clear();
	strlist <<QString::fromLocal8Bit("ҽ����Ŀ");
	item = new QTreeWidgetItem(ui.treeWidget, strlist);
	ui.treeWidget->addTopLevelItem(item);
	strlist.clear();
	strlist <<QString::fromLocal8Bit("��������");
	item = new QTreeWidgetItem(ui.treeWidget, strlist);
	ui.treeWidget->addTopLevelItem(item);
	ui.treeWidget->expandAll();

	ui.tableView->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
	ui.tableView->setStyleSheet("QTableWidget{border: 1px solid gray;	background-color: transparent;	selection-color: white;}");
	ui.tableView->horizontalHeader()->setStyleSheet("QHeaderView::section {background-color:white;color: black;padding-left: 4px;border: 1px solid #6c6c6c;};"
		"color: white;padding-left: 4px;border: 1px solid #6c6c6c;}"
		"QHeaderView::section:checked{background-color: white;color: black;}");	


	QSqlQueryModel *model=new QSqlQueryModel();	
	QString strsql;
	strsql = "select *from sys_drugcorrespondence order by id";
	model->setQuery(strsql,*sql.db);
	model->setHeaderData(0,Qt::Horizontal,"id");
	model->setHeaderData(1,Qt::Horizontal,QString::fromLocal8Bit("ũ�ϱ���"));
	model->setHeaderData(2,Qt::Horizontal,QString::fromLocal8Bit("ũ���շ���Ŀ����"));
	model->setHeaderData(3,Qt::Horizontal,QString::fromLocal8Bit("ҽԺ����"));
	model->setHeaderData(4,Qt::Horizontal,QString::fromLocal8Bit("ҽԺ�շ���Ŀ����"));
	model->setHeaderData(5,Qt::Horizontal,QString::fromLocal8Bit("����"));
	model->setHeaderData(6,Qt::Horizontal,QString::fromLocal8Bit("��λ"));
	model->setHeaderData(7,Qt::Horizontal,QString::fromLocal8Bit("���"));
	model->setHeaderData(8,Qt::Horizontal,QString::fromLocal8Bit("��������"));
	model->setHeaderData(9,Qt::Horizontal,QString::fromLocal8Bit("��ע"));
	ui.tableView->setModel(model);
}
void Ruralcooperativequery::showTable(QTreeWidgetItem*item,int column)
{
//	ui.tableWidget->setRowCount(0);
	QString strText = item->text(0);
	QSqlQueryModel *model=new QSqlQueryModel();	
	QString strsql;
	if (strText==QString::fromLocal8Bit("ҩƷ"))
	{
		strsql = "select *from sys_drugcorrespondence order by id";
		model->setQuery(strsql,*sql.db);
		model->setHeaderData(0,Qt::Horizontal,"id");
		model->setHeaderData(1,Qt::Horizontal,QString::fromLocal8Bit("ũ�ϱ���"));
		model->setHeaderData(2,Qt::Horizontal,QString::fromLocal8Bit("ũ���շ���Ŀ����"));
		model->setHeaderData(3,Qt::Horizontal,QString::fromLocal8Bit("ҽԺ����"));
		model->setHeaderData(4,Qt::Horizontal,QString::fromLocal8Bit("ҽԺ�շ���Ŀ����"));
		model->setHeaderData(5,Qt::Horizontal,QString::fromLocal8Bit("����"));
		model->setHeaderData(6,Qt::Horizontal,QString::fromLocal8Bit("��λ"));
		model->setHeaderData(7,Qt::Horizontal,QString::fromLocal8Bit("���"));
		model->setHeaderData(8,Qt::Horizontal,QString::fromLocal8Bit("��������"));
		model->setHeaderData(9,Qt::Horizontal,QString::fromLocal8Bit("��ע"));
		ui.tableView->setModel(model);
	}
	else if (strText==QString::fromLocal8Bit("ҽ����Ŀ"))
	{
		strsql = "select *from sys_projectcorrespondence  order by id";
		model->setQuery(strsql,*sql.db);
		model->setHeaderData(0,Qt::Horizontal,"id");
		model->setHeaderData(1,Qt::Horizontal,QString::fromLocal8Bit("ũ�ϱ���"));
		model->setHeaderData(2,Qt::Horizontal,QString::fromLocal8Bit("ũ���շ���Ŀ����"));
		model->setHeaderData(3,Qt::Horizontal,QString::fromLocal8Bit("ҽԺ����"));
		model->setHeaderData(4,Qt::Horizontal,QString::fromLocal8Bit("ҽԺ�շ���Ŀ����"));
		model->setHeaderData(5,Qt::Horizontal,QString::fromLocal8Bit("�Ƽ۵�λ"));
		model->setHeaderData(6,Qt::Horizontal,QString::fromLocal8Bit("�������"));
		model->setHeaderData(7,Qt::Horizontal,QString::fromLocal8Bit("����"));
		ui.tableView->setModel(model);
	}
	else if (strText==QString::fromLocal8Bit("��������"))
	{
		strsql = "select *from sys_materialcorrespondence  order by id";
		model->setQuery(strsql,*sql.db);
		model->setHeaderData(0,Qt::Horizontal,"id");
		model->setHeaderData(1,Qt::Horizontal,QString::fromLocal8Bit("ũ�ϱ���"));
		model->setHeaderData(2,Qt::Horizontal,QString::fromLocal8Bit("ũ���շ���Ŀ����"));
		model->setHeaderData(3,Qt::Horizontal,QString::fromLocal8Bit("ҽԺ����"));
		model->setHeaderData(4,Qt::Horizontal,QString::fromLocal8Bit("ҽԺ�շ���Ŀ����"));
		model->setHeaderData(5,Qt::Horizontal,QString::fromLocal8Bit("��λ"));
		model->setHeaderData(6,Qt::Horizontal,QString::fromLocal8Bit("��װ"));
		model->setHeaderData(7,Qt::Horizontal,QString::fromLocal8Bit("�����������"));
		model->setHeaderData(8,Qt::Horizontal,QString::fromLocal8Bit("��ע"));
		ui.tableView->setModel(model);
	}

}
void Ruralcooperativequery::on_previewButton_clicked()
{
	filePrintPreview();
}
void Ruralcooperativequery::on_printButton_clicked()
{
	QPrinter       printer( QPrinter::PrinterResolution );
	QPrintDialog   dialog( &printer, this );
	if ( dialog.exec() == QDialog::Accepted ) print( &printer );
}
void Ruralcooperativequery::on_outButton_clicked()
{
	QAbstractItemModel* model=ui.tableView->model();
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


	QList<QTreeWidgetItem*> list= ui.treeWidget->selectedItems();
	QTreeWidgetItem*item = list.at(0);
	QString strText = item->text(0);
	dlg.selectFile(strText+QString::fromLocal8Bit("(ũ�϶�Ӧ��ϵ)"));
	if(dlg.exec()!= QDialog::Accepted)
		return;


	QString filePath=dlg.selectedFiles()[0];
	if(OdbcExcel::saveFromTable(filePath,ui.tableView,"")) {
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
void Ruralcooperativequery::filePrintPreview()
{
	// ��ӡԤ���Ի���
	QPrinter             printer( QPrinter::PrinterResolution );
	printer.setPageSize(QPrinter::A4);
	QPrintPreviewDialog  preview( &printer, this );
	preview.setWindowTitle(QString::fromLocal8Bit("Ԥ��"));
	//preview.setMinimumSize(1000,900);
	connect( &preview, SIGNAL(paintRequested(QPrinter*)), SLOT(print(QPrinter*)) );
	preview.exec();
}
void Ruralcooperativequery::filePrint()
{
	// ��ӡ�Ի���
	QPrinter       printer( QPrinter::PrinterResolution );
	printer.setPageSize(QPrinter::A4);
	//printer.setOrientation(QPrinter::Landscape);
	//printer.setPaperSize(QSizeF(120,180),QPrinter::Point);

	QPrintDialog   dialog( &printer, this );

	if ( dialog.exec() == QDialog::Accepted ) print( &printer );
}
void Ruralcooperativequery::print( QPrinter* printer )
{
	QPainter painter( printer );
	int      w = printer->pageRect().width();
	int      h = printer->pageRect().height();
	QRect    page( w/50, h/50, w, h );
	QRect    page4( w/30, h/10, w, h );
	QFont    font = painter.font();
	font.setPointSize(8);
	painter.setFont( font );
	painter.drawText( page, Qt::AlignTop    | Qt::AlignHCenter, QString::fromLocal8Bit(" �������ོ������Ժũ�϶�Ӧ��ϵ") );


	painter.begin(this);
	painter.setPen(QPen(Qt::black,4,Qt::SolidLine));//���û�����ʽ 
	painter.setBrush(QBrush(Qt::white,Qt::SolidPattern));//���û�ˢ��ʽ 
	int row = ui.tableView->model()->rowCount();
	int col = ui.tableView->model()->columnCount();
	double cellwidth = (w-40)/col;
	double cellheight = 160;
	double upmargin = 300;
	//������ҳ��
	int firstpagerow = (h-800)/160;//��һҳ�Ϸ��հ�Ϊ750,�·�Ϊ50
	int everypagerow = (h-100)/160;//����ÿҳ�Ŀհ�Ϊ100
	int pagecount = 0;
	//xpϵͳ
	if(sql.windowsFlag==QSysInfo::WV_5_1||sql.windowsFlag==QSysInfo::WV_5_0||sql.windowsFlag==QSysInfo::WV_5_2||sql.windowsFlag==QSysInfo::WV_4_0)//�жϵ�ǰϵͳ
	{
		cellwidth= (w-100)/col;
		cellheight=60;
		upmargin = 50;
		firstpagerow = (h-200)/cellheight;
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
			//list.append(ui.tableView->horizontalHeader(j)->text());
		}
		if (col == 10)
		{
			list.append("id");
			list.append(QString::fromLocal8Bit("ũ�ϱ���"));
			list.append(QString::fromLocal8Bit("ũ���շ���Ŀ����"));
			list.append(QString::fromLocal8Bit("ҽԺ����"));
			list.append(QString::fromLocal8Bit("ҽԺ�շ���Ŀ����"));
			list.append(QString::fromLocal8Bit("����"));
			list.append(QString::fromLocal8Bit("��λ"));
			list.append(QString::fromLocal8Bit("���"));
			list.append(QString::fromLocal8Bit("��������"));
			list.append(QString::fromLocal8Bit("��ע"));
		}
		else if (col == 8)
		{

			list.append("id");
			list.append(QString::fromLocal8Bit("ũ�ϱ���"));
			list.append(QString::fromLocal8Bit("ũ���շ���Ŀ����"));
			list.append(QString::fromLocal8Bit("ҽԺ����"));
			list.append(QString::fromLocal8Bit("ҽԺ�շ���Ŀ����"));
			list.append(QString::fromLocal8Bit("�Ƽ۵�λ"));
			list.append(QString::fromLocal8Bit("�������"));
			list.append(QString::fromLocal8Bit("����"));
		}
		else if (col == 9)
		{

			list.append("id");
			list.append(QString::fromLocal8Bit("ũ�ϱ���"));
			list.append(QString::fromLocal8Bit("ũ���շ���Ŀ����"));
			list.append(QString::fromLocal8Bit("ҽԺ����"));
			list.append(QString::fromLocal8Bit("ҽԺ�շ���Ŀ����"));
			list.append(QString::fromLocal8Bit("��λ"));
			list.append(QString::fromLocal8Bit("��װ"));
			list.append(QString::fromLocal8Bit("�����������"));
			list.append(QString::fromLocal8Bit("��ע"));
		}


		for (int i=0;i<row;i++)
		{
			for (int j=0;j<col;j++)
			{
				if (ui.tableView->model()->index(i,j).data()==NULL)
				{
					list.append("");
					continue;
				}
				list.append(ui.tableView->model()->index(i,j).data().toString());
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
		//��ҳ
		QStringList list;
		for (int j =0;j<col;j++)
		{
			//list.append(ui.tableView->horizontalHeader(j)->text());
		}
		if (col == 10)
		{
			list.append("id");
			list.append(QString::fromLocal8Bit("ũ�ϱ���"));
			list.append(QString::fromLocal8Bit("ũ���շ���Ŀ����"));
			list.append(QString::fromLocal8Bit("ҽԺ����"));
			list.append(QString::fromLocal8Bit("ҽԺ�շ���Ŀ����"));
			list.append(QString::fromLocal8Bit("����"));
			list.append(QString::fromLocal8Bit("��λ"));
			list.append(QString::fromLocal8Bit("���"));
			list.append(QString::fromLocal8Bit("��������"));
			list.append(QString::fromLocal8Bit("��ע"));
		}
		else if (col == 8)
		{

			list.append("id");
			list.append(QString::fromLocal8Bit("ũ�ϱ���"));
			list.append(QString::fromLocal8Bit("ũ���շ���Ŀ����"));
			list.append(QString::fromLocal8Bit("ҽԺ����"));
			list.append(QString::fromLocal8Bit("ҽԺ�շ���Ŀ����"));
			list.append(QString::fromLocal8Bit("�Ƽ۵�λ"));
			list.append(QString::fromLocal8Bit("�������"));
			list.append(QString::fromLocal8Bit("����"));
		}
		else if (col == 9)
		{

			list.append("id");
			list.append(QString::fromLocal8Bit("ũ�ϱ���"));
			list.append(QString::fromLocal8Bit("ũ���շ���Ŀ����"));
			list.append(QString::fromLocal8Bit("ҽԺ����"));
			list.append(QString::fromLocal8Bit("ҽԺ�շ���Ŀ����"));
			list.append(QString::fromLocal8Bit("��λ"));
			list.append(QString::fromLocal8Bit("��װ"));
			list.append(QString::fromLocal8Bit("�����������"));
			list.append(QString::fromLocal8Bit("��ע"));
		}		for (int i=0;i<firstpagerow;i++)
		{
			for (int j=0;j<col;j++)
			{
				if (ui.tableView->model()->index(i,j).data()==NULL)
				{
					list.append("");
					continue;
				}
				list.append(ui.tableView->model()->index(i,j).data().toString());
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
		//ռ����ҳ��
		for (int k = 0;k<pagecount-2;k++)
		{
			list.clear();
			for (int i=firstpagerow+k*everypagerow;i<firstpagerow+(k+1)*everypagerow;i++)
			{
				for (int j=0;j<col;j++)
				{
					if (ui.tableView->model()->index(i,j).data()==NULL)
					{
						list.append("");
						continue;
					}
					list.append(ui.tableView->model()->index(i,j).data().toString());
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
				if (ui.tableView->model()->index(i,j).data()==NULL)
				{
					list.append("");
					continue;
				}
				list.append(ui.tableView->model()->index(i,j).data().toString());
			}
		}
		for (int i=0;i<row-firstpagerow-(pagecount-2)*everypagerow-1;i++)
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
Ruralcooperativequery::~Ruralcooperativequery()
{

}
