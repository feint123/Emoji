#include "markdownedit.h"


MarkDownEdit::MarkDownEdit(QWidget *parent):
    QTextEdit(parent)
{

    lighter=new MarkDownHighlighter(this->document());
    this->setTabStopWidth(QFontMetrics(this->font()).maxWidth()*3);
    this->setFontFamily("Menlo");

}

void MarkDownEdit::setTheme(MarkDownEdit::Theme theme)
{
    if(theme==Theme::DARK)
        initDarkTheme();
}

void MarkDownEdit::initDarkTheme()
{
    this->setStyleSheet("background:#1f212b;color:#e7e9e8;font-size:14pt;");
    QHash<MarkDownHighlighter::Type,QColor> typeColor;
    typeColor[MarkDownHighlighter::BOLD]=QColor("#c87c36");
    typeColor[MarkDownHighlighter::ORDERLIST]=QColor("#2d631f");
    typeColor[MarkDownHighlighter::HEADER]=QColor("#eade96");
    typeColor[MarkDownHighlighter::UNORDERLIST]=QColor("#2d631f");
    typeColor[MarkDownHighlighter::DEVIDE]=QColor("#e82121");
    typeColor[MarkDownHighlighter::CODEBLOCK]=QColor("#368afc");
    typeColor[MarkDownHighlighter::CODE]=QColor("#38ad52");
    typeColor[MarkDownHighlighter::QUOTEBLOCK]=QColor("#adf05d");
    typeColor[MarkDownHighlighter::ITALIC]=QColor("#f59d49");
    lighter->setTypeColor(typeColor);
    lighter->createTypeFormat();
}


