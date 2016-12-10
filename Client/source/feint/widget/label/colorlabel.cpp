#include "colorlabel.h"

#include <QColorDialog>
#include <QDebug>
//ColorLabel::ColorLabel(QWidget *parent)
//    :QLabel(parent)
//{

//}

ColorLabel::ColorLabel(QWidget *parent,QColor defColor)
    :QLabel(parent)
{
    currentColor=defColor;
    setColor(currentColor);
}

void ColorLabel::mousePressEvent(QMouseEvent *)
{
    QColor color=QColorDialog::getColor(currentColor,this,"选择颜色");
    setColor(color);
    emit colorChange(color);
}

void ColorLabel::setColor(QColor color)
{
    this->setStyleSheet(tr("background:rgb(%1,%2,%3)").arg(color.red()).arg(color.green()).arg(color.blue()));
}

QColor ColorLabel::getCurrentColor() const
{
    return currentColor;
}

void ColorLabel::setCurrentColor(const QColor &value)
{
    currentColor = value;
    setColor(currentColor);
}
