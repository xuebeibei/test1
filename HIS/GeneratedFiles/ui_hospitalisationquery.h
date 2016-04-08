/********************************************************************************
** Form generated from reading UI file 'hospitalisationquery.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOSPITALISATIONQUERY_H
#define UI_HOSPITALISATIONQUERY_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HospitalisationQuery
{
public:

    void setupUi(QWidget *HospitalisationQuery)
    {
        if (HospitalisationQuery->objectName().isEmpty())
            HospitalisationQuery->setObjectName(QString::fromUtf8("HospitalisationQuery"));
        HospitalisationQuery->resize(400, 300);

        retranslateUi(HospitalisationQuery);

        QMetaObject::connectSlotsByName(HospitalisationQuery);
    } // setupUi

    void retranslateUi(QWidget *HospitalisationQuery)
    {
        HospitalisationQuery->setWindowTitle(QApplication::translate("HospitalisationQuery", "HospitalisationQuery", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class HospitalisationQuery: public Ui_HospitalisationQuery {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOSPITALISATIONQUERY_H
