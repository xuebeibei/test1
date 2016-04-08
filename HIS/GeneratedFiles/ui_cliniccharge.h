/********************************************************************************
** Form generated from reading UI file 'cliniccharge.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLINICCHARGE_H
#define UI_CLINICCHARGE_H

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
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ClinicCharge
{
public:
    QVBoxLayout *verticalLayout_9;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *addButton;
    QPushButton *addrowButton;
    QPushButton *deleterowButton;
    QPushButton *packageButton;
    QPushButton *editButton;
    QPushButton *deleteButton;
    QPushButton *discardButton;
    QPushButton *saveButton;
    QPushButton *printButton;
    QPushButton *previewButton;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_15;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *sheetNoEdit;
    QLineEdit *nameEdit;
    QLineEdit *IDEdit;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_5;
    QLabel *label_8;
    QLabel *label_13;
    QVBoxLayout *verticalLayout_4;
    QDateTimeEdit *dateTimeEdit;
    QHBoxLayout *horizontalLayout_2;
    QComboBox *gendercomboBox;
    QLabel *label_9;
    QLineEdit *ageEdit;
    QLineEdit *insuranceNoEdit;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_7;
    QLabel *label_3;
    QLabel *label_12;
    QVBoxLayout *verticalLayout_6;
    QLineEdit *warehouseEdit;
    QLineEdit *doctorEdit;
    QComboBox *insurancetypecomboBox;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_6;
    QLabel *label_4;
    QLabel *label_10;
    QVBoxLayout *verticalLayout_8;
    QLineEdit *customerEdit;
    QLineEdit *departmentEdit;
    QHBoxLayout *horizontalLayout;
    QLineEdit *dueincomeEdit;
    QLabel *label_11;
    QLineEdit *realincomeEdit;
    QHBoxLayout *horizontalLayout_5;
    QTableWidget *tableWidget;
    QHBoxLayout *horizontalLayout_14;
    QSpacerItem *horizontalSpacer;
    QLabel *label_14;
    QLineEdit *sheetmakerEdit;

    void setupUi(QWidget *ClinicCharge)
    {
        if (ClinicCharge->objectName().isEmpty())
            ClinicCharge->setObjectName(QString::fromUtf8("ClinicCharge"));
        ClinicCharge->resize(881, 539);
        verticalLayout_9 = new QVBoxLayout(ClinicCharge);
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setContentsMargins(11, 11, 11, 11);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        addButton = new QPushButton(ClinicCharge);
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

        horizontalLayout_4->addWidget(addButton);

        addrowButton = new QPushButton(ClinicCharge);
        addrowButton->setObjectName(QString::fromUtf8("addrowButton"));
        sizePolicy.setHeightForWidth(addrowButton->sizePolicy().hasHeightForWidth());
        addrowButton->setSizePolicy(sizePolicy);
        addrowButton->setFont(font);

        horizontalLayout_4->addWidget(addrowButton);

        deleterowButton = new QPushButton(ClinicCharge);
        deleterowButton->setObjectName(QString::fromUtf8("deleterowButton"));
        sizePolicy.setHeightForWidth(deleterowButton->sizePolicy().hasHeightForWidth());
        deleterowButton->setSizePolicy(sizePolicy);
        deleterowButton->setFont(font);

        horizontalLayout_4->addWidget(deleterowButton);

        packageButton = new QPushButton(ClinicCharge);
        packageButton->setObjectName(QString::fromUtf8("packageButton"));
        sizePolicy.setHeightForWidth(packageButton->sizePolicy().hasHeightForWidth());
        packageButton->setSizePolicy(sizePolicy);
        packageButton->setFont(font);

        horizontalLayout_4->addWidget(packageButton);

        editButton = new QPushButton(ClinicCharge);
        editButton->setObjectName(QString::fromUtf8("editButton"));
        sizePolicy.setHeightForWidth(editButton->sizePolicy().hasHeightForWidth());
        editButton->setSizePolicy(sizePolicy);
        editButton->setFont(font);

        horizontalLayout_4->addWidget(editButton);

        deleteButton = new QPushButton(ClinicCharge);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));
        sizePolicy.setHeightForWidth(deleteButton->sizePolicy().hasHeightForWidth());
        deleteButton->setSizePolicy(sizePolicy);
        deleteButton->setFont(font);

        horizontalLayout_4->addWidget(deleteButton);

        discardButton = new QPushButton(ClinicCharge);
        discardButton->setObjectName(QString::fromUtf8("discardButton"));
        sizePolicy.setHeightForWidth(discardButton->sizePolicy().hasHeightForWidth());
        discardButton->setSizePolicy(sizePolicy);
        discardButton->setFont(font);

        horizontalLayout_4->addWidget(discardButton);

        saveButton = new QPushButton(ClinicCharge);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));
        sizePolicy.setHeightForWidth(saveButton->sizePolicy().hasHeightForWidth());
        saveButton->setSizePolicy(sizePolicy);
        saveButton->setFont(font);

        horizontalLayout_4->addWidget(saveButton);

        printButton = new QPushButton(ClinicCharge);
        printButton->setObjectName(QString::fromUtf8("printButton"));
        sizePolicy.setHeightForWidth(printButton->sizePolicy().hasHeightForWidth());
        printButton->setSizePolicy(sizePolicy);
        printButton->setFont(font);

        horizontalLayout_4->addWidget(printButton);

        previewButton = new QPushButton(ClinicCharge);
        previewButton->setObjectName(QString::fromUtf8("previewButton"));
        sizePolicy.setHeightForWidth(previewButton->sizePolicy().hasHeightForWidth());
        previewButton->setSizePolicy(sizePolicy);
        previewButton->setFont(font);

        horizontalLayout_4->addWidget(previewButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);


        verticalLayout_9->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(ClinicCharge);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        label->setMaximumSize(QSize(57, 16777215));

        verticalLayout->addWidget(label);

        label_2 = new QLabel(ClinicCharge);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);
        label_2->setMaximumSize(QSize(57, 16777215));

        verticalLayout->addWidget(label_2);

        label_15 = new QLabel(ClinicCharge);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        sizePolicy1.setHeightForWidth(label_15->sizePolicy().hasHeightForWidth());
        label_15->setSizePolicy(sizePolicy1);
        label_15->setMaximumSize(QSize(57, 16777215));

        verticalLayout->addWidget(label_15);


        horizontalLayout_3->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        sheetNoEdit = new QLineEdit(ClinicCharge);
        sheetNoEdit->setObjectName(QString::fromUtf8("sheetNoEdit"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(sheetNoEdit->sizePolicy().hasHeightForWidth());
        sheetNoEdit->setSizePolicy(sizePolicy2);
        sheetNoEdit->setMaximumSize(QSize(1500, 16777215));

        verticalLayout_2->addWidget(sheetNoEdit);

        nameEdit = new QLineEdit(ClinicCharge);
        nameEdit->setObjectName(QString::fromUtf8("nameEdit"));
        sizePolicy2.setHeightForWidth(nameEdit->sizePolicy().hasHeightForWidth());
        nameEdit->setSizePolicy(sizePolicy2);
        nameEdit->setMinimumSize(QSize(100, 0));
        nameEdit->setMaximumSize(QSize(1500, 16777215));

        verticalLayout_2->addWidget(nameEdit);

        IDEdit = new QLineEdit(ClinicCharge);
        IDEdit->setObjectName(QString::fromUtf8("IDEdit"));
        sizePolicy2.setHeightForWidth(IDEdit->sizePolicy().hasHeightForWidth());
        IDEdit->setSizePolicy(sizePolicy2);
        IDEdit->setMinimumSize(QSize(100, 0));
        IDEdit->setMaximumSize(QSize(1500, 16777215));

        verticalLayout_2->addWidget(IDEdit);


        horizontalLayout_3->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_5 = new QLabel(ClinicCharge);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        sizePolicy1.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy1);
        label_5->setMaximumSize(QSize(79, 16777215));

        verticalLayout_3->addWidget(label_5);

        label_8 = new QLabel(ClinicCharge);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        sizePolicy1.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy1);
        label_8->setMaximumSize(QSize(79, 16777215));

        verticalLayout_3->addWidget(label_8);

        label_13 = new QLabel(ClinicCharge);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        sizePolicy1.setHeightForWidth(label_13->sizePolicy().hasHeightForWidth());
        label_13->setSizePolicy(sizePolicy1);
        label_13->setMaximumSize(QSize(79, 16777215));

        verticalLayout_3->addWidget(label_13);


        horizontalLayout_3->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        dateTimeEdit = new QDateTimeEdit(ClinicCharge);
        dateTimeEdit->setObjectName(QString::fromUtf8("dateTimeEdit"));
        sizePolicy2.setHeightForWidth(dateTimeEdit->sizePolicy().hasHeightForWidth());
        dateTimeEdit->setSizePolicy(sizePolicy2);
        dateTimeEdit->setMaximumSize(QSize(16777215, 16777215));

        verticalLayout_4->addWidget(dateTimeEdit);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        gendercomboBox = new QComboBox(ClinicCharge);
        gendercomboBox->setObjectName(QString::fromUtf8("gendercomboBox"));
        sizePolicy2.setHeightForWidth(gendercomboBox->sizePolicy().hasHeightForWidth());
        gendercomboBox->setSizePolicy(sizePolicy2);
        gendercomboBox->setMinimumSize(QSize(61, 0));
        gendercomboBox->setMaximumSize(QSize(1500, 16777215));

        horizontalLayout_2->addWidget(gendercomboBox);

        label_9 = new QLabel(ClinicCharge);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setMaximumSize(QSize(31, 16777215));

        horizontalLayout_2->addWidget(label_9);

        ageEdit = new QLineEdit(ClinicCharge);
        ageEdit->setObjectName(QString::fromUtf8("ageEdit"));
        sizePolicy2.setHeightForWidth(ageEdit->sizePolicy().hasHeightForWidth());
        ageEdit->setSizePolicy(sizePolicy2);
        ageEdit->setMaximumSize(QSize(1500, 16777215));

        horizontalLayout_2->addWidget(ageEdit);


        verticalLayout_4->addLayout(horizontalLayout_2);

        insuranceNoEdit = new QLineEdit(ClinicCharge);
        insuranceNoEdit->setObjectName(QString::fromUtf8("insuranceNoEdit"));

        verticalLayout_4->addWidget(insuranceNoEdit);


        horizontalLayout_3->addLayout(verticalLayout_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        label_7 = new QLabel(ClinicCharge);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        sizePolicy1.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy1);
        label_7->setMaximumSize(QSize(51, 16777215));

        verticalLayout_5->addWidget(label_7);

        label_3 = new QLabel(ClinicCharge);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy1.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy1);
        label_3->setMaximumSize(QSize(52, 16777215));

        verticalLayout_5->addWidget(label_3);

        label_12 = new QLabel(ClinicCharge);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        sizePolicy1.setHeightForWidth(label_12->sizePolicy().hasHeightForWidth());
        label_12->setSizePolicy(sizePolicy1);
        label_12->setMaximumSize(QSize(56, 16777215));

        verticalLayout_5->addWidget(label_12);


        horizontalLayout_3->addLayout(verticalLayout_5);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        warehouseEdit = new QLineEdit(ClinicCharge);
        warehouseEdit->setObjectName(QString::fromUtf8("warehouseEdit"));
        warehouseEdit->setEnabled(false);
        sizePolicy2.setHeightForWidth(warehouseEdit->sizePolicy().hasHeightForWidth());
        warehouseEdit->setSizePolicy(sizePolicy2);
        warehouseEdit->setMinimumSize(QSize(90, 0));
        warehouseEdit->setMaximumSize(QSize(1500, 16777215));

        verticalLayout_6->addWidget(warehouseEdit);

        doctorEdit = new QLineEdit(ClinicCharge);
        doctorEdit->setObjectName(QString::fromUtf8("doctorEdit"));
        sizePolicy2.setHeightForWidth(doctorEdit->sizePolicy().hasHeightForWidth());
        doctorEdit->setSizePolicy(sizePolicy2);
        doctorEdit->setMinimumSize(QSize(90, 0));
        doctorEdit->setMaximumSize(QSize(1500, 16777215));

        verticalLayout_6->addWidget(doctorEdit);

        insurancetypecomboBox = new QComboBox(ClinicCharge);
        insurancetypecomboBox->setObjectName(QString::fromUtf8("insurancetypecomboBox"));
        sizePolicy2.setHeightForWidth(insurancetypecomboBox->sizePolicy().hasHeightForWidth());
        insurancetypecomboBox->setSizePolicy(sizePolicy2);
        insurancetypecomboBox->setMinimumSize(QSize(90, 0));
        insurancetypecomboBox->setMaximumSize(QSize(1500, 16777215));

        verticalLayout_6->addWidget(insurancetypecomboBox);


        horizontalLayout_3->addLayout(verticalLayout_6);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        label_6 = new QLabel(ClinicCharge);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy3);
        label_6->setMaximumSize(QSize(56, 16777215));

        verticalLayout_7->addWidget(label_6);

        label_4 = new QLabel(ClinicCharge);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        QSizePolicy sizePolicy4(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy4);
        label_4->setMaximumSize(QSize(56, 16777215));

        verticalLayout_7->addWidget(label_4);

        label_10 = new QLabel(ClinicCharge);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setMaximumSize(QSize(56, 16777215));

        verticalLayout_7->addWidget(label_10);


        horizontalLayout_3->addLayout(verticalLayout_7);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        customerEdit = new QLineEdit(ClinicCharge);
        customerEdit->setObjectName(QString::fromUtf8("customerEdit"));
        customerEdit->setEnabled(false);
        sizePolicy2.setHeightForWidth(customerEdit->sizePolicy().hasHeightForWidth());
        customerEdit->setSizePolicy(sizePolicy2);

        verticalLayout_8->addWidget(customerEdit);

        departmentEdit = new QLineEdit(ClinicCharge);
        departmentEdit->setObjectName(QString::fromUtf8("departmentEdit"));
        departmentEdit->setEnabled(false);

        verticalLayout_8->addWidget(departmentEdit);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        dueincomeEdit = new QLineEdit(ClinicCharge);
        dueincomeEdit->setObjectName(QString::fromUtf8("dueincomeEdit"));
        dueincomeEdit->setEnabled(false);
        sizePolicy2.setHeightForWidth(dueincomeEdit->sizePolicy().hasHeightForWidth());
        dueincomeEdit->setSizePolicy(sizePolicy2);
        dueincomeEdit->setMaximumSize(QSize(1500, 16777215));

        horizontalLayout->addWidget(dueincomeEdit);

        label_11 = new QLabel(ClinicCharge);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        sizePolicy1.setHeightForWidth(label_11->sizePolicy().hasHeightForWidth());
        label_11->setSizePolicy(sizePolicy1);
        label_11->setMaximumSize(QSize(31, 16777215));

        horizontalLayout->addWidget(label_11);

        realincomeEdit = new QLineEdit(ClinicCharge);
        realincomeEdit->setObjectName(QString::fromUtf8("realincomeEdit"));
        sizePolicy2.setHeightForWidth(realincomeEdit->sizePolicy().hasHeightForWidth());
        realincomeEdit->setSizePolicy(sizePolicy2);
        realincomeEdit->setMinimumSize(QSize(43, 0));
        realincomeEdit->setMaximumSize(QSize(1500, 20));

        horizontalLayout->addWidget(realincomeEdit);


        verticalLayout_8->addLayout(horizontalLayout);


        horizontalLayout_3->addLayout(verticalLayout_8);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));

        horizontalLayout_3->addLayout(horizontalLayout_5);


        verticalLayout_9->addLayout(horizontalLayout_3);

        tableWidget = new QTableWidget(ClinicCharge);
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
        QSizePolicy sizePolicy5(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(tableWidget->sizePolicy().hasHeightForWidth());
        tableWidget->setSizePolicy(sizePolicy5);
        tableWidget->setFocusPolicy(Qt::ClickFocus);
        tableWidget->setSortingEnabled(false);
        tableWidget->verticalHeader()->setProperty("showSortIndicator", QVariant(false));
        tableWidget->verticalHeader()->setStretchLastSection(false);

        verticalLayout_9->addWidget(tableWidget);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer);

        label_14 = new QLabel(ClinicCharge);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        horizontalLayout_14->addWidget(label_14);

        sheetmakerEdit = new QLineEdit(ClinicCharge);
        sheetmakerEdit->setObjectName(QString::fromUtf8("sheetmakerEdit"));
        sizePolicy.setHeightForWidth(sheetmakerEdit->sizePolicy().hasHeightForWidth());
        sheetmakerEdit->setSizePolicy(sizePolicy);
        sheetmakerEdit->setMaximumSize(QSize(60, 16777215));

        horizontalLayout_14->addWidget(sheetmakerEdit);


        verticalLayout_9->addLayout(horizontalLayout_14);

        QWidget::setTabOrder(sheetNoEdit, nameEdit);
        QWidget::setTabOrder(nameEdit, ageEdit);
        QWidget::setTabOrder(ageEdit, doctorEdit);
        QWidget::setTabOrder(doctorEdit, IDEdit);
        QWidget::setTabOrder(IDEdit, insuranceNoEdit);
        QWidget::setTabOrder(insuranceNoEdit, dueincomeEdit);
        QWidget::setTabOrder(dueincomeEdit, realincomeEdit);
        QWidget::setTabOrder(realincomeEdit, tableWidget);
        QWidget::setTabOrder(tableWidget, dateTimeEdit);
        QWidget::setTabOrder(dateTimeEdit, gendercomboBox);
        QWidget::setTabOrder(gendercomboBox, editButton);
        QWidget::setTabOrder(editButton, warehouseEdit);
        QWidget::setTabOrder(warehouseEdit, saveButton);
        QWidget::setTabOrder(saveButton, insurancetypecomboBox);
        QWidget::setTabOrder(insurancetypecomboBox, customerEdit);
        QWidget::setTabOrder(customerEdit, sheetmakerEdit);
        QWidget::setTabOrder(sheetmakerEdit, addButton);
        QWidget::setTabOrder(addButton, addrowButton);
        QWidget::setTabOrder(addrowButton, deleterowButton);
        QWidget::setTabOrder(deleterowButton, packageButton);
        QWidget::setTabOrder(packageButton, deleteButton);
        QWidget::setTabOrder(deleteButton, discardButton);
        QWidget::setTabOrder(discardButton, printButton);
        QWidget::setTabOrder(printButton, previewButton);

        retranslateUi(ClinicCharge);

        QMetaObject::connectSlotsByName(ClinicCharge);
    } // setupUi

    void retranslateUi(QWidget *ClinicCharge)
    {
        ClinicCharge->setWindowTitle(QApplication::translate("ClinicCharge", "\351\227\250\350\257\212\346\224\266\350\264\271", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        addButton->setToolTip(QApplication::translate("ClinicCharge", "\346\226\260\345\273\272\344\270\200\344\270\252\346\224\266\350\264\271\345\215\225", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        addButton->setText(QApplication::translate("ClinicCharge", "\346\226\260\345\242\236", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        addrowButton->setToolTip(QApplication::translate("ClinicCharge", "\350\241\250\346\240\274\345\242\236\345\212\240\344\270\200\350\241\214", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        addrowButton->setText(QApplication::translate("ClinicCharge", "\345\242\236\350\241\214", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        deleterowButton->setToolTip(QApplication::translate("ClinicCharge", "\344\273\216\350\241\250\346\240\274\344\270\255\345\210\240\351\231\244\351\200\211\344\270\255\350\241\214", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        deleterowButton->setText(QApplication::translate("ClinicCharge", "\345\210\240\350\241\214", 0, QApplication::UnicodeUTF8));
        packageButton->setText(QApplication::translate("ClinicCharge", "\345\245\227\351\244\220", 0, QApplication::UnicodeUTF8));
        editButton->setText(QApplication::translate("ClinicCharge", "\344\277\256\346\224\271", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        deleteButton->setToolTip(QApplication::translate("ClinicCharge", "\344\273\216\346\225\260\346\215\256\345\272\223\344\270\255\345\210\240\351\231\244\350\257\245\345\215\225", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        deleteButton->setText(QApplication::translate("ClinicCharge", "\345\210\240\351\231\244", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        discardButton->setToolTip(QApplication::translate("ClinicCharge", "\346\270\205\347\251\272", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        discardButton->setText(QApplication::translate("ClinicCharge", "\346\224\276\345\274\203", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        saveButton->setToolTip(QApplication::translate("ClinicCharge", "\344\277\235\345\255\230\350\207\263\346\225\260\346\215\256\345\272\223", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        saveButton->setText(QApplication::translate("ClinicCharge", "\344\277\235\345\255\230", 0, QApplication::UnicodeUTF8));
        printButton->setText(QApplication::translate("ClinicCharge", "\346\211\223\345\215\260", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        previewButton->setToolTip(QApplication::translate("ClinicCharge", "\346\211\223\345\215\260\351\242\204\350\247\210", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        previewButton->setText(QApplication::translate("ClinicCharge", "\351\242\204\350\247\210", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ClinicCharge", "\345\215\225\345\217\267\357\274\232", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ClinicCharge", "\345\247\223\345\220\215\357\274\232", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("ClinicCharge", "\350\272\253\344\273\275\350\257\201\345\217\267\357\274\232", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("ClinicCharge", "\345\274\200\347\245\250\346\227\245\346\234\237\357\274\232", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("ClinicCharge", "\346\200\247\345\210\253\357\274\232", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("ClinicCharge", "\347\244\276\344\274\232\344\277\235\351\232\234\345\217\267\347\240\201\357\274\232", 0, QApplication::UnicodeUTF8));
        gendercomboBox->clear();
        gendercomboBox->insertItems(0, QStringList()
         << QApplication::translate("ClinicCharge", "\347\224\267", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ClinicCharge", "\345\245\263", 0, QApplication::UnicodeUTF8)
        );
        label_9->setText(QApplication::translate("ClinicCharge", "\345\271\264\351\276\204\357\274\232", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("ClinicCharge", "\350\215\257\346\210\277\357\274\232    ", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("ClinicCharge", "\345\214\273\347\224\237\357\274\232    ", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("ClinicCharge", "\345\214\273\344\277\235\347\261\273\345\236\213\357\274\232", 0, QApplication::UnicodeUTF8));
        warehouseEdit->setText(QApplication::translate("ClinicCharge", "\350\215\257\346\210\277 ", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("ClinicCharge", "\345\256\242\346\210\267\357\274\232    ", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("ClinicCharge", "\345\260\261\350\257\212\347\247\221\345\256\244\357\274\232", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("ClinicCharge", "\345\272\224\346\224\266\357\274\232", 0, QApplication::UnicodeUTF8));
        customerEdit->setText(QApplication::translate("ClinicCharge", "\351\227\250\350\257\212\346\224\266\345\205\245", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("ClinicCharge", "\345\256\236\346\224\266\357\274\232", 0, QApplication::UnicodeUTF8));
        realincomeEdit->setText(QString());
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("ClinicCharge", "\347\274\226\347\240\201", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("ClinicCharge", "\345\220\215\347\247\260", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("ClinicCharge", "\350\247\204\346\240\274", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("ClinicCharge", "\347\224\237\344\272\247\345\216\202\345\225\206", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("ClinicCharge", "\346\211\271\345\217\267", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("ClinicCharge", "\345\272\223\345\255\230\351\207\217", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("ClinicCharge", "\345\215\225\344\275\215", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QApplication::translate("ClinicCharge", "\346\225\260\351\207\217", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QApplication::translate("ClinicCharge", "\345\215\225\344\273\267", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->horizontalHeaderItem(9);
        ___qtablewidgetitem9->setText(QApplication::translate("ClinicCharge", "\351\207\221\351\242\235", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget->horizontalHeaderItem(10);
        ___qtablewidgetitem10->setText(QApplication::translate("ClinicCharge", "\351\227\250\350\257\212\346\224\266\346\215\256", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget->horizontalHeaderItem(11);
        ___qtablewidgetitem11->setText(QApplication::translate("ClinicCharge", "\345\214\273\350\215\257\345\210\206\347\261\273", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget->horizontalHeaderItem(12);
        ___qtablewidgetitem12->setText(QApplication::translate("ClinicCharge", "\351\227\250\350\257\212\345\210\206\347\261\273", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("ClinicCharge", "\345\210\266\345\215\225\357\274\232", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ClinicCharge: public Ui_ClinicCharge {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLINICCHARGE_H
