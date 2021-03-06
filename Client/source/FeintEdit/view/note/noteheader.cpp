#include "noteheader.h"

#include <QBoxLayout>
#include <qpainter.h>

#include <view/notebook/list/notebooknamedialog.h>

#include <util/graphic/effectutil.h>

#include <util/appcolorhelper.h>
#include <util/dialogshowutil.h>
#include <util/noteutil.h>
#include <util/screenfit.h>
#include <util/settinghelper.h>
#include <util/stringutil.h>
#include <QDebug>
#include <domain/setting.h>
#include <domain/wordstatic.h>
#include <plug/appstatic.h>
#include <factory/booknamefactory.h>

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
    notebookBtn=new QPushButton();
    notebookBtn->setText(StringUtil::fitToLength(currentNotebook(),AppStatic::maxTitleLength));
    notebookBtn->setToolTip(currentNotebook());
    notebookBtn->setMinimumWidth(100);
    notebookBtn->setStyleSheet(tr("QPushButton{border:1px solid #f9f9f9;"
                                  "border-radius:5px;color:white;padding:2px 8px;}"
                                     "QPushButton:pressed{background:%1;border:none;}").arg(AppColorHelper::menuBg()));
    allNotesBtn =new FButton();
    allNotesBtn->setText(WordStatic::all+WordStatic::note);
    allNotesBtn->setObjectName("all");

    allNotesBtn->setMaxShadow(10);
    allNotesBtn->setBorderRadius(ScreenFit::fitToScreen(5));
    allNotesBtn->setStyleSheet(allNotesBtn->styleSheet()+"#all{padding:4px 8px;}");
    QHBoxLayout *vb=new QHBoxLayout;
    notebookBtn->setFixedHeight(ScreenFit::fitToScreen(AppStatic::standardBtnHeight));
    allNotesBtn->setFixedHeight(ScreenFit::fitToScreen(AppStatic::standardBtnHeight));
    ScreenFit::fitWithFont(notebookBtn);
    ScreenFit::fitWithFont(allNotesBtn);

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
    notebookBtn->setText(StringUtil::fitToLength(book,AppStatic::maxTitleLength));
    notebookBtn->setToolTip(book);
}

void NoteHeader::showAllBooks()
{
    QWidget *p=(QWidget*)this->parent();
    dialog=BookNameFactory::create(WordStatic::book);
    dialog->raise();
    if(dialog->isVisible())
        dialog->deleteLater();
    else
        DialogShowUtil::showPopUp(QCursor::pos(),dialog,ScreenFit::fitToScreen(8));
    connect(dialog,SIGNAL(bookClicked(NoteBook*)),this,SLOT(loadBooks(NoteBook*)));
}

void NoteHeader::loadAllNotes()
{
//    Setting *setting=SettingHelper::loadSetting();
//    setting->setCurrentNote("&_&");
//    setting->setCurrentBookName("全部笔记");
//    SettingHelper::saveSetting(setting);
    AppStatic::currentBook="&_&";

    emit selectOtherNoteBook();
}

void NoteHeader::loadBooks(NoteBook *book)
{
    if(book->fileName()!=AppStatic::currentBook)
    {
        AppStatic::currentBook=book->fileName();
        emit selectOtherNoteBook();
    }
    dialog->deleteLater();
}

void NoteHeader::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setBrush(QBrush(QColor(140,140,140,200)));
    painter.setPen(QColor(0,0,0,0));
    painter.drawRect(0,0,this->width(),this->height());
}
