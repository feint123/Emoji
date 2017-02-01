#include "markfactory.h"
#include "markitem.h"

MarkFactory::MarkFactory()
{

}

FWidget* MarkFactory::create(const QVariant &data)
{
    MarkItem *item=new MarkItem();
    item->setStyleSheet("QLabel{background:#f9f9f9;color:#666;padding-left:8px;}"
                        "QLabel:hover{background:#2470ff;color:#f9f9f9}");
    item->setData(data);
    return item;
}
