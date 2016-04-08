#ifndef PERSONNELADD_H
#define PERSONNELADD_H

#include <QWidget>
#include "ui_personneladd.h"

class personneladd : public QWidget
{
	Q_OBJECT

public:
	personneladd(QWidget *parent = 0);
	~personneladd();

private:
	Ui::personneladd ui;
};

#endif // PERSONNELADD_H
