#include "settingmenucontroller.h"
#include "dialogs/aboutdialog.h"
#include <QDesktopServices>
#include <QUrl>
#include <QApplication>
#include "mainwindow.h"
#include <QProcess>

SettingMenuController::SettingMenuController(QObject *parent) :
    QObject(parent)
{

}


void SettingMenuController::checkUpdate()
{
    QDesktopServices::openUrl(QUrl("https://github.com/dragondjf/QCFramer"));
}

void SettingMenuController::onlineHelp()
{
    QDesktopServices::openUrl(QUrl("https://github.com/dragondjf/QCFramer"));
}

void SettingMenuController::visitOfficialSite()
{
    QDesktopServices::openUrl(QUrl("https://github.com/dragondjf/QCFramer"));
}

void SettingMenuController::showAboutUs()
{
    MainWindow::getInstance()->show();
    AboutDialog* aboutDialog = new AboutDialog;
    aboutDialog->exec();

}

void SettingMenuController::closeMainWindow()
{
    MainWindow* p = MainWindow::getInstance();
    p->animationClose();
}

void SettingMenuController::restartMainWindow()
{
	qApp->closeAllWindows();  
	QProcess::startDetached(qApp->applicationFilePath(), QStringList());  
}