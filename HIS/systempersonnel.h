#ifndef SYSTEMPERSONNEL_H
#define SYSTEMPERSONNEL_H

#include <QWidget>
#include "ui_systempersonnel.h"

class SystemPersonnel : public QWidget
{
	Q_OBJECT

public:
	SystemPersonnel(QWidget *parent = 0);
	~SystemPersonnel();

private:
	Ui::SystemPersonnel ui;
};

#endif // SYSTEMPERSONNEL_H
