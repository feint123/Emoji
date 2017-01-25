#include "transframe.h"

#include <QPainter>

TransFrame::TransFrame(QWidget *parent):
    QFrame(parent)
{
    setAutoFillBackground(false);
    setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground, true);
}

void TransFrame::paintEvent(QPaintEvent *evnet)
{
    QPainter p(this);
    QBrush brush;
    brush.setColor(QColor(0, 0, 0,160));
    brush.setStyle(Qt::SolidPattern);
    p.setPen(QColor(255,255,255,0));
    p.setBrush(brush);
    p.drawRect(0,0,this->width(),this->height());
}
