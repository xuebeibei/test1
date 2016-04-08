#ifndef PACKAGE_H
#define PACKAGE_H

#include <QWidget>
#include "ui_package.h"

class Package : public QWidget
{
	Q_OBJECT

public:
	Package(QWidget *parent = 0);
	~Package();
	void initUI();
signals:
	void showPackage(QString);
private:
	Ui::Package ui;
	private slots:
		void showTable(QTreeWidgetItem*,int column);
		void on_okButton_clicked();
		void on_exitButton_clicked();
};

#endif // PACKAGE_H
