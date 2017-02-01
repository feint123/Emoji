#include "noteitem.h"
#include "notelist.h"

#include <widget/view/listviewbeauti.h>
#include <QDebug>
#include <util/appcolorhelper.h>
#include <util/screenfit.h>
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
        AppColor *color=AppColorHelper::loadColor();
        listView=new ListView(this);
        listView->setScrollHandle(color->scrollHandle());
        listView->setScrollPage(color->scrollPage());
        listView->createView();
        listView->setBgColor(QColor(AppColorHelper::noteList()));
        listView->setBg(ListViewBeauti::colorBackground);
        listView->setMargin(QMargins(0,ScreenFit::fitToScreen(50+16),0,ScreenFit::fitToScreen(16)));
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

    this->noteH->setGeometry(0,0,this->width(),ScreenFit::fitToScreen(54));

    this->noteH->raise();
}
