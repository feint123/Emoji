#include "imagebtnaction.h"

#include <pane/markdown/dialog/markdownimagedialog.h>

#include <util/graphic/animationutil.h>

#include <util/json/jsondata.h>

#include <QDebug>

#include <util/dialogshowutil.h>

ImageBtnAction::ImageBtnAction()
{

}

void ImageBtnAction::updateImgInfo(QWidget *parent, Image *img,QString defaultPath)
{
    MarkdownImageDialog* dialog=MarkdownImageDialog::getInstance(parent);
    dialog->setFlag(MarkdownImageDialog::UPDATE);
    dialog->setWindowFlags(Qt::FramelessWindowHint);

    connect(dialog,SIGNAL(updateImage(QString)),this,SLOT(updateImgName(QString)));
    dialog->setImageUrl(img->tempPath().toUtf8());
    dialog->setImgWidth(img->width());
    dialog->setImgHeight(img->height());
    dialog->setImgTip(img->alt());
    id=img->id();
    this->defaultPath=defaultPath;
    dialog->raise();
    DialogShowUtil::show(parent,dialog);
}

void ImageBtnAction::updateImgName(QString name)
{
    JsonData *datas=new JsonData(defaultPath.toUtf8(),"images");
    Image *img=datas->selectById<Image>(id);
    img->setAlt(name);
    datas->update<Image>(img,id);

    delete datas;
}
