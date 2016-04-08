#ifndef UIELEMENT_H
#define UIELEMENT_H

#include <QProgressBar>
#include "QFramer/ftabwidget.h"
#include "animationgradientlabel.h"


class ClinicManagement : public FTabWidget
{
    Q_OBJECT
private:
    QList<QProgressBar *> progressBars;
public:
    explicit ClinicManagement(QWidget *parent = 0);
    void initUI();
    void Charge();
    void SourceInfoManagement();
    void DailyReport();
	void Statistics();
	void InternalPayment();
	void ComponentInfoManagement4();
	void Pharmacystorage();
};

#endif // UIELEMENT_H
