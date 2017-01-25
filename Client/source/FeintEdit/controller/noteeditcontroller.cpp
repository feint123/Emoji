#include "noteeditcontroller.h"

#include <util/json/jsondata.h>

#include <view/note/noteitemview.h>

#include <QDebug>
#include <QTimer>

#include <util/settinghelper.h>

#include <pane/markdown/markdownmanager.h>
NoteEditController::NoteEditController(const QString &noteFile, const QString &noteBookFile, MarkDownEdit *edit)
{
    this->noteFile=noteFile;
    this->noteBookFile=noteBookFile;
    this->edit=edit;
    connect(edit,SIGNAL(textChanged()),this,SLOT(onEditChange()));
}

NoteEditController::~NoteEditController()
{
    delete timer;
}

void NoteEditController::onEditChange()
{
    NoteItemView *view=(NoteItemView*)(list->getListView()->getCurrentWidget());

    QString tip=edit->toPlainText().remove("\n");
    view->setTip(tip.length()>43?(tip.mid(0,40)+"..."):tip);
}

void NoteEditController::onTitleChange(QString title)
{
    NoteItemView *view=(NoteItemView*)(list->getListView()->getCurrentWidget());
    view->setTitle(title);
}

void NoteEditController::onAutoSave()
{
    //保存笔记文件
    MarkdownManager *manager=new MarkdownManager();
    manager->setTitle(title->title());
    manager->save(tr("%1/%2.fei").arg(SettingHelper::workspacing()).arg(this->noteFile),
                  this->edit->toPlainText());
    //更新笔记列表文件
    NoteTip tip=qvariant_cast<NoteTip>(this->list->getListView()->getCurrentItem());
    JsonData *data=new JsonData(SettingHelper::workPath(this->noteBookFile).toUtf8(),"notes");
    tip.setTitle(title->title());
    tip.setTip(((NoteItemView*)this->list->getListView()->getCurrentWidget())->tip());
    data->update(&tip,tip.id());
    timer->start();

}

void NoteEditController::setTitle(MarkDownTitle *value)
{
    title = value;
    connect(title,SIGNAL(titleChanged(QString)),this,SLOT(onTitleChange(QString)));

}

void NoteEditController::setList(NoteList *value)
{
    list = value;
}

void NoteEditController::startEdit()
{
    timer=new QTimer(this);
    timer->setInterval(SettingHelper::autoSave()*1000);
    connect(timer,SIGNAL(timeout()),this,SLOT(onAutoSave()));
    timer->start();

}
