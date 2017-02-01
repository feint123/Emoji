#ifndef MARKFACTORY_H
#define MARKFACTORY_H

#include <view/pulldownlist/fwidget.h>



class MarkFactory
{
public:
    MarkFactory();
    static FWidget* create(const QVariant &data);
};

#endif // MARKFACTORY_H
