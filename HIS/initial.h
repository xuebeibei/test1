#ifndef INITIAL_H
#define INITIAL_H
#include <string>
#include <QtGui>
#include <QWidget>
using namespace std;
class Initial
{
public:
    Initial();
    ~Initial();
    QString GetIntial(QString strname);
	QString getPinyinByName(QString strName);
private:
    static char Convert(wchar_t n);
    static bool Input(wchar_t start, wchar_t end, wchar_t code);
private:
    char *m_buff;
};

#endif // INITIAL_H