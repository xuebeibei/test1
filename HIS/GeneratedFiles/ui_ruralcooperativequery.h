/********************************************************************************
** Form generated from reading UI file 'ruralcooperativequery.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RURALCOOPERATIVEQUERY_H
#define UI_RURALCOOPERATIVEQUERY_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTableView>
#include <QtGui/QTreeWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Ruralcooperativequery
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *printButton;
    QPushButton *previewButton;
    QPushButton *outButton;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout;
    QTreeWidget *treeWidget;
    QTableView *tableView;

    void setupUi(QWidget *Ruralcooperativequery)
    {
        if (Ruralcooperativequery->objectName().isEmpty())
            Ruralcooperativequery->setObjectName(QString::fromUtf8("Ruralcooperativequery"));
        Ruralcooperativequery->resize(990, 577);
        verticalLayout = new QVBoxLayout(Ruralcooperativequery);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        printButton = new QPushButton(Ruralcooperativequery);
        printButton->setObjectName(QString::fromUtf8("printButton"));
        QFont font;
        font.setFamily(QString::fromUtf8("Agency FB"));
        font.setPointSize(12);
        printButton->setFont(font);

        horizontalLayout_2->addWidget(printButton);

        previewButton = new QPushButton(Ruralcooperativequery);
        previewButton->setObjectName(QString::fromUtf8("previewButton"));
        previewButton->setFont(font);

        horizontalLayout_2->addWidget(previewButton);

        outButton = new QPushButton(Ruralcooperativequery);
        outButton->setObjectName(QString::fromUtf8("outButton"));
        outButton->setFont(font);

        horizontalLayout_2->addWidget(outButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        treeWidget = new QTreeWidget(Ruralcooperativequery);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));
        treeWidget->setMaximumSize(QSize(140, 16777215));

        horizontalLayout->addWidget(treeWidget);

        tableView = new QTableView(Ruralcooperativequery);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        horizontalLayout->addWidget(tableView);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(Ruralcooperativequery);

        QMetaObject::connectSlotsByName(Ruralcooperativequery);
    } // setupUi

    void retranslateUi(QWidget *Ruralcooperativequery)
    {
        Ruralcooperativequery->setWindowTitle(QApplication::translate("Ruralcooperativequery", "\345\206\234\345\220\210\345\257\271\345\272\224\345\205\263\347\263\273", 0, QApplication::UnicodeUTF8));
        printButton->setText(QApplication::translate("Ruralcooperativequery", "\346\211\223\345\215\260", 0, QApplication::UnicodeUTF8));
        previewButton->setText(QApplication::translate("Ruralcooperativequery", "\351\242\204\350\247\210", 0, QApplication::UnicodeUTF8));
        outButton->setText(QApplication::translate("Ruralcooperativequery", "\345\257\274\345\207\272excel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Ruralcooperativequery: public Ui_Ruralcooperativequery {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RURALCOOPERATIVEQUERY_H
