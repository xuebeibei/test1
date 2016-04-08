#ifndef DATAANALYSIS_H
#define DATAANALYSIS_H

#include "QFramer/ftabwidget.h"
#include "animationgradientlabel.h"
class PharmacyManagement : public FTabWidget
{
	Q_OBJECT
public:
    explicit PharmacyManagement(QWidget *parent = 0);
    void initUI();
    void CurveDisplay();
    void ThreeDemensionDisplay();
};

#endif // DATAANALYSIS_H
