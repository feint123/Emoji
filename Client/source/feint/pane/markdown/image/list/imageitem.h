#ifndef IMAGEITEM_H
#define IMAGEITEM_H

#include <widget/view/listitem.h>



class ImageItem:public ListItem
{
public:
    ImageItem();

    // ListItem interface
public:
    void updateItem(QVariant item);
};

#endif // IMAGEITEM_H
