#include "cardcell.h"
#include "carditem.h"


CardItem::CardItem(FeintSetting::STYLE style)
{
    this->m_style=style;
}

void CardItem::updateItem(QVariant item)
{
       CardCell *cell=new CardCell;
       cell->setColorStyle(m_style);
       cell->setCard(qvariant_cast<InvitationCard>(item));
       setGraphic(cell);
}
