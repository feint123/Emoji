#include "animationutil.h"

#include <QPropertyAnimation>
#include <QDebug>
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

QPropertyAnimation *AnimationUtil::GeometryAnim(QList<QRect> values, QWidget *widget, int mesc)
{
    QPropertyAnimation *prop=new QPropertyAnimation(widget,"geometry");
    for(int i=0;i<values.count();i++)
    {
        qreal key;
        if(i==0)
            key=0;
        else
            key=(i+1)/(float)values.count();
        prop->setKeyValueAt(key,values.at(i));
    }
    prop->setDuration(mesc);
    prop->setEasingCurve(QEasingCurve::InBack);
    prop->start(QAbstractAnimation::DeleteWhenStopped);
    return prop;
}

