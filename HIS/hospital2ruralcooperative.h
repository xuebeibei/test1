#ifndef HOSPITAL2RURALCOOPERATIVE_H
#define HOSPITAL2RURALCOOPERATIVE_H

#include <QWidget>
#include "ui_hospital2ruralcooperative.h"

class Hospital2ruralcooperative : public QWidget
{
	Q_OBJECT

public:
	Hospital2ruralcooperative(QWidget *parent = 0);
	~Hospital2ruralcooperative();
	void initUI();
private:
	Ui::Hospital2ruralcooperative ui;
	private slots:
		void on_inputButton_clicked();
		void on_refreshButton_clicked();
		void on_radioButton_6_clicked();
		void on_radioButton_7_clicked();
		void showinfo(QListWidgetItem *item);
		void writeindb(QString strNo);
};

#endif // HOSPITAL2RURALCOOPERATIVE_H
