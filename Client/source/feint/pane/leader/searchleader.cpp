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

void SearchLeader::setSettingIcon(QIcon icon)
{
    ui->setBtn->setIcon(icon);
}

void SearchLeader::setMenuIcon(QIcon icon)
{
    ui->menuBtn->setIcon(icon);
}

SearchLeader::~SearchLeader()
{
    delete ui;
}


void SearchLeader::on_menuBtn_clicked()
{
    isMenuShow=!isMenuShow;
    emit showMenu(isMenuShow);
}

bool SearchLeader::getIsMenuShow() const
{
    return isMenuShow;
}

void SearchLeader::setIsMenuShow(bool value)
{
    isMenuShow = value;
}
