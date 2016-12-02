#include "emojilabel.h"

#include <QPainter>
#include <QDebug>
EmojiLabel::EmojiLabel()
{

}


void EmojiLabel::paintEvent(QPaintEvent *event)
{
    switch(paintState){
    case PaintState::LOADIMAGE:
        paintImage();
        break;
    case PaintState::EDITTEXT:
        editText();
        break;
    }
}

void EmojiLabel::mousePressEvent(QMouseEvent *event)
{
    setPaintState(PaintState::EDITTEXT);
    point.setX(event->x());
    point.setY(event->y());
    this->update();
}

void EmojiLabel::paintImage()
{
    QPainter painter(this);
    painter.drawPixmap(0,0,this->pixmap()->width(),this->pixmap()->height(),*(this->pixmap()));

}

void EmojiLabel::editText()
{
    paintImage();
    QPainter painter(this);
    painter.setPen(Qt::black);
    painter.setFont(this->font);
    QRect rect=QRect(point.x(),point.y(),100,100);
    painter.drawText(rect,"text");
}

QString EmojiLabel::getText() const
{
    return text;
}

void EmojiLabel::setText(const QString &value)
{
    text = value;
    this->update();
}

void EmojiLabel::setFontSize(int size)
{
    this->fontSize=size;
    this->font.setPixelSize(fontSize);
    this->update();
}

void EmojiLabel::setFont(const QFont &font)
{
    this->font=font;
    this->update();
}

EmojiLabel::PaintState EmojiLabel::getPaintState() const
{
    return paintState;
}

void EmojiLabel::setPaintState(const PaintState &value)
{
    paintState = value;
}


