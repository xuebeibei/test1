#include "hospitalisationregistry.h"
#include "hospitalisationpay.h"
#include "connectsql.h"
#include "getdoctor.h"
extern ConnectSql sql;
HospitalisationRegistry::HospitalisationRegistry(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	initUI();
	ui.doctorEdit->installEventFilter(this);
	doctorlist = new QListView(this);
	model = new QStringListModel(this);
	doctorlist->setWindowFlags(Qt::ToolTip);
	connect(doctorlist, SIGNAL(clicked(const QModelIndex &)), this, SLOT(completeText(const QModelIndex &)));
	connect(ui.doctorEdit, SIGNAL(textChanged(const QString &)), this, SLOT(setCompleter(const QString &)));

}
void HospitalisationRegistry::initUI()
{
	QSqlQuery query(*sql.db);		
	query.exec("select * from sys_nursinglevel");
	QStringList list;
	while(query.next())
	{
		QString str = query.value(1).toString();
		list.append(str);
	}
	ui.nursinglevelcomboBox->clear();
	ui.nursinglevelcomboBox->addItems(list);

	query.exec("select * from sys_insurancetype");
	list.clear();
	while(query.next())
	{
		QString str = query.value(2).toString();
		list.append(str);
	}
	ui.feetypecomboBox->clear();
	ui.feetypecomboBox->addItems(list);


	query.exec("select * from sys_department");
	list.clear();
	while(query.next())
	{
		QString str = query.value(1).toString();
		list.append(str);
	}
	ui.departmentcomboBox->clear();
	ui.departmentcomboBox->addItems(list);

	QDateTime current_date_time = QDateTime::currentDateTime();
	ui.dateTimeEdit->setDateTime(current_date_time);

	ui.saveButton->setEnabled(false);
	ui.editButton->setEnabled(false);
	ui.discardButton->setEnabled(false);
	ui.deleteButton->setEnabled(false);
	//setEdit(false);
	ui.sheetmakerEdit->setEnabled(false);
	ui.sheetmakerEdit->setText(sql.struser);
	Isupdate=false;
}
void HospitalisationRegistry::GetCount()
{
	QSqlQuery query(*sql.db);		
	query.exec("select * from zy_patientinfo");
	int icount=0;
	while(query.next())
	{
		icount++;
	}
	itotalcount=icount;
}
void HospitalisationRegistry::on_addButton_clicked()
{
	initUI();
	installEventFilter(this);
	setEdit(true);
	on_discardButton_clicked();
	GetCount();
	itotalcount++;
	QString strNo= "zy"+QString::number(itotalcount);
	ui.hospitalisationNoEdit->setText(strNo);
	ui.recordNoEdit->setText(strNo);
	ui.statusEdit->setText(QString::fromLocal8Bit("住院中"));
	ui.saveButton->setEnabled(true);
	ui.discardButton->setEnabled(true);
}
void HospitalisationRegistry::on_saveButton_clicked()
{
	QSqlQuery query(*sql.db);		
	QString strNo=ui.hospitalisationNoEdit->text();
	int isheetcount;
	if(Isupdate)
	{
		QString strsql = "select *from zy_patientinfo where hospitalisationno ='"+strNo+"'"; 
		query.exec(strsql);
		while(query.next())
		{
			QString str = query.value(1).toString();
			isheetcount=query.value(0).toString().toInt();
		}
	}
	QString strsql = "delete from zy_patientinfo where hospitalisationno ='"+strNo+"'"; 
	query.exec(strsql);

	if (ui.nameEdit->text()=="")
	{
		QMessageBox box(QMessageBox::Warning,QString::fromLocal8Bit("警告"),QString::fromLocal8Bit("请填写病人姓名"));
		box.setStandardButtons (QMessageBox::Ok);
		box.setButtonText (QMessageBox::Ok,QString::fromLocal8Bit("确 定"));
		box.exec();
		return;
	}
	/*
	if (ui.ageEdit->text()=="")
	{
		QMessageBox::information(this,QString::fromLocal8Bit("警告"),QString::fromLocal8Bit("请填写病人年龄"));
		return;
	}
	if (ui.doctorEdit->text()=="")
	{
		QMessageBox::information(this,QString::fromLocal8Bit("警告"),QString::fromLocal8Bit("请选择医生"));
		return;
	}
	if (ui.telEdit->text()=="")
	{
		QMessageBox::information(this,QString::fromLocal8Bit("警告"),QString::fromLocal8Bit("请填写联系方式"));
		return;
	}
	if (ui.diagnosisEdit->document()->toPlainText()=="")
	{
		QMessageBox::information(this,QString::fromLocal8Bit("警告"),QString::fromLocal8Bit("请填写诊断结果"));
		return;
	}*/
	QString strsign;
	query.prepare("INSERT INTO zy_patientinfo VALUES (?,?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)");
	if(Isupdate)
	{
		query.bindValue(0, isheetcount);
		strsign = QString::number(isheetcount);
		if (strsign.length()==1)
		{
			strsign = "00000"+strsign;
		}
		if (strsign.length()==2)
		{
			strsign = "0000"+strsign;
		}
		if (strsign.length()==3)
		{
			strsign = "000"+strsign;
		}
		if (strsign.length()==4)
		{
			strsign = "00"+strsign;
		}
		if (strsign.length()==5)
		{
			strsign = "0"+strsign;
		}
	}
	if(!Isupdate)
	{
		query.bindValue(0, itotalcount);
		strsign = QString::number(itotalcount);
		if (strsign.length()==1)
		{
			strsign = "00000"+strsign;
		}
		if (strsign.length()==2)
		{
			strsign = "0000"+strsign;
		}
		if (strsign.length()==3)
		{
			strsign = "000"+strsign;
		}
		if (strsign.length()==4)
		{
			strsign = "00"+strsign;
		}
		if (strsign.length()==5)
		{
			strsign = "0"+strsign;
		}
	}
	query.bindValue(1, ui.hospitalisationNoEdit->text());
	query.bindValue(2, ui.dateTimeEdit->dateTime());
	query.bindValue(3, ui.recordNoEdit->text());
	query.bindValue(4, ui.nameEdit->text());
	query.bindValue(5, ui.gendercomboBox->currentText());
	query.bindValue(6, ui.ageEdit->text().toInt());
	query.bindValue(7, ui.IDEdit->text());
	query.bindValue(8, ui.addressEdit->text());
	query.bindValue(9, ui.contactEdit->text());
	query.bindValue(10, ui.telEdit->text().toInt());
	query.bindValue(11, ui.certificateNoEdit->text());
	query.bindValue(12, ui.cooperativemedicalNoEdit->text());
	query.bindValue(13, ui.departmentcomboBox->currentText());
	query.bindValue(14, ui.doctorEdit->text());
	query.bindValue(15, ui.feetypecomboBox->currentText());
	query.bindValue(16, ui.nursinglevelcomboBox->currentText());
	query.bindValue(17, ui.bedEdit->text());
	query.bindValue(18, ui.diagnosisEdit->document()->toPlainText());
	query.bindValue(19, ui.minimumEdit->text());
	query.bindValue(20, ui.sheetmakerEdit->text());
	query.bindValue(21,NULL);//审核
	query.bindValue(22, ui.statusEdit->text());
	query.bindValue(23, ui.dateTimeEdit->dateTime());
	query.bindValue(24, 0);
	query.bindValue(25, NULL);
	query.bindValue(26, ui.dateTimeEdit->dateTime());
	query.bindValue(27, strsign);

	if(query.exec())
	{
		//QMessageBox::information(this,QString ::fromLocal8Bit("提示"),QString::fromLocal8Bit("保存成功！"));
		if(!Isupdate)
		{
			QMessageBox box(QMessageBox::Warning,QString::fromLocal8Bit("警告"),QString::fromLocal8Bit("是否交押金？"));
			box.setStandardButtons (QMessageBox::Ok|QMessageBox::Cancel);
			box.setButtonText (QMessageBox::Ok,QString::fromLocal8Bit("确 定"));
			box.setButtonText (QMessageBox::Cancel,QString::fromLocal8Bit("取 消"));
			if(box.exec()==QMessageBox::Ok)
			{
				HospitalisationPay*pay= new HospitalisationPay;
				pay->refund(strNo,0);//同补款，加载后自动填写住院号等病人信息
				pay->Isrefund=false;
				pay->showNormal();
			}
		}
		ui.editButton->setEnabled(true);
		ui.saveButton->setEnabled(false);
		ui.discardButton->setEnabled(false);
		setEdit(false);
	}
	else
	{
		QMessageBox box(QMessageBox::Warning,QString::fromLocal8Bit("警告"),QString::fromLocal8Bit("保存失败"));
		box.setStandardButtons (QMessageBox::Ok);
		box.setButtonText (QMessageBox::Ok,QString::fromLocal8Bit("确 定"));
		box.exec();
	}
}
void HospitalisationRegistry::on_discardButton_clicked()
{
	ui.hospitalisationNoEdit->setText("");
	ui.nameEdit->setText("");
	ui.recordNoEdit->setText("");
	ui.ageEdit->setText("");
	ui.IDEdit->setText("");
	ui.contactEdit->setText("");
	ui.telEdit->setText("");
	ui.certificateNoEdit->setText("");
	ui.cooperativemedicalNoEdit->setText("");
	//ui.departmentEdit->setText("");
	ui.doctorEdit->setText("");
	//ui.feetypeEdit->setText("");
	ui.bedEdit->setText("");
	ui.addressEdit->setText("");
	ui.diagnosisEdit->setText("");
	ui.minimumEdit->setText("");
}
void HospitalisationRegistry::on_editButton_clicked()
{
	ui.deleteButton->setEnabled(true);
	ui.saveButton->setEnabled(true);
	ui.discardButton->setEnabled(true);
	setEdit(true);
}
void HospitalisationRegistry::on_deleteButton_clicked()
{
	QMessageBox box(QMessageBox::Warning,QString::fromLocal8Bit("警告"),QString::fromLocal8Bit("确认从数据库中删除该住院号？"));
	box.setStandardButtons (QMessageBox::Ok|QMessageBox::Cancel);
	box.setButtonText (QMessageBox::Ok,QString::fromLocal8Bit("确 定"));
	box.setButtonText (QMessageBox::Cancel,QString::fromLocal8Bit("取 消"));
	if(box.exec()==QMessageBox::Ok)
	{
		QSqlQuery query(*sql.db);		
		QString strNo=ui.hospitalisationNoEdit->text();
		query.exec("select* from zy_patientinfo"); 
		int count=0;
		QString lastNo;
		while (query.next())
		{
			lastNo=query.value(1).toString();
		}
		if (lastNo!=strNo) 
		{
			QMessageBox box(QMessageBox::Warning,QString::fromLocal8Bit("警告"),QString::fromLocal8Bit("删除该号会造成重复！"));
			box.setStandardButtons (QMessageBox::Ok);
			box.setButtonText (QMessageBox::Ok,QString::fromLocal8Bit("确 定"));
			box.exec();
			return;
		}
		//query.exec("select from zy_patientinfo where hospitalisationno ='"+strNo+"'");
		//int id=0;
		//while (query.next())
		//{
		//	id = query.value(0).toInt();
		//}
		//if(id ==count)
		//{
		//	
		//}
		QString strsql = "delete from zy_patientinfo where hospitalisationno ='"+strNo+"'"; 
		if(query.exec(strsql))
		{
			QMessageBox box(QMessageBox::Warning,QString::fromLocal8Bit("警告"),QString::fromLocal8Bit("删除成功！"));
			box.setStandardButtons (QMessageBox::Ok);
			box.setButtonText (QMessageBox::Ok,QString::fromLocal8Bit("确 定"));
			box.exec();
			on_discardButton_clicked();
		}
	}
}
void HospitalisationRegistry::on_previewButton_clicked()
{

}
void HospitalisationRegistry::on_printButton_clicked()
{

}
void HospitalisationRegistry::on_checkButton_clicked()
{

}
void HospitalisationRegistry::setEdit(bool IsEdit)
{
	if (IsEdit==true)
	{
		ui.hospitalisationNoEdit->setEnabled(true);
		ui.doctorEdit->setEnabled(true);
		ui.bedEdit->setEnabled(true);
		ui.addressEdit->setEnabled(true);
		ui.ageEdit->setEnabled(true);
		ui.certificateNoEdit->setEnabled(true);
		ui.contactEdit->setEnabled(true);
		ui.cooperativemedicalNoEdit->setEnabled(true);
		ui.dateTimeEdit->setEnabled(true);
		ui.diagnosisEdit->setEnabled(true);
		ui.telEdit->setEnabled(true);
		ui.minimumEdit->setEnabled(true);
		ui.nameEdit->setEnabled(true);
	//	ui.recordNoEdit->setEnabled(true);
		ui.IDEdit->setEnabled(true);
		ui.gendercomboBox->setEnabled(true);
		ui.departmentcomboBox->setEnabled(true);
		ui.feetypecomboBox->setEnabled(true);
		ui.nursinglevelcomboBox->setEnabled(true);
	}
	else 
	{
		ui.hospitalisationNoEdit->setEnabled(false);
		ui.doctorEdit->setEnabled(false);
		ui.bedEdit->setEnabled(false);
		ui.addressEdit->setEnabled(false);
		ui.ageEdit->setEnabled(false);
		ui.certificateNoEdit->setEnabled(false);
		ui.contactEdit->setEnabled(false);
		ui.cooperativemedicalNoEdit->setEnabled(false);
		ui.dateTimeEdit->setEnabled(false);
		ui.diagnosisEdit->setEnabled(false);
		ui.telEdit->setEnabled(false);
		ui.minimumEdit->setEnabled(false);
		ui.nameEdit->setEnabled(false);
		ui.recordNoEdit->setEnabled(false);
		ui.sheetmakerEdit->setEnabled(false);
		ui.IDEdit->setEnabled(false);
		ui.gendercomboBox->setEnabled(false);
		ui.departmentcomboBox->setEnabled(false);
		ui.feetypecomboBox->setEnabled(false);
		ui.nursinglevelcomboBox->setEnabled(false);
	}
}
void HospitalisationRegistry::edit(QString strNo)
{

	ui.addButton->setEnabled(false);
	ui.editButton->setEnabled(true);
	setEdit(false);
	Isupdate=true;
	QSqlQuery query(*sql.db);	
	query.exec("select * from zy_patientinfo where hospitalisationno='"+strNo+"'");
	while(query.next())
	{
		ui.hospitalisationNoEdit->setText(query.value(1).toString());
		ui.dateTimeEdit->setDateTime(query.value(2).toDateTime());
		ui.recordNoEdit->setText(query.value(3).toString());
		ui.nameEdit->setText(query.value(4).toString());
		QString strgender = query.value(5).toString();
		if (strgender==QString::fromLocal8Bit("男"))
		{
			ui.gendercomboBox->setCurrentIndex(0);
		}
		if (strgender==QString::fromLocal8Bit("女"))
		{
			ui.gendercomboBox->setCurrentIndex(1);
		}
/*		ui.gendercomboBox->setEditText(query.value(5).toString());*/
		ui.ageEdit->setText(query.value(6).toString());
		ui.IDEdit->setText(query.value(7).toString());
		ui.addressEdit->setText(query.value(8).toString());
		ui.contactEdit->setText(query.value(9).toString());
		ui.telEdit->setText(query.value(10).toString());
		ui.certificateNoEdit->setText(query.value(11).toString());
		ui.cooperativemedicalNoEdit->setText(query.value(12).toString());

		QString strdepartment = query.value(13).toString();
		for (int i =0;i<ui.departmentcomboBox->count();i++)
		{
			if (ui.departmentcomboBox->itemText(i)==strdepartment)
			{
				ui.departmentcomboBox->setCurrentIndex(i);
			}
		}
		//ui.departmentcomboBox->setEditText(query.value(13).toString());
		ui.doctorEdit->setText(query.value(14).toString());	
		//ui.feetypecomboBox->setEditText(query.value(15).toString());	

		QString strfeetype = query.value(15).toString();
		if (strfeetype==QString::fromLocal8Bit("自费"))
		{
			ui.feetypecomboBox->setCurrentIndex(0);
		}
		if (strfeetype==QString::fromLocal8Bit("新农合"))
		{
			ui.feetypecomboBox->setCurrentIndex(1);
		}
		if (strfeetype==QString::fromLocal8Bit("医保"))
		{
			ui.feetypecomboBox->setCurrentIndex(2);
		}


		QString strnursinglevel = query.value(16).toString();
		for (int i =0;i<ui.nursinglevelcomboBox->count();i++)
		{
			if (ui.nursinglevelcomboBox->itemText(i)==strnursinglevel)
			{
				ui.nursinglevelcomboBox->setCurrentIndex(i);
			}
		}
		//ui.nursinglevelcomboBox->setEditText(query.value(16).toString());	
		ui.bedEdit->setText(query.value(17).toString());	
		ui.diagnosisEdit->setText(query.value(18).toString());	
		ui.minimumEdit->setText(query.value(19).toString());	

		ui.sheetmakerEdit->setText(query.value(20).toString());	
		ui.statusEdit->setText(query.value(22).toString());			
	}
	doctorlist->hide();
}
void HospitalisationRegistry::completeText(const QModelIndex &index) {
	QString strName = index.data().toString();
	ui.doctorEdit->setText(strName);
	doctorlist->hide();
}
void HospitalisationRegistry::focusOutEvent(QFocusEvent *e) {
	doctorlist->hide();
}
void HospitalisationRegistry::setCompleter(const QString &text) {
	doctorlist->hide();
	if (text.isEmpty()) {
		doctorlist->hide();
		return;
	}
	if ((text.length() > 1) && (!doctorlist->isHidden())) {
		return;
	}
	QSqlQuery query(*sql.db);	
	QString strsql=QString("select * from sys_personnel where jianpin like'%%1%' or name like'%%1%'").arg(text).arg(text);
	query.exec(strsql);
	QStringList list;
	while(query.next())
	{
		QString str = query.value(2).toString();
		list.append(str);
	}

	model->setStringList(list);
	doctorlist->setModel(model);
	if (model->rowCount() == 0) {
		return;
	}

	doctorlist->setMinimumWidth(width());
	doctorlist->setMaximumWidth(width());

	QPoint GlobalPoint(ui.doctorEdit->mapToGlobal(QPoint(0, 0)));
	doctorlist->setGeometry(GlobalPoint.x(), GlobalPoint.y()+ui.doctorEdit->height(), 60, 100);
	//doctorlist->setGeometry(this->x()+441, this->y()+270, 50, 100);
	//doctorlist->setFixedWidth(40);
	doctorlist->show();
}
void HospitalisationRegistry::keyPressEvent(QKeyEvent *e) {
	if (!doctorlist->isHidden()) {
		int key = e->key();
		int count = doctorlist->model()->rowCount();
		QModelIndex currentIndex = doctorlist->currentIndex();

		if (Qt::Key_Down == key) {
			// 按向下方向键时，移动光标选中下一个完成列表中的项
			int row = currentIndex.row() + 1;
			if (row >= count) {
				row = 0;
			}

			QModelIndex index = doctorlist->model()->index(row, 0);
			doctorlist->setCurrentIndex(index);
		} else if (Qt::Key_Up == key) {
			// 按向下方向键时，移动光标选中上一个完成列表中的项
			int row = currentIndex.row() - 1;
			if (row < 0) {
				row = count - 1;
			}

			QModelIndex index = doctorlist->model()->index(row, 0);
			doctorlist->setCurrentIndex(index);
		} else if (Qt::Key_Escape == key) {
			// 按下Esc键时，隐藏完成列表
			doctorlist->hide();
		} else if (Qt::Key_Enter == key || Qt::Key_Return == key) {
			// 按下回车键时，使用完成列表中选中的项，并隐藏完成列表
			if (currentIndex.isValid()) {
				QString text = doctorlist->currentIndex().data().toString();
				ui.doctorEdit->setText(text);
			}

			doctorlist->hide();
		} else {
			// 其他情况，隐藏完成列表，并使用QLineEdit的键盘按下事件
			doctorlist->hide();
			//QLineEdit::keyPressEvent(e);
		}
	} else {
		//QLineEdit::keyPressEvent(e);
	}
}
HospitalisationRegistry::~HospitalisationRegistry()
{

}
