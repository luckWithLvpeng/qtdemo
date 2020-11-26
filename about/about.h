#pragma once
#include <QWidget>
namespace Ui {class About;}

class About : public QWidget {
	Q_OBJECT

public:
	About(QWidget * parent = Q_NULLPTR);
	~About();

private:
	Ui::About *ui;
};
