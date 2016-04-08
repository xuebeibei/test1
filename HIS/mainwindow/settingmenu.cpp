#include "settingmenu.h"
#include "mainwindow.h"
#include <QApplication>


SettingMenu::SettingMenu(QWidget *parent) :
    QMenu(parent)
{
    initData();
    initUI();
    initController();
    initConnect();
}

void SettingMenu::initData()
{
	QString str = str.fromLocal8Bit("显示悬浮窗");
	QString str3 = str.fromLocal8Bit("重启");
	QString str1 = str.fromLocal8Bit("关于");
	QString str2 = str.fromLocal8Bit("退出");
    actionNames<<str3 <<str2;// << tr("Check update") << tr("Online help") \
              << tr("Office site")  << tr("Show rightBar")<< "display"<<str1
}

void SettingMenu::initUI()
{
    for(int i=0; i< actionNames.length() ; ++i)
    {
        actions.append(new QAction(actionNames.at(i), this));
        actionMaps[actionNames.at(i)] = actions.at(i);
    }
    addActions(actions);
}

void SettingMenu::initController()
{
    controller = new SettingMenuController();
}

void SettingMenu::initConnect()
{
	QString str = str.fromLocal8Bit("显示悬浮窗");

	QString str1 = str.fromLocal8Bit("关于");
	QString str3 = str.fromLocal8Bit("重启");
	QString str2 = str.fromLocal8Bit("退出");

//    connect(actionMaps["display"], SIGNAL(triggered()), this, SLOT(switchActionState()));
//    connect(actionMaps[tr("Show rightBar")], SIGNAL(triggered()), this, SLOT(switchFloatWindow()));
 //   connect(actionMaps[str1], SIGNAL(triggered()), controller, SLOT(showSettingDialog()));
//    connect(actionMaps[tr("Check update")], SIGNAL(triggered()), controller, SLOT(checkUpdate()));
//    connect(actionMaps[tr("Online help")], SIGNAL(triggered()), controller, SLOT(onlineHelp()));
//    connect(actionMaps[tr("Office site")], SIGNAL(triggered()), controller, SLOT(visitOfficialSite()));
    connect(actionMaps[str1], SIGNAL(triggered()), controller, SLOT(showAboutUs()));
    connect(actionMaps[str2], SIGNAL(triggered()), controller, SLOT(closeMainWindow()));
	connect(actionMaps[str3], SIGNAL(triggered()), controller, SLOT(restartMainWindow()));
}

QMap<QString, QAction*> SettingMenu::getActionMaps()
{
    return actionMaps;
}


void SettingMenu::switchActionState()
{
 
}

void SettingMenu::switchFloatWindow()
{
  
}
