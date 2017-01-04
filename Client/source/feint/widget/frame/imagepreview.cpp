#include "imagepreview.h"

#include <QPainter>
#include <QDebug>

#include <util/graphic/innerdialogrect.h>
ImagePreview::ImagePreview(QWidget *parent, QSize size):
    QFrame(parent)
{
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->size=size;
}

QString ImagePreview::path() const
{
    return m_path;
}

void ImagePreview::setPath(QString path)
{
    m_path = path;
    update();
}

void ImagePreview::paintEvent(QPaintEvent *event)
{

    int border=6;
    InnerDialogRect *inner=new InnerDialogRect(InnerDialogRect::UP);
    inner->setTri(tri);
    inner->draw(this,deta);
    QPixmap pix(this->path());
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.drawPixmap(border,tri+border,
                       this->size.width()-2*border,
                       this->size.height()-2*border,pix);

}

void ImagePreview::fixSize(QSize maxSize)
{
    if(this->size.width()>maxSize.width()/3*2)
    {

        size.setHeight(this->size.height()*(maxSize.width()*2/3)/this->size.width());
        size.setWidth(maxSize.width()*2/3);
    }
    resize(size.width(),size.height()+tri);
}

void ImagePreview::fixPosition(QRect imgBtn)
{
    this->deta=imgBtn.width()/2;
    this->move(imgBtn.x(),imgBtn.y()+imgBtn.height());
}
