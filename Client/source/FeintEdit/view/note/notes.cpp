#include "notes.h"

#include <factory/markdownfactory.h>

#include <domain/notetip.h>

#include <view/note/notelist.h>

#include <util/editloader.h>
#include <util/screenfit.h>

#include <graphic/screenhelper.h>

#include <view/tool/notetool.h>

Notes *Notes::notes=NULL;
Notes::Notes(QWidget *parent):
    QFrame(parent)
{
    createView();
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
    mark->setPadding(ScreenFit::fitToScreen(42));
    mark->setNoteFile(noteFile);
    this->setMark(mark);
    mark->setGeometry(this->list->width(),tool->height(),
                            this->width()-this->list->width()
                      ,this->height()-tool->height());
    mark->installEventFilter(this);
    mark->show();
    ((NoteTool*)tool)->createMarkPull();
    hasMark=true;

}

void Notes::setTool(QDialog *value)
{
    tool = value;
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
    setAttribute(Qt::WA_DeleteOnClose);
    setWindowFlags(Qt::FramelessWindowHint);
    list=NoteList::getInstance(this);
    list->setMinimumWidth(ScreenHelper::getScreenSize().width()/6);

    list->installEventFilter(this);

   // edit= mark->getEdit();
}

void Notes::resizeEvent(QResizeEvent *event)
{


    this->list->setGeometry(0,0,this->width()/5,this->height());

    this->tool->setGeometry(list->width(),0,this->width()-list->width(),tool->height());

    this->mark->setGeometry(this->list->width(),tool->height(),
                            this->width()-this->list->width(),
                            this->height()-tool->height());


    NotebookNameDialog *dialog=NotebookNameDialog::getInstance();

    if(dialog!=NULL&&dialog->isVisible())
       dialog->close();
}

bool Notes::eventFilter(QObject *watched, QEvent *event)
{
    if(event->type()==QEvent::MouseButtonPress){
        NotebookNameDialog *dialog=NotebookNameDialog::getInstance();

        if(dialog!=NULL&&dialog->isVisible())
           dialog->close();
    }

}


