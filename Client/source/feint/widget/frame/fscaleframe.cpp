#include "fscaleframe.h"

#include <QPropertyAnimation>
#include <QDebug>
#include <QGraphicsDropShadowEffect>

FScaleFrame::FScaleFrame(QWidget *parent):
    QFrame(parent)
{
    this->scale=1.05;
}

void FScaleFrame::enterEvent(QEvent *)
{
//    if(isFirstIn)
//    {
//        frameRect=this->geometry();
//        qDebug()<<"FScaleFrame[enterEvent]:"<<frameRect;
//    }
//    QPropertyAnimation *anim=new QPropertyAnimation(this,"geometry");
//    anim->setDuration(300);
//    anim->setStartValue(geometry());
//    int width=frameRect.width()*scale;
//    int height=frameRect.height()*scale;
//    int x=frameRect.x()-frameRect.width()*((scale-1)/2.0);
//    int y=frameRect.y()-frameRect.height()*((scale-1)/2.0);
//    anim->setEndValue(QRect(x,y,width,height));
//    anim->start();
    QPropertyAnimation *anim=new QPropertyAnimation(this,"shadow");
    anim->setDuration(400);
    anim->setStartValue(0);
    anim->setEndValue(15);
    anim->start();
}

void FScaleFrame::leaveEvent(QEvent *)
{
//    QPropertyAnimation *anim=new QPropertyAnimation(this,"geometry");
//    anim->setDuration(400);
//    anim->setStartValue(this->geometry());
//    anim->setEndValue(frameRect);
//    anim->start();
    QPropertyAnimation *anim=new QPropertyAnimation(this,"shadow");
    anim->setDuration(400);
    anim->setStartValue(15);
    anim->setEndValue(0);
    anim->start();
}

double FScaleFrame::getScale() const
{
    return scale;
}

void FScaleFrame::setScale(double value)
{
    scale = value;
}

int FScaleFrame::shadow() const
{
    return m_shadow;
}

void FScaleFrame::setShadow(int shadow)
{
    m_shadow = shadow;
    QGraphicsDropShadowEffect *dropshadow=new QGraphicsDropShadowEffect(this);
    dropshadow->setColor("#aaa");
    dropshadow->setXOffset(0);
    dropshadow->setYOffset(0);
    dropshadow->setBlurRadius(this->shadow());
    this->setGraphicsEffect(dropshadow);
}
