#include "imageframe.h"

#include <QPainter>

#include <QDebug>
#include <util/graphic/animationutil.h>

ImageFrame::ImageFrame(QWidget *parent):
    QFrame(parent)
{
    setScalePercent(100);
    scaleImage(100);
    connect(this,SIGNAL(scalePercentChanged(int)),this,SLOT(scaleImage(int)));
}

int ImageFrame::scalePercent() const
{
    return m_scalePercent;
}

QString ImageFrame::imageAlt() const
{
    return m_imageAlt;
}

QString ImageFrame::imageFile() const
{
    return m_imageFile;
}

void ImageFrame::setScalePercent(int scalePercent)
{
    if (m_scalePercent == scalePercent)
        return;

    m_scalePercent = scalePercent;
    emit scalePercentChanged(scalePercent);
}

void ImageFrame::setImageAlt(QString imageAlt)
{
    m_imageAlt = imageAlt;
}

void ImageFrame::setImageFile(QString imageFile)
{
    m_imageFile = imageFile;
    image.load(imageFile);
    pix=QPixmap::fromImage(image);
    resize(image.width(),image.height());

}

void ImageFrame::scaleImage(int scalePercent)
{
    QMatrix matrix;
    matrix.scale(scalePercent/100.0,scalePercent/100.0);
    image=QImage(imageFile()).transformed(matrix);
    pix=QPixmap::fromImage(image);
    resize(image.width(),image.height());

}

void ImageFrame::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
  //  painter.drawImage(0,0,image);
    painter.drawPixmap(0,0,pix);
}
