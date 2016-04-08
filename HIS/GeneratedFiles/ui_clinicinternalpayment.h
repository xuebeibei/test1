/********************************************************************************
** Form generated from reading UI file 'clinicinternalpayment.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLINICINTERNALPAYMENT_H
#define UI_CLINICINTERNALPAYMENT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDateTimeEdit>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTableWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ClinicInternalPayment
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *printButton;
    QPushButton *previewButton;
    QPushButton *excelButton;
    QPushButton *queryButton;
    QLabel *label_5;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QDateTimeEdit *dateTimeEdit;
    QLabel *label_2;
    QDateTimeEdit *dateTimeEdit_2;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_4;
    QTableWidget *tableWidget;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_4;

    void setupUi(QWidget *ClinicInternalPayment)
    {
        if (ClinicInternalPayment->objectName().isEmpty())
            ClinicInternalPayment->setObjectName(QString::fromUtf8("ClinicInternalPayment"));
        ClinicInternalPayment->resize(863, 570);
        verticalLayout_2 = new QVBoxLayout(ClinicInternalPayment);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        printButton = new QPushButton(ClinicInternalPayment);
        printButton->setObjectName(QString::fromUtf8("printButton"));
        QFont font;
        font.setFamily(QString::fromUtf8("Agency FB"));
        font.setPointSize(12);
        printButton->setFont(font);

        horizontalLayout->addWidget(printButton);

        previewButton = new QPushButton(ClinicInternalPayment);
        previewButton->setObjectName(QString::fromUtf8("previewButton"));
        previewButton->setFont(font);

        horizontalLayout->addWidget(previewButton);

        excelButton = new QPushButton(ClinicInternalPayment);
        excelButton->setObjectName(QString::fromUtf8("excelButton"));
        excelButton->setFont(font);

        horizontalLayout->addWidget(excelButton);

        queryButton = new QPushButton(ClinicInternalPayment);
        queryButton->setObjectName(QString::fromUtf8("queryButton"));
        queryButton->setFont(font);

        horizontalLayout->addWidget(queryButton);

        label_5 = new QLabel(ClinicInternalPayment);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(label_5);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(ClinicInternalPayment);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        dateTimeEdit = new QDateTimeEdit(ClinicInternalPayment);
        dateTimeEdit->setObjectName(QString::fromUtf8("dateTimeEdit"));

        horizontalLayout_2->addWidget(dateTimeEdit);

        label_2 = new QLabel(ClinicInternalPayment);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        dateTimeEdit_2 = new QDateTimeEdit(ClinicInternalPayment);
        dateTimeEdit_2->setObjectName(QString::fromUtf8("dateTimeEdit_2"));

        horizontalLayout_2->addWidget(dateTimeEdit_2);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        tableWidget = new QTableWidget(ClinicInternalPayment);
        if (tableWidget->columnCount() < 2)
            tableWidget->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        if (tableWidget->rowCount() < 14)
            tableWidget->setRowCount(14);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(1, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(2, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(3, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(4, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(5, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(6, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(7, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(8, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(9, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(10, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(11, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(12, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(13, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tableWidget->setItem(0, 0, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tableWidget->setItem(1, 0, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tableWidget->setItem(2, 0, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        tableWidget->setItem(3, 0, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        tableWidget->setItem(4, 0, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        tableWidget->setItem(5, 0, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        tableWidget->setItem(6, 0, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        tableWidget->setItem(7, 0, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        tableWidget->setItem(8, 0, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        tableWidget->setItem(9, 0, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        tableWidget->setItem(10, 0, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        tableWidget->setItem(11, 0, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        tableWidget->setItem(12, 0, __qtablewidgetitem28);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        tableWidget->setItem(13, 0, __qtablewidgetitem29);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setAutoFillBackground(true);
        tableWidget->setMidLineWidth(1);
        tableWidget->setShowGrid(true);
        tableWidget->setSortingEnabled(false);
        tableWidget->horizontalHeader()->setCascadingSectionResizes(true);
        tableWidget->horizontalHeader()->setStretchLastSection(false);
        tableWidget->verticalHeader()->setProperty("showSortIndicator", QVariant(true));
        tableWidget->verticalHeader()->setStretchLastSection(false);

        horizontalLayout_4->addWidget(tableWidget);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);

        label_4 = new QLabel(ClinicInternalPayment);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_4->addWidget(label_4);


        verticalLayout->addLayout(horizontalLayout_4);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(ClinicInternalPayment);

        QMetaObject::connectSlotsByName(ClinicInternalPayment);
    } // setupUi

    void retranslateUi(QWidget *ClinicInternalPayment)
    {
        ClinicInternalPayment->setWindowTitle(QApplication::translate("ClinicInternalPayment", "\351\227\250\350\257\212\345\206\205\351\203\250\347\274\264\346\254\276", 0, QApplication::UnicodeUTF8));
        printButton->setText(QApplication::translate("ClinicInternalPayment", "\346\211\223\345\215\260", 0, QApplication::UnicodeUTF8));
        previewButton->setText(QApplication::translate("ClinicInternalPayment", "\351\242\204\350\247\210", 0, QApplication::UnicodeUTF8));
        excelButton->setText(QApplication::translate("ClinicInternalPayment", "Excel", 0, QApplication::UnicodeUTF8));
        queryButton->setText(QApplication::translate("ClinicInternalPayment", "\346\237\245\350\257\242", 0, QApplication::UnicodeUTF8));
        label_5->setText(QString());
        label->setText(QApplication::translate("ClinicInternalPayment", "\346\227\245\346\234\237\357\274\232", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ClinicInternalPayment", "-", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("ClinicInternalPayment", "\345\220\215\347\247\260", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("ClinicInternalPayment", "\351\207\221\351\242\235", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem2->setText(QApplication::translate("ClinicInternalPayment", "1", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->verticalHeaderItem(1);
        ___qtablewidgetitem3->setText(QApplication::translate("ClinicInternalPayment", "2", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->verticalHeaderItem(2);
        ___qtablewidgetitem4->setText(QApplication::translate("ClinicInternalPayment", "3", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->verticalHeaderItem(3);
        ___qtablewidgetitem5->setText(QApplication::translate("ClinicInternalPayment", "4", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->verticalHeaderItem(4);
        ___qtablewidgetitem6->setText(QApplication::translate("ClinicInternalPayment", "5", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->verticalHeaderItem(5);
        ___qtablewidgetitem7->setText(QApplication::translate("ClinicInternalPayment", "6", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->verticalHeaderItem(6);
        ___qtablewidgetitem8->setText(QApplication::translate("ClinicInternalPayment", "7", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->verticalHeaderItem(7);
        ___qtablewidgetitem9->setText(QApplication::translate("ClinicInternalPayment", "8", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget->verticalHeaderItem(8);
        ___qtablewidgetitem10->setText(QApplication::translate("ClinicInternalPayment", "9", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget->verticalHeaderItem(9);
        ___qtablewidgetitem11->setText(QApplication::translate("ClinicInternalPayment", "10", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget->verticalHeaderItem(10);
        ___qtablewidgetitem12->setText(QApplication::translate("ClinicInternalPayment", "11", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget->verticalHeaderItem(11);
        ___qtablewidgetitem13->setText(QApplication::translate("ClinicInternalPayment", "12", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget->verticalHeaderItem(12);
        ___qtablewidgetitem14->setText(QApplication::translate("ClinicInternalPayment", "13", 0, QApplication::UnicodeUTF8));

        const bool __sortingEnabled = tableWidget->isSortingEnabled();
        tableWidget->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem15 = tableWidget->item(0, 0);
        ___qtablewidgetitem15->setText(QApplication::translate("ClinicInternalPayment", "\350\245\277\350\215\257\350\264\271", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem16 = tableWidget->item(1, 0);
        ___qtablewidgetitem16->setText(QApplication::translate("ClinicInternalPayment", "\344\270\255\346\210\220\350\215\257\350\264\271", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem17 = tableWidget->item(2, 0);
        ___qtablewidgetitem17->setText(QApplication::translate("ClinicInternalPayment", "\346\214\202\345\217\267\350\264\271A", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem18 = tableWidget->item(3, 0);
        ___qtablewidgetitem18->setText(QApplication::translate("ClinicInternalPayment", "\346\243\200\346\237\245\350\264\271D", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem19 = tableWidget->item(4, 0);
        ___qtablewidgetitem19->setText(QApplication::translate("ClinicInternalPayment", "\346\262\273\347\226\227\350\264\271E", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem20 = tableWidget->item(5, 0);
        ___qtablewidgetitem20->setText(QApplication::translate("ClinicInternalPayment", "\346\212\244\347\220\206\350\264\271F", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem21 = tableWidget->item(6, 0);
        ___qtablewidgetitem21->setText(QApplication::translate("ClinicInternalPayment", "\346\211\213\346\234\257\350\264\271G", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem22 = tableWidget->item(7, 0);
        ___qtablewidgetitem22->setText(QApplication::translate("ClinicInternalPayment", "\345\214\226\351\252\214\350\264\271H", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem23 = tableWidget->item(8, 0);
        ___qtablewidgetitem23->setText(QApplication::translate("ClinicInternalPayment", "\346\235\220\346\226\231\350\264\271", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem24 = tableWidget->item(9, 0);
        ___qtablewidgetitem24->setText(QApplication::translate("ClinicInternalPayment", "\350\257\212\346\237\245\350\264\271C", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem25 = tableWidget->item(10, 0);
        ___qtablewidgetitem25->setText(QApplication::translate("ClinicInternalPayment", "\345\205\266\344\273\226\350\264\271", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem26 = tableWidget->item(11, 0);
        ___qtablewidgetitem26->setText(QApplication::translate("ClinicInternalPayment", "\345\272\212\344\275\215\350\264\271", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem27 = tableWidget->item(12, 0);
        ___qtablewidgetitem27->setText(QApplication::translate("ClinicInternalPayment", "\344\270\200\350\210\254\350\257\212\347\226\227\350\264\271", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem28 = tableWidget->item(13, 0);
        ___qtablewidgetitem28->setText(QApplication::translate("ClinicInternalPayment", "\345\220\210\350\256\241", 0, QApplication::UnicodeUTF8));
        tableWidget->setSortingEnabled(__sortingEnabled);

        label_4->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ClinicInternalPayment: public Ui_ClinicInternalPayment {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLINICINTERNALPAYMENT_H
