#include "searchleader.h"
#include "ui_searchleader.h"

#include <QGraphicsDropShadowEffect>

SearchLeader::SearchLeader(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SearchLeader)
{
    ui->setupUi(this);
    QGraphicsDropShadowEffect *ef=new QGraphicsDropShadowEffect(this);
    ef->setXOffset(0);
    ef->setYOffset(2);
    ef->setBlurRadius(5);
    ef->setColor(QColor("#ccc"));
    this->setGraphicsEffect(ef);

    isMenuShow=false;
}

SearchLeader::~SearchLeader()
{
    delete ui;
}

void SearchLeader::on_pushButton_clicked()
{
    isMenuShow=!isMenuShow;
    emit showMenu(isMenuShow);
}
