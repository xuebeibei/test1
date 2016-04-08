#include "help.h"
#include "QProcess"
#include "QDesktopServices"
#include "QFramer/futil.h"
#include <QHBoxLayout>
help::help(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	setStyleSheet("QPushButton{background-color: rgb(70,130,180);color: white;border-style: outset;border-color:rgb(27, 118, 150);border-width: 1px;border-radius: 5px;}"
		"QPushButton:pressed{background-color: rgb(50, 77, 92);color: white;}"
		"QPushButton:hover{	background-color: rgb(3,110,184);color: white;}"
		"QLabel{ background-color: transparent;color: black;qproperty-alignment: AlignCenter;border-color:rgb(27, 118, 150);border-width: 1px;border-radius: 5px;}"
		"QTextBrowser{ background-color: transparent;black: white;border-color:rgb(27, 118, 150);border-width: 1px;border-radius: 5px;}");
}

void help::on_commandLinkButton_clicked()
{

}
void help::on_commandLinkButton_2_clicked()
{

}
void help::on_commandLinkButton_3_clicked()
{

}
void help::on_commandLinkButton_4_clicked()
{

}
void help::on_commandLinkButton_5_clicked()
{

}
void help::on_commandLinkButton_6_clicked()
{

}
help::~help()
{

}
