#include "booknamefactory.h"

#include <util/appcolorhelper.h>
#include <util/screenfit.h>

#include <util/graphic/effectutil.h>

BookNameFactory::BookNameFactory()
{

}

NotebookNameDialog *BookNameFactory::create(QString title)
{
    NotebookNameDialog *dialog=NotebookNameDialog::getInstance();
    dialog->setWindowFlags(Qt::Popup);
    EffectUtil::addDropShadow(25,AppColorHelper::noteListShadow(),dialog);
    dialog->setTitle(title);
    dialog->setUserTri(true);
    dialog->setMaximumHeight(500);
    dialog->setTop(8);
    dialog->setBottom(8);
    dialog->createList();
    dialog->resize(ScreenFit::fitToScreen(225),dialog->getHeight());
    return dialog;
}
