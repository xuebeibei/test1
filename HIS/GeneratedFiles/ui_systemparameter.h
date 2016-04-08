/********************************************************************************
** Form generated from reading UI file 'systemparameter.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SYSTEMPARAMETER_H
#define UI_SYSTEMPARAMETER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SystemParameter
{
public:

    void setupUi(QWidget *SystemParameter)
    {
        if (SystemParameter->objectName().isEmpty())
            SystemParameter->setObjectName(QString::fromUtf8("SystemParameter"));
        SystemParameter->resize(400, 300);

        retranslateUi(SystemParameter);

        QMetaObject::connectSlotsByName(SystemParameter);
    } // setupUi

    void retranslateUi(QWidget *SystemParameter)
    {
        SystemParameter->setWindowTitle(QApplication::translate("SystemParameter", "SystemParameter", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SystemParameter: public Ui_SystemParameter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SYSTEMPARAMETER_H
