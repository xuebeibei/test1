#ifndef SYSTEMADMIN_H
#define SYSTEMADMIN_H

#include <QWidget>
#include "ui_systemadmin.h"

class SystemAdmin : public QWidget
{
	Q_OBJECT

public:
	SystemAdmin(QWidget *parent = 0);
	~SystemAdmin();

private:
	Ui::SystemAdmin ui;
	private slots:
		void on_commandLinkButton_clicked();
		void on_userButton_clicked();
		void on_villageclinicButton_clicked();
		void on_insurancetypeButton_clicked();
		void on_dictionarytypeButton_clicked();
		void on_drugtypeButton_clicked();
		void on_commandLinkButton_2_clicked();
		void on_commandLinkButton_3_clicked();
		void on_commandLinkButton_4_clicked();
		void on_commandLinkButton_5_clicked();
		void on_commandLinkButton_6_clicked();
		void on_commandLinkButton_7_clicked();
		void on_commandLinkButton_8_clicked();
		void on_commandLinkButton_9_clicked();
		void on_commandLinkButton_10_clicked();
		void on_commandLinkButton_11_clicked();
		void on_commandLinkButton_12_clicked();
		void on_commandLinkButton_13_clicked();
		void on_commandLinkButton_14_clicked();
		void on_commandLinkButton_15_clicked();

};

#endif // SYSTEMADMIN_H
