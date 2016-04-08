#ifndef SETTLEMETHOD_H
#define SETTLEMETHOD_H

#include <QWidget>
#include "ui_settlemethod.h"

class Settlemethod : public QWidget
{
	Q_OBJECT

public:
	Settlemethod(QWidget *parent = 0);
	~Settlemethod();

private:
	Ui::Settlemethod ui;
	private slots:
		void showTable(QTreeWidgetItem*,int column);
		void on_addButton_clicked();
		void on_editButton_clicked();
		void on_saveButton_clicked();
		void on_deleteButton_clicked();
		void on_exitButton_clicked();
		void initUI();
};

#endif // SETTLEMETHOD_H
