#ifndef PHARMACYCHECK_H
#define PHARMACYCHECK_H
#include <QtGui>
#include <QWidget>
#include "ui_pharmacycheck.h"

class PharmacyCheck : public QWidget
{
	Q_OBJECT

public:
	PharmacyCheck(QWidget *parent = 0);
	~PharmacyCheck();
	void initUI();
	int SheetNo();
	double TotalPrice();
	int PublicInfoSheetNo();
	int InventorySheetNo();
	//void printTableWidget(const QTableWidget* view,QString stitile,QPrinter *printer);
	void SetEdit(bool IsEdit);
	int iRow;
	QListWidget*list_widget ;
	void keyPressEvent(QKeyEvent *e);
private:
	Ui::PharmacyCheck ui;
public slots:
	void on_printButton_clicked();
	void on_saveButton_clicked();
	void on_previewButton_clicked();
	void on_addButton_clicked();
	void on_discardButton_clicked();
	void on_addRowButton_clicked();
	void on_deleteRowButton_clicked();
	//void on_checkButton_clicked();
	void getItem(int row,int column);
	void filePrintPreview();
	void print(QPrinter* printer);
	void on_editButton_clicked();
	void on_deleteButton_clicked();
	void edit(QString strNo);
};

#endif // PHARMACYCHECK_H
