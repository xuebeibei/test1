#ifndef INTERFACE_H
#define INTERFACE_H
#include "QFramer/ftabwidget.h"

class Interface : public FTabWidget
{
	Q_OBJECT

public:
	Interface(QWidget *parent = 0);
	void initUI();
	void clinic();
	void hospitalisation();
	void dictionary();
private:
	
};

#endif // INTERFACE_H
