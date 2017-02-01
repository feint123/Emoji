#include "markdownplace.h"

#include <factory/markdownfactory.h>
#include<QDebug>
#include <QPainter>

#include <action/editaction.h>
#include <action/noteaction.h>
#include <controller/noteeditcontroller.h>
#include <domain/wordstatic.h>
#include <util/appcolorhelper.h>
#include <util/settinghelper.h>

MarkDownPlace::MarkDownPlace(QWidget *parent):
    QFrame(parent)
{
    this->edit=MarkDownFactory::create(this);
    watcher=new QFileSystemWatcher(this);
    lighterLine=edit->cursorRect();

    this->title=new MarkDownTitle(this);
    connect(this,SIGNAL(resizeFrame()),edit,SLOT(updateImgBtnLine()));
    createActions();
    this->edit->setActionList(this->getActionList());

}

void MarkDownPlace::resizeEvent(QResizeEvent *event)
{
    this->edit->setGeometry(padding,2*padding,this->width()-2*padding,
                            this->height()-padding*2);

    emit resizeFrame();

    this->title->setGeometry(padding,0,this->width()-2*padding,padding*1.5);

    resizeView();
}

void MarkDownPlace::createActions()
{
    menu=new QMenu();
    insert_image=new QAction(WordStatic::insert+WordStatic::photo,this);
    save=new QAction(WordStatic::save,this);
    copyCont=new QAction(WordStatic::copy,this);
    cutCont=new QAction(WordStatic::cut,this);
    pasteCont=new QAction(WordStatic::paste,this);
    //预览笔记中的所有图片
    preImages=new QAction("",this);
    outCont=new QAction(WordStatic::out+WordStatic::note,this);
    outImage=new QAction(WordStatic::out+WordStatic::photo,this);


    addActionToList();
    addShortCuts();
    EditAction *action=new EditAction;
    NoteAction *nAction=new NoteAction;
    nAction->setParent(this);
    connect(insert_image,SIGNAL(triggered(bool)),this->edit,SLOT(on_insert_image()));
    connect(save,SIGNAL(triggered(bool)),NoteEditController::getInstance(),SLOT(onAutoSave()));
    connect(copyCont,SIGNAL(triggered(bool)),this->edit,SLOT(copy()));
    connect(cutCont,SIGNAL(triggered(bool)),this->edit,SLOT(cut()));
    connect(pasteCont,SIGNAL(triggered(bool)),this->edit,SLOT(paste()));
    connect(preImages,SIGNAL(triggered(bool)),this,SLOT(onEmitPreviewImages()));
    connect(outCont,SIGNAL(triggered(bool)),this,SLOT(onEmitOutNote()));
    connect(outImage,SIGNAL(triggered(bool)),this,SLOT(onEmitOutImages()));
    connect(this,SIGNAL(outNoteAction(QString)),nAction,SLOT(outNote(QString)));
    connect(this,SIGNAL(outImagesAction(QString)),nAction,SLOT(outImages(QString)));
    connect(this,SIGNAL(previewImages(Images)),action,SLOT(previewImages(Images)));

    this->addActions(getActionList());

}

void MarkDownPlace::addShortCuts()
{
    insert_image->setShortcut(QKeySequence(tr("Ctrl+Alt+I")));
    copyCont->setShortcut(QKeySequence(tr("Ctrl+C")));
    save->setShortcut(QKeySequence(tr("Ctrl+S")));
    cutCont->setShortcut(QKeySequence(tr("Ctrl+X")));
    pasteCont->setShortcut(QKeySequence(tr("Ctrl+V")));
    preImages->setShortcut(QKeySequence(tr("Alt+P")));
}

void MarkDownPlace::addActionToList()
{
    addBaseAction(insert_image);
    addBaseAction(save);
    addBaseAction(copyCont);
    addBaseAction(cutCont);
    addBaseAction(pasteCont);
  //  addBaseAction(preImages);
    addBaseAction(outCont);
    addBaseAction(outImage);
}

void MarkDownPlace::resizeView()
{

//    int lp=4;
//    upFrame->setGeometry(0,1.5*padding,this->width(),lighterLine.y()-lp+0.5*padding);

//    downFrame->setGeometry(0,lighterLine.y()+lighterLine.height()+2*padding+lp
//                           ,this->width(),
//                           this->height()-2*padding-lighterLine.y());
}

MarkDownTitle *MarkDownPlace::getTitle() const
{
    return title;
}

void MarkDownPlace::onEmitPreviewImages()
{
    emit previewImages(edit->getImageList());
}

void MarkDownPlace::updateHighlighterLine()
{
    lighterLine=edit->cursorRect();
    resizeView();
}

void MarkDownPlace::onEmitOutNote()
{
    emit outNoteAction(edit->noteFile());
}

void MarkDownPlace::onEmitOutImages()
{
    emit outImagesAction(edit->noteFile());
}

void MarkDownPlace::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QBrush brush;
    brush.setColor(QColor(AppColorHelper::editorBg()));
    brush.setStyle(Qt::SolidPattern);
    painter.setBrush(brush);
    painter.setPen(Qt::transparent);
    painter.drawRect(0,0,this->width(),this->height());

}

void MarkDownPlace::contextMenuEvent(QContextMenuEvent *event)
{
    menu->clear();
    menu->addActions(getActionList());

    menu->exec(QCursor::pos());
    event->accept();
}


void MarkDownPlace::setPadding(int value)
{
    padding = value;
}

void MarkDownPlace::setNoteFile(QString noteFile)
{
    edit->setNoteFile(noteFile);
    watcher->addPath(SettingHelper::workPath(noteFile+"_img.json"));
    connect(watcher,SIGNAL(fileChanged(QString)),edit,SLOT(updateImgBtnLine()));
}

MarkDownEdit *MarkDownPlace::getEdit() const
{
    return edit;
}
