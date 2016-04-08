/********************************************************************************
** Form generated from reading UI file 'drugstatistics.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DRUGSTATISTICS_H
#define UI_DRUGSTATISTICS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDateTimeEdit>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTableWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DrugStatistics
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_9;
    QComboBox *comboBox_find;
    QLabel *label;
    QDateTimeEdit *dateTimeEdit_1;
    QLabel *label_2;
    QDateTimeEdit *dateTimeEdit_2;
    QRadioButton *radioButton;
    QLineEdit *lineEdit_DrugName;
    QPushButton *findButton;
    QTableWidget *tableWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_5;
    QLineEdit *lineEdit_TotalNum;
    QLabel *label_6;
    QLineEdit *lineEdit_TotalPrice;
    QSpacerItem *horizontalSpacer;
    QPushButton *printButton;
    QPushButton *previewButton;
    QPushButton *excelButton;

    void setupUi(QWidget *DrugStatistics)
    {
        if (DrugStatistics->objectName().isEmpty())
            DrugStatistics->setObjectName(QString::fromUtf8("DrugStatistics"));
        DrugStatistics->resize(850, 422);
        verticalLayout = new QVBoxLayout(DrugStatistics);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_9 = new QLabel(DrugStatistics);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(label_9);

        comboBox_find = new QComboBox(DrugStatistics);
        comboBox_find->setObjectName(QString::fromUtf8("comboBox_find"));
        comboBox_find->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(comboBox_find->sizePolicy().hasHeightForWidth());
        comboBox_find->setSizePolicy(sizePolicy1);
        comboBox_find->setMaximumSize(QSize(80, 16777215));

        horizontalLayout->addWidget(comboBox_find);

        label = new QLabel(DrugStatistics);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        dateTimeEdit_1 = new QDateTimeEdit(DrugStatistics);
        dateTimeEdit_1->setObjectName(QString::fromUtf8("dateTimeEdit_1"));
        dateTimeEdit_1->setMaximumSize(QSize(180, 16777215));

        horizontalLayout->addWidget(dateTimeEdit_1);

        label_2 = new QLabel(DrugStatistics);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        dateTimeEdit_2 = new QDateTimeEdit(DrugStatistics);
        dateTimeEdit_2->setObjectName(QString::fromUtf8("dateTimeEdit_2"));
        dateTimeEdit_2->setMaximumSize(QSize(180, 16777215));

        horizontalLayout->addWidget(dateTimeEdit_2);

        radioButton = new QRadioButton(DrugStatistics);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));

        horizontalLayout->addWidget(radioButton);

        lineEdit_DrugName = new QLineEdit(DrugStatistics);
        lineEdit_DrugName->setObjectName(QString::fromUtf8("lineEdit_DrugName"));
        lineEdit_DrugName->setEnabled(false);

        horizontalLayout->addWidget(lineEdit_DrugName);

        findButton = new QPushButton(DrugStatistics);
        findButton->setObjectName(QString::fromUtf8("findButton"));

        horizontalLayout->addWidget(findButton);


        verticalLayout->addLayout(horizontalLayout);

        tableWidget = new QTableWidget(DrugStatistics);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));

        verticalLayout->addWidget(tableWidget);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_5 = new QLabel(DrugStatistics);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_2->addWidget(label_5);

        lineEdit_TotalNum = new QLineEdit(DrugStatistics);
        lineEdit_TotalNum->setObjectName(QString::fromUtf8("lineEdit_TotalNum"));
        lineEdit_TotalNum->setMaximumSize(QSize(60, 16777215));

        horizontalLayout_2->addWidget(lineEdit_TotalNum);

        label_6 = new QLabel(DrugStatistics);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_2->addWidget(label_6);

        lineEdit_TotalPrice = new QLineEdit(DrugStatistics);
        lineEdit_TotalPrice->setObjectName(QString::fromUtf8("lineEdit_TotalPrice"));
        lineEdit_TotalPrice->setMaximumSize(QSize(60, 16777215));

        horizontalLayout_2->addWidget(lineEdit_TotalPrice);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        printButton = new QPushButton(DrugStatistics);
        printButton->setObjectName(QString::fromUtf8("printButton"));

        horizontalLayout_2->addWidget(printButton);

        previewButton = new QPushButton(DrugStatistics);
        previewButton->setObjectName(QString::fromUtf8("previewButton"));

        horizontalLayout_2->addWidget(previewButton);

        excelButton = new QPushButton(DrugStatistics);
        excelButton->setObjectName(QString::fromUtf8("excelButton"));

        horizontalLayout_2->addWidget(excelButton);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(DrugStatistics);

        QMetaObject::connectSlotsByName(DrugStatistics);
    } // setupUi

    void retranslateUi(QWidget *DrugStatistics)
    {
        DrugStatistics->setWindowTitle(QApplication::translate("DrugStatistics", "DrugStatistics", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("DrugStatistics", "\346\237\245\350\257\242\345\206\205\345\256\271\357\274\232", 0, QApplication::UnicodeUTF8));
        comboBox_find->clear();
        comboBox_find->insertItems(0, QStringList()
         << QApplication::translate("DrugStatistics", "\345\205\245\345\272\223\350\256\260\345\275\225", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DrugStatistics", "\351\200\200\350\264\247\350\256\260\345\275\225", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DrugStatistics", "\351\224\200\345\224\256\350\260\203\346\213\250\350\256\260\345\275\225", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DrugStatistics", "\344\273\223\345\272\223\350\260\203\346\213\250\350\256\260\345\275\225", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DrugStatistics", "\350\260\203\344\273\267\350\256\260\345\275\225", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DrugStatistics", "\347\233\210\344\272\217\346\215\237\347\233\212", 0, QApplication::UnicodeUTF8)
        );
        label->setText(QApplication::translate("DrugStatistics", "\346\227\245\346\234\237\350\214\203\345\233\264\357\274\232", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("DrugStatistics", "-", 0, QApplication::UnicodeUTF8));
        radioButton->setText(QApplication::translate("DrugStatistics", "\351\200\211\345\256\232\350\215\257\345\223\201", 0, QApplication::UnicodeUTF8));
        findButton->setText(QApplication::translate("DrugStatistics", "\346\237\245\350\257\242", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("DrugStatistics", "\346\200\273\346\225\260\351\207\217\357\274\232", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("DrugStatistics", "\346\200\273\351\207\221\351\242\235\357\274\232", 0, QApplication::UnicodeUTF8));
        printButton->setText(QApplication::translate("DrugStatistics", "\346\211\223\345\215\260", 0, QApplication::UnicodeUTF8));
        previewButton->setText(QApplication::translate("DrugStatistics", "\351\242\204\350\247\210", 0, QApplication::UnicodeUTF8));
        excelButton->setText(QApplication::translate("DrugStatistics", "\345\257\274\345\207\272excel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DrugStatistics: public Ui_DrugStatistics {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DRUGSTATISTICS_H
