#ifndef NOTEITEM_H
#define NOTEITEM_H

#include <widget/view/listitem.h>



class NoteItem:public ListItem
{
public:
    NoteItem();

    // ListItem interface
public:
    void updateItem(QVariant item);
};

#endif // NOTEITEM_H
