/********************************************************************************
** Form generated from reading UI file 'pharmacyinventory.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PHARMACYINVENTORY_H
#define UI_PHARMACYINVENTORY_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
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

class Ui_PharmacyInventory
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit_code;
    QPushButton *FindButton;
    QSpacerItem *horizontalSpacer;
    QTableWidget *tableWidget;

    void setupUi(QWidget *PharmacyInventory)
    {
        if (PharmacyInventory->objectName().isEmpty())
            PharmacyInventory->setObjectName(QString::fromUtf8("PharmacyInventory"));
        PharmacyInventory->resize(714, 362);
        verticalLayout = new QVBoxLayout(PharmacyInventory);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(PharmacyInventory);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lineEdit_code = new QLineEdit(PharmacyInventory);
        lineEdit_code->setObjectName(QString::fromUtf8("lineEdit_code"));
        lineEdit_code->setMaximumSize(QSize(120, 16777215));

        horizontalLayout->addWidget(lineEdit_code);

        FindButton = new QPushButton(PharmacyInventory);
        FindButton->setObjectName(QString::fromUtf8("FindButton"));
        FindButton->setMaximumSize(QSize(16777215, 23));
        QFont font;
        font.setFamily(QString::fromUtf8("Agency FB"));
        font.setPointSize(12);
        FindButton->setFont(font);

        horizontalLayout->addWidget(FindButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        tableWidget = new QTableWidget(PharmacyInventory);
        if (tableWidget->columnCount() < 7)
            tableWidget->setColumnCount(7);
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
        if (tableWidget->rowCount() < 1)
            tableWidget->setRowCount(1);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem7);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setSortingEnabled(true);
        tableWidget->verticalHeader()->setProperty("showSortIndicator", QVariant(false));
        tableWidget->verticalHeader()->setStretchLastSection(false);

        verticalLayout->addWidget(tableWidget);


        retranslateUi(PharmacyInventory);

        QMetaObject::connectSlotsByName(PharmacyInventory);
    } // setupUi

    void retranslateUi(QWidget *PharmacyInventory)
    {
        PharmacyInventory->setWindowTitle(QApplication::translate("PharmacyInventory", "\350\215\257\345\223\201\345\272\223\345\255\230", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("PharmacyInventory", "\350\215\257\345\223\201\345\220\215\347\247\260", 0, QApplication::UnicodeUTF8));
        FindButton->setText(QApplication::translate("PharmacyInventory", "\346\237\245\350\257\242\345\272\223\345\255\230", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("PharmacyInventory", "\345\220\215\347\247\260", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("PharmacyInventory", "\350\247\204\346\240\274", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("PharmacyInventory", "\347\224\237\344\272\247\345\216\202\345\225\206", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("PharmacyInventory", "\346\211\271\345\217\267", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("PharmacyInventory", "\345\215\225\344\275\215", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("PharmacyInventory", "\345\272\223\345\255\230\346\200\273\351\207\217", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("PharmacyInventory", "\344\273\267\346\240\274", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem7->setText(QApplication::translate("PharmacyInventory", "1", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class PharmacyInventory: public Ui_PharmacyInventory {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PHARMACYINVENTORY_H
