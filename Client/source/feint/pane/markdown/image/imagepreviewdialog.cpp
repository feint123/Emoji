#include "imagepreviewdialog.h"

#include <util/qvariantutil.h>

#include <pane/markdown/image/list/imageitem.h>

#include <widget/view/gridviewbeauti.h>

ImagePreviewDialog::ImagePreviewDialog(QWidget *parent)
{

}

void ImagePreviewDialog::setDatas(QList<Image *> imageList)
{
    grid=new GridView(this);

    grid->setBgImage(QImage(imageList.at(0)->tempPath()+"_8x.png"));
    grid->setBgFun(GridViewBeauti::imageWithPane);
    grid->setHorizontalSpacing(16);
    grid->setVerticalSpacing(16);
    grid->setPadding(QMargins(32,32,32,32));
    QVariantUtil *util=new QVariantUtil();
    grid->setData(util->turn<Image>(imageList));
    grid->setItem(new ImageItem());
    grid->setGeometry(0,0,this->width(),this->height());
    grid->show();

    delete util;
//    for(Image *img:imageList)
//        img->deleteLater();
}

void ImagePreviewDialog::imageSelect(QVariant qvariant)
{
    Image image=qvariant_cast<Image>(qvariant);
    imageView->setImage(&image);

    imageView->show();
    info->show();

    grid->setBgImage(QImage(image.tempPath()+"_16x.png"));

    grid->setPadding(QMargins(32,32+size.height(),32,32));

    updateResize();

    emit createImageInfo(&image);
}

void ImagePreviewDialog::updateResize()
{


    if(grid==NULL)
        return;
    grid->setGeometry(0,0,this->width(),this->height());

    int viewWith=size.height()*((float)size.height()/(float)size.width());
    imageView->setGeometry((this->width()-viewWith-info->width())/2,
                           grid->padding().bottom()/2,
                           viewWith,
                           size.height());
    info->setGeometry(imageView->x()+imageView->width(),
                      grid->padding().bottom()/2,
                      size.width(),size.height());
    update();
}

void ImagePreviewDialog::createView()
{
    imageView=new ImageItemView(this);
    imageView->hide();
    info=new ImageInfoDialog(this);
    info->hide();
    info->setWindowFlags(Qt::FramelessWindowHint);
    connect(grid,SIGNAL(selectItemValue(QVariant)),this,SLOT(imageSelect(QVariant)));
    connect(this,SIGNAL(createImageInfo(Image*)),info,SLOT(setImage(Image* )));
}

void ImagePreviewDialog::resizeEvent(QResizeEvent *event)
{
    updateResize();
}
