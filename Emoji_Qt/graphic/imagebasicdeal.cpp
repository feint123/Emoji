#include "imagebasicdeal.h"

#include <QLabel>

ImageBasicDeal::ImageBasicDeal()
{

}

void ImageBasicDeal::cutImage(QImage *image, QPoint startPoint, QSize size)
{

}

void ImageBasicDeal::scaleImage(QLabel* label, double scale,double* currentScale)
{
    (*currentScale)*=scale;
    label->resize(label->pixmap()->size()*(*currentScale));
}
