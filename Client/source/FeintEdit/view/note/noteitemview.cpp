#include "noteitemview.h"
#include "notes.h"
#include "ui_noteitemview.h"

#include <QPainter>
#include <qevent.h>

#include <util/graphic/effectutil.h>
#include <QDebug>
#include <action/noteaction.h>

NoteItemView::NoteItemView(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::NoteItemView)
{
    ui->setupUi(this);
    EffectUtil::addDropShadow(16,"#000",this);
}

NoteItemView::~NoteItemView()
{
    delete ui;
}

void NoteItemView::setNote(NoteTip *note)
{
    noteq=QVariant::fromValue(*note);
    ui->titleLab->setText(note->title());
    ui->tipEdit->setText(note->tip());
    ui->updateLab->setText(note->updateDate().toString("yyyy-MM-dd HH:mm"));

}

QString NoteItemView::tip() const
{
    return ui->tipEdit->toPlainText();
}

QString NoteItemView::title() const
{
    return ui->titleLab->text();
}

void NoteItemView::setTip(QString tip)
{
    m_tip = tip;
    ui->tipEdit->setText(tip);
}

void NoteItemView::setTitle(QString title)
{
    m_title = title;
    ui->titleLab->setText(title);
}

void NoteItemView::onDeleteNote()
{
    NoteTip tip=qvariant_cast<NoteTip>(noteq);
    emit deleteNoteAction(tip.id(),tip.notebook());
}

void NoteItemView::onEmitMoveNote()
{
    NoteTip tip=qvariant_cast<NoteTip>(noteq);
    emit moveNoteAction(&tip,Notes::getInstance());
}

void NoteItemView::onEmitCopyNote()
{
    NoteTip tip=qvariant_cast<NoteTip>(noteq);
    emit copyNoteAction(&tip,Notes::getInstance());
}

void NoteItemView::onEmitInNote()
{
    NoteTip tip=qvariant_cast<NoteTip>(noteq);
    emit inNoteAction(tip.notebook());
}

void NoteItemView::createActions()
{
    menu=new QMenu();
    this->newNote=new QAction("新建笔记",this);
    this->deleteNote=new QAction("删除笔记",this);
    this->shareNote=new QAction("分享笔记",this);
    shareNote->setEnabled(false);
    inNote=new QAction("导入笔记",this);
    outNote=new QAction("导出笔记至...",this);
    this->moveToNotebook=new QAction("移动到笔记本",this);
    this->copyToNotebook=new QAction("复制到笔记本",this);


    connect(deleteNote,SIGNAL(triggered(bool)),this,SLOT(onDeleteNote()));

    NoteAction *action=new NoteAction;
    connect(this,SIGNAL(deleteNoteAction(int,QString)),action,SLOT(deleteNote(int,QString)));
    connect(newNote,SIGNAL(triggered(bool)),action,SLOT(addNote()));
    connect(moveToNotebook,SIGNAL(triggered(bool)),this,SLOT(onEmitMoveNote()));
    connect(copyToNotebook,SIGNAL(triggered(bool)),this,SLOT(onEmitCopyNote()));
    connect(inNote,SIGNAL(triggered(bool)),this,SLOT(onEmitInNote()));
    connect(this,SIGNAL(inNoteAction(QString)),action,SLOT(inNote(QString)));
    connect(this,SIGNAL(moveNoteAction(NoteTip*,QWidget*)),
            action,SLOT(moveToNotebook(NoteTip*,QWidget*)));
    connect(this,SIGNAL(copyNoteAction(NoteTip*,QWidget*)),
            action,SLOT(copyToNotebook(NoteTip*,QWidget*)));

}

void NoteItemView::addShortCuts()
{
    this->newNote->setShortcut(QKeySequence(tr("Alt+N")));

    this->deleteNote->setShortcut(QKeySequence(QKeySequence::Delete));
    this->shareNote->setShortcut(QKeySequence(tr("Alt+S")));
}



void NoteItemView::paintEvent(QPaintEvent *event)
{
    int border=4;
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    painter.setBrush(QBrush(QColor("#1f212b")));
    painter.setPen(Qt::transparent);

    painter.drawRect(QRect(0,border,
                                  this->width(),this->height()-2*border));
}


void NoteItemView::contextMenuEvent(QContextMenuEvent *event)
{
    menu->clear();
    menu->addAction(newNote);
    menu->addSeparator();
    menu->addAction(deleteNote);
    menu->addAction(shareNote);
    menu->addSeparator();
    menu->addAction(inNote);
    menu->addAction(outNote);
    menu->addSeparator();
    menu->addAction(moveToNotebook);
    menu->addAction(copyToNotebook);

    menu->exec(QCursor::pos());
    event->accept();
}
