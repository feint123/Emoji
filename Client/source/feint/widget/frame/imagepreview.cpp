#include "imagepreview.h"

#include <QPainter>
#include <QDebug>

#include <util/graphic/innerdialogrect.h>

ImagePreview *ImagePreview::preview=NULL;
ImagePreview::ImagePreview(QWidget *parent):
    QFrame(parent)
{
    setWindowFlags(Qt::FramelessWindowHint);
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

void ImagePreview::setStore(QString store)
{
    m_store = store;
}

void ImagePreview::paintEvent(QPaintEvent *event)
{

    int border=6;
    InnerDialogRect *inner=new InnerDialogRect(InnerDialogRect::UP);
    inner->setTri(tri);
    inner->draw(preview,deta);

    QPainter painter(preview);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.drawPixmap(border,tri+border,
                       preview->size.width()-2*border,
                       preview->size.height()-2*border,loadImage());

}

void ImagePreview::setSize(const QSize &value)
{
    size = value;
}

QPixmap ImagePreview::loadImage()
{
    fileUtil->setFileName(path());
    QImage img=fileUtil->loadImage();
    QPixmap pix=QPixmap::fromImage(img);
    return pix;
}

void ImagePreview::setFileUtil(FileUtil *value)
{
    fileUtil = value;
}


void ImagePreview::fixSize(QSize maxSize)
{
    if(preview->size.width()>maxSize.width()/3*2)
    {

        size.setHeight(preview->size.height()*(maxSize.width()*2/3)/preview->size.width());
        size.setWidth(maxSize.width()*2/3);
    }
    resize(size.width(),size.height()+tri);
}

void ImagePreview::fixPosition(QRect imgBtn)
{
    preview->deta=imgBtn.width()/2;
    preview->move(imgBtn.x(),imgBtn.y()+imgBtn.height());
}

ImagePreview::~ImagePreview()
{
    preview=NULL;
}

ImagePreview *ImagePreview::getInstance(QWidget *parent)
{
    if(preview==NULL)
        preview=new ImagePreview(parent);
    return preview;
}

QString ImagePreview::store() const
{
    return m_store;
}
