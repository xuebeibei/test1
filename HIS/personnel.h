#ifndef PERSONNEL_H
#define PERSONNEL_H

#include <QWidget>
#include "ui_personnel.h"

class personnel : public QWidget
{
	Q_OBJECT

public:
	personnel(QWidget *parent = 0);
	~personnel();

private:
	Ui::personnel ui;
	private slots:
		void showTable(QTreeWidgetItem*,int column);
		void on_addButton_clicked();
		void on_editButton_clicked();
		void on_saveButton_clicked();
		void on_deleteButton_clicked();
		void on_exitButton_clicked();
		void initUI();
};

#endif // PERSONNEL_H
