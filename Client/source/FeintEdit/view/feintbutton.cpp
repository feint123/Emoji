#include "feintbutton.h"

#include <qpainter.h>

FeintButton::FeintButton(QWidget *parent)
{

}

void FeintButton::paintEvent(QPaintEvent *event)
{
    QPushButton::paintEvent(event);
    QImage temp;
    QPainter painter(this);
    QMatrix matrix;
    matrix.scale(this->width()/(float)state.width(),
                 this->height()/(float)state.height());
    temp=state.transformed(matrix);
    painter.drawImage(this->width()/2-temp.width()/2,
                      this->height()/2-temp.height()/2,temp);
}

void FeintButton::mousePressEvent(QMouseEvent *event)
{
    if(click().isNull())
        return;
    state=click();
    update();
}

void FeintButton::mouseReleaseEvent(QMouseEvent *event)
{

    state=normal();
    update();
}

void FeintButton::enterEvent(QEvent *event)
{
    if(hover().isNull())
        return;
    state=hover();
    update();
}

void FeintButton::leaveEvent(QEvent *event)
{
    state=normal();
    update();
}
