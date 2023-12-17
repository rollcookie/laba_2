#include "Images.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Images w;
    w.show();
    return a.exec();
}
