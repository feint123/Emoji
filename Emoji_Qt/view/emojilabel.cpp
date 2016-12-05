#include "emojilabel.h"

#include <QPainter>
#include <QDebug>
EmojiLabel::EmojiLabel()
{
    moveable=false;
}

EmojiLabel::~EmojiLabel()
{
    foreach (EmojiText *text, textList) {
        text=NULL;
    }
}


void EmojiLabel::paintEvent(QPaintEvent *event)
{
    switch(paintState){
    case PaintState::LOADIMAGE:
        paintImage();
        this->textList.clear();
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

    }else{
        if(!hasHistoryText(event)){
            currentText=new EmojiText();
            textList.append(currentText);
            updateText();
            if(textList.size()==1)
                emit editEmoji();
            else copyLastEmojiText();

        }else
            emit currentEmojiTextChanged(currentText);
    }
 //   this->clearNullEmoji();
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
    foreach(EmojiText* currentText,textList){
        painter.setPen(Qt::black);
        painter.setFont(getcurrentFont(currentText));
        QRect rect=QRect(currentText->getX(),currentText->getY(),
                         currentText->getWidth(),currentText->getHeight());
        painter.drawText(rect,currentText->getEmojiCont());
    }
    focusText();
}

void EmojiLabel::focusText()
{
    QPainter painter(this);
    painter.setPen(QColor("#70d1f9"));
    painter.drawRect(currentText->getX()-2,currentText->getY()-2,currentText->getWidth()+4,currentText->getHeight()+4);
}

bool EmojiLabel::hasHistoryText(QMouseEvent *event)
{
    foreach(EmojiText *text,textList)
    {
        if((text->getX()<event->x())&&((text->getX()+text->getWidth())>event->x())
                &&(text->getY()<event->y())&&((text->getY()+text->getHeight())>event->y()))
        {
            currentText=text;
            return true;
        }
    }
    return false;
}

void EmojiLabel::updateText()
{

    currentText->setWidth(QFontMetrics(getcurrentFont(currentText)).width(currentText->getEmojiCont()));
    currentText->setHeight(QFontMetrics(getcurrentFont(currentText)).height());
    if((currentText->getY()+currentText->getHeight())>this->height())
        currentText->setY(this->height()-currentText->getHeight());
    if((currentText->getX()+currentText->getWidth())>this->width())
        currentText->setX(this->width()-currentText->getWidth());
}

void EmojiLabel::placeVerText(int placeId)
{
    switch (placeId) {
    //vertical center
    case 2:
        currentText->setY(this->height()/2-QFontMetrics(getcurrentFont(currentText)).height()/2);
        break;
    case 1:
        currentText->setY(0);
        break;
    case 3:
        currentText->setY(this->height()-QFontMetrics(getcurrentFont(currentText)).height());
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
        currentText->setX(this->width()/2-QFontMetrics(getcurrentFont(currentText)).width(currentText->getEmojiCont())/2);
        break;
    case 1:
        currentText->setX(0);
        break;
    case 3:
        currentText->setX(this->width()-QFontMetrics(getcurrentFont(currentText)).width(currentText->getEmojiCont()));
        break;
    default:
        break;
    }
    update();
}

void EmojiLabel::clearNullEmoji()
{
    int i=0;
    foreach(EmojiText* text,textList)
    {
        if(text->getEmojiCont().length()==0){
            textList.removeAt(i);
            text=NULL;
        }
        i++;
    }
}

void EmojiLabel::copyLastEmojiText()
{
    EmojiText* lastText=textList.at(textList.size()-2);
    currentText->setEmojiFont(lastText->getEmojiFont());
    currentText->setFontSize(lastText->getFontSize());
}

QFont EmojiLabel::getcurrentFont(EmojiText* currentText)
{
    QFont font=currentText->getEmojiFont();
    font.setPointSize(currentText->getFontSize());
    return font;
}



void EmojiLabel::setMoveable(bool value)
{
    moveable = value;
}

void EmojiLabel::setFontSize(int size)
{
    currentText->setFontSize(size);
    updateText();
    this->update();
}

void EmojiLabel::setFont(const QFont &font)
{
    currentText->setEmojiFont(font);
    updateText();
    this->update();
}

void EmojiLabel::setEmojiText(QString text)
{
    currentText->setEmojiCont(text);
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


