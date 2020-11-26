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

	// ����content�Ĳ���
	contentLayout = new QHBoxLayout(ui.content);
	contentLayout->setSpacing(0);
	contentLayout->setContentsMargins(0, 0, 0, 0);

	// ��ť��ҳ��
	btnBindContent(ui.btnData, data, "data");
	btnBindContent(ui.btnAbout, about, "about");
	btnBindContent(ui.btnDataFound, datafound, "datafound");
	// Ĭ��չʾ data
	navShow("about");
}
void testCmake::btnBindContent(QPushButton * btn, QWidget* contetnt, QString name)
{
	contetnt->hide();
	QMap<QString, QWidget*> tmp;
	tmp["btn"] = btn;
	tmp["content"] = contetnt;
	navMap[name] = tmp;

	// �󶨰�ť����¼�
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
