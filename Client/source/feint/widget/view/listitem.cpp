#include "listitem.h"

ListItem::ListItem()
{

}
void ListItem::updateItem(QVariant item)
{

}

void ListItem::setGraphic(QWidget *widget)
{
    this->widget=widget;
}

QWidget *ListItem::getGraphic()
{
    return this->widget;
}
