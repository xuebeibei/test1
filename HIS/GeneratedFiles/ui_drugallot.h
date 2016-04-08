/********************************************************************************
** Form generated from reading UI file 'drugallot.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DRUGALLOT_H
#define UI_DRUGALLOT_H

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
#include <QtGui/QTabWidget>
#include <QtGui/QTableWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DrugAllot
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *addButton;
    QPushButton *addRowButton;
    QPushButton *deleteRowButton;
    QPushButton *saveButton;
    QPushButton *discardButton;
    QPushButton *editButton;
    QPushButton *deleteButton;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_4;
    QRadioButton *radioButton_Sellout;
    QRadioButton *radioButton_Back;
    QLabel *label;
    QLineEdit *lineEdit_SaleNo;
    QLabel *label_5;
    QDateTimeEdit *dateTimeEdit_Date_Sale;
    QLabel *label_9;
    QComboBox *comboBox_Customer;
    QSpacerItem *horizontalSpacer;
    QTableWidget *tableWidget_SaleAllot;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_14;
    QLineEdit *lineEdit_Payable;
    QLabel *label_15;
    QLineEdit *lineEdit_Paid;
    QLabel *label_17;
    QLineEdit *lineEdit_Debt;
    QLabel *label_16;
    QLineEdit *lineEdit_2;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QPushButton *addButton_2;
    QPushButton *addRowButton_2;
    QPushButton *deleteRowButton_2;
    QPushButton *saveButton_2;
    QPushButton *discardButton_2;
    QPushButton *editButton_2;
    QPushButton *deleteButton_2;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_5;
    QRadioButton *radioButton_ToYF;
    QRadioButton *radioButton_ToYK;
    QLabel *label_3;
    QLineEdit *lineEdit_StoreAllotNo;
    QLabel *label_7;
    QDateTimeEdit *dateTimeEdit_Date_Store;
    QSpacerItem *horizontalSpacer_4;
    QTableWidget *tableWidget_StoreAllot;
    QHBoxLayout *horizontalLayout_43;
    QHBoxLayout *horizontalLayout_44;
    QLabel *label_34;
    QLineEdit *lineEdit_Remark;

    void setupUi(QWidget *DrugAllot)
    {
        if (DrugAllot->objectName().isEmpty())
            DrugAllot->setObjectName(QString::fromUtf8("DrugAllot"));
        DrugAllot->resize(811, 453);
        verticalLayout = new QVBoxLayout(DrugAllot);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tabWidget = new QTabWidget(DrugAllot);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        verticalLayout_2 = new QVBoxLayout(tab);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        addButton = new QPushButton(tab);
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

        addRowButton = new QPushButton(tab);
        addRowButton->setObjectName(QString::fromUtf8("addRowButton"));
        sizePolicy.setHeightForWidth(addRowButton->sizePolicy().hasHeightForWidth());
        addRowButton->setSizePolicy(sizePolicy);
        addRowButton->setFont(font);

        horizontalLayout_2->addWidget(addRowButton);

        deleteRowButton = new QPushButton(tab);
        deleteRowButton->setObjectName(QString::fromUtf8("deleteRowButton"));
        sizePolicy.setHeightForWidth(deleteRowButton->sizePolicy().hasHeightForWidth());
        deleteRowButton->setSizePolicy(sizePolicy);
        deleteRowButton->setFont(font);

        horizontalLayout_2->addWidget(deleteRowButton);

        saveButton = new QPushButton(tab);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));
        sizePolicy.setHeightForWidth(saveButton->sizePolicy().hasHeightForWidth());
        saveButton->setSizePolicy(sizePolicy);
        saveButton->setFont(font);

        horizontalLayout_2->addWidget(saveButton);

        discardButton = new QPushButton(tab);
        discardButton->setObjectName(QString::fromUtf8("discardButton"));
        sizePolicy.setHeightForWidth(discardButton->sizePolicy().hasHeightForWidth());
        discardButton->setSizePolicy(sizePolicy);
        discardButton->setFont(font);

        horizontalLayout_2->addWidget(discardButton);

        editButton = new QPushButton(tab);
        editButton->setObjectName(QString::fromUtf8("editButton"));
        sizePolicy.setHeightForWidth(editButton->sizePolicy().hasHeightForWidth());
        editButton->setSizePolicy(sizePolicy);
        editButton->setFont(font);

        horizontalLayout_2->addWidget(editButton);

        deleteButton = new QPushButton(tab);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));
        sizePolicy.setHeightForWidth(deleteButton->sizePolicy().hasHeightForWidth());
        deleteButton->setSizePolicy(sizePolicy);
        deleteButton->setFont(font);

        horizontalLayout_2->addWidget(deleteButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        radioButton_Sellout = new QRadioButton(tab);
        radioButton_Sellout->setObjectName(QString::fromUtf8("radioButton_Sellout"));
        radioButton_Sellout->setChecked(true);

        horizontalLayout_4->addWidget(radioButton_Sellout);

        radioButton_Back = new QRadioButton(tab);
        radioButton_Back->setObjectName(QString::fromUtf8("radioButton_Back"));

        horizontalLayout_4->addWidget(radioButton_Back);

        label = new QLabel(tab);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_4->addWidget(label);

        lineEdit_SaleNo = new QLineEdit(tab);
        lineEdit_SaleNo->setObjectName(QString::fromUtf8("lineEdit_SaleNo"));
        lineEdit_SaleNo->setMaximumSize(QSize(80, 16777215));

        horizontalLayout_4->addWidget(lineEdit_SaleNo);

        label_5 = new QLabel(tab);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_4->addWidget(label_5);

        dateTimeEdit_Date_Sale = new QDateTimeEdit(tab);
        dateTimeEdit_Date_Sale->setObjectName(QString::fromUtf8("dateTimeEdit_Date_Sale"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(dateTimeEdit_Date_Sale->sizePolicy().hasHeightForWidth());
        dateTimeEdit_Date_Sale->setSizePolicy(sizePolicy1);
        dateTimeEdit_Date_Sale->setMaximumSize(QSize(180, 16777215));

        horizontalLayout_4->addWidget(dateTimeEdit_Date_Sale);

        label_9 = new QLabel(tab);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_4->addWidget(label_9);

        comboBox_Customer = new QComboBox(tab);
        comboBox_Customer->setObjectName(QString::fromUtf8("comboBox_Customer"));
        sizePolicy1.setHeightForWidth(comboBox_Customer->sizePolicy().hasHeightForWidth());
        comboBox_Customer->setSizePolicy(sizePolicy1);
        comboBox_Customer->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_4->addWidget(comboBox_Customer);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);


        verticalLayout_2->addLayout(horizontalLayout_4);

        tableWidget_SaleAllot = new QTableWidget(tab);
        if (tableWidget_SaleAllot->columnCount() < 11)
            tableWidget_SaleAllot->setColumnCount(11);
        QFont font1;
        font1.setPointSize(9);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font1);
        tableWidget_SaleAllot->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_SaleAllot->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget_SaleAllot->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget_SaleAllot->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget_SaleAllot->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget_SaleAllot->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget_SaleAllot->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget_SaleAllot->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget_SaleAllot->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget_SaleAllot->setHorizontalHeaderItem(9, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget_SaleAllot->setHorizontalHeaderItem(10, __qtablewidgetitem10);
        if (tableWidget_SaleAllot->rowCount() < 1)
            tableWidget_SaleAllot->setRowCount(1);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget_SaleAllot->setVerticalHeaderItem(0, __qtablewidgetitem11);
        tableWidget_SaleAllot->setObjectName(QString::fromUtf8("tableWidget_SaleAllot"));
        tableWidget_SaleAllot->setSortingEnabled(true);
        tableWidget_SaleAllot->verticalHeader()->setProperty("showSortIndicator", QVariant(false));
        tableWidget_SaleAllot->verticalHeader()->setStretchLastSection(false);

        verticalLayout_2->addWidget(tableWidget_SaleAllot);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_14 = new QLabel(tab);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        horizontalLayout_3->addWidget(label_14);

        lineEdit_Payable = new QLineEdit(tab);
        lineEdit_Payable->setObjectName(QString::fromUtf8("lineEdit_Payable"));
        sizePolicy1.setHeightForWidth(lineEdit_Payable->sizePolicy().hasHeightForWidth());
        lineEdit_Payable->setSizePolicy(sizePolicy1);
        lineEdit_Payable->setMaximumSize(QSize(80, 16777215));

        horizontalLayout_3->addWidget(lineEdit_Payable);

        label_15 = new QLabel(tab);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        horizontalLayout_3->addWidget(label_15);

        lineEdit_Paid = new QLineEdit(tab);
        lineEdit_Paid->setObjectName(QString::fromUtf8("lineEdit_Paid"));
        sizePolicy1.setHeightForWidth(lineEdit_Paid->sizePolicy().hasHeightForWidth());
        lineEdit_Paid->setSizePolicy(sizePolicy1);
        lineEdit_Paid->setMaximumSize(QSize(80, 16777215));

        horizontalLayout_3->addWidget(lineEdit_Paid);

        label_17 = new QLabel(tab);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        horizontalLayout_3->addWidget(label_17);

        lineEdit_Debt = new QLineEdit(tab);
        lineEdit_Debt->setObjectName(QString::fromUtf8("lineEdit_Debt"));
        lineEdit_Debt->setMaximumSize(QSize(80, 16777215));

        horizontalLayout_3->addWidget(lineEdit_Debt);

        label_16 = new QLabel(tab);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        horizontalLayout_3->addWidget(label_16);

        lineEdit_2 = new QLineEdit(tab);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        horizontalLayout_3->addWidget(lineEdit_2);


        verticalLayout_2->addLayout(horizontalLayout_3);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        verticalLayout_3 = new QVBoxLayout(tab_2);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        addButton_2 = new QPushButton(tab_2);
        addButton_2->setObjectName(QString::fromUtf8("addButton_2"));
        sizePolicy.setHeightForWidth(addButton_2->sizePolicy().hasHeightForWidth());
        addButton_2->setSizePolicy(sizePolicy);
        addButton_2->setFont(font);

        horizontalLayout->addWidget(addButton_2);

        addRowButton_2 = new QPushButton(tab_2);
        addRowButton_2->setObjectName(QString::fromUtf8("addRowButton_2"));
        sizePolicy.setHeightForWidth(addRowButton_2->sizePolicy().hasHeightForWidth());
        addRowButton_2->setSizePolicy(sizePolicy);
        addRowButton_2->setFont(font);

        horizontalLayout->addWidget(addRowButton_2);

        deleteRowButton_2 = new QPushButton(tab_2);
        deleteRowButton_2->setObjectName(QString::fromUtf8("deleteRowButton_2"));
        sizePolicy.setHeightForWidth(deleteRowButton_2->sizePolicy().hasHeightForWidth());
        deleteRowButton_2->setSizePolicy(sizePolicy);
        deleteRowButton_2->setFont(font);

        horizontalLayout->addWidget(deleteRowButton_2);

        saveButton_2 = new QPushButton(tab_2);
        saveButton_2->setObjectName(QString::fromUtf8("saveButton_2"));
        sizePolicy.setHeightForWidth(saveButton_2->sizePolicy().hasHeightForWidth());
        saveButton_2->setSizePolicy(sizePolicy);
        saveButton_2->setFont(font);

        horizontalLayout->addWidget(saveButton_2);

        discardButton_2 = new QPushButton(tab_2);
        discardButton_2->setObjectName(QString::fromUtf8("discardButton_2"));
        sizePolicy.setHeightForWidth(discardButton_2->sizePolicy().hasHeightForWidth());
        discardButton_2->setSizePolicy(sizePolicy);
        discardButton_2->setFont(font);

        horizontalLayout->addWidget(discardButton_2);

        editButton_2 = new QPushButton(tab_2);
        editButton_2->setObjectName(QString::fromUtf8("editButton_2"));
        sizePolicy.setHeightForWidth(editButton_2->sizePolicy().hasHeightForWidth());
        editButton_2->setSizePolicy(sizePolicy);
        editButton_2->setFont(font);

        horizontalLayout->addWidget(editButton_2);

        deleteButton_2 = new QPushButton(tab_2);
        deleteButton_2->setObjectName(QString::fromUtf8("deleteButton_2"));
        sizePolicy.setHeightForWidth(deleteButton_2->sizePolicy().hasHeightForWidth());
        deleteButton_2->setSizePolicy(sizePolicy);
        deleteButton_2->setFont(font);

        horizontalLayout->addWidget(deleteButton_2);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);


        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        radioButton_ToYF = new QRadioButton(tab_2);
        radioButton_ToYF->setObjectName(QString::fromUtf8("radioButton_ToYF"));
        radioButton_ToYF->setChecked(true);

        horizontalLayout_5->addWidget(radioButton_ToYF);

        radioButton_ToYK = new QRadioButton(tab_2);
        radioButton_ToYK->setObjectName(QString::fromUtf8("radioButton_ToYK"));

        horizontalLayout_5->addWidget(radioButton_ToYK);

        label_3 = new QLabel(tab_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_5->addWidget(label_3);

        lineEdit_StoreAllotNo = new QLineEdit(tab_2);
        lineEdit_StoreAllotNo->setObjectName(QString::fromUtf8("lineEdit_StoreAllotNo"));
        lineEdit_StoreAllotNo->setMaximumSize(QSize(80, 16777215));

        horizontalLayout_5->addWidget(lineEdit_StoreAllotNo);

        label_7 = new QLabel(tab_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_5->addWidget(label_7);

        dateTimeEdit_Date_Store = new QDateTimeEdit(tab_2);
        dateTimeEdit_Date_Store->setObjectName(QString::fromUtf8("dateTimeEdit_Date_Store"));
        sizePolicy1.setHeightForWidth(dateTimeEdit_Date_Store->sizePolicy().hasHeightForWidth());
        dateTimeEdit_Date_Store->setSizePolicy(sizePolicy1);
        dateTimeEdit_Date_Store->setMaximumSize(QSize(180, 16777215));

        horizontalLayout_5->addWidget(dateTimeEdit_Date_Store);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_4);


        verticalLayout_3->addLayout(horizontalLayout_5);

        tableWidget_StoreAllot = new QTableWidget(tab_2);
        if (tableWidget_StoreAllot->columnCount() < 12)
            tableWidget_StoreAllot->setColumnCount(12);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        __qtablewidgetitem12->setFont(font1);
        tableWidget_StoreAllot->setHorizontalHeaderItem(0, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget_StoreAllot->setHorizontalHeaderItem(1, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidget_StoreAllot->setHorizontalHeaderItem(2, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableWidget_StoreAllot->setHorizontalHeaderItem(3, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tableWidget_StoreAllot->setHorizontalHeaderItem(4, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tableWidget_StoreAllot->setHorizontalHeaderItem(5, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tableWidget_StoreAllot->setHorizontalHeaderItem(6, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        tableWidget_StoreAllot->setHorizontalHeaderItem(7, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        tableWidget_StoreAllot->setHorizontalHeaderItem(8, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        tableWidget_StoreAllot->setHorizontalHeaderItem(9, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        tableWidget_StoreAllot->setHorizontalHeaderItem(10, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        tableWidget_StoreAllot->setHorizontalHeaderItem(11, __qtablewidgetitem23);
        if (tableWidget_StoreAllot->rowCount() < 1)
            tableWidget_StoreAllot->setRowCount(1);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        tableWidget_StoreAllot->setVerticalHeaderItem(0, __qtablewidgetitem24);
        tableWidget_StoreAllot->setObjectName(QString::fromUtf8("tableWidget_StoreAllot"));
        tableWidget_StoreAllot->setSortingEnabled(true);
        tableWidget_StoreAllot->verticalHeader()->setProperty("showSortIndicator", QVariant(false));
        tableWidget_StoreAllot->verticalHeader()->setStretchLastSection(false);

        verticalLayout_3->addWidget(tableWidget_StoreAllot);

        horizontalLayout_43 = new QHBoxLayout();
        horizontalLayout_43->setSpacing(6);
        horizontalLayout_43->setObjectName(QString::fromUtf8("horizontalLayout_43"));
        horizontalLayout_44 = new QHBoxLayout();
        horizontalLayout_44->setSpacing(6);
        horizontalLayout_44->setObjectName(QString::fromUtf8("horizontalLayout_44"));
        label_34 = new QLabel(tab_2);
        label_34->setObjectName(QString::fromUtf8("label_34"));

        horizontalLayout_44->addWidget(label_34);

        lineEdit_Remark = new QLineEdit(tab_2);
        lineEdit_Remark->setObjectName(QString::fromUtf8("lineEdit_Remark"));

        horizontalLayout_44->addWidget(lineEdit_Remark);


        horizontalLayout_43->addLayout(horizontalLayout_44);


        verticalLayout_3->addLayout(horizontalLayout_43);

        tabWidget->addTab(tab_2, QString());

        verticalLayout->addWidget(tabWidget);


        retranslateUi(DrugAllot);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(DrugAllot);
    } // setupUi

    void retranslateUi(QWidget *DrugAllot)
    {
        DrugAllot->setWindowTitle(QApplication::translate("DrugAllot", "\350\215\257\345\223\201\350\260\203\346\213\250", 0, QApplication::UnicodeUTF8));
        addButton->setText(QApplication::translate("DrugAllot", "\346\226\260\345\242\236", 0, QApplication::UnicodeUTF8));
        addRowButton->setText(QApplication::translate("DrugAllot", "\345\242\236\350\241\214", 0, QApplication::UnicodeUTF8));
        deleteRowButton->setText(QApplication::translate("DrugAllot", "\345\210\240\350\241\214", 0, QApplication::UnicodeUTF8));
        saveButton->setText(QApplication::translate("DrugAllot", "\344\277\235\345\255\230", 0, QApplication::UnicodeUTF8));
        discardButton->setText(QApplication::translate("DrugAllot", "\346\224\276\345\274\203", 0, QApplication::UnicodeUTF8));
        editButton->setText(QApplication::translate("DrugAllot", "\344\277\256\346\224\271", 0, QApplication::UnicodeUTF8));
        deleteButton->setText(QApplication::translate("DrugAllot", "\345\210\240\351\231\244", 0, QApplication::UnicodeUTF8));
        radioButton_Sellout->setText(QApplication::translate("DrugAllot", "\345\224\256\345\207\272", 0, QApplication::UnicodeUTF8));
        radioButton_Back->setText(QApplication::translate("DrugAllot", "\351\200\200\350\264\247", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("DrugAllot", "\345\215\225\345\217\267\357\274\232", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("DrugAllot", "\346\217\220\350\264\247\346\227\245\346\234\237\357\274\232", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("DrugAllot", "\345\256\242\346\210\267\357\274\232", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_SaleAllot->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("DrugAllot", "\347\274\226\347\240\201", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_SaleAllot->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("DrugAllot", "\345\220\215\347\247\260", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_SaleAllot->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("DrugAllot", "\350\247\204\346\240\274", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_SaleAllot->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("DrugAllot", "\347\224\237\344\272\247\345\216\202\345\225\206", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget_SaleAllot->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("DrugAllot", "\346\211\271\345\217\267", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget_SaleAllot->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("DrugAllot", "\345\215\225\344\275\215", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget_SaleAllot->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("DrugAllot", "\350\260\203\346\213\250\346\225\260\351\207\217", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget_SaleAllot->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QApplication::translate("DrugAllot", "\345\272\223\345\255\230\346\200\273\351\207\217", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget_SaleAllot->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QApplication::translate("DrugAllot", "\345\205\245\345\272\223\344\273\267\346\240\274", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget_SaleAllot->horizontalHeaderItem(9);
        ___qtablewidgetitem9->setText(QApplication::translate("DrugAllot", "\346\200\273\344\273\267", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget_SaleAllot->horizontalHeaderItem(10);
        ___qtablewidgetitem10->setText(QApplication::translate("DrugAllot", "\350\215\257\345\223\201\347\261\273\345\210\253", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget_SaleAllot->verticalHeaderItem(0);
        ___qtablewidgetitem11->setText(QApplication::translate("DrugAllot", "1", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("DrugAllot", "\346\234\254\346\254\241\345\272\224\346\224\266\357\274\232", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("DrugAllot", "\345\256\236\351\231\205\346\224\266\345\217\226\357\274\232", 0, QApplication::UnicodeUTF8));
        lineEdit_Paid->setText(QString());
        label_17->setText(QApplication::translate("DrugAllot", "\345\267\256\344\273\267\345\220\210\350\256\241\357\274\232", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("DrugAllot", "\345\244\207\346\263\250\357\274\232", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("DrugAllot", "\351\224\200\345\224\256\350\260\203\346\213\250", 0, QApplication::UnicodeUTF8));
        addButton_2->setText(QApplication::translate("DrugAllot", "\346\226\260\345\242\236", 0, QApplication::UnicodeUTF8));
        addRowButton_2->setText(QApplication::translate("DrugAllot", "\345\242\236\350\241\214", 0, QApplication::UnicodeUTF8));
        deleteRowButton_2->setText(QApplication::translate("DrugAllot", "\345\210\240\350\241\214", 0, QApplication::UnicodeUTF8));
        saveButton_2->setText(QApplication::translate("DrugAllot", "\344\277\235\345\255\230", 0, QApplication::UnicodeUTF8));
        discardButton_2->setText(QApplication::translate("DrugAllot", "\346\224\276\345\274\203", 0, QApplication::UnicodeUTF8));
        editButton_2->setText(QApplication::translate("DrugAllot", "\344\277\256\346\224\271", 0, QApplication::UnicodeUTF8));
        deleteButton_2->setText(QApplication::translate("DrugAllot", "\345\210\240\351\231\244", 0, QApplication::UnicodeUTF8));
        radioButton_ToYF->setText(QApplication::translate("DrugAllot", "\350\215\257\345\272\223\342\200\224>\350\215\257\346\210\277", 0, QApplication::UnicodeUTF8));
        radioButton_ToYK->setText(QApplication::translate("DrugAllot", "\350\215\257\346\210\277\342\200\224>\350\215\257\345\272\223", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("DrugAllot", "\345\215\225\345\217\267\357\274\232", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("DrugAllot", "\350\260\203\346\213\250\346\227\245\346\234\237\357\274\232", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget_StoreAllot->horizontalHeaderItem(0);
        ___qtablewidgetitem12->setText(QApplication::translate("DrugAllot", "\347\274\226\347\240\201", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget_StoreAllot->horizontalHeaderItem(1);
        ___qtablewidgetitem13->setText(QApplication::translate("DrugAllot", "\345\220\215\347\247\260", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget_StoreAllot->horizontalHeaderItem(2);
        ___qtablewidgetitem14->setText(QApplication::translate("DrugAllot", "\350\247\204\346\240\274", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidget_StoreAllot->horizontalHeaderItem(3);
        ___qtablewidgetitem15->setText(QApplication::translate("DrugAllot", "\347\224\237\344\272\247\345\216\202\345\225\206", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem16 = tableWidget_StoreAllot->horizontalHeaderItem(4);
        ___qtablewidgetitem16->setText(QApplication::translate("DrugAllot", "\346\211\271\345\217\267", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem17 = tableWidget_StoreAllot->horizontalHeaderItem(5);
        ___qtablewidgetitem17->setText(QApplication::translate("DrugAllot", "\345\215\225\344\275\215", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem18 = tableWidget_StoreAllot->horizontalHeaderItem(6);
        ___qtablewidgetitem18->setText(QApplication::translate("DrugAllot", "\350\260\203\346\213\250\346\225\260\351\207\217", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem19 = tableWidget_StoreAllot->horizontalHeaderItem(7);
        ___qtablewidgetitem19->setText(QApplication::translate("DrugAllot", "\350\215\257\346\210\277\345\272\223\345\255\230", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem20 = tableWidget_StoreAllot->horizontalHeaderItem(8);
        ___qtablewidgetitem20->setText(QApplication::translate("DrugAllot", "\350\215\257\345\272\223\345\272\223\345\255\230", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem21 = tableWidget_StoreAllot->horizontalHeaderItem(9);
        ___qtablewidgetitem21->setText(QApplication::translate("DrugAllot", "\345\215\225\344\273\267", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem22 = tableWidget_StoreAllot->horizontalHeaderItem(10);
        ___qtablewidgetitem22->setText(QApplication::translate("DrugAllot", "\346\200\273\344\273\267", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem23 = tableWidget_StoreAllot->horizontalHeaderItem(11);
        ___qtablewidgetitem23->setText(QApplication::translate("DrugAllot", "\350\215\257\345\223\201\347\261\273\345\210\253", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem24 = tableWidget_StoreAllot->verticalHeaderItem(0);
        ___qtablewidgetitem24->setText(QApplication::translate("DrugAllot", "1", 0, QApplication::UnicodeUTF8));
        label_34->setText(QApplication::translate("DrugAllot", "\345\244\207\346\263\250\357\274\232", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("DrugAllot", "\344\273\223\345\272\223\350\260\203\346\213\250", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DrugAllot: public Ui_DrugAllot {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DRUGALLOT_H
