#include "buttonitem.h"

#include <QPushButton>

ButtonItem::ButtonItem()
{

}

void ButtonItem::updateItem(QVariant item)
{
    QPushButton *btn=new QPushButton();
    btn->setText(item.toString());
    setGraphic(btn);
}
