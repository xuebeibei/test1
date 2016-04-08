#ifndef DICTIONARYTYPE_H
#define DICTIONARYTYPE_H

#include <QWidget>
#include "ui_dictionarytype.h"

class Dictionarytype : public QWidget
{
	Q_OBJECT

public:
	Dictionarytype(QWidget *parent = 0);
	~Dictionarytype();

private:
	Ui::Dictionarytype ui;
	private slots:
	void showTable(QTreeWidgetItem*,int column);
	void on_addButton_clicked();
	void on_editButton_clicked();
	void on_saveButton_clicked();
	void on_deleteButton_clicked();
	void on_exitButton_clicked();
	void initUI();
};

#endif // DICTIONARYTYPE_H
