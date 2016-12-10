#include "emojitext.h"

EmojiText::EmojiText()
{
    this->emojiCont="";
    this->width=0;
    this->height=0;
    this->fontSize=16;
}

QColor EmojiText::getEmojiColor() const
{
    return emojiColor;
}

void EmojiText::setEmojiColor(const QColor &value)
{
    emojiColor = value;
}

int EmojiText::getHeight() const
{
    return height;
}

void EmojiText::setHeight(int value)
{
    height = value;
}

int EmojiText::getWidth() const
{
    return width;
}

void EmojiText::setWidth(int value)
{
    width = value;
}

int EmojiText::getY() const
{
    return y;
}

void EmojiText::setY(int value)
{
    y = value;
}

int EmojiText::getX() const
{
    return x;
}

void EmojiText::setX(int value)
{
    x = value;
}

QFont EmojiText::getEmojiFont() const
{
    return emojiFont;
}

void EmojiText::setEmojiFont(const QFont &value)
{
    emojiFont = value;
}

QString EmojiText::getEmojiCont() const
{
    return emojiCont;
}

void EmojiText::setEmojiCont(const QString &value)
{
    emojiCont = value;
}

int EmojiText::getFontSize() const
{
    return fontSize;
}

void EmojiText::setFontSize(int value)
{
    fontSize = value;
}
