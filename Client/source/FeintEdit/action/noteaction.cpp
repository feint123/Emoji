#include "noteaction.h"

#include <util/json/jsondata.h>

#include <util/dialogshowutil.h>
#include <util/noteutil.h>
#include <util/settinghelper.h>

#include <QDebug>
#include <QDesktopServices>
#include <QFileDialog>
#include <QFileSystemWatcher>
#include <QTimer>

#include <domain/notebook.h>

#include <controller/notecontroller.h>

#include <view/notebook/list/notebooknamedialog.h>

#include <util/graphic/effectutil.h>

#include <view/tipdialog.h>

NoteAction::NoteAction(QWidget *parent)
{
    this->parent=parent;
}

void NoteAction::deleteNote(int id, QString notebook)
{
    JsonData *datas=new JsonData(SettingHelper::workPath(notebook).toUtf8(),"notes");
    if(datas->selectAll<NoteBook>().count()>1)
        datas->deleteData(id);

}

void NoteAction::addNote()
{
    NoteController *controller=new NoteController;
    controller->addNote();
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
    dir=QFileDialog::getSaveFileName(0,"导出笔记至...",
                                          QStandardPaths::standardLocations(QStandardPaths::DocumentsLocation).at(0),
                                     tr("FeintEdit笔记文件(*.feint)"));
    outNote(noteName,dir);
}

void NoteAction::inNote(QString notebook)
{
    JsonData *datas=new JsonData(SettingHelper::workPath(notebook).toUtf8(),"notes");
    QString fileName=QFileDialog::getOpenFileName(0,"导入笔记",
                                                  QStandardPaths::standardLocations(QStandardPaths::DocumentsLocation).at(0),
                                                  tr("feintEdit笔记文件(*.feint)"));

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
}

void NoteAction::outImages(QString noteName)
{
    JsonData *datas=new JsonData(SettingHelper::workPath(noteName+"_img.json").toUtf8(),"images");
    QList<Image*> images=datas->selectAll<Image>();
    QStringList imagePaths;
    for(Image *img:images)
        imagePaths.append(img->file()+".png");
    QString dir=QFileDialog::getExistingDirectory(0,"导出图片至...",
                                                  QStandardPaths::standardLocations(QStandardPaths::PicturesLocation).at(0));
    for(QString path:imagePaths)
    {
        FileUtil *fileutil=new FileUtil;
        connect(fileutil,SIGNAL(fileCopySuccess(QString)),this,SLOT(onOutImagesSuccess(QString)));
        fileutil->copyFile(SettingHelper::workPath(path),dir+"/"+path);

    }
}

void NoteAction::moveNote(NoteBook *noteBook)
{
    deleteNote(tip.id(),tip.notebook());
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
}

void NoteAction::onOutDirChanged(QString file)
{
    qDebug()<<"NoteAction:"<<file;
}

void NoteAction::onOutSuccess(QString path)
{
    createTip("成功导入笔记至目录：",path);

}

void NoteAction::onOutImagesSuccess(QString path)
{
    createTip("成功导入图片至目录：",path);
}

void NoteAction::moveNoteTo(NoteTip *tip, QWidget *parent)
{
    this->tip=*tip;
    dialog=NotebookNameDialog::getInstance(parent);
    EffectUtil::addDropShadow(25,dialog);
    dialog->setWindowFlags(Qt::FramelessWindowHint);
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
        image.save(SettingHelper::workPath(itera.key()));
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
    for(Image *img:images)
        needFile.append(img->file()+".png");

    QString name=noteName+".feint";
    QString path=NoteUtil::createNoteFile(SettingHelper::workPath(name),noteName,
                             noteName+"_img.json",needFile,SettingHelper::workspacing());
    if(path!=NULL)
    {

        FileUtil *fileutil=new FileUtil;
        connect(fileutil,SIGNAL(fileCopySuccess(QString)),this,SLOT(onOutSuccess(QString)));
        fileutil->copyFile(SettingHelper::workPath(name),dir);
    }
}
