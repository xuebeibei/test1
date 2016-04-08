

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "QFramer/fmainwindow.h"
#include "centerwindow.h"
#include "settingmenu.h"
#include "thememenu.h"
#include <QResizeEvent>
#include <QMouseEvent>
#include <QHideEvent>

static const int EXIT_CODE_REBOOT = -123456789;
class MainWindow : public FMainWindow
{
    Q_OBJECT
private:
  
    void initUI();
    void initConnect();
protected:
    void mouseMoveEvent(QMouseEvent *event);
    void resizeEvent(QResizeEvent * event);
    void hideEvent(QHideEvent * event);
    void showEvent(QHideEvent * event);
    void mouseDoubleClickEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);
public:
    static MainWindow* instance;
    CenterWindow* centerWindow;
    SettingMenu* settingMenu;
    ThemeMenu* themeMenu;
	bool bAdmin;
public:
    explicit MainWindow(QWidget *parent = 0);
    static MainWindow* getInstance();
	void initData(bool IsAdmin,bool IsAuthorized);
	public slots:
		void slotReboot();
signals:

public slots:


};

#endif // MAINWINDOW_H
