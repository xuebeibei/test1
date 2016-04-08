#ifndef CLINICCHARGE_H
#define CLINICCHARGE_H
#include <QtGui>
#include <QWidget>
#include "ui_cliniccharge.h"
#include <QTextDocumentFragment>

class QTextDocument;
class QTextEdit;
class QEvent;
class QObject;
class ClinicCharge : public QWidget
{
	Q_OBJECT

public:
	ClinicCharge(QWidget *parent = 0);
	~ClinicCharge();
	void initUI();
	int sheetNo();
	void setEdit(bool IsEdit);
	int iRow;
	bool Isupdate;
	QComboBox *combox;
	QListWidget*list_widget ;
private:
	Ui::ClinicCharge ui;
	//bool eventFilter(QObject*obj,QEvent*event);
/*	void keyPressEvent(QEvent* e);*/

	QStringList words; // 整个完成列表的单词
	QListView *doctorlist; 
	QStringListModel *model; 
	QListView *departmentlist;
	QStringListModel *departmentmodel; 
	void keyPressEvent(QKeyEvent *e);
	void focusOutEvent(QFocusEvent *e);
	//bool eventFilter(QObject*obj,QEvent*event);
public slots:
	void on_printButton_clicked();
	void on_previewButton_clicked();
	void filePrint();
	void print(QPrinter* printer);
	void printString(const QString &htmlString);
	void filePrintPreview();
	void on_saveButton_clicked();

	void on_checkButton_clicked();
	void on_discardButton_clicked();
	void on_addButton_clicked();
	void on_editButton_clicked();
	void on_deleteButton_clicked();
	void on_packageButton_clicked();
	void on_addrowButton_clicked();
	void on_deleterowButton_clicked();


	void getItem(int row,int column);
	void selectDoctor(QString strDoctor);
	void edit(QString strNo);
	void indexchange(int index);
	void selectItem(QListWidgetItem *item);
	void completeText(const QModelIndex &index); 
	void setCompleter(const QString &text); 
	void showDepartment(const QString &text); 
    void addPackage(QString);
};

#endif // CLINICCHARGE_H
