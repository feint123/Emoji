#include "noteitem.h"
#include "notelist.h"

#include <widget/view/listviewbeauti.h>
NoteList *NoteList::list=NULL;
NoteList::NoteList(QWidget *parent):
    QWidget(parent)
{
    noteH=new NoteHeader(this);
    noteH->createView();
}

NoteHeader *NoteList::getNoteH() const
{
    return noteH;
}

NoteList::~NoteList()
{
    list=NULL;
}

void NoteList::loadDate(QList<QVariant> datas)
{
    if(init)
        delete listView;

    {
        listView=new ListView(this);
        listView->setBgColor(QColor("#1f212b"));
        listView->setBg(ListViewBeauti::colorBackground);
        listView->setMargin(QMargins(0,50+16,0,16));
        listView->setData(datas);
        NoteItem *item=new NoteItem;
        listView->setItem(item);
        listView->setColorStyle(FeintSetting::Daily);
        listView->setSpacing(8);
        listView->show();
        this->listView->setGeometry(0,0,this->width(),this->height());
        init=true;

        noteH->raise();
    }
}

ListView *NoteList::getListView() const
{
    return listView;
}

NoteList *NoteList::getInstance(QWidget *parent)
{
    if(list==NULL)
        list=new NoteList(parent);
    return list;
}

void NoteList::resizeEvent(QResizeEvent *event)
{
    this->listView->setGeometry(0,0,this->width(),this->height());

    this->noteH->setGeometry(0,0,this->width(),54);

    this->noteH->raise();
}