#ifndef HOSPITALISATIONREGISTRY_H
#define HOSPITALISATIONREGISTRY_H

#include <QWidget>
#include "ui_hospitalisationregistry.h"
#include <QtGui>
class HospitalisationRegistry : public QWidget
{
	Q_OBJECT

public:
	HospitalisationRegistry(QWidget *parent = 0);
	~HospitalisationRegistry();
	void initUI();
	void GetCount();
	int itotalcount;
	Ui::HospitalisationRegistry ui;
	//bool eventFilter(QObject*obj,QEvent*event);
	void setEdit(bool IsEdit);
	void edit(QString strNo);
	bool Isupdate;
	QListView *doctorlist; 
	QStringListModel *model; 
	void keyPressEvent(QKeyEvent *e);
	void focusOutEvent(QFocusEvent *e);
private:
	private slots:
		void on_printButton_clicked();
		void on_saveButton_clicked();
		void on_previewButton_clicked();
		void on_checkButton_clicked();
		void on_discardButton_clicked();
		void on_addButton_clicked();
		void on_editButton_clicked();
		void on_deleteButton_clicked();
		void completeText(const QModelIndex &index); 
		void setCompleter(const QString &text); 
};

#endif // HOSPITALISATIONREGISTRY_H
