

#include "ftabwidget.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QBoxLayout>
#include <QStackedLayout>
FTabWidget::FTabWidget(QWidget *parent) :
    QWidget(parent)
{
    initUI();
    initConnect();
}

void FTabWidget::initUI()
{
    tabTile = new QWidget;
    tabTile->setObjectName(QString("FTabTile"));

    stackLayout = new QStackedLayout;
    tabLayout = new QVBoxLayout;
    tabLayout->addStretch();
    tabLayout->setContentsMargins(0, 0, 0, 0);
    tabLayout->setSpacing(15);
    tabTile->setLayout(tabLayout);

    mainLayout = new QHBoxLayout;
    mainLayout->addWidget(tabTile);
    mainLayout->addLayout(stackLayout);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->setSpacing(0);
    setLayout(mainLayout);
}

void FTabWidget::initConnect()
{


}

void FTabWidget::addWidget(const QString &tile, const QString &objectName, QWidget *widget,int index)
{
    buttonTitles  << tile;
    FCheckabelButton* button = new FCheckabelButton(tile);
    buttons.append(button);
//    button->setObjectName(objectName);
    button->setFixedSize(120, 70);
	button->setAutoFillBackground(true);

	if (index==1)
	{
		button->setStyleSheet("QPushButton{background-image: url(:/skin/his/menzhenguanli/menzhenshoufei.ico);background-repeat:no-repeat;background-position: center top;background-color: transparent;color: dark;text-align: center bottom;padding-bottom: 2px;}"
			"QPushButton:hover{background-color: rgb(85,170,255);color: dark;}"
			"QPushButton:pressed{background-color: rgb(240,240,240);color: dark;}"
			"QPushButton:checked{background-color: rgb(85,170,255);color: dark;}");
		
	}
	if (index==2)
	{
	
		button->setStyleSheet("QPushButton{background-image: url(:/skin/his/menzhenguanli/rijie.ico);background-repeat:no-repeat;background-position: center top;background-color: transparent;color: dark;text-align: center bottom;padding-bottom: 2px;}"
			"QPushButton:hover{background-color: rgb(85,170,255);color: dark;}"
			"QPushButton:pressed{background-color: rgb(240,240,240);color: dark;}"
			"QPushButton:checked{background-color: rgb(85,170,255);color: dark;}");
	}
	if (index==3)
	{

		button->setStyleSheet("QPushButton{background-image:  url(:/skin/his/menzhenguanli/dayinkuozhantongji.ico);background-repeat:no-repeat;background-position: center top;background-color: transparent;color: dark;text-align: center bottom;padding-bottom: 2px;}"
			"QPushButton:hover{background-color: rgb(85,170,255);color: dark;}"
			"QPushButton:pressed{background-color: rgb(240,240,240);color: dark;}"
			"QPushButton:checked{background-color: rgb(85,170,255);color: dark;}");
	}
	if (index==4)
	{

		button->setStyleSheet("QPushButton{background-image: url(:/skin/his/menzhenguanli/niebujiaokuan.ico);background-repeat:no-repeat;background-position: center top;background-color: transparent;color: dark;text-align: center bottom;padding-bottom: 2px;}"
			"QPushButton:hover{background-color: rgb(85,170,255);color: dark;}"
			"QPushButton:pressed{background-color: rgb(240,240,240);color: dark;}"
			"QPushButton:checked{background-color: rgb(85,170,255);color: dark;}");
	}
	if (index==5)
	{

		button->setStyleSheet("QPushButton{background-image:  url(:/skin/his/menzhenguanli/yaofangkucun.ico);background-repeat:no-repeat;background-position: center top;background-color: transparent;color: dark;text-align: center bottom;padding-bottom: 2px;}"
			"QPushButton:hover{background-color: rgb(85,170,255);color: dark;}"
			"QPushButton:pressed{background-color: rgb(240,240,240);color: dark;}"
			"QPushButton:checked{background-color: rgb(85,170,255);color: dark;}");
	}




	if (index==6)
	{
		button->setStyleSheet("QPushButton{background-image: url(:/skin/his/zhuyuanguanli/ruyuandengji.ico);background-repeat:no-repeat;background-position: center top;background-color: transparent;color: dark;text-align: center bottom;padding-bottom: 2px;}"
			"QPushButton:hover{background-color: rgb(85,170,255);color: dark;}"
			"QPushButton:pressed{background-color: rgb(240,240,240);color: dark;}"
			"QPushButton:checked{background-color: rgb(85,170,255);color: dark;}");
	}
	if (index==7)
	{
		button->setStyleSheet("QPushButton{background-image: url(:/skin/his/zhuyuanguanli/zhuyuanchaxun.ico);background-repeat:no-repeat;background-position: center top;background-color: transparent;color: white;text-align: center bottom;padding-bottom: 2px;}"
			"QPushButton:hover{background-color: rgb(85,170,255);color: dark;}"
			"QPushButton:pressed{background-color: rgb(240,240,240);color: dark;}"
			"QPushButton:checked{background-color: rgb(85,170,255);color: dark;}");
	}
	if (index==8)
	{
		button->setStyleSheet("QPushButton{background-image: url(:/skin/his/zhuyuanguanli/jiaokuan.ico);background-repeat:no-repeat;background-position: center top;background-color: transparent;color: dark;text-align: center bottom;padding-bottom: 2px;}"
			"QPushButton:hover{background-color: rgb(85,170,255);color: dark;}"
			"QPushButton:pressed{background-color: rgb(240,240,240);color: dark;}"
			"QPushButton:checked{background-color: rgb(85,170,255);color: dark;}");
	}
	if (index==9)
	{
		button->setStyleSheet("QPushButton{background-image: url(:/skin/his/zhuyuanguanli/zhuyuanshoufei.ico);background-repeat:no-repeat;background-position: center top;background-color: transparent;color: dark;text-align: center bottom;padding-bottom: 2px;}"
			"QPushButton:hover{background-color: rgb(85,170,255);color: dark;}"
			"QPushButton:pressed{background-color: rgb(240,240,240);color: dark;}"
			"QPushButton:checked{background-color: rgb(85,170,255);color: dark;}");
	}
	if (index==10)
	{
		button->setStyleSheet("QPushButton{background-image: url(:/skin/his/menzhenguanli/dayinkuozhantongji.ico);background-repeat:no-repeat;background-position: center top;background-color: transparent;color: dark;text-align: center bottom;padding-bottom: 2px;}"
			"QPushButton:hover{background-color: rgb(85,170,255);color: dark;}"
			"QPushButton:pressed{background-color: rgb(240,240,240);color: dark;}"
			"QPushButton:checked{background-color: rgb(85,170,255);color: dark;}");
	}
	if (index==11)
	{
		button->setStyleSheet("QPushButton{background-image: url(:/skin/his/zhuyuanguanli/zhuankezhuanchuang.ico);background-repeat:no-repeat;background-position: center top;background-color: transparent;color: dark;text-align: center bottom;padding-bottom: 2px;}"
			"QPushButton:hover{background-color: rgb(85,170,255);color: dark;}"
			"QPushButton:pressed{background-color: rgb(240,240,240);color: dark;}"
			"QPushButton:checked{background-color: rgb(85,170,255);color: dark;}");
	}
	if (index==12)
	{
		button->setStyleSheet("QPushButton{background-image: url(:/skin/his/zhuyuanguanli/chuyuan.ico);background-repeat:no-repeat;background-position: center top;background-color: transparent;color: dark;text-align: center bottom;padding-bottom: 2px;}"
			"QPushButton:hover{background-color: rgb(85,170,255);color: dark;}"
			"QPushButton:pressed{background-color: rgb(240,240,240);color: dark;}"
			"QPushButton:checked{background-color: rgb(85,170,255);color: dark;}");
	}


	if (index==13)
	{
		button->setStyleSheet("QPushButton{background-image: url(:/skin/his/yaokuguanli/yaopinruku.ico);background-repeat:no-repeat;background-position: center top;background-color: transparent;color: dark;text-align: center bottom;padding-bottom: 2px;}"
			"QPushButton:hover{background-color: rgb(85,170,255);color: dark;}"
			"QPushButton:pressed{background-color: rgb(240,240,240);color: dark;}"
			"QPushButton:checked{background-color: rgb(85,170,255);color: dark;}");
	}

	if (index==14)
	{
		button->setStyleSheet("QPushButton{background-image: url(:/skin/his/yaokuguanli/yaopindiaobo.ico);background-repeat:no-repeat;background-position: center top;background-color: transparent;color: dark;text-align: center bottom;padding-bottom: 2px;}"
			"QPushButton:hover{background-color: rgb(85,170,255);color: dark;}"
			"QPushButton:pressed{background-color: rgb(240,240,240);color: dark;}"
			"QPushButton:checked{background-color: rgb(85,170,255);color: dark;}");
	}
	if (index==15)
	{
		button->setStyleSheet("QPushButton{background-image: url(:/skin/his/yaokuguanli/kucunpandian.ico);background-repeat:no-repeat;background-position: center top;background-color: transparent;color: dark;text-align: center bottom;padding-bottom: 2px;}"
			"QPushButton:hover{background-color: rgb(85,170,255);color: dark;}"
			"QPushButton:pressed{background-color: rgb(240,240,240);color: dark;}"
			"QPushButton:checked{background-color: rgb(85,170,255);color: dark;}");
	}
	if (index==16)
	{
		button->setStyleSheet("QPushButton{background-image: url(:/skin/his/yaokuguanli/tiaojia.ico);background-repeat:no-repeat;background-position: center top;background-color: transparent;color: dark;text-align: center bottom;padding-bottom: 2px;}"
			"QPushButton:hover{background-color: rgb(85,170,255);color: dark;}"
			"QPushButton:pressed{background-color: rgb(240,240,240);color: dark;}"
			"QPushButton:checked{background-color: rgb(85,170,255);color: dark;}");
	}
	if (index==17)
	{
		button->setStyleSheet("QPushButton{background-image: url(:/skin/his/yaokuguanli/tongjichaxun.ico);background-repeat:no-repeat;background-position: center top;background-color: transparent;color: dark;text-align: center bottom;padding-bottom: 2px;}"
			"QPushButton:hover{background-color: rgb(85,170,255);color: dark;}"
			"QPushButton:pressed{background-color: rgb(240,240,240);color: dark;}"
			"QPushButton:checked{background-color: rgb(85,170,255);color: dark;}");
	}


	if (index==18)
	{
		button->setStyleSheet("QPushButton{background-image: url(:/skin/his/yaofangguanli/diaoboshouhuo.ico);background-repeat:no-repeat;background-position: center top;background-color: transparent;color: dark;text-align: center bottom;padding-bottom: 2px;}"
			"QPushButton:hover{background-color: rgb(85,170,255);color: dark;}"
			"QPushButton:pressed{background-color: rgb(240,240,240);color: dark;}"
			"QPushButton:checked{background-color: rgb(85,170,255);color: dark;}");
	}
	if (index==19)
	{
		button->setStyleSheet("QPushButton{background-image: url(:/skin/his/yaofangguanli/pandian.ico);background-repeat:no-repeat;background-position: center top;background-color: transparent;color: dark;text-align: center bottom;padding-bottom: 2px;}"
			"QPushButton:hover{background-color: rgb(85,170,255);color: dark;}"
			"QPushButton:pressed{background-color: rgb(240,240,240);color: dark;}"
			"QPushButton:checked{background-color: rgb(85,170,255);color: dark;}");
	}
	if (index==20)
	{
		button->setStyleSheet("QPushButton{background-image: url(:/skin/his/yaofangguanli/kucun.ico);background-repeat:no-repeat;background-position: center top;background-color: transparent;color: dark;text-align: center bottom;padding-bottom: 2px;}"
			"QPushButton:hover{background-color: rgb(85,170,255);color: dark;}"
			"QPushButton:pressed{background-color: rgb(240,240,240);color: dark;}"
			"QPushButton:checked{background-color: rgb(85,170,255);color: dark;}");
	}
	if (index==21)
	{
		button->setStyleSheet("QPushButton{background-image: url(:/skin/his/yaofangguanli/pandianchaxun.ico);background-repeat:no-repeat;background-position: center top;background-color: transparent;color: dark;text-align: center bottom;padding-bottom: 2px;}"
			"QPushButton:hover{background-color: rgb(85,170,255);color: dark;}"
			"QPushButton:pressed{background-color: rgb(240,240,240);color: dark;}"
			"QPushButton:checked{background-color: rgb(85,170,255);color: dark;}");
	}


	if (index==22)
	{
		button->setStyleSheet("QPushButton{background-image: url(:/skin/his/xitongguanli/yaowuzidian.ico);background-repeat:no-repeat;background-position: center top;background-color: transparent;color: dark;text-align: center bottom;padding-bottom: 2px;}"
			"QPushButton:hover{background-color: rgb(85,170,255);color: dark;}"
			"QPushButton:pressed{background-color: rgb(240,240,240);color: dark;}"
			"QPushButton:checked{background-color: rgb(85,170,255);color: dark;}");
	}

	if (index==23)
	{
		button->setStyleSheet("QPushButton{background-image: url(:/skin/his/xitongguanli/keshibumen.ico);background-repeat:no-repeat;background-position: center top;background-color: transparent;color: dark;text-align: center bottom;padding-bottom: 2px;}"
			"QPushButton:hover{background-color: rgb(85,170,255);color: dark;}"
			"QPushButton:pressed{background-color: rgb(240,240,240);color: dark;}"
			"QPushButton:checked{background-color: rgb(85,170,255);color: dark;}");
	}
	if (index==24)
	{
		button->setStyleSheet("QPushButton{background-image: url(:/skin/his/xitongguanli/renshidangan.ico);background-repeat:no-repeat;background-position: center top;background-color: transparent;color: dark;text-align: center bottom;padding-bottom: 2px;}"
			"QPushButton:hover{background-color: rgb(85,170,255);color: dark;}"
			"QPushButton:pressed{background-color: rgb(240,240,240);color: dark;}"
			"QPushButton:checked{background-color: rgb(85,170,255);color: dark;}");
	}
	if (index==25)
	{
		button->setStyleSheet("QPushButton{background-image: url(:/skin/his/xitongguanli/canshushezhi.ico);background-repeat:no-repeat;background-position: center top;background-color: transparent;color: dark;text-align: center bottom;padding-bottom: 2px;}"
			"QPushButton:hover{background-color: rgb(85,170,255);color: dark;}"
			"QPushButton:pressed{background-color: rgb(240,240,240);color: dark;}"
			"QPushButton:checked{background-color: rgb(85,170,255);color: dark;}");
	}
	if (index==26)
	{
		button->setStyleSheet("QPushButton{background-image: url(:/skin/his/xitongguanli/yaowuzidian.ico);background-repeat:no-repeat;background-position: center top;background-color: transparent;color: dark;text-align: center bottom;padding-bottom: 2px;}"
			"QPushButton:hover{background-color: rgb(85,170,255);color: dark;}"
			"QPushButton:pressed{background-color: rgb(240,240,240);color: dark;}"
			"QPushButton:checked{background-color: rgb(85,170,255);color: dark;}");
	}
	if (index==27)
	{
		button->setStyleSheet("QPushButton{background-image: url(:/skin/his/xitongguanli/yaowuzidian.ico);background-repeat:no-repeat;background-position: center top;background-color: transparent;color: dark;text-align: center bottom;padding-bottom: 2px;}"
			"QPushButton:hover{background-color: rgb(85,170,255);color: dark;}"
			"QPushButton:pressed{background-color: rgb(240,240,240);color: dark;}"
			"QPushButton:checked{background-color: rgb(85,170,255);color: dark;}");
	}

	if (index==28)
	{
		button->setStyleSheet("QPushButton{background-image: url(:/skin/his/yibao/canshu.ico);background-repeat:no-repeat;background-position: center top;background-color: transparent;color: dark;text-align: center bottom;padding-bottom: 2px;}"
				"QPushButton:hover{background-color: rgb(85,170,255);color: dark;}"
			"QPushButton:pressed{background-color: rgb(240,240,240);color: dark;}"
			"QPushButton:checked{background-color: rgb(85,170,255);color: dark;}");
	}

	if (index==29)
	{
		button->setStyleSheet("QPushButton{background-image: url(:/skin/his/yibao/menzhen.ico);background-repeat:no-repeat;background-position: center top;background-color: transparent;color: dark;text-align: center bottom;padding-bottom: 2px;}"
			"QPushButton:hover{background-color: rgb(85,170,255);color: dark;}"
			"QPushButton:pressed{background-color: rgb(240,240,240);color: dark;}"
			"QPushButton:checked{background-color: rgb(85,170,255);color: dark;}");
	}

	if (index==30)
	{
		button->setStyleSheet("QPushButton{background-image: url(:/skin/his/yibao/zhuyuan.ico);background-repeat:no-repeat;background-position: center top;background-color: transparent;color: dark;text-align: center bottom;padding-bottom: 2px;}"
			"QPushButton:hover{background-color: rgb(85,170,255);color: dark;}"
			"QPushButton:pressed{background-color: rgb(240,240,240);color: dark;}"
			"QPushButton:checked{background-color: rgb(85,170,255);color: dark;}");
	}
	QFont f("ZYSong18030", 10);
	button->setFont(f);
    tabLayout->insertWidget(tabLayout->count() - 1, button);
    connect(button, SIGNAL(clicked()), this, SLOT(setButtonChecked()));
//    widget->setObjectName(objectName);
    stackLayout->addWidget(widget);
}

QList<FCheckabelButton*> FTabWidget::getButtons()
{
    return buttons;
}

void FTabWidget::setButtonChecked()
{
    for (int i = 0; i < buttons.size(); ++i) {
        if (buttons.at(i) == sender())
        {
            buttons.at(i)->setChecked(true);
            stackLayout->setCurrentIndex(i);
            emit indexChanged(i);
        }
        else{
            buttons.at(i)->setChecked(false);
        }
    }
}
