#include "notebooks.h"

#include <QFileSystemWatcher>
#include <QPushButton>
#include <qpainter.h>

#include <domain/notebook.h>

#include <util/appcolorhelper.h>
#include <util/fileutil.h>
#include <util/qvariantutil.h>
#include <util/screenfit.h>
#include <util/settinghelper.h>

#include <util/json/jsondata.h>

#include <view/notebook/notebookitem.h>
#include <view/notebook/notebookstarter.h>
#include <QDebug>
#include <action/notebookaction.h>
#include <widget/view/gridviewbeauti.h>
#include <graphic/screenhelper.h>
#include <plug/appstatic.h>

Notebooks *Notebooks::books=NULL;

Notebooks::Notebooks(QWidget *parent):
    QFrame(parent)
{
    setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_DeleteOnClose);


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
//    Setting *setting=SettingHelper::setting();
    NoteBook book=qvariant_cast<NoteBook>(value);
//    setting->setCurrentNote(book.fileName());
//    setting->setCurrentBookName(book.name());
//    SettingHelper::saveSetting(setting);
    AppStatic::currentBook=book.fileName();
    emit onBookClicked();
}

void Notebooks::loadData()
{

    QList<QVariant> bl=bookList();
    if(!isFileGrid)
    {
        grid->close();
        recircle->close();
    }
    if(bl.count()==0)
    {
        return;
    }else if(starter!=NULL){
        starter->deleteLater();
        starter=NULL;
        tool->show();
    }

    grid=new GridView(this);
//    grid->setBgImage(QImage(":/image/notebg.jpg"));
    grid->setBgColor(QColor(AppColorHelper::noteList()));
    grid->setBgFun(GridViewBeauti::imageWithPane);
    this->grid->setGeometry(ScreenHelper::getScreenSize().width()/5,
                            tool->height(),this->width()-ScreenHelper::getScreenSize().width()/5
                            ,this->height()-tool->height());
    int margin=ScreenFit::fitToScreen(32);
    grid->setPadding(QMargins(margin,margin,margin,margin));
    grid->setHorizontalSpacing(ScreenFit::fitToScreen(8));
    grid->setVerticalSpacing(ScreenFit::fitToScreen(8));
    grid->setData(bl);
    grid->setItem(new NotebookItem());
    grid->show();
    connect(grid,SIGNAL(selectItemValueDouble(QVariant)),this,SLOT(intoNotebook(QVariant)));
    isFileGrid=false;

    loadView();

    tool->setGeometry(recircle->width(),0,this->width()-recircle->width(),tool->height());

}

void Notebooks::loadStart()
{
    starter=new NotebookStarter(this);
    starter->show();
    this->starter->setGeometry(0,0,this->width(),this->height());
    connect(starter->getStart(),SIGNAL(clicked(bool)),this,SLOT(ceateStart()));
    tool->hide();
}

void Notebooks::loadView()
{
    recircle=new Recircle(this);
    recircle->setWindowFlags(Qt::FramelessWindowHint);
    recircle->setGeometry(0,0,ScreenHelper::getScreenSize().width()/5,
                          this->height());
    recircle->setImg(QImage(":/image/recircle.svg"));
    recircle->refreshList();
    recircle->update();
    recircle->raise();
    recircle->show();
}

void Notebooks::ceateStart()
{
    NotebookAction *action=new NotebookAction;
    action->newBook(this);
    connect(action,SIGNAL(createBookSuccess()),this,SLOT(loadData()));
//   action->deleteLater();
}

void Notebooks::addFileListener()
{
    QFileSystemWatcher *watcher=new QFileSystemWatcher;
    watcher->addPath(SettingHelper::workPath("notebooks.json"));
    watcher->addPath(SettingHelper::workPath("recircles.json"));
    watcher->addPath(SettingHelper::workPath("lastedits.json"));
    connect(watcher,SIGNAL(fileChanged(QString)),this,SLOT(updateDatas()));
}

QList<QVariant> Notebooks::bookList()
{
    data=new JsonData(tr("%1/notebooks.json").arg(SettingHelper::workspacing()).toUtf8(),"notebooks");

    QList<NoteBook*> bookL=data->selectAll<NoteBook>();
    QVariantUtil *util=new QVariantUtil();

    delete data;

    for(NoteBook *book:bookL)
        book->deleteLater();

    return util->turn<NoteBook>(bookL);
}

void Notebooks::updateDatas()
{
    recircle->setFirstShow(true);
    recircle->updateRecircleIndex(AppStatic::recircleIndex);
    grid->addData(bookList());
}

void Notebooks::createView()
{
    setObjectName("notebook");
    data=new JsonData(tr("%1/notebooks.json").arg(SettingHelper::workspacing()).toUtf8(),"notebooks");

    if(data->count()>0)
        loadData();
    else
        loadStart();


    addFileListener();
}

void Notebooks::setTool(QDialog *value)
{
    tool = value;

}

void Notebooks::resizeEvent(QResizeEvent *event)
{
    if(!isFileGrid){
        this->grid->setGeometry(ScreenHelper::getScreenSize().width()/5,tool->height(),
                                this->width()-ScreenHelper::getScreenSize().width()/5,
                                this->height()-tool->height());

        recircle->setGeometry(0,0,ScreenHelper::getScreenSize().width()/5,this->height());

        tool->setGeometry(recircle->width(),0,
                          this->width()-recircle->width(),tool->height());
    }
    else
        this->starter->setGeometry(0,0,this->width(),this->height());
}

void Notebooks::paintEvent(QPaintEvent *event)
{

    if(starter!=NULL)
    {
        QPainter painter(this);
        painter.setBrush(QBrush(QColor(AppColorHelper::menuBg())));
        painter.setPen(Qt::transparent);
        painter.drawRect(0,0,this->width(),this->height());
    }

}



