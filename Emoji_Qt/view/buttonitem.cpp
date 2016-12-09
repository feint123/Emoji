#include "buttonitem.h"
#include "cardwidget.h"

#include <QPushButton>

#include <domain/card.h>

ButtonItem::ButtonItem()
{

}

void ButtonItem::updateItem(QVariant item)
{

    CardWidget *cardWidget=new CardWidget();

    Card card = qvariant_cast<Card>(item);
    cardWidget->createCard(card.getTname(),card.getTip(),card.getDate(),card.getHot());
    setGraphic(cardWidget);
}
