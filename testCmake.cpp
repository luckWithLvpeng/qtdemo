#include "testCmake.h"
#include "QtWidgets"
#include "about.h"
#include "datafound.h"
#include "data.hpp"

testCmake::testCmake(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
	About *about = new About(ui.content);
	DataFound * datafound= new DataFound(ui.content);
	Data * data = new Data(ui.content);

	// 设置content的布局
	contentLayout = new QHBoxLayout(ui.content);
	contentLayout->setSpacing(0);
	contentLayout->setContentsMargins(0, 0, 0, 0);

	// 按钮绑定页面
	btnBindContent(ui.btnData, data, "data");
	btnBindContent(ui.btnAbout, about, "about");
	btnBindContent(ui.btnDataFound, datafound, "datafound");
	// 默认展示 data
	navShow("about");
}
void testCmake::btnBindContent(QPushButton * btn, QWidget* contetnt, QString name)
{
	contetnt->hide();
	QMap<QString, QWidget*> tmp;
	tmp["btn"] = btn;
	tmp["content"] = contetnt;
	navMap[name] = tmp;

	// 绑定按钮点击事件
	connect(btn, &QPushButton::clicked, this, [=]() {
		navShow(name);
	});
}
void testCmake::navShow(QString name)
{
	QList<QString> navKeys = navMap.keys();
	for (int i = 0; i< navKeys.size(); i++)
	{
		if (navKeys[i] == name)
		{
			contentLayout->addWidget(navMap[navKeys[i]]["content"]);
			navMap[navKeys[i]]["content"]->show();
			static_cast<QPushButton*>(navMap[navKeys[i]]["btn"])->setChecked(true);
		}
		else
		{
			contentLayout->removeWidget(navMap[navKeys[i]]["content"]);
			navMap[navKeys[i]]["content"]->hide();
			static_cast<QPushButton*>(navMap[navKeys[i]]["btn"])->setChecked(false);
		}
	}
}
