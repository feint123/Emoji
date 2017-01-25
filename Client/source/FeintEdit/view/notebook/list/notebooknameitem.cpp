#include "notebooknameitem.h"

#include <QLabel>

#include <domain/notebook.h>

NotebookNameItem::NotebookNameItem()
{

}

void NotebookNameItem::updateItem(QVariant item)
{
    NoteBook book=qvariant_cast<NoteBook>(item);
    QLabel* label=new QLabel("##"+book.name()+"##");
    label->resize(label->width(),24);
    label->setStyleSheet("QLabel{background:transparent;color:#444;padding-left:16px}"
                          "QLabel:hover{background:#3176ff;color:#eee}");
    setGraphic(label);
}
