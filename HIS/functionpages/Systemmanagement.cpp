#include "systemmanagement.h"
#include "QFramer/ftabwidget.h"
#include "QFramer/futil.h"
#include <QtCore/QTextCodec>
#include "systemdepartment.h"
#include "systemdrugdictionary.h"
#include "systemparameter.h"
#include "systempersonnel.h"
SystemManagement::SystemManagement(QWidget *parent):
	FTabWidget(parent)
{
	initUI();
}
void SystemManagement::initUI()
{
	DrugDictionary();
	Department();
	Personnel();	
	ParameterConfig();
	getButtons().at(0)->click();
}
void SystemManagement::DrugDictionary()
{
	QString strText = QString::fromLocal8Bit("药物字典");
	SystemDrugDictionary*drugdictionary = new SystemDrugDictionary;
	addWidget(strText, QString(""), drugdictionary,22);
}
void SystemManagement::Department()
{
	QString strText = QString::fromLocal8Bit("科室部门");
	SystemDepartment*department= new SystemDepartment;
	addWidget(strText, QString(""), department,23);
}
void SystemManagement::Personnel()
{
	QString strText = QString::fromLocal8Bit("人事档案");
	SystemPersonnel*personnel = new SystemPersonnel;
	addWidget(strText, QString(""), personnel,24);
}
void SystemManagement::ParameterConfig()
{
	QString strText = QString::fromLocal8Bit("参数设置");
	SystemParameter*parameterconfig = new SystemParameter;
	addWidget(strText, QString(""), parameterconfig,25);
}