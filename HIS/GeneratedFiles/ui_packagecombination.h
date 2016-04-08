/********************************************************************************
** Form generated from reading UI file 'packagecombination.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PACKAGECOMBINATION_H
#define UI_PACKAGECOMBINATION_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Packagecombination
{
public:

    void setupUi(QWidget *Packagecombination)
    {
        if (Packagecombination->objectName().isEmpty())
            Packagecombination->setObjectName(QString::fromUtf8("Packagecombination"));
        Packagecombination->resize(400, 300);

        retranslateUi(Packagecombination);

        QMetaObject::connectSlotsByName(Packagecombination);
    } // setupUi

    void retranslateUi(QWidget *Packagecombination)
    {
        Packagecombination->setWindowTitle(QApplication::translate("Packagecombination", "Packagecombination", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Packagecombination: public Ui_Packagecombination {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PACKAGECOMBINATION_H
