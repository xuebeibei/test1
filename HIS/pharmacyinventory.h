#ifndef PHARMACYINVENTORY_H
#define PHARMACYINVENTORY_H
#include <QtGui>
#include <QWidget>
#include "ui_pharmacyinventory.h"

class PharmacyInventory : public QWidget
{
	Q_OBJECT

public:
	PharmacyInventory(QWidget *parent = 0);
	~PharmacyInventory();
	void initUI();
	int SheetNo();
	int InventorySheetNo();
	//void printTableWidget(const QTableWidget* view,QString stitile,QPrinter *printer);
	void SetEdit(bool IsEdit);
	int iRow;
	QListWidget*list_widget ;
	QListView *druglist; 
	QStringListModel *model; 
	void keyPressEvent(QKeyEvent *e);
private:
	Ui::PharmacyInventory ui;
public slots:
	void on_FindButton_clicked();
	void on_FindAllButton_clicked();
	void getItem(int row,int column);
	void findbyname(const QString &);
	void completeText(const QModelIndex &index); 
};

#endif // PHARMACYINVENTORY_H
