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
	headers << QString::fromLocal8Bit("农合对应关系");
	ui.treeWidget->setHeaderLabels(headers);

	QTextCodec::setCodecForTr(QTextCodec::codecForName("GBK"));
	QTextCodec::setCodecForLocale(QTextCodec::codecForName("GBK"));
	QStringList strlist;
	strlist <<QString::fromLocal8Bit("药品");
	QTreeWidgetItem *item = new QTreeWidgetItem(ui.treeWidget, strlist);
	ui.treeWidget->addTopLevelItem(item);
	strlist.clear();
	strlist <<QString::fromLocal8Bit("医疗项目");
	item = new QTreeWidgetItem(ui.treeWidget, strlist);
	ui.treeWidget->addTopLevelItem(item);
	strlist.clear();
	strlist <<QString::fromLocal8Bit("卫生材料");
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
	model->setHeaderData(1,Qt::Horizontal,QString::fromLocal8Bit("农合编码"));
	model->setHeaderData(2,Qt::Horizontal,QString::fromLocal8Bit("农合收费项目名称"));
	model->setHeaderData(3,Qt::Horizontal,QString::fromLocal8Bit("医院编码"));
	model->setHeaderData(4,Qt::Horizontal,QString::fromLocal8Bit("医院收费项目名称"));
	model->setHeaderData(5,Qt::Horizontal,QString::fromLocal8Bit("剂型"));
	model->setHeaderData(6,Qt::Horizontal,QString::fromLocal8Bit("单位"));
	model->setHeaderData(7,Qt::Horizontal,QString::fromLocal8Bit("规格"));
	model->setHeaderData(8,Qt::Horizontal,QString::fromLocal8Bit("生产厂家"));
	model->setHeaderData(9,Qt::Horizontal,QString::fromLocal8Bit("备注"));
	ui.tableView->setModel(model);
}
void Ruralcooperativequery::showTable(QTreeWidgetItem*item,int column)
{
//	ui.tableWidget->setRowCount(0);
	QString strText = item->text(0);
	QSqlQueryModel *model=new QSqlQueryModel();	
	QString strsql;
	if (strText==QString::fromLocal8Bit("药品"))
	{
		strsql = "select *from sys_drugcorrespondence order by id";
		model->setQuery(strsql,*sql.db);
		model->setHeaderData(0,Qt::Horizontal,"id");
		model->setHeaderData(1,Qt::Horizontal,QString::fromLocal8Bit("农合编码"));
		model->setHeaderData(2,Qt::Horizontal,QString::fromLocal8Bit("农合收费项目名称"));
		model->setHeaderData(3,Qt::Horizontal,QString::fromLocal8Bit("医院编码"));
		model->setHeaderData(4,Qt::Horizontal,QString::fromLocal8Bit("医院收费项目名称"));
		model->setHeaderData(5,Qt::Horizontal,QString::fromLocal8Bit("剂型"));
		model->setHeaderData(6,Qt::Horizontal,QString::fromLocal8Bit("单位"));
		model->setHeaderData(7,Qt::Horizontal,QString::fromLocal8Bit("规格"));
		model->setHeaderData(8,Qt::Horizontal,QString::fromLocal8Bit("生产厂家"));
		model->setHeaderData(9,Qt::Horizontal,QString::fromLocal8Bit("备注"));
		ui.tableView->setModel(model);
	}
	else if (strText==QString::fromLocal8Bit("医疗项目"))
	{
		strsql = "select *from sys_projectcorrespondence  order by id";
		model->setQuery(strsql,*sql.db);
		model->setHeaderData(0,Qt::Horizontal,"id");
		model->setHeaderData(1,Qt::Horizontal,QString::fromLocal8Bit("农合编码"));
		model->setHeaderData(2,Qt::Horizontal,QString::fromLocal8Bit("农合收费项目名称"));
		model->setHeaderData(3,Qt::Horizontal,QString::fromLocal8Bit("医院编码"));
		model->setHeaderData(4,Qt::Horizontal,QString::fromLocal8Bit("医院收费项目名称"));
		model->setHeaderData(5,Qt::Horizontal,QString::fromLocal8Bit("计价单位"));
		model->setHeaderData(6,Qt::Horizontal,QString::fromLocal8Bit("财务分类"));
		model->setHeaderData(7,Qt::Horizontal,QString::fromLocal8Bit("编码"));
		ui.tableView->setModel(model);
	}
	else if (strText==QString::fromLocal8Bit("卫生材料"))
	{
		strsql = "select *from sys_materialcorrespondence  order by id";
		model->setQuery(strsql,*sql.db);
		model->setHeaderData(0,Qt::Horizontal,"id");
		model->setHeaderData(1,Qt::Horizontal,QString::fromLocal8Bit("农合编码"));
		model->setHeaderData(2,Qt::Horizontal,QString::fromLocal8Bit("农合收费项目名称"));
		model->setHeaderData(3,Qt::Horizontal,QString::fromLocal8Bit("医院编码"));
		model->setHeaderData(4,Qt::Horizontal,QString::fromLocal8Bit("医院收费项目名称"));
		model->setHeaderData(5,Qt::Horizontal,QString::fromLocal8Bit("单位"));
		model->setHeaderData(6,Qt::Horizontal,QString::fromLocal8Bit("包装"));
		model->setHeaderData(7,Qt::Horizontal,QString::fromLocal8Bit("规格、生产厂家"));
		model->setHeaderData(8,Qt::Horizontal,QString::fromLocal8Bit("备注"));
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


	QList<QTreeWidgetItem*> list= ui.treeWidget->selectedItems();
	QTreeWidgetItem*item = list.at(0);
	QString strText = item->text(0);
	dlg.selectFile(strText+QString::fromLocal8Bit("(农合对应关系)"));
	if(dlg.exec()!= QDialog::Accepted)
		return;


	QString filePath=dlg.selectedFiles()[0];
	if(OdbcExcel::saveFromTable(filePath,ui.tableView,"")) {
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
void Ruralcooperativequery::filePrintPreview()
{
	// 打印预览对话框
	QPrinter             printer( QPrinter::PrinterResolution );
	printer.setPageSize(QPrinter::A4);
	QPrintPreviewDialog  preview( &printer, this );
	preview.setWindowTitle(QString::fromLocal8Bit("预览"));
	//preview.setMinimumSize(1000,900);
	connect( &preview, SIGNAL(paintRequested(QPrinter*)), SLOT(print(QPrinter*)) );
	preview.exec();
}
void Ruralcooperativequery::filePrint()
{
	// 打印对话框
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
	painter.drawText( page, Qt::AlignTop    | Qt::AlignHCenter, QString::fromLocal8Bit(" 三河市燕郊镇卫生院农合对应关系") );


	painter.begin(this);
	painter.setPen(QPen(Qt::black,4,Qt::SolidLine));//设置画笔形式 
	painter.setBrush(QBrush(Qt::white,Qt::SolidPattern));//设置画刷形式 
	int row = ui.tableView->model()->rowCount();
	int col = ui.tableView->model()->columnCount();
	double cellwidth = (w-40)/col;
	double cellheight = 160;
	double upmargin = 300;
	//计算总页数
	int firstpagerow = (h-800)/160;//第一页上方空白为750,下方为50
	int everypagerow = (h-100)/160;//后面每页的空白为100
	int pagecount = 0;
	//xp系统
	if(sql.windowsFlag==QSysInfo::WV_5_1||sql.windowsFlag==QSysInfo::WV_5_0||sql.windowsFlag==QSysInfo::WV_5_2||sql.windowsFlag==QSysInfo::WV_4_0)//判断当前系统
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
			list.append(QString::fromLocal8Bit("农合编码"));
			list.append(QString::fromLocal8Bit("农合收费项目名称"));
			list.append(QString::fromLocal8Bit("医院编码"));
			list.append(QString::fromLocal8Bit("医院收费项目名称"));
			list.append(QString::fromLocal8Bit("剂型"));
			list.append(QString::fromLocal8Bit("单位"));
			list.append(QString::fromLocal8Bit("规格"));
			list.append(QString::fromLocal8Bit("生产厂家"));
			list.append(QString::fromLocal8Bit("备注"));
		}
		else if (col == 8)
		{

			list.append("id");
			list.append(QString::fromLocal8Bit("农合编码"));
			list.append(QString::fromLocal8Bit("农合收费项目名称"));
			list.append(QString::fromLocal8Bit("医院编码"));
			list.append(QString::fromLocal8Bit("医院收费项目名称"));
			list.append(QString::fromLocal8Bit("计价单位"));
			list.append(QString::fromLocal8Bit("财务分类"));
			list.append(QString::fromLocal8Bit("编码"));
		}
		else if (col == 9)
		{

			list.append("id");
			list.append(QString::fromLocal8Bit("农合编码"));
			list.append(QString::fromLocal8Bit("农合收费项目名称"));
			list.append(QString::fromLocal8Bit("医院编码"));
			list.append(QString::fromLocal8Bit("医院收费项目名称"));
			list.append(QString::fromLocal8Bit("单位"));
			list.append(QString::fromLocal8Bit("包装"));
			list.append(QString::fromLocal8Bit("规格、生产厂家"));
			list.append(QString::fromLocal8Bit("备注"));
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
		//首页
		QStringList list;
		for (int j =0;j<col;j++)
		{
			//list.append(ui.tableView->horizontalHeader(j)->text());
		}
		if (col == 10)
		{
			list.append("id");
			list.append(QString::fromLocal8Bit("农合编码"));
			list.append(QString::fromLocal8Bit("农合收费项目名称"));
			list.append(QString::fromLocal8Bit("医院编码"));
			list.append(QString::fromLocal8Bit("医院收费项目名称"));
			list.append(QString::fromLocal8Bit("剂型"));
			list.append(QString::fromLocal8Bit("单位"));
			list.append(QString::fromLocal8Bit("规格"));
			list.append(QString::fromLocal8Bit("生产厂家"));
			list.append(QString::fromLocal8Bit("备注"));
		}
		else if (col == 8)
		{

			list.append("id");
			list.append(QString::fromLocal8Bit("农合编码"));
			list.append(QString::fromLocal8Bit("农合收费项目名称"));
			list.append(QString::fromLocal8Bit("医院编码"));
			list.append(QString::fromLocal8Bit("医院收费项目名称"));
			list.append(QString::fromLocal8Bit("计价单位"));
			list.append(QString::fromLocal8Bit("财务分类"));
			list.append(QString::fromLocal8Bit("编码"));
		}
		else if (col == 9)
		{

			list.append("id");
			list.append(QString::fromLocal8Bit("农合编码"));
			list.append(QString::fromLocal8Bit("农合收费项目名称"));
			list.append(QString::fromLocal8Bit("医院编码"));
			list.append(QString::fromLocal8Bit("医院收费项目名称"));
			list.append(QString::fromLocal8Bit("单位"));
			list.append(QString::fromLocal8Bit("包装"));
			list.append(QString::fromLocal8Bit("规格、生产厂家"));
			list.append(QString::fromLocal8Bit("备注"));
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
		//占满的页面
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
