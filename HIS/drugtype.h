#ifndef DRUGTYPE_H
#define DRUGTYPE_H

#include <QWidget>
#include "ui_drugtype.h"

class Drugtype : public QWidget
{
	Q_OBJECT

public:
	Drugtype(QWidget *parent = 0);
	~Drugtype();

private:
	Ui::Drugtype ui;
	private slots:
		void showTable(QTreeWidgetItem*,int column);
		void on_addButton_clicked();
		void on_editButton_clicked();
		void on_saveButton_clicked();
		void on_deleteButton_clicked();
		void on_exitButton_clicked();
		void initUI();
};

#endif // DRUGTYPE_H
