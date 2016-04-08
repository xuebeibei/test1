/********************************************************************************
** Form generated from reading UI file 'systemdrugdictionary.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SYSTEMDRUGDICTIONARY_H
#define UI_SYSTEMDRUGDICTIONARY_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SystemDrugDictionary
{
public:

    void setupUi(QWidget *SystemDrugDictionary)
    {
        if (SystemDrugDictionary->objectName().isEmpty())
            SystemDrugDictionary->setObjectName(QString::fromUtf8("SystemDrugDictionary"));
        SystemDrugDictionary->resize(400, 300);

        retranslateUi(SystemDrugDictionary);

        QMetaObject::connectSlotsByName(SystemDrugDictionary);
    } // setupUi

    void retranslateUi(QWidget *SystemDrugDictionary)
    {
        SystemDrugDictionary->setWindowTitle(QApplication::translate("SystemDrugDictionary", "SystemDrugDictionary", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SystemDrugDictionary: public Ui_SystemDrugDictionary {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SYSTEMDRUGDICTIONARY_H
