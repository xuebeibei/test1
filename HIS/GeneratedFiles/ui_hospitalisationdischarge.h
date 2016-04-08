/********************************************************************************
** Form generated from reading UI file 'hospitalisationdischarge.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOSPITALISATIONDISCHARGE_H
#define UI_HOSPITALISATIONDISCHARGE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDateTimeEdit>
#include <QtGui/QFrame>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTabWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HospitalisationDischarge
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QFrame *line;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_17;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label;
    QLineEdit *hospitalisationNoEdit;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_2;
    QLineEdit *patientEdit;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_8;
    QLineEdit *recordNoEdit;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_6;
    QLineEdit *genderEdit;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_7;
    QLineEdit *ageEdit;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_14;
    QLineEdit *typeEdit;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_3;
    QLineEdit *registrydateEdit;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_5;
    QDateTimeEdit *outTimeEdit;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_12;
    QLineEdit *departmentEdit;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_13;
    QLineEdit *doctorEdit;
    QHBoxLayout *horizontalLayout_15;
    QLabel *label_4;
    QLineEdit *sheetmakerEdit;
    QHBoxLayout *horizontalLayout_16;
    QLabel *label_15;
    QLineEdit *nursinglevelEdit;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *refundButton;
    QPushButton *supplementButton;
    QPushButton *printButton;
    QPushButton *applyButton;
    QPushButton *quitButton;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_7;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_18;
    QHBoxLayout *horizontalLayout;
    QLabel *label_16;
    QLineEdit *totalpayEdit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_17;
    QLineEdit *totalfeeEdit;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_21;
    QLineEdit *balanceEdit;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer;
    QLabel *hintlabel;
    QWidget *widget;
    QLabel *label_24;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_19;
    QLabel *label_22;
    QLineEdit *hospitalisationNoEdit_2;
    QHBoxLayout *horizontalLayout_20;
    QLabel *label_23;
    QLineEdit *patientEdit_2;
    QHBoxLayout *horizontalLayout_21;
    QLabel *label_9;
    QLineEdit *genderEdit_2;
    QHBoxLayout *horizontalLayout_22;
    QLabel *label_10;
    QLineEdit *ageEdit_2;
    QHBoxLayout *horizontalLayout_23;
    QLabel *label_11;
    QLineEdit *registrydateEdit_2;
    QHBoxLayout *horizontalLayout_24;
    QLabel *label_20;
    QLineEdit *doctorEdit_2;
    QHBoxLayout *horizontalLayout_25;
    QLabel *label_19;
    QLineEdit *departmentEdit_2;
    QHBoxLayout *horizontalLayout_26;
    QLabel *label_18;
    QLineEdit *typeEdit_2;
    QHBoxLayout *horizontalLayout_27;
    QLabel *label_26;
    QLineEdit *nursinglevelEdit_2;
    QLabel *label_25;
    QFrame *line_2;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_28;
    QPushButton *recallButton;
    QPushButton *cancelButton;

    void setupUi(QWidget *HospitalisationDischarge)
    {
        if (HospitalisationDischarge->objectName().isEmpty())
            HospitalisationDischarge->setObjectName(QString::fromUtf8("HospitalisationDischarge"));
        HospitalisationDischarge->resize(892, 499);
        verticalLayout = new QVBoxLayout(HospitalisationDischarge);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tabWidget = new QTabWidget(HospitalisationDischarge);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        line = new QFrame(tab);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(10, 340, 541, 20));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        groupBox_2 = new QGroupBox(tab);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 10, 531, 184));
        horizontalLayout_17 = new QHBoxLayout(groupBox_2);
        horizontalLayout_17->setSpacing(6);
        horizontalLayout_17->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_17->setObjectName(QString::fromUtf8("horizontalLayout_17"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_5->addWidget(label);

        hospitalisationNoEdit = new QLineEdit(groupBox_2);
        hospitalisationNoEdit->setObjectName(QString::fromUtf8("hospitalisationNoEdit"));

        horizontalLayout_5->addWidget(hospitalisationNoEdit);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_6->addWidget(label_2);

        patientEdit = new QLineEdit(groupBox_2);
        patientEdit->setObjectName(QString::fromUtf8("patientEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(patientEdit->sizePolicy().hasHeightForWidth());
        patientEdit->setSizePolicy(sizePolicy);

        horizontalLayout_6->addWidget(patientEdit);


        verticalLayout_2->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_7->addWidget(label_8);

        recordNoEdit = new QLineEdit(groupBox_2);
        recordNoEdit->setObjectName(QString::fromUtf8("recordNoEdit"));
        recordNoEdit->setEnabled(false);
        sizePolicy.setHeightForWidth(recordNoEdit->sizePolicy().hasHeightForWidth());
        recordNoEdit->setSizePolicy(sizePolicy);

        horizontalLayout_7->addWidget(recordNoEdit);


        verticalLayout_2->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_8->addWidget(label_6);

        genderEdit = new QLineEdit(groupBox_2);
        genderEdit->setObjectName(QString::fromUtf8("genderEdit"));
        genderEdit->setEnabled(false);
        sizePolicy.setHeightForWidth(genderEdit->sizePolicy().hasHeightForWidth());
        genderEdit->setSizePolicy(sizePolicy);

        horizontalLayout_8->addWidget(genderEdit);


        verticalLayout_2->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_9->addWidget(label_7);

        ageEdit = new QLineEdit(groupBox_2);
        ageEdit->setObjectName(QString::fromUtf8("ageEdit"));
        ageEdit->setEnabled(false);
        sizePolicy.setHeightForWidth(ageEdit->sizePolicy().hasHeightForWidth());
        ageEdit->setSizePolicy(sizePolicy);

        horizontalLayout_9->addWidget(ageEdit);


        verticalLayout_2->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label_14 = new QLabel(groupBox_2);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        horizontalLayout_10->addWidget(label_14);

        typeEdit = new QLineEdit(groupBox_2);
        typeEdit->setObjectName(QString::fromUtf8("typeEdit"));
        typeEdit->setEnabled(false);
        sizePolicy.setHeightForWidth(typeEdit->sizePolicy().hasHeightForWidth());
        typeEdit->setSizePolicy(sizePolicy);

        horizontalLayout_10->addWidget(typeEdit);


        verticalLayout_2->addLayout(horizontalLayout_10);


        horizontalLayout_17->addLayout(verticalLayout_2);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_11->addWidget(label_3);

        registrydateEdit = new QLineEdit(groupBox_2);
        registrydateEdit->setObjectName(QString::fromUtf8("registrydateEdit"));
        registrydateEdit->setEnabled(false);

        horizontalLayout_11->addWidget(registrydateEdit);


        verticalLayout_5->addLayout(horizontalLayout_11);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_12->addWidget(label_5);

        outTimeEdit = new QDateTimeEdit(groupBox_2);
        outTimeEdit->setObjectName(QString::fromUtf8("outTimeEdit"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(outTimeEdit->sizePolicy().hasHeightForWidth());
        outTimeEdit->setSizePolicy(sizePolicy1);

        horizontalLayout_12->addWidget(outTimeEdit);


        verticalLayout_5->addLayout(horizontalLayout_12);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        label_12 = new QLabel(groupBox_2);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        horizontalLayout_13->addWidget(label_12);

        departmentEdit = new QLineEdit(groupBox_2);
        departmentEdit->setObjectName(QString::fromUtf8("departmentEdit"));
        departmentEdit->setEnabled(false);
        sizePolicy.setHeightForWidth(departmentEdit->sizePolicy().hasHeightForWidth());
        departmentEdit->setSizePolicy(sizePolicy);

        horizontalLayout_13->addWidget(departmentEdit);


        verticalLayout_5->addLayout(horizontalLayout_13);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        label_13 = new QLabel(groupBox_2);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        horizontalLayout_14->addWidget(label_13);

        doctorEdit = new QLineEdit(groupBox_2);
        doctorEdit->setObjectName(QString::fromUtf8("doctorEdit"));
        doctorEdit->setEnabled(false);
        sizePolicy.setHeightForWidth(doctorEdit->sizePolicy().hasHeightForWidth());
        doctorEdit->setSizePolicy(sizePolicy);

        horizontalLayout_14->addWidget(doctorEdit);


        verticalLayout_5->addLayout(horizontalLayout_14);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setSpacing(6);
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy2);

        horizontalLayout_15->addWidget(label_4);

        sheetmakerEdit = new QLineEdit(groupBox_2);
        sheetmakerEdit->setObjectName(QString::fromUtf8("sheetmakerEdit"));
        sheetmakerEdit->setEnabled(false);
        sizePolicy.setHeightForWidth(sheetmakerEdit->sizePolicy().hasHeightForWidth());
        sheetmakerEdit->setSizePolicy(sizePolicy);

        horizontalLayout_15->addWidget(sheetmakerEdit);


        verticalLayout_5->addLayout(horizontalLayout_15);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setSpacing(6);
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        label_15 = new QLabel(groupBox_2);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        horizontalLayout_16->addWidget(label_15);

        nursinglevelEdit = new QLineEdit(groupBox_2);
        nursinglevelEdit->setObjectName(QString::fromUtf8("nursinglevelEdit"));
        nursinglevelEdit->setEnabled(false);
        sizePolicy.setHeightForWidth(nursinglevelEdit->sizePolicy().hasHeightForWidth());
        nursinglevelEdit->setSizePolicy(sizePolicy);

        horizontalLayout_16->addWidget(nursinglevelEdit);


        verticalLayout_5->addLayout(horizontalLayout_16);


        horizontalLayout_17->addLayout(verticalLayout_5);

        layoutWidget = new QWidget(tab);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(140, 370, 414, 30));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        refundButton = new QPushButton(layoutWidget);
        refundButton->setObjectName(QString::fromUtf8("refundButton"));
        QFont font;
        font.setFamily(QString::fromUtf8("Agency FB"));
        font.setPointSize(12);
        refundButton->setFont(font);

        horizontalLayout_2->addWidget(refundButton);

        supplementButton = new QPushButton(layoutWidget);
        supplementButton->setObjectName(QString::fromUtf8("supplementButton"));
        supplementButton->setFont(font);

        horizontalLayout_2->addWidget(supplementButton);

        printButton = new QPushButton(layoutWidget);
        printButton->setObjectName(QString::fromUtf8("printButton"));
        printButton->setFont(font);

        horizontalLayout_2->addWidget(printButton);

        applyButton = new QPushButton(layoutWidget);
        applyButton->setObjectName(QString::fromUtf8("applyButton"));
        applyButton->setFont(font);

        horizontalLayout_2->addWidget(applyButton);

        quitButton = new QPushButton(layoutWidget);
        quitButton->setObjectName(QString::fromUtf8("quitButton"));
        quitButton->setFont(font);

        horizontalLayout_2->addWidget(quitButton);

        groupBox_3 = new QGroupBox(tab);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 210, 531, 111));
        verticalLayout_7 = new QVBoxLayout(groupBox_3);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setSpacing(6);
        horizontalLayout_18->setObjectName(QString::fromUtf8("horizontalLayout_18"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_16 = new QLabel(groupBox_3);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        horizontalLayout->addWidget(label_16);

        totalpayEdit = new QLineEdit(groupBox_3);
        totalpayEdit->setObjectName(QString::fromUtf8("totalpayEdit"));
        totalpayEdit->setEnabled(false);
        sizePolicy.setHeightForWidth(totalpayEdit->sizePolicy().hasHeightForWidth());
        totalpayEdit->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(totalpayEdit);


        horizontalLayout_18->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_17 = new QLabel(groupBox_3);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        horizontalLayout_3->addWidget(label_17);

        totalfeeEdit = new QLineEdit(groupBox_3);
        totalfeeEdit->setObjectName(QString::fromUtf8("totalfeeEdit"));
        totalfeeEdit->setEnabled(false);
        sizePolicy.setHeightForWidth(totalfeeEdit->sizePolicy().hasHeightForWidth());
        totalfeeEdit->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(totalfeeEdit);


        horizontalLayout_18->addLayout(horizontalLayout_3);


        verticalLayout_6->addLayout(horizontalLayout_18);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_21 = new QLabel(groupBox_3);
        label_21->setObjectName(QString::fromUtf8("label_21"));

        horizontalLayout_4->addWidget(label_21);

        balanceEdit = new QLineEdit(groupBox_3);
        balanceEdit->setObjectName(QString::fromUtf8("balanceEdit"));
        balanceEdit->setEnabled(false);
        sizePolicy.setHeightForWidth(balanceEdit->sizePolicy().hasHeightForWidth());
        balanceEdit->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(balanceEdit);

        horizontalSpacer_2 = new QSpacerItem(70, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);


        verticalLayout_6->addLayout(horizontalLayout_4);


        verticalLayout_7->addLayout(verticalLayout_6);

        hintlabel = new QLabel(groupBox_3);
        hintlabel->setObjectName(QString::fromUtf8("hintlabel"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(hintlabel->sizePolicy().hasHeightForWidth());
        hintlabel->setSizePolicy(sizePolicy3);

        verticalLayout_7->addWidget(hintlabel);

        tabWidget->addTab(tab, QString());
        widget = new QWidget();
        widget->setObjectName(QString::fromUtf8("widget"));
        label_24 = new QLabel(widget);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setGeometry(QRect(9, 315, 16, 16));
        groupBox = new QGroupBox(widget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 261, 266));
        verticalLayout_3 = new QVBoxLayout(groupBox);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setSpacing(6);
        horizontalLayout_19->setObjectName(QString::fromUtf8("horizontalLayout_19"));
        label_22 = new QLabel(groupBox);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        sizePolicy2.setHeightForWidth(label_22->sizePolicy().hasHeightForWidth());
        label_22->setSizePolicy(sizePolicy2);

        horizontalLayout_19->addWidget(label_22);

        hospitalisationNoEdit_2 = new QLineEdit(groupBox);
        hospitalisationNoEdit_2->setObjectName(QString::fromUtf8("hospitalisationNoEdit_2"));

        horizontalLayout_19->addWidget(hospitalisationNoEdit_2);


        verticalLayout_3->addLayout(horizontalLayout_19);

        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setSpacing(6);
        horizontalLayout_20->setObjectName(QString::fromUtf8("horizontalLayout_20"));
        label_23 = new QLabel(groupBox);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        sizePolicy2.setHeightForWidth(label_23->sizePolicy().hasHeightForWidth());
        label_23->setSizePolicy(sizePolicy2);

        horizontalLayout_20->addWidget(label_23);

        patientEdit_2 = new QLineEdit(groupBox);
        patientEdit_2->setObjectName(QString::fromUtf8("patientEdit_2"));
        sizePolicy.setHeightForWidth(patientEdit_2->sizePolicy().hasHeightForWidth());
        patientEdit_2->setSizePolicy(sizePolicy);

        horizontalLayout_20->addWidget(patientEdit_2);


        verticalLayout_3->addLayout(horizontalLayout_20);

        horizontalLayout_21 = new QHBoxLayout();
        horizontalLayout_21->setSpacing(6);
        horizontalLayout_21->setObjectName(QString::fromUtf8("horizontalLayout_21"));
        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_21->addWidget(label_9);

        genderEdit_2 = new QLineEdit(groupBox);
        genderEdit_2->setObjectName(QString::fromUtf8("genderEdit_2"));
        genderEdit_2->setEnabled(false);
        sizePolicy.setHeightForWidth(genderEdit_2->sizePolicy().hasHeightForWidth());
        genderEdit_2->setSizePolicy(sizePolicy);

        horizontalLayout_21->addWidget(genderEdit_2);


        verticalLayout_3->addLayout(horizontalLayout_21);

        horizontalLayout_22 = new QHBoxLayout();
        horizontalLayout_22->setSpacing(6);
        horizontalLayout_22->setObjectName(QString::fromUtf8("horizontalLayout_22"));
        label_10 = new QLabel(groupBox);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        horizontalLayout_22->addWidget(label_10);

        ageEdit_2 = new QLineEdit(groupBox);
        ageEdit_2->setObjectName(QString::fromUtf8("ageEdit_2"));
        ageEdit_2->setEnabled(false);

        horizontalLayout_22->addWidget(ageEdit_2);


        verticalLayout_3->addLayout(horizontalLayout_22);

        horizontalLayout_23 = new QHBoxLayout();
        horizontalLayout_23->setSpacing(6);
        horizontalLayout_23->setObjectName(QString::fromUtf8("horizontalLayout_23"));
        label_11 = new QLabel(groupBox);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        sizePolicy2.setHeightForWidth(label_11->sizePolicy().hasHeightForWidth());
        label_11->setSizePolicy(sizePolicy2);

        horizontalLayout_23->addWidget(label_11);

        registrydateEdit_2 = new QLineEdit(groupBox);
        registrydateEdit_2->setObjectName(QString::fromUtf8("registrydateEdit_2"));
        registrydateEdit_2->setEnabled(false);

        horizontalLayout_23->addWidget(registrydateEdit_2);


        verticalLayout_3->addLayout(horizontalLayout_23);

        horizontalLayout_24 = new QHBoxLayout();
        horizontalLayout_24->setSpacing(6);
        horizontalLayout_24->setObjectName(QString::fromUtf8("horizontalLayout_24"));
        label_20 = new QLabel(groupBox);
        label_20->setObjectName(QString::fromUtf8("label_20"));

        horizontalLayout_24->addWidget(label_20);

        doctorEdit_2 = new QLineEdit(groupBox);
        doctorEdit_2->setObjectName(QString::fromUtf8("doctorEdit_2"));
        doctorEdit_2->setEnabled(false);
        sizePolicy.setHeightForWidth(doctorEdit_2->sizePolicy().hasHeightForWidth());
        doctorEdit_2->setSizePolicy(sizePolicy);

        horizontalLayout_24->addWidget(doctorEdit_2);


        verticalLayout_3->addLayout(horizontalLayout_24);

        horizontalLayout_25 = new QHBoxLayout();
        horizontalLayout_25->setSpacing(6);
        horizontalLayout_25->setObjectName(QString::fromUtf8("horizontalLayout_25"));
        label_19 = new QLabel(groupBox);
        label_19->setObjectName(QString::fromUtf8("label_19"));

        horizontalLayout_25->addWidget(label_19);

        departmentEdit_2 = new QLineEdit(groupBox);
        departmentEdit_2->setObjectName(QString::fromUtf8("departmentEdit_2"));
        departmentEdit_2->setEnabled(false);
        sizePolicy.setHeightForWidth(departmentEdit_2->sizePolicy().hasHeightForWidth());
        departmentEdit_2->setSizePolicy(sizePolicy);

        horizontalLayout_25->addWidget(departmentEdit_2);


        verticalLayout_3->addLayout(horizontalLayout_25);

        horizontalLayout_26 = new QHBoxLayout();
        horizontalLayout_26->setSpacing(6);
        horizontalLayout_26->setObjectName(QString::fromUtf8("horizontalLayout_26"));
        label_18 = new QLabel(groupBox);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        sizePolicy2.setHeightForWidth(label_18->sizePolicy().hasHeightForWidth());
        label_18->setSizePolicy(sizePolicy2);

        horizontalLayout_26->addWidget(label_18);

        typeEdit_2 = new QLineEdit(groupBox);
        typeEdit_2->setObjectName(QString::fromUtf8("typeEdit_2"));
        typeEdit_2->setEnabled(false);
        sizePolicy.setHeightForWidth(typeEdit_2->sizePolicy().hasHeightForWidth());
        typeEdit_2->setSizePolicy(sizePolicy);

        horizontalLayout_26->addWidget(typeEdit_2);


        verticalLayout_3->addLayout(horizontalLayout_26);

        horizontalLayout_27 = new QHBoxLayout();
        horizontalLayout_27->setSpacing(6);
        horizontalLayout_27->setObjectName(QString::fromUtf8("horizontalLayout_27"));
        label_26 = new QLabel(groupBox);
        label_26->setObjectName(QString::fromUtf8("label_26"));

        horizontalLayout_27->addWidget(label_26);

        nursinglevelEdit_2 = new QLineEdit(groupBox);
        nursinglevelEdit_2->setObjectName(QString::fromUtf8("nursinglevelEdit_2"));
        nursinglevelEdit_2->setEnabled(false);
        sizePolicy.setHeightForWidth(nursinglevelEdit_2->sizePolicy().hasHeightForWidth());
        nursinglevelEdit_2->setSizePolicy(sizePolicy);

        horizontalLayout_27->addWidget(nursinglevelEdit_2);


        verticalLayout_3->addLayout(horizontalLayout_27);

        label_25 = new QLabel(widget);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setGeometry(QRect(137, 377, 16, 16));
        line_2 = new QFrame(widget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(0, 280, 281, 20));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        layoutWidget1 = new QWidget(widget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(110, 300, 158, 30));
        horizontalLayout_28 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_28->setSpacing(6);
        horizontalLayout_28->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_28->setObjectName(QString::fromUtf8("horizontalLayout_28"));
        horizontalLayout_28->setContentsMargins(0, 0, 0, 0);
        recallButton = new QPushButton(layoutWidget1);
        recallButton->setObjectName(QString::fromUtf8("recallButton"));
        sizePolicy1.setHeightForWidth(recallButton->sizePolicy().hasHeightForWidth());
        recallButton->setSizePolicy(sizePolicy1);
        recallButton->setFont(font);

        horizontalLayout_28->addWidget(recallButton);

        cancelButton = new QPushButton(layoutWidget1);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setFont(font);

        horizontalLayout_28->addWidget(cancelButton);

        tabWidget->addTab(widget, QString());

        verticalLayout->addWidget(tabWidget);


        retranslateUi(HospitalisationDischarge);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(HospitalisationDischarge);
    } // setupUi

    void retranslateUi(QWidget *HospitalisationDischarge)
    {
        HospitalisationDischarge->setWindowTitle(QApplication::translate("HospitalisationDischarge", "HospitalisationDischarge", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QString());
        label->setText(QApplication::translate("HospitalisationDischarge", "\344\275\217\351\231\242\345\217\267\357\274\232  ", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("HospitalisationDischarge", "\347\224\263\350\257\267\344\272\272\357\274\232  ", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("HospitalisationDischarge", "\347\227\205\345\216\206\345\217\267\357\274\232  ", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("HospitalisationDischarge", "\346\200\247\345\210\253\357\274\232    ", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("HospitalisationDischarge", "\345\271\264\351\276\204\357\274\232    ", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("HospitalisationDischarge", "\350\264\271\347\224\250\347\261\273\345\210\253\357\274\232", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("HospitalisationDischarge", "\344\275\217\351\231\242\346\227\245\346\234\237\357\274\232", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("HospitalisationDischarge", "\345\207\272\351\231\242\346\227\245\346\234\237\357\274\232", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("HospitalisationDischarge", "\344\275\217\351\231\242\347\247\221\345\256\244\357\274\232", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("HospitalisationDischarge", "\344\270\273\346\262\273\345\214\273\347\224\237\357\274\232", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("HospitalisationDischarge", "\345\210\266\345\215\225\357\274\232    ", 0, QApplication::UnicodeUTF8));
        sheetmakerEdit->setText(QString());
        label_15->setText(QApplication::translate("HospitalisationDischarge", "\346\212\244\347\220\206\347\272\247\345\210\253\357\274\232", 0, QApplication::UnicodeUTF8));
        refundButton->setText(QApplication::translate("HospitalisationDischarge", "\345\207\272\351\231\242\351\200\200\346\254\276", 0, QApplication::UnicodeUTF8));
        supplementButton->setText(QApplication::translate("HospitalisationDischarge", "\345\207\272\351\231\242\350\241\245\346\254\276", 0, QApplication::UnicodeUTF8));
        printButton->setText(QApplication::translate("HospitalisationDischarge", "\346\211\223\345\215\260\347\273\223\347\256\227\345\215\225", 0, QApplication::UnicodeUTF8));
        applyButton->setText(QApplication::translate("HospitalisationDischarge", "\347\224\263\350\257\267\345\207\272\351\231\242", 0, QApplication::UnicodeUTF8));
        quitButton->setText(QApplication::translate("HospitalisationDischarge", "\351\207\215\347\275\256", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QString());
        label_16->setText(QApplication::translate("HospitalisationDischarge", "\347\264\257\350\256\241\344\272\244\346\254\276\357\274\232", 0, QApplication::UnicodeUTF8));
        label_17->setText(QApplication::translate("HospitalisationDischarge", "\347\264\257\350\256\241\346\266\210\350\264\271\357\274\232", 0, QApplication::UnicodeUTF8));
        label_21->setText(QApplication::translate("HospitalisationDischarge", "\345\275\223\345\211\215\344\275\231\351\242\235\357\274\232", 0, QApplication::UnicodeUTF8));
        hintlabel->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("HospitalisationDischarge", "\345\207\272\351\231\242\347\273\223\347\256\227", 0, QApplication::UnicodeUTF8));
        label_24->setText(QString());
        groupBox->setTitle(QString());
        label_22->setText(QApplication::translate("HospitalisationDischarge", "\344\275\217\351\231\242\345\217\267\357\274\232  ", 0, QApplication::UnicodeUTF8));
        label_23->setText(QApplication::translate("HospitalisationDischarge", "\347\224\263\350\257\267\344\272\272\357\274\232  ", 0, QApplication::UnicodeUTF8));
        patientEdit_2->setText(QString());
        label_9->setText(QApplication::translate("HospitalisationDischarge", "\346\200\247\345\210\253\357\274\232    ", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("HospitalisationDischarge", "\345\271\264\351\276\204\357\274\232    ", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("HospitalisationDischarge", "\344\275\217\351\231\242\346\227\245\346\234\237\357\274\232", 0, QApplication::UnicodeUTF8));
        label_20->setText(QApplication::translate("HospitalisationDischarge", "\344\270\273\346\262\273\345\214\273\347\224\237\357\274\232", 0, QApplication::UnicodeUTF8));
        label_19->setText(QApplication::translate("HospitalisationDischarge", "\344\275\217\351\231\242\347\247\221\345\256\244\357\274\232", 0, QApplication::UnicodeUTF8));
        label_18->setText(QApplication::translate("HospitalisationDischarge", "\350\264\271\347\224\250\347\261\273\345\210\253\357\274\232", 0, QApplication::UnicodeUTF8));
        label_26->setText(QApplication::translate("HospitalisationDischarge", "\346\212\244\347\220\206\347\272\247\345\210\253\357\274\232", 0, QApplication::UnicodeUTF8));
        label_25->setText(QString());
        recallButton->setText(QApplication::translate("HospitalisationDischarge", "\345\217\254\345\233\236", 0, QApplication::UnicodeUTF8));
        cancelButton->setText(QApplication::translate("HospitalisationDischarge", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(widget), QApplication::translate("HospitalisationDischarge", "\345\207\272\351\231\242\345\217\254\345\233\236", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class HospitalisationDischarge: public Ui_HospitalisationDischarge {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOSPITALISATIONDISCHARGE_H
