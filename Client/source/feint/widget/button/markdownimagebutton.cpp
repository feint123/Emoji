#include "markdownimagebutton.h"
#include <QDebug>
#include <QPropertyAnimation>
#include <util/graphic/animationutil.h>
MarkdownImageButton::MarkdownImageButton(QWidget *parent):
    FButton(parent)
{

}

QString MarkdownImageButton::imagePath() const
{
    return m_imagePath;
}

QString MarkdownImageButton::imageTip() const
{
    return m_imageTip;
}

int MarkdownImageButton::imageWidth() const
{
    return m_imageWidth;
}

int MarkdownImageButton::imageHeight() const
{
    return m_imageHeight;
}

void MarkdownImageButton::createView()
{
    this->setText(this->imageTip());
    this->setMaxShadow(15);
    this->setBorderRadius(4);
    this->setBgColor("#d3d3d3");
    this->setColor("#787878");
    this->setIcon(QIcon(this->imagePath()));
    this->show();
}

void MarkdownImageButton::updatePosition(QRect rect)
{
   this->move(rect.x(),rect.y()+(rect.height()/2-this->height()/2));
}

QString MarkdownImageButton::posMark() const
{
    return m_posMark;
}

int MarkdownImageButton::anchor() const
{
    return m_anchor;
}

void MarkdownImageButton::setImagePath(QString imagePath)
{
    m_imagePath = imagePath;
}

void MarkdownImageButton::setImageTip(QString imageTip)
{
    m_imageTip = imageTip;
}

void MarkdownImageButton::setImageWidth(int imageWidth)
{
    m_imageWidth = imageWidth;
}

void MarkdownImageButton::setImageHeight(int imageHeight)
{
    m_imageHeight = imageHeight;
}


void MarkdownImageButton::setPosMark(QString posMark)
{
    m_posMark = posMark;
}

void MarkdownImageButton::setAnchor(int anchor)
{
    m_anchor = anchor;
}

void MarkdownImageButton::enterEvent(QEvent *event)
{
    emit previewImage(this);
    setCursor(QCursor(Qt::ArrowCursor));
}

void MarkdownImageButton::leaveEvent(QEvent *event)
{
    emit hideImage();
}

void MarkdownImageButton::focusOutEvent(QFocusEvent *event)
{
    emit hideImage();
}

void MarkdownImageButton::mousePressEvent(QMouseEvent *event)
{
//    this->dragAction=true;
//    oldPoint=event->pos();
}

void MarkdownImageButton::mouseMoveEvent(QMouseEvent *event)
{
    emit hideImage();
    int detaX=event->x()-oldPoint.x();
    int detaY=event->y()-oldPoint.y();
    if(dragAction)
    {
        this->move(this->x()+detaX,this->y()+detaY);
    }
}

void MarkdownImageButton::mouseReleaseEvent(QMouseEvent *event)
{/*
    this->dragAction=false;
    int line=this->y()/this->lineHeight();

    AnimationUtil::GeometryAnim(this->geometry(),
                                QRect(0,
                                      line*lineHeight()+(lineHeight()/2-this->height()/2)
                                      ,this->width(),this->height()),this);*/
}
