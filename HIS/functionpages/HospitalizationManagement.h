#ifndef DATAANALYSIS_H
#define DATAANALYSIS_H

#include "QFramer/ftabwidget.h"
#include "animationgradientlabel.h"
#include "hospitalisationcharge.h"
#include "hospitalisationdischarge.h"
#include "hospitalisationpay.h"
#include "hospitalisationregistry.h"
#include "hospitalisationstatistics.h"
#include "hospitalisationtransference.h"
#include "hospitalisationquery.h"
#include "hospitalisationinternalpayment.h"
#include "hospitalisationdailyreport.h"
class HospitalizationManagement : public FTabWidget
{
	Q_OBJECT
public:
    explicit HospitalizationManagement(QWidget *parent = 0);
	HospitalisationRegistry*registry ;
	HospitalisationQuery*query ;
	HospitalisationPay*pay ;
	HospitalisationCharge*charge;
	HospitalisationStatistics*statistics;
	HospitalisationInternalPayment*internalpayment;
	HospitalisationDischarge*discharge;
	Hospitalisationdailyreport*dailyreport;
    void initUI();
    void Registry();
    void Pay();
	void Query();
	void Charge();
	void Statistics();
	void Transference();
	void Discharge();
	void Dailyreport();
	void InternalPayment();
public slots:
	void refresh();
};

#endif // DATAANALYSIS_H
