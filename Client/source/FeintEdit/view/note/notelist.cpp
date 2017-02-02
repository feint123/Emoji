#include "noteitem.h"
#include "notelist.h"

#include <widget/view/listviewbeauti.h>
#include <QDebug>
#include <util/appcolorhelper.h>
#include <util/screenfit.h>
#include <plug/appstatic.h>
NoteList *NoteList::list=NULL;
NoteList::NoteList(QWidget *parent):
    QWidget(parent)
{
    noteH=new NoteHeader(this);
    noteH->createView();

    createList();
}

void NoteList::createList()
{
    AppColor *color=AppColorHelper::loadColor();
    listView=new ListView(this);
    listView->setScrollHandle(color->scrollHandle());
    listView->setScrollPage(color->scrollPage());
    listView->createView();
    listView->setBgColor(QColor(AppColorHelper::noteList()));
    listView->setBg(ListViewBeauti::colorBackground);
    listView->setMargin(QMargins(0,ScreenFit::fitToScreen(AppStatic::toolHeight+16)
                                 ,0,ScreenFit::fitToScreen(16)));

    listView->setColorStyle(FeintSetting::Daily);
    listView->setSpacing(8);
    listView->show();

    this->listView->setGeometry(0,0,this->width(),this->height());
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

        NoteItem *item=new NoteItem;

        listView->setItem(item);

        listView->addData(datas);

        noteH->raise();
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

    this->noteH->setGeometry(0,0,this->width(),ScreenFit::fitToScreen(AppStatic::toolHeight));

    this->noteH->raise();
}
