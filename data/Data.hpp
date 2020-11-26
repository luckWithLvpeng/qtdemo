#pragma once
#include <QWidget>
#include "ui_Data.h"

class Data : public QWidget {
	Q_OBJECT

public:
	Data(QWidget * parent = Q_NULLPTR);
	~Data();

private:
	Ui::Data ui;
};
