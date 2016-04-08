#ifndef SYSTEMMANAGEMENT_H
#define SYSTEMMANAGEMENT_H
#include "QFramer/ftabwidget.h"

class SystemManagement : public FTabWidget
{
	Q_OBJECT

public:
	explicit SystemManagement(QWidget *parent = 0);
	void initUI();

private:
	void DrugDictionary();
	void Department();
	void Personnel();
	void ParameterConfig();
};

#endif // SYSTEMMANAGEMENT_H
