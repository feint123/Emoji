#include "imagerender.h"
#include <QDebug>
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

QImage ImageRender::changeLighting(double light)
{
    return image;
}

QImage ImageRender::changeQuarty(double q)
{
    return image;
}

QImage ImageRender::changeContrast()
{
    return image;
}

QImage ImageRender::changeRgb(int r, int b, int g)
{
    for(int i=0;i<image.width();i++)
    {

        for(int j=0;j<image.height();j++){

            QColor color=QColor(image.pixel(i,j));
            if(color.alpha()<255){
                qDebug()<<color.alpha();
                int colorResult=r+b+g;
                int red=color.red()*r*3/colorResult;
                int green=color.green()*g*3/colorResult;
                int blue=color.green()*g*3/colorResult;
                color.setRed(red>255?255:red);
                color.setGreen(green>255?255:green);
                color.setBlue(blue>255?255:blue);
            }
            image.setPixelColor(i,j,color);
        }
    }
    return this->image;
}
