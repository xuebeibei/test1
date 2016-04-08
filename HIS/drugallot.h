#ifndef DRUGALLOT_H
#define DRUGALLOT_H
#include <QtGui>
#include <QWidget>
#include "ui_drugallot.h"

class DrugAllot : public QWidget
{
	Q_OBJECT

public:
	DrugAllot(QWidget *parent = 0);
	~DrugAllot();
	void initUI();
	int SheetNo_Sale();
	int SheetNo_Store();
	double TotalPrice_sale();
	int PublicInfoSheetNo_Store();
	int PublicInfoSheetNo_Sale();
	int InventorySheetNo();
	//void printTableWidget(const QTableWidget* view,QString stitile,QPrinter *printer);
	void SetEdit(bool IsEdit);
	int iRow_Sale;
	int iRow_Store;
	void keyPressEvent(QKeyEvent *e);
	QListWidget*list_widget ;
	QListWidget*list_widget2 ;
public slots:
	void on_printButton_clicked();
	void on_printButton_2_clicked();
	void on_saveButton_clicked();
	void on_saveButton_2_clicked();
	void on_previewButton_clicked();
	void on_previewButton_2_clicked();
	void on_discardButton_clicked();
	void on_discardButton_2_clicked();
	void on_addButton_clicked();
	void on_addButton_2_clicked();
	void on_editButton_clicked();
	void on_editButton_2_clicked();
	void on_deleteButton_clicked();
	void on_deleteButton_2_clicked();
	void on_addRowButton_clicked();
	void on_addRowButton_2_clicked();
	void on_deleteRowButton_clicked();
	void on_deleteRowButton_2_clicked();
	void filePrintPreview();
	void filePrintPreview_2();
	//void filePrint();
	void print_XSDB(QPrinter* printer);
	void print_CKDB(QPrinter* printer);
	void getItem_Sale(int row,int column);
	void getItem_Store(int row,int column);
	void pay(const QString &);
	void on_radioButton_Sellout_clicked();
	void on_radioButton_Back_clicked();
	void on_radioButton_ToYF_clicked();
	void on_radioButton_ToYK_clicked();
	void edit_sale(QString strNo);
	void edit_store(QString strNo);
private:
	Ui::DrugAllot ui;
	//bool eventFilter(QObject*obj,QEvent*event);
};

#endif // DRUGALLOT_H
