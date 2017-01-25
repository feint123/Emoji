#include "notecontroller.h"
#include "noteeditcontroller.h"
#include <factory/notecontrolfactory.h>
#include <pane/markdown/markdownmanager.h>
#include <util/qvariantutil.h>
#include <util/settinghelper.h>
#include <domain/notebook.h>
#include <util/json/jsondata.h>
#include <view/note/noteitem.h>
#include <QDebug>
#include <QFileSystemWatcher>
#include <QTimer>

NoteController::NoteController(Notes *note)
{
    connect(this,SIGNAL(currentNoteChanged(QString)),this,SLOT(readyLoadNote(QString)));

    this->notes=note;
    connect(note,SIGNAL(destroyed(QObject*)),this,SLOT(deleteLater()));

    ControlFloatButton *floatBtn=NoteControlFactory::create(note);
    note->setFloatBtn(floatBtn);
    connect(floatBtn,SIGNAL(controlClicked(int)),this,SLOT(onControlClicked(int)));

    refreshNoteList();
    connect(this,SIGNAL(noteNumChanged(int)),this,SLOT(refreshNoteList()));
    createView();
}

NoteController::NoteController()
{

}

NoteController::~NoteController()
{
    delete timer;
    delete editController;
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
    if(refreshLock)
        saveNoteBeforeChange();
    refreshLock=true;

    if (m_currentNote == currentNote)
        return;
    m_currentNote = currentNote;
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

void NoteController::onControlClicked(int i)
{
    switch (i) {
    case 0:
        addNote();
        break;
    default:
        break;
    }
}
/**
 * @brief NoteController::refreshNoteList
 * 更新笔记列表。
 */
void NoteController::refreshNoteList()
{
    //在笔记列表设置当前的笔记本名称
    notes->getList()->getNoteH()->setCurrentNotebook(SettingHelper::currentBookName());
    //从当前笔记本获取笔记列表
    JsonData *data=new JsonData(tr("%1/%2").arg(SettingHelper::workspacing()).arg(getNoteBookFile()).toUtf8(),"notes");
    QList<NoteTip*> noteTip=data->selectAll<NoteTip>();
    QVariantUtil *qv=new QVariantUtil;
    QList<QVariant> qdata=qv->turn<NoteTip>(noteTip);
    notes->getList()->loadDate(qdata);
    connect(notes->getList()->getListView(),SIGNAL(selectItem(QVariant)),this,SLOT(onNoteSelect(QVariant)));
    connect(notes->getList()->getListView(),SIGNAL(scrollYChanged(int)),this,SLOT(onScrollLNoteList(int)));
    this->notes->getList()->getListView()->setFocusIndex(focusIndex);
    setNoteNum(noteTip.count());
    this->notes->getList()->getListView()->setScrollY(this->currentScroll);
}

void NoteController::loadNote()
{
    disconnect(loadtimer,SIGNAL(timeout()),this,SLOT(loadNote()));
    loadtimer->stop();
    notes->createMark(currentNote());
    chooseMark(currentNote()+".fei");
    initEditController();
}

void NoteController::readyLoadNote(QString noteFile)
{
    loadtimer=new QTimer(this);
    loadtimer->setInterval(50);
    connect(loadtimer,SIGNAL(timeout()),this,SLOT(loadNote()));
    loadtimer->start();
}

void NoteController::onScrollLNoteList(int value)
{
    this->currentScroll=value;
}

void NoteController::checkNoteNum()
{
    JsonData *data=new JsonData(tr("%1/%2").arg(SettingHelper::workspacing()).arg(getNoteBookFile()).toUtf8(),"notes");
    QList<NoteTip*> noteTip=data->selectAll<NoteTip>();
    setNoteNum(noteTip.count());
}

void NoteController::createView()
{
    JsonData *data=new JsonData(SettingHelper::workPath(this->getNoteBookFile()).toUtf8(),"notes");

    setCurrentNote(data->selectAll<NoteTip>()[0]->fileName());
    timer=new QTimer(this);
    timer->setInterval(1000);
    connect(timer,SIGNAL(timeout()),this,SLOT(checkNoteNum()));
    timer->start();
}


void NoteController::chooseMark(QString path)
{
    notes->setVisible(true);
    MarkdownManager *manager=new MarkdownManager();
    manager->load(SettingHelper::workPath(path));
    notes->getMark()->getEdit()->setText(
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
//    notes->getList()->getListView()->addValue(QVariant::fromValue(*createBasicTip(name)));

//    notes->getList()->getListView()->setFocusIndex(data->selectAll<NoteTip>().count());

//    setCurrentNote(name);
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
    if(editControlLock)
        delete editController;
    editController=new NoteEditController(currentNote(),this->getNoteBookFile(),notes->getMark()->getEdit());
    editController->setList(notes->getList());
    editController->setTitle(notes->getMark()->getTitle());
    editController->startEdit();
    editControlLock=true;
}
/**
 * @brief NoteController::saveNoteBeforeChange
 * 在切换笔记之前，先对上一个笔记的内容进行保存
 */
void NoteController::saveNoteBeforeChange()
{
    int focusIndex_=this->notes->getList()->getListView()->focusIndex();
    this->notes->getList()->getListView()->setFocusIndex(focusIndex);
    if(currentNote().length()>0){
        initEditController();
        editController->onAutoSave();
    }
    this->notes->getList()->getListView()->setFocusIndex(focusIndex_);
    focusIndex=focusIndex_;
}

/**
 * @brief NoteController::getNoteBookFile
 * @return
 * 获取当前笔记本对应的文件名称
 */
QString NoteController::getNoteBookFile()
{
    if(SettingHelper::currentNote().length()==0){
        JsonData *data=new JsonData(tr("%1/notebooks.json").arg(SettingHelper::workspacing()).toUtf8(),"notebooks");
        QString notebookName=data->selectFirst<NoteBook>()->fileName();
        return notebookName;
    }else
    {
        return SettingHelper::currentNote();
    }
}

NoteTip *NoteController::createBasicTip(QString fileName)
{
    NoteTip *tip=new NoteTip;
    tip->setFileName(fileName);
    tip->setTitle("新建笔记");
    tip->setUpdateDate(QDateTime::currentDateTime());
    tip->setTip("请输入笔记内容");
    tip->setNotebook(SettingHelper::currentNote());
    return tip;
}
