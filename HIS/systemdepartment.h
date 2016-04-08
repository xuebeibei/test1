#ifndef SYSTEMDEPARTMENT_H
#define SYSTEMDEPARTMENT_H

#include <QWidget>
#include "ui_systemdepartment.h"

class SystemDepartment : public QWidget
{
	Q_OBJECT

public:
	SystemDepartment(QWidget *parent = 0);
	~SystemDepartment();

private:
	Ui::SystemDepartment ui;
};

#endif // SYSTEMDEPARTMENT_H
