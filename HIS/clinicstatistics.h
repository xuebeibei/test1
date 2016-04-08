#ifndef CLINICSTATISTICS_H
#define CLINICSTATISTICS_H
#include <QtGui>
#include <QWidget>
#include "ui_clinicstatistics.h"

class ClinicStatistics : public QWidget
{
	Q_OBJECT

public:
	ClinicStatistics(QWidget *parent = 0);
	~ClinicStatistics();
	void initUI();
	QStringList words;
	QListView *listView; 
	QStringListModel *model; 
	QListView *patientlist; 
	void keyPressEvent(QKeyEvent *e);
private:
	Ui::ClinicStatistics ui;
	private slots:
		void on_queryButton_clicked();
		void on_clearButton_clicked();
		void on_queryButton_2_clicked();
		void on_clearButton_2_clicked();
		void on_queryButton_3_clicked();
		void on_clearButton_3_clicked();
		void getItem(int row,int column);
		void on_radioButton_clicked();
		void on_radioButton_2_clicked();
		void on_radioButton_3_clicked();
		void on_radioButton_4_clicked();
		void completeText(const QModelIndex &index); 
		void setCompleter(const QString &text); 

		void on_printButton_clicked();
		void on_previewButton_clicked();
		void print(QPrinter* printer);
		void filePrintPreview();

		void on_printButton_2_clicked();
		void on_previewButton_2_clicked();
		void print_2(QPrinter* printer);
		void filePrintPreview_2();

		void on_printButton_3_clicked();
		void on_previewButton_3_clicked();
		void print_3(QPrinter* printer);
		void filePrintPreview_3();
};

#endif // CLINICSTATISTICS_H
