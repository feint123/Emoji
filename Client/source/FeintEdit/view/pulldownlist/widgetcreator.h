#ifndef WIDGETCREATOR_H
#define WIDGETCREATOR_H

#include "fwidget.h"



class WidgetCreator
{
public:
    WidgetCreator();
    static FWidget* create(const QVariant &data);
};

#endif // WIDGETCREATOR_H
