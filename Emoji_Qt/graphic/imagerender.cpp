#include "imagerender.h"

ImageRender::ImageRender()
{

}

void ImageRender::grayImg(QImage *image, double gray)
{

}

QImage ImageRender::getImage() const
{
    return image;
}

void ImageRender::setImage(const QImage &value)
{
    image = value;
}
