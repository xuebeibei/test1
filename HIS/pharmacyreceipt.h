#ifndef PHARMACYRECEIPT_H
#define PHARMACYRECEIPT_H
#include <QtGui>
#include <QWidget>
#include "ui_pharmacyreceipt.h"

class PharmacyReceipt : public QWidget
{
	Q_OBJECT

public:
	PharmacyReceipt(QWidget *parent = 0);
	~PharmacyReceipt();
	void initUI();
	int SheetNo();
	int PublicInfoSheetNo();
	int InventorySheetNo();
	double TotalPrice();
	//void printTableWidget(const QTableWidget* view,QString stitile,QPrinter *printer);
	void SetEdit(bool IsEdit);
	int iRow;
	QListWidget*list_widget ;
	void keyPressEvent(QKeyEvent *e);
private:
	Ui::PharmacyReceipt ui;
public slots:
	void on_printButton_clicked();
	void on_saveButton_clicked();
	void on_previewButton_clicked();
	void on_discardButton_clicked();
	void on_addButton_clicked();
	void on_editButton_clicked();
	void on_deleteButton_clicked();
	void on_addRowButton_clicked();
	void on_deleteRowButton_clicked();
	void filePrintPreview();
	//void filePrint();
	void print(QPrinter* printer);
	void getItem(int row,int column);
	void pay(const QString &);
	void on_radioButton_Minus_clicked();
	void on_radioButton_Add_clicked();
	void on_radioButton_sendback_clicked();
	void on_radioButton_broken_clicked();
	void edit(QString strNo);
};

#endif // PHARMACYRECEIPT_H
