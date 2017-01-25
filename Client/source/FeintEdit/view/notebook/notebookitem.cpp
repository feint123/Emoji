#include "notebookitem.h"
#include "notebookitemview.h"

#include <QPushButton>

NotebookItem::NotebookItem()
{

}

void NotebookItem::updateItem(QVariant item)
{
    NotebookItemView *view=new NotebookItemView();
    NoteBook notebook=qvariant_cast<NoteBook>(item);
    view->setNotebook(&notebook);
    view->createView();
    view->resize(256,56);
    setGraphic(view);
}
