#ifndef GETDOCTOR_H
#define GETDOCTOR_H

#include <QDialog>
#include "ui_getdoctor.h"

class GetDoctor : public QDialog
{
	Q_OBJECT

public:
	GetDoctor(QWidget *parent = 0);
	~GetDoctor();
	void initData(QString strDoctor);
	QString strDoctorName;
private:
	Ui::GetDoctor ui;
	private slots:
		void on_okButton_clicked();
		void on_cancelButton_clicked();
		void currentItem();
};

#endif // GETDOCTOR_H
