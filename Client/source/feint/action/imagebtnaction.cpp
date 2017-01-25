#include "imagebtnaction.h"

#include <pane/markdown/dialog/markdownimagedialog.h>

#include <util/graphic/animationutil.h>

ImageBtnAction::ImageBtnAction()
{

}

void ImageBtnAction::updateImgInfo(QWidget *parent, Image *img)
{
    MarkdownImageDialog* dialog=MarkdownImageDialog::getInstance(parent);
    dialog->setWindowFlags(Qt::FramelessWindowHint);
    dialog->setGeometry((parent->width()-dialog->width())/2,-dialog->height(),dialog->width(),dialog->height());
    dialog->setImageUrl(img->tempPath().toUtf8());
    dialog->setImgWidth(img->width());
    dialog->setImgHeight(img->height());
    dialog->setImgTip(img->alt());
    dialog->show();
    AnimationUtil::GeometryAnim(dialog->geometry(),
                                QRect((parent->width()-dialog->width())/2,0,dialog->width(),dialog->height()),
                                dialog);
}
