#include "basewidget.h"

#include <qapplication.h>

BaseWidget::BaseWidget(QWidget *parent):
    QMainWindow(parent)
{
    setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);
}

void BaseWidget::setDragRect(const QRect &value)
{
    dragRect = value;
}

void BaseWidget::maxWindow()
{

    showFullScreen();
}

void BaseWidget::minWindow()
{

}

void BaseWidget::closeWindow()
{
    this->hide();
}

bool BaseWidget::isInDragRect(QPoint p)
{
    if(p.x()>dragRect.x()&&p.x()<dragRect.x()+dragRect.width()
            &&p.y()>dragRect.y()&&p.y()<dragRect.y()+dragRect.height())
        return true;
    else return false;
}

void BaseWidget::mousePressEvent(QMouseEvent *event)
{
    canDrag=true;
    dragStart=event->pos();
}

void BaseWidget::mouseReleaseEvent(QMouseEvent *event)
{
    canDrag=false;
}

void BaseWidget::mouseDoubleClickEvent(QMouseEvent *event)
{
    if(isInDragRect(event->pos()))
    {

            hide();

    }

}

void BaseWidget::mouseMoveEvent(QMouseEvent *event)
{
    if(isInDragRect(event->pos())&&canDrag)
    {
        this->move(pos()+event->pos()-dragStart);
    }
}
