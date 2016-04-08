#ifndef PACKAGECOMBINATION_H
#define PACKAGECOMBINATION_H

#include <QWidget>
#include "ui_packagecombination.h"

class Packagecombination : public QWidget
{
	Q_OBJECT

public:
	Packagecombination(QWidget *parent = 0);
	~Packagecombination();

private:
	Ui::Packagecombination ui;
};

#endif // PACKAGECOMBINATION_H
