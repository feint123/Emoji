#include "cardshow.h"
#include "ui_cardshow.h"
#include <QDebug>
CardShow::CardShow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CardShow)
{
    ui->setupUi(this);
}

CardShow::CardShow(Card card)
    :ui(new Ui::CardShow)
{
    ui->setupUi(this);
   // ui->label->setText("Hello");
    ui->label->setText(card.getTip());
}

CardShow::~CardShow()
{
    delete ui;
}
