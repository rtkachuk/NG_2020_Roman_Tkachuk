#include "simpleapp.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    simpleapp w;
    w.show();
    return a.exec();
}
