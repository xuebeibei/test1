#ifndef VILLAGECLINIC_H
#define VILLAGECLINIC_H

#include <QWidget>
#include "ui_villageclinic.h"

class Villageclinic : public QWidget
{
	Q_OBJECT

public:
	Villageclinic(QWidget *parent = 0);
	~Villageclinic();

private:
	Ui::Villageclinic ui;
private slots:
	void showTable(QTreeWidgetItem*,int column);
	void on_addButton_clicked();
	void on_editButton_clicked();
	void on_saveButton_clicked();
	void on_deleteButton_clicked();
	void on_exitButton_clicked();
	void initUI();
};

#endif // VILLAGECLINIC_H
