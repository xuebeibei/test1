#ifndef USER_H
#define USER_H

#include <QWidget>
#include "ui_user.h"
#include <QtGui>
class User : public QWidget
{
	Q_OBJECT

public:
	User(QWidget *parent = 0);
	~User();

private:
	Ui::User ui;
	private slots:
		void showTable(QTreeWidgetItem*,int column);
		void on_addButton_clicked();
		void on_editButton_clicked();
		void on_saveButton_clicked();
		void on_deleteButton_clicked();
		void on_exitButton_clicked();
		void initUI();
};

#endif // USER_H
