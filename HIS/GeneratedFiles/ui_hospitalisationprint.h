/********************************************************************************
** Form generated from reading UI file 'hospitalisationprint.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOSPITALISATIONPRINT_H
#define UI_HOSPITALISATIONPRINT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QTableWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Hospitalisationprint
{
public:
    QPushButton *printButton;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QFrame *line;
    QFrame *line_2;
    QFrame *line_3;
    QFrame *line_4;
    QFrame *line_5;
    QFrame *line_6;
    QFrame *line_7;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_18;
    QTableWidget *tableWidget;
    QTableWidget *tableWidget_2;
    QLabel *label_19;
    QLabel *label_20;
    QLabel *label_21;
    QLabel *label_22;
    QLabel *label_23;
    QLabel *label_24;
    QLabel *label_25;
    QLabel *label_26;
    QLabel *label_27;
    QLabel *label_28;
    QLabel *label_29;
    QLabel *label_30;
    QLabel *label_31;
    QLabel *label_32;
    QLabel *label_33;
    QLabel *label_34;
    QLabel *label_35;
    QPushButton *previewButton;
    QLabel *sheetnolabel;
    QLabel *hospitallabel;
    QLabel *typelabel;
    QLabel *departmentlabel;
    QLabel *hospitalisationNolabel;
    QLabel *namelabel;
    QLabel *genderlabel;
    QLabel *insurancetypelabel;
    QLabel *insurancenolabel;
    QLabel *sheetmakerlabel;
    QLabel *totalfeelabel;
    QLabel *feeblocklabel;
    QLabel *currentyearlabel;
    QLabel *currentmonthlabel;
    QLabel *currentdaylabel;
    QLabel *startyearlabel;
    QLabel *startmonthlabel;
    QLabel *startdaylabel;
    QLabel *endmonthlabel;
    QLabel *endyearlabel;
    QLabel *enddaylabel;
    QLabel *deltadaylabel;

    void setupUi(QWidget *Hospitalisationprint)
    {
        if (Hospitalisationprint->objectName().isEmpty())
            Hospitalisationprint->setObjectName(QString::fromUtf8("Hospitalisationprint"));
        Hospitalisationprint->resize(741, 475);
        printButton = new QPushButton(Hospitalisationprint);
        printButton->setObjectName(QString::fromUtf8("printButton"));
        printButton->setGeometry(QRect(0, 0, 75, 23));
        label = new QLabel(Hospitalisationprint);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(260, 20, 221, 20));
        QFont font;
        font.setFamily(QString::fromUtf8("Agency FB"));
        font.setPointSize(14);
        label->setFont(font);
        label_2 = new QLabel(Hospitalisationprint);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 50, 54, 12));
        label_3 = new QLabel(Hospitalisationprint);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(220, 50, 54, 12));
        label_4 = new QLabel(Hospitalisationprint);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(360, 50, 54, 12));
        label_5 = new QLabel(Hospitalisationprint);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(560, 50, 54, 12));
        line = new QFrame(Hospitalisationprint);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(2, 80, 738, 16));
        line->setStyleSheet(QString::fromUtf8("border-color: rgb(0, 0, 0);"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(Hospitalisationprint);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(2, 100, 741, 16));
        line_2->setStyleSheet(QString::fromUtf8("border-color: rgb(0, 0, 0);"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        line_3 = new QFrame(Hospitalisationprint);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setGeometry(QRect(-10, 87, 25, 301));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);
        line_4 = new QFrame(Hospitalisationprint);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setGeometry(QRect(2, 310, 741, 16));
        line_4->setStyleSheet(QString::fromUtf8("border-color: rgb(0, 0, 0);"));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);
        line_5 = new QFrame(Hospitalisationprint);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setGeometry(QRect(2, 330, 738, 16));
        line_5->setStyleSheet(QString::fromUtf8("border-color: rgb(0, 0, 0);"));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);
        line_6 = new QFrame(Hospitalisationprint);
        line_6->setObjectName(QString::fromUtf8("line_6"));
        line_6->setGeometry(QRect(2, 400, 738, 16));
        line_6->setStyleSheet(QString::fromUtf8("border-color: rgb(0, 0, 0);"));
        line_6->setFrameShape(QFrame::HLine);
        line_6->setFrameShadow(QFrame::Sunken);
        line_7 = new QFrame(Hospitalisationprint);
        line_7->setObjectName(QString::fromUtf8("line_7"));
        line_7->setGeometry(QRect(730, 88, 21, 300));
        line_7->setFrameShape(QFrame::VLine);
        line_7->setFrameShadow(QFrame::Sunken);
        label_6 = new QLabel(Hospitalisationprint);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(20, 70, 54, 12));
        label_7 = new QLabel(Hospitalisationprint);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(160, 70, 54, 16));
        label_8 = new QLabel(Hospitalisationprint);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(260, 70, 21, 16));
        label_9 = new QLabel(Hospitalisationprint);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(310, 70, 21, 16));
        label_10 = new QLabel(Hospitalisationprint);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(360, 70, 31, 16));
        label_11 = new QLabel(Hospitalisationprint);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(480, 70, 21, 16));
        label_12 = new QLabel(Hospitalisationprint);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(420, 70, 21, 16));
        label_13 = new QLabel(Hospitalisationprint);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(540, 70, 21, 16));
        label_14 = new QLabel(Hospitalisationprint);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(560, 70, 81, 16));
        label_15 = new QLabel(Hospitalisationprint);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(10, 90, 54, 12));
        label_16 = new QLabel(Hospitalisationprint);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(120, 90, 54, 12));
        label_17 = new QLabel(Hospitalisationprint);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(290, 90, 61, 16));
        label_18 = new QLabel(Hospitalisationprint);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(490, 90, 91, 16));
        tableWidget = new QTableWidget(Hospitalisationprint);
        if (tableWidget->columnCount() < 3)
            tableWidget->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        if (tableWidget->rowCount() < 6)
            tableWidget->setRowCount(6);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(1, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(2, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(3, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(4, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(5, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget->setItem(0, 0, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget->setItem(1, 0, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget->setItem(2, 0, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget->setItem(3, 0, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget->setItem(4, 0, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidget->setItem(5, 0, __qtablewidgetitem14);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(1, 107, 369, 211));
        tableWidget_2 = new QTableWidget(Hospitalisationprint);
        if (tableWidget_2->columnCount() < 3)
            tableWidget_2->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(0, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(1, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(2, __qtablewidgetitem17);
        if (tableWidget_2->rowCount() < 6)
            tableWidget_2->setRowCount(6);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tableWidget_2->setVerticalHeaderItem(0, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        tableWidget_2->setVerticalHeaderItem(1, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        tableWidget_2->setVerticalHeaderItem(2, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        tableWidget_2->setVerticalHeaderItem(3, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        tableWidget_2->setVerticalHeaderItem(4, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        tableWidget_2->setVerticalHeaderItem(5, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        tableWidget_2->setItem(0, 0, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        tableWidget_2->setItem(1, 0, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        tableWidget_2->setItem(2, 0, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        tableWidget_2->setItem(3, 0, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        tableWidget_2->setItem(4, 0, __qtablewidgetitem28);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        tableWidget_2->setItem(5, 0, __qtablewidgetitem29);
        tableWidget_2->setObjectName(QString::fromUtf8("tableWidget_2"));
        tableWidget_2->setGeometry(QRect(369, 107, 371, 211));
        label_19 = new QLabel(Hospitalisationprint);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(10, 320, 91, 16));
        label_20 = new QLabel(Hospitalisationprint);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(360, 320, 54, 12));
        label_21 = new QLabel(Hospitalisationprint);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setGeometry(QRect(10, 410, 101, 16));
        label_22 = new QLabel(Hospitalisationprint);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(350, 410, 54, 12));
        label_23 = new QLabel(Hospitalisationprint);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setGeometry(QRect(630, 410, 21, 16));
        label_24 = new QLabel(Hospitalisationprint);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setGeometry(QRect(720, 410, 21, 16));
        label_25 = new QLabel(Hospitalisationprint);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setGeometry(QRect(680, 410, 21, 16));
        label_26 = new QLabel(Hospitalisationprint);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setGeometry(QRect(10, 340, 54, 12));
        label_27 = new QLabel(Hospitalisationprint);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setGeometry(QRect(180, 340, 54, 12));
        label_28 = new QLabel(Hospitalisationprint);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        label_28->setGeometry(QRect(360, 340, 54, 12));
        label_29 = new QLabel(Hospitalisationprint);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        label_29->setGeometry(QRect(560, 340, 54, 12));
        label_30 = new QLabel(Hospitalisationprint);
        label_30->setObjectName(QString::fromUtf8("label_30"));
        label_30->setGeometry(QRect(10, 360, 81, 16));
        label_31 = new QLabel(Hospitalisationprint);
        label_31->setObjectName(QString::fromUtf8("label_31"));
        label_31->setGeometry(QRect(180, 360, 91, 16));
        label_32 = new QLabel(Hospitalisationprint);
        label_32->setObjectName(QString::fromUtf8("label_32"));
        label_32->setGeometry(QRect(360, 360, 91, 16));
        label_33 = new QLabel(Hospitalisationprint);
        label_33->setObjectName(QString::fromUtf8("label_33"));
        label_33->setGeometry(QRect(10, 380, 91, 16));
        label_34 = new QLabel(Hospitalisationprint);
        label_34->setObjectName(QString::fromUtf8("label_34"));
        label_34->setGeometry(QRect(180, 380, 91, 16));
        label_35 = new QLabel(Hospitalisationprint);
        label_35->setObjectName(QString::fromUtf8("label_35"));
        label_35->setGeometry(QRect(560, 360, 91, 16));
        previewButton = new QPushButton(Hospitalisationprint);
        previewButton->setObjectName(QString::fromUtf8("previewButton"));
        previewButton->setGeometry(QRect(80, 0, 75, 23));
        sheetnolabel = new QLabel(Hospitalisationprint);
        sheetnolabel->setObjectName(QString::fromUtf8("sheetnolabel"));
        sheetnolabel->setGeometry(QRect(610, 50, 101, 16));
        hospitallabel = new QLabel(Hospitalisationprint);
        hospitallabel->setObjectName(QString::fromUtf8("hospitallabel"));
        hospitallabel->setGeometry(QRect(80, 50, 121, 16));
        typelabel = new QLabel(Hospitalisationprint);
        typelabel->setObjectName(QString::fromUtf8("typelabel"));
        typelabel->setGeometry(QRect(260, 50, 54, 12));
        departmentlabel = new QLabel(Hospitalisationprint);
        departmentlabel->setObjectName(QString::fromUtf8("departmentlabel"));
        departmentlabel->setGeometry(QRect(400, 50, 54, 12));
        hospitalisationNolabel = new QLabel(Hospitalisationprint);
        hospitalisationNolabel->setObjectName(QString::fromUtf8("hospitalisationNolabel"));
        hospitalisationNolabel->setGeometry(QRect(70, 70, 71, 16));
        namelabel = new QLabel(Hospitalisationprint);
        namelabel->setObjectName(QString::fromUtf8("namelabel"));
        namelabel->setGeometry(QRect(50, 90, 54, 12));
        genderlabel = new QLabel(Hospitalisationprint);
        genderlabel->setObjectName(QString::fromUtf8("genderlabel"));
        genderlabel->setGeometry(QRect(160, 90, 54, 12));
        insurancetypelabel = new QLabel(Hospitalisationprint);
        insurancetypelabel->setObjectName(QString::fromUtf8("insurancetypelabel"));
        insurancetypelabel->setGeometry(QRect(350, 90, 54, 12));
        insurancenolabel = new QLabel(Hospitalisationprint);
        insurancenolabel->setObjectName(QString::fromUtf8("insurancenolabel"));
        insurancenolabel->setGeometry(QRect(580, 90, 54, 12));
        sheetmakerlabel = new QLabel(Hospitalisationprint);
        sheetmakerlabel->setObjectName(QString::fromUtf8("sheetmakerlabel"));
        sheetmakerlabel->setGeometry(QRect(410, 410, 54, 12));
        totalfeelabel = new QLabel(Hospitalisationprint);
        totalfeelabel->setObjectName(QString::fromUtf8("totalfeelabel"));
        totalfeelabel->setGeometry(QRect(380, 320, 54, 12));
        feeblocklabel = new QLabel(Hospitalisationprint);
        feeblocklabel->setObjectName(QString::fromUtf8("feeblocklabel"));
        feeblocklabel->setGeometry(QRect(100, 320, 251, 16));
        currentyearlabel = new QLabel(Hospitalisationprint);
        currentyearlabel->setObjectName(QString::fromUtf8("currentyearlabel"));
        currentyearlabel->setGeometry(QRect(590, 410, 31, 16));
        currentmonthlabel = new QLabel(Hospitalisationprint);
        currentmonthlabel->setObjectName(QString::fromUtf8("currentmonthlabel"));
        currentmonthlabel->setGeometry(QRect(650, 410, 21, 16));
        currentdaylabel = new QLabel(Hospitalisationprint);
        currentdaylabel->setObjectName(QString::fromUtf8("currentdaylabel"));
        currentdaylabel->setGeometry(QRect(700, 410, 16, 16));
        startyearlabel = new QLabel(Hospitalisationprint);
        startyearlabel->setObjectName(QString::fromUtf8("startyearlabel"));
        startyearlabel->setGeometry(QRect(220, 70, 31, 16));
        startmonthlabel = new QLabel(Hospitalisationprint);
        startmonthlabel->setObjectName(QString::fromUtf8("startmonthlabel"));
        startmonthlabel->setGeometry(QRect(280, 70, 31, 16));
        startdaylabel = new QLabel(Hospitalisationprint);
        startdaylabel->setObjectName(QString::fromUtf8("startdaylabel"));
        startdaylabel->setGeometry(QRect(330, 70, 31, 16));
        endmonthlabel = new QLabel(Hospitalisationprint);
        endmonthlabel->setObjectName(QString::fromUtf8("endmonthlabel"));
        endmonthlabel->setGeometry(QRect(440, 70, 31, 16));
        endyearlabel = new QLabel(Hospitalisationprint);
        endyearlabel->setObjectName(QString::fromUtf8("endyearlabel"));
        endyearlabel->setGeometry(QRect(390, 70, 31, 16));
        enddaylabel = new QLabel(Hospitalisationprint);
        enddaylabel->setObjectName(QString::fromUtf8("enddaylabel"));
        enddaylabel->setGeometry(QRect(500, 70, 31, 16));
        deltadaylabel = new QLabel(Hospitalisationprint);
        deltadaylabel->setObjectName(QString::fromUtf8("deltadaylabel"));
        deltadaylabel->setGeometry(QRect(620, 70, 54, 12));

        retranslateUi(Hospitalisationprint);

        QMetaObject::connectSlotsByName(Hospitalisationprint);
    } // setupUi

    void retranslateUi(QWidget *Hospitalisationprint)
    {
        Hospitalisationprint->setWindowTitle(QApplication::translate("Hospitalisationprint", "\344\275\217\351\231\242\347\273\223\347\256\227", 0, QApplication::UnicodeUTF8));
        printButton->setText(QApplication::translate("Hospitalisationprint", "\346\211\223\345\215\260", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Hospitalisationprint", "\346\262\263\345\214\227\347\234\201\345\214\273\347\226\227\344\275\217\351\231\242\346\224\266\350\264\271\347\245\250\346\215\256", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Hospitalisationprint", "\345\214\273\347\226\227\346\234\272\346\236\204\357\274\232", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Hospitalisationprint", "\347\261\273\345\236\213\357\274\232", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Hospitalisationprint", "\347\247\221\345\256\244\357\274\232", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("Hospitalisationprint", "\346\265\201\346\260\264\345\217\267\357\274\232", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("Hospitalisationprint", "\344\275\217\351\231\242\345\217\267\357\274\232", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("Hospitalisationprint", "\344\275\217\351\231\242\346\227\266\351\227\264\357\274\232", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("Hospitalisationprint", "\345\271\264", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("Hospitalisationprint", "\346\234\210", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("Hospitalisationprint", "\346\227\245\345\210\260", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("Hospitalisationprint", "\346\234\210", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("Hospitalisationprint", "\345\271\264", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("Hospitalisationprint", "\346\227\245", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("Hospitalisationprint", "\344\275\217\351\231\242\345\244\251\346\225\260\357\274\232", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("Hospitalisationprint", "\345\247\223\345\220\215\357\274\232", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("Hospitalisationprint", "\346\200\247\345\210\253\357\274\232", 0, QApplication::UnicodeUTF8));
        label_17->setText(QApplication::translate("Hospitalisationprint", "\345\214\273\344\277\235\347\261\273\345\236\213\357\274\232", 0, QApplication::UnicodeUTF8));
        label_18->setText(QApplication::translate("Hospitalisationprint", "\347\244\276\344\274\232\344\277\235\351\232\234\345\217\267\347\240\201\357\274\232", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("Hospitalisationprint", "\346\224\266\350\264\271\351\241\271\347\233\256", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("Hospitalisationprint", "\351\207\221\351\242\235", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("Hospitalisationprint", "\346\224\257\344\273\230\347\261\273\345\236\213", 0, QApplication::UnicodeUTF8));

        const bool __sortingEnabled = tableWidget->isSortingEnabled();
        tableWidget->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->item(0, 0);
        ___qtablewidgetitem3->setText(QApplication::translate("Hospitalisationprint", "\345\272\212\344\275\215\350\264\271B", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->item(1, 0);
        ___qtablewidgetitem4->setText(QApplication::translate("Hospitalisationprint", "\346\212\244\347\220\206\350\264\271F", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->item(2, 0);
        ___qtablewidgetitem5->setText(QApplication::translate("Hospitalisationprint", "\350\245\277\350\215\257\350\264\271", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->item(3, 0);
        ___qtablewidgetitem6->setText(QApplication::translate("Hospitalisationprint", "\344\270\255\346\210\220\350\215\257\350\264\271", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->item(4, 0);
        ___qtablewidgetitem7->setText(QApplication::translate("Hospitalisationprint", "\346\235\220\346\226\231\350\264\271", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->item(5, 0);
        ___qtablewidgetitem8->setText(QApplication::translate("Hospitalisationprint", "\345\205\266\344\273\226\350\264\271", 0, QApplication::UnicodeUTF8));
        tableWidget->setSortingEnabled(__sortingEnabled);

        QTableWidgetItem *___qtablewidgetitem9 = tableWidget_2->horizontalHeaderItem(0);
        ___qtablewidgetitem9->setText(QApplication::translate("Hospitalisationprint", "\346\224\266\350\264\271\351\241\271\347\233\256", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget_2->horizontalHeaderItem(1);
        ___qtablewidgetitem10->setText(QApplication::translate("Hospitalisationprint", "\351\207\221\351\242\235", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget_2->horizontalHeaderItem(2);
        ___qtablewidgetitem11->setText(QApplication::translate("Hospitalisationprint", "\346\224\257\344\273\230\347\261\273\345\236\213", 0, QApplication::UnicodeUTF8));

        const bool __sortingEnabled1 = tableWidget_2->isSortingEnabled();
        tableWidget_2->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget_2->item(0, 0);
        ___qtablewidgetitem12->setText(QApplication::translate("Hospitalisationprint", "\350\257\212\346\237\245\350\264\271C", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget_2->item(1, 0);
        ___qtablewidgetitem13->setText(QApplication::translate("Hospitalisationprint", "\346\262\273\347\226\227\350\264\271E", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget_2->item(2, 0);
        ___qtablewidgetitem14->setText(QApplication::translate("Hospitalisationprint", "\346\243\200\346\237\245\350\264\271D", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidget_2->item(3, 0);
        ___qtablewidgetitem15->setText(QApplication::translate("Hospitalisationprint", "\345\214\226\351\252\214\350\264\271H", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem16 = tableWidget_2->item(4, 0);
        ___qtablewidgetitem16->setText(QApplication::translate("Hospitalisationprint", "\346\211\213\346\234\257\350\264\271G", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem17 = tableWidget_2->item(5, 0);
        ___qtablewidgetitem17->setText(QApplication::translate("Hospitalisationprint", "\346\214\202\345\217\267\350\264\271A", 0, QApplication::UnicodeUTF8));
        tableWidget_2->setSortingEnabled(__sortingEnabled1);

        label_19->setText(QApplication::translate("Hospitalisationprint", "\345\220\210\350\256\241\357\274\210\345\244\247\345\206\231\357\274\211\357\274\232", 0, QApplication::UnicodeUTF8));
        label_20->setText(QApplication::translate("Hospitalisationprint", "\302\245\357\274\232", 0, QApplication::UnicodeUTF8));
        label_21->setText(QApplication::translate("Hospitalisationprint", "\346\224\266\346\254\276\345\215\225\344\275\215\357\274\210\347\253\240\357\274\211\357\274\232", 0, QApplication::UnicodeUTF8));
        label_22->setText(QApplication::translate("Hospitalisationprint", "\346\224\266\346\254\276\344\272\272\357\274\232", 0, QApplication::UnicodeUTF8));
        label_23->setText(QApplication::translate("Hospitalisationprint", "\345\271\264", 0, QApplication::UnicodeUTF8));
        label_24->setText(QApplication::translate("Hospitalisationprint", "\346\227\245", 0, QApplication::UnicodeUTF8));
        label_25->setText(QApplication::translate("Hospitalisationprint", "\346\234\210", 0, QApplication::UnicodeUTF8));
        label_26->setText(QApplication::translate("Hospitalisationprint", "\351\242\204\347\274\264\351\207\221\351\242\235\357\274\232", 0, QApplication::UnicodeUTF8));
        label_27->setText(QApplication::translate("Hospitalisationprint", "\350\241\245\347\274\264\351\207\221\351\242\235\357\274\232", 0, QApplication::UnicodeUTF8));
        label_28->setText(QApplication::translate("Hospitalisationprint", "\351\200\200\350\264\271\351\207\221\351\242\235\357\274\232", 0, QApplication::UnicodeUTF8));
        label_29->setText(QApplication::translate("Hospitalisationprint", "\345\214\273\351\231\242\345\236\253\344\273\230\357\274\232", 0, QApplication::UnicodeUTF8));
        label_30->setText(QApplication::translate("Hospitalisationprint", "\345\214\273\344\277\235\347\273\237\347\255\271\346\224\257\344\273\230\357\274\232", 0, QApplication::UnicodeUTF8));
        label_31->setText(QApplication::translate("Hospitalisationprint", "\344\270\252\344\272\272\350\264\246\346\210\267\346\224\257\344\273\230\357\274\232", 0, QApplication::UnicodeUTF8));
        label_32->setText(QApplication::translate("Hospitalisationprint", "\344\270\252\344\272\272\350\207\252\344\273\230\357\274\232", 0, QApplication::UnicodeUTF8));
        label_33->setText(QApplication::translate("Hospitalisationprint", "\344\270\252\344\272\272\350\264\246\346\210\267\344\275\231\351\242\235\357\274\232", 0, QApplication::UnicodeUTF8));
        label_34->setText(QApplication::translate("Hospitalisationprint", "\347\273\237\347\255\271\347\264\257\350\256\241\346\224\257\344\273\230\357\274\232", 0, QApplication::UnicodeUTF8));
        label_35->setText(QApplication::translate("Hospitalisationprint", "\344\270\252\344\272\272\350\207\252\350\264\271\357\274\232", 0, QApplication::UnicodeUTF8));
        previewButton->setText(QApplication::translate("Hospitalisationprint", "\351\242\204\350\247\210", 0, QApplication::UnicodeUTF8));
        sheetnolabel->setText(QString());
        hospitallabel->setText(QString());
        typelabel->setText(QString());
        departmentlabel->setText(QString());
        hospitalisationNolabel->setText(QString());
        namelabel->setText(QString());
        genderlabel->setText(QString());
        insurancetypelabel->setText(QString());
        insurancenolabel->setText(QString());
        sheetmakerlabel->setText(QString());
        totalfeelabel->setText(QString());
        feeblocklabel->setText(QString());
        currentyearlabel->setText(QString());
        currentmonthlabel->setText(QString());
        currentdaylabel->setText(QString());
        startyearlabel->setText(QString());
        startmonthlabel->setText(QString());
        startdaylabel->setText(QString());
        endmonthlabel->setText(QString());
        endyearlabel->setText(QString());
        enddaylabel->setText(QString());
        deltadaylabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Hospitalisationprint: public Ui_Hospitalisationprint {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOSPITALISATIONPRINT_H
