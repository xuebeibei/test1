#ifndef DRUGPRICING_H
#define DRUGPRICING_H
#include <QtGui>
#include <QWidget>
#include "ui_drugpricing.h"

class DrugPricing : public QWidget
{
	Q_OBJECT

public:
	DrugPricing(QWidget *parent = 0);
	~DrugPricing();
	void initUI();
	int SheetNo();
	int PublicInfoSheetNo();
	int iRow;
	double TotalPrice();
	void SetEdit(bool IsEdit);
	QListWidget*list_widget ;
	void keyPressEvent(QKeyEvent *e);
private:
	Ui::DrugPricing ui;
public slots:
	void on_printButton_clicked();
	void on_saveButton_clicked();
	void on_previewButton_clicked();
	void on_addRowButton_clicked();
	void on_deleteRowButton_clicked();
	void on_addButton_clicked();
	void on_editButton_clicked();
	void on_deleteButton_clicked();
	void on_discardButton_clicked();
	//void on_checkButton_clicked();
	void getItem(int row,int column);
	void filePrintPreview();
	void print(QPrinter* printer);
	void edit(QString strNo);
};

#endif // DRUGPRICING_H
