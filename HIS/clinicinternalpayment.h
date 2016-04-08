#ifndef CLINICINTERNALPAYMENT_H
#define CLINICINTERNALPAYMENT_H

#include <QWidget>
#include "ui_clinicinternalpayment.h"
class QTextDocument;
class QTextEdit;
class QEvent;
class QObject;
class ClinicInternalPayment : public QWidget
{
	Q_OBJECT

public:
	ClinicInternalPayment(QWidget *parent = 0);
	~ClinicInternalPayment();
	void initUI();
	void filePrintPreview();
private:
	Ui::ClinicInternalPayment ui;
	private slots:
		void on_printButton_clicked();
		void on_previewButton_clicked();
		void on_excelButton_clicked();
		void on_queryButton_clicked();
		void print(QPrinter* printer);
};

#endif // CLINICINTERNALPAYMENT_H
