/********************************************************************************
** Form generated from reading UI file 'drugstorage.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DRUGSTORAGE_H
#define UI_DRUGSTORAGE_H

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

class Ui_DrugStorage
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
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QRadioButton *radioButton_Add;
    QRadioButton *radioButton_Minus;
    QLabel *label;
    QLineEdit *lineEdit_No;
    QLabel *label_5;
    QDateTimeEdit *dateTimeEdit;
    QLabel *label_8;
    QComboBox *comboBox_supplier;
    QSpacerItem *horizontalSpacer;
    QTableWidget *tableWidget;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_14;
    QLineEdit *lineEdit_Payable;
    QLabel *label_15;
    QLineEdit *lineEdit_Paid;
    QLabel *label_17;
    QLineEdit *lineEdit_debt;
    QLabel *label_16;
    QLineEdit *lineEdit_2;

    void setupUi(QWidget *DrugStorage)
    {
        if (DrugStorage->objectName().isEmpty())
            DrugStorage->setObjectName(QString::fromUtf8("DrugStorage"));
        DrugStorage->resize(874, 447);
        verticalLayout = new QVBoxLayout(DrugStorage);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        addButton = new QPushButton(DrugStorage);
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

        addRowButton = new QPushButton(DrugStorage);
        addRowButton->setObjectName(QString::fromUtf8("addRowButton"));
        sizePolicy.setHeightForWidth(addRowButton->sizePolicy().hasHeightForWidth());
        addRowButton->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setPointSize(12);
        addRowButton->setFont(font1);

        horizontalLayout_2->addWidget(addRowButton);

        deleteRowButton = new QPushButton(DrugStorage);
        deleteRowButton->setObjectName(QString::fromUtf8("deleteRowButton"));
        sizePolicy.setHeightForWidth(deleteRowButton->sizePolicy().hasHeightForWidth());
        deleteRowButton->setSizePolicy(sizePolicy);
        deleteRowButton->setFont(font1);

        horizontalLayout_2->addWidget(deleteRowButton);

        saveButton = new QPushButton(DrugStorage);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));
        sizePolicy.setHeightForWidth(saveButton->sizePolicy().hasHeightForWidth());
        saveButton->setSizePolicy(sizePolicy);
        saveButton->setFont(font);

        horizontalLayout_2->addWidget(saveButton);

        discardButton = new QPushButton(DrugStorage);
        discardButton->setObjectName(QString::fromUtf8("discardButton"));
        sizePolicy.setHeightForWidth(discardButton->sizePolicy().hasHeightForWidth());
        discardButton->setSizePolicy(sizePolicy);
        discardButton->setFont(font);

        horizontalLayout_2->addWidget(discardButton);

        editButton = new QPushButton(DrugStorage);
        editButton->setObjectName(QString::fromUtf8("editButton"));
        sizePolicy.setHeightForWidth(editButton->sizePolicy().hasHeightForWidth());
        editButton->setSizePolicy(sizePolicy);
        editButton->setFont(font);

        horizontalLayout_2->addWidget(editButton);

        deleteButton = new QPushButton(DrugStorage);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));
        sizePolicy.setHeightForWidth(deleteButton->sizePolicy().hasHeightForWidth());
        deleteButton->setSizePolicy(sizePolicy);
        deleteButton->setFont(font);

        horizontalLayout_2->addWidget(deleteButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        radioButton_Add = new QRadioButton(DrugStorage);
        radioButton_Add->setObjectName(QString::fromUtf8("radioButton_Add"));
        radioButton_Add->setChecked(true);

        horizontalLayout->addWidget(radioButton_Add);

        radioButton_Minus = new QRadioButton(DrugStorage);
        radioButton_Minus->setObjectName(QString::fromUtf8("radioButton_Minus"));

        horizontalLayout->addWidget(radioButton_Minus);

        label = new QLabel(DrugStorage);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lineEdit_No = new QLineEdit(DrugStorage);
        lineEdit_No->setObjectName(QString::fromUtf8("lineEdit_No"));
        lineEdit_No->setMaximumSize(QSize(80, 16777215));

        horizontalLayout->addWidget(lineEdit_No);

        label_5 = new QLabel(DrugStorage);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout->addWidget(label_5);

        dateTimeEdit = new QDateTimeEdit(DrugStorage);
        dateTimeEdit->setObjectName(QString::fromUtf8("dateTimeEdit"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(dateTimeEdit->sizePolicy().hasHeightForWidth());
        dateTimeEdit->setSizePolicy(sizePolicy1);
        dateTimeEdit->setMaximumSize(QSize(180, 16777215));

        horizontalLayout->addWidget(dateTimeEdit);

        label_8 = new QLabel(DrugStorage);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout->addWidget(label_8);

        comboBox_supplier = new QComboBox(DrugStorage);
        comboBox_supplier->setObjectName(QString::fromUtf8("comboBox_supplier"));
        sizePolicy1.setHeightForWidth(comboBox_supplier->sizePolicy().hasHeightForWidth());
        comboBox_supplier->setSizePolicy(sizePolicy1);
        comboBox_supplier->setMaximumSize(QSize(100, 16777215));

        horizontalLayout->addWidget(comboBox_supplier);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        tableWidget = new QTableWidget(DrugStorage);
        if (tableWidget->columnCount() < 11)
            tableWidget->setColumnCount(11);
        QFont font2;
        font2.setPointSize(9);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font2);
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

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_14 = new QLabel(DrugStorage);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        horizontalLayout_4->addWidget(label_14);

        lineEdit_Payable = new QLineEdit(DrugStorage);
        lineEdit_Payable->setObjectName(QString::fromUtf8("lineEdit_Payable"));
        sizePolicy.setHeightForWidth(lineEdit_Payable->sizePolicy().hasHeightForWidth());
        lineEdit_Payable->setSizePolicy(sizePolicy);
        lineEdit_Payable->setMaximumSize(QSize(80, 16777215));

        horizontalLayout_4->addWidget(lineEdit_Payable);

        label_15 = new QLabel(DrugStorage);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        horizontalLayout_4->addWidget(label_15);

        lineEdit_Paid = new QLineEdit(DrugStorage);
        lineEdit_Paid->setObjectName(QString::fromUtf8("lineEdit_Paid"));
        sizePolicy.setHeightForWidth(lineEdit_Paid->sizePolicy().hasHeightForWidth());
        lineEdit_Paid->setSizePolicy(sizePolicy);
        lineEdit_Paid->setMaximumSize(QSize(80, 16777215));

        horizontalLayout_4->addWidget(lineEdit_Paid);

        label_17 = new QLabel(DrugStorage);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        horizontalLayout_4->addWidget(label_17);

        lineEdit_debt = new QLineEdit(DrugStorage);
        lineEdit_debt->setObjectName(QString::fromUtf8("lineEdit_debt"));
        lineEdit_debt->setMaximumSize(QSize(80, 16777215));

        horizontalLayout_4->addWidget(lineEdit_debt);

        label_16 = new QLabel(DrugStorage);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        horizontalLayout_4->addWidget(label_16);

        lineEdit_2 = new QLineEdit(DrugStorage);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        horizontalLayout_4->addWidget(lineEdit_2);


        verticalLayout->addLayout(horizontalLayout_4);


        retranslateUi(DrugStorage);

        QMetaObject::connectSlotsByName(DrugStorage);
    } // setupUi

    void retranslateUi(QWidget *DrugStorage)
    {
        DrugStorage->setWindowTitle(QApplication::translate("DrugStorage", "\350\215\257\345\223\201\345\205\245\345\272\223", 0, QApplication::UnicodeUTF8));
        addButton->setText(QApplication::translate("DrugStorage", "\346\226\260\345\242\236", 0, QApplication::UnicodeUTF8));
        addRowButton->setText(QApplication::translate("DrugStorage", "\345\242\236\350\241\214", 0, QApplication::UnicodeUTF8));
        deleteRowButton->setText(QApplication::translate("DrugStorage", "\345\210\240\350\241\214", 0, QApplication::UnicodeUTF8));
        saveButton->setText(QApplication::translate("DrugStorage", "\344\277\235\345\255\230", 0, QApplication::UnicodeUTF8));
        discardButton->setText(QApplication::translate("DrugStorage", "\346\224\276\345\274\203", 0, QApplication::UnicodeUTF8));
        editButton->setText(QApplication::translate("DrugStorage", "\344\277\256\346\224\271", 0, QApplication::UnicodeUTF8));
        deleteButton->setText(QApplication::translate("DrugStorage", "\345\210\240\351\231\244", 0, QApplication::UnicodeUTF8));
        radioButton_Add->setText(QApplication::translate("DrugStorage", "\345\205\245\345\272\223", 0, QApplication::UnicodeUTF8));
        radioButton_Minus->setText(QApplication::translate("DrugStorage", "\351\200\200\350\264\247", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("DrugStorage", "\345\215\225\345\217\267\357\274\232", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("DrugStorage", "\345\205\245\345\272\223\346\227\245\346\234\237\357\274\232", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("DrugStorage", "\344\276\233\345\272\224\345\225\206\357\274\232", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("DrugStorage", "\347\274\226\347\240\201", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("DrugStorage", "\345\220\215\347\247\260", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("DrugStorage", "\350\247\204\346\240\274", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("DrugStorage", "\347\224\237\344\272\247\345\216\202\345\225\206", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("DrugStorage", "\346\211\271\345\217\267", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("DrugStorage", "\345\215\225\344\275\215", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("DrugStorage", "\345\205\245\345\272\223\346\225\260\351\207\217", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QApplication::translate("DrugStorage", "\345\272\223\345\255\230\346\200\273\351\207\217", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QApplication::translate("DrugStorage", "\345\205\245\345\272\223\344\273\267\346\240\274", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->horizontalHeaderItem(9);
        ___qtablewidgetitem9->setText(QApplication::translate("DrugStorage", "\346\200\273\344\273\267", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget->horizontalHeaderItem(10);
        ___qtablewidgetitem10->setText(QApplication::translate("DrugStorage", "\350\215\257\345\223\201\347\261\273\345\210\253", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem11->setText(QApplication::translate("DrugStorage", "1", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("DrugStorage", "\346\234\254\346\254\241\345\272\224\344\273\230\357\274\232", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("DrugStorage", "\345\256\236\351\231\205\344\273\230\346\254\276\357\274\232", 0, QApplication::UnicodeUTF8));
        lineEdit_Paid->setText(QString());
        label_17->setText(QApplication::translate("DrugStorage", "\346\254\240\346\254\276\347\264\257\350\256\241\357\274\232", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("DrugStorage", "\345\244\207\346\263\250\357\274\232", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DrugStorage: public Ui_DrugStorage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DRUGSTORAGE_H
