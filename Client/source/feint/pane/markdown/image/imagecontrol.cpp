#include "imagecontrol.h"

#include <QPainter>

ImageControl::ImageControl(QWidget *parent):
    QFrame(parent)
{
    createView();
}

int ImageControl::scale() const
{
    return m_scale;
}

int ImageControl::increase() const
{
    return m_increase;
}

void ImageControl::setScale(int scale)
{
    if (m_scale == scale)
        return;

    m_scale = scale;
    emit scaleChanged(scale);
}

void ImageControl::setIncrease(int increase)
{
    m_increase = increase;
}

void ImageControl::zoomInImage()
{

    setScale(scale()+increase());
}

void ImageControl::zoomOutImage()
{
    if(scale()>increase())
        setScale(scale()-increase());
}

void ImageControl::restoreImage()
{
    setScale(100);
}

void ImageControl::outImage()
{

}

void ImageControl::createView()
{
    zoomIn=createBasicBtn(QIcon(":/image/zoomin.png"));
    zoomOut=createBasicBtn(QIcon(":/image/zoomout.png"));
    restore=createBasicBtn(QIcon(":/image/screen-restore.png"));
    out=createBasicBtn(QIcon(":/image/out.png"));

    connect(zoomIn,SIGNAL(clicked(bool)),this,SLOT(zoomInImage()));
    connect(zoomOut,SIGNAL(clicked(bool)),this,SLOT(zoomOutImage()));
    connect(restore,SIGNAL(clicked(bool)),this,SLOT(restoreImage()));
    connect(out,SIGNAL(clicked(bool)),this,SLOT(outImage()));

    btnList.append(zoomOut);
    btnList.append(zoomIn);
    btnList.append(restore);
    btnList.append(out);
}

FButton *ImageControl::createBasicBtn(QIcon icon)
{
    FButton *btn=new FButton(this);
    btn->setMaxShadow(15);
    btn->setIcon(icon);
    btn->resize(40,40);
    btn->setBorderRadius(20);
    btn->setObjectName("control");
    btn->setStyleSheet(btn->styleSheet()+"#control{background:transparent;}"
                                         "#control:hover{border:1px solid #2064db;}");
    return btn;
}

void ImageControl::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QBrush brush(QColor(232,232,232,180));
    painter.setBrush(brush);
    painter.setPen(QPen(Qt::transparent));
    painter.drawRect(0,0,this->width(),this->height());
}

void ImageControl::resizeEvent(QResizeEvent *event)
{
    int btnWidth=40;
    int spacing=16;
    int totalWidth=btnList.count()*(btnWidth+spacing)-spacing;
    for(int i=0;i<btnList.count();i++)
    {
        btnList.at(i)->setGeometry(this->width()/2-totalWidth/2+i*(btnWidth+spacing),
                                   this->height()/2-btnWidth/2,
                                   btnWidth,btnWidth);
    }
}

