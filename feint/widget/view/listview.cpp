#include "listview.h"



ListView::ListView()
{
    this->box=new QBoxLayout(QBoxLayout::TopToBottom);
    this->setLayout(box);
}


void ListView::setOrientation(ListView::Orien orien)
{
    if(orien==ListView::Horizontal)
        this->box=new QBoxLayout(QBoxLayout::LeftToRight);

    else
        this->box=new QBoxLayout(QBoxLayout::TopToBottom);
    this->setLayout(box);
}


void ListView::setData(QList<QVariant> data)
{
    this->data=data;
}



void ListView::setItem(ListItem* item)
{
    foreach (QVariant dataitem, this->data) {
        item->updateItem(dataitem);
        this->box->addWidget(item->getGraphic());
    }
}
