#ifndef HOSPITALISATIONTRANSFERENCE_H
#define HOSPITALISATIONTRANSFERENCE_H

#include <QWidget>
#include "ui_hospitalisationtransference.h"

class HospitalisationTransference : public QWidget
{
	Q_OBJECT

public:
	HospitalisationTransference(QWidget *parent = 0);
	~HospitalisationTransference();

private:
	Ui::HospitalisationTransference ui;
};

#endif // HOSPITALISATIONTRANSFERENCE_H
