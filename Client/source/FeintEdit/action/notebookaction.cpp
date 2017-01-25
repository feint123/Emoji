#include "notebookaction.h"

#include <view/notebook/notebookdialog.h>

#include <util/graphic/animationutil.h>

#include <util/json/jsondata.h>

#include <util/noteutil.h>
#include <util/settinghelper.h>

#include <domain/notebook.h>

#include <QDebug>
#include <QFileDialog>
#include <qstandardpaths.h>

#include <plug/filecopydialog.h>

#include <view/notebooks.h>
#include <view/tipdialog.h>

NotebookAction::NotebookAction(QWidget *parent)
{
    action=new NoteAction(parent);
}

void NotebookAction::newBook(QWidget *parent)
{
    NotebookDialog *dialog=new NotebookDialog(parent);
    dialog->setWindowFlags(Qt::FramelessWindowHint);
    dialog->setGeometry(parent->width()/2-dialog->width()/2,
                        -dialog->height(),dialog->width(),dialog->height());
    dialog->show();
    AnimationUtil::GeometryAnim(dialog->geometry(),
                                QRect(parent->width()/2-dialog->width()/2,
                                      0,dialog->width(),dialog->height()),dialog);

}

void NotebookAction::deleteBook(int nid)
{

    JsonData *datas=new JsonData(SettingHelper::workPath("notebooks.json").toUtf8(),"notebooks");
    datas->deleteData(nid);
    QList<NoteBook*> books;
    if((books=datas->selectAll<NoteBook>()).count()>0)
    {
        Setting *setting=SettingHelper::loadSetting();
        setting->setCurrentNote(books.at(0)->fileName());
        setting->setCurrentBookName(books.at(0)->name());
        SettingHelper::saveSetting(setting);
    }

}

void NotebookAction::outBook(int nid,QWidget *parent)
{
    action->setParent(parent);
    QStringList needFiles;
    JsonData *datas=new JsonData(SettingHelper::workPath("notebooks.json").toUtf8(),"notebooks");
    NoteBook *book=datas->selectById<NoteBook>(nid);
    datas=new JsonData(SettingHelper::workPath(book->fileName()).toUtf8(),"notes");
    needFiles.append(getNoteFileList(datas->selectAll<NoteTip>()));
    QString toFile=QFileDialog::getExistingDirectory(0,"导出目录",
                                                     QStandardPaths::standardLocations(QStandardPaths::DocumentsLocation).at(0));
    QDir dir(toFile);
    dir.mkdir(book->name());
    QFile::copy(SettingHelper::workPath(book->fileName()),
                toFile+"/"+book->name()+"/"+book->fileName());


    for(QString file:needFiles)
        action->outNote(file,toFile+"/"+file+".feint");


}

void NotebookAction::inBook(QWidget *parent)
{
    action->setParent(parent);
    QString bookFile=QFileDialog::getExistingDirectory(0,"导入笔记本",
                                                  QStandardPaths::standardLocations(QStandardPaths::DocumentsLocation).at(0));
    QDir dir(bookFile);
    dir.setFilter(QDir::Files|QDir::NoDotAndDotDot);
    QFileInfoList infos=dir.entryInfoList();
    QString bookName="";
    for(QFileInfo info:infos)
    {
        if(info.fileName().contains("_notebook.json")){
            bookName=info.fileName();
            break;
        }
    }


    NoteBook *notebook=new NoteBook;

    notebook->setCreateDate(QDateTime::currentDateTime());
    notebook->setFileName(bookName);
    notebook->setName("导入笔记");
    notebook->setUpdateDate(QDateTime::currentDateTime());
    JsonData *datas=new JsonData(SettingHelper::workPath("notebooks.json").toUtf8(),"notebooks");
    if(NULL!=datas->selectByColumn<NoteBook>("fileName",bookName)){
        action->createTip("笔记本已存在，尝试导入笔记","");
        return;
    }
    else{
        if(bookName.length()>0)
        {
            inBook(bookFile,bookName);
            datas->addData<NoteBook>(notebook);
        }else
            action->createTip("该目录下不存在笔记本","");
    }

}

QStringList NotebookAction::getNoteFileList(QList<NoteTip *> tips)
{
    QStringList fileList;
    for(NoteTip* tip:tips)
    {
        fileList.append(tip->fileName());
    }
    return fileList;
}

void NotebookAction::inBook(QString dir, QString book)
{
    JsonData *datas=new JsonData((dir+"/"+book).toUtf8(),"notes");
    QList<NoteTip*> tips=datas->selectAll<NoteTip>();
    for(NoteTip *tip:tips)
    {
        QFile file(dir+"/"+tip->fileName()+".feint");
        if(file.exists())
        {
            NoteIn *in=NoteUtil::readNoteFile(file.fileName());
            action->copyFile(in);
        }else
        {
            datas->deleteData(tip->id());
        }
    }

}
