/********************************************************************************
** Form generated from reading UI file 'connectdb.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONNECTDB_H
#define UI_CONNECTDB_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ConnectDB
{
public:
    QPushButton *cancelButton_2;
    QWidget *widget;
    QPushButton *closeButton;
    QLabel *label;
    QPushButton *exitButton;
    QPushButton *loginButton;
    QLineEdit *lineEdit_2;
    QComboBox *comboBox_2;
    QLabel *textLabel4;
    QLabel *textLabel4_2;
    QLabel *label_2;
    QLineEdit *lineEdit;

    void setupUi(QDialog *ConnectDB)
    {
        if (ConnectDB->objectName().isEmpty())
            ConnectDB->setObjectName(QString::fromUtf8("ConnectDB"));
        ConnectDB->setWindowModality(Qt::ApplicationModal);
        ConnectDB->resize(385, 312);
        QPalette palette;
        QBrush brush(QColor(240, 240, 240, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        QBrush brush1(QColor(255, 255, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        ConnectDB->setPalette(palette);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/skin/images/his.ico"), QSize(), QIcon::Normal, QIcon::Off);
        ConnectDB->setWindowIcon(icon);
        ConnectDB->setSizeGripEnabled(false);
        ConnectDB->setModal(true);
        cancelButton_2 = new QPushButton(ConnectDB);
        cancelButton_2->setObjectName(QString::fromUtf8("cancelButton_2"));
        cancelButton_2->setEnabled(true);
        cancelButton_2->setGeometry(QRect(580, 270, 75, 23));
        cancelButton_2->setCheckable(false);
        cancelButton_2->setChecked(false);
        widget = new QWidget(ConnectDB);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(0, 0, 385, 131));
        closeButton = new QPushButton(widget);
        closeButton->setObjectName(QString::fromUtf8("closeButton"));
        closeButton->setGeometry(QRect(355, 0, 31, 23));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/skin/icons/dark/appbar.close.png"), QSize(), QIcon::Normal, QIcon::Off);
        closeButton->setIcon(icon1);
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 60, 281, 21));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\215\216\346\226\207\346\245\267\344\275\223"));
        font.setPointSize(18);
        label->setFont(font);
        label->raise();
        closeButton->raise();
        exitButton = new QPushButton(ConnectDB);
        exitButton->setObjectName(QString::fromUtf8("exitButton"));
        exitButton->setGeometry(QRect(550, 250, 53, 21));
        QPalette palette1;
        QBrush brush2(QColor(61, 148, 255, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        QBrush brush3(QColor(120, 120, 120, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        exitButton->setPalette(palette1);
        QFont font1;
        font1.setFamily(QString::fromUtf8("AcadEref"));
        font1.setPointSize(9);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setUnderline(false);
        font1.setWeight(50);
        exitButton->setFont(font1);
        loginButton = new QPushButton(ConnectDB);
        loginButton->setObjectName(QString::fromUtf8("loginButton"));
        loginButton->setGeometry(QRect(119, 270, 191, 31));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::Button, brush2);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        loginButton->setPalette(palette2);
        loginButton->setFont(font1);
        loginButton->setStyleSheet(QString::fromUtf8(""));
        lineEdit_2 = new QLineEdit(ConnectDB);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(119, 230, 191, 22));
        lineEdit_2->setEchoMode(QLineEdit::Password);
        comboBox_2 = new QComboBox(ConnectDB);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setGeometry(QRect(119, 190, 191, 22));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font2.setPointSize(12);
        font2.setBold(false);
        font2.setWeight(50);
        comboBox_2->setFont(font2);
        comboBox_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        comboBox_2->setEditable(true);
        textLabel4 = new QLabel(ConnectDB);
        textLabel4->setObjectName(QString::fromUtf8("textLabel4"));
        textLabel4->setGeometry(QRect(60, 191, 48, 16));
        textLabel4_2 = new QLabel(ConnectDB);
        textLabel4_2->setObjectName(QString::fromUtf8("textLabel4_2"));
        textLabel4_2->setGeometry(QRect(60, 230, 36, 16));
        label_2 = new QLabel(ConnectDB);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(60, 155, 54, 12));
        lineEdit = new QLineEdit(ConnectDB);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(119, 150, 191, 22));
        widget->raise();
        cancelButton_2->raise();
        exitButton->raise();
        loginButton->raise();
        lineEdit_2->raise();
        comboBox_2->raise();
        textLabel4->raise();
        textLabel4_2->raise();
        label_2->raise();
        lineEdit->raise();
        QWidget::setTabOrder(comboBox_2, lineEdit_2);
        QWidget::setTabOrder(lineEdit_2, loginButton);
        QWidget::setTabOrder(loginButton, exitButton);
        QWidget::setTabOrder(exitButton, closeButton);
        QWidget::setTabOrder(closeButton, cancelButton_2);

        retranslateUi(ConnectDB);

        QMetaObject::connectSlotsByName(ConnectDB);
    } // setupUi

    void retranslateUi(QDialog *ConnectDB)
    {
        ConnectDB->setWindowTitle(QApplication::translate("ConnectDB", "HIS", 0, QApplication::UnicodeUTF8));
        cancelButton_2->setText(QApplication::translate("ConnectDB", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
        closeButton->setText(QString());
        label->setText(QApplication::translate("ConnectDB", "\344\271\241\351\225\207\345\215\253\347\224\237\351\231\242\347\256\241\347\220\206\344\277\241\346\201\257\347\263\273\347\273\237", 0, QApplication::UnicodeUTF8));
        exitButton->setText(QApplication::translate("ConnectDB", "\351\200\200\345\207\272", 0, QApplication::UnicodeUTF8));
        loginButton->setText(QApplication::translate("ConnectDB", "\347\231\273\345\275\225", 0, QApplication::UnicodeUTF8));
        lineEdit_2->setText(QString());
        textLabel4->setText(QApplication::translate("ConnectDB", "\347\224\250\346\210\267\345\220\215\357\274\232", 0, QApplication::UnicodeUTF8));
        textLabel4_2->setText(QApplication::translate("ConnectDB", "\345\257\206\347\240\201\357\274\232", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ConnectDB", "\346\225\260\346\215\256\345\272\223\357\274\232", 0, QApplication::UnicodeUTF8));
        lineEdit->setText(QApplication::translate("ConnectDB", "192.168.1.101", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ConnectDB: public Ui_ConnectDB {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONNECTDB_H
