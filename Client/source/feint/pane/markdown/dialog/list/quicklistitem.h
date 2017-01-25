#ifndef QUICKLISTITEM_H
#define QUICKLISTITEM_H

#include <widget/view/listitem.h>



class QuickListItem:public ListItem
{
public:
    QuickListItem();

    // ListItem interface
public:
    void updateItem(QVariant item);
};

#endif // QUICKLISTITEM_H
