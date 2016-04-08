#include "QFramer/futil.h"
#include "mainwindow/mainwindow.h"
#include <QApplication>
#include "connectsql.h"
#include "connectdb.h"
#include <qtextcodec.h>
#include <QTextEdit>  
#include <QSplashScreen>  
#include <QThread>
#include <QSqlDatabase>
#include <QFont>
extern ConnectSql sql;
class SleeperThread : public QThread
{
public:
	static void msleep(unsigned long msecs)
	{
		QThread::msleep(msecs);
	}
};
int main(int argc, char *argv[])
{

    QApplication app(argc, argv);
    QApplication::setApplicationName("HIS");
    QApplication::setWindowIcon(QIcon(":/images/skin/images/his.ico"));
	QTextCodec::setCodecForLocale(QTextCodec::codecForName("GBK"));
	QApplication::addLibraryPath("./plugins");
	QFont font  = app.font();
	font.setPointSize(9);
	app.setFont(font);

	QTranslator trans;  
	trans.load(":/qt_zh_CN");  
	app.installTranslator(&trans);  

	ConnectDB connectdatase;
    int currentExitCode = 0;
	if(connectdatase.exec())
	{
		do{
			MainWindow *main = MainWindow::getInstance();
			main->initData(connectdatase.IsAdmin,true);
			main->setAttribute(Qt::WA_DeleteOnClose);			
			main->show();
			setSkinForApp(QString(":/qss/skin/qss/GB.qss"));
			currentExitCode = app.exec();

		}while( currentExitCode == EXIT_CODE_REBOOT );
	}
    return 0;
}
