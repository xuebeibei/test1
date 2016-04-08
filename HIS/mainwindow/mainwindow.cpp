#include "mainwindow.h"
#include "centerwindow.h"
#include "QFramer/futil.h"
#include "thememenu.h"
MainWindow* MainWindow::instance = NULL;

MainWindow::MainWindow(QWidget *parent) :
    FMainWindow(parent)
{
    initUI();
    initConnect();
	
}

void MainWindow::initData(bool IsAdmin,bool IsAuthorized)
{
	if(IsAdmin==false)
	{
		centerWindow->getNavgationBar()->buttons.at(5)->setEnabled(false);
	}

}

void MainWindow::initUI()
{
    centerWindow = new CenterWindow;
    setCentralWidget(centerWindow);
    centerWindow->getNavgationBar()->setCurrentIndex(0);
	
    settingMenu = new SettingMenu;
    getTitleBar()->getSettingButton()->setMenu(settingMenu);
    getQSystemTrayIcon()->setContextMenu(settingMenu);

    themeMenu = new ThemeMenu;
    getTitleBar()->getSkinButton()->setMenu(themeMenu);

}

void MainWindow::initConnect()
{

}

MainWindow* MainWindow::getInstance()
{
    if(!instance)
    {
        instance = new MainWindow();
    }
    return instance;
	
}



void MainWindow::resizeEvent(QResizeEvent *event)
{
  
    QMainWindow::resizeEvent(event);
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{

    FMainWindow::mouseMoveEvent(event);
}

void MainWindow::showEvent(QHideEvent *event)
{

    event->accept();
}

void MainWindow::hideEvent(QHideEvent *event)
{

    event->accept();
}

void MainWindow::mouseDoubleClickEvent(QMouseEvent *event)
{
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Left)
    {
        int index = centerWindow->getNavgationBar()->currentIndex();
        int count = centerWindow->getNavgationBar()->count();
        if(index == 0){
            centerWindow->getNavgationBar()->setCurrentIndex(count - 1);
        }else if(index <= (count - 1) && index > 0){
            centerWindow->getNavgationBar()->setCurrentIndex(index - 1);
        }
    }
    else if(event->key() == Qt::Key_Right)
    {
        int index = centerWindow->getNavgationBar()->currentIndex();
        int count = centerWindow->getNavgationBar()->count();
        if(index == (count - 1)){
            centerWindow->getNavgationBar()->setCurrentIndex(0);
        }else if(index >= 0 && index < (count - 1)){
            centerWindow->getNavgationBar()->setCurrentIndex(index + 1);
        }
    }

    FMainWindow::keyPressEvent(event);
}

void MainWindow::slotReboot()
{
	qDebug() << "Performing application reboot..";
	qApp->exit( EXIT_CODE_REBOOT );//调用exit()，退出应用程序。
	qDebug() << "..........";
}
