#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowFlags( Qt::WindowTitleHint |  Qt::WindowCloseButtonHint |Qt::WindowMinimizeButtonHint | Qt::WindowSystemMenuHint);

    w.show();

    return a.exec();
}
