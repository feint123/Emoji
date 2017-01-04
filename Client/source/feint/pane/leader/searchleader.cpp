#include "searchleader.h"
#include "ui_searchleader.h"

#include <QGraphicsDropShadowEffect>

#include <util/graphic/effectutil.h>

SearchLeader::SearchLeader(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SearchLeader)
{
    flag=true;
    ui->setupUi(this);
  //  EffectUtil::addDropShadow(6,this);
    isMenuShow=false;
    ui->fToogleButton->setChecked(true);

    this->baseStyle=tr("background:%1;border:none;color:%2;");
}



void SearchLeader::setMenuIcon(QIcon icon)
{
    ui->menuBtn->setIcon(icon);
}

SearchLeader::~SearchLeader()
{
    flag=false;
    delete ui;
}


void SearchLeader::on_menuBtn_clicked()
{
    isMenuShow=!isMenuShow;
    emit showMenu(isMenuShow);
}

void SearchLeader::createDailyStyle()
{
    QString currentStyle=baseStyle.arg("#e9e9e9").arg("#1d181f");
    ui->frame->setStyleSheet(currentStyle);
}

void SearchLeader::createDarkStyle()
{
    QString currentStyle=baseStyle.arg("#1d181f").arg("#e9e9e9");
    ui->frame->setStyleSheet(currentStyle);
}

bool SearchLeader::getIsMenuShow() const
{
    return isMenuShow;
}

void SearchLeader::setIsMenuShow(bool value)
{
    isMenuShow = value;
}
