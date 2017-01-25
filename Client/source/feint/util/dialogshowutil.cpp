#include "dialogshowutil.h"

#include <util/graphic/animationutil.h>

DialogShowUtil::DialogShowUtil()
{

}

void DialogShowUtil::show(QWidget *parent, QWidget *dialog,int offset)
{
    dialog->setGeometry((parent->width()-dialog->width())/2,
                        -dialog->height(),
                        dialog->width(),dialog->height());
    dialog->show();
    AnimationUtil::GeometryAnim(dialog->geometry(),
                                QRect((parent->width()-dialog->width())/2,offset,
                                dialog->width(),dialog->height()),dialog);
}
