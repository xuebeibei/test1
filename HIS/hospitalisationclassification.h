#ifndef HOSPITALISATIONCLASSIFICATION_H
#define HOSPITALISATIONCLASSIFICATION_H

#include <QWidget>
#include "ui_hospitalisationclassification.h"

class Hospitalisationclassification : public QWidget
{
	Q_OBJECT

public:
	Hospitalisationclassification(QWidget *parent = 0);
	~Hospitalisationclassification();

private:
	Ui::Hospitalisationclassification ui;
	private slots:
		void showTable(QTreeWidgetItem*,int column);
		void on_addButton_clicked();
		void on_editButton_clicked();
		void on_saveButton_clicked();
		void on_deleteButton_clicked();
		void on_exitButton_clicked();
		void initUI();
};

#endif // HOSPITALISATIONCLASSIFICATION_H
