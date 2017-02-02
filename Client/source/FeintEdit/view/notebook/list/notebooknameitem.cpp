#include "notebooknameitem.h"

#include <QLabel>

#include <domain/notebook.h>

#include <util/screenfit.h>
#include <util/stringutil.h>

#include <plug/appstatic.h>

NotebookNameItem::NotebookNameItem()
{

}

void NotebookNameItem::updateItem(QVariant item)
{
    NoteBook book=qvariant_cast<NoteBook>(item);
    QLabel* label=new QLabel("##"+StringUtil::fitToLength(book.name(),AppStatic::maxTitleLength)+"##");
    label->resize(label->width(),24);
    label->setAlignment(Qt::AlignCenter);
    label->setStyleSheet("QLabel{background:transparent;color:#444;}"
                          "QLabel:hover{background:#3176ff;color:#eee}");

    ScreenFit::fitWithFont(label);
    setGraphic(label);
}
