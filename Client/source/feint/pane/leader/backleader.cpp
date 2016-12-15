#include "backleader.h"
#include "ui_backleader.h"

BackLeader::BackLeader(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BackLeader)
{
    ui->setupUi(this);
}

void BackLeader::setBackId(int id)
{
    backId=id;
}

BackLeader::~BackLeader()
{
    delete ui;
}

void BackLeader::on_pushButton_2_clicked()
{
    emit back(backId);
}
