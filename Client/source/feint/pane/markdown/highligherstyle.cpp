#include "highligherstyle.h"

HighligherStyle::HighligherStyle()
{

}

void HighligherStyle::dark(MarkDownHighlighter *lighter)
{
    QHash<MarkDownHighlighter::Type,QColor> typeColor;
    typeColor[MarkDownHighlighter::BOLD]=QColor("#c87c36");
    typeColor[MarkDownHighlighter::ORDERLIST]=QColor("#39ae53");
    typeColor[MarkDownHighlighter::HEADER]=QColor("#eade96");
    typeColor[MarkDownHighlighter::UNORDERLIST]=QColor("#2d631f");
    typeColor[MarkDownHighlighter::DEVIDE]=QColor("#e82121");
    typeColor[MarkDownHighlighter::CODEBLOCK]=QColor("#368afc");
    typeColor[MarkDownHighlighter::CODE]=QColor("#3176ff");
    typeColor[MarkDownHighlighter::QUOTEBLOCK]=QColor("#adf05d");
    typeColor[MarkDownHighlighter::ITALIC]=QColor("#f59d49");
    typeColor[MarkDownHighlighter::IMG]=QColor("#2064db");
    typeColor[MarkDownHighlighter::DELETE]=QColor("#de5145");
    lighter->setTypeColor(typeColor);
    lighter->createTypeFormat();
}
