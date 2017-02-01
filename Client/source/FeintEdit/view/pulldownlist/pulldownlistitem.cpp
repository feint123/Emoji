#include "pulldownlistitem.h"



PullDownListItem::PullDownListItem(WidgetFactory widget)
{
    this->widget=widget;
}

void PullDownListItem::updateItem(QVariant item)
{
    FWidget *w=(*widget)(item);
    setGraphic(w);
}
