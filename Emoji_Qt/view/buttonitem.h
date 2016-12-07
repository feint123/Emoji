#ifndef BUTTONITEM_H
#define BUTTONITEM_H

#include <widget/view/listitem.h>



class ButtonItem:public ListItem
{
public:
    ButtonItem();
    void updateItem(QVariant item);
};

#endif // BUTTONITEM_H
