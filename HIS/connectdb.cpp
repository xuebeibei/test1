#include "connectdb.h"
#include "ui_connectdb.h"
#include "connectsql.h"
#include <vector>  
using namespace std;
vector <QString> vtSat; 
ConnectSql sql;
ConnectDB::ConnectDB(QWidget *parent): 
QDialog(parent),
	ui(new Ui::ConnectDB)
{
	ui->setupUi(this);
	initUI();
	namelistview = new QListView(this);
	model = new QStringListModel(this);
	namelistview->setWindowFlags(Qt::ToolTip);
	installEventFilter(namelistview);
	connect(namelistview, SIGNAL(clicked(const QModelIndex &)), this, SLOT(completeText(const QModelIndex &)));
	connect(ui->comboBox_2, SIGNAL(editTextChanged(const QString &)), this, SLOT(setCompleter(const QString &)));

	ui->widget->setStyleSheet("QWidget{background-color: rgb(85,170,255);}"
		"QPushButton{background-color: rgb(85,170,255);color: white;border-style: outset;}"
		"QPushButton:hover{	background-color: rgb(3,110,184);color: white;}");
	ui->label->setStyleSheet("QLabel{ background-color: transparent;color: white;qproperty-alignment: AlignCenter;border-color:rgb(27, 118, 150);border-width: 1px;border-radius: 5px;}");
}
void ConnectDB::initUI()
{
	setWindowFlags(Qt::FramelessWindowHint);
	QString strfile;
	strfile = QCoreApplication::applicationDirPath();
	QString sDbNm = strfile+"/DACS.accdb";  
	QString dsn = QString("DRIVER={Microsoft Access Driver (*.mdb, *.accdb)}; FIL={MS Access};DBQ=%1;").arg(sDbNm);//连接字符串  
	IsAdmin=false;
	QSettings setting("posgresql.ini",QSettings::IniFormat);//读配置文件
	setting.beginGroup("config");
	ui->lineEdit->setText(setting.value("hostname").toString());
	Isconnect =on_okButton_clicked();
}
ConnectDB::~ConnectDB()
{
	delete ui;
}
bool ConnectDB::on_okButton_clicked()
{

	bool isconnect =sql.connect(ui->lineEdit->text().trimmed());
	QStringList list;
	if (isconnect)
	{
		QSqlQuery query(*sql.db);
		query.exec("select * from sys_users");
		while(query.next())
		{
			list.append(query.value(1).toString());
			vtSat.push_back(query.value(1).toString());
		}
		ui->comboBox_2->addItems(list);
	}
	return isconnect;

}
void ConnectDB::on_loginButton_clicked()
{

	/*bool isconnect = on_okButton_clicked();
	if (!isconnect) return;*/
	if (!Isconnect)
	{
		Isconnect =on_okButton_clicked();
	}
	if (!Isconnect) return;
	QString user = ui->comboBox_2->currentText().trimmed();
	QString pwd =ui->lineEdit_2->text().trimmed();
	QString str = str.fromLocal8Bit("警告");
	if(user==NULL)
	{
		QMessageBox box(QMessageBox::Warning,QString::fromLocal8Bit("警告"),QString::fromLocal8Bit("请输入用户名"));
		box.setStandardButtons (QMessageBox::Ok);
		box.setButtonText (QMessageBox::Ok,QString::fromLocal8Bit("确 定"));
		box.exec();
		return;
	}
	if(pwd==NULL)
	{
		QMessageBox box(QMessageBox::Warning,QString::fromLocal8Bit("警告"),QString::fromLocal8Bit("请输入密码"));
		box.setStandardButtons (QMessageBox::Ok);
		box.setButtonText (QMessageBox::Ok,QString::fromLocal8Bit("确 定"));
		box.exec();
		return;
	}

	//sql.connect(ui->comboBox_2->currentIndex());

	QSqlQuery query(*sql.db);
	query.exec("select * from sys_users where Name='"+user+"' and Password='"+pwd+"'");

	QString strIsAuthorized;
	if(query.next())
	{
		if (user=="admin")
		{
			IsAdmin=true;
		}
		//IsAuthorized=query.value(3).toBool();
		sql.struser=user;
		accept();
	}
	else
	{
		QMessageBox box(QMessageBox::Warning,QString::fromLocal8Bit("警告"),QString::fromLocal8Bit("用户名或密码错误"));
		box.setStandardButtons (QMessageBox::Ok);
		box.setButtonText (QMessageBox::Ok,QString::fromLocal8Bit("确 定"));
		box.exec();
		ui->lineEdit_2->clear();
		ui->comboBox_2->setFocus();
		return;
	}
}
void ConnectDB::on_cancelButton_2_clicked()
{
	this->close();
}
void ConnectDB::on_exitButton_clicked()
{
	this->close();
}
void ConnectDB::on_cancelButton_clicked()
{
	this->close();
}
void ConnectDB::onChanged(int index)
{

}
void ConnectDB:: on_closeButton_clicked()
{
	this->close();
}
void ConnectDB:: on_openButton_clicked()
{
}
void ConnectDB::keyPressEvent(QEvent*event)
{
	if(event->type() == QEvent::KeyPress)
	{
		QKeyEvent*keyEvent=static_cast<QKeyEvent*>(event);//将事件转化为键盘事件
		if(keyEvent->key() == Qt::Key_Tab)
		{
			focusNextChild();
			return;
		}
		else
		{
		}
	}
}
bool ConnectDB::eventFilter(QObject*obj,QEvent*event)
{
	if(obj == this)
	{
		if(event->type() == QEvent::KeyPress)
		{
			QKeyEvent*keyEvent=static_cast<QKeyEvent*>(event);//将事件转化为键盘事件
			if(keyEvent->key() == Qt::Key_Return)
			{
				focusNextChild();
				return true;
			}
		}
	}
}
void ConnectDB::setCompleter(const QString &text) {
	namelistview->hide();
	//disconnect(ui.comboBox,SIGNAL(editTextChanged (const QString & )),this,SLOT(setCompleter(const QString & )));  
	if (text.isEmpty()) {
		namelistview->hide();
		return;
	}

	if ((text.length() > 1) && (!namelistview->isHidden())) {
		return;
	}

	QSqlQuery query(*sql.db);	


	QString strsql= "select * from sys_users where name like '"+text+"'";
	query.exec(strsql);
	if (query.next())return;

	QStringList list;
	for(int i = 0;i < vtSat.size();++i){

		if (vtSat[i].indexOf(text) != -1)
		{

			list.append(vtSat[i]);
		}
	}

	model->setStringList(list);
	//	model->setStringList(sl);
	namelistview->setModel(model);

	if (model->rowCount() == 0) {
		return;
	}

	// Position the text edit
	namelistview->setMinimumWidth(this->width());
	namelistview->setMaximumWidth(this->width());

	QPoint p(0, this->height());
	int x = this->mapToGlobal(p).x();
	int y = this->mapToGlobal(p).y() + 1;

	QPoint GlobalPoint(ui->comboBox_2->mapToGlobal(QPoint(0, 0)));//获取控件在窗体中的坐标

	namelistview->setGeometry(GlobalPoint.x(), GlobalPoint.y()+ui->comboBox_2->height(), 60, 100);
	namelistview->resize(100,200);
	namelistview->setFixedWidth(123);
	namelistview->show();
	//	connect(ui.comboBox,SIGNAL(editTextChanged (const QString & )),this,SLOT(setCompleter(const QString & )));  
}
void ConnectDB::completeText(const QModelIndex &index) {
	QString strName = index.data().toString();
	for (int i =0;i<ui->comboBox_2->count();i++)
	{
		if (ui->comboBox_2->itemText(i)==strName)
		{
			ui->comboBox_2->setCurrentIndex(i);
		}
	}
	//ui.comboBox->setEditText(strName);
	namelistview->hide();
}