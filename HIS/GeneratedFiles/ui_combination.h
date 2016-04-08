/********************************************************************************
** Form generated from reading UI file 'combination.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMBINATION_H
#define UI_COMBINATION_H

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

class Ui_Combination
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *addButton;
    QPushButton *addrowButton;
    QPushButton *deleterowButton;
    QPushButton *deleteButton;
    QPushButton *editButton;
    QPushButton *discardButton;
    QPushButton *saveButton;
    QPushButton *queryButton;
    QPushButton *exitButton;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QSpacerItem *horizontalSpacer;
    QTableWidget *tableWidget;

    void setupUi(QWidget *Combination)
    {
        if (Combination->objectName().isEmpty())
            Combination->setObjectName(QString::fromUtf8("Combination"));
        Combination->resize(826, 514);
        verticalLayout_2 = new QVBoxLayout(Combination);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        addButton = new QPushButton(Combination);
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

        horizontalLayout->addWidget(addButton);

        addrowButton = new QPushButton(Combination);
        addrowButton->setObjectName(QString::fromUtf8("addrowButton"));
        sizePolicy.setHeightForWidth(addrowButton->sizePolicy().hasHeightForWidth());
        addrowButton->setSizePolicy(sizePolicy);
        addrowButton->setFont(font);

        horizontalLayout->addWidget(addrowButton);

        deleterowButton = new QPushButton(Combination);
        deleterowButton->setObjectName(QString::fromUtf8("deleterowButton"));
        sizePolicy.setHeightForWidth(deleterowButton->sizePolicy().hasHeightForWidth());
        deleterowButton->setSizePolicy(sizePolicy);
        deleterowButton->setFont(font);

        horizontalLayout->addWidget(deleterowButton);

        deleteButton = new QPushButton(Combination);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));
        sizePolicy.setHeightForWidth(deleteButton->sizePolicy().hasHeightForWidth());
        deleteButton->setSizePolicy(sizePolicy);
        deleteButton->setFont(font);

        horizontalLayout->addWidget(deleteButton);

        editButton = new QPushButton(Combination);
        editButton->setObjectName(QString::fromUtf8("editButton"));
        sizePolicy.setHeightForWidth(editButton->sizePolicy().hasHeightForWidth());
        editButton->setSizePolicy(sizePolicy);
        editButton->setFont(font);

        horizontalLayout->addWidget(editButton);

        discardButton = new QPushButton(Combination);
        discardButton->setObjectName(QString::fromUtf8("discardButton"));
        sizePolicy.setHeightForWidth(discardButton->sizePolicy().hasHeightForWidth());
        discardButton->setSizePolicy(sizePolicy);
        discardButton->setFont(font);

        horizontalLayout->addWidget(discardButton);

        saveButton = new QPushButton(Combination);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));
        sizePolicy.setHeightForWidth(saveButton->sizePolicy().hasHeightForWidth());
        saveButton->setSizePolicy(sizePolicy);
        saveButton->setFont(font);

        horizontalLayout->addWidget(saveButton);

        queryButton = new QPushButton(Combination);
        queryButton->setObjectName(QString::fromUtf8("queryButton"));
        queryButton->setFont(font);

        horizontalLayout->addWidget(queryButton);

        exitButton = new QPushButton(Combination);
        exitButton->setObjectName(QString::fromUtf8("exitButton"));
        sizePolicy.setHeightForWidth(exitButton->sizePolicy().hasHeightForWidth());
        exitButton->setSizePolicy(sizePolicy);
        exitButton->setFont(font);

        horizontalLayout->addWidget(exitButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(Combination);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        lineEdit = new QLineEdit(Combination);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout_2->addWidget(lineEdit);


        horizontalLayout_4->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_2 = new QLabel(Combination);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_3->addWidget(label_2);

        lineEdit_2 = new QLineEdit(Combination);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        horizontalLayout_3->addWidget(lineEdit_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);


        horizontalLayout_4->addLayout(horizontalLayout_3);


        verticalLayout->addLayout(horizontalLayout_4);

        tableWidget = new QTableWidget(Combination);
        if (tableWidget->columnCount() < 8)
            tableWidget->setColumnCount(8);
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
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));

        verticalLayout->addWidget(tableWidget);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(Combination);

        QMetaObject::connectSlotsByName(Combination);
    } // setupUi

    void retranslateUi(QWidget *Combination)
    {
        Combination->setWindowTitle(QApplication::translate("Combination", "\345\245\227\351\244\220\347\273\204\345\220\210", 0, QApplication::UnicodeUTF8));
        addButton->setText(QApplication::translate("Combination", "\346\226\260\345\242\236", 0, QApplication::UnicodeUTF8));
        addrowButton->setText(QApplication::translate("Combination", "\345\242\236\350\241\214", 0, QApplication::UnicodeUTF8));
        deleterowButton->setText(QApplication::translate("Combination", "\345\210\240\350\241\214", 0, QApplication::UnicodeUTF8));
        deleteButton->setText(QApplication::translate("Combination", "\345\210\240\351\231\244", 0, QApplication::UnicodeUTF8));
        editButton->setText(QApplication::translate("Combination", "\344\277\256\346\224\271", 0, QApplication::UnicodeUTF8));
        discardButton->setText(QApplication::translate("Combination", "\346\224\276\345\274\203", 0, QApplication::UnicodeUTF8));
        saveButton->setText(QApplication::translate("Combination", "\344\277\235\345\255\230", 0, QApplication::UnicodeUTF8));
        queryButton->setText(QApplication::translate("Combination", "\346\237\245\350\257\242", 0, QApplication::UnicodeUTF8));
        exitButton->setText(QApplication::translate("Combination", "\351\200\200\345\207\272", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Combination", "\345\245\227\351\244\220\345\220\215\347\247\260\357\274\232", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Combination", "\345\212\251\350\256\260\347\254\246\357\274\232", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("Combination", "\347\274\226\347\240\201", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("Combination", "\345\220\215\347\247\260", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("Combination", "\350\247\204\346\240\274\345\236\213\345\217\267", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("Combination", "\347\224\237\344\272\247\345\216\202\345\256\266", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("Combination", "\346\234\200\345\260\217\345\215\225\344\275\215", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("Combination", "\346\234\200\345\260\217\346\225\260\351\207\217", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("Combination", "\351\227\250\350\257\212\345\215\225\344\273\267", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QApplication::translate("Combination", "\344\275\217\351\231\242\345\215\225\344\273\267", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Combination: public Ui_Combination {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMBINATION_H
