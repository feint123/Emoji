#include "noteitem.h"
#include "noteitemview.h"

#include <domain/notetip.h>
#include <QDebug>
#include <util/screenfit.h>
NoteItem::NoteItem()
{

}
void NoteItem::updateItem(QVariant item)
{
    NoteTip note=qvariant_cast<NoteTip>(item);
    NoteItemView *noteView=new NoteItemView();
    noteView->setNote(&note);
    noteView->createActions();
    ScreenFit::fit(noteView);
    setGraphic(noteView);
}
