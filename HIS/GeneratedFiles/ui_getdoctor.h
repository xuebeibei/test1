/********************************************************************************
** Form generated from reading UI file 'getdoctor.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GETDOCTOR_H
#define UI_GETDOCTOR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_GetDoctor
{
public:
    QPushButton *cancelButton;
    QListWidget *listWidget;
    QPushButton *okButton;

    void setupUi(QDialog *GetDoctor)
    {
        if (GetDoctor->objectName().isEmpty())
            GetDoctor->setObjectName(QString::fromUtf8("GetDoctor"));
        GetDoctor->resize(312, 272);
        cancelButton = new QPushButton(GetDoctor);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setGeometry(QRect(211, 240, 75, 23));
        QFont font;
        font.setFamily(QString::fromUtf8("Agency FB"));
        font.setPointSize(12);
        cancelButton->setFont(font);
        listWidget = new QListWidget(GetDoctor);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(19, 9, 271, 221));
        okButton = new QPushButton(GetDoctor);
        okButton->setObjectName(QString::fromUtf8("okButton"));
        okButton->setGeometry(QRect(130, 240, 75, 23));
        okButton->setFont(font);

        retranslateUi(GetDoctor);

        QMetaObject::connectSlotsByName(GetDoctor);
    } // setupUi

    void retranslateUi(QDialog *GetDoctor)
    {
        GetDoctor->setWindowTitle(QApplication::translate("GetDoctor", "\345\214\273\347\224\237", 0, QApplication::UnicodeUTF8));
        cancelButton->setText(QApplication::translate("GetDoctor", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
        okButton->setText(QApplication::translate("GetDoctor", "\347\241\256\345\256\232", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class GetDoctor: public Ui_GetDoctor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GETDOCTOR_H
