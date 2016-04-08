

#ifndef UTIL_H
#define UTIL_H
#include <stdio.h>
#include <stdlib.h>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QApplication>
#include <QFontDatabase>


#if QT_VERSION >= QT_VERSION_CHECK(5, 0, 0)
    void myMessageOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg);
    void loadFonts(QApplication& app);
#endif


QString getQssFromFile(QString filename);
QString readFile(const QString filename);
void setSkinForApp(QString filename);

#endif // UTIL_H
