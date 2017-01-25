#include "animationutil.h"

#include <QPropertyAnimation>

AnimationUtil::AnimationUtil()
{

}

QPropertyAnimation *AnimationUtil::GeometryAnim(QRect start, QRect end, QWidget *widget)
{
   return GeometryAnim(start,end,widget,350);
}

QPropertyAnimation *AnimationUtil::GeometryAnim(QRect start, QRect end, QWidget *widget, int mesc)
{
    QPropertyAnimation *prop=new QPropertyAnimation(widget,"geometry");
    prop->setStartValue(start);
    prop->setEndValue(end);
    prop->setDuration(mesc);
    prop->setEasingCurve(QEasingCurve::InOutCirc);
    prop->start(QAbstractAnimation::DeleteWhenStopped);
    return prop;
}
