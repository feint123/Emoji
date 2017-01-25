#include "editaction.h"

#include <pane/markdown/image/imagepreviewdialog.h>
#include <QDebug>
EditAction::EditAction()
{

}

void EditAction::previewImages(Images images)
{
    ImagePreviewDialog *dialog=new ImagePreviewDialog();
    dialog->setDatas(images);
    dialog->createView();
    dialog->resize(800,600);
    dialog->show();
}
