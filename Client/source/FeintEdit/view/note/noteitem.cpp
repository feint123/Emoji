#include "noteitem.h"
#include "noteitemview.h"

#include <domain/notetip.h>

NoteItem::NoteItem()
{

}
void NoteItem::updateItem(QVariant item)
{
    NoteTip note=qvariant_cast<NoteTip>(item);
    NoteItemView *noteView=new NoteItemView();
    noteView->setNote(&note);
    noteView->createActions();
    setGraphic(noteView);
}
