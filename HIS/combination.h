#ifndef COMBINATION_H
#define COMBINATION_H
#include <QtGui>
#include <QWidget>
#include "ui_combination.h"

class Combination : public QWidget
{
	Q_OBJECT

public:
	Combination(QWidget *parent = 0);
	~Combination();
	void initUI();
	QListWidget*list_widget ;
	void keyPressEvent(QKeyEvent *e);
public slots:
	void on_saveButton_clicked();
	void on_discardButton_clicked();
	void on_addButton_clicked();
	void on_editButton_clicked();
	void on_deleteButton_clicked();
	void on_addrowButton_clicked();
	void on_deleterowButton_clicked();
	void on_exitButton_clicked();
	void on_queryButton_clicked();
	void getItem(int row,int column);
private:
	Ui::Combination ui;
};

#endif // COMBINATION_H
