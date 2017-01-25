#ifndef ANIMATIONUTIL_H
#define ANIMATIONUTIL_H

#include <QPropertyAnimation>
#include <QWidget>



class AnimationUtil
{
public:
    AnimationUtil();
    static QPropertyAnimation* GeometryAnim(QRect start,QRect end,QWidget *widget);
    static QPropertyAnimation* GeometryAnim(QRect start, QRect end, QWidget *widget,int mesc);
};

#endif // ANIMATIONUTIL_H
