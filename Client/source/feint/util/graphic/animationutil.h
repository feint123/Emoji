#ifndef ANIMATIONUTIL_H
#define ANIMATIONUTIL_H

#include <QWidget>



class AnimationUtil
{
public:
    AnimationUtil();
    static void GeometryAnim(QRect start,QRect end,QWidget *widget);
};

#endif // ANIMATIONUTIL_H
