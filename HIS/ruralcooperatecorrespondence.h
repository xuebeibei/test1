#ifndef RURALCOOPERATECORRESPONDENCE_H
#define RURALCOOPERATECORRESPONDENCE_H
#include<QFileDialog>
#include <QWidget>
#include "ui_ruralcooperatecorrespondence.h"

class ruralcooperatecorrespondence : public QWidget
{
	Q_OBJECT

public:
	ruralcooperatecorrespondence(QWidget *parent = 0);
	~ruralcooperatecorrespondence();
	QStringList CSVList; 
	void initUI();
private:
	Ui::ruralcooperatecorrespondence ui;
	private slots:
		//void showTable(QTreeWidgetItem*,int column);
		//void on_addButton_clicked();
		//void on_editButton_clicked();
		void on_deleteButton_clicked();
		void on_exitButton_clicked();
		void on_outputButton_clicked();
		void on_inputButton_clicked();
		void showTable(QTreeWidgetItem*,int);
	//	void initUI();
};

#endif // RURALCOOPERATECORRESPONDENCE_H
