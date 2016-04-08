#ifndef CLINICDRUGFILTER_H
#define CLINICDRUGFILTER_H

#include <QDialog>
#include "ui_clinicdrugfilter.h"
namespace Ui {
	class ClinicDrugFilter;
}
class ClinicDrugFilter : public QDialog
{
	Q_OBJECT

public:
	ClinicDrugFilter(QWidget *parent = 0);
	~ClinicDrugFilter();
	void initData(QString strName);
	QString strDrugName;
private:
	Ui::ClinicDrugFilter *ui;
private  slots:
	void on_okButton_clicked();
	void on_cancelButton_clicked();
	void currentItem();
};

#endif // CLINICDRUGFILTER_H
