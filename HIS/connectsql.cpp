#include "connectsql.h"
#include <QtGui/QApplication>
#include "QSettings"
#include "QSysInfo"
ConnectSql::ConnectSql()
{
	strtitle =QString::fromLocal8Bit("HIS");
	windowsFlag = QSysInfo::WindowsVersion;
}

ConnectSql::~ConnectSql()
{
   /* QString DBname=db->connectionName();*/
  // db->close();
   // QSqlDatabase::removeDatabase(DBname);

}

bool ConnectSql::connect(QString  strip)
{
	db = new QSqlDatabase(QSqlDatabase::addDatabase("QPSQL" ,"psql" ));

	QSettings setting("posgresql.ini",QSettings::IniFormat);//读配置文件
	setting.beginGroup("config");
	db->setHostName(strip);
	db->setDatabaseName(setting.value("databasename").toString());
	db->setUserName(setting.value("username").toString());
	db->setPassword(setting.value("password").toString());
	db->setPort(setting.value("port").toInt());
	setting.endGroup();
	if(!db->open())
	{
		QMessageBox box(QMessageBox::Warning,QString::fromLocal8Bit("提示"),QString::fromLocal8Bit("连接数据库失败！"));
		box.setStandardButtons (QMessageBox::Ok);
		box.setButtonText (QMessageBox::Ok,QString::fromLocal8Bit("确 定"));
		box.exec();
		return false;
	}
	return true;
}

bool ConnectSql::connect2()
{
	db2=QSqlDatabase::addDatabase("QODBC");  
	QSettings setting("sqlserver.ini",QSettings::IniFormat);//读配置文件
	setting.beginGroup("config");
	QString dsn = QString::fromLocal8Bit("DRIVER={SQL Server Native Client 10.0};SERVER=%1;DATABASE=%2").arg(setting.value("server").toString()).arg(setting.value("databasename").toString());  
	db2.setDatabaseName(dsn);
	db2.setUserName(setting.value("username").toString());
	db2.setPassword(setting.value("password").toString());
	setting.endGroup();
	if(!db2.open())  
	{  
		QMessageBox box(QMessageBox::Warning,QString::fromLocal8Bit("提示"),db2.lastError().text());
		box.setStandardButtons (QMessageBox::Ok);
		box.setButtonText (QMessageBox::Ok,QString::fromLocal8Bit("确 定"));
		box.exec();
	}
	return true; 
}
bool ConnectSql::disconnect2()
{
	db2.close();
	return true; 
}
void ConnectSql::InputProduct()
{

}
void ConnectSql::AddProduct()
{

}
void ConnectSql::DeleteProduct()
{

}
void ConnectSql::InputOriginalData()
{

}
void ConnectSql::AddOriginalData()
{

}
void ConnectSql::DeleteOriginalData()
{

}
void ConnectSql::InputComponentData()
{

}
void ConnectSql::AddComponentData()
{

}
void ConnectSql::DeleteComponentData()
{

}