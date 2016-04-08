#ifndef COOPERATIVEDICTIONARY_H
#define COOPERATIVEDICTIONARY_H

#include <QWidget>
#include "ui_cooperativedictionary.h"

class Cooperativedictionary : public QWidget
{
	Q_OBJECT

public:
	Cooperativedictionary(QWidget *parent = 0);
	~Cooperativedictionary();
	void initUI(QString,QString);
signals:
		void getno(QString);
public:
	Ui::Cooperativedictionary ui;
	private slots:
		void on_getNoButton_clicked();
};

#endif // COOPERATIVEDICTIONARY_H
