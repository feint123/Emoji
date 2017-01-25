#ifndef NOTEBOOKITEM_H
#define NOTEBOOKITEM_H

#include <widget/view/listitem.h>



class NotebookItem:public ListItem
{
public:
    NotebookItem();

    // ListItem interface
public:
    void updateItem(QVariant item);
};

#endif // NOTEBOOKITEM_H
