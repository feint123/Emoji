#include "imageitemview.h"

#include <QPainter>
#include <QDebug>

#include <util/graphic/effectutil.h>
#include <util/graphic/imageutil.h>

#include <pane/markdown/image/imagedialog.h>

ImageItemView::ImageItemView(QWidget *parent, Image *image):
    QFrame(parent)
{
}

void ImageItemView::setImage(Image *value)
{
    image = value;
    imageC=*image;
    img.load(image->tempPath());
    update();
}

void ImageItemView::paintEvent(QPaintEvent *event)
{
    QImage temp;
    int padding=4;
    if(img.isNull())
        return;
     temp=ImageUtil::fitToDevice(img,this->size());
        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing);
        painter.setBrush(QBrush(QColor(250,250,250,255),Qt::SolidPattern));
        painter.setPen(Qt::transparent);
        painter.drawRect(0,0,this->width(),this->height() );
        painter.drawImage(padding,padding,temp,(temp.width()-this->width())/2,
                          (temp.height()-this->height())/2,this->width()-padding*2,this->height()-padding*2);
}

void ImageItemView::mouseDoubleClickEvent(QMouseEvent *event)
{
    ImageDialog *frame=new ImageDialog;
    qDebug()<<"ImageItemView"<<imageC.tempPath();
    frame->setImageFile(imageC.tempPath());
    frame->resize(600,500);
    frame->setMinimumSize(600,500);
    frame->setWindowTitle(tr("%1 %2 x %3").
                          arg(imageC.alt()).arg(imageC.width()).arg(imageC.height()));
    frame->show();
}
