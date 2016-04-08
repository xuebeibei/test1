#ifndef HOSPITALISATIONINTERNALPAYMENT_H
#define HOSPITALISATIONINTERNALPAYMENT_H

#include <QWidget>
#include "ui_hospitalisationinternalpayment.h"

class HospitalisationInternalPayment : public QWidget
{
	Q_OBJECT

public:
	HospitalisationInternalPayment(QWidget *parent = 0);
	~HospitalisationInternalPayment();
	void initUI();
	void filePrintPreview();
private:
	Ui::HospitalisationInternalPayment ui;
	private slots:
		void on_printButton_clicked();
		void on_previewButton_clicked();
		void on_excelButton_clicked();
		void on_queryButton_clicked();
		void print(QPrinter* printer);
};

#endif // HOSPITALISATIONINTERNALPAYMENT_H
