#include "markdownhotkey.h"
#include "markitem.h"

#include <util/screenfit.h>

MarkItem::MarkItem(QWidget *parent):
    FWidget(parent)
{
    label=new QLabel(this);
    this->setStyleSheet("QLabel{background:#f9f9f9;color:#666;padding-left:8px;}");
    ScreenFit::fitFont(label);
}

void MarkItem::setData(QVariant data)
{
    MarkdownHotKey hotKey=qvariant_cast<MarkdownHotKey>(data);
    label->setText(hotKey.value());
}

void MarkItem::setText(const QString &text)
{
    label->setText(text);
}

void MarkItem::resizeEvent(QResizeEvent *event)
{
    label->setGeometry(0,0,this->width(),this->height());
}
