/********************************************************************************
** Form generated from reading UI file 'clinicdrugfilter.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLINICDRUGFILTER_H
#define UI_CLINICDRUGFILTER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ClinicDrugFilter
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QListWidget *listWidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *okButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *ClinicDrugFilter)
    {
        if (ClinicDrugFilter->objectName().isEmpty())
            ClinicDrugFilter->setObjectName(QString::fromUtf8("ClinicDrugFilter"));
        ClinicDrugFilter->resize(320, 275);
        verticalLayout_2 = new QVBoxLayout(ClinicDrugFilter);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        listWidget = new QListWidget(ClinicDrugFilter);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        verticalLayout->addWidget(listWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        okButton = new QPushButton(ClinicDrugFilter);
        okButton->setObjectName(QString::fromUtf8("okButton"));
        QFont font;
        font.setFamily(QString::fromUtf8("Agency FB"));
        font.setPointSize(12);
        okButton->setFont(font);

        horizontalLayout->addWidget(okButton);

        cancelButton = new QPushButton(ClinicDrugFilter);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setFont(font);

        horizontalLayout->addWidget(cancelButton);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(ClinicDrugFilter);

        QMetaObject::connectSlotsByName(ClinicDrugFilter);
    } // setupUi

    void retranslateUi(QDialog *ClinicDrugFilter)
    {
        ClinicDrugFilter->setWindowTitle(QApplication::translate("ClinicDrugFilter", "\350\215\257\345\223\201", 0, QApplication::UnicodeUTF8));
        okButton->setText(QApplication::translate("ClinicDrugFilter", "\347\241\256\345\256\232", 0, QApplication::UnicodeUTF8));
        cancelButton->setText(QApplication::translate("ClinicDrugFilter", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ClinicDrugFilter: public Ui_ClinicDrugFilter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLINICDRUGFILTER_H
