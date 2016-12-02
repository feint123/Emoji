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
public slots:
    void setFontSize(int size);
    void setFont(const QFont &);
private:
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent* event);
    void paintImage();
    void editText();
    void focusText();
    void hasText();
    QString text;
    QPoint point;
    PaintState paintState;
    QList<EmojiText> textList;

    int fontSize;
    QFont font;
};

#endif // EMOJILABEL_H
