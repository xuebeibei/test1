#include "fmainwindow.h"
#include "futil.h"
#include <QtCore>

#include <QMouseEvent>
#include <QKeyEvent>
#include <QDesktopWidget>
#include <QApplication>
#include <QDebug>
#include <QDir>
#include "connectsql.h"
extern ConnectSql sql;
FMainWindow::FMainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    qDebug("mainwindow init");
    initData();
    initUI();
    initConnect();
}

void FMainWindow::initData()
{
    leftbuttonpressed = false;
    lockmoved = false;
    locked = false;
}

void FMainWindow::initUI()
{
    titleBar = FTitleBar::getInstace();

    setObjectName(QString("FMainWindow"));
    QDesktopWidget* desktopWidget = QApplication::desktop();
    setMaximumSize(desktopWidget->availableGeometry().size());
    readSettings();

    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowMinimizeButtonHint);
	
	setWindowTitle(sql.strtitle);

    pstatusbar = new QStatusBar;
    pstatusbar->setFixedHeight(35);
	pstatusbar->setStyleSheet(QString("QStatusBar::item{border: 0px}"));


	QString currentdatetime = QDateTime::currentDateTime().toString("yyyy-MM-dd  hh:mm:ss");  
	QString strcurrentuser=QApplication::translate("ConnectDB", "\345\275\223\345\211\215\347\224\250\346\210\267", 0, QApplication::UnicodeUTF8);
	QString strtime =QApplication::translate("ConnectDB", "\347\231\273\345\275\225\346\227\266\351\227\264", 0, QApplication::UnicodeUTF8);
	strcurrentuser +=":"+sql.struser+"   ";
	strtime+=":"+currentdatetime;
	QString str=strcurrentuser+strtime;
    pstatusbar->showMessage(str);
	setStatusBar(pstatusbar);


    trayicon = new QSystemTrayIcon(QIcon(QString(":/skin/images/his.ico")), this);
    trayicon->setObjectName(QString("trayicon"));
    trayicon->setToolTip(QString(qApp->applicationName()));
    trayicon->show();
}


void FMainWindow::initConnect( )
{
    connect(titleBar, SIGNAL(minimuned()), this, SIGNAL(Hidden()));
    connect(titleBar, SIGNAL(closed()), this, SLOT(CloseWindow()));
    connect(titleBar, SIGNAL(minimuned()), this, SLOT(hide()));
 //   connect(titleBar, SIGNAL(minimuned()), this, SLOT(showFlyWidget()));
    connect(titleBar, SIGNAL(maximumed()), this, SLOT(swithMaxNormal()));
    //connect(titleBar, SIGNAL(closed()), this, SLOT(hide()));
  //  connect(titleBar, SIGNAL(closed()), this, SLOT(showFlyWidget()));
    connect(trayicon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)),
            this, SLOT(onSystemTrayIconClicked(QSystemTrayIcon::ActivationReason)));
}


void FMainWindow::readSettings()
{
   QDesktopWidget* desktopWidget = QApplication::desktop();
   int w = desktopWidget->availableGeometry().width();
   int h = desktopWidget->availableGeometry().height();
   QSettings settings(QDir::currentPath() + "/HIS.ini", QSettings::IniFormat);
   settings.beginGroup("FMainWindow");
   setFixedSize(settings.value("size", QSize(w * 0.6, h * 0.6)).toSize());
   printf("%d\n" ,(settings.value("size", QSize(w * 0.6, h * 0.6)).toSize().height()));
   printf("%d\n" ,(settings.value("size", QSize(w * 0.6, h * 0.6)).toSize().width()));
   move(settings.value("pos", QPoint(w * 0.2, h * 0.1)).toPoint());
   settings.endGroup();
}

void FMainWindow::writeSettings()
{
    QSettings settings(QDir::currentPath() + "/HIS.ini", QSettings::IniFormat);
    qDebug(qPrintable(QDir::currentPath() + "/HIS.ini"));
    settings.beginGroup("FMainWindow");
    settings.setValue("size", size());
    settings.setValue("pos", pos());
    settings.endGroup();
}

bool FMainWindow::isMoved()
{
    return lockmoved;
}

bool FMainWindow::isLocked()
{
    return locked;
}

void FMainWindow::setLockMoved(bool flag)
{
    lockmoved = flag;
}

void FMainWindow::setLocked(bool flag)
{
    locked = flag;
}

FTitleBar* FMainWindow::getTitleBar()
{
    return titleBar;
}

QStatusBar* FMainWindow::getStatusBar()
{
    return pstatusbar;
}

QSystemTrayIcon* FMainWindow::getQSystemTrayIcon()
{
    return trayicon;
}

void FMainWindow::swithMaxNormal()
{
    if(isMaximized())
    {
        showNormal();
    }else{
        showMaximized();
    }
}



void FMainWindow::mousePressEvent(QMouseEvent *e)
{
    if(e->button() & Qt::LeftButton)
    {
        if(e->y() < titleBar->height() && e->x() > titleBar->width() - 120)
        {
            leftbuttonpressed = false;
        }
        else
        {
            dragPosition = e->globalPos() - frameGeometry().topLeft();
            leftbuttonpressed = true;
        }
    }
    e->accept();
}

void FMainWindow::mouseDoubleClickEvent(QMouseEvent *e)
{
    if(e->y() < titleBar->height() && e->x() < titleBar->width() - 120)
    {
        swithMaxNormal();
        e->accept();
    }else{
        e->ignore();
    }
}

void FMainWindow::SetCursorStyle(enum_Direction direction)
{
    //设置上下左右以及右上、右下、左上、坐下的鼠标形状
    switch(direction)
    {
    case eTop:
    case eBottom:
        setCursor(Qt::SizeVerCursor);
        break;
    case eRight:
    case eLeft:
        setCursor(Qt::SizeHorCursor);
        break;
    case eNormal:
        setCursor(Qt::ArrowCursor);
    default:
        setCursor(Qt::ArrowCursor);
        break;
    }
}

void FMainWindow::mouseReleaseEvent(QMouseEvent *e)
{
    leftbuttonpressed = false;
    titleBar->clearChecked();
    e->accept();
}

void FMainWindow::mouseMoveEvent(QMouseEvent *e)
{
    if(isMaximized())
    {
        e->ignore();
    }
    else
    {

        if(e->y() < titleBar->height() && e->x() > titleBar->width() - 120)
        {
            e->ignore();
        }
        else{
            if(leftbuttonpressed)
            {
                if(getTitleBar()->getFixedflag())
                {
                    move(e->globalPos() - dragPosition);
                }
                e->accept();
            }

        }
    }

}

void FMainWindow::keyPressEvent(QKeyEvent *e)
{
    if(e->key() == Qt::Key_Escape){
        close();
    }
    else if (e->key() == Qt::Key_F11) {
        titleBar->getMaxButton()->click();
    }
}

void FMainWindow::closeEvent(QCloseEvent *event)
{
  //  writeSettings();
    QMainWindow::closeEvent(event);
}


void FMainWindow::animationClose()
{
    QPropertyAnimation *animation = new QPropertyAnimation(this, "windowOpacity");
    connect(animation, SIGNAL(finished()), this, SLOT(close()));
    animation->setDuration(1500);
    animation->setStartValue(1);
    animation->setEndValue(0);
    animation->start();
}

void FMainWindow::onSystemTrayIconClicked(QSystemTrayIcon::ActivationReason reason)
{
    switch(reason)
        {
        //单击
        case QSystemTrayIcon::Trigger:
            //双击
        case QSystemTrayIcon::DoubleClick:
            if(isHidden())
            {
                //恢复窗口显示
                show();
                //一下两句缺一均不能有效将窗口置顶
                setWindowState(Qt::WindowActive);
                activateWindow();
                setLocked(locked);
            }
            else
            {
                if(! locked)
                {
                    hide();
                }
            }
            break;
        case QSystemTrayIcon::Context:
            break;
        default:
            break;
        }
}
void FMainWindow::CloseWindow()
{
	QMessageBox box(QMessageBox::Warning,QApplication::translate("help", "\350\255\246\345\221\212", 0, QApplication::UnicodeUTF8),QApplication::translate("help", "\347\241\256\350\256\244\351\200\200\345\207\272\347\250\213\345\272\217\345\220\227\357\274\237", 0, QApplication::UnicodeUTF8));
	box.setStandardButtons(QMessageBox::Ok|QMessageBox::Cancel);
	box.setButtonText(QMessageBox::Ok,QApplication::translate("User", "\347\241\256\345\256\232", 0, QApplication::UnicodeUTF8));
	box.setButtonText(QMessageBox::Cancel,QApplication::translate("User", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
	if(box.exec()==QMessageBox::Ok)
	{
		this->animationClose();
	}
}
FMainWindow::~FMainWindow()
{
    printf("111111\n");
}
