#include "markdownimagebutton.h"
#include <QDebug>
#include <QPropertyAnimation>
#include <action/imagebtnaction.h>
#include <pane/markdown/image/imagedialog.h>
#include <util/graphic/animationutil.h>
MarkdownImageButton::MarkdownImageButton(QWidget *parent):
    FButton(parent)
{
    setWindowFlags(Qt::FramelessWindowHint);
    createAction();
}

void MarkdownImageButton::createView()
{
    this->setText(image->alt());
    this->setMaxShadow(15);
    this->setBorderRadius(4);
    this->setBgColor("#d3d3d3");
    this->setColor("#787878");
  //  this->setIcon(QIcon(image->tempPath()));
    this->show();
}

void MarkdownImageButton::updatePosition(QRect rect)
{
   this->move(rect.x(),rect.y()+(rect.height()/2-this->height()/2));
}




void MarkdownImageButton::onEmitUpdateImgInfo()
{
    emit updateImageInfo((QWidget*)this->parent(),this->image);
}

void MarkdownImageButton::createAction()
{
    ImageBtnAction *action=new ImageBtnAction;
    menu=new QMenu();
    copyImage=new QAction("复制图片",this);
    cutImage=new QAction("剪切图片",this);
    outImage=new QAction("导出图片",this);
    updateImage=new QAction("修改图片信息",this);

    connect(updateImage,SIGNAL(triggered(bool)),this,SLOT(onEmitUpdateImgInfo()));
    connect(this,SIGNAL(updateImageInfo(QWidget*,Image*)),action,SLOT(updateImgInfo(QWidget*,Image*)));
    addShortCuts();
}

void MarkdownImageButton::addShortCuts()
{

}

Image *MarkdownImageButton::getImage() const
{
    return image;
}

void MarkdownImageButton::setImage(Image *value)
{
    image = value;
}

void MarkdownImageButton::enterEvent(QEvent *event)
{
    emit previewImage(this);
    setCursor(QCursor(Qt::ArrowCursor));
}

void MarkdownImageButton::contextMenuEvent(QContextMenuEvent *event)
{
    menu->clear();
    menu->addAction(copyImage);
    menu->addAction(cutImage);
    menu->addAction(outImage);
    menu->addSeparator();
    menu->addAction(updateImage);
    menu->exec(QCursor::pos());
    event->accept();
}

void MarkdownImageButton::mouseDoubleClickEvent(QMouseEvent *event)
{
    ImageDialog *frame=new ImageDialog;
    frame->setImageFile(image->tempPath());
    frame->resize(600,500);
    frame->setMinimumSize(600,500);
    frame->setWindowTitle(tr("%1 %2 x %3").
                          arg(image->alt()).arg(image->width()).arg(image->height()));
    frame->show();
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
