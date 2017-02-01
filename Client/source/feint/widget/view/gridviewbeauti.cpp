#include "gridviewbeauti.h"

#include <QImage>
#include <QPainter>

#include <util/graphic/imageutil.h>
GridViewBeauti::GridViewBeauti()
{

}

void GridViewBeauti::imageWithPane(QPaintDevice *device,const QColor& color)
{
//    if(bgImage.isNull())
//        return;
//    QImage tempImage=bgImage;
    QPainter painter(device);
//    tempImage=ImageUtil::fitToDevice(tempImage,QSize(device->width(),device->height()));

//    painter.drawImage(0,0,tempImage,(tempImage.width()-device->width())/2,
//                      (tempImage.height()-device->height())/2,device->width(),device->height());
//    QLinearGradient linear(device->width()/2,0,device->width()/2,device->height());
//    linear.setColorAt(0,QColor(250,250,250,250));
//    linear.setColorAt(1,QColor(250,250,250,100));
    painter.setBrush(QBrush(color));
    painter.setPen(Qt::transparent);

    painter.drawRect(0,0,
                     device->width(),device->height());
}

