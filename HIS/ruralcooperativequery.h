#ifndef RURALCOOPERATIVEQUERY_H
#define RURALCOOPERATIVEQUERY_H
#include <QtGui>
#include <QWidget>
#include "ui_ruralcooperativequery.h"

class Ruralcooperativequery : public QWidget
{
	Q_OBJECT

public:
	Ruralcooperativequery(QWidget *parent = 0);
	~Ruralcooperativequery();
	void initUI();
private:
	Ui::Ruralcooperativequery ui;
	private slots:
		void showTable(QTreeWidgetItem*,int column);
		void on_printButton_clicked();
		void on_previewButton_clicked();
		void on_outButton_clicked();
		void filePrintPreview();
		void filePrint();
		void print(QPrinter* printer);
};

#endif // RURALCOOPERATIVEQUERY_H
