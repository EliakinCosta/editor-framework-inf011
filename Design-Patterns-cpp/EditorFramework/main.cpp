#include "mainwindow.h"
#include <QApplication>
#include "core.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Core *core = Core::getInstance();
    return a.exec();

    delete core;
}
