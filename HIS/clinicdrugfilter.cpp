#include "clinicdrugfilter.h"
#include "connectsql.h"
extern ConnectSql sql;
ClinicDrugFilter::ClinicDrugFilter(QWidget *parent): 
	QDialog(parent),
	ui(new Ui::ClinicDrugFilter)
{
	ui->setupUi(this);
	setGeometry(312, 282, 300, 280);
	setWindowFlags(Qt::FramelessWindowHint);
	connect(ui->listWidget,SIGNAL(itemSelectionChanged()),this,SLOT(currentItem()));//
}
void ClinicDrugFilter::initData(QString strName)
{
	QSqlQuery query(*sql.db);	
	
	QString strsql=QString("select * from sys_drugdictionary where abbr like '%%1%'or name like'%%2%'  ").arg(strName).arg(strName);

	query.exec(strsql);
	QStringList list;
	while(query.next())
	{
		QString str = query.value(1).toString();
		list.append(str);
	}
	ui->listWidget->addItems(list);
}
void ClinicDrugFilter::on_okButton_clicked()
{
	accept();
	this->close();
}
void ClinicDrugFilter:: on_cancelButton_clicked()
{
	this->close();
}
void ClinicDrugFilter::currentItem()
{
	strDrugName=ui->listWidget->selectedItems().at(0)->text();
}
ClinicDrugFilter::~ClinicDrugFilter()
{

}
