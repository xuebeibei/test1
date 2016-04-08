#ifndef DRUGSTORAGE_H
#define DRUGSTORAGE_H
#include <QtGui>
#include <QWidget>
#include "ui_drugstorage.h"

class DrugStorage : public QWidget
{
	Q_OBJECT

public:
	DrugStorage(QWidget *parent = 0);
	~DrugStorage();
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
	Ui::DrugStorage ui;
	//bool eventFilter(QObject*obj,QEvent*event);
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
	void edit(QString strNo);
};

#endif // DRUGSTORAGE_H
