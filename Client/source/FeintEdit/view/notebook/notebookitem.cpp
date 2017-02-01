#include "notebookitem.h"
#include "notebookitemview.h"

#include <QPushButton>

#include <util/screenfit.h>

NotebookItem::NotebookItem()
{

}

void NotebookItem::updateItem(QVariant item)
{
    NotebookItemView *view=new NotebookItemView();
    NoteBook notebook=qvariant_cast<NoteBook>(item);
    view->setNotebook(&notebook);
    view->createView();
    view->resize(304,68);
    ScreenFit::fit(view);
    setGraphic(view);
}
