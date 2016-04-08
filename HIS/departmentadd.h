#ifndef DEPARTMENTADD_H
#define DEPARTMENTADD_H

#include <QWidget>
#include "ui_departmentadd.h"

class Departmentadd : public QWidget
{
	Q_OBJECT

public:
	Departmentadd(QWidget *parent = 0);
	~Departmentadd();
	Ui::Departmentadd ui;
private:
	
	private slots:
		void on_okButton_clicked();
		void on_cancelButton_clicked();
};

#endif // DEPARTMENTADD_H
