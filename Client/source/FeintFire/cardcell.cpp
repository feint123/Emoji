#include "cardcell.h"
#include "ui_cardcell.h"

#include <QGraphicsDropShadowEffect>
#include <QDebug>
CardCell::CardCell(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CardCell)
{
    ui->setupUi(this);


    QGraphicsDropShadowEffect *ef=new QGraphicsDropShadowEffect(this);
    ef->setXOffset(0);
    ef->setYOffset(2);
    ef->setBlurRadius(5);
    ef->setColor(QColor("#ccc"));
    this->setGraphicsEffect(ef);
}

CardCell::~CardCell()
{
    delete ui;
}

void CardCell::setCard(ArticalCard card)
{
    ui->titleLab->setText(card.getTname());
    ui->tipLab->setText(card.getTip());
    qDebug()<<card.getDate();
    ui->dateLab->setText(card.getDate().toString("yyyy-MM-dd"));
    ui->surportLab->setText(QString::number(card.getSupport()));
    if(card.getSupported())
        ui->surportBtn->setText("取消赞");
    else
        ui->surportBtn->setText("赞");
    if(card.getCollected())
        ui->collectBtn->setText("取消收藏");
    else
        ui->collectBtn->setText("收藏");
}
