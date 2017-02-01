#ifndef IMAGEUTIL_H
#define IMAGEUTIL_H

#include <QImage>
#include <qpaintdevice.h>



class ImageUtil:public QObject
{
public:
    ImageUtil();
    static QImage fitToDevice(QImage tempImage, QSize device);
    static QImage thumbImage(const QImage &img,int scale);
    static QImage fullDevice(QImage tempImage,QSize device);
    static bool saveImage(QString defaultPath,QString imgName,QImage image);
};

#endif // IMAGEUTIL_H
