#include "imageutil.h"

#include <QDir>
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

QImage ImageUtil::thumbImage(const QImage &img, int scale)
{
    int size=32*scale;
    QMatrix matrix;
    if(img.width()>img.height())
        matrix.scale(size/(float)img.width(),size/(float)img.width());
    else
        matrix.scale(size/(float)img.height(),size/(float)img.height());
    return img.transformed(matrix);
}

QImage ImageUtil::fullDevice(QImage img, QSize device)
{

    QMatrix matrix;
    float scale=(device.width())/(float)img.width();
    matrix.scale(scale,device.height()/(float)img.height());
    return img.transformed(matrix);
}

bool ImageUtil::saveImage(QString defaultPath, QString imgName, QImage image)
{
    QDir dir(defaultPath);
    dir.mkdir(imgName);
    for(int i=1;i<=16;i=i*2)
    {
        QImage _image=ImageUtil::thumbImage(image,i);
        _image.save(tr("%1/%2/%2_%3x.png").arg(defaultPath).arg(imgName).arg(i));
    }
    image.save(tr("%1/%2/%2.png").arg(defaultPath).arg(imgName));
}
