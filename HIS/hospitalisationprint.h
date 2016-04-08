#ifndef HOSPITALISATIONPRINT_H
#define HOSPITALISATIONPRINT_H
#include <QtGui>
#include <QWidget>
#include "ui_hospitalisationprint.h"
class QTextDocument;
class QTextEdit;
class QEvent;
class QObject;
class Hospitalisationprint : public QWidget
{
	Q_OBJECT

public:
	Hospitalisationprint(QWidget *parent = 0);
	~Hospitalisationprint();

private:
	Ui::Hospitalisationprint ui;
	public slots:
		void on_printButton_clicked();
		void on_previewButton_clicked();
		void print(QPrinter* printer);
		void filePrintPreview();
		void filePrint();
		void initUI(QString strNo);
};

#endif // HOSPITALISATIONPRINT_H
