/********************************************************************************
** Form generated from reading UI file 'systemdepartment.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SYSTEMDEPARTMENT_H
#define UI_SYSTEMDEPARTMENT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SystemDepartment
{
public:

    void setupUi(QWidget *SystemDepartment)
    {
        if (SystemDepartment->objectName().isEmpty())
            SystemDepartment->setObjectName(QString::fromUtf8("SystemDepartment"));
        SystemDepartment->resize(400, 300);

        retranslateUi(SystemDepartment);

        QMetaObject::connectSlotsByName(SystemDepartment);
    } // setupUi

    void retranslateUi(QWidget *SystemDepartment)
    {
        SystemDepartment->setWindowTitle(QApplication::translate("SystemDepartment", "SystemDepartment", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SystemDepartment: public Ui_SystemDepartment {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SYSTEMDEPARTMENT_H
