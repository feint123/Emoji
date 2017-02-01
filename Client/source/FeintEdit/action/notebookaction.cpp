#include "notebookaction.h"

#include <view/notebook/notebookdialog.h>

#include <util/graphic/animationutil.h>

#include <util/json/jsondata.h>

#include <util/noteutil.h>
#include <util/screenfit.h>
#include <util/settinghelper.h>

#include <domain/notebook.h>
#include <domain/recirclepage.h>
#include <domain/wordstatic.h>

#include <QDebug>
#include <QFileDialog>
#include <qstandardpaths.h>

#include <plug/appstatic.h>
#include <plug/filecopydialog.h>

#include <view/notebooks.h>
#include <view/tipdialog.h>

#include <controller/notecontroller.h>

NotebookAction::NotebookAction(QWidget *parent)
{
    action=new NoteAction(parent);
}

void NotebookAction::newBook(QWidget *parent)
{
    NotebookDialog *dialog=NotebookDialog::getInstance(parent);
    ScreenFit::fit(dialog);
    dialog->setTitle(WordStatic::new_+WordStatic::book);
    dialog->setWindowFlags(Qt::FramelessWindowHint);
    connect(dialog,SIGNAL(ready(QString)),this,SLOT(createBook(QString)));
    dialog->setGeometry(parent->width()/2-dialog->width()/2,
                        -dialog->height(),dialog->width(),dialog->height());
    dialog->show();
    dialog->raise();
    AnimationUtil::GeometryAnim(dialog->geometry(),
                                QRect(parent->width()/2-dialog->width()/2,
                                      0,dialog->width(),dialog->height()),dialog);

}

void NotebookAction::deleteBook(int nid)
{

    JsonData *datas=new JsonData(SettingHelper::workPath("notebooks.json").toUtf8(),"notebooks");
    NoteBook *book=datas->selectById<NoteBook>(nid);
    datas->deleteData(nid);
    QList<NoteBook*> books;
    if((books=datas->selectAll<NoteBook>()).count()>0)
    {
//        Setting *setting=SettingHelper::loadSetting();
//        setting->setCurrentNote(books.at(0)->fileName());
//        setting->setCurrentBookName(books.at(0)->name());
//        SettingHelper::saveSetting(setting);
        AppStatic::currentBook=books.at(0)->fileName();
    }
    delete datas;

    datas=new JsonData(SettingHelper::workPath("recircles.json").toUtf8(),"recircles");
    RecirclePage *page=new RecirclePage;
    page->setBookFile(book->fileName());
    page->setName(book->name());
    page->setFileName(book->fileName());
    page->setType(RecirclePage::BOOK);
    datas->addOnlyByColumn<RecirclePage>("fileName",book->fileName(),page);

    delete datas;
}

void NotebookAction::outBook(int nid,QWidget *parent)
{
    action->setParent(parent);
    QStringList needFiles;
    JsonData *datas=new JsonData(SettingHelper::workPath("notebooks.json").toUtf8(),"notebooks");
    NoteBook *book=datas->selectById<NoteBook>(nid);
    datas=new JsonData(SettingHelper::workPath(book->fileName()).toUtf8(),"notes");
    needFiles.append(getNoteFileList(datas->selectAll<NoteTip>()));
    QString toFile=QFileDialog::getExistingDirectory(0,WordStatic::out+WordStatic::book,
                                                     QStandardPaths::standardLocations(QStandardPaths::DocumentsLocation).at(0));
    QDir dir(toFile);
    QString dirN=book->name()+QDateTime::currentDateTime().toString("_yyyy_MM_dd_HH");
    dir.mkdir(dirN);
    QFile::copy(SettingHelper::workPath(book->fileName()),
                toFile+"/"+dirN+"/"+book->fileName());


    for(QString file:needFiles)
        action->outNote(file,toFile+"/"+dirN+"/"+file+".feint");


}

void NotebookAction::inBook(QWidget *parent)
{
    action->setParent(parent);
    QString bookFile=QFileDialog::getExistingDirectory(0,WordStatic::in+WordStatic::book,
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
    notebook->setName(WordStatic::in+WordStatic::book);
    notebook->setUpdateDate(QDateTime::currentDateTime());
    JsonData *datas=new JsonData(SettingHelper::workPath("notebooks.json").toUtf8(),"notebooks");
    if(NULL!=datas->selectByColumn<NoteBook>("fileName",bookName)){
        action->createTip(WordStatic::tip_5,"");
        return;
    }
    else{
        if(bookName.length()>0)
        {
            inBook(bookFile,bookName);

            datas->addData<NoteBook>(notebook);
        }else
            action->createTip(WordStatic::tip_6,"");
    }

}

void NotebookAction::updateBook(QWidget *parent,int id)
{
    cid= id;

    NotebookDialog *dialog=NotebookDialog::getInstance(parent);
    dialog->setTitle(WordStatic::update+WordStatic::book);
    dialog->setWindowFlags(Qt::FramelessWindowHint);
    connect(dialog,SIGNAL(ready(QString)),this,SLOT(readyUpdateBook(QString)));
    dialog->setGeometry(parent->width()/2-dialog->width()/2,
                        -dialog->height(),dialog->width(),dialog->height());
    dialog->show();
    dialog->raise();
    AnimationUtil::GeometryAnim(dialog->geometry(),
                                QRect(parent->width()/2-dialog->width()/2,
                                      0,dialog->width(),dialog->height()),dialog);
}

void NotebookAction::createBook(QString name)
{
    NoteBook *noteBook=new NoteBook;

    noteBook->setFileName(tr("%1.json").arg(FileUtil::onlyName("notebook")));
    noteBook->setName(name);
    noteBook->setCreateDate(QDateTime::currentDateTime());
    JsonData *data=new JsonData(SettingHelper::workPath("notebooks.json").toUtf8(),"notebooks");
    data->addData<NoteBook>(noteBook);
    NoteController *controller=new NoteController();
//    Setting *setting=SettingHelper::setting();
//    setting->setCurrentNoteBook(noteBook->fileName());
//    setting->setCurrentBookName(noteBook->name());
//    SettingHelper::saveSetting(setting);
    AppStatic::currentBook=noteBook->fileName();
    //向新建笔记本中添加默认笔记
    controller->addNote();

    emit createBookSuccess();
}

void NotebookAction::readyUpdateBook(QString name)
{
    JsonData *datas=new JsonData(SettingHelper::workPath("notebooks.json").toUtf8(),"notebooks");
    NoteBook *book=datas->selectById<NoteBook>(cid);
    book->setName(name);
    datas->update<NoteBook>(book,cid);

    delete datas;
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

    QFile::copy(dir+"/"+book,SettingHelper::workPath(book));

}
