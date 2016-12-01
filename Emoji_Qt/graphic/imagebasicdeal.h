#ifndef IMAGEBASICDEAL_H
#define IMAGEBASICDEAL_H

#include <QImage>
#include <QLabel>
#include <QSize>



class ImageBasicDeal
{
public:
    ImageBasicDeal();
    static void cutImage(QImage *image,QPoint startPoint,QSize size);
    static void scaleImage(QLabel *label,double scale,double *currentScale);

};

#endif // IMAGEBASICDEAL_H
