#include "effectutil.h"

#include <QGraphicsDropShadowEffect>

EffectUtil::EffectUtil()
{

}

void EffectUtil::addDropShadow(int radius, QWidget *widget)
{
    QGraphicsDropShadowEffect *ef=new QGraphicsDropShadowEffect(widget);
    ef->setXOffset(0);
    ef->setYOffset(2);
    ef->setBlurRadius(radius);
    ef->setColor(QColor("#ccc"));
    widget->setGraphicsEffect(ef);
}

void EffectUtil::addOpacity(qreal opacity, QWidget *widget)
{
    QGraphicsOpacityEffect *effect=new QGraphicsOpacityEffect(widget);
    effect->setOpacity(opacity);
    widget->setGraphicsEffect(effect);
}
