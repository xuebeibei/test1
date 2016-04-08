#ifndef DRUGDICTIONARY_H
#define DRUGDICTIONARY_H

#include <QWidget>
#include "ui_drugdictionary.h"
#include<QFileDialog>
class Drugdictionary : public QWidget
{
	Q_OBJECT

public:
	Drugdictionary(QWidget *parent = 0);
	~Drugdictionary();

private:
	Ui::Drugdictionary ui;
	private slots:
		void showTable(QTreeWidgetItem*,int column);
		void on_addButton_clicked();
		void on_editButton_clicked();
		void on_saveButton_clicked();
		void on_deleteButton_clicked();
		void on_deleteAllButton_clicked();
		void on_exitButton_clicked();
		void on_outputButton_clicked();
		void on_inputButton_clicked();
		void initUI();
		void getItem(int,int);
};

#endif // DRUGDICTIONARY_H
