/********************************************************************************
** Form generated from reading UI file 'hospitalisationpay.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOSPITALISATIONPAY_H
#define UI_HOSPITALISATIONPAY_H

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
#include <QtGui/QSpacerItem>
#include <QtGui/QTableWidget>
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HospitalisationPay
{
public:
    QVBoxLayout *verticalLayout_11;
    QHBoxLayout *horizontalLayout_14;
    QPushButton *addButton;
    QPushButton *discardButton;
    QPushButton *editButton;
    QPushButton *deleteButton;
    QPushButton *saveButton;
    QPushButton *printButton;
    QPushButton *previewButton;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_6;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *sheetNoEdit;
    QLineEdit *bedEdit;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_2;
    QLabel *label_7;
    QVBoxLayout *verticalLayout_4;
    QDateTimeEdit *dateTimeEdit;
    QComboBox *chargemethodcomboBox;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_3;
    QLabel *label_8;
    QVBoxLayout *verticalLayout_6;
    QComboBox *hospitalNocomboBox;
    QLineEdit *amountEdit;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_4;
    QLabel *label_9;
    QVBoxLayout *verticalLayout_8;
    QLineEdit *nameEdit;
    QLineEdit *lineEdit_6;
    QVBoxLayout *verticalLayout_9;
    QLabel *label_5;
    QLabel *label_12;
    QVBoxLayout *verticalLayout_10;
    QLineEdit *registrydateEdit;
    QLineEdit *payerEdit;
    QTextEdit *remarkEdit;
    QLabel *label_10;
    QTableWidget *tableWidget;
    QHBoxLayout *horizontalLayout_13;
    QSpacerItem *horizontalSpacer;
    QLabel *label_11;
    QLineEdit *sheetmakerEdit;

    void setupUi(QWidget *HospitalisationPay)
    {
        if (HospitalisationPay->objectName().isEmpty())
            HospitalisationPay->setObjectName(QString::fromUtf8("HospitalisationPay"));
        HospitalisationPay->resize(962, 520);
        verticalLayout_11 = new QVBoxLayout(HospitalisationPay);
        verticalLayout_11->setSpacing(6);
        verticalLayout_11->setContentsMargins(11, 11, 11, 11);
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        addButton = new QPushButton(HospitalisationPay);
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

        horizontalLayout_14->addWidget(addButton);

        discardButton = new QPushButton(HospitalisationPay);
        discardButton->setObjectName(QString::fromUtf8("discardButton"));
        sizePolicy.setHeightForWidth(discardButton->sizePolicy().hasHeightForWidth());
        discardButton->setSizePolicy(sizePolicy);
        discardButton->setFont(font);

        horizontalLayout_14->addWidget(discardButton);

        editButton = new QPushButton(HospitalisationPay);
        editButton->setObjectName(QString::fromUtf8("editButton"));
        sizePolicy.setHeightForWidth(editButton->sizePolicy().hasHeightForWidth());
        editButton->setSizePolicy(sizePolicy);
        editButton->setFont(font);

        horizontalLayout_14->addWidget(editButton);

        deleteButton = new QPushButton(HospitalisationPay);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));
        sizePolicy.setHeightForWidth(deleteButton->sizePolicy().hasHeightForWidth());
        deleteButton->setSizePolicy(sizePolicy);
        deleteButton->setFont(font);

        horizontalLayout_14->addWidget(deleteButton);

        saveButton = new QPushButton(HospitalisationPay);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));
        sizePolicy.setHeightForWidth(saveButton->sizePolicy().hasHeightForWidth());
        saveButton->setSizePolicy(sizePolicy);
        saveButton->setFont(font);

        horizontalLayout_14->addWidget(saveButton);

        printButton = new QPushButton(HospitalisationPay);
        printButton->setObjectName(QString::fromUtf8("printButton"));
        sizePolicy.setHeightForWidth(printButton->sizePolicy().hasHeightForWidth());
        printButton->setSizePolicy(sizePolicy);
        printButton->setFont(font);

        horizontalLayout_14->addWidget(printButton);

        previewButton = new QPushButton(HospitalisationPay);
        previewButton->setObjectName(QString::fromUtf8("previewButton"));
        sizePolicy.setHeightForWidth(previewButton->sizePolicy().hasHeightForWidth());
        previewButton->setSizePolicy(sizePolicy);
        previewButton->setFont(font);

        horizontalLayout_14->addWidget(previewButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer_2);


        verticalLayout_11->addLayout(horizontalLayout_14);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(HospitalisationPay);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        label_6 = new QLabel(HospitalisationPay);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout->addWidget(label_6);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        sheetNoEdit = new QLineEdit(HospitalisationPay);
        sheetNoEdit->setObjectName(QString::fromUtf8("sheetNoEdit"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(sheetNoEdit->sizePolicy().hasHeightForWidth());
        sheetNoEdit->setSizePolicy(sizePolicy1);

        verticalLayout_2->addWidget(sheetNoEdit);

        bedEdit = new QLineEdit(HospitalisationPay);
        bedEdit->setObjectName(QString::fromUtf8("bedEdit"));

        verticalLayout_2->addWidget(bedEdit);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_2 = new QLabel(HospitalisationPay);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_3->addWidget(label_2);

        label_7 = new QLabel(HospitalisationPay);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        verticalLayout_3->addWidget(label_7);


        horizontalLayout->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        dateTimeEdit = new QDateTimeEdit(HospitalisationPay);
        dateTimeEdit->setObjectName(QString::fromUtf8("dateTimeEdit"));
        sizePolicy.setHeightForWidth(dateTimeEdit->sizePolicy().hasHeightForWidth());
        dateTimeEdit->setSizePolicy(sizePolicy);

        verticalLayout_4->addWidget(dateTimeEdit);

        chargemethodcomboBox = new QComboBox(HospitalisationPay);
        chargemethodcomboBox->setObjectName(QString::fromUtf8("chargemethodcomboBox"));
        sizePolicy1.setHeightForWidth(chargemethodcomboBox->sizePolicy().hasHeightForWidth());
        chargemethodcomboBox->setSizePolicy(sizePolicy1);

        verticalLayout_4->addWidget(chargemethodcomboBox);


        horizontalLayout->addLayout(verticalLayout_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        label_3 = new QLabel(HospitalisationPay);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy2);

        verticalLayout_5->addWidget(label_3);

        label_8 = new QLabel(HospitalisationPay);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        verticalLayout_5->addWidget(label_8);


        horizontalLayout->addLayout(verticalLayout_5);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        hospitalNocomboBox = new QComboBox(HospitalisationPay);
        hospitalNocomboBox->setObjectName(QString::fromUtf8("hospitalNocomboBox"));
        sizePolicy1.setHeightForWidth(hospitalNocomboBox->sizePolicy().hasHeightForWidth());
        hospitalNocomboBox->setSizePolicy(sizePolicy1);

        verticalLayout_6->addWidget(hospitalNocomboBox);

        amountEdit = new QLineEdit(HospitalisationPay);
        amountEdit->setObjectName(QString::fromUtf8("amountEdit"));

        verticalLayout_6->addWidget(amountEdit);


        horizontalLayout->addLayout(verticalLayout_6);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        label_4 = new QLabel(HospitalisationPay);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_7->addWidget(label_4);

        label_9 = new QLabel(HospitalisationPay);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        verticalLayout_7->addWidget(label_9);


        horizontalLayout->addLayout(verticalLayout_7);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        nameEdit = new QLineEdit(HospitalisationPay);
        nameEdit->setObjectName(QString::fromUtf8("nameEdit"));

        verticalLayout_8->addWidget(nameEdit);

        lineEdit_6 = new QLineEdit(HospitalisationPay);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));

        verticalLayout_8->addWidget(lineEdit_6);


        horizontalLayout->addLayout(verticalLayout_8);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        label_5 = new QLabel(HospitalisationPay);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout_9->addWidget(label_5);

        label_12 = new QLabel(HospitalisationPay);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        verticalLayout_9->addWidget(label_12);


        horizontalLayout->addLayout(verticalLayout_9);

        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        registrydateEdit = new QLineEdit(HospitalisationPay);
        registrydateEdit->setObjectName(QString::fromUtf8("registrydateEdit"));

        verticalLayout_10->addWidget(registrydateEdit);

        payerEdit = new QLineEdit(HospitalisationPay);
        payerEdit->setObjectName(QString::fromUtf8("payerEdit"));

        verticalLayout_10->addWidget(payerEdit);


        horizontalLayout->addLayout(verticalLayout_10);


        verticalLayout_11->addLayout(horizontalLayout);

        remarkEdit = new QTextEdit(HospitalisationPay);
        remarkEdit->setObjectName(QString::fromUtf8("remarkEdit"));
        remarkEdit->setFont(font);

        verticalLayout_11->addWidget(remarkEdit);

        label_10 = new QLabel(HospitalisationPay);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        sizePolicy2.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy2);

        verticalLayout_11->addWidget(label_10);

        tableWidget = new QTableWidget(HospitalisationPay);
        if (tableWidget->columnCount() < 6)
            tableWidget->setColumnCount(6);
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
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));

        verticalLayout_11->addWidget(tableWidget);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer);

        label_11 = new QLabel(HospitalisationPay);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        horizontalLayout_13->addWidget(label_11);

        sheetmakerEdit = new QLineEdit(HospitalisationPay);
        sheetmakerEdit->setObjectName(QString::fromUtf8("sheetmakerEdit"));
        sizePolicy.setHeightForWidth(sheetmakerEdit->sizePolicy().hasHeightForWidth());
        sheetmakerEdit->setSizePolicy(sizePolicy);

        horizontalLayout_13->addWidget(sheetmakerEdit);


        verticalLayout_11->addLayout(horizontalLayout_13);

        amountEdit->raise();
        label_8->raise();
        nameEdit->raise();

        retranslateUi(HospitalisationPay);

        QMetaObject::connectSlotsByName(HospitalisationPay);
    } // setupUi

    void retranslateUi(QWidget *HospitalisationPay)
    {
        HospitalisationPay->setWindowTitle(QApplication::translate("HospitalisationPay", "\344\275\217\351\231\242\344\272\244\346\212\274\351\207\221", 0, QApplication::UnicodeUTF8));
        addButton->setText(QApplication::translate("HospitalisationPay", "\346\226\260\345\242\236", 0, QApplication::UnicodeUTF8));
        discardButton->setText(QApplication::translate("HospitalisationPay", "\346\224\276\345\274\203", 0, QApplication::UnicodeUTF8));
        editButton->setText(QApplication::translate("HospitalisationPay", "\344\277\256\346\224\271", 0, QApplication::UnicodeUTF8));
        deleteButton->setText(QApplication::translate("HospitalisationPay", "\345\210\240\351\231\244", 0, QApplication::UnicodeUTF8));
        saveButton->setText(QApplication::translate("HospitalisationPay", "\344\277\235\345\255\230", 0, QApplication::UnicodeUTF8));
        printButton->setText(QApplication::translate("HospitalisationPay", "\346\211\223\345\215\260", 0, QApplication::UnicodeUTF8));
        previewButton->setText(QApplication::translate("HospitalisationPay", "\351\242\204\350\247\210", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("HospitalisationPay", "\345\215\225\345\217\267\357\274\232", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("HospitalisationPay", "\345\272\212\344\275\215\357\274\232", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("HospitalisationPay", "\346\224\266\350\264\271\346\227\245\346\234\237\357\274\232", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("HospitalisationPay", "\346\224\266\350\264\271\346\226\271\345\274\217\357\274\232", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("HospitalisationPay", "\344\275\217\351\231\242\345\217\267\357\274\232", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("HospitalisationPay", "\351\207\221\351\242\235\357\274\232", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("HospitalisationPay", "\345\247\223\345\220\215\357\274\232", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("HospitalisationPay", "\347\245\250\345\217\267\357\274\232", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("HospitalisationPay", "\344\275\217\351\231\242\346\227\245\346\234\237\357\274\232", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("HospitalisationPay", "\344\272\244\346\254\276\344\272\272\357\274\232", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("HospitalisationPay", "\344\272\244\346\254\276\350\256\260\345\275\225\357\274\232", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("HospitalisationPay", "\345\215\225\345\217\267", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("HospitalisationPay", "\346\227\245\346\234\237", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("HospitalisationPay", "\351\207\221\351\242\235", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("HospitalisationPay", "\347\245\250\345\217\267", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("HospitalisationPay", "\345\244\207\346\263\250", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("HospitalisationPay", "\345\210\266\345\215\225", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("HospitalisationPay", "\345\210\266\345\215\225\357\274\232", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class HospitalisationPay: public Ui_HospitalisationPay {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOSPITALISATIONPAY_H
