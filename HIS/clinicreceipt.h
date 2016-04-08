#ifndef CLINICRECEIPT_H
#define CLINICRECEIPT_H

#include <QWidget>
#include "ui_clinicreceipt.h"

class Clinicreceipt : public QWidget
{
	Q_OBJECT

public:
	Clinicreceipt(QWidget *parent = 0);
	~Clinicreceipt();

private:
	Ui::Clinicreceipt ui;
	private slots:
		void showTable(QTreeWidgetItem*,int column);
		void on_addButton_clicked();
		void on_editButton_clicked();
		void on_saveButton_clicked();
		void on_deleteButton_clicked();
		void on_exitButton_clicked();
		void initUI();
};

#endif // CLINICRECEIPT_H
