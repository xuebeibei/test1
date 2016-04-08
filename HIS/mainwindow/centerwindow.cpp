#include "centerwindow.h"
#include "QFramer/fwigglywidget.h"
#include <QHBoxLayout>
#include <QGridLayout>
#include <QGroupBox>
#include <QLabel>
#include <QPushButton>
#include <QRadioButton>
#include <QCheckBox>
#include <QTreeWidget>
#include <QTabWidget>
#include <QSplitter>
#include <QHeaderView>
#include <QProgressBar>
#include <QTimer>
#include <QGraphicsScene>
#include "DrugStorageManagement.h"
#include "PharmacyManagement.h"
#include "DataInterface.h"
#include "systemadmin.h"
CenterWindow::CenterWindow(QWidget *parent) :
    FCenterWindow(parent)
{
    initUI();
	connect(hospitalisationmanage->registry,SIGNAL(hospitalisationmanage->registry->refresh()), this, SLOT(hospitalisationmanage->pay->initUI()));

}
void CenterWindow::initUI()
{
    clinicmanage = new ClinicManagement;
	hospitalisationmanage = new HospitalizationManagement;
	DrugStorageManagement*drugstoragemanage = new DrugStorageManagement;
	PharmacyManagement*pharmacymanage= new PharmacyManagement;
	SystemManagement*systemmanagement =new SystemManagement;
	Interface*interface= new Interface;
	SystemAdmin*systemmanage = new SystemAdmin;
	QString str = str.fromLocal8Bit("�������");
    addWidget(str, "Menzhen", clinicmanage);

    str = str.fromLocal8Bit("סԺ����");
    addWidget(str,"Zhuyuan",hospitalisationmanage);

	str = str.fromLocal8Bit("ҩ�����");	
    addWidget(str,"Yaoku", drugstoragemanage);

 	 str = str.fromLocal8Bit("ҩ������");
 	addWidget(str,"Yaofang", pharmacymanage);
 
	str = str.fromLocal8Bit("���ݽӿ�");
	addWidget(str,"Shujujiekou", interface);

	str = str.fromLocal8Bit("ϵͳ����");
	addWidget(str,"SystemAdmin", systemmanage);
	
    setAlignment(TopCenter);
}
void CenterWindow::addWiggleWiget()
{
	QString str = str.fromLocal8Bit("HIS");
    FWigglyWidget* wiggleWidget = new FWigglyWidget(str, getNavgationBar());
    wiggleWidget->move(40, 5);
    wiggleWidget->setFixedSize(400, 60);
    wiggleWidget->setStyleSheet("background-color: transparent;\
                                 font-size: 20px;");
								 
}
