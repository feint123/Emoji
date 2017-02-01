#ifndef RECIRCLEITEM_H
#define RECIRCLEITEM_H

#include <widget/view/listitem.h>



class RecircleItem:public ListItem
{
public:
    RecircleItem();

    // ListItem interface
public:
    void updateItem(QVariant item);
};

#endif // RECIRCLEITEM_H
