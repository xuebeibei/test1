#ifndef RURALCOOPERATIVEDICTIONARY_H
#define RURALCOOPERATIVEDICTIONARY_H

#include <QWidget>
#include "ui_ruralcooperativedictionary.h"
#include "cooperativedictionary.h"
class Ruralcooperativedictionary : public QWidget
{
	Q_OBJECT

public:
	Ruralcooperativedictionary(QWidget *parent = 0);
	~Ruralcooperativedictionary();
	void initUI();
	QString strNo;
	Cooperativedictionary*dictionary;
private:
	Ui::Ruralcooperativedictionary ui;
	private slots:
		void on_browseButton_clicked();
		void on_clearButton_clicked();
		void on_checkButton_clicked();
		void on_browseButton_2_clicked();
		void on_clearButton_2_clicked();
		void on_checkButton_2_clicked();
		void on_queryButton_clicked();
		void on_outButton_clicked();
		void on_saveButton_clicked();
		void getItem(int row,int column);
		void getItem2(int row,int column);
		void setNo(QString);
};

#endif // RURALCOOPERATIVEDICTIONARY_H
