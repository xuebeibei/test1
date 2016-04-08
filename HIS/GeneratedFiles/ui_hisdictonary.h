/********************************************************************************
** Form generated from reading UI file 'hisdictonary.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HISDICTONARY_H
#define UI_HISDICTONARY_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Hisdictonary
{
public:

    void setupUi(QWidget *Hisdictonary)
    {
        if (Hisdictonary->objectName().isEmpty())
            Hisdictonary->setObjectName(QString::fromUtf8("Hisdictonary"));
        Hisdictonary->resize(400, 300);

        retranslateUi(Hisdictonary);

        QMetaObject::connectSlotsByName(Hisdictonary);
    } // setupUi

    void retranslateUi(QWidget *Hisdictonary)
    {
        Hisdictonary->setWindowTitle(QApplication::translate("Hisdictonary", "Hisdictonary", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Hisdictonary: public Ui_Hisdictonary {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HISDICTONARY_H
