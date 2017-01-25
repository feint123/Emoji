#include "noteheader.h"

#include <QBoxLayout>
#include <qpainter.h>

#include <view/notebook/list/notebooknamedialog.h>

#include <util/graphic/effectutil.h>

#include <util/dialogshowutil.h>
#include <util/noteutil.h>
#include <util/settinghelper.h>
#include <QDebug>
#include <domain/setting.h>

NoteHeader::NoteHeader(QWidget *parent):
    QFrame(parent)
{
    setWindowFlags(Qt::FramelessWindowHint);
    setAutoFillBackground(false);
}

QString NoteHeader::currentNotebook() const
{
    return m_currentNotebook;
}

void NoteHeader::createView()
{
    notebookBtn=new FButton(this);
    notebookBtn->setText(currentNotebook());
    notebookBtn->setMaxShadow(15);
    notebookBtn->setStyleSheet("border:1px solid #f9f9f9;color:#f9f9f9;"
                               "padding:3px 8px;background:transparent;"
                               "border-radius:5px;");
    allNotesBtn =new FButton(this);
    allNotesBtn->setText("全部笔记");
    allNotesBtn->setObjectName("all");

    allNotesBtn->setMaxShadow(10);
    allNotesBtn->setBorderRadius(5);
    allNotesBtn->setStyleSheet(allNotesBtn->styleSheet()+"#all{padding:4px 8px;}");
    QHBoxLayout *vb=new QHBoxLayout;
    vb->addWidget(allNotesBtn);
    vb->addWidget(notebookBtn);
    vb->addStretch();
    this->setLayout(vb);
    connect(this,SIGNAL(currentNotebookChanged(QString)),this,SLOT(setNotebookText(QString)));
    connect(notebookBtn,SIGNAL(clicked(bool)),this,SLOT(showAllBooks()));
    connect(allNotesBtn,SIGNAL(clicked(bool)),this,SLOT(loadAllNotes()));
}

void NoteHeader::setCurrentNotebook(QString currentNotebook)
{
    if (m_currentNotebook == currentNotebook)
        return;

    m_currentNotebook = currentNotebook;
    emit currentNotebookChanged(currentNotebook);
}

void NoteHeader::setNotebookText(QString book)
{
    notebookBtn->setText(book);
}

void NoteHeader::showAllBooks()
{

    QWidget *p=(QWidget *)this->parent();
    dialog=NotebookNameDialog::getInstance((QWidget*)this->parent());

    EffectUtil::addDropShadow(25,dialog);
    dialog->setWindowFlags(Qt::FramelessWindowHint);
    dialog->setMaximumHeight(500);
    dialog->setTop(8);
    dialog->setBottom(8);
    dialog->createList();
    dialog->resize(p->width(),dialog->getHeight());
    dialog->raise();
    if(dialog->isVisible())
        dialog->deleteLater();
    else
        DialogShowUtil::show((QWidget*)this->parent(),dialog,this->height()+8);
    connect(dialog,SIGNAL(bookClicked(NoteBook*)),this,SLOT(loadBooks(NoteBook*)));
}

void NoteHeader::loadAllNotes()
{

}

void NoteHeader::loadBooks(NoteBook *book)
{

    Setting *setting=SettingHelper::loadSetting();
    setting->setCurrentNote(book->fileName());
    setting->setCurrentBookName(book->name());
    SettingHelper::saveSetting(setting);
    dialog->deleteLater();
}

void NoteHeader::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setBrush(QBrush(QColor(240,240,240,120)));
    painter.setPen(QColor(0,0,0,0));
    painter.drawRect(0,0,this->width(),this->height());
}
