#ifndef SUPPLIER_H
#define SUPPLIER_H

#include <QWidget>
#include "ui_supplier.h"

class Supplier : public QWidget
{
	Q_OBJECT

public:
	Supplier(QWidget *parent = 0);
	~Supplier();

private:
	Ui::Supplier ui;
	private slots:
		void showTable(QTreeWidgetItem*,int column);
		void on_addButton_clicked();
		void on_editButton_clicked();
		void on_saveButton_clicked();
		void on_deleteButton_clicked();
		void on_exitButton_clicked();
		void initUI();
};

#endif // SUPPLIER_H
