#ifndef NOTEBOOKNAMEITEM_H
#define NOTEBOOKNAMEITEM_H

#include <widget/view/listitem.h>



class NotebookNameItem:public ListItem
{
public:
    NotebookNameItem();


    // ListItem interface
public:
    void updateItem(QVariant item);
};

#endif // NOTEBOOKNAMEITEM_H
