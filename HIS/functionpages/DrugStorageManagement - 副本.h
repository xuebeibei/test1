#ifndef DATAANALYSIS_H
#define DATAANALYSIS_H

#include "QFramer/ftabwidget.h"
#include "animationgradientlabel.h"
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
};

#endif // DATAANALYSIS_H
