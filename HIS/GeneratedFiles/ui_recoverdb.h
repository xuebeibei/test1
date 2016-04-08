/********************************************************************************
** Form generated from reading UI file 'recoverdb.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECOVERDB_H
#define UI_RECOVERDB_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Recoverdb
{
public:
    QGroupBox *groupBox;
    QPushButton *recoverButton;
    QLineEdit *lineEdit;
    QPushButton *openButton;
    QLabel *label;

    void setupUi(QDialog *Recoverdb)
    {
        if (Recoverdb->objectName().isEmpty())
            Recoverdb->setObjectName(QString::fromUtf8("Recoverdb"));
        Recoverdb->resize(407, 177);
        groupBox = new QGroupBox(Recoverdb);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 20, 391, 131));
        recoverButton = new QPushButton(groupBox);
        recoverButton->setObjectName(QString::fromUtf8("recoverButton"));
        recoverButton->setGeometry(QRect(300, 90, 81, 21));
        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(60, 40, 231, 21));
        openButton = new QPushButton(groupBox);
        openButton->setObjectName(QString::fromUtf8("openButton"));
        openButton->setGeometry(QRect(300, 40, 81, 21));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 42, 41, 16));

        retranslateUi(Recoverdb);

        QMetaObject::connectSlotsByName(Recoverdb);
    } // setupUi

    void retranslateUi(QDialog *Recoverdb)
    {
        Recoverdb->setWindowTitle(QApplication::translate("Recoverdb", "\346\201\242\345\244\215", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QString());
        recoverButton->setText(QApplication::translate("Recoverdb", "\346\201\242\345\244\215", 0, QApplication::UnicodeUTF8));
        openButton->setText(QApplication::translate("Recoverdb", "\346\265\217\350\247\210...", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Recoverdb", "\346\225\260\346\215\256\345\272\223", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Recoverdb: public Ui_Recoverdb {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECOVERDB_H
