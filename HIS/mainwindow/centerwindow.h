

#ifndef CENTERWINDOW_H
#define CENTERWINDOW_H

#include "QFramer/fcenterwindow.h"
#include "functionpages/ClinicManagement.h"
#include "functionpages/HospitalizationManagement.h"
#include "interface.h"
#include "functionpages/systemmanagement.h"
#include <QVBoxLayout>
#include "help.h"

class CenterWindow : public FCenterWindow
{
    Q_OBJECT

public:
    ClinicManagement* clinicmanage;
	HospitalizationManagement* hospitalisationmanage;
public:
    explicit CenterWindow(QWidget *parent = 0);
    void initUI();
    void addWiggleWiget();
signals:

public slots:
//    void cloudAntimation();
};

#endif // CENTERWINDOW_H
