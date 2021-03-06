#include "notebookstarter.h"

#include <domain/wordstatic.h>

NotebookStarter::NotebookStarter(QWidget *parent):
    QFrame(parent)
{
    createView();
}

FButton *NotebookStarter::getStart() const
{
    return start;
}

void NotebookStarter::createView()
{
    start=new FButton(this);
    start->setMaxShadow(14);
    //Todo: tip_1 "新建笔记本，开始新的旅程"
    start->setText(WordStatic::tip_1);
    start->setBorderRadius(100);
    start->resize(200,200);
}

void NotebookStarter::resizeEvent(QResizeEvent *event)
{
    start->setGeometry((this->width()-start->width())/2,
                       (this->height()-start->height())/2,
                       start->width(),start->height());
}
