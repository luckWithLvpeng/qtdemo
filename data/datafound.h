#pragma once
#include <QWidget>
#include "ui_datafound.h"

class DataFound : public QWidget {
	Q_OBJECT

public:
	DataFound(QWidget * parent = Q_NULLPTR);
	~DataFound();

private:
	Ui::DataFound ui;
};
