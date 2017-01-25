#include "imagedialog.h"

#include <QDebug>
#include <qboxlayout.h>

#include <widget/frame/shorttip.h>
ImageDialog::ImageDialog(QWidget *parent):
    QFrame(parent)
{
    connect(this,SIGNAL(imageFileChanged(QString)),this,SLOT(loadImage(QString)));

    createControl();
}

int ImageDialog::scalePercent() const
{
    return m_scalePercent;
}

QString ImageDialog::imageAlt() const
{
    return m_imageAlt;
}

QString ImageDialog::imageFile() const
{
    return m_imageFile;
}

void ImageDialog::setScalePercent(int scalePercent)
{
    if (m_scalePercent == scalePercent)
        return;

    m_scalePercent = scalePercent;
    emit scalePercentChanged(scalePercent);
}

void ImageDialog::setImageAlt(QString imageAlt)
{
    m_imageAlt = imageAlt;
}

void ImageDialog::setImageFile(QString imageFile)
{
    m_imageFile = imageFile;

    emit imageFileChanged(imageFile);
}

void ImageDialog::loadImage(QString imageFile)
{
    image=new ImageFrame(this);
    image->setWindowFlags(Qt::FramelessWindowHint);
    image->setImageFile(imageFile);
    image->setGeometry((this->width()-image->width())/2,
                       (this->height()-image->height())/2,
                       image->width(),image->height());
    image->show();
    area=new QScrollArea(this);
    area->setObjectName("s");
    area->setStyleSheet("#s{background:#a7a7a7;border:none;}");
    area->setWidget(image);
    area->setAlignment(Qt::AlignCenter);
    connect(this,SIGNAL(scalePercentChanged(int)),image,SLOT(setScalePercent(int)));
    connect(this,SIGNAL(scalePercentChanged(int)),this,SLOT(showScalePercent(int)));
}

void ImageDialog::showScalePercent(int scale)
{
    ShortTip *tip=ShortTip::getInstance(this);
    tip->resize(200,50);
    tip->setGeometry((this->width()-tip->width())/2,
                     (this->height()-tip->height())/2,
                     tip->width(),tip->height());
    tip->setTipStr(tr("缩放：%1 %").arg(scale));
    tip->raise();
    tip->showTip(1000);

}


void ImageDialog::createControl()
{
    control=new ImageControl(this);
    control->setWindowFlags(Qt::FramelessWindowHint);
    control->setScale(100);
    control->setIncrease(20);
    connect(control,SIGNAL(scaleChanged(int)),this,SLOT(setScalePercent(int)));

    control->show();
}

void ImageDialog::resizeEvent(QResizeEvent *event)
{
    int height=14;

    area->setGeometry(0,0,this->width(),this->height());

    int cW=400;
    control->setGeometry(this->width()/2-cW/2,this->height()-56,cW,56);
    control->raise();

}


