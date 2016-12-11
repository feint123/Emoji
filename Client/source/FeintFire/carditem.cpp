#include "cardcell.h"
#include "carditem.h"

CardItem::CardItem()
{

}

void CardItem::updateItem(QVariant item)
{
       CardCell *cell=new CardCell;
       cell->setCard(qvariant_cast<ArticalCard>(item));
       setGraphic(cell);
}
