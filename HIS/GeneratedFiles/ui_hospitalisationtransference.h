/********************************************************************************
** Form generated from reading UI file 'hospitalisationtransference.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOSPITALISATIONTRANSFERENCE_H
#define UI_HOSPITALISATIONTRANSFERENCE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HospitalisationTransference
{
public:

    void setupUi(QWidget *HospitalisationTransference)
    {
        if (HospitalisationTransference->objectName().isEmpty())
            HospitalisationTransference->setObjectName(QString::fromUtf8("HospitalisationTransference"));
        HospitalisationTransference->resize(400, 300);

        retranslateUi(HospitalisationTransference);

        QMetaObject::connectSlotsByName(HospitalisationTransference);
    } // setupUi

    void retranslateUi(QWidget *HospitalisationTransference)
    {
        HospitalisationTransference->setWindowTitle(QApplication::translate("HospitalisationTransference", "HospitalisationTransference", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class HospitalisationTransference: public Ui_HospitalisationTransference {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOSPITALISATIONTRANSFERENCE_H
