#ifndef PULLDOWNLISTITEM_H
#define PULLDOWNLISTITEM_H

#include "fwidget.h"

#include <widget/view/listitem.h>

typedef FWidget* (*WidgetFactory)(const QVariant &data);

class PullDownListItem:public ListItem
{
public:
    PullDownListItem(WidgetFactory widget);

    // ListItem interface
public:
    void updateItem(QVariant item);

private:

    WidgetFactory widget;
};

#endif // PULLDOWNLISTITEM_H
