

#ifndef SETTINGMENUCONTROLLER_H
#define SETTINGMENUCONTROLLER_H

#include <QObject>

class SettingMenuController : public QObject
{
    Q_OBJECT
public:
    explicit SettingMenuController(QObject *parent = 0);

signals:

public slots:
    void checkUpdate();
    void onlineHelp();
    void visitOfficialSite();
    void showAboutUs();
    void closeMainWindow();
	void restartMainWindow();
};

#endif // FSETTINGMENUCONTROLLER_H
