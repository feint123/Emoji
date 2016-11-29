#ifndef EMOJITEXT_H
#define EMOJITEXT_H

#include <QColor>
#include <QFont>



class EmojiText
{
public:
    EmojiText();
    QColor getEmojiColor() const;
    void setEmojiColor(const QColor &value);

    int getHeight() const;
    void setHeight(int value);

    int getWidth() const;
    void setWidth(int value);

    int getY() const;
    void setY(int value);

    int getX() const;
    void setX(int value);

    QFont getEmojiFont() const;
    void setEmojiFont(const QFont &value);

    QString getEmojiCont() const;
    void setEmojiCont(const QString &value);

private:
    QString emojiCont;
    QFont emojiFont;
    int x;
    int y;
    int width;
    int height;
    QColor emojiColor;

};

#endif // EMOJITEXT_H
