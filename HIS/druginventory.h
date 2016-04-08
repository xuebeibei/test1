#ifndef DRUGINVENTORY_H
#define DRUGINVENTORY_H

#include <QWidget>
#include "ui_druginventory.h"
#include <QtGui>
class DrugInventory : public QWidget
{
	Q_OBJECT

public:
	DrugInventory(QWidget *parent = 0);
	~DrugInventory();
	void initUI();
	int SheetNo();
	int InventorySheetNo();
	void SetEdit(bool IsEdit);
	int iRow;
	QListView *druglist; 
	QStringListModel *model; 
	void keyPressEvent(QKeyEvent *e);
private:
	Ui::DrugInventory ui;
public slots:
	void on_FindButton_clicked();
	void on_FindAllButton_clicked();
	void getItem(int row,int column);
	void findbyname(const QString &);
	void completeText(const QModelIndex &index); 
};

#endif // DRUGINVENTORY_H
