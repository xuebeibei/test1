#ifndef PHARMACYMANAGEMENT_H
#define PHARMACYMANAGEMENT_H

#include "QFramer/ftabwidget.h"

class PharmacyManagement : public FTabWidget
{
public:
	explicit PharmacyManagement(QWidget *parent = 0);
	void initUI();
	void Receipt();
	void Check();
	void Inventory();
	void Statistics();
};

#endif // PHARMACYMANAGEMENT_H
