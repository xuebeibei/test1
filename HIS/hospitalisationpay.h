#ifndef HOSPITALISATIONPAY_H
#define HOSPITALISATIONPAY_H

#include <QWidget>
#include "ui_hospitalisationpay.h"

class HospitalisationPay : public QWidget
{
	Q_OBJECT

public:
	HospitalisationPay(QWidget *parent = 0);
	~HospitalisationPay();
	void setEdit(bool IsEdit);
	void filePrintPreview();
	bool eventFilter(QObject*obj,QEvent*event);
	int itotalcount;
	bool Isupdate;
	Ui::HospitalisationPay ui;
	bool Isrefund;
private:
	public slots:
		void on_printButton_clicked();
		void on_saveButton_clicked();
		void on_previewButton_clicked();
		void on_discardButton_clicked();
		void on_addButton_clicked();
		void on_editButton_clicked();
		void on_deleteButton_clicked();
		void getInfo(QString strinfo);
		void print(QPrinter* printer);
		void textAreaChanged();
		void initUI();
		void edit(QString strNo);
		void refund(QString strNo,double amount);
};

#endif // HOSPITALISATIONPAY_H
