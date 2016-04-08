/********************************************************************************
** Form generated from reading UI file 'hospitalisationregistry.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOSPITALISATIONREGISTRY_H
#define UI_HOSPITALISATIONREGISTRY_H

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
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HospitalisationRegistry
{
public:
    QVBoxLayout *verticalLayout_9;
    QHBoxLayout *horizontalLayout_23;
    QPushButton *addButton;
    QPushButton *editButton;
    QPushButton *deleteButton;
    QPushButton *discardButton;
    QPushButton *saveButton;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_10;
    QLabel *label_12;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *hospitalisationNoEdit;
    QLineEdit *contactEdit;
    QComboBox *departmentcomboBox;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_2;
    QLabel *label_11;
    QLabel *label_13;
    QVBoxLayout *verticalLayout_5;
    QLineEdit *recordNoEdit;
    QLineEdit *telEdit;
    QLineEdit *doctorEdit;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_4;
    QLabel *label_8;
    QLabel *label_14;
    QVBoxLayout *verticalLayout_7;
    QLineEdit *nameEdit;
    QLineEdit *IDEdit;
    QComboBox *feetypecomboBox;
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_7;
    QLineEdit *ageEdit;
    QLabel *label_6;
    QComboBox *gendercomboBox;
    QLabel *label_3;
    QDateTimeEdit *dateTimeEdit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_9;
    QLineEdit *addressEdit;
    QHBoxLayout *horizontalLayout;
    QLabel *label_16;
    QLineEdit *bedEdit;
    QLabel *label_15;
    QComboBox *nursinglevelcomboBox;
    QLabel *label_23;
    QLineEdit *cooperativemedicalNoEdit;
    QLabel *label_22;
    QLineEdit *certificateNoEdit;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_17;
    QLabel *label_5;
    QSpacerItem *horizontalSpacer_3;
    QTextEdit *diagnosisEdit;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_18;
    QLineEdit *minimumEdit;
    QLabel *label_19;
    QLineEdit *sheetmakerEdit;
    QLabel *label_21;
    QLineEdit *statusEdit;
    QSpacerItem *horizontalSpacer_6;

    void setupUi(QWidget *HospitalisationRegistry)
    {
        if (HospitalisationRegistry->objectName().isEmpty())
            HospitalisationRegistry->setObjectName(QString::fromUtf8("HospitalisationRegistry"));
        HospitalisationRegistry->resize(1134, 520);
        verticalLayout_9 = new QVBoxLayout(HospitalisationRegistry);
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setContentsMargins(11, 11, 11, 11);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        horizontalLayout_23 = new QHBoxLayout();
        horizontalLayout_23->setSpacing(6);
        horizontalLayout_23->setObjectName(QString::fromUtf8("horizontalLayout_23"));
        addButton = new QPushButton(HospitalisationRegistry);
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

        horizontalLayout_23->addWidget(addButton);

        editButton = new QPushButton(HospitalisationRegistry);
        editButton->setObjectName(QString::fromUtf8("editButton"));
        sizePolicy.setHeightForWidth(editButton->sizePolicy().hasHeightForWidth());
        editButton->setSizePolicy(sizePolicy);
        editButton->setFont(font);

        horizontalLayout_23->addWidget(editButton);

        deleteButton = new QPushButton(HospitalisationRegistry);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));
        sizePolicy.setHeightForWidth(deleteButton->sizePolicy().hasHeightForWidth());
        deleteButton->setSizePolicy(sizePolicy);
        deleteButton->setFont(font);

        horizontalLayout_23->addWidget(deleteButton);

        discardButton = new QPushButton(HospitalisationRegistry);
        discardButton->setObjectName(QString::fromUtf8("discardButton"));
        sizePolicy.setHeightForWidth(discardButton->sizePolicy().hasHeightForWidth());
        discardButton->setSizePolicy(sizePolicy);
        discardButton->setFont(font);

        horizontalLayout_23->addWidget(discardButton);

        saveButton = new QPushButton(HospitalisationRegistry);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));
        sizePolicy.setHeightForWidth(saveButton->sizePolicy().hasHeightForWidth());
        saveButton->setSizePolicy(sizePolicy);
        saveButton->setFont(font);

        horizontalLayout_23->addWidget(saveButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_23->addItem(horizontalSpacer);


        verticalLayout_9->addLayout(horizontalLayout_23);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(HospitalisationRegistry);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(label);

        label_10 = new QLabel(HospitalisationRegistry);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        sizePolicy1.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(label_10);

        label_12 = new QLabel(HospitalisationRegistry);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        verticalLayout->addWidget(label_12);


        horizontalLayout_5->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        hospitalisationNoEdit = new QLineEdit(HospitalisationRegistry);
        hospitalisationNoEdit->setObjectName(QString::fromUtf8("hospitalisationNoEdit"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(hospitalisationNoEdit->sizePolicy().hasHeightForWidth());
        hospitalisationNoEdit->setSizePolicy(sizePolicy2);
        hospitalisationNoEdit->setMinimumSize(QSize(60, 0));
        hospitalisationNoEdit->setMaximumSize(QSize(100, 16777215));

        verticalLayout_2->addWidget(hospitalisationNoEdit);

        contactEdit = new QLineEdit(HospitalisationRegistry);
        contactEdit->setObjectName(QString::fromUtf8("contactEdit"));
        sizePolicy2.setHeightForWidth(contactEdit->sizePolicy().hasHeightForWidth());
        contactEdit->setSizePolicy(sizePolicy2);
        contactEdit->setMinimumSize(QSize(60, 0));
        contactEdit->setMaximumSize(QSize(100, 16777215));

        verticalLayout_2->addWidget(contactEdit);

        departmentcomboBox = new QComboBox(HospitalisationRegistry);
        departmentcomboBox->setObjectName(QString::fromUtf8("departmentcomboBox"));
        sizePolicy2.setHeightForWidth(departmentcomboBox->sizePolicy().hasHeightForWidth());
        departmentcomboBox->setSizePolicy(sizePolicy2);
        departmentcomboBox->setMaximumSize(QSize(100, 16777215));

        verticalLayout_2->addWidget(departmentcomboBox);


        horizontalLayout_5->addLayout(verticalLayout_2);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_2 = new QLabel(HospitalisationRegistry);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);

        verticalLayout_4->addWidget(label_2);

        label_11 = new QLabel(HospitalisationRegistry);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        sizePolicy1.setHeightForWidth(label_11->sizePolicy().hasHeightForWidth());
        label_11->setSizePolicy(sizePolicy1);

        verticalLayout_4->addWidget(label_11);

        label_13 = new QLabel(HospitalisationRegistry);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        verticalLayout_4->addWidget(label_13);


        horizontalLayout_5->addLayout(verticalLayout_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        recordNoEdit = new QLineEdit(HospitalisationRegistry);
        recordNoEdit->setObjectName(QString::fromUtf8("recordNoEdit"));
        recordNoEdit->setEnabled(false);
        sizePolicy2.setHeightForWidth(recordNoEdit->sizePolicy().hasHeightForWidth());
        recordNoEdit->setSizePolicy(sizePolicy2);
        recordNoEdit->setMinimumSize(QSize(60, 0));
        recordNoEdit->setMaximumSize(QSize(60, 16777215));

        verticalLayout_5->addWidget(recordNoEdit);

        telEdit = new QLineEdit(HospitalisationRegistry);
        telEdit->setObjectName(QString::fromUtf8("telEdit"));
        sizePolicy2.setHeightForWidth(telEdit->sizePolicy().hasHeightForWidth());
        telEdit->setSizePolicy(sizePolicy2);
        telEdit->setMaximumSize(QSize(60, 16777215));

        verticalLayout_5->addWidget(telEdit);

        doctorEdit = new QLineEdit(HospitalisationRegistry);
        doctorEdit->setObjectName(QString::fromUtf8("doctorEdit"));
        sizePolicy2.setHeightForWidth(doctorEdit->sizePolicy().hasHeightForWidth());
        doctorEdit->setSizePolicy(sizePolicy2);
        doctorEdit->setMaximumSize(QSize(60, 16777215));

        verticalLayout_5->addWidget(doctorEdit);


        horizontalLayout_5->addLayout(verticalLayout_5);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        label_4 = new QLabel(HospitalisationRegistry);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        sizePolicy1.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy1);

        verticalLayout_6->addWidget(label_4);

        label_8 = new QLabel(HospitalisationRegistry);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        sizePolicy1.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy1);

        verticalLayout_6->addWidget(label_8);

        label_14 = new QLabel(HospitalisationRegistry);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        verticalLayout_6->addWidget(label_14);


        horizontalLayout_5->addLayout(verticalLayout_6);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        nameEdit = new QLineEdit(HospitalisationRegistry);
        nameEdit->setObjectName(QString::fromUtf8("nameEdit"));
        sizePolicy2.setHeightForWidth(nameEdit->sizePolicy().hasHeightForWidth());
        nameEdit->setSizePolicy(sizePolicy2);
        nameEdit->setMaximumSize(QSize(60, 16777215));

        verticalLayout_7->addWidget(nameEdit);

        IDEdit = new QLineEdit(HospitalisationRegistry);
        IDEdit->setObjectName(QString::fromUtf8("IDEdit"));
        sizePolicy2.setHeightForWidth(IDEdit->sizePolicy().hasHeightForWidth());
        IDEdit->setSizePolicy(sizePolicy2);
        IDEdit->setMaximumSize(QSize(60, 16777215));

        verticalLayout_7->addWidget(IDEdit);

        feetypecomboBox = new QComboBox(HospitalisationRegistry);
        feetypecomboBox->setObjectName(QString::fromUtf8("feetypecomboBox"));
        sizePolicy2.setHeightForWidth(feetypecomboBox->sizePolicy().hasHeightForWidth());
        feetypecomboBox->setSizePolicy(sizePolicy2);
        feetypecomboBox->setMaximumSize(QSize(60, 16777215));

        verticalLayout_7->addWidget(feetypecomboBox);


        horizontalLayout_5->addLayout(verticalLayout_7);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_7 = new QLabel(HospitalisationRegistry);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        sizePolicy1.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(label_7);

        ageEdit = new QLineEdit(HospitalisationRegistry);
        ageEdit->setObjectName(QString::fromUtf8("ageEdit"));
        sizePolicy.setHeightForWidth(ageEdit->sizePolicy().hasHeightForWidth());
        ageEdit->setSizePolicy(sizePolicy);
        ageEdit->setMaximumSize(QSize(60, 16777215));

        horizontalLayout_2->addWidget(ageEdit);

        label_6 = new QLabel(HospitalisationRegistry);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        sizePolicy1.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(label_6);

        gendercomboBox = new QComboBox(HospitalisationRegistry);
        gendercomboBox->setObjectName(QString::fromUtf8("gendercomboBox"));
        sizePolicy.setHeightForWidth(gendercomboBox->sizePolicy().hasHeightForWidth());
        gendercomboBox->setSizePolicy(sizePolicy);
        gendercomboBox->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_2->addWidget(gendercomboBox);

        label_3 = new QLabel(HospitalisationRegistry);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy1.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(label_3);

        dateTimeEdit = new QDateTimeEdit(HospitalisationRegistry);
        dateTimeEdit->setObjectName(QString::fromUtf8("dateTimeEdit"));
        sizePolicy.setHeightForWidth(dateTimeEdit->sizePolicy().hasHeightForWidth());
        dateTimeEdit->setSizePolicy(sizePolicy);
        dateTimeEdit->setMaximumSize(QSize(200, 16777215));

        horizontalLayout_2->addWidget(dateTimeEdit);


        verticalLayout_8->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_9 = new QLabel(HospitalisationRegistry);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        sizePolicy1.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy1);

        horizontalLayout_3->addWidget(label_9);

        addressEdit = new QLineEdit(HospitalisationRegistry);
        addressEdit->setObjectName(QString::fromUtf8("addressEdit"));
        sizePolicy2.setHeightForWidth(addressEdit->sizePolicy().hasHeightForWidth());
        addressEdit->setSizePolicy(sizePolicy2);
        addressEdit->setMaximumSize(QSize(900, 16777215));

        horizontalLayout_3->addWidget(addressEdit);


        verticalLayout_8->addLayout(horizontalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_16 = new QLabel(HospitalisationRegistry);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        horizontalLayout->addWidget(label_16);

        bedEdit = new QLineEdit(HospitalisationRegistry);
        bedEdit->setObjectName(QString::fromUtf8("bedEdit"));
        sizePolicy.setHeightForWidth(bedEdit->sizePolicy().hasHeightForWidth());
        bedEdit->setSizePolicy(sizePolicy);
        bedEdit->setMaximumSize(QSize(60, 16777215));

        horizontalLayout->addWidget(bedEdit);

        label_15 = new QLabel(HospitalisationRegistry);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        horizontalLayout->addWidget(label_15);

        nursinglevelcomboBox = new QComboBox(HospitalisationRegistry);
        nursinglevelcomboBox->setObjectName(QString::fromUtf8("nursinglevelcomboBox"));
        sizePolicy.setHeightForWidth(nursinglevelcomboBox->sizePolicy().hasHeightForWidth());
        nursinglevelcomboBox->setSizePolicy(sizePolicy);
        nursinglevelcomboBox->setMaximumSize(QSize(100, 16777215));

        horizontalLayout->addWidget(nursinglevelcomboBox);

        label_23 = new QLabel(HospitalisationRegistry);
        label_23->setObjectName(QString::fromUtf8("label_23"));

        horizontalLayout->addWidget(label_23);

        cooperativemedicalNoEdit = new QLineEdit(HospitalisationRegistry);
        cooperativemedicalNoEdit->setObjectName(QString::fromUtf8("cooperativemedicalNoEdit"));
        sizePolicy.setHeightForWidth(cooperativemedicalNoEdit->sizePolicy().hasHeightForWidth());
        cooperativemedicalNoEdit->setSizePolicy(sizePolicy);
        cooperativemedicalNoEdit->setMinimumSize(QSize(60, 0));
        cooperativemedicalNoEdit->setMaximumSize(QSize(60, 16777215));

        horizontalLayout->addWidget(cooperativemedicalNoEdit);

        label_22 = new QLabel(HospitalisationRegistry);
        label_22->setObjectName(QString::fromUtf8("label_22"));

        horizontalLayout->addWidget(label_22);

        certificateNoEdit = new QLineEdit(HospitalisationRegistry);
        certificateNoEdit->setObjectName(QString::fromUtf8("certificateNoEdit"));
        sizePolicy.setHeightForWidth(certificateNoEdit->sizePolicy().hasHeightForWidth());
        certificateNoEdit->setSizePolicy(sizePolicy);
        certificateNoEdit->setMaximumSize(QSize(60, 16777215));

        horizontalLayout->addWidget(certificateNoEdit);


        verticalLayout_8->addLayout(horizontalLayout);


        horizontalLayout_5->addLayout(verticalLayout_8);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);


        verticalLayout_9->addLayout(horizontalLayout_5);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label_17 = new QLabel(HospitalisationRegistry);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        horizontalLayout_10->addWidget(label_17);

        label_5 = new QLabel(HospitalisationRegistry);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_10->addWidget(label_5);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_3);


        verticalLayout_3->addLayout(horizontalLayout_10);

        diagnosisEdit = new QTextEdit(HospitalisationRegistry);
        diagnosisEdit->setObjectName(QString::fromUtf8("diagnosisEdit"));

        verticalLayout_3->addWidget(diagnosisEdit);


        verticalLayout_9->addLayout(verticalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_18 = new QLabel(HospitalisationRegistry);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        horizontalLayout_4->addWidget(label_18);

        minimumEdit = new QLineEdit(HospitalisationRegistry);
        minimumEdit->setObjectName(QString::fromUtf8("minimumEdit"));
        minimumEdit->setMaximumSize(QSize(60, 16777215));

        horizontalLayout_4->addWidget(minimumEdit);

        label_19 = new QLabel(HospitalisationRegistry);
        label_19->setObjectName(QString::fromUtf8("label_19"));

        horizontalLayout_4->addWidget(label_19);

        sheetmakerEdit = new QLineEdit(HospitalisationRegistry);
        sheetmakerEdit->setObjectName(QString::fromUtf8("sheetmakerEdit"));
        sheetmakerEdit->setMaximumSize(QSize(60, 16777215));

        horizontalLayout_4->addWidget(sheetmakerEdit);

        label_21 = new QLabel(HospitalisationRegistry);
        label_21->setObjectName(QString::fromUtf8("label_21"));

        horizontalLayout_4->addWidget(label_21);

        statusEdit = new QLineEdit(HospitalisationRegistry);
        statusEdit->setObjectName(QString::fromUtf8("statusEdit"));
        statusEdit->setEnabled(false);
        statusEdit->setMaximumSize(QSize(60, 16777215));

        horizontalLayout_4->addWidget(statusEdit);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_6);


        verticalLayout_9->addLayout(horizontalLayout_4);

        QWidget::setTabOrder(hospitalisationNoEdit, recordNoEdit);
        QWidget::setTabOrder(recordNoEdit, nameEdit);
        QWidget::setTabOrder(nameEdit, gendercomboBox);
        QWidget::setTabOrder(gendercomboBox, contactEdit);
        QWidget::setTabOrder(contactEdit, telEdit);
        QWidget::setTabOrder(telEdit, IDEdit);
        QWidget::setTabOrder(IDEdit, addressEdit);
        QWidget::setTabOrder(addressEdit, departmentcomboBox);
        QWidget::setTabOrder(departmentcomboBox, doctorEdit);
        QWidget::setTabOrder(doctorEdit, feetypecomboBox);
        QWidget::setTabOrder(feetypecomboBox, bedEdit);
        QWidget::setTabOrder(bedEdit, nursinglevelcomboBox);
        QWidget::setTabOrder(nursinglevelcomboBox, cooperativemedicalNoEdit);
        QWidget::setTabOrder(cooperativemedicalNoEdit, certificateNoEdit);
        QWidget::setTabOrder(certificateNoEdit, diagnosisEdit);
        QWidget::setTabOrder(diagnosisEdit, minimumEdit);
        QWidget::setTabOrder(minimumEdit, sheetmakerEdit);
        QWidget::setTabOrder(sheetmakerEdit, statusEdit);
        QWidget::setTabOrder(statusEdit, addButton);
        QWidget::setTabOrder(addButton, editButton);
        QWidget::setTabOrder(editButton, deleteButton);
        QWidget::setTabOrder(deleteButton, discardButton);
        QWidget::setTabOrder(discardButton, saveButton);

        retranslateUi(HospitalisationRegistry);

        QMetaObject::connectSlotsByName(HospitalisationRegistry);
    } // setupUi

    void retranslateUi(QWidget *HospitalisationRegistry)
    {
        HospitalisationRegistry->setWindowTitle(QApplication::translate("HospitalisationRegistry", "\344\275\217\351\231\242\347\231\273\350\256\260", 0, QApplication::UnicodeUTF8));
        addButton->setText(QApplication::translate("HospitalisationRegistry", "\346\226\260\345\242\236", 0, QApplication::UnicodeUTF8));
        editButton->setText(QApplication::translate("HospitalisationRegistry", "\344\277\256\346\224\271", 0, QApplication::UnicodeUTF8));
        deleteButton->setText(QApplication::translate("HospitalisationRegistry", "\345\210\240\351\231\244", 0, QApplication::UnicodeUTF8));
        discardButton->setText(QApplication::translate("HospitalisationRegistry", "\346\224\276\345\274\203", 0, QApplication::UnicodeUTF8));
        saveButton->setText(QApplication::translate("HospitalisationRegistry", "\344\277\235\345\255\230", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("HospitalisationRegistry", "\344\275\217\351\231\242\345\217\267\357\274\232  ", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("HospitalisationRegistry", "\350\201\224\347\263\273\344\272\272\357\274\232  ", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("HospitalisationRegistry", "\344\275\217\351\231\242\347\247\221\345\256\244\357\274\232", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("HospitalisationRegistry", "\347\227\205\345\216\206\345\217\267\357\274\232  ", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("HospitalisationRegistry", "\350\201\224\347\263\273\346\226\271\345\274\217\357\274\232", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("HospitalisationRegistry", "\344\270\273\346\262\273\345\214\273\347\224\237\357\274\232", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("HospitalisationRegistry", "\345\247\223\345\220\215\357\274\232    ", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("HospitalisationRegistry", "\350\272\253\344\273\275\350\257\201\345\217\267\357\274\232", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("HospitalisationRegistry", "\350\264\271\347\224\250\347\261\273\345\210\253\357\274\232", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("HospitalisationRegistry", "\345\271\264\351\276\204\357\274\232    ", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("HospitalisationRegistry", "\346\200\247\345\210\253\357\274\232", 0, QApplication::UnicodeUTF8));
        gendercomboBox->clear();
        gendercomboBox->insertItems(0, QStringList()
         << QApplication::translate("HospitalisationRegistry", "\347\224\267", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("HospitalisationRegistry", "\345\245\263", 0, QApplication::UnicodeUTF8)
        );
        label_3->setText(QApplication::translate("HospitalisationRegistry", "\347\231\273\350\256\260\346\227\245\346\234\237\357\274\232", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("HospitalisationRegistry", "\345\234\260\345\235\200\357\274\232    ", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("HospitalisationRegistry", "\345\205\245\351\231\242\345\272\212\344\275\215\357\274\232", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("HospitalisationRegistry", "\346\212\244\347\220\206\347\272\247\345\210\253\357\274\232", 0, QApplication::UnicodeUTF8));
        label_23->setText(QApplication::translate("HospitalisationRegistry", "\345\217\202\345\220\210\350\257\201\345\217\267\357\274\232", 0, QApplication::UnicodeUTF8));
        label_22->setText(QApplication::translate("HospitalisationRegistry", "\345\214\273\347\226\227\350\257\201\345\217\267\357\274\232", 0, QApplication::UnicodeUTF8));
        label_17->setText(QApplication::translate("HospitalisationRegistry", "\350\257\212\346\226\255\347\273\223\346\236\234\357\274\232", 0, QApplication::UnicodeUTF8));
        label_5->setText(QString());
        label_18->setText(QApplication::translate("HospitalisationRegistry", "\346\234\200\344\275\216\346\212\274\351\207\221\357\274\232", 0, QApplication::UnicodeUTF8));
        label_19->setText(QApplication::translate("HospitalisationRegistry", "\345\210\266\345\215\225\357\274\232", 0, QApplication::UnicodeUTF8));
        label_21->setText(QApplication::translate("HospitalisationRegistry", "\347\212\266\346\200\201\357\274\232", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class HospitalisationRegistry: public Ui_HospitalisationRegistry {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOSPITALISATIONREGISTRY_H
