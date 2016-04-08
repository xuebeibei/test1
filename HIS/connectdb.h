#ifndef CONNECTDB_H
#define CONNECTDB_H

#include <QtGui>
#include <QDialog>
#include "ui_connectdb.h"
#include<QFileDialog>
namespace Ui {
	class ConnectDB;
}
class ConnectDB : public QDialog
{
	Q_OBJECT

public:
	ConnectDB(QWidget *parent = 0);
	~ConnectDB();
	void initUI();
	bool IsAdmin;
	bool IsAuthorized;
	bool  Isconnect;
	QListView *namelistview; 
	QStringListModel *model; 
private:
	Ui::ConnectDB *ui;
	bool eventFilter(QObject*obj,QEvent*event);
	void keyPressEvent(QEvent* event);
	private slots:
		bool on_okButton_clicked();
		void on_cancelButton_clicked();
		void onChanged(int index);
		void on_openButton_clicked();
		void on_loginButton_clicked();
		void on_cancelButton_2_clicked();
		void on_exitButton_clicked();
		void on_closeButton_clicked();
		void setCompleter(const QString &text); 
		void completeText(const QModelIndex &index);
};

#endif // CONNECTDB_H
