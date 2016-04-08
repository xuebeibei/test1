#ifndef DEPARTMENTFILE_H
#define DEPARTMENTFILE_H

#include <QDialog>
#include "ui_departmentfile.h"

class Departmentfile : public QDialog
{
	Q_OBJECT

public:
	Departmentfile(QWidget *parent = 0);
	~Departmentfile();
	void initUI();
private:
	Ui::Departmentfile ui;
	private slots:
		void showTable(QTreeWidgetItem*,int column);
		void on_addButton_clicked();
		void on_editButton_clicked();
		void on_deleteButton_clicked();
		void on_exitButton_clicked();
};

#endif // DEPARTMENTFILE_H
