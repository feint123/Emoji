#include "showpane.h"
#include "ui_showpane.h"

ShowPane::ShowPane(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ShowPane)
{
    ui->setupUi(this);
}

ShowPane::~ShowPane()
{
    delete ui;
}
