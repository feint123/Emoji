#ifndef EFFECTUTIL_H
#define EFFECTUTIL_H

#include <QWidget>



class EffectUtil
{
public:
    EffectUtil();
    static void addDropShadow(int radius,QWidget* widget);

    static void addDropShadow(int radius, QString color,QWidget *widget);
    static void addOpacity(qreal opacity,QWidget* widget);
};

#endif // EFFECTUTIL_H
