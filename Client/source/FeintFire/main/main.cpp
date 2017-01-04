
#include "mainwindow.h"

#include <QApplication>
#include <QDir>
#include <form.h>

#include <user/logindialog.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    LoginDialog login;
    login.show();


//    Form form;
//    form.show();
    return a.exec();
}
