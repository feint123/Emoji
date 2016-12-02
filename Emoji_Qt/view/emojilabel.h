#ifndef EMOJILABEL_H
#define EMOJILABEL_H

#include <QLabel>
#include <QPaintEvent>
#include <QMouseEvent>

#include <graphic/emojitext.h>


class EmojiLabel:public QLabel
{
    Q_OBJECT

public:
    enum PaintState{
        LOADIMAGE,
        EDITTEXT
    };

    explicit EmojiLabel();
    PaintState getPaintState() const;
    void setPaintState(const PaintState &value);

    QString getText() const;
    void setText(const QString &value);
    void setMoveable(bool value);

signals:
    void editEmoji();
public slots:
    void setFontSize(int size);
    void setFont(const QFont &);
    void setEmojiText(QString);
    void placeText(int placeId,bool ver);

private:
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent* event);
    void paintImage();
    void editText();
    void focusText();
    void hasText();
    void updateText();
    void placeVerText(int placeId);
    void placeHorText(int placeId);
    QString text;
    QPoint point;
    int textRectWidth;
    int textRectHeight;
    PaintState paintState;
    QList<EmojiText> textList;
    bool moveable;
    int fontSize;
    QFont font;
};

#endif // EMOJILABEL_H
