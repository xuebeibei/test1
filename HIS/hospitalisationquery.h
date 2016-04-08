#ifndef HOSPITALISATIONQUERY_H
#define HOSPITALISATIONQUERY_H

#include <QWidget>
#include "ui_hospitalisationquery.h"

class HospitalisationQuery : public QWidget
{
	Q_OBJECT

public:
	HospitalisationQuery(QWidget *parent = 0);
	~HospitalisationQuery();

private:
	Ui::HospitalisationQuery ui;
};

#endif // HOSPITALISATIONQUERY_H
