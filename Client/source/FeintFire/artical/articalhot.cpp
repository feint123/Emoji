#include "articalhot.h"

#include <QPainter>
#include <math.h>
#include <QDebug>
ArticalHot::ArticalHot(QWidget *parent):
    QLabel(parent)
{
    colorList<<"#ffecec"<<"#ffd2d2"<<"#ffb5b5"<<"#ff9797"<<"#ff5151"<<
               "#ff2d2d"<<"#ff0000"<<"#ea0000"<<"#ce0000"<<"#ae0000";
    update();
}

double ArticalHot::hot() const
{
    return m_hot;
}

void ArticalHot::setHot(double hot)
{
    if (m_hot == hot)
        return;

    m_hot = hot;
    update();
    emit hotChanged(hot);
}

void ArticalHot::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    int deta=3;
    int incr=3;
    int x=10;
    int h=ceil(this->m_hot*10);
    for(int i=0;i<10;i++){
        if(h>0)
            painter.fillRect(QRect(i*x+i*deta+incr*(i-1)*i/2,0,x+incr*i,x),
                             QBrush(QColor(colorList.at(i))));
        painter.drawRect(i*x+i*deta+incr*(i-1)*i/2,0,x+incr*i,x);
        h--;
    }

}
