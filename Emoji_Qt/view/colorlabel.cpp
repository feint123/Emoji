#include "colorlabel.h"

#include <QColorDialog>

ColorLabel::ColorLabel()
{

}

ColorLabel::ColorLabel(QWidget *parent)
    :QLabel(parent)
{
    bgColor=Qt::black;
    width=24;
    height=24;
    updateColor();
}

void ColorLabel::mousePressEvent(QMouseEvent *)
{
    bgColor=QColorDialog::getColor(bgColor,this,"选取颜色");
    updateColor();
}

void ColorLabel::updateColor()
{
    this->setStyleSheet(this->createStyle());
}

QString ColorLabel::createStyle()
{
    QString s;
    QString colorStr;
    foreach (QString color, QColor::colorNames()) {
        if(bgColor==QColor(color)){
            colorStr=color;
            break;
        }
    }
    s=tr("min-width:%1px;min-height:%2px;border:1px solid #ccc;background:%3;border-radius:5px;")
            .arg(width).arg(height).arg(colorStr);
    return s;
}
