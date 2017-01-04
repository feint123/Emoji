#include "fcircle.h"

#include <QPainter>
#include <QDebug>
FCircle::FCircle(QWidget *parent) :
    QLabel(parent)
{
    setColor(QString("#ccc"));
}

void FCircle::paintEvent(QPaintEvent *event)
{
    this->resize(radius()*2+4,radius()*2+4);
    QPainter painter(this);
    QBrush brush;
    brush.setColor(QColor(color()));
    brush.setStyle(Qt::SolidPattern);
    QPen pen;
    pen.setBrush(brush);
    painter.setPen(pen);
    painter.setBrush(brush);
    painter.setRenderHint(QPainter::Antialiasing);
  //  qDebug()<<"FCircle[paintEvent]:"<<"radius:"<<radius();
    painter.drawEllipse(QPoint(this->width()/2,this->height()/2),radius(),radius());
}

QString FCircle::color() const
{
    return m_color;
}

QString FCircle::flag() const
{
    return m_flag;
}

int FCircle::radius() const
{
    return m_radius;
}

void FCircle::setColor(QString color)
{
    if (m_color == color)
        return;

    m_color = color;
    update();
    emit colorChanged(color);
}

void FCircle::setFlag(QString flag)
{
    if (m_flag == flag)
        return;

    m_flag = flag;
    this->setToolTip(flag);
    emit flagChanged(flag);
}

void FCircle::setRadius(int radius)
{
    if (m_radius == radius)
        return;

    m_radius = radius;
    update();
    emit radiusChanged(radius);
}
