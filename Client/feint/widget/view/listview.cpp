#include "listview.h"

#include <QPushButton>

#include <QDebug>


ListView::ListView()
{
    this->box=new QBoxLayout(QBoxLayout::TopToBottom);

    widget=new QWidget();

    this->setAlignment(Qt::AlignHCenter);

}


void ListView::setOrientation(ListView::Orien orien)
{
    if(orien==ListView::Horizontal)
        this->box=new QBoxLayout(QBoxLayout::LeftToRight);

    else
        this->box=new QBoxLayout(QBoxLayout::TopToBottom);

}


void ListView::setData(QList<QVariant> data)
{
    this->data=data;
}



void ListView::setItem(ListItem* item)
{
    this->item=item;
    foreach (QVariant dataitem, this->data) {
        item->updateItem(dataitem);
        this->box->addWidget(item->getGraphic());
        this->itemList.append(item->getGraphic());
        item->getGraphic()->setParent(this);
    }
    widget->setLayout(box);
    this->setWidget(widget);
}

void ListView::setBackgroundColor(QColor color)
{

}

int ListView::firstVisibleItemIndex()
{

}

void ListView::setItemSpacing(int space)
{
    this->box->setSpacing(space);
}

void ListView::mousePressEvent(QMouseEvent *event)
{

       foreach(QWidget *widget,itemList)
       {
           int x=widget->x()+this->widget->x();
           int y=widget->y()+this->widget->y();
           if((x<event->x())&&((x+widget->width())>event->x())
                       &&(y<event->y())&&((y+widget->height())>event->y()))
           {

               emit this->selectItem(this->data.at(itemList.indexOf(widget)));

               emit this->selectItemIndex(itemList.indexOf(widget));
           }
       }
}
