#ifndef LISTITEM_H
#define LISTITEM_H

#include <QVariant>
#include <QWidget>


class ListItem
{
public:
    ListItem();
    virtual void updateItem(QVariant item);
    void setGraphic(QWidget *widget);
    QWidget *getGraphic();
private:
    QWidget *widget;
};

#endif // LISTITEM_H
