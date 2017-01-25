#include "imageutil.h"

#include <QMatrix>

ImageUtil::ImageUtil()
{

}

QImage ImageUtil::fitToDevice(QImage tempImage, QSize device)
{
    QMatrix matrix;
    if(tempImage.width()<device.width())
    {
        matrix.scale((float)device.width()/(float)tempImage.width(),
                   (float)device.width()/(float)tempImage.width());
        tempImage=tempImage.transformed(matrix);
    }
    if(tempImage.height()<device.height())
    {
        matrix.scale((float)device.height()/(float)tempImage.height(),
                   (float)device.height()/(float)tempImage.height());
        tempImage=tempImage.transformed(matrix);
    }
    return tempImage;
}
