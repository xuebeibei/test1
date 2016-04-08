/********************************************************************************
** Form generated from reading UI file 'pharmacycheck.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PHARMACYCHECK_H
#define UI_PHARMACYCHECK_H

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

class Ui_PharmacyCheck
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *addButton;
    QPushButton *addRowButton;
    QPushButton *deleteRowButton;
    QPushButton *saveButton;
    QPushButton *discardButton;
    QPushButton *editButton;
    QPushButton *deleteButton;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit_CheckNo;
    QLabel *label_5;
    QDateTimeEdit *dateTimeEdit;
    QSpacerItem *horizontalSpacer_2;
    QTableWidget *tableWidget;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_14;
    QLineEdit *lineEdit_PreProfit;
    QLabel *label_15;
    QLineEdit *lineEdit_CurProfit;
    QLabel *label_17;
    QLineEdit *lineEdit_AftProfit;
    QLabel *label_16;
    QLineEdit *lineEdit_Remark;

    void setupUi(QWidget *PharmacyCheck)
    {
        if (PharmacyCheck->objectName().isEmpty())
            PharmacyCheck->setObjectName(QString::fromUtf8("PharmacyCheck"));
        PharmacyCheck->resize(749, 481);
        verticalLayout = new QVBoxLayout(PharmacyCheck);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        addButton = new QPushButton(PharmacyCheck);
        addButton->setObjectName(QString::fromUtf8("addButton"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(addButton->sizePolicy().hasHeightForWidth());
        addButton->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QString::fromUtf8("Agency FB"));
        font.setPointSize(12);
        addButton->setFont(font);

        horizontalLayout_2->addWidget(addButton);

        addRowButton = new QPushButton(PharmacyCheck);
        addRowButton->setObjectName(QString::fromUtf8("addRowButton"));
        sizePolicy.setHeightForWidth(addRowButton->sizePolicy().hasHeightForWidth());
        addRowButton->setSizePolicy(sizePolicy);
        addRowButton->setFont(font);

        horizontalLayout_2->addWidget(addRowButton);

        deleteRowButton = new QPushButton(PharmacyCheck);
        deleteRowButton->setObjectName(QString::fromUtf8("deleteRowButton"));
        sizePolicy.setHeightForWidth(deleteRowButton->sizePolicy().hasHeightForWidth());
        deleteRowButton->setSizePolicy(sizePolicy);
        deleteRowButton->setFont(font);

        horizontalLayout_2->addWidget(deleteRowButton);

        saveButton = new QPushButton(PharmacyCheck);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));
        sizePolicy.setHeightForWidth(saveButton->sizePolicy().hasHeightForWidth());
        saveButton->setSizePolicy(sizePolicy);
        saveButton->setFont(font);

        horizontalLayout_2->addWidget(saveButton);

        discardButton = new QPushButton(PharmacyCheck);
        discardButton->setObjectName(QString::fromUtf8("discardButton"));
        sizePolicy.setHeightForWidth(discardButton->sizePolicy().hasHeightForWidth());
        discardButton->setSizePolicy(sizePolicy);
        discardButton->setFont(font);

        horizontalLayout_2->addWidget(discardButton);

        editButton = new QPushButton(PharmacyCheck);
        editButton->setObjectName(QString::fromUtf8("editButton"));
        sizePolicy.setHeightForWidth(editButton->sizePolicy().hasHeightForWidth());
        editButton->setSizePolicy(sizePolicy);
        editButton->setFont(font);

        horizontalLayout_2->addWidget(editButton);

        deleteButton = new QPushButton(PharmacyCheck);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));
        sizePolicy.setHeightForWidth(deleteButton->sizePolicy().hasHeightForWidth());
        deleteButton->setSizePolicy(sizePolicy);
        deleteButton->setFont(font);

        horizontalLayout_2->addWidget(deleteButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(PharmacyCheck);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lineEdit_CheckNo = new QLineEdit(PharmacyCheck);
        lineEdit_CheckNo->setObjectName(QString::fromUtf8("lineEdit_CheckNo"));
        lineEdit_CheckNo->setMaximumSize(QSize(60, 16777215));

        horizontalLayout->addWidget(lineEdit_CheckNo);

        label_5 = new QLabel(PharmacyCheck);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout->addWidget(label_5);

        dateTimeEdit = new QDateTimeEdit(PharmacyCheck);
        dateTimeEdit->setObjectName(QString::fromUtf8("dateTimeEdit"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(dateTimeEdit->sizePolicy().hasHeightForWidth());
        dateTimeEdit->setSizePolicy(sizePolicy1);
        dateTimeEdit->setMaximumSize(QSize(180, 16777215));

        horizontalLayout->addWidget(dateTimeEdit);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        tableWidget = new QTableWidget(PharmacyCheck);
        if (tableWidget->columnCount() < 11)
            tableWidget->setColumnCount(11);
        QFont font1;
        font1.setPointSize(9);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font1);
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(9, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(10, __qtablewidgetitem10);
        if (tableWidget->rowCount() < 1)
            tableWidget->setRowCount(1);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem11);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setSortingEnabled(true);
        tableWidget->verticalHeader()->setProperty("showSortIndicator", QVariant(false));
        tableWidget->verticalHeader()->setStretchLastSection(false);

        verticalLayout->addWidget(tableWidget);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_14 = new QLabel(PharmacyCheck);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        horizontalLayout_3->addWidget(label_14);

        lineEdit_PreProfit = new QLineEdit(PharmacyCheck);
        lineEdit_PreProfit->setObjectName(QString::fromUtf8("lineEdit_PreProfit"));
        sizePolicy1.setHeightForWidth(lineEdit_PreProfit->sizePolicy().hasHeightForWidth());
        lineEdit_PreProfit->setSizePolicy(sizePolicy1);
        lineEdit_PreProfit->setMaximumSize(QSize(60, 16777215));

        horizontalLayout_3->addWidget(lineEdit_PreProfit);

        label_15 = new QLabel(PharmacyCheck);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        horizontalLayout_3->addWidget(label_15);

        lineEdit_CurProfit = new QLineEdit(PharmacyCheck);
        lineEdit_CurProfit->setObjectName(QString::fromUtf8("lineEdit_CurProfit"));
        sizePolicy1.setHeightForWidth(lineEdit_CurProfit->sizePolicy().hasHeightForWidth());
        lineEdit_CurProfit->setSizePolicy(sizePolicy1);
        lineEdit_CurProfit->setMaximumSize(QSize(60, 16777215));

        horizontalLayout_3->addWidget(lineEdit_CurProfit);

        label_17 = new QLabel(PharmacyCheck);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        horizontalLayout_3->addWidget(label_17);

        lineEdit_AftProfit = new QLineEdit(PharmacyCheck);
        lineEdit_AftProfit->setObjectName(QString::fromUtf8("lineEdit_AftProfit"));
        lineEdit_AftProfit->setMaximumSize(QSize(60, 16777215));

        horizontalLayout_3->addWidget(lineEdit_AftProfit);

        label_16 = new QLabel(PharmacyCheck);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        horizontalLayout_3->addWidget(label_16);

        lineEdit_Remark = new QLineEdit(PharmacyCheck);
        lineEdit_Remark->setObjectName(QString::fromUtf8("lineEdit_Remark"));

        horizontalLayout_3->addWidget(lineEdit_Remark);


        verticalLayout->addLayout(horizontalLayout_3);


        retranslateUi(PharmacyCheck);

        QMetaObject::connectSlotsByName(PharmacyCheck);
    } // setupUi

    void retranslateUi(QWidget *PharmacyCheck)
    {
        PharmacyCheck->setWindowTitle(QApplication::translate("PharmacyCheck", "\350\215\257\345\223\201\347\233\230\347\202\271", 0, QApplication::UnicodeUTF8));
        addButton->setText(QApplication::translate("PharmacyCheck", "\346\226\260\345\273\272", 0, QApplication::UnicodeUTF8));
        addRowButton->setText(QApplication::translate("PharmacyCheck", "\345\242\236\350\241\214", 0, QApplication::UnicodeUTF8));
        deleteRowButton->setText(QApplication::translate("PharmacyCheck", "\345\210\240\350\241\214", 0, QApplication::UnicodeUTF8));
        saveButton->setText(QApplication::translate("PharmacyCheck", "\344\277\235\345\255\230", 0, QApplication::UnicodeUTF8));
        discardButton->setText(QApplication::translate("PharmacyCheck", "\346\224\276\345\274\203", 0, QApplication::UnicodeUTF8));
        editButton->setText(QApplication::translate("PharmacyCheck", "\344\277\256\346\224\271", 0, QApplication::UnicodeUTF8));
        deleteButton->setText(QApplication::translate("PharmacyCheck", "\345\210\240\351\231\244", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("PharmacyCheck", "\347\233\230\347\202\271\345\215\225\345\217\267\357\274\232", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("PharmacyCheck", "\347\233\230\347\202\271\346\227\245\346\234\237\357\274\232", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("PharmacyCheck", "\347\274\226\347\240\201", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("PharmacyCheck", "\345\220\215\347\247\260", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("PharmacyCheck", "\350\247\204\346\240\274", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("PharmacyCheck", "\347\224\237\344\272\247\345\216\202\345\225\206", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("PharmacyCheck", "\346\211\271\345\217\267", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("PharmacyCheck", "\345\215\225\344\275\215", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("PharmacyCheck", "\350\264\246\351\235\242\346\225\260\351\207\217", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QApplication::translate("PharmacyCheck", "\347\233\230\347\202\271\346\225\260\351\207\217", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QApplication::translate("PharmacyCheck", "\347\233\210\344\272\217\346\225\260\351\207\217", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->horizontalHeaderItem(9);
        ___qtablewidgetitem9->setText(QApplication::translate("PharmacyCheck", "\351\233\266\345\224\256\345\215\225\344\273\267", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget->horizontalHeaderItem(10);
        ___qtablewidgetitem10->setText(QApplication::translate("PharmacyCheck", "\346\215\237\347\233\212\351\207\221\351\242\235", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem11->setText(QApplication::translate("PharmacyCheck", "1", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("PharmacyCheck", "\347\233\230\347\202\271\345\211\215\346\215\237\347\233\212\357\274\232", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("PharmacyCheck", "\346\234\254\346\254\241\347\233\230\347\202\271\346\215\237\347\233\212\357\274\232", 0, QApplication::UnicodeUTF8));
        lineEdit_CurProfit->setText(QString());
        label_17->setText(QApplication::translate("PharmacyCheck", "\347\233\230\347\202\271\345\220\216\346\215\237\347\233\212\357\274\232", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("PharmacyCheck", "\345\244\207\346\263\250\357\274\232", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class PharmacyCheck: public Ui_PharmacyCheck {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PHARMACYCHECK_H
