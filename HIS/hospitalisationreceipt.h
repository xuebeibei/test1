#ifndef HOSPITALISATIONRECEIPT_H
#define HOSPITALISATIONRECEIPT_H

#include <QWidget>
#include "ui_hospitalisationreceipt.h"

class Hospitalisationreceipt : public QWidget
{
	Q_OBJECT

public:
	Hospitalisationreceipt(QWidget *parent = 0);
	~Hospitalisationreceipt();

private:
	Ui::Hospitalisationreceipt ui;
	private slots:
		void showTable(QTreeWidgetItem*,int column);
		void on_addButton_clicked();
		void on_editButton_clicked();
		void on_saveButton_clicked();
		void on_deleteButton_clicked();
		void on_exitButton_clicked();
		void initUI();
};

#endif // HOSPITALISATIONRECEIPT_H
