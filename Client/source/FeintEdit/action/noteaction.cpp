#include "noteaction.h"

#include <util/json/jsondata.h>

#include <util/appcolorhelper.h>
#include <util/dialogshowutil.h>
#include <util/noteutil.h>
#include <util/settinghelper.h>
#include <util/timermanager.h>

#include <QDebug>
#include <QDesktopServices>
#include <QFileDialog>
#include <QFileSystemWatcher>
#include <QTimer>

#include <domain/notebook.h>
#include <domain/recirclepage.h>
#include <domain/timertag.h>
#include <domain/wordstatic.h>

#include <controller/notecontroller.h>

#include <view/notebook/list/notebooknamedialog.h>

#include <util/graphic/effectutil.h>
#include <util/graphic/imageutil.h>

#include <view/tipdialog.h>

#include <plug/appstatic.h>

NoteAction::NoteAction(QWidget *parent)
{
    this->parent=parent;
}

void NoteAction::deleteNote(int id, QString notebook)
{
    JsonData *datas=new JsonData(SettingHelper::workPath(notebook).toUtf8(),"notes");
    NoteTip *tip=NULL;
    if(AppStatic::noteNum>1)
    {
        tip=datas->selectById<NoteTip>(id);
        datas->deleteData(id);

        AppStatic::noteNum-=1;
    }
    delete datas;

    datas=new JsonData(SettingHelper::workPath("recircles.json").toUtf8(),"recircles");
    if(tip!=NULL)
    {
        RecirclePage *page=new RecirclePage;
        page->setFileName(tip->fileName());
        page->setName(tip->title());
        page->setType(RecirclePage::NOTE);
        page->setBookFile(tip->notebook());
        datas->addOnlyByColumn<RecirclePage>("fileName",page->fileName(),page);
    }
    TimerManager::getInstance()->getTimer(TimerTag::tag(TimerTag::NOTE_NUM_CHANGE))->start();
}

void NoteAction::addNote()
{
    NoteController *controller=new NoteController();
    controller->addNote();

    TimerManager::getInstance()->getTimer(TimerTag::tag(TimerTag::NOTE_NUM_CHANGE))->start();
}

void NoteAction::moveToNotebook(NoteTip *tip, QWidget *parent)
{
    moveNoteTo(tip,parent);
    connect(dialog,SIGNAL(bookClicked(NoteBook*)),this,SLOT(moveNote(NoteBook*)));
}

void NoteAction::copyToNotebook(NoteTip *tip, QWidget *parent)
{
    moveNoteTo(tip,parent);
    connect(dialog,SIGNAL(bookClicked(NoteBook*)),this,SLOT(copyNote(NoteBook*)));
}

void NoteAction::outNote(QString noteName)
{
    dir=QFileDialog::getSaveFileName(0,WordStatic::out+WordStatic::note,
                                          QStandardPaths::standardLocations(QStandardPaths::DocumentsLocation).at(0),
                                     tr("FeintEdit"+WordStatic::note+WordStatic::file+"(*.feint)"));
    outNote(noteName,dir);
}

void NoteAction::inNote(QString notebook)
{
    JsonData *datas=new JsonData(SettingHelper::workPath(notebook).toUtf8(),"notes");
    QString fileName=QFileDialog::getOpenFileName(0,WordStatic::in+WordStatic::note,
                                                  QStandardPaths::standardLocations(QStandardPaths::DocumentsLocation).at(0),
                                                  tr("feintEdit"+WordStatic::note+WordStatic::file+"(*.feint)"));

    if(fileName.length()<=0)
        return;
    NoteIn *in=NoteUtil::readNoteFile(fileName);

    copyFile(in);

    MarkdownManager *manager=new MarkdownManager();
    manager->load(SettingHelper::workPath(in->getNoteName()+".fei"));
    MarkContent *content=manager->loadContent();

    NoteTip *tip=new NoteTip;
    tip->setTitle(content->title());
    tip->setTip(content->content());
    tip->setFileName(in->getNoteName());
    tip->setUpdateDate(QDateTime::currentDateTime());
    tip->setNotebook(notebook);

    datas->addData<NoteTip>(tip);

    AppStatic::noteNum+=1;

    tip->deleteLater();
    content->deleteLater();
    manager->deleteLater();
    delete in;
    delete datas;

    QTimer *timer=TimerManager::getInstance()->getTimer(TimerTag::tag(TimerTag::NOTE_NUM_CHANGE));
    if(timer!=NULL)
        timer->start();
}

void NoteAction::outImages(QString noteName)
{
    JsonData *datas=new JsonData(SettingHelper::workPath(noteName+"_img.json").toUtf8(),"images");
    QList<Image*> images=datas->selectAll<Image>();
    QStringList imagePaths;
    for(Image *img:images){
        imagePaths.append(img->file());
        img->deleteLater();
    }
    QString dir=QFileDialog::getExistingDirectory(0,WordStatic::out+WordStatic::photo,
                                                  QStandardPaths::standardLocations(QStandardPaths::PicturesLocation).at(0));
    for(QString path:imagePaths)
    {
        FileUtil *fileutil=new FileUtil;
        connect(fileutil,SIGNAL(fileCopySuccess(QString)),this,SLOT(onOutImagesSuccess(QString)));
        fileutil->copyFile(FileUtil::imageTempPath(SettingHelper::workspacing(),path)+".png",dir+"/"+path+".png");

        fileutil->deleteLater();
    }

    delete datas;

}

void NoteAction::moveNote(NoteBook *noteBook)
{
    deleteNote(tip.id(),tip.notebook());
    AppStatic::noteNum-=1;
    copyNote(noteBook);
}

void NoteAction::copyNote(NoteBook *noteBook)
{

    dialog->close();
    dialog->deleteLater();
    tip.setNotebook(noteBook->fileName());
    JsonData* datas=new JsonData(SettingHelper::workPath(noteBook->fileName()).toUtf8(),"notes");
    tip.setUpdateDate(QDateTime::currentDateTime());
    datas->addData<NoteTip>(&tip);

    delete datas;
}

void NoteAction::onOutDirChanged(QString file)
{

}

void NoteAction::onOutSuccess(QString path)
{
    createTip(WordStatic::tip_3,path);

}

void NoteAction::onOutImagesSuccess(QString path)
{
    createTip(WordStatic::tip_4,path);
}

void NoteAction::moveNoteTo(NoteTip *tip, QWidget *parent)
{
    this->tip=*tip;
    dialog=NotebookNameDialog::getInstance(parent);
    EffectUtil::addDropShadow(25,AppColorHelper::noteListShadow(),dialog);
    dialog->setMaximumHeight(500);
    dialog->setTop(8);
    dialog->setBottom(8);
    dialog->createList();
    dialog->resize(400,dialog->getHeight());
    dialog->raise();
    DialogShowUtil::show(parent,dialog);

}

void NoteAction::copyFile(NoteIn *in)
{
    QFile file(SettingHelper::workPath(in->getNoteName()+".fei"));
    file.open(QFile::WriteOnly|QFile::Text);
    file.write(in->getNote().toUtf8());
    file.flush();
    file.close();
    file.setFileName(SettingHelper::workPath(in->getImageRName()));
    file.open(QFile::WriteOnly|QFile::Text);
    file.write(in->getImageR().toUtf8());
    file.flush();
    file.close();

    QHashIterator<QString,QImage> itera(in->getImages());
    while(itera.hasNext()){
        QImage image=itera.next().value();
        ImageUtil::saveImage(SettingHelper::workspacing(),itera.key(),image);
    }

}

void NoteAction::createTip(QString desc, QString path)
{
    TipDialog *tip=TipDialog::getInstance(parent);
    tip->setFontSize(SettingHelper::fontSize()+5);
    tip->setTip(desc+path);
    tip->setKeep(3500);
    tip->resize(tip->width(),60);
    tip->raise();
    tip->showTip();
}

void NoteAction::setParent(QWidget *value)
{
    parent = value;
}

void NoteAction::outNote(QString noteName, QString dir)
{
    QStringList needFile;

    JsonData *datas=new JsonData(SettingHelper::workPath(noteName+"_img.json").toUtf8(),"images");
    QList<Image*> images=datas->selectAll<Image>();
    for(Image *img:images){
        needFile.append(img->file());
        img->deleteLater();
    }
    QString name=noteName+".feint";
    QString path=NoteUtil::createNoteFile(SettingHelper::workPath(name),noteName,
                             noteName+"_img.json",needFile,SettingHelper::workspacing());
    if(path!=NULL)
    {

        FileUtil *fileutil=new FileUtil;
        connect(fileutil,SIGNAL(fileCopySuccess(QString)),this,SLOT(onOutSuccess(QString)));
        fileutil->copyFile(SettingHelper::workPath(name),dir);
        fileutil->deleteLater();
    }

    delete datas;
}
