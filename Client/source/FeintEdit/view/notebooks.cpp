#include "notebooks.h"

#include <QFileSystemWatcher>
#include <QPushButton>

#include <domain/notebook.h>

#include <util/fileutil.h>
#include <util/qvariantutil.h>
#include <util/settinghelper.h>

#include <util/json/jsondata.h>

#include <view/notebook/notebookitem.h>
#include <view/notebook/notebookstarter.h>
#include <QDebug>
#include <action/notebookaction.h>
#include <widget/view/gridviewbeauti.h>

Notebooks *Notebooks::books=NULL;

Notebooks::Notebooks(QWidget *parent):
    QFrame(parent)
{
    setWindowFlags(Qt::FramelessWindowHint);
    setObjectName("notebook");
    data=new JsonData(tr("%1/notebooks.json").arg(SettingHelper::workspacing()).toUtf8(),"notebooks");
    if(data->selectAll<NoteBook>().count()>0)
        loadData();
    else
        loadStart();
    addFileListener();

}



Notebooks::~Notebooks()
{
    books=NULL;
}

Notebooks *Notebooks::getInstance(QWidget *parent)
{
    if(books==NULL)
        books=new Notebooks(parent);
    return books;
}

void Notebooks::intoNotebook(QVariant value)
{
    Setting *setting=SettingHelper::setting();
    NoteBook book=qvariant_cast<NoteBook>(value);
    setting->setCurrentNote(book.fileName());
    setting->setCurrentBookName(book.name());
    SettingHelper::saveSetting(setting);
    emit onBookClicked();
}

void Notebooks::loadData()
{
    QList<NoteBook*> bookList=data->selectAll<NoteBook>();

    QVariantUtil *util=new QVariantUtil();
    if(!isFileGrid)
    { grid->close();}
    grid=new GridView(this);
    grid->setBgImage(QImage(":/image/notebg.jpg"));
    grid->setBgFun(GridViewBeauti::imageWithPane);
    this->grid->setGeometry(0,0,this->width(),this->height());
    grid->setPadding(QMargins(32,32,32,32));
    grid->setHorizontalSpacing(8);
    grid->setVerticalSpacing(8);
    grid->setData(util->turn<NoteBook>(bookList));
    grid->setItem(new NotebookItem());
    grid->show();
    connect(grid,SIGNAL(selectItemValueDouble(QVariant)),this,SLOT(intoNotebook(QVariant)));
    isFileGrid=false;
}

void Notebooks::loadStart()
{
    starter=new NotebookStarter(this);
    starter->show();
    connect(starter->getStart(),SIGNAL(clicked(bool)),this,SLOT(ceateStart()));
}

void Notebooks::ceateStart()
{
    NotebookAction *action=new NotebookAction;
    action->newBook(this);
}

void Notebooks::addFileListener()
{
    QFileSystemWatcher *watcher=new QFileSystemWatcher;
    watcher->addPath(SettingHelper::workPath("notebooks.json"));
    connect(watcher,SIGNAL(fileChanged(QString)),this,SLOT(loadData()));
}

void Notebooks::resizeEvent(QResizeEvent *event)
{
    if(!isFileGrid)
        this->grid->setGeometry(0,0,this->width(),this->height());
    else
        this->starter->setGeometry(0,0,this->width(),this->height());
}
