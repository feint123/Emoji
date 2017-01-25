#include "listviewbeauti.h"

#include <QPainter>

ListViewBeauti::ListViewBeauti()
{

}

void ListViewBeauti::colorBackground(QPaintDevice *device, const QImage &image, const QColor &color)
{
    QPainter painter(device);
    painter.setBrush(color);
    painter.setPen(Qt::transparent);
    painter.drawRect(0,0,device->width(),device->height());
}
