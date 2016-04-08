/********************************************************************************
** Form generated from reading UI file 'clinicstatistics.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLINICSTATISTICS_H
#define UI_CLINICSTATISTICS_H

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

class Ui_ClinicStatistics
{
public:
    QVBoxLayout *verticalLayout_2;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_14;
    QPushButton *queryButton;
    QPushButton *clearButton;
    QPushButton *previewButton;
    QPushButton *printButton;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_11;
    QLineEdit *patientEdit;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_9;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_10;
    QLineEdit *lineEdit_2;
    QRadioButton *radioButton;
    QDateTimeEdit *dateTimeEdit_3;
    QLabel *label_2;
    QDateTimeEdit *dateTimeEdit_4;
    QHBoxLayout *horizontalLayout_4;
    QTableWidget *tableWidget;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *queryButton_2;
    QPushButton *clearButton_2;
    QPushButton *previewButton_2;
    QPushButton *printButton_2;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_3;
    QRadioButton *radioButton_2;
    QDateTimeEdit *dateTimeEdit;
    QLabel *label_4;
    QDateTimeEdit *dateTimeEdit_2;
    QSpacerItem *horizontalSpacer_2;
    QTableWidget *tableWidget_2;
    QWidget *widget;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_29;
    QPushButton *queryButton_3;
    QPushButton *clearButton_3;
    QPushButton *previewButton_3;
    QPushButton *printButton_3;
    QSpacerItem *horizontalSpacer_12;
    QHBoxLayout *horizontalLayout_30;
    QRadioButton *radioButton_4;
    QDateTimeEdit *dateTimeEdit_5;
    QLabel *label_24;
    QDateTimeEdit *dateTimeEdit_6;
    QHBoxLayout *horizontalLayout_31;
    QLabel *label_25;
    QComboBox *comboBox_9;
    QTableWidget *tableWidget_5;

    void setupUi(QWidget *ClinicStatistics)
    {
        if (ClinicStatistics->objectName().isEmpty())
            ClinicStatistics->setObjectName(QString::fromUtf8("ClinicStatistics"));
        ClinicStatistics->resize(1116, 470);
        verticalLayout_2 = new QVBoxLayout(ClinicStatistics);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        tabWidget = new QTabWidget(ClinicStatistics);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        verticalLayout = new QVBoxLayout(tab);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        queryButton = new QPushButton(tab);
        queryButton->setObjectName(QString::fromUtf8("queryButton"));
        QFont font;
        font.setFamily(QString::fromUtf8("Agency FB"));
        font.setPointSize(12);
        queryButton->setFont(font);

        horizontalLayout_14->addWidget(queryButton);

        clearButton = new QPushButton(tab);
        clearButton->setObjectName(QString::fromUtf8("clearButton"));
        clearButton->setFont(font);

        horizontalLayout_14->addWidget(clearButton);

        previewButton = new QPushButton(tab);
        previewButton->setObjectName(QString::fromUtf8("previewButton"));
        previewButton->setFont(font);

        horizontalLayout_14->addWidget(previewButton);

        printButton = new QPushButton(tab);
        printButton->setObjectName(QString::fromUtf8("printButton"));
        printButton->setFont(font);

        horizontalLayout_14->addWidget(printButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_14);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        label_11 = new QLabel(tab);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        horizontalLayout_12->addWidget(label_11);

        patientEdit = new QLineEdit(tab);
        patientEdit->setObjectName(QString::fromUtf8("patientEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(patientEdit->sizePolicy().hasHeightForWidth());
        patientEdit->setSizePolicy(sizePolicy);

        horizontalLayout_12->addWidget(patientEdit);


        horizontalLayout->addLayout(horizontalLayout_12);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label_9 = new QLabel(tab);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy1);

        horizontalLayout_10->addWidget(label_9);

        lineEdit = new QLineEdit(tab);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setEnabled(false);
        sizePolicy.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy);

        horizontalLayout_10->addWidget(lineEdit);


        horizontalLayout->addLayout(horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        label_10 = new QLabel(tab);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        sizePolicy1.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy1);

        horizontalLayout_11->addWidget(label_10);

        lineEdit_2 = new QLineEdit(tab);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setEnabled(false);
        sizePolicy.setHeightForWidth(lineEdit_2->sizePolicy().hasHeightForWidth());
        lineEdit_2->setSizePolicy(sizePolicy);

        horizontalLayout_11->addWidget(lineEdit_2);


        horizontalLayout->addLayout(horizontalLayout_11);

        radioButton = new QRadioButton(tab);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(radioButton->sizePolicy().hasHeightForWidth());
        radioButton->setSizePolicy(sizePolicy2);
        radioButton->setMaximumSize(QSize(82, 16777215));

        horizontalLayout->addWidget(radioButton);

        dateTimeEdit_3 = new QDateTimeEdit(tab);
        dateTimeEdit_3->setObjectName(QString::fromUtf8("dateTimeEdit_3"));
        dateTimeEdit_3->setEnabled(false);

        horizontalLayout->addWidget(dateTimeEdit_3);

        label_2 = new QLabel(tab);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setEnabled(false);
        label_2->setMaximumSize(QSize(6, 16777215));

        horizontalLayout->addWidget(label_2);

        dateTimeEdit_4 = new QDateTimeEdit(tab);
        dateTimeEdit_4->setObjectName(QString::fromUtf8("dateTimeEdit_4"));
        dateTimeEdit_4->setEnabled(false);

        horizontalLayout->addWidget(dateTimeEdit_4);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));

        horizontalLayout->addLayout(horizontalLayout_4);


        verticalLayout->addLayout(horizontalLayout);

        tableWidget = new QTableWidget(tab);
        if (tableWidget->columnCount() < 11)
            tableWidget->setColumnCount(11);
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
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));

        verticalLayout->addWidget(tableWidget);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        verticalLayout_3 = new QVBoxLayout(tab_2);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        queryButton_2 = new QPushButton(tab_2);
        queryButton_2->setObjectName(QString::fromUtf8("queryButton_2"));
        queryButton_2->setFont(font);

        horizontalLayout_2->addWidget(queryButton_2);

        clearButton_2 = new QPushButton(tab_2);
        clearButton_2->setObjectName(QString::fromUtf8("clearButton_2"));
        clearButton_2->setFont(font);

        horizontalLayout_2->addWidget(clearButton_2);

        previewButton_2 = new QPushButton(tab_2);
        previewButton_2->setObjectName(QString::fromUtf8("previewButton_2"));
        previewButton_2->setFont(font);

        horizontalLayout_2->addWidget(previewButton_2);

        printButton_2 = new QPushButton(tab_2);
        printButton_2->setObjectName(QString::fromUtf8("printButton_2"));
        printButton_2->setFont(font);

        horizontalLayout_2->addWidget(printButton_2);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);


        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        radioButton_2 = new QRadioButton(tab_2);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));

        horizontalLayout_3->addWidget(radioButton_2);

        dateTimeEdit = new QDateTimeEdit(tab_2);
        dateTimeEdit->setObjectName(QString::fromUtf8("dateTimeEdit"));
        sizePolicy2.setHeightForWidth(dateTimeEdit->sizePolicy().hasHeightForWidth());
        dateTimeEdit->setSizePolicy(sizePolicy2);

        horizontalLayout_3->addWidget(dateTimeEdit);

        label_4 = new QLabel(tab_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_3->addWidget(label_4);

        dateTimeEdit_2 = new QDateTimeEdit(tab_2);
        dateTimeEdit_2->setObjectName(QString::fromUtf8("dateTimeEdit_2"));
        sizePolicy2.setHeightForWidth(dateTimeEdit_2->sizePolicy().hasHeightForWidth());
        dateTimeEdit_2->setSizePolicy(sizePolicy2);

        horizontalLayout_3->addWidget(dateTimeEdit_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        verticalLayout_3->addLayout(horizontalLayout_3);

        tableWidget_2 = new QTableWidget(tab_2);
        if (tableWidget_2->columnCount() < 5)
            tableWidget_2->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(0, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(1, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(2, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(3, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(4, __qtablewidgetitem15);
        tableWidget_2->setObjectName(QString::fromUtf8("tableWidget_2"));

        verticalLayout_3->addWidget(tableWidget_2);

        tabWidget->addTab(tab_2, QString());
        widget = new QWidget();
        widget->setObjectName(QString::fromUtf8("widget"));
        verticalLayout_6 = new QVBoxLayout(widget);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        horizontalLayout_29 = new QHBoxLayout();
        horizontalLayout_29->setSpacing(6);
        horizontalLayout_29->setObjectName(QString::fromUtf8("horizontalLayout_29"));
        queryButton_3 = new QPushButton(widget);
        queryButton_3->setObjectName(QString::fromUtf8("queryButton_3"));
        queryButton_3->setFont(font);

        horizontalLayout_29->addWidget(queryButton_3);

        clearButton_3 = new QPushButton(widget);
        clearButton_3->setObjectName(QString::fromUtf8("clearButton_3"));
        clearButton_3->setFont(font);

        horizontalLayout_29->addWidget(clearButton_3);

        previewButton_3 = new QPushButton(widget);
        previewButton_3->setObjectName(QString::fromUtf8("previewButton_3"));
        previewButton_3->setFont(font);

        horizontalLayout_29->addWidget(previewButton_3);

        printButton_3 = new QPushButton(widget);
        printButton_3->setObjectName(QString::fromUtf8("printButton_3"));
        printButton_3->setFont(font);

        horizontalLayout_29->addWidget(printButton_3);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_29->addItem(horizontalSpacer_12);


        verticalLayout_6->addLayout(horizontalLayout_29);

        horizontalLayout_30 = new QHBoxLayout();
        horizontalLayout_30->setSpacing(6);
        horizontalLayout_30->setObjectName(QString::fromUtf8("horizontalLayout_30"));
        radioButton_4 = new QRadioButton(widget);
        radioButton_4->setObjectName(QString::fromUtf8("radioButton_4"));

        horizontalLayout_30->addWidget(radioButton_4);

        dateTimeEdit_5 = new QDateTimeEdit(widget);
        dateTimeEdit_5->setObjectName(QString::fromUtf8("dateTimeEdit_5"));
        dateTimeEdit_5->setEnabled(false);
        sizePolicy2.setHeightForWidth(dateTimeEdit_5->sizePolicy().hasHeightForWidth());
        dateTimeEdit_5->setSizePolicy(sizePolicy2);

        horizontalLayout_30->addWidget(dateTimeEdit_5);

        label_24 = new QLabel(widget);
        label_24->setObjectName(QString::fromUtf8("label_24"));

        horizontalLayout_30->addWidget(label_24);

        dateTimeEdit_6 = new QDateTimeEdit(widget);
        dateTimeEdit_6->setObjectName(QString::fromUtf8("dateTimeEdit_6"));
        dateTimeEdit_6->setEnabled(false);
        sizePolicy2.setHeightForWidth(dateTimeEdit_6->sizePolicy().hasHeightForWidth());
        dateTimeEdit_6->setSizePolicy(sizePolicy2);

        horizontalLayout_30->addWidget(dateTimeEdit_6);

        horizontalLayout_31 = new QHBoxLayout();
        horizontalLayout_31->setSpacing(6);
        horizontalLayout_31->setObjectName(QString::fromUtf8("horizontalLayout_31"));
        label_25 = new QLabel(widget);
        label_25->setObjectName(QString::fromUtf8("label_25"));

        horizontalLayout_31->addWidget(label_25);

        comboBox_9 = new QComboBox(widget);
        comboBox_9->setObjectName(QString::fromUtf8("comboBox_9"));
        sizePolicy2.setHeightForWidth(comboBox_9->sizePolicy().hasHeightForWidth());
        comboBox_9->setSizePolicy(sizePolicy2);

        horizontalLayout_31->addWidget(comboBox_9);


        horizontalLayout_30->addLayout(horizontalLayout_31);


        verticalLayout_6->addLayout(horizontalLayout_30);

        tableWidget_5 = new QTableWidget(widget);
        if (tableWidget_5->columnCount() < 13)
            tableWidget_5->setColumnCount(13);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tableWidget_5->setHorizontalHeaderItem(0, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tableWidget_5->setHorizontalHeaderItem(1, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tableWidget_5->setHorizontalHeaderItem(2, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        tableWidget_5->setHorizontalHeaderItem(3, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        tableWidget_5->setHorizontalHeaderItem(4, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        tableWidget_5->setHorizontalHeaderItem(5, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        tableWidget_5->setHorizontalHeaderItem(6, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        tableWidget_5->setHorizontalHeaderItem(7, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        tableWidget_5->setHorizontalHeaderItem(8, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        tableWidget_5->setHorizontalHeaderItem(9, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        tableWidget_5->setHorizontalHeaderItem(10, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        tableWidget_5->setHorizontalHeaderItem(11, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        tableWidget_5->setHorizontalHeaderItem(12, __qtablewidgetitem28);
        tableWidget_5->setObjectName(QString::fromUtf8("tableWidget_5"));

        verticalLayout_6->addWidget(tableWidget_5);

        tabWidget->addTab(widget, QString());

        verticalLayout_2->addWidget(tabWidget);


        retranslateUi(ClinicStatistics);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ClinicStatistics);
    } // setupUi

    void retranslateUi(QWidget *ClinicStatistics)
    {
        ClinicStatistics->setWindowTitle(QApplication::translate("ClinicStatistics", "ClinicStatistics", 0, QApplication::UnicodeUTF8));
        queryButton->setText(QApplication::translate("ClinicStatistics", "\346\237\245\350\257\242", 0, QApplication::UnicodeUTF8));
        clearButton->setText(QApplication::translate("ClinicStatistics", "\346\270\205\345\261\217", 0, QApplication::UnicodeUTF8));
        previewButton->setText(QApplication::translate("ClinicStatistics", "\351\242\204\350\247\210", 0, QApplication::UnicodeUTF8));
        printButton->setText(QApplication::translate("ClinicStatistics", "\346\211\223\345\215\260", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("ClinicStatistics", "\347\227\205\344\272\272\345\247\223\345\220\215\357\274\232", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("ClinicStatistics", "\345\214\273\347\224\237\357\274\232", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("ClinicStatistics", "\347\247\221\345\256\244\357\274\232", 0, QApplication::UnicodeUTF8));
        radioButton->setText(QApplication::translate("ClinicStatistics", "\346\214\211\346\227\245\346\234\237\346\237\245\350\257\242", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ClinicStatistics", "-", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("ClinicStatistics", "\351\227\250\350\257\212\345\210\206\347\261\273", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("ClinicStatistics", "\345\274\200\347\245\250\346\227\245\346\234\237", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("ClinicStatistics", "\345\220\215\347\247\260", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("ClinicStatistics", "\346\225\260\351\207\217", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("ClinicStatistics", "\345\215\225\344\275\215", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("ClinicStatistics", "\345\215\225\344\273\267", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("ClinicStatistics", "\351\207\221\351\242\235", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QApplication::translate("ClinicStatistics", "\347\227\205\344\272\272\345\247\223\345\220\215", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QApplication::translate("ClinicStatistics", "\345\214\273\347\224\237", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->horizontalHeaderItem(9);
        ___qtablewidgetitem9->setText(QApplication::translate("ClinicStatistics", "\345\210\266\345\215\225", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget->horizontalHeaderItem(10);
        ___qtablewidgetitem10->setText(QApplication::translate("ClinicStatistics", "\345\215\225\345\217\267", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("ClinicStatistics", "\351\227\250\350\257\212\346\224\266\350\264\271\346\237\245\350\257\242", 0, QApplication::UnicodeUTF8));
        queryButton_2->setText(QApplication::translate("ClinicStatistics", "\346\237\245\350\257\242", 0, QApplication::UnicodeUTF8));
        clearButton_2->setText(QApplication::translate("ClinicStatistics", "\346\270\205\345\261\217", 0, QApplication::UnicodeUTF8));
        previewButton_2->setText(QApplication::translate("ClinicStatistics", "\351\242\204\350\247\210", 0, QApplication::UnicodeUTF8));
        printButton_2->setText(QApplication::translate("ClinicStatistics", "\346\211\223\345\215\260", 0, QApplication::UnicodeUTF8));
        radioButton_2->setText(QApplication::translate("ClinicStatistics", "\346\214\211\346\227\245\346\234\237\346\237\245\350\257\242", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("ClinicStatistics", "-", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget_2->horizontalHeaderItem(0);
        ___qtablewidgetitem11->setText(QApplication::translate("ClinicStatistics", "\345\215\225\345\217\267", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget_2->horizontalHeaderItem(1);
        ___qtablewidgetitem12->setText(QApplication::translate("ClinicStatistics", "\345\210\266\345\215\225\346\227\245\346\234\237", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget_2->horizontalHeaderItem(2);
        ___qtablewidgetitem13->setText(QApplication::translate("ClinicStatistics", "\345\210\266\345\215\225\345\221\230", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget_2->horizontalHeaderItem(3);
        ___qtablewidgetitem14->setText(QApplication::translate("ClinicStatistics", "\345\272\224\346\224\266\351\207\221\351\242\235", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidget_2->horizontalHeaderItem(4);
        ___qtablewidgetitem15->setText(QApplication::translate("ClinicStatistics", "\345\256\236\346\224\266\351\207\221\351\242\235", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("ClinicStatistics", "\346\227\245\347\273\223\346\237\245\350\257\242", 0, QApplication::UnicodeUTF8));
        queryButton_3->setText(QApplication::translate("ClinicStatistics", "\346\237\245\350\257\242", 0, QApplication::UnicodeUTF8));
        clearButton_3->setText(QApplication::translate("ClinicStatistics", "\346\270\205\345\261\217", 0, QApplication::UnicodeUTF8));
        previewButton_3->setText(QApplication::translate("ClinicStatistics", "\351\242\204\350\247\210", 0, QApplication::UnicodeUTF8));
        printButton_3->setText(QApplication::translate("ClinicStatistics", "\346\211\223\345\215\260", 0, QApplication::UnicodeUTF8));
        radioButton_4->setText(QApplication::translate("ClinicStatistics", "\346\214\211\346\227\245\346\234\237\346\237\245\350\257\242", 0, QApplication::UnicodeUTF8));
        label_24->setText(QApplication::translate("ClinicStatistics", "-", 0, QApplication::UnicodeUTF8));
        label_25->setText(QApplication::translate("ClinicStatistics", "\346\261\207\346\200\273\346\226\271\345\274\217\357\274\232", 0, QApplication::UnicodeUTF8));
        comboBox_9->clear();
        comboBox_9->insertItems(0, QStringList()
         << QApplication::translate("ClinicStatistics", "\351\227\250\350\257\212\346\224\266\346\215\256", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ClinicStatistics", "\347\247\221\345\256\244+\351\227\250\350\257\212\346\224\266\346\215\256", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ClinicStatistics", "\345\214\273\347\224\237+\351\227\250\350\257\212\346\224\266\346\215\256", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ClinicStatistics", "\345\210\266\345\215\225\344\272\272+\351\227\250\350\257\212\345\210\206\347\261\273", 0, QApplication::UnicodeUTF8)
        );
        tabWidget->setTabText(tabWidget->indexOf(widget), QApplication::translate("ClinicStatistics", "\351\241\271\347\233\256\346\237\245\350\257\242", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ClinicStatistics: public Ui_ClinicStatistics {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLINICSTATISTICS_H
