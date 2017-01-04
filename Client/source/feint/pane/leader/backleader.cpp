#include "backleader.h"
#include "ui_backleader.h"

#include <util/graphic/effectutil.h>

BackLeader::BackLeader(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BackLeader)
{
    flag=true;
    ui->setupUi(this);
    EffectUtil::addDropShadow(6,this);
    baseStyle=tr("background:%1;border:none;color:%2");
}

void BackLeader::setBackId(int id)
{
    backId=id;
}

void BackLeader::setIcon(QIcon back, QIcon setting)
{
    ui->backBtn->setIcon(back);
    ui->setBtn->setIcon(setting);
}

void BackLeader::setTitle(QString title)
{
    ui->label->setText(title);
    this->title=title;
}

QString BackLeader::getTitle()
{
    return title;
}

BackLeader::~BackLeader()
{
    flag=false;
    delete ui;
}


void BackLeader::on_backBtn_clicked()
{
    emit back(backId);
}

void BackLeader::createDailyStyle()
{
    QString currentStyle=baseStyle.arg("#e9e9e9").arg("#252526");
    ui->frame->setStyleSheet(currentStyle);
}

void BackLeader::createDarkStyle()
{
    QString currentStyle=baseStyle.arg("#252526").arg("#e9e9e9");
    ui->frame->setStyleSheet(currentStyle);
}
