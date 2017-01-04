#include "ftooglebutton.h"

#include <QPainter>
#include <QDebug>

FToogleButton::FToogleButton(QWidget *parent) :
    QPushButton(parent)
{
    connect(this,SIGNAL(toggled(bool)),this,SLOT(setFChecked(bool)));
}

QString FToogleButton::toggleColor() const
{
    return m_toggleColor;
}

QRect FToogleButton::toggleRect() const
{
    return m_toggleRect;
}

int FToogleButton::arcRadius() const
{
    return m_arcRadius;
}

QString FToogleButton::toggleBgColor() const
{
    return m_toggleBgColor;
}

QString FToogleButton::onBgColor() const
{
    return m_onBgColor;
}

QString FToogleButton::offBgColor() const
{
    return m_offBgColor;
}

void FToogleButton::setFChecked(bool checked)
{
    if(checked){
        setToggleRect(QRect(2*arcRadius()+detaX,detaY,2*arcRadius(),2*arcRadius()));
        setToggleBgColor(onBgColor());
    }else
    {
        setToggleRect(QRect(detaX,detaY,arcRadius()*2,arcRadius()*2));
        setToggleBgColor(offBgColor());
    }
}

void FToogleButton::setToggleColor(QString toggleColor)
{
    if (m_toggleColor == toggleColor)
        return;

    m_toggleColor = toggleColor;
    update();
    emit toggleColorChanged(toggleColor);
}

void FToogleButton::setToggleRect(QRect toggleRect)
{
    m_toggleRect = toggleRect;
    update();
    emit toggleRectChanged(toggleRect);
}

void FToogleButton::setArcRadius(int arcRadius)
{
    m_arcRadius = arcRadius;
    qDebug()<<"FToggleButton[setArcRadius]:"<<this->geometry();
    detaX=1;
    detaY=1;
    this->resize(4*arcRadius+2,2*arcRadius+2);
}

void FToogleButton::setToggleBgColor(QString toggleBgColor)
{
    if (m_toggleBgColor == toggleBgColor)
        return;

    m_toggleBgColor = toggleBgColor;
    update();
    emit toggleBgColorChanged(toggleBgColor);
}

void FToogleButton::setOnBgColor(QString onBgColor)
{
    if (m_onBgColor == onBgColor)
        return;

    m_onBgColor = onBgColor;
    emit onBgColorChanged(onBgColor);
}

void FToogleButton::setOffBgColor(QString offBgColor)
{
    if (m_offBgColor == offBgColor)
        return;

    m_offBgColor = offBgColor;
    emit offBgColorChanged(offBgColor);
}


void FToogleButton::paintEvent(QPaintEvent *event)
{

    QPainter painter(this);
    QPainterPath path;
    QPoint start(arcRadius()+detaX,detaY);
    QPoint end(2*arcRadius()+detaX,2*arcRadius()+detaY);
    QRect rect(detaX,detaY,arcRadius()*2,arcRadius()*2);
    //用来定位右半边的半圆弧
    QRect rect_(2*arcRadius()+detaX,detaY,2*arcRadius(),2*arcRadius());
    path.moveTo(start);
    path.arcTo(rect,90,180);
    path.lineTo(end);
    path.arcTo(rect_,270,180);
    path.lineTo(start);
    QPen pen;
    pen.setWidth(0.5);
    pen.setColor(QColor("#666"));
    QBrush brush;
    brush.setColor(QColor(toggleBgColor()));
    brush.setStyle(Qt::SolidPattern);

    painter.setRenderHints(QPainter::HighQualityAntialiasing|QPainter::Antialiasing, true);
    painter.setPen(pen);
    painter.setBrush(brush);
    painter.drawPath(path);
    brush.setColor(QColor(toggleColor()));
    painter.setBrush(brush);
    painter.drawEllipse(toggleRect());

}

