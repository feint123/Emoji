#include "notecontroller.h"
#include "settingcontroller.h"

#include <factory/markdownfactory.h>
#include <factory/menulinefactory.h>

#include <qcoreapplication.h>
#include <qfilesystemwatcher.h>

#include <util/settinghelper.h>

#include <domain/notebook.h>
#include <QDebug>

SettingController::SettingController(MainWindow *parent)
{
    this->main=parent;
    menu=MenuLineFactory::create(main);
    main->setMenu(menu);
    connect(menu,SIGNAL(menuClick(int)),main,SLOT(on_menu_clicked(int)));
    connect(menu,SIGNAL(menuClick(int)),this,SLOT(on_menu_clicked(int)));
    menu->setClickItem(0);
    setCurrentNote(SettingHelper::currentNote());
 //   connect(this,SIGNAL(currentNoteChanged(QString)),this,SLOT(on_currentNote_change()));
    connect(this,SIGNAL(workspaceChanged(QString)),this,SLOT(on_workSpacing_change()));
    loadFileListener();
}

QString SettingController::currentNote() const
{
    return m_currentNote;
}

QString SettingController::workspace() const
{
    return m_workspace;
}

void SettingController::setCurrentNote(QString currentNote)
{
    if(m_currentNote==currentNote)
        return;
    m_currentNote = currentNote;
    emit currentNoteChanged(currentNote);
}

void SettingController::setWorkspace(QString workspace)
{
    if (m_workspace == workspace)
        return;

    m_workspace = workspace;
    emit workspaceChanged(workspace);
}

void SettingController::on_menu_clicked(int i)
{
    switch(i){
    case 0:
        if(lock!=0){
            if(!hasNotebook()){
                lock=0;
                menu->setClickItem(1);
            }
            else createNotes();
        }
        break;
    case 1:
        if(lock!=1)
            createNoteBooks();
        break;
//    case 2:
//        break;
    case 2:
        if(lock!=2)
            createSetting();
        break;
    default:
        break;
    }
}

void SettingController::on_currentNote_change()
{
  //  menu->setClickItem(1);
    menu->setClickItem(0);
}

void SettingController::on_workSpacing_change()
{
    Setting *setting=SettingHelper::loadSetting();
    setting->setCurrentNote("");
    SettingHelper::saveSetting(setting);
}

void SettingController::on_setting_change()
{
    setCurrentNote(SettingHelper::currentNote());
    setWorkspace(SettingHelper::workspacing());

}

void SettingController::createNotes()
{
    Notes *notes=Notes::getInstance(main);

    notes->createMark();

    NoteController *controller=new NoteController(notes);

    main->setEdit(notes);

    notes->show();

    notes->setGeometry(main->getMenu()->width(),0,main->width()-main->getMenu()->width(),
                       main->height());
    main->removeUnusedWidget(0);
    lock=0;
}

void SettingController::createSetting()
{
    SettingDialog *setting=new SettingDialog(main);
    main->setSetting(setting);
    setting->show();
    setting->setGeometry(main->getMenu()->width(),0,main->width()-main->getMenu()->width(),main->height());
    main->removeUnusedWidget(3);
    lock=2;
}

void SettingController::createNoteBooks()
{
    Notebooks *books=Notebooks::getInstance(main);
    main->setNotebooks(books);
    books->show();
    books->setGeometry(main->getMenu()->width(),0,
                       main->width()-main->getMenu()->width(),main->height());
    connect(books,SIGNAL(onBookClicked()),this,SLOT(on_currentNote_change()));
    main->removeUnusedWidget(1);
    lock=1;
}

void SettingController::loadFileListener()
{
    QFileSystemWatcher *watcher=new QFileSystemWatcher;
    watcher->addPath(QCoreApplication::applicationDirPath()+"/setting.json");
    connect(watcher,SIGNAL(fileChanged(QString)),this,SLOT(on_setting_change()));

}

bool SettingController::hasNotebook()
{
    JsonData *datas=new JsonData(SettingHelper::workPath("notebooks.json").toUtf8(),"notebooks");
    if(datas->selectAll<NoteBook>().count()>0)
        return true;
    return false;
}



