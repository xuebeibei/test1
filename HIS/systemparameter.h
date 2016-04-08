#ifndef SYSTEMPARAMETER_H
#define SYSTEMPARAMETER_H

#include <QWidget>
#include "ui_systemparameter.h"

class SystemParameter : public QWidget
{
	Q_OBJECT

public:
	SystemParameter(QWidget *parent = 0);
	~SystemParameter();

private:
	Ui::SystemParameter ui;
};

#endif // SYSTEMPARAMETER_H
