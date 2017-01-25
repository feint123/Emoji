#include "notebookitemview.h"

#include <util/json/jsondata.h>

#include <util/settinghelper.h>

#include <domain/notetip.h>

#include <QPainter>
#include <QPen>
#include <QDebug>

#include <util/graphic/effectutil.h>

#include <action/notebookaction.h>

#include <view/notebooks.h>

NotebookItemView::NotebookItemView(QWidget *parent) :
    QFrame(parent)

{
    padding=8;
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
    bookName=new QLabel(notebook->name(),this);
    bookName->setStyleSheet("color:#666;");
    noteCount=new QLabel(tr("%1").arg(countNote()),this);
    noteCount->setAlignment(Qt::AlignCenter);
    noteCount->setStyleSheet("color:#999");
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

void NotebookItemView::createActions()
{
    NotebookAction *action=new NotebookAction;
    menu=new QMenu();
    newBook=new QAction("新建笔记本",this);
    deleteBook=new QAction("删除笔记本",this);
    outBook=new QAction("导出笔记本",this);
    inBook=new QAction("导入笔记本",this);
    connect(newBook,SIGNAL(triggered(bool)),this,SLOT(onEmitNewBook()));
    connect(this,SIGNAL(newNoteBook(QWidget*)),action,SLOT(newBook(QWidget*)));
    connect(deleteBook,SIGNAL(triggered(bool)),this,SLOT(onEmitDeleteBook()));
    connect(this,SIGNAL(deleteNoteBook(int)),action,SLOT(deleteBook(int)));
    connect(outBook,SIGNAL(triggered(bool)),this,SLOT(onEmitOutBook()));
    connect(this,SIGNAL(outNoteBook(int,QWidget*)),action,SLOT(outBook(int,QWidget *)));
    connect(inBook,SIGNAL(triggered(bool)),this,SLOT(onEmitInBook()));
    connect(this,SIGNAL(inBookAction(QWidget*)),action,SLOT(inBook(QWidget *)));
}

void NotebookItemView::addShortCuts()
{

}

int NotebookItemView::countNote()
{
    NoteBook notebook=qvariant_cast<NoteBook>(bookQ);
    JsonData *datas=new JsonData(SettingHelper::workPath(notebook.fileName()).toUtf8(),"notes");
    return datas->selectAll<NoteTip>().count();
}

void NotebookItemView::resizeEvent(QResizeEvent *event)
{
    int detaY=pagePadding*((countNote()>maxPage?maxPage:countNote())-1);
    bookName->setGeometry(padding,this->height()/2-bookName->height()/2+detaY/2,
                          bookName->width(),bookName->height());

    noteCount->setGeometry(this->width()-this->height()-padding,
                           this->height()/2-noteCount->height()/2+detaY/2,
                           this->height(),noteCount->height());
}
void NotebookItemView::contextMenuEvent(QContextMenuEvent *event)
{
    menu->clear();
    menu->addAction(newBook);
    menu->addAction(deleteBook);
    menu->addAction(outBook);
    menu->addAction(inBook);
    menu->exec(QCursor::pos());
    event->accept();
}

void NotebookItemView::paintEvent(QPaintEvent *event)
{

    int border=2;
    QPainter painter(this);
  //  painter.setRenderHint(QPainter::Antialiasing);
    QBrush brush;
    brush.setColor(QColor(255, 255, 244,230));
    brush.setStyle(Qt::SolidPattern);
    painter.setPen(QColor(167, 167, 167,100));
    painter.setBrush(brush);
    int count=countNote()>maxPage?maxPage:countNote();
    for(int i=0;i<count;i++)
        painter.drawRect(border+(count-i-1)*pagePadding,border+i*pagePadding,
                         this->width()-2*border-2*(count-i-1)*pagePadding,
                         this->height()-2*border-pagePadding
                         *(count-1));
    QPen pen;
    pen.setColor(QColor("#999"));
    pen.setWidth(0.5);
    pen.setStyle(Qt::DashLine);
    painter.setPen(pen);
    int dx=this->width()-2*padding-noteCount->width();
    painter.drawLine(QPoint(dx,border),
                     QPoint(dx,this->height()-2*border));
}

