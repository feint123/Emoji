#include "noteeditcontroller.h"

#include <util/json/jsondata.h>

#include <view/note/noteitemview.h>

#include <QDebug>
#include <QTimer>

#include <util/settinghelper.h>
#include <util/timermanager.h>

#include <pane/markdown/markdownmanager.h>

#include <domain/appmessage.h>
#include <domain/lastedit.h>
#include <domain/timertag.h>

#include <plug/appstatic.h>

NoteEditController *NoteEditController::controller=NULL;
NoteEditController::NoteEditController(QObject *parent):
    QObject(parent)
{
    startEdit();
}

NoteEditController::~NoteEditController()
{
    controller=NULL;
}

NoteEditController *NoteEditController::getInstance(QObject *parent)
{
    if(controller==NULL)
        controller=new NoteEditController(parent);
    else if(controller->parent()!=parent&&parent!=0)
        controller->setParent(parent);


    return controller;
}

void NoteEditController::init(const QString &noteFile, const QString &noteBookFile, MarkDownEdit *edit)
{
    this->noteFile=noteFile;
    this->noteBookFile=noteBookFile;
    this->edit=edit;
    connect(edit,SIGNAL(textChanged()),this,SLOT(onEditChange()));
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

    delete manager;
    updateImageList();
    //更新笔记列表文件
    NoteTip tip=qvariant_cast<NoteTip>(this->list->getListView()->getCurrentItem());
    JsonData *data=new JsonData(SettingHelper::workPath(this->noteBookFile).toUtf8(),"notes");
    loadImageToTip(&tip);
    tip.setTitle(title->title());
    tip.setTip(((NoteItemView*)this->list->getListView()->getCurrentWidget())->tip());

    data->update(&tip,tip.id());

    delete data;

    updateLastEdit(&tip);

    TimerManager::getInstance()->getTimer(TimerTag::tag(TimerTag::NOTE_NUM_CHANGE))->start();

}

void NoteEditController::loadImageToTip(NoteTip *tip)
{
    JsonData *data=new JsonData(SettingHelper::workPath(this->noteFile+"_img.json").toUtf8(),"images");
    QList<Image *> images=data->selectAll<Image>();
    if(images.count()>0)
        tip->setImage(images[0]->file());
    else
        tip->setImage("");
    delete data;

    for(Image *img:images)
        img->deleteLater();
}

void NoteEditController::updateImageList()
{
    QList<int> imageIds=Image::getImageIdList(this->edit->getImageList());
    JsonData *data=new JsonData(SettingHelper::workPath(this->noteFile+"_img.json").toUtf8(),"images");
    QList<int> idList=Image::getImageIdList(data->selectAll<Image>());
    for(int id:idList)
    {
        if(imageIds.indexOf(id)>=0)
            continue;
        else
            data->deleteData(id);
    }

    delete data;
}

void NoteEditController::updateLastEdit(NoteTip *tip)
{
    LastEdit *last=new LastEdit;
    last->setFile(tip->fileName());
    last->setTip(tip->tip());
    last->setTitle(tip->title());
    last->setUpdateDate(QDateTime::currentDateTime());
    last->setBookFile(tip->notebook());
    JsonData *data=new JsonData(SettingHelper::workPath(
                                    AppMessage::getFileName(AppMessage::LASTEDIT)+".json").toUtf8(),
                                AppMessage::getFileName(AppMessage::LASTEDIT));
    if(AppStatic::lastEdit==AppStatic::maxLastEdit){
        data->deleteData(data->selectFirst<LastEdit>()->id());
        AppStatic::lastEdit-=1;
    }
    LastEdit *_last=data->selectByColumn<LastEdit>("file",tip->fileName());
    if(_last!=NULL)
        data->deleteData(_last->id());
    data->addData<LastEdit>(last);
    AppStatic::lastEdit=data->count();

    delete data;
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
