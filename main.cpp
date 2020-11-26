#include "testCmake.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    testCmake w;
    w.show();
    return a.exec();
}
