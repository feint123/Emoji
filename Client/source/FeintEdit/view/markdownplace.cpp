#include "markdownplace.h"

#include <factory/markdownfactory.h>
#include<QDebug>
#include <QPainter>
#include <action/editaction.h>
#include <action/noteaction.h>

MarkDownPlace::MarkDownPlace(QWidget *parent):
    QFrame(parent)
{
    this->edit=MarkDownFactory::create(this);
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
    insert_image=new QAction("插入图片");
    copyCont=new QAction("复制");
    cutCont=new QAction("剪切");
    pasteCont=new QAction("黏贴");
    preImages=new QAction("预览笔记中的所有图片");
    outCont=new QAction("导出笔记到...");
    outImage=new QAction("导出图片到...");
    addActionToList();
    addShortCuts();
    EditAction *action=new EditAction;
    NoteAction *nAction=new NoteAction;
    nAction->setParent(this);
    connect(insert_image,SIGNAL(triggered(bool)),this->edit,SLOT(on_insert_image()));
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
    cutCont->setShortcut(QKeySequence(tr("Ctrl+X")));
    pasteCont->setShortcut(QKeySequence(tr("Ctrl+V")));
    preImages->setShortcut(QKeySequence(tr("Alt+P")));
}

void MarkDownPlace::addActionToList()
{
    addBaseAction(insert_image);
    addBaseAction(copyCont);
    addBaseAction(cutCont);
    addBaseAction(pasteCont);
    addBaseAction(preImages);
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
    brush.setColor(QColor("#1f212b"));
    brush.setStyle(Qt::SolidPattern);
    painter.setBrush(brush);
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
}

MarkDownEdit *MarkDownPlace::getEdit() const
{
    return edit;
}
