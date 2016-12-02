#include "emojilabel.h"

#include <QPainter>
#include <QDebug>
EmojiLabel::EmojiLabel()
{
    moveable=false;
    point.setX(0);
    point.setY(0);
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
    if(moveable){
        point.setX(event->x());
        point.setY(event->y());
    }else{
        emit editEmoji();
        updateText();
    }

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
    QRect rect=QRect(point.x(),point.y(),textRectWidth,textRectHeight);
    painter.drawText(rect,text);
}

void EmojiLabel::updateText()
{
//    point.setX(this->width()/2-QFontMetrics(font).width(text)/2);
//    point.setY(this->height()/2-QFontMetrics(font).height()/2);
    textRectWidth=QFontMetrics(font).width(text);
    textRectHeight=QFontMetrics(font).height();
}

void EmojiLabel::placeVerText(int placeId)
{
    switch (placeId) {
    //vertical center
    case 2:
        point.setY(this->height()/2-QFontMetrics(font).height()/2);
        break;
    case 1:
        point.setY(0);
        break;
    case 3:
        point.setY(this->height()-QFontMetrics(font).height());
        break;
    default:
        break;
    }
    update();
}

void EmojiLabel::placeHorText(int placeId)
{
    switch (placeId) {
    //vertical center
    case 2:
        point.setX(this->width()/2-QFontMetrics(font).width(text)/2);
        break;
    case 1:
        point.setX(0);
        break;
    case 3:
        point.setX(this->width()-QFontMetrics(font).width(text));
        break;
    default:
        break;
    }
    update();
}



void EmojiLabel::setMoveable(bool value)
{
    moveable = value;
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
    updateText();
    this->update();
}

void EmojiLabel::setFont(const QFont &font)
{
    this->font=font;
    updateText();
    this->update();
}

void EmojiLabel::setEmojiText(QString text)
{
    this->text=text;
     updateText();
     update();
}

void EmojiLabel::placeText(int placeId, bool ver)
{
    if(ver)
        placeVerText(placeId);
    else
        placeHorText(placeId);
}

EmojiLabel::PaintState EmojiLabel::getPaintState() const
{
    return paintState;
}

void EmojiLabel::setPaintState(const PaintState &value)
{
    paintState = value;
}


