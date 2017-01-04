#include "animationutil.h"

#include <QPropertyAnimation>

AnimationUtil::AnimationUtil()
{

}

void AnimationUtil::GeometryAnim(QRect start, QRect end, QWidget *widget)
{
    QPropertyAnimation *prop=new QPropertyAnimation(widget,"geometry");
    prop->setStartValue(start);
    prop->setEndValue(end);
    prop->setDuration(350);
    prop->setEasingCurve(QEasingCurve::InOutCirc);
    prop->start(QAbstractAnimation::DeleteWhenStopped);
}
