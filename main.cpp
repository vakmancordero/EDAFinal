#include "edawindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    EDAWindow w;
    w.show();

    return a.exec();
}
