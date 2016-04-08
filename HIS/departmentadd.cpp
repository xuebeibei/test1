#include "departmentadd.h"
#include "connectsql.h"
extern ConnectSql sql;
Departmentadd::Departmentadd(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}
void Departmentadd::on_okButton_clicked()
{
	QSqlQuery query(*sql.db);
	query.exec("select * from sys_department");
	int icount=0;
	while(query.next())
	{
		icount++;
	}
	icount++;
	query.prepare("INSERT INTO sys_department VALUES (?,?, ?, ?, ?, ?)");
	query.bindValue(0, icount);
	query.bindValue(1, ui.lineEdit->text());
	query.bindValue(2, ui.lineEdit_2->text());
	query.bindValue(3, ui.lineEdit_3->text());
	query.bindValue(4, ui.lineEdit_4->text());
	query.bindValue(5, ui.lineEdit_5->text());
	query.exec();
	this->close();
	

}
void Departmentadd::on_cancelButton_clicked()
{
	this->close();
}
Departmentadd::~Departmentadd()
{

}
