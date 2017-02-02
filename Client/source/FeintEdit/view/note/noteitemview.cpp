#include "noteitemview.h"
#include "notes.h"
#include "ui_noteitemview.h"

#include <QPainter>
#include <qevent.h>

#include <util/graphic/effectutil.h>
#include <QDebug>
#include <action/noteaction.h>
#include <pane/markdown/image/imageframe.h>
#include <util/appcolorhelper.h>
#include <util/screenfit.h>
#include <util/settinghelper.h>
#include <util/stringutil.h>
#include <domain/wordstatic.h>
#include <plug/appstatic.h>

NoteItemView::NoteItemView(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::NoteItemView)
{

    ui->setupUi(this);
    AppColor *color=AppColorHelper::loadColor();
    ui->tipEdit->setStyleSheet(tr("#tipEdit{border:none;background:transparent;color:%1}")
                               .arg(color->colorMid()));
    ui->titleLab->setStyleSheet(tr("color:%1").arg(color->colorTop()));
    ui->updateLab->setStyleSheet(tr("color:%1").arg(color->colorBot()));
    EffectUtil::addDropShadow(16,AppColorHelper::noteListShadow(),this);

    ScreenFit::fitFont(ui->tipEdit);
    ScreenFit::fitFont(ui->titleLab);
    ScreenFit::fitFont(ui->updateLab);
}

NoteItemView::~NoteItemView()
{
    delete ui;
}

void NoteItemView::setNote(NoteTip *note)
{
    noteq=QVariant::fromValue(*note);
    ui->titleLab->setText(StringUtil::fitToLength(note->title(),AppStatic::maxTitleLength));
    ui->titleLab->setToolTip(note->title());
    ui->tipEdit->setText(note->tip());
    ui->updateLab->setText(note->updateDate().toString("yyyy-MM-dd HH:mm"));
    if(note->image().length()>0){
        ui->frame->setImageFile(SettingHelper::workPath(note->image()+"/"+note->image()+"_4x.png"));
        ui->frame->scaleImage(((ScreenFit::fitToScreen(this->height())/2)
                               /(float)ui->frame->height())*100);
        ui->frame->setFixedSize(ScreenFit::fitToScreen(this->height())*0.5,
                                ScreenFit::fitToScreen(this->height())*0.5);


    }
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
    emit moveNoteAction(&tip);
}

void NoteItemView::onEmitCopyNote()
{
    NoteTip tip=qvariant_cast<NoteTip>(noteq);
    emit copyNoteAction(&tip);
}

void NoteItemView::onEmitInNote()
{
    NoteTip tip=qvariant_cast<NoteTip>(noteq);
    emit inNoteAction(tip.notebook());
}

void NoteItemView::createActions()
{
    menu=new QMenu();
    this->newNote=new QAction(WordStatic::new_+WordStatic::note,this);
    this->deleteNote=new QAction(WordStatic::del+WordStatic::note,this);
    this->shareNote=new QAction(WordStatic::share+WordStatic::note,this);
    shareNote->setEnabled(false);
    inNote=new QAction(WordStatic::in+WordStatic::note,this);
    outNote=new QAction(WordStatic::out+WordStatic::note,this);
    this->moveToNotebook=new QAction(WordStatic::moveTo+WordStatic::book,this);
    this->copyToNotebook=new QAction(WordStatic::copyTo+WordStatic::book,this);


    connect(deleteNote,SIGNAL(triggered(bool)),this,SLOT(onDeleteNote()));

    NoteAction *action=new NoteAction;
    connect(this,SIGNAL(deleteNoteAction(int,QString)),action,SLOT(deleteNote(int,QString)));
    connect(newNote,SIGNAL(triggered(bool)),action,SLOT(addNote()));
    connect(moveToNotebook,SIGNAL(triggered(bool)),this,SLOT(onEmitMoveNote()));
    connect(copyToNotebook,SIGNAL(triggered(bool)),this,SLOT(onEmitCopyNote()));
    connect(inNote,SIGNAL(triggered(bool)),this,SLOT(onEmitInNote()));
    connect(this,SIGNAL(inNoteAction(QString)),action,SLOT(inNote(QString)));
    connect(this,SIGNAL(moveNoteAction(NoteTip*)),
            action,SLOT(moveToNotebook(NoteTip*)));
    connect(this,SIGNAL(copyNoteAction(NoteTip*)),
            action,SLOT(copyToNotebook(NoteTip*)));

}

void NoteItemView::addShortCuts()
{
    this->newNote->setShortcut(QKeySequence(tr("Alt+N")));

    this->deleteNote->setShortcut(QKeySequence(QKeySequence::Delete));
    this->shareNote->setShortcut(QKeySequence(tr("Alt+S")));
}



void NoteItemView::paintEvent(QPaintEvent *event)
{
    int border=ScreenFit::fitToScreen(4);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    painter.setBrush(QBrush(QColor(AppColorHelper::noteList())));
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
