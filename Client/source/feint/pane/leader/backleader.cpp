#include "backleader.h"
#include "ui_backleader.h"

BackLeader::BackLeader(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BackLeader)
{
    ui->setupUi(this);
}

BackLeader::~BackLeader()
{
    delete ui;
}

void BackLeader::on_pushButton_2_clicked()
{
    emit back(0);
}
