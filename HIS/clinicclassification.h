#ifndef CLINICCLASSIFICATION_H
#define CLINICCLASSIFICATION_H

#include <QWidget>
#include "ui_clinicclassification.h"

class Clinicclassification : public QWidget
{
	Q_OBJECT

public:
	Clinicclassification(QWidget *parent = 0);
	~Clinicclassification();

private:
	Ui::Clinicclassification ui;
	private slots:
		void showTable(QTreeWidgetItem*,int column);
		void on_addButton_clicked();
		void on_editButton_clicked();
		void on_saveButton_clicked();
		void on_deleteButton_clicked();
		void on_exitButton_clicked();
		void initUI();
};

#endif // CLINICCLASSIFICATION_H
