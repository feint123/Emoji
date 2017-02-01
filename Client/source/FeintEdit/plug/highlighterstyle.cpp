#include "highlighterstyle.h"

#include <util/highlighterhelper.h>

HighlighterStyle::HighlighterStyle()
{

}

void HighlighterStyle::style(MarkDownHighlighter *lighter)
{
    Highlighter *high=HighlighterHelper::loadHighlighter();
    QHash<MarkDownHighlighter::Type,QColor> typeColor;
    typeColor[MarkDownHighlighter::BOLD]=QColor(high->bold());
    typeColor[MarkDownHighlighter::ORDERLIST]=QColor(high->orderList());
    typeColor[MarkDownHighlighter::HEADER]=QColor(high->header());
    typeColor[MarkDownHighlighter::UNORDERLIST]=QColor(high->unOrderList());
    typeColor[MarkDownHighlighter::DEVIDE]=QColor(high->devide());
    typeColor[MarkDownHighlighter::CODEBLOCK]=QColor(high->code());
    typeColor[MarkDownHighlighter::CODE]=QColor(high->code());
    typeColor[MarkDownHighlighter::QUOTEBLOCK]=QColor(high->block());
    typeColor[MarkDownHighlighter::ITALIC]=QColor(high->italic());
    typeColor[MarkDownHighlighter::IMG]=QColor(high->img());
    typeColor[MarkDownHighlighter::DELETE]=QColor(high->del());
    lighter->setTypeColor(typeColor);
    lighter->createTypeFormat();
}
