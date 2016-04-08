#ifndef DRUGSTATISTICS_H
#define DRUGSTATISTICS_H

#include <QWidget>
#include "ui_drugstatistics.h"
#include <QtGui>
class DrugStatistics : public QWidget
{
	Q_OBJECT

public:
	DrugStatistics(QWidget *parent = 0);
	~DrugStatistics();
	void initUI();
	int iRow;
	QListView *druglist; 
	QStringListModel *model; 
	void keyPressEvent(QKeyEvent *e);
private:
	Ui::DrugStatistics ui;
public slots:
	void on_printButton_clicked();
	void on_findButton_clicked();
	//void on_saveButton_clicked();
	//void on_discardButton_clicked();
	void on_previewButton_clicked();
	void on_radioButton_clicked();
	void on_excelButton_clicked();
	void print(QPrinter* printer);
	void filePrintPreview();
	void DrugName(const QString &);
	void getItem(int row,int column);
	void completeText(const QModelIndex &index); 
};

#endif // DRUGSTATISTICS_H
