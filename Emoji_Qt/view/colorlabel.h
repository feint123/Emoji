#ifndef COLORLABEL_H
#define COLORLABEL_H

#include <QLabel>
#include <QMouseEvent>



class ColorLabel:public QLabel
{
public:
    ColorLabel();
    ColorLabel(QWidget *parent);
private:
    void mousePressEvent(QMouseEvent *);
    void updateColor();
    int width;
    int height;
    QColor bgColor;
    QString createStyle();
};

#endif // COLORLABEL_H
