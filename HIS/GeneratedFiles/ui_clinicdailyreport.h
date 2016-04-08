/********************************************************************************
** Form generated from reading UI file 'clinicdailyreport.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLINICDAILYREPORT_H
#define UI_CLINICDAILYREPORT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDateTimeEdit>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTableWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ClinicDailyReport
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_9;
    QPushButton *addButton;
    QPushButton *queryButton;
    QPushButton *saveButton;
    QPushButton *discardButton;
    QPushButton *editButton;
    QPushButton *deleteButton;
    QPushButton *printButton;
    QPushButton *previewButton;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_6;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *sheetNoEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QDateTimeEdit *makedateTimeEdit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QDateTimeEdit *startdateTimeEdit;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QDateTimeEdit *endateTimeEdit;
    QSpacerItem *horizontalSpacer_2;
    QTableWidget *tableWidget;
    QHBoxLayout *horizontalLayout_10;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_7;
    QLineEdit *sheetmakerEdit;

    void setupUi(QWidget *ClinicDailyReport)
    {
        if (ClinicDailyReport->objectName().isEmpty())
            ClinicDailyReport->setObjectName(QString::fromUtf8("ClinicDailyReport"));
        ClinicDailyReport->resize(805, 483);
        verticalLayout = new QVBoxLayout(ClinicDailyReport);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        addButton = new QPushButton(ClinicDailyReport);
        addButton->setObjectName(QString::fromUtf8("addButton"));
        QFont font;
        font.setFamily(QString::fromUtf8("Agency FB"));
        font.setPointSize(12);
        addButton->setFont(font);

        horizontalLayout_9->addWidget(addButton);

        queryButton = new QPushButton(ClinicDailyReport);
        queryButton->setObjectName(QString::fromUtf8("queryButton"));
        queryButton->setFont(font);

        horizontalLayout_9->addWidget(queryButton);

        saveButton = new QPushButton(ClinicDailyReport);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));
        saveButton->setFont(font);

        horizontalLayout_9->addWidget(saveButton);

        discardButton = new QPushButton(ClinicDailyReport);
        discardButton->setObjectName(QString::fromUtf8("discardButton"));
        discardButton->setFont(font);

        horizontalLayout_9->addWidget(discardButton);

        editButton = new QPushButton(ClinicDailyReport);
        editButton->setObjectName(QString::fromUtf8("editButton"));
        editButton->setFont(font);

        horizontalLayout_9->addWidget(editButton);

        deleteButton = new QPushButton(ClinicDailyReport);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));
        deleteButton->setFont(font);

        horizontalLayout_9->addWidget(deleteButton);

        printButton = new QPushButton(ClinicDailyReport);
        printButton->setObjectName(QString::fromUtf8("printButton"));
        printButton->setFont(font);

        horizontalLayout_9->addWidget(printButton);

        previewButton = new QPushButton(ClinicDailyReport);
        previewButton->setObjectName(QString::fromUtf8("previewButton"));
        previewButton->setFont(font);

        horizontalLayout_9->addWidget(previewButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_9);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(ClinicDailyReport);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMaximumSize(QSize(32, 16777215));

        horizontalLayout->addWidget(label);

        sheetNoEdit = new QLineEdit(ClinicDailyReport);
        sheetNoEdit->setObjectName(QString::fromUtf8("sheetNoEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(sheetNoEdit->sizePolicy().hasHeightForWidth());
        sheetNoEdit->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(sheetNoEdit);


        horizontalLayout_6->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(ClinicDailyReport);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMaximumSize(QSize(56, 16777215));

        horizontalLayout_2->addWidget(label_2);

        makedateTimeEdit = new QDateTimeEdit(ClinicDailyReport);
        makedateTimeEdit->setObjectName(QString::fromUtf8("makedateTimeEdit"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(makedateTimeEdit->sizePolicy().hasHeightForWidth());
        makedateTimeEdit->setSizePolicy(sizePolicy1);
        makedateTimeEdit->setMaximumSize(QSize(160, 16777215));

        horizontalLayout_2->addWidget(makedateTimeEdit);


        horizontalLayout_6->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(ClinicDailyReport);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMaximumSize(QSize(56, 16777215));

        horizontalLayout_3->addWidget(label_3);

        startdateTimeEdit = new QDateTimeEdit(ClinicDailyReport);
        startdateTimeEdit->setObjectName(QString::fromUtf8("startdateTimeEdit"));
        sizePolicy1.setHeightForWidth(startdateTimeEdit->sizePolicy().hasHeightForWidth());
        startdateTimeEdit->setSizePolicy(sizePolicy1);
        startdateTimeEdit->setMaximumSize(QSize(160, 16777215));

        horizontalLayout_3->addWidget(startdateTimeEdit);


        horizontalLayout_6->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_4 = new QLabel(ClinicDailyReport);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMaximumSize(QSize(56, 16777215));

        horizontalLayout_4->addWidget(label_4);

        endateTimeEdit = new QDateTimeEdit(ClinicDailyReport);
        endateTimeEdit->setObjectName(QString::fromUtf8("endateTimeEdit"));
        sizePolicy1.setHeightForWidth(endateTimeEdit->sizePolicy().hasHeightForWidth());
        endateTimeEdit->setSizePolicy(sizePolicy1);
        endateTimeEdit->setMaximumSize(QSize(160, 16777215));

        horizontalLayout_4->addWidget(endateTimeEdit);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);


        horizontalLayout_6->addLayout(horizontalLayout_4);


        verticalLayout->addLayout(horizontalLayout_6);

        tableWidget = new QTableWidget(ClinicDailyReport);
        if (tableWidget->columnCount() < 5)
            tableWidget->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));

        verticalLayout->addWidget(tableWidget);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_4);

        label_7 = new QLabel(ClinicDailyReport);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_10->addWidget(label_7);

        sheetmakerEdit = new QLineEdit(ClinicDailyReport);
        sheetmakerEdit->setObjectName(QString::fromUtf8("sheetmakerEdit"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(sheetmakerEdit->sizePolicy().hasHeightForWidth());
        sheetmakerEdit->setSizePolicy(sizePolicy2);

        horizontalLayout_10->addWidget(sheetmakerEdit);


        verticalLayout->addLayout(horizontalLayout_10);


        retranslateUi(ClinicDailyReport);

        QMetaObject::connectSlotsByName(ClinicDailyReport);
    } // setupUi

    void retranslateUi(QWidget *ClinicDailyReport)
    {
        ClinicDailyReport->setWindowTitle(QApplication::translate("ClinicDailyReport", "\351\227\250\350\257\212\346\227\245\347\273\223", 0, QApplication::UnicodeUTF8));
        addButton->setText(QApplication::translate("ClinicDailyReport", "\346\226\260\345\242\236", 0, QApplication::UnicodeUTF8));
        queryButton->setText(QApplication::translate("ClinicDailyReport", "\346\237\245\350\257\242", 0, QApplication::UnicodeUTF8));
        saveButton->setText(QApplication::translate("ClinicDailyReport", "\344\277\235\345\255\230", 0, QApplication::UnicodeUTF8));
        discardButton->setText(QApplication::translate("ClinicDailyReport", "\346\224\276\345\274\203", 0, QApplication::UnicodeUTF8));
        editButton->setText(QApplication::translate("ClinicDailyReport", "\344\277\256\346\224\271", 0, QApplication::UnicodeUTF8));
        deleteButton->setText(QApplication::translate("ClinicDailyReport", "\345\210\240\351\231\244", 0, QApplication::UnicodeUTF8));
        printButton->setText(QApplication::translate("ClinicDailyReport", "\346\211\223\345\215\260", 0, QApplication::UnicodeUTF8));
        previewButton->setText(QApplication::translate("ClinicDailyReport", "\351\242\204\350\247\210", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ClinicDailyReport", "\345\215\225\345\217\267\357\274\232", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ClinicDailyReport", "\345\210\266\345\215\225\346\227\245\346\234\237\357\274\232", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("ClinicDailyReport", "\350\265\267\345\247\213\346\227\245\346\234\237\357\274\232", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("ClinicDailyReport", "\347\273\223\346\235\237\346\227\245\346\234\237\357\274\232", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("ClinicDailyReport", "\345\215\225\345\217\267", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("ClinicDailyReport", "\345\274\200\347\245\250\346\227\245\346\234\237", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("ClinicDailyReport", "\345\272\224\346\224\266\351\207\221\351\242\235", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("ClinicDailyReport", "\345\256\236\346\224\266\351\207\221\351\242\235", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("ClinicDailyReport", "\346\254\240\346\254\276\351\207\221\351\242\235", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("ClinicDailyReport", "\345\210\266\345\215\225\357\274\232", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ClinicDailyReport: public Ui_ClinicDailyReport {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLINICDAILYREPORT_H
