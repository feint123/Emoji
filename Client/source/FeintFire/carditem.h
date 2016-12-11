#ifndef CARDITEM_H
#define CARDITEM_H

#include <widget/view/listitem.h>



class CardItem:public ListItem
{
public:
    CardItem();
    void updateItem(QVariant item);
};

#endif // CARDITEM_H
