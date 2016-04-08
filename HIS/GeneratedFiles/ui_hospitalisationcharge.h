/********************************************************************************
** Form generated from reading UI file 'hospitalisationcharge.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOSPITALISATIONCHARGE_H
#define UI_HOSPITALISATIONCHARGE_H

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

class Ui_HospitalisationCharge
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *addButton;
    QPushButton *addrowButton;
    QPushButton *deleterowButton;
    QPushButton *saveButton;
    QPushButton *discardButton;
    QPushButton *editButton;
    QPushButton *deleteButton;
    QPushButton *printButton;
    QPushButton *previewButton;
    QPushButton *packageButton;
    QSpacerItem *horizontalSpacer_3;
    QVBoxLayout *verticalLayout_11;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_10;
    QVBoxLayout *verticalLayout_3;
    QLineEdit *sheetNoEdit;
    QLineEdit *nameEdit;
    QLineEdit *bedEdit;
    QVBoxLayout *verticalLayout_10;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_6;
    QLabel *label_8;
    QVBoxLayout *verticalLayout_5;
    QComboBox *hospitalisationNocomboBox;
    QLineEdit *genderEdit;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_5;
    QLabel *label_9;
    QVBoxLayout *verticalLayout_7;
    QDateTimeEdit *dateTimeEdit;
    QHBoxLayout *horizontalLayout;
    QLineEdit *ageEdit;
    QLabel *label_3;
    QLineEdit *doctorEdit;
    QVBoxLayout *verticalLayout_8;
    QLabel *label_7;
    QLabel *label_4;
    QVBoxLayout *verticalLayout_9;
    QLineEdit *warehouseEdit;
    QLineEdit *departmentEdit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_11;
    QLineEdit *remarkEdit;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_12;
    QSpacerItem *horizontalSpacer;
    QTextEdit *hintEdit;
    QTableWidget *tableWidget;
    QHBoxLayout *horizontalLayout_19;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_13;
    QLineEdit *sheetmakerEdit;

    void setupUi(QWidget *HospitalisationCharge)
    {
        if (HospitalisationCharge->objectName().isEmpty())
            HospitalisationCharge->setObjectName(QString::fromUtf8("HospitalisationCharge"));
        HospitalisationCharge->resize(893, 595);
        verticalLayout_2 = new QVBoxLayout(HospitalisationCharge);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        addButton = new QPushButton(HospitalisationCharge);
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

        horizontalLayout_5->addWidget(addButton);

        addrowButton = new QPushButton(HospitalisationCharge);
        addrowButton->setObjectName(QString::fromUtf8("addrowButton"));
        sizePolicy.setHeightForWidth(addrowButton->sizePolicy().hasHeightForWidth());
        addrowButton->setSizePolicy(sizePolicy);
        addrowButton->setFont(font);

        horizontalLayout_5->addWidget(addrowButton);

        deleterowButton = new QPushButton(HospitalisationCharge);
        deleterowButton->setObjectName(QString::fromUtf8("deleterowButton"));
        sizePolicy.setHeightForWidth(deleterowButton->sizePolicy().hasHeightForWidth());
        deleterowButton->setSizePolicy(sizePolicy);
        deleterowButton->setFont(font);

        horizontalLayout_5->addWidget(deleterowButton);

        saveButton = new QPushButton(HospitalisationCharge);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));
        sizePolicy.setHeightForWidth(saveButton->sizePolicy().hasHeightForWidth());
        saveButton->setSizePolicy(sizePolicy);
        saveButton->setFont(font);

        horizontalLayout_5->addWidget(saveButton);

        discardButton = new QPushButton(HospitalisationCharge);
        discardButton->setObjectName(QString::fromUtf8("discardButton"));
        sizePolicy.setHeightForWidth(discardButton->sizePolicy().hasHeightForWidth());
        discardButton->setSizePolicy(sizePolicy);
        discardButton->setFont(font);

        horizontalLayout_5->addWidget(discardButton);

        editButton = new QPushButton(HospitalisationCharge);
        editButton->setObjectName(QString::fromUtf8("editButton"));
        sizePolicy.setHeightForWidth(editButton->sizePolicy().hasHeightForWidth());
        editButton->setSizePolicy(sizePolicy);
        editButton->setFont(font);

        horizontalLayout_5->addWidget(editButton);

        deleteButton = new QPushButton(HospitalisationCharge);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));
        sizePolicy.setHeightForWidth(deleteButton->sizePolicy().hasHeightForWidth());
        deleteButton->setSizePolicy(sizePolicy);
        deleteButton->setFont(font);

        horizontalLayout_5->addWidget(deleteButton);

        printButton = new QPushButton(HospitalisationCharge);
        printButton->setObjectName(QString::fromUtf8("printButton"));
        sizePolicy.setHeightForWidth(printButton->sizePolicy().hasHeightForWidth());
        printButton->setSizePolicy(sizePolicy);
        printButton->setFont(font);

        horizontalLayout_5->addWidget(printButton);

        previewButton = new QPushButton(HospitalisationCharge);
        previewButton->setObjectName(QString::fromUtf8("previewButton"));
        sizePolicy.setHeightForWidth(previewButton->sizePolicy().hasHeightForWidth());
        previewButton->setSizePolicy(sizePolicy);
        previewButton->setFont(font);

        horizontalLayout_5->addWidget(previewButton);

        packageButton = new QPushButton(HospitalisationCharge);
        packageButton->setObjectName(QString::fromUtf8("packageButton"));
        sizePolicy.setHeightForWidth(packageButton->sizePolicy().hasHeightForWidth());
        packageButton->setSizePolicy(sizePolicy);
        packageButton->setFont(font);

        horizontalLayout_5->addWidget(packageButton);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);


        verticalLayout_2->addLayout(horizontalLayout_5);

        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setSpacing(6);
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(HospitalisationCharge);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        label_2 = new QLabel(HospitalisationCharge);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        label_10 = new QLabel(HospitalisationCharge);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        verticalLayout->addWidget(label_10);


        horizontalLayout_4->addLayout(verticalLayout);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        sheetNoEdit = new QLineEdit(HospitalisationCharge);
        sheetNoEdit->setObjectName(QString::fromUtf8("sheetNoEdit"));
        sizePolicy.setHeightForWidth(sheetNoEdit->sizePolicy().hasHeightForWidth());
        sheetNoEdit->setSizePolicy(sizePolicy);

        verticalLayout_3->addWidget(sheetNoEdit);

        nameEdit = new QLineEdit(HospitalisationCharge);
        nameEdit->setObjectName(QString::fromUtf8("nameEdit"));
        nameEdit->setEnabled(true);
        sizePolicy.setHeightForWidth(nameEdit->sizePolicy().hasHeightForWidth());
        nameEdit->setSizePolicy(sizePolicy);

        verticalLayout_3->addWidget(nameEdit);

        bedEdit = new QLineEdit(HospitalisationCharge);
        bedEdit->setObjectName(QString::fromUtf8("bedEdit"));
        bedEdit->setEnabled(false);
        sizePolicy.setHeightForWidth(bedEdit->sizePolicy().hasHeightForWidth());
        bedEdit->setSizePolicy(sizePolicy);

        verticalLayout_3->addWidget(bedEdit);


        horizontalLayout_4->addLayout(verticalLayout_3);

        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_6 = new QLabel(HospitalisationCharge);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout_4->addWidget(label_6);

        label_8 = new QLabel(HospitalisationCharge);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        verticalLayout_4->addWidget(label_8);


        horizontalLayout_2->addLayout(verticalLayout_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        hospitalisationNocomboBox = new QComboBox(HospitalisationCharge);
        hospitalisationNocomboBox->setObjectName(QString::fromUtf8("hospitalisationNocomboBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(hospitalisationNocomboBox->sizePolicy().hasHeightForWidth());
        hospitalisationNocomboBox->setSizePolicy(sizePolicy1);

        verticalLayout_5->addWidget(hospitalisationNocomboBox);

        genderEdit = new QLineEdit(HospitalisationCharge);
        genderEdit->setObjectName(QString::fromUtf8("genderEdit"));
        genderEdit->setEnabled(false);

        verticalLayout_5->addWidget(genderEdit);


        horizontalLayout_2->addLayout(verticalLayout_5);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        label_5 = new QLabel(HospitalisationCharge);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout_6->addWidget(label_5);

        label_9 = new QLabel(HospitalisationCharge);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        verticalLayout_6->addWidget(label_9);


        horizontalLayout_2->addLayout(verticalLayout_6);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        dateTimeEdit = new QDateTimeEdit(HospitalisationCharge);
        dateTimeEdit->setObjectName(QString::fromUtf8("dateTimeEdit"));

        verticalLayout_7->addWidget(dateTimeEdit);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        ageEdit = new QLineEdit(HospitalisationCharge);
        ageEdit->setObjectName(QString::fromUtf8("ageEdit"));
        ageEdit->setEnabled(false);

        horizontalLayout->addWidget(ageEdit);

        label_3 = new QLabel(HospitalisationCharge);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout->addWidget(label_3);

        doctorEdit = new QLineEdit(HospitalisationCharge);
        doctorEdit->setObjectName(QString::fromUtf8("doctorEdit"));
        doctorEdit->setEnabled(false);

        horizontalLayout->addWidget(doctorEdit);


        verticalLayout_7->addLayout(horizontalLayout);


        horizontalLayout_2->addLayout(verticalLayout_7);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        label_7 = new QLabel(HospitalisationCharge);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        verticalLayout_8->addWidget(label_7);

        label_4 = new QLabel(HospitalisationCharge);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_8->addWidget(label_4);


        horizontalLayout_2->addLayout(verticalLayout_8);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        warehouseEdit = new QLineEdit(HospitalisationCharge);
        warehouseEdit->setObjectName(QString::fromUtf8("warehouseEdit"));
        warehouseEdit->setEnabled(false);
        sizePolicy1.setHeightForWidth(warehouseEdit->sizePolicy().hasHeightForWidth());
        warehouseEdit->setSizePolicy(sizePolicy1);

        verticalLayout_9->addWidget(warehouseEdit);

        departmentEdit = new QLineEdit(HospitalisationCharge);
        departmentEdit->setObjectName(QString::fromUtf8("departmentEdit"));
        departmentEdit->setEnabled(false);

        verticalLayout_9->addWidget(departmentEdit);


        horizontalLayout_2->addLayout(verticalLayout_9);


        verticalLayout_10->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_11 = new QLabel(HospitalisationCharge);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        horizontalLayout_3->addWidget(label_11);

        remarkEdit = new QLineEdit(HospitalisationCharge);
        remarkEdit->setObjectName(QString::fromUtf8("remarkEdit"));
        remarkEdit->setEnabled(true);
        sizePolicy1.setHeightForWidth(remarkEdit->sizePolicy().hasHeightForWidth());
        remarkEdit->setSizePolicy(sizePolicy1);

        horizontalLayout_3->addWidget(remarkEdit);


        verticalLayout_10->addLayout(horizontalLayout_3);


        horizontalLayout_4->addLayout(verticalLayout_10);


        verticalLayout_11->addLayout(horizontalLayout_4);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        label_12 = new QLabel(HospitalisationCharge);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        horizontalLayout_14->addWidget(label_12);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer);


        verticalLayout_11->addLayout(horizontalLayout_14);

        hintEdit = new QTextEdit(HospitalisationCharge);
        hintEdit->setObjectName(QString::fromUtf8("hintEdit"));
        hintEdit->setEnabled(false);
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(hintEdit->sizePolicy().hasHeightForWidth());
        hintEdit->setSizePolicy(sizePolicy2);
        hintEdit->setFont(font);

        verticalLayout_11->addWidget(hintEdit);

        tableWidget = new QTableWidget(HospitalisationCharge);
        if (tableWidget->columnCount() < 13)
            tableWidget->setColumnCount(13);
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
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(11, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(12, __qtablewidgetitem12);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setSortingEnabled(true);
        tableWidget->verticalHeader()->setProperty("showSortIndicator", QVariant(false));
        tableWidget->verticalHeader()->setStretchLastSection(false);

        verticalLayout_11->addWidget(tableWidget);

        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setSpacing(6);
        horizontalLayout_19->setObjectName(QString::fromUtf8("horizontalLayout_19"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_19->addItem(horizontalSpacer_2);

        label_13 = new QLabel(HospitalisationCharge);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        horizontalLayout_19->addWidget(label_13);

        sheetmakerEdit = new QLineEdit(HospitalisationCharge);
        sheetmakerEdit->setObjectName(QString::fromUtf8("sheetmakerEdit"));
        sizePolicy.setHeightForWidth(sheetmakerEdit->sizePolicy().hasHeightForWidth());
        sheetmakerEdit->setSizePolicy(sizePolicy);

        horizontalLayout_19->addWidget(sheetmakerEdit);


        verticalLayout_11->addLayout(horizontalLayout_19);


        verticalLayout_2->addLayout(verticalLayout_11);


        retranslateUi(HospitalisationCharge);

        QMetaObject::connectSlotsByName(HospitalisationCharge);
    } // setupUi

    void retranslateUi(QWidget *HospitalisationCharge)
    {
        HospitalisationCharge->setWindowTitle(QApplication::translate("HospitalisationCharge", "\344\275\217\351\231\242\346\224\266\350\264\271", 0, QApplication::UnicodeUTF8));
        addButton->setText(QApplication::translate("HospitalisationCharge", "\346\226\260\345\242\236", 0, QApplication::UnicodeUTF8));
        addrowButton->setText(QApplication::translate("HospitalisationCharge", "\345\242\236\350\241\214", 0, QApplication::UnicodeUTF8));
        deleterowButton->setText(QApplication::translate("HospitalisationCharge", "\345\210\240\350\241\214", 0, QApplication::UnicodeUTF8));
        saveButton->setText(QApplication::translate("HospitalisationCharge", "\344\277\235\345\255\230", 0, QApplication::UnicodeUTF8));
        discardButton->setText(QApplication::translate("HospitalisationCharge", "\346\224\276\345\274\203", 0, QApplication::UnicodeUTF8));
        editButton->setText(QApplication::translate("HospitalisationCharge", "\344\277\256\346\224\271", 0, QApplication::UnicodeUTF8));
        deleteButton->setText(QApplication::translate("HospitalisationCharge", "\345\210\240\351\231\244", 0, QApplication::UnicodeUTF8));
        printButton->setText(QApplication::translate("HospitalisationCharge", "\346\211\223\345\215\260", 0, QApplication::UnicodeUTF8));
        previewButton->setText(QApplication::translate("HospitalisationCharge", "\351\242\204\350\247\210", 0, QApplication::UnicodeUTF8));
        packageButton->setText(QApplication::translate("HospitalisationCharge", "\345\245\227\351\244\220", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("HospitalisationCharge", "\345\215\225\345\217\267\357\274\232", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("HospitalisationCharge", "\345\247\223\345\220\215\357\274\232", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("HospitalisationCharge", "\345\272\212\344\275\215\357\274\232", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("HospitalisationCharge", "\344\275\217\351\231\242\345\217\267\357\274\232", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("HospitalisationCharge", "\346\200\247\345\210\253\357\274\232", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("HospitalisationCharge", "\346\227\245\346\234\237\357\274\232", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("HospitalisationCharge", "\345\271\264\351\276\204\357\274\232", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("HospitalisationCharge", "\345\214\273\347\224\237\357\274\232", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("HospitalisationCharge", "\350\215\257\346\210\277\357\274\232", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("HospitalisationCharge", "\345\260\261\350\257\212\347\247\221\345\256\244\357\274\232", 0, QApplication::UnicodeUTF8));
        warehouseEdit->setText(QApplication::translate("HospitalisationCharge", "\350\215\257\346\210\277", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("HospitalisationCharge", "\345\244\207\346\263\250\357\274\232", 0, QApplication::UnicodeUTF8));
        remarkEdit->setText(QString());
        label_12->setText(QApplication::translate("HospitalisationCharge", "\346\217\220\347\244\272:", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("HospitalisationCharge", "\347\274\226\347\240\201", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("HospitalisationCharge", "\345\220\215\347\247\260", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("HospitalisationCharge", "\350\247\204\346\240\274", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("HospitalisationCharge", "\347\224\237\344\272\247\345\216\202\345\225\206", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("HospitalisationCharge", "\346\211\271\345\217\267", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("HospitalisationCharge", "\345\215\225\344\275\215", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("HospitalisationCharge", "\345\272\223\345\255\230\351\207\217", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QApplication::translate("HospitalisationCharge", "\346\225\260\351\207\217", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QApplication::translate("HospitalisationCharge", "\345\215\225\344\273\267", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->horizontalHeaderItem(9);
        ___qtablewidgetitem9->setText(QApplication::translate("HospitalisationCharge", "\351\207\221\351\242\235", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget->horizontalHeaderItem(10);
        ___qtablewidgetitem10->setText(QApplication::translate("HospitalisationCharge", "\344\275\217\351\231\242\346\224\266\346\215\256", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget->horizontalHeaderItem(11);
        ___qtablewidgetitem11->setText(QApplication::translate("HospitalisationCharge", "\345\214\273\350\215\257\345\210\206\347\261\273", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget->horizontalHeaderItem(12);
        ___qtablewidgetitem12->setText(QApplication::translate("HospitalisationCharge", "\344\275\217\351\231\242\345\210\206\347\261\273", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("HospitalisationCharge", "\345\210\266\345\215\225\357\274\232", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class HospitalisationCharge: public Ui_HospitalisationCharge {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOSPITALISATIONCHARGE_H
