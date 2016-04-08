/********************************************************************************
** Form generated from reading UI file 'departmentadd.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEPARTMENTADD_H
#define UI_DEPARTMENTADD_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Departmentadd
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *lineEdit_4;
    QPushButton *cancelButton;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QWidget *layoutWidget_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *okButton;
    QWidget *layoutWidget_4;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *lineEdit_3;
    QWidget *layoutWidget_5;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QLineEdit *lineEdit_5;

    void setupUi(QWidget *Departmentadd)
    {
        if (Departmentadd->objectName().isEmpty())
            Departmentadd->setObjectName(QString::fromUtf8("Departmentadd"));
        Departmentadd->resize(232, 191);
        layoutWidget = new QWidget(Departmentadd);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 98, 201, 22));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_4->addWidget(label_4);

        lineEdit_4 = new QLineEdit(layoutWidget);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));

        horizontalLayout_4->addWidget(lineEdit_4);

        cancelButton = new QPushButton(Departmentadd);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setGeometry(QRect(140, 160, 75, 23));
        layoutWidget_2 = new QWidget(Departmentadd);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(10, 42, 201, 22));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        lineEdit_2 = new QLineEdit(layoutWidget_2);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        horizontalLayout_2->addWidget(lineEdit_2);

        layoutWidget_3 = new QWidget(Departmentadd);
        layoutWidget_3->setObjectName(QString::fromUtf8("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(10, 14, 201, 22));
        horizontalLayout = new QHBoxLayout(layoutWidget_3);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget_3);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(layoutWidget_3);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout->addWidget(lineEdit);

        okButton = new QPushButton(Departmentadd);
        okButton->setObjectName(QString::fromUtf8("okButton"));
        okButton->setGeometry(QRect(59, 160, 75, 23));
        layoutWidget_4 = new QWidget(Departmentadd);
        layoutWidget_4->setObjectName(QString::fromUtf8("layoutWidget_4"));
        layoutWidget_4->setGeometry(QRect(10, 70, 201, 22));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget_4);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget_4);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        lineEdit_3 = new QLineEdit(layoutWidget_4);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));

        horizontalLayout_3->addWidget(lineEdit_3);

        layoutWidget_5 = new QWidget(Departmentadd);
        layoutWidget_5->setObjectName(QString::fromUtf8("layoutWidget_5"));
        layoutWidget_5->setGeometry(QRect(10, 130, 201, 22));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget_5);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(layoutWidget_5);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_5->addWidget(label_5);

        lineEdit_5 = new QLineEdit(layoutWidget_5);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));

        horizontalLayout_5->addWidget(lineEdit_5);


        retranslateUi(Departmentadd);

        QMetaObject::connectSlotsByName(Departmentadd);
    } // setupUi

    void retranslateUi(QWidget *Departmentadd)
    {
        Departmentadd->setWindowTitle(QApplication::translate("Departmentadd", "\345\242\236\345\212\240", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Departmentadd", "\345\205\250\346\213\274\357\274\232  ", 0, QApplication::UnicodeUTF8));
        cancelButton->setText(QApplication::translate("Departmentadd", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Departmentadd", "\350\264\237\350\264\243\344\272\272\357\274\232", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Departmentadd", "\345\220\215\347\247\260\357\274\232  ", 0, QApplication::UnicodeUTF8));
        okButton->setText(QApplication::translate("Departmentadd", "\347\241\256\345\256\232", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Departmentadd", "\347\256\200\346\213\274\357\274\232  ", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("Departmentadd", "\347\274\226\347\240\201\357\274\232  ", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Departmentadd: public Ui_Departmentadd {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEPARTMENTADD_H
