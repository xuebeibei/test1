#ifndef HELP_H
#define HELP_H

#include <QWidget>
#include "ui_help.h"

class help : public QWidget
{
	Q_OBJECT

public:
	help(QWidget *parent = 0);
	~help();

private:
	Ui::help ui;
	private slots:
		void on_commandLinkButton_clicked();
		void on_commandLinkButton_2_clicked();
		void on_commandLinkButton_3_clicked();
		void on_commandLinkButton_4_clicked();
		void on_commandLinkButton_5_clicked();
		void on_commandLinkButton_6_clicked();
};

#endif // HELP_H
