/********************************************************************************
** Form generated from reading UI file 'systempersonnel.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SYSTEMPERSONNEL_H
#define UI_SYSTEMPERSONNEL_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SystemPersonnel
{
public:

    void setupUi(QWidget *SystemPersonnel)
    {
        if (SystemPersonnel->objectName().isEmpty())
            SystemPersonnel->setObjectName(QString::fromUtf8("SystemPersonnel"));
        SystemPersonnel->resize(400, 300);

        retranslateUi(SystemPersonnel);

        QMetaObject::connectSlotsByName(SystemPersonnel);
    } // setupUi

    void retranslateUi(QWidget *SystemPersonnel)
    {
        SystemPersonnel->setWindowTitle(QApplication::translate("SystemPersonnel", "SystemPersonnel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SystemPersonnel: public Ui_SystemPersonnel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SYSTEMPERSONNEL_H
