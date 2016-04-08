#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include <QWidget>
#include "ui_department.h"

class Department : public QWidget
{
	Q_OBJECT

public:
	Department(QWidget *parent = 0);
	~Department();
	
private:
	Ui::Department ui;
	private slots:
		void showTable(QTreeWidgetItem*,int column);
		void on_addButton_clicked();
		void on_editButton_clicked();
		void on_deleteButton_clicked();
		void on_exitButton_clicked();
		void on_saveButton_clicked();
		void initUI();
};

#endif // DEPARTMENT_H
