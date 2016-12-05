#include "normaltoolpane.h"
#include "ui_normaltoolpane.h"

NormalToolPane::NormalToolPane(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NormalToolPane)
{
    ui->setupUi(this);
}

NormalToolPane::~NormalToolPane()
{
    delete ui;
}
