#include "logindialog.h"
#include "ui_logindialog.h"

#include <main/mainwindow.h>

#include <QPainter>

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);

}

LoginDialog::~LoginDialog()
{
    delete ui;
}


void LoginDialog::on_travelBtn_clicked()
{
    MainWindow *main=new MainWindow;
    main->show();
    this->close();
}

void LoginDialog::paintEvent(QPaintEvent *event)
{

}

