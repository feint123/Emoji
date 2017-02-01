#include "abstructview.h"

AbstructView::AbstructView(QWidget *parent)
{

}

void AbstructView::setDatas(QList<QVariant> datas)
{
    this->datas=datas;
}

void AbstructView::addDatas(QList<QVariant> datas)
{
    this->datas.clear();
    this->datas=datas;
    for(QWidget *widget:itemList)
        widget->deleteLater();
    itemList.clear();
    setItem(this->item);
    setScroll(0);
    setFocusIndex(0);
    layout();
}

void AbstructView::addData(QVariant data)
{

}

bool AbstructView::deleteData(QVariant data)
{

}

void AbstructView::setItem(ListItem *item)
{
    this->item=item;

    foreach (QVariant dataitem, this->datas) {
        item->updateItem(dataitem);
        item->getGraphic()->installEventFilter(this);
        item->getGraphic()->setMouseTracking(true);
        this->itemList.append(item->getGraphic());
        item->getGraphic()->setParent(this);
        item->getGraphic()->show();
    }
}

void AbstructView::layout()
{

}

int AbstructView::maxSize()
{

}

void AbstructView::createScroll()
{

}
