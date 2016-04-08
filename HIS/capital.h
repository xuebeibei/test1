#ifndef CAPITAL_H
#define CAPITAL_H

#include <QObject>
#include <QStringList>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QSqlError>
#include <QTableView>
#define MAX 100

class Capital
{
public:
	Capital();
	int ReplaceSubStr(std::string &strOrig, std::string strSub, std::string strReplace);
	QString NumToChineseStr(double money);
private:

};

#endif // CAPITAL_H
