#include "mainwindow.h"
#include <QApplication>
#include <test/pulldowntest.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
//    PullDownTest *test=new PullDownTest;
//    test->show();
    return a.exec();
}
