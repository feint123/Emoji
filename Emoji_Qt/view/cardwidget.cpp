#include "cardwidget.h"
#include "ui_cardwidget.h"

#include <QGraphicsDropShadowEffect>

CardWidget::CardWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CardWidget)
{
    ui->setupUi(this);
    QGraphicsDropShadowEffect *sf=new QGraphicsDropShadowEffect(this);
    sf->setXOffset(5);
    sf->setYOffset(5);
    sf->setColor(Qt::gray);
    sf->setBlurRadius(10);
    this->setGraphicsEffect(sf);
}

void CardWidget::createCard(QString title, QString tip, QDate date, float hot)
{
    ui->titleLab->setText(title);
    ui->tipLab->setText(tip);
    ui->dateLab->setText(date.toString("yyyy-MM-dd"));
    ui->hotLab->setText(QString::number(hot));
}

CardWidget::~CardWidget()
{
    delete ui;
}
