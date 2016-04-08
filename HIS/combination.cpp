#include "combination.h"
#include "connectsql.h"
#include "package.h"
extern ConnectSql sql;
Combination::Combination(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	initUI();
}
void Combination::initUI()
{
	list_widget = new QListWidget(this);
	list_widget->setWindowFlags(Qt::FramelessWindowHint);
	list_widget->close();
	installEventFilter(list_widget);

	ui.tableWidget->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
	ui.tableWidget->setStyleSheet("QTableWidget{border: 1px solid gray;	background-color: transparent;	selection-color: grey;}");
	ui.tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section {background-color:white;color: black;padding-left: 4px;border: 1px solid #6c6c6c;};"
		"color: white;padding-left: 4px;border: 1px solid #6c6c6c;}"
		"QHeaderView::section:checked{background-color: white;color: black;}");	

	connect(ui.tableWidget,SIGNAL(cellChanged(int,int)),this,SLOT(getItem(int,int)));

	ui.saveButton->setEnabled(false);
	ui.editButton->setEnabled(false);
	ui.discardButton->setEnabled(false);
	ui.deleteButton->setEnabled(false);
	ui.addrowButton->setEnabled(false);
	ui.deleterowButton->setEnabled(false);
}
void Combination::on_saveButton_clicked()
{

	if (ui.lineEdit->text()=="")
	{

		QMessageBox box(QMessageBox::Warning,QString::fromLocal8Bit("警告"),QString::fromLocal8Bit("请填写套餐名称"));
		box.setStandardButtons (QMessageBox::Ok);
		box.setButtonText (QMessageBox::Ok,QString::fromLocal8Bit("确 定"));
		box.exec();
		return;
	}
	if (ui.lineEdit_2->text()=="")
	{

		QMessageBox box(QMessageBox::Warning,QString::fromLocal8Bit("警告"),QString::fromLocal8Bit("请填写助记符"));
		box.setStandardButtons (QMessageBox::Ok);
		box.setButtonText (QMessageBox::Ok,QString::fromLocal8Bit("确 定"));
		box.exec();
		return;
	}
	int irows = ui.tableWidget->model()->rowCount();   //行总数
	for (int i=0;i<irows;i++)
	{
		QTableWidgetItem*item = ui.tableWidget->item(i,0);
		if( ui.tableWidget->item(i,0)==NULL) continue;

		if( ui.tableWidget->item(i,0)==NULL||ui.tableWidget->item(i,0)->text()=="")
		{
			QMessageBox box(QMessageBox::Warning,QString::fromLocal8Bit("警告"),QString::fromLocal8Bit("请选择药品"));
			box.setStandardButtons (QMessageBox::Ok);
			box.setButtonText (QMessageBox::Ok,QString::fromLocal8Bit("确 定"));
			box.exec();
			return;
		}
		if( ui.tableWidget->item(i,5)==NULL||ui.tableWidget->item(i,5)->text()=="")
		{
			QMessageBox box(QMessageBox::Warning,QString::fromLocal8Bit("警告"),QString::fromLocal8Bit("请填写数量"));
			box.setStandardButtons (QMessageBox::Ok);
			box.setButtonText (QMessageBox::Ok,QString::fromLocal8Bit("确 定"));
			box.exec();
			return;
		}
		if( ui.tableWidget->item(i,6)==NULL||ui.tableWidget->item(i,6)->text()=="")
		{
			QMessageBox box(QMessageBox::Warning,QString::fromLocal8Bit("警告"),QString::fromLocal8Bit("请填写门诊单价"));
			box.setStandardButtons (QMessageBox::Ok);
			box.setButtonText (QMessageBox::Ok,QString::fromLocal8Bit("确 定"));
			box.exec();
			return;
		}
		if( ui.tableWidget->item(i,7)==NULL||ui.tableWidget->item(i,7)->text()=="")
		{
			QMessageBox box(QMessageBox::Warning,QString::fromLocal8Bit("警告"),QString::fromLocal8Bit("请填写住院单价"));
			box.setStandardButtons (QMessageBox::Ok);
			box.setButtonText (QMessageBox::Ok,QString::fromLocal8Bit("确 定"));
			box.exec();
			return;
		}
	}
	QSqlQuery query(*sql.db);		

	query.prepare("INSERT INTO sys_package VALUES (?,?)");
	query.bindValue(0,ui.lineEdit_2->text());
	query.bindValue(1,ui.lineEdit->text());
	query.exec();

	int row = ui.tableWidget->rowCount();
	for (int i=0;i<row;i++)
	{
		query.prepare("INSERT INTO sys_package_detail VALUES (?,?, ?, ?, ?, ?, ?, ?, ?, ?)");
		query.bindValue(0,ui.lineEdit_2->text());
		query.bindValue(1,ui.lineEdit->text());
		query.bindValue(2,ui.tableWidget->item(i,0)->text());
		query.bindValue(3,ui.tableWidget->item(i,1)->text());
		query.bindValue(4,ui.tableWidget->item(i,2)->text());
		query.bindValue(5,ui.tableWidget->item(i,3)->text());
		query.bindValue(6,ui.tableWidget->item(i,4)->text());
		query.bindValue(7,ui.tableWidget->item(i,5)->text().toInt());
		query.bindValue(8,ui.tableWidget->item(i,6)->text().toDouble());
		query.bindValue(9,ui.tableWidget->item(i,7)->text().toDouble());
		query.exec();
	}

	ui.editButton->setEnabled(true);
	ui.saveButton->setEnabled(false);
	ui.deleteButton->setEnabled(false);
	ui.addrowButton->setEnabled(false);
	ui.deleterowButton->setEnabled(false);
	ui.discardButton->setEnabled(false);
}
void Combination::on_discardButton_clicked()
{
	ui.lineEdit->clear();
	ui.lineEdit_2->clear();
	ui.tableWidget->setRowCount(0);
}
void Combination::on_addButton_clicked()
{
	on_discardButton_clicked();
	ui.editButton->setEnabled(false);
	ui.deleteButton->setEnabled(false);
	ui.saveButton->setEnabled(true);
	ui.discardButton->setEnabled(true);
	ui.addrowButton->setEnabled(true);
	ui.deleterowButton->setEnabled(true);
	ui.tableWidget->insertRow(0);
}
void Combination::on_editButton_clicked()
{
	ui.deleteButton->setEnabled(true);
	ui.saveButton->setEnabled(true);
	ui.addrowButton->setEnabled(true);
	ui.deleterowButton->setEnabled(true);
}
void Combination::on_deleteButton_clicked()
{
	QMessageBox box(QMessageBox::Warning,QString::fromLocal8Bit("警告"),QString::fromLocal8Bit("确定删除？"));
	box.setStandardButtons (QMessageBox::Ok|QMessageBox::Cancel);
	box.setButtonText (QMessageBox::Ok,QString::fromLocal8Bit("确 定"));
	box.setButtonText (QMessageBox::Cancel,QString::fromLocal8Bit("取 消"));
	if(box.exec()==QMessageBox::Ok)
	{
		QSqlQuery query(*sql.db);		
		QString strname=ui.lineEdit->text();
		QString strsql = "delete from sys_package where name ='"+strname+"'"; 
		query.exec(strsql);
		strsql = "delete from sys_package_detail where name ='"+strname+"'"; 
		query.exec(strsql);
		on_discardButton_clicked();
		ui.saveButton->setEnabled(false);
		ui.editButton->setEnabled(false);
		ui.discardButton->setEnabled(false);
		ui.deleteButton->setEnabled(false);
		ui.addrowButton->setEnabled(false);
		ui.deleterowButton->setEnabled(false);
	}
}
void Combination::on_addrowButton_clicked()
{
	int irows = ui.tableWidget->model()->rowCount();
	ui.tableWidget->insertRow(irows);
}
void Combination::on_deleterowButton_clicked()
{
	int rows = ui.tableWidget->model()->rowCount();  
	ui.tableWidget->setRowCount(rows-1);
}
void Combination::getItem(int row,int column)
{
	if (column==0)
	{
		list_widget->close();
		QString strText;
		if(ui.tableWidget->item(row,0)==NULL)  return;

		strText =  ui.tableWidget->item(row,0)->text();
		if(strText.at(0)== QChar('1')) return;

		//list_widget->setGeometry(103, 160+row*30, 150, 280);

		QPoint GlobalPoint(ui.addButton->mapToGlobal(QPoint(0, 0)));//获取控件在窗体中的坐标
		list_widget->setGeometry(GlobalPoint.x(), GlobalPoint.y(), 150, 280);

		list_widget->show();
		QSqlQuery query(*sql.db);	
		strText =  ui.tableWidget->item(row,0)->text();
		QString strsql= QString("select * from sys_drugdictionary where abbr like '%%1%'or name like'%%2%'  ").arg(strText).arg(strText);
		query.exec(strsql);
		QStringList list;
		list_widget->clear();
		while(query.next())
		{
			QString str = query.value(1).toString();
			list.append(str);
		}
		list_widget->addItems(list);
	}
}
void Combination::keyPressEvent(QKeyEvent *e) {
	if (!list_widget->isHidden()) {
		int key = e->key();
		int count = list_widget->model()->rowCount();
		QModelIndex currentIndex = list_widget->currentIndex();

		if (Qt::Key_Down == key) {
			int row = currentIndex.row() + 1;
			if (row >= count) {
				row = 0;
			}

			QModelIndex index = list_widget->model()->index(row, 0);
			list_widget->setCurrentIndex(index);
		} else if (Qt::Key_Up == key) {
			int row = currentIndex.row() - 1;
			if (row < 0) {
				row = count - 1;
			}

			QModelIndex index = list_widget->model()->index(row, 0);
			list_widget->setCurrentIndex(index);
		} else if (Qt::Key_Escape == key) {
			list_widget->hide();
		} else if (Qt::Key_Enter == key || Qt::Key_Return == key) {
			if (currentIndex.isValid()) {
				QString strName = list_widget->currentIndex().data().toString();

				int row = ui.tableWidget->currentRow();
				QSqlQuery query(*sql.db);	
				QString strsql= "select * from sys_drugdictionary where name='"+strName+"'";
				query.exec(strsql);
				while(query.next())
				{
					ui.tableWidget->setItem(row,0,new QTableWidgetItem(query.value(22).toString()));
					ui.tableWidget->setItem(row,1,new QTableWidgetItem(query.value(1).toString()));
					ui.tableWidget->setItem(row,2,new QTableWidgetItem(query.value(4).toString()));
					ui.tableWidget->setItem(row,3,new QTableWidgetItem(query.value(5).toString()));
					ui.tableWidget->setItem(row,4,new QTableWidgetItem(query.value(8).toString()));
					ui.tableWidget->setItem(row,6,new QTableWidgetItem(query.value(15).toString()));//
					ui.tableWidget->setItem(row,7,new QTableWidgetItem(query.value(17).toString()));//
				}
			}

			list_widget->hide();
		} else {
			list_widget->hide();
			//QLineEdit::keyPressEvent(e);
		}
	} else {
		//QLineEdit::keyPressEvent(e);
	}
}
void Combination::on_exitButton_clicked()
{	

	QMessageBox box(QMessageBox::Warning,QString::fromLocal8Bit("警告"),QString::fromLocal8Bit("确认退出？"));
	box.setStandardButtons (QMessageBox::Ok|QMessageBox::Cancel);
	box.setButtonText (QMessageBox::Ok,QString::fromLocal8Bit("确 定"));
	box.setButtonText (QMessageBox::Cancel,QString::fromLocal8Bit("取 消"));
	if(box.exec()==QMessageBox::Ok)
	{
		this->close();
	}
}
void Combination::on_queryButton_clicked()
{	
	Package*package = new Package;
	package->setWindowModality(Qt::WindowModal);
	package->setWindowTitle(QString::fromLocal8Bit("套餐查询"));
	package->show();
}
Combination::~Combination()
{

}
