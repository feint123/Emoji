#ifndef COLORLABEL_H
#define COLORLABEL_H

#include <QLabel>

#include <QColor>
#include <QMouseEvent>


class ColorLabel:public QLabel
{
Q_OBJECT
public:

    //explicit ColorLabel(QWidget* parent=0);
    ColorLabel(QWidget* parent=0,QColor defColor=Qt::white);
    QColor getCurrentColor() const;
    void setCurrentColor(const QColor &value);
signals:
    void colorChange(QColor);
private:
    QColor currentColor;
    void mousePressEvent(QMouseEvent *);
    void setColor(QColor);
};

#endif // COLORLABEL_H
