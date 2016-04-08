/********************************************************************************
** Form generated from reading UI file 'hospitalisationdailyreport.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOSPITALISATIONDAILYREPORT_H
#define UI_HOSPITALISATIONDAILYREPORT_H

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

class Ui_Hospitalisationdailyreport
{
public:
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_15;
    QPushButton *addButton;
    QPushButton *dailyreportqueryButton;
    QPushButton *saveButton;
    QPushButton *discardButton;
    QPushButton *editButton;
    QPushButton *deleteButton;
    QPushButton *printButton;
    QPushButton *previewButton;
    QSpacerItem *horizontalSpacer_7;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label_9;
    QLabel *label_12;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *sheetNoEdit;
    QDateTimeEdit *startdateTimeEdit;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_10;
    QLabel *label_13;
    QVBoxLayout *verticalLayout_4;
    QDateTimeEdit *makedateTimeEdit;
    QDateTimeEdit *endateTimeEdit;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_11;
    QLabel *label_14;
    QVBoxLayout *verticalLayout_6;
    QLineEdit *casherEdit;
    QLineEdit *lineEdit_8;
    QSpacerItem *horizontalSpacer;
    QTableWidget *dailyreporttableWidget;
    QHBoxLayout *horizontalLayout_10;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label_8;
    QLineEdit *sheetmakerEdit;

    void setupUi(QWidget *Hospitalisationdailyreport)
    {
        if (Hospitalisationdailyreport->objectName().isEmpty())
            Hospitalisationdailyreport->setObjectName(QString::fromUtf8("Hospitalisationdailyreport"));
        Hospitalisationdailyreport->resize(668, 550);
        verticalLayout_7 = new QVBoxLayout(Hospitalisationdailyreport);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setSpacing(6);
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        addButton = new QPushButton(Hospitalisationdailyreport);
        addButton->setObjectName(QString::fromUtf8("addButton"));
        QFont font;
        font.setFamily(QString::fromUtf8("Agency FB"));
        font.setPointSize(12);
        addButton->setFont(font);

        horizontalLayout_15->addWidget(addButton);

        dailyreportqueryButton = new QPushButton(Hospitalisationdailyreport);
        dailyreportqueryButton->setObjectName(QString::fromUtf8("dailyreportqueryButton"));
        dailyreportqueryButton->setFont(font);

        horizontalLayout_15->addWidget(dailyreportqueryButton);

        saveButton = new QPushButton(Hospitalisationdailyreport);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));
        saveButton->setFont(font);

        horizontalLayout_15->addWidget(saveButton);

        discardButton = new QPushButton(Hospitalisationdailyreport);
        discardButton->setObjectName(QString::fromUtf8("discardButton"));
        discardButton->setFont(font);

        horizontalLayout_15->addWidget(discardButton);

        editButton = new QPushButton(Hospitalisationdailyreport);
        editButton->setObjectName(QString::fromUtf8("editButton"));
        editButton->setFont(font);

        horizontalLayout_15->addWidget(editButton);

        deleteButton = new QPushButton(Hospitalisationdailyreport);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));
        deleteButton->setFont(font);

        horizontalLayout_15->addWidget(deleteButton);

        printButton = new QPushButton(Hospitalisationdailyreport);
        printButton->setObjectName(QString::fromUtf8("printButton"));
        printButton->setFont(font);

        horizontalLayout_15->addWidget(printButton);

        previewButton = new QPushButton(Hospitalisationdailyreport);
        previewButton->setObjectName(QString::fromUtf8("previewButton"));
        previewButton->setFont(font);

        horizontalLayout_15->addWidget(previewButton);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_15->addItem(horizontalSpacer_7);


        verticalLayout_7->addLayout(horizontalLayout_15);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_9 = new QLabel(Hospitalisationdailyreport);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        verticalLayout->addWidget(label_9);

        label_12 = new QLabel(Hospitalisationdailyreport);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        verticalLayout->addWidget(label_12);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        sheetNoEdit = new QLineEdit(Hospitalisationdailyreport);
        sheetNoEdit->setObjectName(QString::fromUtf8("sheetNoEdit"));
        sheetNoEdit->setMaximumSize(QSize(160, 16777215));

        verticalLayout_2->addWidget(sheetNoEdit);

        startdateTimeEdit = new QDateTimeEdit(Hospitalisationdailyreport);
        startdateTimeEdit->setObjectName(QString::fromUtf8("startdateTimeEdit"));
        startdateTimeEdit->setMaximumSize(QSize(160, 16777215));

        verticalLayout_2->addWidget(startdateTimeEdit);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_10 = new QLabel(Hospitalisationdailyreport);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        verticalLayout_3->addWidget(label_10);

        label_13 = new QLabel(Hospitalisationdailyreport);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        verticalLayout_3->addWidget(label_13);


        horizontalLayout->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        makedateTimeEdit = new QDateTimeEdit(Hospitalisationdailyreport);
        makedateTimeEdit->setObjectName(QString::fromUtf8("makedateTimeEdit"));
        makedateTimeEdit->setMaximumSize(QSize(160, 16777215));

        verticalLayout_4->addWidget(makedateTimeEdit);

        endateTimeEdit = new QDateTimeEdit(Hospitalisationdailyreport);
        endateTimeEdit->setObjectName(QString::fromUtf8("endateTimeEdit"));
        endateTimeEdit->setMaximumSize(QSize(160, 16777215));

        verticalLayout_4->addWidget(endateTimeEdit);


        horizontalLayout->addLayout(verticalLayout_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        label_11 = new QLabel(Hospitalisationdailyreport);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        verticalLayout_5->addWidget(label_11);

        label_14 = new QLabel(Hospitalisationdailyreport);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        verticalLayout_5->addWidget(label_14);


        horizontalLayout->addLayout(verticalLayout_5);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        casherEdit = new QLineEdit(Hospitalisationdailyreport);
        casherEdit->setObjectName(QString::fromUtf8("casherEdit"));
        casherEdit->setMaximumSize(QSize(160, 16777215));

        verticalLayout_6->addWidget(casherEdit);

        lineEdit_8 = new QLineEdit(Hospitalisationdailyreport);
        lineEdit_8->setObjectName(QString::fromUtf8("lineEdit_8"));
        lineEdit_8->setMaximumSize(QSize(160, 16777215));

        verticalLayout_6->addWidget(lineEdit_8);


        horizontalLayout->addLayout(verticalLayout_6);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout_7->addLayout(horizontalLayout);

        dailyreporttableWidget = new QTableWidget(Hospitalisationdailyreport);
        if (dailyreporttableWidget->columnCount() < 4)
            dailyreporttableWidget->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        dailyreporttableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        dailyreporttableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        dailyreporttableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        dailyreporttableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        dailyreporttableWidget->setObjectName(QString::fromUtf8("dailyreporttableWidget"));

        verticalLayout_7->addWidget(dailyreporttableWidget);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_5);

        label_8 = new QLabel(Hospitalisationdailyreport);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_10->addWidget(label_8);

        sheetmakerEdit = new QLineEdit(Hospitalisationdailyreport);
        sheetmakerEdit->setObjectName(QString::fromUtf8("sheetmakerEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(sheetmakerEdit->sizePolicy().hasHeightForWidth());
        sheetmakerEdit->setSizePolicy(sizePolicy);

        horizontalLayout_10->addWidget(sheetmakerEdit);


        verticalLayout_7->addLayout(horizontalLayout_10);


        retranslateUi(Hospitalisationdailyreport);

        QMetaObject::connectSlotsByName(Hospitalisationdailyreport);
    } // setupUi

    void retranslateUi(QWidget *Hospitalisationdailyreport)
    {
        Hospitalisationdailyreport->setWindowTitle(QApplication::translate("Hospitalisationdailyreport", "Hospitalisationdailyreport", 0, QApplication::UnicodeUTF8));
        addButton->setText(QApplication::translate("Hospitalisationdailyreport", "\346\226\260\345\242\236", 0, QApplication::UnicodeUTF8));
        dailyreportqueryButton->setText(QApplication::translate("Hospitalisationdailyreport", "\346\237\245\350\257\242", 0, QApplication::UnicodeUTF8));
        saveButton->setText(QApplication::translate("Hospitalisationdailyreport", "\344\277\235\345\255\230", 0, QApplication::UnicodeUTF8));
        discardButton->setText(QApplication::translate("Hospitalisationdailyreport", "\346\224\276\345\274\203", 0, QApplication::UnicodeUTF8));
        editButton->setText(QApplication::translate("Hospitalisationdailyreport", "\344\277\256\346\224\271", 0, QApplication::UnicodeUTF8));
        deleteButton->setText(QApplication::translate("Hospitalisationdailyreport", "\345\210\240\351\231\244", 0, QApplication::UnicodeUTF8));
        printButton->setText(QApplication::translate("Hospitalisationdailyreport", "\346\211\223\345\215\260", 0, QApplication::UnicodeUTF8));
        previewButton->setText(QApplication::translate("Hospitalisationdailyreport", "\351\242\204\350\247\210", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("Hospitalisationdailyreport", "\345\215\225\345\217\267\357\274\232", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("Hospitalisationdailyreport", "\350\265\267\345\247\213\346\227\245\346\234\237\357\274\232", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("Hospitalisationdailyreport", "\345\210\266\345\215\225\346\227\245\346\234\237\357\274\232", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("Hospitalisationdailyreport", "\347\273\223\346\235\237\346\227\245\346\234\237\357\274\232", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("Hospitalisationdailyreport", "\346\224\266\350\264\271\345\221\230\357\274\232", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("Hospitalisationdailyreport", "\345\215\225\346\215\256\347\261\273\345\236\213\357\274\232", 0, QApplication::UnicodeUTF8));
        lineEdit_8->setText(QApplication::translate("Hospitalisationdailyreport", "\344\275\217\351\231\242\346\227\245\347\273\223", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = dailyreporttableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("Hospitalisationdailyreport", "\345\215\225\345\217\267", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = dailyreporttableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("Hospitalisationdailyreport", "\345\274\200\347\245\250\346\227\245\346\234\237", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = dailyreporttableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("Hospitalisationdailyreport", "\345\272\224\346\224\266\351\207\221\351\242\235", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = dailyreporttableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("Hospitalisationdailyreport", "\346\224\266\350\264\271\345\221\230", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("Hospitalisationdailyreport", "\345\210\266\345\215\225\357\274\232", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Hospitalisationdailyreport: public Ui_Hospitalisationdailyreport {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOSPITALISATIONDAILYREPORT_H
