#include "getdoctor.h"
#include "connectsql.h"
extern ConnectSql sql;
GetDoctor::GetDoctor(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	connect(ui.listWidget,SIGNAL(itemSelectionChanged()),this,SLOT(currentItem()));//
}
void GetDoctor::initData(QString strDoctor)
{
	QSqlQuery query(*sql.db);	

	QString strsql= "select * from sys_personnel where jianpin='"+strDoctor+"'";
	query.exec(strsql);
	QStringList list;
	while(query.next())
	{
		QString str = query.value(2).toString();
		list.append(str);
	}
	ui.listWidget->addItems(list);
}
void GetDoctor::on_okButton_clicked()
{
	accept();
	this->close();
}
void GetDoctor:: on_cancelButton_clicked()
{
	this->close();
}
void GetDoctor::currentItem()
{
	strDoctorName=ui.listWidget->selectedItems().at(0)->text();
}
GetDoctor::~GetDoctor()
{

}
