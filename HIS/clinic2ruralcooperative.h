#ifndef CLINIC2RURALCOOPERATIVE_H
#define CLINIC2RURALCOOPERATIVE_H

#include <QWidget>
#include "ui_clinic2ruralcooperative.h"

class Clinic2ruralcooperative : public QWidget
{
	Q_OBJECT

public:
	Clinic2ruralcooperative(QWidget *parent = 0);
	~Clinic2ruralcooperative();
	void initUI();
private:
	Ui::Clinic2ruralcooperative ui;
	private slots:
		void on_inputButton_clicked();
		void on_refreshButton_clicked();
		void on_radioButton_6_clicked();
		void on_radioButton_7_clicked();
		void showinfo(QListWidgetItem *item);
		void writeindb(QString strNo);
};

#endif // CLINIC2RURALCOOPERATIVE_H
