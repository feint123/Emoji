#include "innerdialogrect.h"

#include <QPainter>

InnerDialogRect::InnerDialogRect(DIR dir)
{
    this->dir=dir;
}

void InnerDialogRect::draw(QWidget *parent, int delay)
{
    QPainter painter(parent);
    QBrush brush;
    QPen pen;
    brush.setColor(QColor(240,240,240,240));
    brush.setStyle(Qt::SolidPattern);
    pen.setColor(QColor(0x00,0x00,0x00,0x00));
    painter.setPen(pen);
    painter.setBrush(brush);
    painter.setRenderHint(QPainter::Antialiasing);
    this->parent=parent;
    this->delay=delay;
    switch (this->dir) {
    case RIGHT:
        drawRight(&painter);
        break;
    case UP:
        drawUp(&painter);
        break;
    case DOWN:
        drawDown(&painter);
    default:
        break;
    }

}

void InnerDialogRect::drawRight(QPainter *painter)
{
    QPainterPath path;
    path.moveTo(0,0);
    path.lineTo(parent->width()-tri,0);
    path.lineTo(parent->width()-tri,parent->height()-delay);
    path.lineTo(parent->width(),parent->height()-delay+tri*3/2);
    path.lineTo(parent->width()-tri,parent->height()-delay+2*tri);
    path.lineTo(parent->width()-tri,parent->height());
    path.lineTo(0,parent->height());
    path.lineTo(0,0);

    painter->drawPath(path);
}

void InnerDialogRect::drawUp(QPainter *painter)
{
    QPainterPath path;
    path.moveTo(0,tri);
    path.lineTo(delay,tri);
    path.lineTo(delay+tri*3/2,0);
    path.lineTo(delay+2*tri,tri);
    path.lineTo(parent->width(),tri);
    path.lineTo(parent->width(),parent->height());
    path.lineTo(0,parent->height());
    path.lineTo(0,tri);

    painter->drawPath(path);
}

void InnerDialogRect::drawDown(QPainter *painter)
{

    QPainterPath path;
    path.moveTo(0,0);
    path.lineTo(0,parent->height()-tri);
    path.lineTo(delay,parent->height()-tri);
    path.lineTo(delay+tri*3/2,parent->height());
    path.lineTo(delay+2*tri,parent->height()-tri);
    path.lineTo(parent->width(),parent->height()-tri);
    path.lineTo(parent->width(),0);
    path.lineTo(0,0);

    painter->drawPath(path);
}

void InnerDialogRect::setTri(int value)
{
    tri = value;
}
