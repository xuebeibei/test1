/********************************************************************************
** Form generated from reading UI file 'cooperativedictionary.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COOPERATIVEDICTIONARY_H
#define UI_COOPERATIVEDICTIONARY_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Cooperativedictionary
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QPushButton *getNoButton;

    void setupUi(QWidget *Cooperativedictionary)
    {
        if (Cooperativedictionary->objectName().isEmpty())
            Cooperativedictionary->setObjectName(QString::fromUtf8("Cooperativedictionary"));
        Cooperativedictionary->resize(218, 104);
        verticalLayout = new QVBoxLayout(Cooperativedictionary);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(Cooperativedictionary);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(Cooperativedictionary);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout->addWidget(lineEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(Cooperativedictionary);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        lineEdit_2 = new QLineEdit(Cooperativedictionary);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        horizontalLayout_2->addWidget(lineEdit_2);


        verticalLayout->addLayout(horizontalLayout_2);

        getNoButton = new QPushButton(Cooperativedictionary);
        getNoButton->setObjectName(QString::fromUtf8("getNoButton"));

        verticalLayout->addWidget(getNoButton);


        retranslateUi(Cooperativedictionary);

        QMetaObject::connectSlotsByName(Cooperativedictionary);
    } // setupUi

    void retranslateUi(QWidget *Cooperativedictionary)
    {
        Cooperativedictionary->setWindowTitle(QApplication::translate("Cooperativedictionary", "\350\216\267\345\217\226\345\206\234\345\220\210\347\240\201", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Cooperativedictionary", "\345\206\234\345\220\210\344\273\243\347\240\201\357\274\232", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Cooperativedictionary", "\345\220\215\347\247\260    \357\274\232", 0, QApplication::UnicodeUTF8));
        getNoButton->setText(QApplication::translate("Cooperativedictionary", "\345\217\226\345\217\267", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Cooperativedictionary: public Ui_Cooperativedictionary {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COOPERATIVEDICTIONARY_H
