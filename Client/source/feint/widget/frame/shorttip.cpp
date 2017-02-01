#include "shorttip.h"

#include <QHBoxLayout>
#include <QPainter>
#include <QTimer>

ShortTip *ShortTip::tip=NULL;
ShortTip *ShortTip::getInstance(QWidget *parent)
{

    if(tip==NULL)
        tip=new ShortTip(parent);
    else{
        if(parent!=tip->parent())
            tip->setParent(parent);
    }


    return tip;
}

ShortTip::~ShortTip()
{
    tip=NULL;
}

QString ShortTip::tipStr() const
{
    return m_tipStr;
}

void ShortTip::showTip(int mesc)
{
    this->show();
    timer->setInterval(mesc);
    disconnect(timer,SIGNAL(timeout()),this,SLOT(hide()));
    connect(timer,SIGNAL(timeout()),this,SLOT(hide()));
    timer->start();
}

void ShortTip::setTipStr(QString tipStr)
{
    if (m_tipStr == tipStr)
        return;

    m_tipStr = tipStr;
    emit tipStrChanged(tipStr);
}

ShortTip::ShortTip(QWidget *parent):
    QFrame(parent)
{
    timer=new QTimer();
    setWindowFlags(Qt::FramelessWindowHint);
    tipLab=new QLabel();
    tipLab->setStyleSheet("color:white");
    QHBoxLayout *hb=new QHBoxLayout;
    hb->addWidget(tipLab);
    hb->setAlignment(Qt::AlignCenter);
    this->setLayout(hb);

    connect(this,SIGNAL(tipStrChanged(QString)),tipLab,SLOT(setText(QString)));
}

void ShortTip::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    QBrush brush(QColor(20,20,20,180));
    painter.setBrush(brush);
    painter.setPen(QColor(0,0,0,0));
    painter.drawRoundedRect(0,0,this->width(),this->height(),10,10);
}
