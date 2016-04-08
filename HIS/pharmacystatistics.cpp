#include "pharmacystatistics.h"
#include <QtGui>
#include "connectsql.h"
#include "clinicdrugfilter.h"
#include "package.h"
#include "pharmacyreceipt.h"
#include "pharmacycheck.h"
#include "odbcexcel.h"
static int icount;
extern ConnectSql sql;

PharmacyStatistics::PharmacyStatistics(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	druglist = new QListView(this);
	model = new QStringListModel(this);
	druglist->setWindowFlags(Qt::ToolTip);
	initUI();
	setStyleSheet("QTableWidget{border: 1px solid gray;	background-color: transparent;	selection-color: grey;}");
	ui.tableWidget->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
	ui.tableWidget->setStyleSheet("QTableWidget{border: 1px solid gray;	background-color: transparent;	selection-color: grey;}");
	ui.tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section {background-color:white;color: black;padding-left: 4px;border: 1px solid #6c6c6c;};"
		"color: white;padding-left: 4px;border: 1px solid #6c6c6c;}"
		"QHeaderView::section:checked{background-color: white;color: black;}");	
	ui.tableWidget->installEventFilter(this);//ע���¼�������
	connect(ui.lineEdit_DrugNo,SIGNAL(textChanged(const QString &)),this,SLOT(DrugName(const QString &)));
	connect(ui.tableWidget,SIGNAL(cellDoubleClicked(int,int)),this,SLOT(getItem(int,int)));
	connect(druglist, SIGNAL(clicked(const QModelIndex &)), this, SLOT(completeText(const QModelIndex &)));
}
void PharmacyStatistics::getItem(int row,int column)
{
	QString strFindItem;
	strFindItem = ui.comboBox_find->currentText();
	std::string strStd= strFindItem.toStdString();
	QTextCodec *code = QTextCodec::codecForName("gb18030");
	 // ���codeΪ0����ʾ�����еĻ�����û��װgb18030�ַ���������һ�������windowsϵͳ�ж���װ����һ�ַ���
	if (code)   
		strStd= code->fromUnicode(strFindItem).data();
	/*	ui.tabWidget->hide();*/
	
	///*charge->setWindowFlags(Qt::SubWindow);*/
	///*charge->setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowCloseButtonHint);*/
	//
	//
	
	if(strStd == "�ջ���¼"||strStd == "�˻���¼")
	{
		PharmacyReceipt *receipt = new PharmacyReceipt();
		QString strNo= ui.tableWidget->item(row,0)->text();
		receipt->resize(943,575);
		receipt->show();
		receipt->edit(strNo);
	}
	if(strStd == "�̵��¼")
	{
		PharmacyCheck *check = new PharmacyCheck();
		QString strNo= ui.tableWidget->item(row,0)->text();
		check->resize(943,575);
		check->show();
		check->edit(strNo);
	}
	
	//clinicchargedlg chargedlg = new clinicchargedlg;
	//chargedlg.setWindowModality(Qt::ApplicationModal); //��������ǰ����֮������еĴ���
	//chargedlg.exec();
	//QString strNo= ui.tableWidget->item(row,10)->text();
	//chargedlg->edit(strNo);

	/*ConnectDB connectdatase;
	connectdatase.exec();*/
}
void PharmacyStatistics::DrugName(const QString &text)
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

	//druglist->move(x, y);
	//druglist->setGeometry(this->x()+822, this->y()+165, 50, 100);
	QPoint GlobalPoint(ui.lineEdit_DrugNo->mapToGlobal(QPoint(0, 0)));
	druglist->setGeometry(GlobalPoint.x(), GlobalPoint.y()+ui.lineEdit_DrugNo->height(), 60, 100);
	druglist->show();
}
void PharmacyStatistics::on_radioButton_clicked()
{
	if(!ui.radioButton->isChecked())
	{
		ui.lineEdit_DrugNo->setEnabled(false);
		//ui.lineEdit_DrugName->setEnabled(false);
	}
	if(ui.radioButton->isChecked())
	{
		ui.lineEdit_DrugNo->setEnabled(true);
		//ui.lineEdit_DrugName->setEnabled(true);
	}
		
}
void PharmacyStatistics::initUI()
{
	
	iRow=0;
	QSqlQuery query(*sql.db);		
	QDateTime current_date_time = QDateTime::currentDateTime();
	//ui.dateTimeEdit_1->setDateTime(current_date_time);
	//ui.dateTimeEdit_2->setDateTime(current_date_time);

	ui.dateTimeEdit_1->setDateTime(current_date_time);
	QTime time= QTime::fromString("00:00:00", "hh:mm:ss");
	ui.dateTimeEdit_1->setTime(time);
	ui.dateTimeEdit_2->setDateTime(current_date_time);
	time= QTime::fromString("23:59:59", "hh:mm:ss");
	ui.dateTimeEdit_2->setTime(time);

	//ui.saveButton->setEnabled(true);
	//ui.discardButton->setEnabled(true);
	ui.tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);  //����ѡ�еķ�ʽ
	QTextCodec::setCodecForTr(QTextCodec::codecForName("gb18030"));
	if(!ui.radioButton->isChecked())
	{
		ui.lineEdit_DrugNo->setEnabled(false);
		//ui.lineEdit_DrugName->setEnabled(false);
	}
	if(ui.radioButton->isChecked())
	{
		ui.lineEdit_DrugNo->setEnabled(true);
		//ui.lineEdit_DrugName->setEnabled(true);
	}
}
void PharmacyStatistics::on_findButton_clicked()
{
	QString strFindItem;
	QString strDate1;
	QString strDate2;
	QString strsql;
	QString strName;
	strFindItem = ui.comboBox_find->currentText();
	QDateTime time;	
	time = ui.dateTimeEdit_1->dateTime();
	strDate1 = time.toString("yyyy-MM-dd hh:mm:ss");

	time = ui.dateTimeEdit_2->dateTime();
	strDate2 = time.toString("yyyy-MM-dd hh:mm:ss");

	int rows = ui.tableWidget->model()->rowCount();   //������
	for (int i=0;i<rows+1;i++)
	{
		ui.tableWidget->removeRow(rows - i);
	}


	QSqlQuery query(*sql.db);

	std::string strStd= strFindItem.toStdString();
	QTextCodec *code = QTextCodec::codecForName("gb18030");
	 // ���codeΪ0����ʾ�����еĻ�����û��װgb18030�ַ���������һ�������windowsϵͳ�ж���װ����һ�ַ���
	if (code)   
		strStd= code->fromUnicode(strFindItem).data();

	rows = ui.tableWidget->model()->rowCount();   //������
		for (int i=0;i<rows+1;i++)
		{
			ui.tableWidget->removeRow(rows - i);
		}

	if(strStd == "�ջ���¼")
	{
		QString strType = QString::number(1);
		ui.tableWidget->setColumnCount(9); //��������
		ui.tableWidget->horizontalHeader()->setClickable(false); //���ñ�ͷ���ɵ����Ĭ�ϵ�����������

		QStringList header;
		header<<tr("����")<<tr("����")<<tr("����")<<tr("���")<<tr("��������")<<tr("��λ")<<tr("�ջ�����")<<tr("�۸�")<<tr("�ܶ�");
		ui.tableWidget->setHorizontalHeaderLabels(header);

		ui.tableWidget->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
		ui.tableWidget->setStyleSheet("QTableWidget{border: 1px solid gray;	background-color: transparent;	selection-color: white;}");
		ui.tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section {background-color:white;color: black;padding-left: 4px;border: 1px solid #6c6c6c;};"
		"color: white;padding-left: 4px;border: 1px solid #6c6c6c;}"
		"QHeaderView::section:checked{background-color: white;color: black;}");	

		if(ui.radioButton->isChecked())
		{
			int itotalNum=0;
			double dtotalPrice=0;
			strName = ui.lineEdit_DrugNo->text();
			strsql= "select * from yf_receipt where isinput= '"+strType+"'and name='"+strName+"'and date between '"+strDate1+"' and '"+strDate2+"'";
			query.exec(strsql);
			iRow = 0;
			while(query.next())
			{
				int rows = ui.tableWidget->model()->rowCount();   //������
				ui.tableWidget->insertRow(rows);
				iRow=rows;
				ui.tableWidget->setItem(iRow,0,new QTableWidgetItem(query.value(1).toString()));
				ui.tableWidget->setItem(iRow,1,new QTableWidgetItem(query.value(2).toString()));
				ui.tableWidget->setItem(iRow,2,new QTableWidgetItem(query.value(6).toString()));
				ui.tableWidget->setItem(iRow,3,new QTableWidgetItem(query.value(7).toString()));
				ui.tableWidget->setItem(iRow,4,new QTableWidgetItem(query.value(8).toString()));
				ui.tableWidget->setItem(iRow,5,new QTableWidgetItem(query.value(10).toString()));//
				ui.tableWidget->setItem(iRow,6,new QTableWidgetItem(query.value(11).toString()));//
				ui.tableWidget->setItem(iRow,7,new QTableWidgetItem(query.value(12).toString()));//
				ui.tableWidget->setItem(iRow,8,new QTableWidgetItem(query.value(13).toString()));//
				int num = query.value(11).toInt();
				itotalNum = itotalNum + num;
				double price = query.value(13).toInt();
				dtotalPrice = dtotalPrice + price;
				//iRow ++;
			}
			QString strProfit = QString::number(itotalNum);
			ui.lineEdit_TotalNum->setText(strProfit);
			strProfit = QString::number(dtotalPrice);
			ui.lineEdit_TotalPrice->setText(strProfit);
		}
		if(!ui.radioButton->isChecked())
		{
			int itotalNum =0;
			double dtotalPrice=0;
			strName = ui.lineEdit_DrugNo->text();
			strsql= "select * from yf_receipt where isinput= '"+strType+"'and date between '"+strDate1+"' and '"+strDate2+"'";
			query.exec(strsql);
			iRow = 0;
			while(query.next())
			{
				int rows = ui.tableWidget->model()->rowCount();   //������
				ui.tableWidget->insertRow(rows);
				iRow=rows;
				ui.tableWidget->setItem(iRow,0,new QTableWidgetItem(query.value(1).toString()));
				ui.tableWidget->setItem(iRow,1,new QTableWidgetItem(query.value(2).toString()));
				ui.tableWidget->setItem(iRow,2,new QTableWidgetItem(query.value(6).toString()));
				ui.tableWidget->setItem(iRow,3,new QTableWidgetItem(query.value(7).toString()));
				ui.tableWidget->setItem(iRow,4,new QTableWidgetItem(query.value(8).toString()));
				ui.tableWidget->setItem(iRow,5,new QTableWidgetItem(query.value(10).toString()));//
				ui.tableWidget->setItem(iRow,6,new QTableWidgetItem(query.value(11).toString()));//
				ui.tableWidget->setItem(iRow,7,new QTableWidgetItem(query.value(12).toString()));//
				ui.tableWidget->setItem(iRow,8,new QTableWidgetItem(query.value(13).toString()));//
				int num = query.value(11).toInt();
				itotalNum = itotalNum + num;
				double price = query.value(13).toInt();
				dtotalPrice = dtotalPrice + price;
			}
			QString strProfit = QString::number(itotalNum);
			ui.lineEdit_TotalNum->setText(strProfit);
			strProfit = QString::number(dtotalPrice);
			ui.lineEdit_TotalPrice->setText(strProfit);
		}

	}
	else if(strStd == "�˻���¼")
	{
		QString strType = QString::number(2);
		ui.tableWidget->setColumnCount(9); //��������
		ui.tableWidget->horizontalHeader()->setClickable(false); //���ñ�ͷ���ɵ����Ĭ�ϵ�����������

		QStringList header;
		header<<tr("����")<<tr("����")<<tr("����")<<tr("���")<<tr("��������")<<tr("��λ")<<tr("�˻�����")<<tr("�۸�")<<tr("�ܶ�");
		ui.tableWidget->setHorizontalHeaderLabels(header);

		ui.tableWidget->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
		ui.tableWidget->setStyleSheet("QTableWidget{border: 1px solid gray;	background-color: transparent;	selection-color: white;}");
		ui.tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section {background-color:white;color: black;padding-left: 4px;border: 1px solid #6c6c6c;};"
		"color: white;padding-left: 4px;border: 1px solid #6c6c6c;}"
		"QHeaderView::section:checked{background-color: white;color: black;}");	

		if(ui.radioButton->isChecked())
		{
			int itotalNum=0;
			double dtotalPrice=0;
			strName = ui.lineEdit_DrugNo->text();
			strsql= "select * from yf_receipt where isinput= '"+strType+"'and name='"+strName+"'and date between '"+strDate1+"' and '"+strDate2+"'";
			query.exec(strsql);
			iRow = 0;
			while(query.next())
			{
				int rows = ui.tableWidget->model()->rowCount();   //������
				ui.tableWidget->insertRow(rows);
				iRow=rows;
				ui.tableWidget->setItem(iRow,0,new QTableWidgetItem(query.value(1).toString()));
				ui.tableWidget->setItem(iRow,1,new QTableWidgetItem(query.value(2).toString()));
				ui.tableWidget->setItem(iRow,2,new QTableWidgetItem(query.value(6).toString()));
				ui.tableWidget->setItem(iRow,3,new QTableWidgetItem(query.value(7).toString()));
				ui.tableWidget->setItem(iRow,4,new QTableWidgetItem(query.value(8).toString()));
				ui.tableWidget->setItem(iRow,5,new QTableWidgetItem(query.value(10).toString()));//
				ui.tableWidget->setItem(iRow,6,new QTableWidgetItem(query.value(11).toString()));//
				ui.tableWidget->setItem(iRow,7,new QTableWidgetItem(query.value(12).toString()));//
				ui.tableWidget->setItem(iRow,8,new QTableWidgetItem(query.value(13).toString()));//
				int num = query.value(11).toInt();
				itotalNum = itotalNum + num;
				double price = query.value(13).toDouble();
				dtotalPrice = dtotalPrice + price;
				//iRow ++;
			}
			QString strProfit = QString::number(itotalNum);
			ui.lineEdit_TotalNum->setText(strProfit);
			strProfit = QString::number(dtotalPrice);
			ui.lineEdit_TotalPrice->setText(strProfit);
		}
		if(!ui.radioButton->isChecked())
		{
			int itotalNum =0;
			double dtotalPrice=0;
			strName = ui.lineEdit_DrugNo->text();
			strsql= "select * from yf_receipt where isinput= '"+strType+"'and date between '"+strDate1+"' and '"+strDate2+"'";
			query.exec(strsql);
			iRow = 0;
			while(query.next())
			{
				int rows = ui.tableWidget->model()->rowCount();   //������
				ui.tableWidget->insertRow(rows);
				iRow=rows;
				ui.tableWidget->setItem(iRow,0,new QTableWidgetItem(query.value(1).toString()));
				ui.tableWidget->setItem(iRow,1,new QTableWidgetItem(query.value(2).toString()));
				ui.tableWidget->setItem(iRow,2,new QTableWidgetItem(query.value(6).toString()));
				ui.tableWidget->setItem(iRow,3,new QTableWidgetItem(query.value(7).toString()));
				ui.tableWidget->setItem(iRow,4,new QTableWidgetItem(query.value(8).toString()));
				ui.tableWidget->setItem(iRow,5,new QTableWidgetItem(query.value(10).toString()));//
				ui.tableWidget->setItem(iRow,6,new QTableWidgetItem(query.value(11).toString()));//
				ui.tableWidget->setItem(iRow,7,new QTableWidgetItem(query.value(12).toString()));//
				ui.tableWidget->setItem(iRow,8,new QTableWidgetItem(query.value(13).toString()));//
				int num = query.value(11).toInt();
				itotalNum = itotalNum + num;
				double price = query.value(13).toDouble();
				dtotalPrice = dtotalPrice + price;
			}
			QString strProfit = QString::number(itotalNum);
			ui.lineEdit_TotalNum->setText(strProfit);
			strProfit = QString::number(dtotalPrice);
			ui.lineEdit_TotalPrice->setText(strProfit);
		}
	}
	else if(strStd == "���ۼ�¼")
	{
		
		ui.tableWidget->setColumnCount(7); //��������
		ui.tableWidget->horizontalHeader()->setClickable(false); //���ñ�ͷ���ɵ����Ĭ�ϵ�����������

		QStringList header;
		header<<tr("����")<<tr("����")<<tr("����")<<tr("��λ")<<tr("��������")<<tr("�۸�")<<tr("�ܼ�");
		ui.tableWidget->setHorizontalHeaderLabels(header);

		ui.tableWidget->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
		ui.tableWidget->setStyleSheet("QTableWidget{border: 1px solid gray;	background-color: transparent;	selection-color: white;}");
		ui.tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section {background-color:white;color: black;padding-left: 4px;border: 1px solid #6c6c6c;};"
		"color: white;padding-left: 4px;border: 1px solid #6c6c6c;}"
		"QHeaderView::section:checked{background-color: white;color: black;}");	

		if(ui.radioButton->isChecked())
		{
			int itotalNum=0;
			double dtotalPrice=0;
			strName = ui.lineEdit_DrugNo->text();
			strsql= "select * from mz_chargedetail where itemname='"+strName+"'and date between '"+strDate1+"' and '"+strDate2+"'";
			query.exec(strsql);
			iRow = 0;
			while(query.next())
			{
				int rows = ui.tableWidget->model()->rowCount();   //������
				ui.tableWidget->insertRow(rows);
				iRow=rows;
				ui.tableWidget->setItem(iRow,0,new QTableWidgetItem(query.value(1).toString()));
				ui.tableWidget->setItem(iRow,1,new QTableWidgetItem(query.value(9).toString()));
				ui.tableWidget->setItem(iRow,2,new QTableWidgetItem(query.value(4).toString()));
				ui.tableWidget->setItem(iRow,3,new QTableWidgetItem(query.value(5).toString()));
				ui.tableWidget->setItem(iRow,4,new QTableWidgetItem(query.value(6).toString()));
				ui.tableWidget->setItem(iRow,5,new QTableWidgetItem(query.value(7).toString()));
				ui.tableWidget->setItem(iRow,6,new QTableWidgetItem(query.value(8).toString()));//
				int num = query.value(6).toInt();
				itotalNum = itotalNum + num;
				double price = query.value(8).toDouble();
				dtotalPrice = dtotalPrice + price;
			}
			QString strProfit = QString::number(itotalNum);
			ui.lineEdit_TotalNum->setText(strProfit);
			strProfit = QString::number(dtotalPrice);
			ui.lineEdit_TotalPrice->setText(strProfit);
		}
		if(!ui.radioButton->isChecked())
		{
			int itotalNum=0;
			double dtotalPrice=0;
			strName = ui.lineEdit_DrugNo->text();
			strsql= "select * from mz_chargedetail where date between '"+strDate1+"' and '"+strDate2+"'";
			query.exec(strsql);
			iRow = 0;
			while(query.next())
			{
				int rows = ui.tableWidget->model()->rowCount();   //������
				ui.tableWidget->insertRow(rows);
				iRow=rows;
				ui.tableWidget->setItem(iRow,0,new QTableWidgetItem(query.value(1).toString()));
				ui.tableWidget->setItem(iRow,1,new QTableWidgetItem(query.value(9).toString()));
				ui.tableWidget->setItem(iRow,2,new QTableWidgetItem(query.value(4).toString()));
				ui.tableWidget->setItem(iRow,3,new QTableWidgetItem(query.value(5).toString()));
				ui.tableWidget->setItem(iRow,4,new QTableWidgetItem(query.value(6).toString()));
				ui.tableWidget->setItem(iRow,5,new QTableWidgetItem(query.value(7).toString()));
				ui.tableWidget->setItem(iRow,6,new QTableWidgetItem(query.value(8).toString()));//
				int num = query.value(6).toInt();
				itotalNum = itotalNum + num;
				double price = query.value(8).toDouble();
				dtotalPrice = dtotalPrice + price;
			}
			QString strProfit = QString::number(itotalNum);
			ui.lineEdit_TotalNum->setText(strProfit);
			strProfit = QString::number(dtotalPrice);
			ui.lineEdit_TotalPrice->setText(strProfit);
		}
	}
	else if(strStd == "��ҩ��¼")
	{
		QString strType = QString::number(3);
		ui.tableWidget->setColumnCount(9); //��������
		ui.tableWidget->horizontalHeader()->setClickable(false); //���ñ�ͷ���ɵ����Ĭ�ϵ�����������

		QStringList header;
		header<<tr("����")<<tr("����")<<tr("����")<<tr("���")<<tr("��������")<<tr("��λ")<<tr("�ջ�����")<<tr("�۸�")<<tr("�ܶ�");
		ui.tableWidget->setHorizontalHeaderLabels(header);

		ui.tableWidget->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
		ui.tableWidget->setStyleSheet("QTableWidget{border: 1px solid gray;	background-color: transparent;	selection-color: white;}");
		ui.tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section {background-color:white;color: black;padding-left: 4px;border: 1px solid #6c6c6c;};"
		"color: white;padding-left: 4px;border: 1px solid #6c6c6c;}"
		"QHeaderView::section:checked{background-color: white;color: black;}");	

		if(ui.radioButton->isChecked())
		{
			int itotalNum=0;
			double dtotalPrice=0;
			strName = ui.lineEdit_DrugNo->text();
			strsql= "select * from yf_receipt where isinput= '"+strType+"'and name='"+strName+"'and date between '"+strDate1+"' and '"+strDate2+"'";
			query.exec(strsql);
			iRow = 0;
			while(query.next())
			{
				int rows = ui.tableWidget->model()->rowCount();   //������
				ui.tableWidget->insertRow(rows);
				iRow=rows;
				ui.tableWidget->setItem(iRow,0,new QTableWidgetItem(query.value(1).toString()));
				ui.tableWidget->setItem(iRow,1,new QTableWidgetItem(query.value(2).toString()));
				ui.tableWidget->setItem(iRow,2,new QTableWidgetItem(query.value(6).toString()));
				ui.tableWidget->setItem(iRow,3,new QTableWidgetItem(query.value(7).toString()));
				ui.tableWidget->setItem(iRow,4,new QTableWidgetItem(query.value(8).toString()));
				ui.tableWidget->setItem(iRow,5,new QTableWidgetItem(query.value(10).toString()));//
				ui.tableWidget->setItem(iRow,6,new QTableWidgetItem(query.value(11).toString()));//
				ui.tableWidget->setItem(iRow,7,new QTableWidgetItem(query.value(12).toString()));//
				ui.tableWidget->setItem(iRow,8,new QTableWidgetItem(query.value(13).toString()));//
				int num = query.value(11).toInt();
				itotalNum = itotalNum + num;
				double price = query.value(13).toDouble();
				dtotalPrice = dtotalPrice + price;
				//iRow ++;
			}
			QString strProfit = QString::number(itotalNum);
			ui.lineEdit_TotalNum->setText(strProfit);
			strProfit = QString::number(dtotalPrice);
			ui.lineEdit_TotalPrice->setText(strProfit);
		}
		if(!ui.radioButton->isChecked())
		{
			int itotalNum =0;
			double dtotalPrice=0;
			strName = ui.lineEdit_DrugNo->text();
			strsql= "select * from yf_receipt where isinput= '"+strType+"'and date between '"+strDate1+"' and '"+strDate2+"'";
			query.exec(strsql);
			iRow = 0;
			while(query.next())
			{
				int rows = ui.tableWidget->model()->rowCount();   //������
				ui.tableWidget->insertRow(rows);
				iRow=rows;
				ui.tableWidget->setItem(iRow,0,new QTableWidgetItem(query.value(1).toString()));
				ui.tableWidget->setItem(iRow,1,new QTableWidgetItem(query.value(2).toString()));
				ui.tableWidget->setItem(iRow,2,new QTableWidgetItem(query.value(6).toString()));
				ui.tableWidget->setItem(iRow,3,new QTableWidgetItem(query.value(7).toString()));
				ui.tableWidget->setItem(iRow,4,new QTableWidgetItem(query.value(8).toString()));
				ui.tableWidget->setItem(iRow,5,new QTableWidgetItem(query.value(10).toString()));//
				ui.tableWidget->setItem(iRow,6,new QTableWidgetItem(query.value(11).toString()));//
				ui.tableWidget->setItem(iRow,7,new QTableWidgetItem(query.value(12).toString()));//
				ui.tableWidget->setItem(iRow,8,new QTableWidgetItem(query.value(13).toString()));//
				int num = query.value(11).toInt();
				itotalNum = itotalNum + num;
				double price = query.value(13).toDouble();
				dtotalPrice = dtotalPrice + price;
			}
			QString strProfit = QString::number(itotalNum);
			ui.lineEdit_TotalNum->setText(strProfit);
			strProfit = QString::number(dtotalPrice);
			ui.lineEdit_TotalPrice->setText(strProfit);
		}
	}
	else if(strStd == "�����¼")
	{
		QString strType = QString::number(4);
				ui.tableWidget->setColumnCount(9); //��������
		ui.tableWidget->horizontalHeader()->setClickable(false); //���ñ�ͷ���ɵ����Ĭ�ϵ�����������

		QStringList header;
		header<<tr("����")<<tr("����")<<tr("����")<<tr("���")<<tr("��������")<<tr("��λ")<<tr("�ջ�����")<<tr("�۸�")<<tr("�ܶ�");
		ui.tableWidget->setHorizontalHeaderLabels(header);

		ui.tableWidget->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
		ui.tableWidget->setStyleSheet("QTableWidget{border: 1px solid gray;	background-color: transparent;	selection-color: white;}");
		ui.tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section {background-color:white;color: black;padding-left: 4px;border: 1px solid #6c6c6c;};"
		"color: white;padding-left: 4px;border: 1px solid #6c6c6c;}"
		"QHeaderView::section:checked{background-color: white;color: black;}");	

		if(ui.radioButton->isChecked())
		{
			int itotalNum=0;
			double dtotalPrice=0;
			strName = ui.lineEdit_DrugNo->text();
			strsql= "select * from yf_receipt where isinput= '"+strType+"'and name='"+strName+"'and date between '"+strDate1+"' and '"+strDate2+"'";
			query.exec(strsql);
			iRow = 0;
			while(query.next())
			{
				int rows = ui.tableWidget->model()->rowCount();   //������
				ui.tableWidget->insertRow(rows);
				iRow=rows;
				ui.tableWidget->setItem(iRow,0,new QTableWidgetItem(query.value(1).toString()));
				ui.tableWidget->setItem(iRow,1,new QTableWidgetItem(query.value(2).toString()));
				ui.tableWidget->setItem(iRow,2,new QTableWidgetItem(query.value(6).toString()));
				ui.tableWidget->setItem(iRow,3,new QTableWidgetItem(query.value(7).toString()));
				ui.tableWidget->setItem(iRow,4,new QTableWidgetItem(query.value(8).toString()));
				ui.tableWidget->setItem(iRow,5,new QTableWidgetItem(query.value(10).toString()));//
				ui.tableWidget->setItem(iRow,6,new QTableWidgetItem(query.value(11).toString()));//
				ui.tableWidget->setItem(iRow,7,new QTableWidgetItem(query.value(12).toString()));//
				ui.tableWidget->setItem(iRow,8,new QTableWidgetItem(query.value(13).toString()));//
				int num = query.value(11).toInt();
				itotalNum = itotalNum + num;
				double price = query.value(13).toDouble();
				dtotalPrice = dtotalPrice + price;
				//iRow ++;
			}
			QString strProfit = QString::number(itotalNum);
			ui.lineEdit_TotalNum->setText(strProfit);
			strProfit = QString::number(dtotalPrice);
			ui.lineEdit_TotalPrice->setText(strProfit);
		}
		if(!ui.radioButton->isChecked())
		{
			int itotalNum =0;
			double dtotalPrice=0;
			strName = ui.lineEdit_DrugNo->text();
			strsql= "select * from yf_receipt where isinput= '"+strType+"'and date between '"+strDate1+"' and '"+strDate2+"'";
			query.exec(strsql);
			iRow = 0;
			while(query.next())
			{
				int rows = ui.tableWidget->model()->rowCount();   //������
				ui.tableWidget->insertRow(rows);
				iRow=rows;
				ui.tableWidget->setItem(iRow,0,new QTableWidgetItem(query.value(1).toString()));
				ui.tableWidget->setItem(iRow,1,new QTableWidgetItem(query.value(2).toString()));
				ui.tableWidget->setItem(iRow,2,new QTableWidgetItem(query.value(6).toString()));
				ui.tableWidget->setItem(iRow,3,new QTableWidgetItem(query.value(7).toString()));
				ui.tableWidget->setItem(iRow,4,new QTableWidgetItem(query.value(8).toString()));
				ui.tableWidget->setItem(iRow,5,new QTableWidgetItem(query.value(10).toString()));//
				ui.tableWidget->setItem(iRow,6,new QTableWidgetItem(query.value(11).toString()));//
				ui.tableWidget->setItem(iRow,7,new QTableWidgetItem(query.value(12).toString()));//
				ui.tableWidget->setItem(iRow,8,new QTableWidgetItem(query.value(13).toString()));//
				int num = query.value(11).toInt();
				itotalNum = itotalNum + num;
				double price = query.value(13).toDouble();
				dtotalPrice = dtotalPrice + price;
			}
			QString strProfit = QString::number(itotalNum);
			ui.lineEdit_TotalNum->setText(strProfit);
			strProfit = QString::number(dtotalPrice);
			ui.lineEdit_TotalPrice->setText(strProfit);
		}
	}
	else if(strStd == "�̵��¼")
	{
		ui.tableWidget->setColumnCount(11); //��������
		ui.tableWidget->horizontalHeader()->setClickable(false); //���ñ�ͷ���ɵ����Ĭ�ϵ�����������

		QStringList header;
		header<<tr("����")<<tr("����")<<tr("����")<<tr("���")<<tr("��������")<<tr("��λ")<<tr("��������")<<tr("�̵�����")<<tr("ӯ������")<<tr("�۸�")<<tr("������");
		ui.tableWidget->setHorizontalHeaderLabels(header);

		ui.tableWidget->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
		ui.tableWidget->setStyleSheet("QTableWidget{border: 1px solid gray;	background-color: transparent;	selection-color: white;}");
		ui.tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section {background-color:white;color: black;padding-left: 4px;border: 1px solid #6c6c6c;};"
		"color: white;padding-left: 4px;border: 1px solid #6c6c6c;}"
		"QHeaderView::section:checked{background-color: white;color: black;}");	

		if(ui.radioButton->isChecked())
		{
			int itotalNum=0;
			double dtotalPrice=0;
			strName = ui.lineEdit_DrugNo->text();
			strsql= "select * from yf_check where name='"+strName+"'and date between '"+strDate1+"' and '"+strDate2+"'";
			query.exec(strsql);
			iRow = 0;
			while(query.next())
			{
				int rows = ui.tableWidget->model()->rowCount();   //������
				ui.tableWidget->insertRow(rows);
				iRow=rows;
				ui.tableWidget->setItem(iRow,0,new QTableWidgetItem(query.value(1).toString()));
				ui.tableWidget->setItem(iRow,1,new QTableWidgetItem(query.value(2).toString()));
				ui.tableWidget->setItem(iRow,2,new QTableWidgetItem(query.value(6).toString()));
				ui.tableWidget->setItem(iRow,3,new QTableWidgetItem(query.value(7).toString()));
				ui.tableWidget->setItem(iRow,4,new QTableWidgetItem(query.value(8).toString()));
				ui.tableWidget->setItem(iRow,5,new QTableWidgetItem(query.value(11).toString()));//
				ui.tableWidget->setItem(iRow,6,new QTableWidgetItem(query.value(12).toString()));//
				ui.tableWidget->setItem(iRow,7,new QTableWidgetItem(query.value(13).toString()));//
				ui.tableWidget->setItem(iRow,8,new QTableWidgetItem(query.value(14).toString()));//
				ui.tableWidget->setItem(iRow,9,new QTableWidgetItem(query.value(15).toString()));//
				ui.tableWidget->setItem(iRow,10,new QTableWidgetItem(query.value(16).toString()));//
				int num = query.value(14).toInt();
				itotalNum = itotalNum + num;
				double price = query.value(16).toDouble();
				dtotalPrice = dtotalPrice + price;
			}
			QString strProfit = QString::number(itotalNum);
			ui.lineEdit_TotalNum->setText(strProfit);
			strProfit = QString::number(dtotalPrice);
			ui.lineEdit_TotalPrice->setText(strProfit);
		}
		if(!ui.radioButton->isChecked())
		{
			int itotalNum=0;
			double dtotalPrice=0;
			strName = ui.lineEdit_DrugNo->text();
			strsql= "select * from yf_check where date between '"+strDate1+"' and '"+strDate2+"'";
			query.exec(strsql);
			iRow = 0;
			while(query.next())
			{
				int rows = ui.tableWidget->model()->rowCount();   //������
				ui.tableWidget->insertRow(rows);
				iRow=rows;
				ui.tableWidget->setItem(iRow,0,new QTableWidgetItem(query.value(1).toString()));
				ui.tableWidget->setItem(iRow,1,new QTableWidgetItem(query.value(2).toString()));
				ui.tableWidget->setItem(iRow,2,new QTableWidgetItem(query.value(6).toString()));
				ui.tableWidget->setItem(iRow,3,new QTableWidgetItem(query.value(7).toString()));
				ui.tableWidget->setItem(iRow,4,new QTableWidgetItem(query.value(8).toString()));
				ui.tableWidget->setItem(iRow,5,new QTableWidgetItem(query.value(11).toString()));//
				ui.tableWidget->setItem(iRow,6,new QTableWidgetItem(query.value(12).toString()));//
				ui.tableWidget->setItem(iRow,7,new QTableWidgetItem(query.value(13).toString()));//
				ui.tableWidget->setItem(iRow,8,new QTableWidgetItem(query.value(14).toString()));//
				ui.tableWidget->setItem(iRow,9,new QTableWidgetItem(query.value(15).toString()));//
				ui.tableWidget->setItem(iRow,10,new QTableWidgetItem(query.value(16).toString()));//
				//iRow ++;
				int num = query.value(14).toInt();
				itotalNum = itotalNum + num;
				double price = query.value(16).toDouble();
				dtotalPrice = dtotalPrice + price;
			}
			QString strProfit = QString::number(itotalNum);
			ui.lineEdit_TotalNum->setText(strProfit);
			strProfit = QString::number(dtotalPrice);
			ui.lineEdit_TotalPrice->setText(strProfit);
		}
	}
}
void PharmacyStatistics::on_printButton_clicked()
{
	QPrinter       printer( QPrinter::PrinterResolution );
	QPrintDialog   dialog( &printer, this );
	if ( dialog.exec() == QDialog::Accepted ) print( &printer );
}
void PharmacyStatistics::on_previewButton_clicked()
{
	filePrintPreview();
}
void PharmacyStatistics::filePrintPreview()
{
	// ��ӡԤ���Ի���
	QPrinter             printer( QPrinter::PrinterResolution );
	QPrintPreviewDialog  preview( &printer, this );
	preview.setWindowTitle(QString::fromLocal8Bit("Ԥ��"));
	preview.setMinimumSize(800,600);
	connect( &preview, SIGNAL(paintRequested(QPrinter*)), SLOT(print(QPrinter*)) );
	preview.exec();
}
void PharmacyStatistics::print( QPrinter* printer )
{
	QPainter painter( printer );
	int      w = printer->pageRect().width();
	int      h = printer->pageRect().height();
	QRect    page( w/50, h/50, w, h );
	QRect    page4( w/30, h/10, w, h );
	QFont    font = painter.font();
	font.setPixelSize( 50 );
	painter.setFont( font );
	QString	strFindItem = ui.comboBox_find->currentText();
	QString strtitle = QString::fromLocal8Bit(" �������ོ������Ժ")+strFindItem;
	painter.drawText( page, Qt::AlignTop    | Qt::AlignHCenter, strtitle);

	QPixmap image;
	image=image.grabWidget(ui.tableWidget,0,0,1000, 1000);
	//	painter.drawPixmap(page4,image);

	painter.begin(this);
	painter.setPen(QPen(Qt::black,4,Qt::SolidLine));//���û�����ʽ 
	painter.setBrush(QBrush(Qt::white,Qt::SolidPattern));//���û�ˢ��ʽ 
	int row = ui.tableWidget->rowCount();
	int col = ui.tableWidget->columnCount();
	if (row==0)
	{
		return;
	}
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
				painter.drawRect(20+j*cellwidth,upmargin+cellheight*(i+1),cellwidth,cellheight);
				QRect rect(20+j*cellwidth,upmargin+cellheight*(i+1),cellwidth,cellheight);
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
				painter.drawRect(20+j*cellwidth,upmargin+cellheight*(i+1),cellwidth,cellheight);
				QRect rect(20+j*cellwidth,upmargin+cellheight*(i+1),cellwidth,cellheight);
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
					painter.drawRect(20+j*cellwidth,50+cellheight*(i),cellwidth,cellheight);
					QRect rect(20+j*cellwidth,50+cellheight*(i),cellwidth,cellheight);
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
				painter.drawRect(20+j*cellwidth,50+cellheight*(i+1),cellwidth,cellheight);
				QRect rect(20+j*cellwidth,50+cellheight*(i+1),cellwidth,cellheight);
				painter.drawText( rect, Qt::AlignVCenter    | Qt::AlignHCenter, list.at(i*col+j) );//ui.tableWidget->item(i,j)->text()
			}
		}
		painter.end();
	}
} 
void PharmacyStatistics::on_excelButton_clicked()
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

	dlg.selectFile(ui.comboBox_find->currentText());
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
void PharmacyStatistics::completeText(const QModelIndex &index) {
	QString strName = index.data().toString();
	ui.lineEdit_DrugNo->setText(strName);
	druglist->hide();
}
void PharmacyStatistics::keyPressEvent(QKeyEvent *e) {
	if (!druglist->isHidden()) {
		int key = e->key();
		int count = druglist->model()->rowCount();
		QModelIndex currentIndex = druglist->currentIndex();

		if (Qt::Key_Down == key) {
			// �����·����ʱ���ƶ����ѡ����һ������б��е���
			int row = currentIndex.row() + 1;
			if (row >= count) {
				row = 0;
			}

			QModelIndex index = druglist->model()->index(row, 0);
			druglist->setCurrentIndex(index);
		} else if (Qt::Key_Up == key) {
			// �����·����ʱ���ƶ����ѡ����һ������б��е���
			int row = currentIndex.row() - 1;
			if (row < 0) {
				row = count - 1;
			}

			QModelIndex index = druglist->model()->index(row, 0);
			druglist->setCurrentIndex(index);
		} else if (Qt::Key_Escape == key) {
			// ����Esc��ʱ����������б�
			druglist->hide();
		} else if (Qt::Key_Enter == key || Qt::Key_Return == key) {
			// ���»س���ʱ��ʹ������б���ѡ�е������������б�
			if (currentIndex.isValid()) {
				QString text = druglist->currentIndex().data().toString();
				ui.lineEdit_DrugNo->setText(text);
			}

			druglist->hide();
		} else {
			// �����������������б���ʹ��QLineEdit�ļ��̰����¼�
			druglist->hide();
			//QLineEdit::keyPressEvent(e);
		}
	} else {
		//QLineEdit::keyPressEvent(e);
	}
}
PharmacyStatistics::~PharmacyStatistics()
{

}