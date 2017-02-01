#include "notecontroller.h"
#include "noteeditcontroller.h"
#include <factory/notecontrolfactory.h>
#include <pane/markdown/markdownmanager.h>
#include <util/notedatautil.h>
#include <util/qvariantutil.h>
#include <util/settinghelper.h>
#include <util/timermanager.h>
#include <domain/notebook.h>
#include <domain/timertag.h>
#include <util/json/jsondata.h>
#include <view/note/noteitem.h>
#include <QDebug>
#include <QFileSystemWatcher>
#include <QTimer>
#include <plug/appstatic.h>

NoteController::NoteController(Notes *note)
{
    connect(this,SIGNAL(currentNoteChanged(QString)),this,SLOT(readyLoadNote()));
    this->setParent(note);
    this->notes=note;
    connect(note,SIGNAL(destroyed(QObject*)),this,SLOT(deleteLater()));
    connect(note->getList()->getNoteH(),SIGNAL(selectOtherNoteBook()),this,SLOT(refersh()));

    refreshNoteList();
    connect(this,SIGNAL(noteNumChanged(int)),this,SLOT(refreshNoteList()));

    startListenNoteNumChange();
}

NoteController::NoteController()
{

}

NoteController::~NoteController()
{

}

QString NoteController::currentNote() const
{
    return m_currentNote;
}

int NoteController::noteNum() const
{
    return m_noteNum;
}

void NoteController::setCurrentNote(QString currentNote)
{
    if (m_currentNote == currentNote)
        return;
    if(refreshLock)
        saveNoteBeforeChange();
//    refreshLock=true;

    m_currentNote = currentNote;
    AppStatic::currentNote=currentNote;
    emit currentNoteChanged(currentNote);
}

void NoteController::setNoteNum(int noteNum)
{
    if (m_noteNum == noteNum)
        return;

    m_noteNum = noteNum;
    emit noteNumChanged(noteNum);
}

void NoteController::onNoteSelect(QVariant note)
{
    NoteTip tip=qvariant_cast<NoteTip>(note);
    setCurrentNote(tip.fileName());
}

/**
 * @brief NoteController::refreshNoteList
 * 更新笔记列表。
 */
void NoteController::refreshNoteList()
{

    //在笔记列表设置当前的笔记本名称
    notes->getList()->getNoteH()->setCurrentNotebook(currentBookName());
    //从当前笔记本获取笔记列表

    QList<QVariant> qDatas=NoteDataUtil::getNotesByBookFile(getNoteBookFile());

    notes->getList()->loadDate(qDatas);

    connect(notes->getList()->getListView(),SIGNAL(selectItem(QVariant)),this,SLOT(onNoteSelect(QVariant)));
    connect(notes->getList()->getListView(),SIGNAL(scrollYChanged(int)),this,SLOT(onScrollLNoteList(int)));

    updateFocusIndex();

    this->notes->getList()->getListView()->setFocusIndex(AppStatic::focusIndex);
    AppStatic::focusIndex=this->notes->getList()->getListView()->focusIndex();

    AppStatic::noteNum=qDatas.count();

    this->notes->getList()->getListView()->setScrollY(AppStatic::noteScroll);

    createView(AppStatic::focusIndex);

    refreshLock=true;
}

void NoteController::loadNote()
{
    if(loadtimer!=NULL){
        loadtimer->stop();
        loadtimer->deleteLater();
        loadtimer=NULL;
    }
    notes->createMark(currentNote());
    chooseMark(currentNote()+".fei");
    initEditController();
}

void NoteController::readyLoadNote()
{

    loadtimer=new QTimer(this);
    loadtimer->setInterval(50);
    connect(loadtimer,SIGNAL(timeout()),this,SLOT(loadNote()));
    loadtimer->start();
}

void NoteController::onScrollLNoteList(int value)
{
    AppStatic::noteScroll=value;
}

void NoteController::checkNoteNum()
{ 
    refreshLock=false;
    emit noteNumChanged(0);  
    TimerManager::getInstance()->getTimer("num_change")->stop();
}

void NoteController::refersh()
{
    refreshLock=false;
    refreshNoteList();
}

void NoteController:: createView(int i)
{

    QList<QVariant> noteTips=NoteDataUtil::getNotesByBookFile(getNoteBookFile());
    NoteTip tip=qvariant_cast<NoteTip>(noteTips.at(i));

    setCurrentNote(tip.fileName());
}

void NoteController::startListenNoteNumChange()
{
    TimerManager::getInstance()->addTimer(TimerTag::tag(TimerTag::NOTE_NUM_CHANGE));
    QTimer *timer=TimerManager::getInstance()->getTimer(TimerTag::tag(TimerTag::NOTE_NUM_CHANGE));
    timer->setInterval(10);
    connect(timer,SIGNAL(timeout()),this,SLOT(checkNoteNum()));
}


void NoteController::chooseMark(QString path)
{
    notes->setVisible(true);
    MarkdownManager *manager=new MarkdownManager();
    manager->load(SettingHelper::workPath(path));
    notes->getMark()->getEdit()->setPlainText(
                manager->loadContent()->content());

    notes->getMark()->getEdit()->refreshFormat();
    notes->getMark()->getTitle()->setTitle(manager->loadContent()->title());
    notes->getMark()->getTitle()->setCreateDate(manager->loadContent()->date().toString("yyyy-MM-dd"));
}
/**
 * @brief NoteController::addNote
 * 新建笔记
 */
void NoteController::addNote()
{
    MarkdownManager *manager=new MarkdownManager();
    manager->load(":/model/note_module.fei");
    QString name=FileUtil::onlyName("note");

    manager->setTitle(manager->loadContent()->title());
    manager->save(tr("%1/%2.fei").arg(SettingHelper::workspacing()).arg(name),
                  manager->loadContent()->content());

    JsonData *data=new JsonData(tr("%1/%2").arg(SettingHelper::workspacing()).arg(getNoteBookFile()).toUtf8(),"notes");
    data->addData<NoteTip>(createBasicTip(name));
    AppStatic::noteNum+=1;
    delete data;
}
/**
 * @brief NoteController::listWorkspacing
 * 监听工作空间中的文件，当文件发生变化时对界面进行相应当更新。
 */
void NoteController::listWorkspacing()
{
    QFileSystemWatcher *watcher=new QFileSystemWatcher(this);
    watcher->addPath(tr("%1/%2").arg(SettingHelper::workspacing()).arg(getNoteBookFile()));
    connect(watcher,SIGNAL(fileChanged(QString)),this,SLOT(refreshNoteList()));
}

void NoteController::initEditController()
{

    editController=NoteEditController::getInstance(this);
    editController->init(currentNote(),this->getNoteBookFile(),notes->getMark()->getEdit());
    editController->setParent(this);
    editController->setList(notes->getList());
    editController->setTitle(notes->getMark()->getTitle());

}

QString NoteController::currentBookName()
{
    if(getNoteBookFile()=="&_&")
        return "全部笔记";
    JsonData *data=new JsonData(SettingHelper::workPath("notebooks.json").toUtf8(),"notebooks");

    NoteBook *book=data->selectByColumn<NoteBook>("fileName",getNoteBookFile());

    if(book==NULL)
        return "找不到笔记";

    return book->name();

}
/**
 * @brief NoteController::saveNoteBeforeChange
 * 在切换笔记之前，先对上一个笔记的内容进行保存
 */
void NoteController::saveNoteBeforeChange()
{
    int focusIndex_=this->notes->getList()->getListView()->focusIndex();
    this->notes->getList()->getListView()->setFocusIndex(AppStatic::focusIndex);
    if(currentNote().length()>0){
        initEditController();
        editController->onAutoSave();
    }
    this->notes->getList()->getListView()->setFocusIndex(focusIndex_);
    AppStatic::focusIndex=focusIndex_;
}

/**
 * @brief NoteController::getNoteBookFile
 * @return
 * 获取当前笔记本对应的文件名称
 */
QString NoteController::getNoteBookFile()
{
    if(AppStatic::currentBook.length()!=0){
        return AppStatic::currentBook;
    }
    else if(SettingHelper::currentBook().length()!=0){
        return SettingHelper::currentBook();
    }else
    {
        JsonData *data=new JsonData(tr("%1/notebooks.json").arg(SettingHelper::workspacing()).toUtf8(),"notebooks");
        NoteBook *book=data->selectFirst<NoteBook>();
        QString notebookName=book->fileName();
        delete data;
        book->deleteLater();
        return notebookName;
    }
}

void NoteController::updateFocusIndex()
{
    JsonData *data=new JsonData(SettingHelper::workPath(getNoteBookFile()).toUtf8(),"notes");
    if(AppStatic::currentNote.length()<=0)
        return;
    int index=data->indexByColumn("fileName",AppStatic::currentNote);
    if(index==-1)
        return;
    AppStatic::focusIndex=index;
}

NoteTip *NoteController::createBasicTip(QString fileName)
{
    NoteTip *tip=new NoteTip;
    tip->setFileName(fileName);
    tip->setTitle("新建笔记");
    tip->setUpdateDate(QDateTime::currentDateTime());
    tip->setTip("请输入笔记内容");
    tip->setNotebook(SettingHelper::currentBook());
    return tip;
}
