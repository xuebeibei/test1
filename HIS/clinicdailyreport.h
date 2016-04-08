#ifndef CLINICDAILYREPORT_H
#define CLINICDAILYREPORT_H
#include <QtGui>
#include <QWidget>
#include "ui_clinicdailyreport.h"

class ClinicDailyReport : public QWidget
{
	Q_OBJECT

public:
	ClinicDailyReport(QWidget *parent = 0);
	~ClinicDailyReport();
	void initUI();
	int sheetNo();
	bool eventFilter(QObject*obj,QEvent*event);
private:
	Ui::ClinicDailyReport ui;
	public slots:
		void on_saveButton_clicked();
		void on_discardButton_clicked();
		void on_addButton_clicked();
		void on_queryButton_clicked();
		void on_editButton_clicked();
		void on_deleteButton_clicked();
		void on_printButton_clicked();
		void on_previewButton_clicked();
		void print(QPrinter* printer);
		void filePrintPreview();
};

#endif // CLINICDAILYREPORT_H
