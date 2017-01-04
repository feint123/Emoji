#ifndef CARDITEM_H
#define CARDITEM_H

#include <widget/view/listitem.h>

#include <util/graphic/feintsetting.h>



class CardItem:public ListItem
{
public:
    CardItem(FeintSetting::STYLE style);
    void updateItem(QVariant item);
private:
    FeintSetting::STYLE m_style;
};

#endif // CARDITEM_H
