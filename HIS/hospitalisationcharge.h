#ifndef HOSPITALISATIONCHARGE_H
#define HOSPITALISATIONCHARGE_H

#include <QWidget>
#include "ui_hospitalisationcharge.h"
#include <QtGui>
#include "package.h"
class HospitalisationCharge : public QWidget
{
	Q_OBJECT

public:
	HospitalisationCharge(QWidget *parent = 0);
	~HospitalisationCharge();
	void initUI();
	void filePrintPreview();
	void setEdit(bool IsEdit);
	void edit(QString strNo);
	int itotalcount;
	int iRow;
	double dueincome;
	bool Isupdate;
	QListWidget*list_widget ;
	void keyPressEvent(QKeyEvent *e);
	Package*package;
private:
	Ui::HospitalisationCharge ui;
	private slots:
		void on_printButton_clicked();
		void on_saveButton_clicked();
		void on_previewButton_clicked();
		void on_discardButton_clicked();
		void on_addButton_clicked();
		void on_editButton_clicked();
		void on_deleteButton_clicked();
		void on_addrowButton_clicked();
		void on_deleterowButton_clicked();
		void on_packageButton_clicked();
		void getInfo(QString strinfo);
		void getItem(int row,int column);
		void textAreaChanged();
		void print(QPrinter* printer);
		void addPackage(QString);
};

#endif // HOSPITALISATIONCHARGE_H
