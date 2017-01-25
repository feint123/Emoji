#include "notes.h"

#include <factory/markdownfactory.h>

#include <domain/notetip.h>

#include <view/note/notelist.h>

#include <util/editloader.h>

Notes *Notes::notes=NULL;
Notes::Notes(QWidget *parent):
    QFrame(parent)
{
    createView();
}



void Notes::setFloatBtn(ControlFloatButton *value)
{
    floatBtn = value;
}

void Notes::setMark(MarkDownPlace *value)
{
    mark = value;
}

void Notes::createMark(QString noteFile)
{
    if(hasMark)
        delete mark;
    mark=new MarkDownPlace(this);
    mark->setPadding(42);
    mark->setNoteFile(noteFile);
    this->setMark(mark);
    mark->setGeometry(this->list->width(),0,
                            this->width()-this->list->width(),this->height());
    mark->show();
    if(hasMark)
        floatBtn->raise();
    hasMark=true;

}


ControlFloatButton *Notes::getFloatBtn() const
{
    return floatBtn;
}

MarkDownPlace *Notes::getMark() const
{
    return mark;
}


Notes *Notes::getInstance(QWidget *parent)
{
    if(notes==NULL)
        notes=new Notes(parent);

    return notes;
}

NoteList *Notes::getList() const
{
    return list;
}

Notes::~Notes()
{
    notes=NULL;
}


void Notes::createView()
{
    list=NoteList::getInstance(this);
    list->setFixedWidth(280);


   // edit= mark->getEdit();
}

void Notes::resizeEvent(QResizeEvent *event)
{


    this->list->setGeometry(0,0,this->list->width(),this->height());

    this->mark->setGeometry(this->list->width(),0,
                            this->width()-this->list->width(),this->height());

    this->floatBtn->setGeometry(this->width()-2*floatBtn->width(),
                                this->height()-floatBtn->width()-floatBtn->height(),
                                floatBtn->width(),
                                floatBtn->height());
}


