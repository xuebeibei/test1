/********************************************************************************
** Form generated from reading UI file 'pharmacystatistics.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PHARMACYSTATISTICS_H
#define UI_PHARMACYSTATISTICS_H

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

class Ui_PharmacyStatistics
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
    QLineEdit *lineEdit_DrugNo;
    QPushButton *findButton;
    QTableWidget *tableWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_5;
    QLineEdit *lineEdit_TotalNum;
    QLabel *label_6;
    QLineEdit *lineEdit_TotalPrice;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *printButton;
    QPushButton *previewButton;
    QPushButton *excelButton;

    void setupUi(QWidget *PharmacyStatistics)
    {
        if (PharmacyStatistics->objectName().isEmpty())
            PharmacyStatistics->setObjectName(QString::fromUtf8("PharmacyStatistics"));
        PharmacyStatistics->resize(855, 422);
        verticalLayout = new QVBoxLayout(PharmacyStatistics);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_9 = new QLabel(PharmacyStatistics);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(label_9);

        comboBox_find = new QComboBox(PharmacyStatistics);
        comboBox_find->setObjectName(QString::fromUtf8("comboBox_find"));
        comboBox_find->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(comboBox_find->sizePolicy().hasHeightForWidth());
        comboBox_find->setSizePolicy(sizePolicy1);
        comboBox_find->setMaximumSize(QSize(100, 16777215));

        horizontalLayout->addWidget(comboBox_find);

        label = new QLabel(PharmacyStatistics);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        dateTimeEdit_1 = new QDateTimeEdit(PharmacyStatistics);
        dateTimeEdit_1->setObjectName(QString::fromUtf8("dateTimeEdit_1"));
        dateTimeEdit_1->setMaximumSize(QSize(180, 16777215));

        horizontalLayout->addWidget(dateTimeEdit_1);

        label_2 = new QLabel(PharmacyStatistics);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        dateTimeEdit_2 = new QDateTimeEdit(PharmacyStatistics);
        dateTimeEdit_2->setObjectName(QString::fromUtf8("dateTimeEdit_2"));
        dateTimeEdit_2->setMaximumSize(QSize(180, 16777215));

        horizontalLayout->addWidget(dateTimeEdit_2);

        radioButton = new QRadioButton(PharmacyStatistics);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));

        horizontalLayout->addWidget(radioButton);

        lineEdit_DrugNo = new QLineEdit(PharmacyStatistics);
        lineEdit_DrugNo->setObjectName(QString::fromUtf8("lineEdit_DrugNo"));
        sizePolicy1.setHeightForWidth(lineEdit_DrugNo->sizePolicy().hasHeightForWidth());
        lineEdit_DrugNo->setSizePolicy(sizePolicy1);
        lineEdit_DrugNo->setMaximumSize(QSize(100, 16777215));

        horizontalLayout->addWidget(lineEdit_DrugNo);

        findButton = new QPushButton(PharmacyStatistics);
        findButton->setObjectName(QString::fromUtf8("findButton"));

        horizontalLayout->addWidget(findButton);


        verticalLayout->addLayout(horizontalLayout);

        tableWidget = new QTableWidget(PharmacyStatistics);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));

        verticalLayout->addWidget(tableWidget);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_5 = new QLabel(PharmacyStatistics);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_2->addWidget(label_5);

        lineEdit_TotalNum = new QLineEdit(PharmacyStatistics);
        lineEdit_TotalNum->setObjectName(QString::fromUtf8("lineEdit_TotalNum"));
        lineEdit_TotalNum->setMaximumSize(QSize(60, 16777215));

        horizontalLayout_2->addWidget(lineEdit_TotalNum);

        label_6 = new QLabel(PharmacyStatistics);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_2->addWidget(label_6);

        lineEdit_TotalPrice = new QLineEdit(PharmacyStatistics);
        lineEdit_TotalPrice->setObjectName(QString::fromUtf8("lineEdit_TotalPrice"));
        lineEdit_TotalPrice->setMaximumSize(QSize(60, 16777215));

        horizontalLayout_2->addWidget(lineEdit_TotalPrice);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        printButton = new QPushButton(PharmacyStatistics);
        printButton->setObjectName(QString::fromUtf8("printButton"));
        QFont font;
        font.setFamily(QString::fromUtf8("Agency FB"));
        font.setPointSize(12);
        printButton->setFont(font);

        horizontalLayout_2->addWidget(printButton);

        previewButton = new QPushButton(PharmacyStatistics);
        previewButton->setObjectName(QString::fromUtf8("previewButton"));
        previewButton->setFont(font);

        horizontalLayout_2->addWidget(previewButton);

        excelButton = new QPushButton(PharmacyStatistics);
        excelButton->setObjectName(QString::fromUtf8("excelButton"));
        excelButton->setFont(font);

        horizontalLayout_2->addWidget(excelButton);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(PharmacyStatistics);

        QMetaObject::connectSlotsByName(PharmacyStatistics);
    } // setupUi

    void retranslateUi(QWidget *PharmacyStatistics)
    {
        PharmacyStatistics->setWindowTitle(QApplication::translate("PharmacyStatistics", "PharmacyStatistics", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("PharmacyStatistics", "\346\237\245\350\257\242\345\206\205\345\256\271\357\274\232", 0, QApplication::UnicodeUTF8));
        comboBox_find->clear();
        comboBox_find->insertItems(0, QStringList()
         << QApplication::translate("PharmacyStatistics", "\346\224\266\350\264\247\350\256\260\345\275\225", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PharmacyStatistics", "\351\200\200\350\264\247\350\256\260\345\275\225", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PharmacyStatistics", "\347\233\230\347\202\271\350\256\260\345\275\225", 0, QApplication::UnicodeUTF8)
        );
        label->setText(QApplication::translate("PharmacyStatistics", "\346\227\245\346\234\237\350\214\203\345\233\264\357\274\232", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("PharmacyStatistics", "-", 0, QApplication::UnicodeUTF8));
        radioButton->setText(QApplication::translate("PharmacyStatistics", "\351\200\211\345\256\232\350\215\257\345\223\201", 0, QApplication::UnicodeUTF8));
        findButton->setText(QApplication::translate("PharmacyStatistics", "\346\237\245\350\257\242", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("PharmacyStatistics", "\346\200\273\346\225\260\351\207\217\357\274\232", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("PharmacyStatistics", "\346\200\273\351\207\221\351\242\235\357\274\232", 0, QApplication::UnicodeUTF8));
        printButton->setText(QApplication::translate("PharmacyStatistics", "\346\211\223\345\215\260", 0, QApplication::UnicodeUTF8));
        previewButton->setText(QApplication::translate("PharmacyStatistics", "\351\242\204\350\247\210", 0, QApplication::UnicodeUTF8));
        excelButton->setText(QApplication::translate("PharmacyStatistics", "\345\257\274\345\207\272excel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class PharmacyStatistics: public Ui_PharmacyStatistics {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PHARMACYSTATISTICS_H
