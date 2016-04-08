#ifndef HOSPITALISATIONSTATISTICS_H
#define HOSPITALISATIONSTATISTICS_H

#include <QWidget>
#include "ui_hospitalisationstatistics.h"
class QTextDocument;
class QTextEdit;
class QEvent;
class QObject;
class HospitalisationStatistics : public QWidget
{
	Q_OBJECT

public:
	HospitalisationStatistics(QWidget *parent = 0);
	~HospitalisationStatistics();
	void initUI();
	void filePrintPreview();
private:
	Ui::HospitalisationStatistics ui;
	private slots:
		void on_hospitalqueryButton_clicked();
		void on_hospitalclearButton_clicked();
		void on_dailyqueryButton_clicked();
		void on_payqueryButton_clicked();
		void on_payclearButton_clicked();
		void on_chargequeryButton_clicked();
		void on_chargeclearButton_clicked();
		void on_balancequeryButton_clicked();
		void on_balanceclearButton_clicked();
		void on_clearButton_4_clicked();
		void on_billqueryButton_clicked();
		void on_billclearButton_clicked();
		void on_printButton_clicked();
		void on_previewButton_clicked();
		void on_projectqueryButton_clicked();
		void on_projectclearButton_clicked();
		void getItem(const QModelIndex &index);
		void edit(const QModelIndex &index);
		void payedit(const QModelIndex &index);
		void on_radioButton_clicked();
		void on_radioButton_2_clicked();
		void on_radioButton_3_clicked();
		void on_radioButton_4_clicked();
		void on_radioButton_5_clicked();
		void on_radioButton_6_clicked();
		void showinfo(const QString &text); 
		void showinfo2(const QString &text); 
		void showinfo3(const QString &text); 
		void showinfo4(const QString &text); 
		void showinfo5(const QString &text);
		void print(QPrinter* printer);
};

#endif // HOSPITALISATIONSTATISTICS_H
