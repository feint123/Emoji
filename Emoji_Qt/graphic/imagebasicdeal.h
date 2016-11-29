#ifndef IMAGEBASICDEAL_H
#define IMAGEBASICDEAL_H

#include <QImage>
#include <QSize>



class ImageBasicDeal
{
public:
    ImageBasicDeal();
    static void cutImage(QImage *image,QPoint startPoint,QSize size);
    static void scaleImage(QImage *image,double scale,bool isZoomOut);

};

#endif // IMAGEBASICDEAL_H
