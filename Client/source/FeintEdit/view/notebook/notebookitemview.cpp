#include "notebookitemview.h"

#include <util/json/jsondata.h>

#include <util/screenfit.h>
#include <util/settinghelper.h>
#include <util/stringutil.h>

#include <domain/notetip.h>
#include <domain/wordstatic.h>

#include <QPainter>
#include <QPen>
#include <QDebug>

#include <util/graphic/effectutil.h>
#include <util/graphic/imageutil.h>

#include <action/notebookaction.h>

#include <view/notebooks.h>

#include <plug/appstatic.h>

NotebookItemView::NotebookItemView(QWidget *parent) :
    QFrame(parent)

{
    padding=ScreenFit::fitToScreen(16);
    img.load(":/image/book.svg");
  //  EffectUtil::addDropShadow(4,this);
    createActions();

}

NotebookItemView::~NotebookItemView()
{
    delete bookName;
    delete noteCount;
}

NoteBook *NotebookItemView::getNotebook() const
{
    return notebook;
}

void NotebookItemView::setNotebook(NoteBook *value)
{
    notebook = value;
    bookQ=QVariant::fromValue(*value);
}

void NotebookItemView::createView()
{
    bookName=new QLabel(StringUtil::fitToLength(notebook->name(),AppStatic::maxTitleLength),this);
    bookName->setToolTip(notebook->name());
    bookName->setStyleSheet("color:#eee;");
    noteCount=new QLabel(tr("%1").arg(countNote()),this);
    noteCount->setAlignment(Qt::AlignCenter);

    noteCount->setStyleSheet("color:#999;font-size:15pt;");

    ScreenFit::fitFont(noteCount);
    ScreenFit::fitFont(bookName);
}

void NotebookItemView::onEmitNewBook()
{
    emit newNoteBook(Notebooks::getInstance());
}

void NotebookItemView::onEmitDeleteBook()
{
    NoteBook notebook=qvariant_cast<NoteBook>(bookQ);
    emit deleteNoteBook(notebook.id());
}

void NotebookItemView::onEmitOutBook()
{
    NoteBook notebook=qvariant_cast<NoteBook>(bookQ);
    emit outNoteBook(notebook.id(),Notebooks::getInstance());
}

void NotebookItemView::onEmitInBook()
{
    emit inBookAction(Notebooks::getInstance());
}

void NotebookItemView::onEmitUpdateBook()
{
    NoteBook notebook=qvariant_cast<NoteBook>(bookQ);
    emit updateBookAction(Notebooks::getInstance(),notebook.id());
}

void NotebookItemView::createActions()
{
    NotebookAction *action=new NotebookAction;
    menu=new QMenu();
    newBook=new QAction(WordStatic::new_+WordStatic::book,this);
    deleteBook=new QAction(WordStatic::del+WordStatic::book,this);
    outBook=new QAction(WordStatic::out+WordStatic::book,this);
    inBook=new QAction(WordStatic::in+WordStatic::book,this);
    updateBook=new QAction(WordStatic::update+WordStatic::book,this);
    connect(newBook,SIGNAL(triggered(bool)),this,SLOT(onEmitNewBook()));
    connect(this,SIGNAL(newNoteBook(QWidget*)),action,SLOT(newBook(QWidget*)));
    connect(deleteBook,SIGNAL(triggered(bool)),this,SLOT(onEmitDeleteBook()));
    connect(this,SIGNAL(deleteNoteBook(int)),action,SLOT(deleteBook(int)));
    connect(outBook,SIGNAL(triggered(bool)),this,SLOT(onEmitOutBook()));
    connect(this,SIGNAL(outNoteBook(int,QWidget*)),action,SLOT(outBook(int,QWidget *)));
    connect(inBook,SIGNAL(triggered(bool)),this,SLOT(onEmitInBook()));
    connect(this,SIGNAL(inBookAction(QWidget*)),action,SLOT(inBook(QWidget *)));
    connect(updateBook,SIGNAL(triggered(bool)),this,SLOT(onEmitUpdateBook()));
    connect(this,SIGNAL(updateBookAction(QWidget *,int)),action,SLOT(updateBook(QWidget *,int)));
}

void NotebookItemView::addShortCuts()
{

}

int NotebookItemView::countNote()
{
    NoteBook notebook=qvariant_cast<NoteBook>(bookQ);
    JsonData *datas=new JsonData(SettingHelper::workPath(notebook.fileName()).toUtf8(),"notes");
    return datas->count();
}

void NotebookItemView::resizeEvent(QResizeEvent *event)
{
    bookName->setGeometry(padding,this->height()/2-bookName->height()/2,
                          ScreenFit::fitToScreen(220),bookName->height());

    noteCount->setGeometry(this->width()-this->height()-padding/2,
                           this->height()/2-noteCount->height()/2,
                           this->height(),noteCount->height());
}
void NotebookItemView::contextMenuEvent(QContextMenuEvent *event)
{
    menu->clear();
    menu->addAction(newBook);
    menu->addAction(deleteBook);
    menu->addAction(outBook);
    menu->addAction(inBook);
    menu->addAction(updateBook);
    menu->exec(QCursor::pos());
    event->accept();
}

void NotebookItemView::paintEvent(QPaintEvent *event)
{

    QPainter painter(this);
    int border=ScreenFit::fitToScreen(2);

    painter.drawImage(border,border,
                      ImageUtil::fullDevice(img,QSize(this->width()-2*border,this->height()-2*border)));

}

