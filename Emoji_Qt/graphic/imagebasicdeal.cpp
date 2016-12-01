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
//    if((*currentScale)<1)
//    {
//        QPixmap pixmap=*(label->pixmap());
//        pixmap=pixmap.scaledToWidth(pixmap.width()*scale);
//        label->setPixmap(pixmap);
//        label->resize(label->pixmap()->size());
//        return;
//    }
    label->resize(label->pixmap()->size()*(*currentScale));
}
