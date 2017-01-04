#include "cardcell.h"
#include "ui_cardcell.h"

#include <QGraphicsDropShadowEffect>
#include <QDebug>
CardCell::CardCell(QWidget *parent) :
    FScaleFrame(parent),
    ui(new Ui::CardCell)
{
    ui->setupUi(this);
    baseStyle=tr("QPushButton{border:none;color:%1;padding:8px;} #frame{background:%2;}");
    titleStyle=tr("color:%1;font-size:15pt;font-weight:bold;");
}

CardCell::~CardCell()
{
    delete ui;
}

void CardCell::setCard(InvitationCard card)
{
    ui->titleLab->setText(card.tname());
    ui->tipLab->setText(card.tip());
    qDebug()<<"CardCell[setCard]: "<<card.date();
    ui->dateLab->setText(card.date().toString("yyyy-MM-dd"));
    ui->surportLab->setText(QString::number(card.support()));
//    ui->hotLab->setHot(card.hot());
    ui->hotLab->setHot(1);
//    if(card.getSupported())
//        ui->surportBtn->setText("取消赞");
//    else
//        ui->surportBtn->setText("赞");
//    if(card.getCollected())
//        ui->collectBtn->setText("取消收藏");
//    else
    //        ui->collectBtn->setText("收藏");
}

void CardCell::createDailyStyle()
{
    ui->frame->setStyleSheet(baseStyle.arg("#aaa").arg("#e9e9e9"));
    ui->titleLab->setStyleSheet(titleStyle.arg("#252526"));
    ui->tipLab->setStyleSheet("color:#404244;background:#e9e9e9");
}

void CardCell::createDarkStyle()
{
    ui->frame->setStyleSheet(baseStyle.arg("#666").arg("#252526"));
    ui->titleLab->setStyleSheet(titleStyle.arg("#ccc"));
    ui->tipLab->setStyleSheet("color:#666;background:#252526");
}

