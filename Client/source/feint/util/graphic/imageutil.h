#ifndef IMAGEUTIL_H
#define IMAGEUTIL_H

#include <QImage>
#include <qpaintdevice.h>



class ImageUtil
{
public:
    ImageUtil();
    static QImage fitToDevice(QImage tempImage, QSize device);
};

#endif // IMAGEUTIL_H
