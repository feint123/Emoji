#include "shadowbutton.h"

#include <QGraphicsDropShadowEffect>

ShadowButton::ShadowButton()
{
    QGraphicsDropShadowEffect *sf=new QGraphicsDropShadowEffect(this);
    sf->setXOffset(5);
    sf->setYOffset(5);
    sf->setColor(Qt::gray);
    sf->setBlurRadius(10);
}
