#include "drugdictionaryadd.h"
#include "connectsql.h"
#include <QTreeWidgetItem>
#include <QTextCodec>
#include "initial.h"
extern ConnectSql sql;

Drugdictionaryadd::Drugdictionaryadd(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	initUI();
	connect(ui.lineEdit, SIGNAL(textChanged(const QString &)), this, SLOT(showinfo(const QString &)));
}
void Drugdictionaryadd::initUI()
{
	QSqlQuery query(*sql.db);		
	query.exec("select * from mz_classification");
	QStringList list;
	while(query.next())
	{
		QString str = query.value(1).toString()+"-"+ query.value(2).toString();
		list.append(str);
	}
	ui.mzclascomboBox->addItems(list);
	list.clear();
	query.exec("select * from mz_receipt");
	while(query.next())
	{
		QString str = query.value(1).toString()+"-"+ query.value(2).toString();
		list.append(str);
	}
	ui.mzreceiptcomboBox->addItems(list);
	list.clear();
	query.exec("select * from zy_classification");
	while(query.next())
	{
		QString str = query.value(1).toString()+"-"+  query.value(2).toString();
		list.append(str);
	}
	ui.comboBox_3->addItems(list);
	list.clear();
	query.exec("select * from zy_receipt");
	while(query.next())
	{
		QString str = query.value(1).toString()+"-"+  query.value(2).toString();
		list.append(str);
	}
	ui.comboBox_4->addItems(list);
	list.clear();
	query.exec("select * from sys_dictionarytype");
	while(query.next())
	{
		QString str = query.value(2).toString();
		list.append(str);
	}
	ui.comboBox_7->addItems(list);
	list.clear();
	list.append(QString::fromLocal8Bit("个"));
	list.append(QString::fromLocal8Bit("公斤"));
	list.append(QString::fromLocal8Bit("袋"));
	list.append(QString::fromLocal8Bit("箱"));
	list.append(QString::fromLocal8Bit("吨"));
	list.append(QString::fromLocal8Bit("桶"));
	list.append(QString::fromLocal8Bit("副"));
	list.append(QString::fromLocal8Bit("盒"));
	list.append(QString::fromLocal8Bit("张"));
	list.append(QString::fromLocal8Bit("串"));
	list.append(QString::fromLocal8Bit("捆"));
	list.append(QString::fromLocal8Bit("套"));
	list.append(QString::fromLocal8Bit("打"));
	list.append(QString::fromLocal8Bit("把"));
	list.append(QString::fromLocal8Bit("元"));
	list.append(QString::fromLocal8Bit("克"));
	list.append(QString::fromLocal8Bit("次"));
	list.append(QString::fromLocal8Bit("方"));
	list.append(QString::fromLocal8Bit("只"));
	ui.comboBox_5->addItems(list);
	ui.comboBox_8->addItems(list);
	IsEdit=false;
}
void Drugdictionaryadd::showinfo(const QString &text)
{
	Initial*init = new Initial;
	QString str = init->getPinyinByName(QString::fromLocal8Bit("拉西"));
	//ui.lineEdit_2->setText(init->GetIntial(text));
 }
void Drugdictionaryadd::on_saveButton_clicked()
{
	
	QSqlQuery query(*sql.db);
	int count =0;
	query.prepare("select *from sys_drugdictionary");
	query.exec();
	while(query.next())
	{
		count++;
	}
	count++;
	QString strdrugname = ui.lineEdit->text().trimmed();
	if(IsEdit)
	{
		query.prepare("select *from sys_drugdictionary where name = '"+strdrugname+"'");
		query.exec();
		while (query.next())
		{
			count = query.value(0).toInt();
		}
		query.prepare("delete from sys_drugdictionary where name = '"+strdrugname+"'");
		query.exec();
	}
	if (ui.lineEdit->text()=="") return;

	query.prepare("INSERT INTO sys_drugdictionary VALUES (?,?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)");
	query.bindValue(0, count);
	query.bindValue(1, ui.lineEdit->text());
	query.bindValue(2, ui.lineEdit_2->text());
	query.bindValue(3, NULL);
	query.bindValue(4, ui.lineEdit_5->text());
	query.bindValue(5, ui.lineEdit_6->text());
	query.bindValue(6, ui.comboBox_5->currentText());
	query.bindValue(7, ui.lineEdit_9->text());
	query.bindValue(8,  ui.comboBox_5->currentText());
	query.bindValue(9, NULL);
	query.bindValue(10, ui.mzreceiptcomboBox->currentText());
	query.bindValue(11,  ui.comboBox_4->currentText());
	query.bindValue(12, ui.mzclascomboBox->currentText());
	query.bindValue(13, ui.comboBox_3->currentText());
	query.bindValue(14, ui.comboBox_7->currentText());
	query.bindValue(15, ui.lineEdit_7->text().toDouble());
	query.bindValue(16, NULL);
	query.bindValue(17, ui.lineEdit_8->text().toDouble());
	query.bindValue(18, NULL);
	query.bindValue(19, NULL);
	query.bindValue(20, NULL);
	query.bindValue(21, NULL);
	query.bindValue(22, ui.lineEdit_3->text());
	query.bindValue(23, NULL);
	if(query.exec())
	{
		QMessageBox box(QMessageBox::Warning,QString::fromLocal8Bit("提示"),QString::fromLocal8Bit("保存成功！"));
		box.setStandardButtons (QMessageBox::Ok);
		box.setButtonText (QMessageBox::Ok,QString::fromLocal8Bit("确 定"));
		box.exec();
		this->close();
		return;
	}
	
}
void Drugdictionaryadd::on_cancelButton_clicked()
{
	this->close();
}
void Drugdictionaryadd::edit(QStringList list)
{
	IsEdit=true;
	ui.lineEdit->setText(list.at(2));
	ui.lineEdit_2->setText(list.at(3));
	ui.lineEdit_3->setText(list.at(1));

	ui.lineEdit_5->setText(list.at(5));
	ui.lineEdit_6->setText(list.at(6));

	ui.lineEdit_7->setText(list.at(16));
	ui.lineEdit_8->setText(list.at(18));
	ui.lineEdit_9->setText(list.at(8));

	//for (int i =0;i<ui.comboBox_5->count();i++)
	//{
	//	if (ui.comboBox_5->itemText(i)==list.at(7))
	//	{
	//		ui.comboBox_5->setCurrentIndex(i);
	//	}
	//}
	ui.comboBox_5->setItemText(0,list.at(7));


	//for (int i =0;i<ui.mzreceiptcomboBox->count();i++)
	//{
	//	if (ui.mzreceiptcomboBox->itemText(i)==list.at(11))
	//	{
	//		ui.mzreceiptcomboBox->setCurrentIndex(i);
	//	}
	//}
	ui.mzreceiptcomboBox->setItemText(0,list.at(11));


	//for (int i =0;i<ui.mzclascomboBox->count();i++)
	//{
	//	if (ui.mzclascomboBox->itemText(i)==list.at(13))
	//	{
	//		ui.mzclascomboBox->setCurrentIndex(i);
	//	}
	//}
	ui.mzclascomboBox->setItemText(0,list.at(13));


	//for (int i =0;i<ui.comboBox_4->count();i++)
	//{
	//	if (ui.comboBox_4->itemText(i)==list.at(12))
	//	{
	//		ui.comboBox_4->setCurrentIndex(i);
	//	}
	//}
	ui.comboBox_4->setItemText(0,list.at(12));

	//for (int i =0;i<ui.comboBox_3->count();i++)
	//{
	//	if (ui.comboBox_3->itemText(i)==list.at(14))
	//	{
	//		ui.comboBox_3->setCurrentIndex(i);
	//	}
	//}
	ui.comboBox_3->setItemText(0,list.at(14));

	//for (int i =0;i<ui.comboBox_7->count();i++)
	//{
	//	if (ui.comboBox_7->itemText(i)==list.at(15))
	//	{
	//		ui.comboBox_7->setCurrentIndex(i);
	//	}
	//}
	ui.comboBox_7->setItemText(0,list.at(15));
}
Drugdictionaryadd::~Drugdictionaryadd()
{

}
