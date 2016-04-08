#ifndef DRUGSTORAGEMANAGEMENT_H
#define DRUGSTORAGEMANAGEMENT_H

#include "QFramer/ftabwidget.h"

class DrugStorageManagement : public FTabWidget
{
	Q_OBJECT

public:
	explicit DrugStorageManagement(QWidget *parent = 0);
	void initUI();
	void Storage();
	void Allot();
	void Check();
	void Pricing();
	void Statistics();
	void Inventory();
};

#endif // DRUGSTORAGEMANAGEMENT_H
