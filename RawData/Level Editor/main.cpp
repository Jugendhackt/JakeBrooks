#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w(QString("levels.csv"));
    w.show();

    return a.exec();
}
