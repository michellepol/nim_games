#include "headers/mainwindow.h"
#include "headers/menuwindow.h"
#include "headers/gamewindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w(nullptr);
    w.show();
    return a.exec();
}
