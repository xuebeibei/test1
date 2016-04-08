#ifndef DRUGDICTIONARYADD_H
#define DRUGDICTIONARYADD_H

#include <QWidget>
#include "ui_drugdictionaryadd.h"

class Drugdictionaryadd : public QWidget
{
	Q_OBJECT

public:
	Drugdictionaryadd(QWidget *parent = 0);
	~Drugdictionaryadd();
	void initUI();
private:
	Ui::Drugdictionaryadd ui;
	bool IsEdit;
	public slots:
		void showinfo(const QString &text); 
		void on_saveButton_clicked();
		void on_cancelButton_clicked();
		void edit(QStringList);
};

#endif // DRUGDICTIONARYADD_H
