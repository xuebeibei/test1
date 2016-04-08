#ifndef HISDICTONARY_H
#define HISDICTONARY_H

#include <QWidget>
#include "ui_hisdictonary.h"

class Hisdictonary : public QWidget
{
	Q_OBJECT

public:
	Hisdictonary(QWidget *parent = 0);
	~Hisdictonary();

private:
	Ui::Hisdictonary ui;
};

#endif // HISDICTONARY_H
