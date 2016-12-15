#include "listview.h"
#include "ui_listview.h"
#include <QDebug>
#include <QPushButton>

ListView::ListView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ListView)
{
    ui->setupUi(this);
    box=new QBoxLayout(QBoxLayout::TopToBottom);
    ui->scrollArea->widget()->setLayout(box);
}

ListView::~ListView()
{
    delete ui;
}




void ListView::setOrientation(ListView::Orien orien)
{
    if(orien==ListView::Horizontal)
        this->box->setDirection(QBoxLayout::LeftToRight);

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
        qDebug()<<item->getGraphic();
        box->addWidget(item->getGraphic());
        this->itemList.append(item->getGraphic());
    }

    box->addStretch();
}


void ListView::setBackgroundColor(QColor color)
{

}

int ListView::firstVisibleItemIndex()
{
    return 0;
}

void ListView::setItemSpacing(int space)
{
    //this->box->setSpacing(space);
    ui->scrollArea->widget()->layout()->setSpacing(space);
}

void ListView::mousePressEvent(QMouseEvent *event)
{

       foreach(QWidget *widget,itemList)
       {

           int x=widget->x()+ui->scrollArea->widget()->x();
           int y=widget->y()+ui->scrollArea->widget()->y();
           if((x<event->x())&&((x+widget->width())>event->x())
                       &&(y<event->y())&&((y+widget->height())>event->y()))
           {
               qDebug()<<"ListView[mousePressEevent]:"<<itemList.indexOf(widget);

               emit this->selectItem(this->data.at(itemList.indexOf(widget)));

               emit this->selectItemIndex(itemList.indexOf(widget));
           }
       }
}
