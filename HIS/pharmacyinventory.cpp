#include "pharmacyinventory.h"

#include "connectsql.h"
#include "clinicdrugfilter.h"
#include "package.h"

static int icount;
extern ConnectSql sql;
PharmacyInventory::PharmacyInventory(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	initUI();
	druglist = new QListView(this);
	model = new QStringListModel(this);
	druglist->setWindowFlags(Qt::ToolTip);
	ui.tableWidget->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
	ui.tableWidget->setStyleSheet("QTableWidget{border: 1px solid gray;	background-color: transparent;	selection-color: grey;}");
	ui.tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section {background-color:white;color: black;padding-left: 4px;border: 1px solid #6c6c6c;};"
		"color: white;padding-left: 4px;border: 1px solid #6c6c6c;}"
		"QHeaderView::section:checked{background-color: white;color: black;}");	
	ui.tableWidget->installEventFilter(this);//注册事件过滤器
	
	list_widget = new QListWidget(this);
	list_widget->setWindowFlags(Qt::FramelessWindowHint);
	list_widget->close();
	installEventFilter(list_widget);
	connect(ui.tableWidget,SIGNAL(cellClicked(int,int)),this,SLOT(getItem(int,int)));
	connect(ui.lineEdit_code,SIGNAL(textChanged(const QString &)),this,SLOT(findbyname(const QString &)));
	connect(druglist, SIGNAL(clicked(const QModelIndex &)), this, SLOT(completeText(const QModelIndex &)));
}

PharmacyInventory::~PharmacyInventory()
{
	
}

void PharmacyInventory::getItem(int row,int column)//计算费用
{

}
void PharmacyInventory::findbyname(const QString &text)
{
	druglist->hide();
	if (text.isEmpty()) {
		druglist->hide();
		return;
	}

	if ((text.length() > 1) && (!druglist->isHidden())) {
		return;
	}

	QSqlQuery query(*sql.db);	

	QString strsql=QString("select * from sys_drugdictionary where abbr like '%%1%' or name like'%%2%'  ").arg(text).arg(text);
	query.exec(strsql);
	QStringList list;
	while(query.next())
	{
		QString str = query.value(1).toString();
		list.append(str);
	}

	model->setStringList(list);
	//	model->setStringList(sl);
	druglist->setModel(model);

	if (model->rowCount() == 0) {
		return;
	}

	// Position the text edit
	druglist->setMinimumWidth(width());
	druglist->setMaximumWidth(width());

	QPoint p(0, height());
	int x = mapToGlobal(p).x();
	int y = mapToGlobal(p).y() + 1;

	QPoint GlobalPoint(ui.lineEdit_code->mapToGlobal(QPoint(0, 0)));
	druglist->setGeometry(GlobalPoint.x(), GlobalPoint.y()+ui.lineEdit_code->height(), 60, 100);
	druglist->show();
}
void PharmacyInventory::initUI()
{
	iRow=0;
	QSqlQuery query(*sql.db);		
	QDateTime current_date_time = QDateTime::currentDateTime();

	//ui.tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
	QTextCodec::setCodecForTr(QTextCodec::codecForName("gb18030"));
//	item(i, colunm)->setFlags(Qt::NoItemFlags);
	//ui.tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);  //整行选中的方式

	iRow = 0;
	icount = 0;
	int rows = ui.tableWidget->model()->rowCount();   //行总数
	for (int i=0;i<rows+1;i++)
	{
		ui.tableWidget->removeRow(rows - i);
	}

}
void PharmacyInventory::SetEdit(bool IsEdit)
{
	if (IsEdit==true)
	{
		
		ui.tableWidget->setEnabled(true);
	}
	else
	{
		ui.tableWidget->setEnabled(false);
	}
}
void PharmacyInventory::on_FindAllButton_clicked()
{
	QSqlQuery query(*sql.db);
	iRow = 0;
	icount = 0;
	int rows = ui.tableWidget->model()->rowCount();   //行总数
	for (int i=0;i<rows+1;i++)
	{
		ui.tableWidget->removeRow(rows - i);
	}
	QString strsql1= "select * from yf_inventory";//;//where AbbrName = '"+strName+"'
	query.exec(strsql1);
					
	while(query.next())
	{
		int rows = ui.tableWidget->model()->rowCount();   //行总数
		ui.tableWidget->insertRow(rows);
		iRow=rows;
		ui.tableWidget->setItem(iRow,0,new QTableWidgetItem(query.value(2).toString()));
		ui.tableWidget->setItem(iRow,1,new QTableWidgetItem(query.value(3).toString()));
		ui.tableWidget->setItem(iRow,2,new QTableWidgetItem(query.value(4).toString()));
		ui.tableWidget->setItem(iRow,4,new QTableWidgetItem(query.value(6).toString()));
		ui.tableWidget->setItem(iRow,5,new QTableWidgetItem(query.value(7).toString()));
		ui.tableWidget->setItem(iRow,6,new QTableWidgetItem(query.value(8).toString()));
	}

}
void PharmacyInventory::on_FindButton_clicked()
{
	QString strName;
	strName = ui.lineEdit_code->text();
	ui.tableWidget->setEditTriggers(QAbstractItemView::AllEditTriggers);

	int rows = ui.tableWidget->model()->rowCount();   //行总数
	for (int i=0;i<rows+1;i++)
	{
		ui.tableWidget->removeRow(rows - i);
	}

	std::string strStd1= strName.toStdString();
	QTextCodec *code = QTextCodec::codecForName("gb18030");
	 // 如果code为0，表示在运行的机器上没有装gb18030字符集。不过一般的中文windows系统中都安装了这一字符集
	if (code)   
		strStd1= code->fromUnicode(strName).data();

	//std::string strStd2= strManufacturer.toStdString();
	// // 如果code为0，表示在运行的机器上没有装gb18030字符集。不过一般的中文windows系统中都安装了这一字符集
	//if (code)   
	//	strStd2= code->fromUnicode(strManufacturer).data();

	if(strStd1!="")//按照药品名称查找
	{
		QSqlQuery query(*sql.db);	
		QString strsql1= "select * from yf_inventory where name like '"+strName+"'";
		query.exec(strsql1);
		
		while(query.next())
		{
			int rows = ui.tableWidget->model()->rowCount();   //行总数
			ui.tableWidget->insertRow(rows);
			iRow=rows;
			ui.tableWidget->setItem(iRow,0,new QTableWidgetItem(query.value(2).toString()));
			ui.tableWidget->setItem(iRow,1,new QTableWidgetItem(query.value(3).toString()));
			ui.tableWidget->setItem(iRow,2,new QTableWidgetItem(query.value(4).toString()));
			ui.tableWidget->setItem(iRow,4,new QTableWidgetItem(query.value(6).toString()));
			ui.tableWidget->setItem(iRow,5,new QTableWidgetItem(query.value(7).toString()));
			ui.tableWidget->setItem(iRow,6,new QTableWidgetItem(query.value(8).toString()));
		}
		ui.tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
	}
	else 
	{
		QSqlQuery query(*sql.db);	
		QString strsql1= "select * from yf_inventory";//;//where AbbrName = '"+strName+"'
		query.exec(strsql1);
					
		while(query.next())
		{
			int rows = ui.tableWidget->model()->rowCount();   //行总数
			ui.tableWidget->insertRow(rows);
			iRow=rows;
			ui.tableWidget->setItem(iRow,0,new QTableWidgetItem(query.value(2).toString()));
			ui.tableWidget->setItem(iRow,1,new QTableWidgetItem(query.value(3).toString()));
			ui.tableWidget->setItem(iRow,2,new QTableWidgetItem(query.value(4).toString()));
			ui.tableWidget->setItem(iRow,4,new QTableWidgetItem(query.value(6).toString()));
			ui.tableWidget->setItem(iRow,5,new QTableWidgetItem(query.value(7).toString()));
			ui.tableWidget->setItem(iRow,6,new QTableWidgetItem(query.value(8).toString()));
		}
		ui.tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
	}
}
void PharmacyInventory::completeText(const QModelIndex &index) {
	QString strName = index.data().toString();
	ui.lineEdit_code->setText(strName);
	druglist->hide();
}
void PharmacyInventory::keyPressEvent(QKeyEvent *e) {
	if (!druglist->isHidden()) {
		int key = e->key();
		int count = druglist->model()->rowCount();
		QModelIndex currentIndex = druglist->currentIndex();

		if (Qt::Key_Down == key) {
			// 按向下方向键时，移动光标选中下一个完成列表中的项
			int row = currentIndex.row() + 1;
			if (row >= count) {
				row = 0;
			}

			QModelIndex index = druglist->model()->index(row, 0);
			druglist->setCurrentIndex(index);
		} else if (Qt::Key_Up == key) {
			// 按向下方向键时，移动光标选中上一个完成列表中的项
			int row = currentIndex.row() - 1;
			if (row < 0) {
				row = count - 1;
			}

			QModelIndex index = druglist->model()->index(row, 0);
			druglist->setCurrentIndex(index);
		} else if (Qt::Key_Escape == key) {
			// 按下Esc键时，隐藏完成列表
			druglist->hide();
		} else if (Qt::Key_Enter == key || Qt::Key_Return == key) {
			// 按下回车键时，使用完成列表中选中的项，并隐藏完成列表
			if (currentIndex.isValid()) {
				QString text = druglist->currentIndex().data().toString();
				ui.lineEdit_code->setText(text);
			}

			druglist->hide();
		} else {
			// 其他情况，隐藏完成列表，并使用QLineEdit的键盘按下事件
			druglist->hide();
			//QLineEdit::keyPressEvent(e);
		}
	} else {
		//QLineEdit::keyPressEvent(e);
	}
}