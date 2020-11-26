#pragma once

#ifndef TESTCMAKE_H
#endif

#include <QtWidgets/QMainWindow>
#include "ui_testCmake.h"
#include <QMap>
#include <QtWidgets>

class testCmake : public QMainWindow
{
    Q_OBJECT

public:
    testCmake(QWidget *parent = Q_NULLPTR);

private:
	// 内容布局
	QHBoxLayout * contentLayout;
	QMap<QString, QMap<QString,QWidget*>> navMap;

	void btnBindContent(QPushButton* , QWidget*, QString);
	// 显示内容
	void navShow(QString);
    Ui::testCmakeClass ui;
};
