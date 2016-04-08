#ifndef FINANCETYPE_H
#define FINANCETYPE_H


#include <QWidget>
#include "ui_financetype.h"
class Financetype : public QWidget
{
	Q_OBJECT

public:
	Financetype(QWidget *parent = 0);
	~Financetype();

private:
	Ui::Financetype ui;
	private slots:
		void showTable(QTreeWidgetItem*,int column);
		void on_addButton_clicked();
		void on_editButton_clicked();
		void on_saveButton_clicked();
		void on_deleteButton_clicked();
		void on_exitButton_clicked();
		void initUI();
};

#endif // FINANCETYPE_H
