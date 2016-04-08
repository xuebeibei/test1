#ifndef INSURANCETYPE_H
#define INSURANCETYPE_H

#include <QWidget>
#include "ui_insurancetype.h"

class Insurancetype : public QWidget
{
	Q_OBJECT

public:
	Insurancetype(QWidget *parent = 0);
	~Insurancetype();

private:
	Ui::Insurancetype ui;
private slots:
	void showTable(QTreeWidgetItem*,int column);
	void on_addButton_clicked();
	void on_editButton_clicked();
	void on_saveButton_clicked();
	void on_deleteButton_clicked();
	void on_exitButton_clicked();
	void initUI();
};

#endif // INSURANCETYPE_H
