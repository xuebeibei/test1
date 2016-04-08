#ifndef HOSPITALISATIONDISCHARGE_H
#define HOSPITALISATIONDISCHARGE_H

#include <QWidget>
#include "ui_hospitalisationdischarge.h"
#include <QtGui>
class HospitalisationDischarge : public QWidget
{
	Q_OBJECT

public:
	HospitalisationDischarge(QWidget *parent = 0);
	~HospitalisationDischarge();
	void initUI();
	bool eventFilter(QObject*obj,QEvent*event);
private:
	Ui::HospitalisationDischarge ui;
	private slots:
		void on_refundButton_clicked();
		void on_supplementButton_clicked();
		void on_quitButton_clicked();
		void on_recallButton_clicked();
		void on_applyButton_clicked();
		void on_cancelButton_clicked();
		void on_printButton_clicked();
		void showinfo(const QString &text); 
		void showinfo2(const QString &text); 
		void refresh();
};

#endif // HOSPITALISATIONDISCHARGE_H
