#include "mainwindow.h"
#include <QApplication>
#include <iostream>
#include "settings.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    qApp->setWindowIcon(QIcon(":/new/prefix1/img/icons8-round-filled-50.png"));
    //qApp->setFont(QFont("Courier"));


#if (defined (_WIN32) || defined (_WIN64))
    std::cout << "I'm on Windows!" << std::endl;
#elif (defined (LINUX) || defined (__linux__))
    std::cout << "I'm on Linux!" << std::endl;
#endif


    MainWindow w;
    w.show();

    return a.exec();
}
