#include "cooperativedictionary.h"

Cooperativedictionary::Cooperativedictionary(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}
void Cooperativedictionary::initUI(QString str,QString str1)
{
	ui.lineEdit->setText(str);
	ui.lineEdit_2->setText(str1);
}
void Cooperativedictionary::on_getNoButton_clicked()
{
	QString strNo = ui.lineEdit->text();
	emit getno(strNo);
	this->close();
}
Cooperativedictionary::~Cooperativedictionary()
{

}
