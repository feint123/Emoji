#ifndef LASTEDITITEM_H
#define LASTEDITITEM_H

#include <widget/view/listitem.h>



class LastEditItem:public ListItem
{
public:
    LastEditItem();

    // ListItem interface
public:
    void updateItem(QVariant item);
};

#endif // LASTEDITITEM_H
