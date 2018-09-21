#include <QtGui/QApplication>
#include "mainwindow.h"
#include <iostream>
#include "SiecNeuronowa/SiecDwuwarstwowa.h"

int main(int argc, char *argv[])
{
    try
    {
        QApplication a(argc, argv);
        MainWindow w;
        w.show();
        return a.exec();
    }
    catch(...)
    {
        std::cout << "ERROR\n";
    }
    return 0;
}
