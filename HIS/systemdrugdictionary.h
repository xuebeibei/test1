#ifndef SYSTEMDRUGDICTIONARY_H
#define SYSTEMDRUGDICTIONARY_H

#include <QWidget>
#include "ui_systemdrugdictionary.h"

class SystemDrugDictionary : public QWidget
{
	Q_OBJECT

public:
	SystemDrugDictionary(QWidget *parent = 0);
	~SystemDrugDictionary();

private:
	Ui::SystemDrugDictionary ui;
};

#endif // SYSTEMDRUGDICTIONARY_H
