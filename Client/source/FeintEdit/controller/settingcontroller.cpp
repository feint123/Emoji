#include "notecontroller.h"
#include "settingcontroller.h"

#include <factory/markdownfactory.h>
#include <factory/menulinefactory.h>
#include <factory/toolfactory.h>

#include <QTimer>
#include <qcoreapplication.h>
#include <qfilesystemwatcher.h>

#include <util/screenfit.h>
#include <util/settinghelper.h>
#include <util/timermanager.h>

#include <domain/notebook.h>
#include <domain/timertag.h>
#include <QDebug>
#include <plug/appstatic.h>

SettingController::SettingController(MainWindow *parent)
{
    this->main=parent;
    menu=MenuLineFactory::create(main);
    main->setMenu(menu);
    menu->show();
 //   connect(menu,SIGNAL(itemClicked(int)),main,SLOT(on_menu_clicked(int)));
    connect(menu,SIGNAL(itemClicked(int)),this,SLOT(on_menu_clicked(int)));

    menu->setClickItem(0);
    on_menu_clicked(0);

    setCurrentBook(AppStatic::currentBook);

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

void SettingController::setCurrentBook(QString currentNote)
{
    if(m_currentNote==currentNote)
        return;
    m_currentNote = currentNote;
    emit currentBookChanged(currentNote);
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
                menu->setClickItem(1);
            }
            else {
                createTool(ToolFactory::Note);
                createNotes();
            }
        }
        break;
    case 1:
        if(lock!=1)
         {
            createTool(ToolFactory::NoteBook);
            createNoteBooks();
         }
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
    menu->setClickItem(0);
}

void SettingController::on_workSpacing_change()
{
    Setting *setting=SettingHelper::loadSetting();
    setting->setCurrentNoteBook("");
    SettingHelper::saveSetting(setting);
    AppStatic::currentBook="";
    SettingHelper::initWorkspacing();
}

void SettingController::on_setting_change()
{
    setCurrentBook(AppStatic::currentBook);
    setWorkspace(SettingHelper::workspacing());

}

void SettingController::createNotes()
{

    main->on_menu_clicked(0);

    Notes *notes=Notes::getInstance(main);

    main->getTool()->setParent(notes);

    notes->setTool(main->getTool());

    notes->createMark();

    NoteController *controller=new NoteController(notes);

    connect(menu,SIGNAL(itemClicked(int)),controller,SLOT(saveNoteBeforeChange()));

    main->setEdit(notes);

    notes->show();

    notes->setGeometry(main->getMenu()->width(),0,
                       main->width()-main->getMenu()->width(),
                       main->height());
    main->removeUnusedWidget(0);
    lock=0;
}

void SettingController::createSetting()
{

    main->on_menu_clicked(2);
    main->getTool()->deleteLater();
    main->setTool(NULL);
    SettingDialog *setting=new SettingDialog(main);
    main->setSetting(setting);
    setting->show();
    setting->setGeometry(main->getMenu()->width(),0,
                         main->width()-main->getMenu()->width(),main->height());
    main->removeUnusedWidget(3);
    lock=2;
}

void SettingController::createNoteBooks()
{
    main->on_menu_clicked(1);
    Notebooks *books=Notebooks::getInstance(main);
    main->getTool()->setParent(books);
    books->setTool(main->getTool());
    books->createView();
    main->setNotebooks(books);
    books->show();

    books->setGeometry(main->getMenu()->width(),0,
                       main->width()-main->getMenu()->width(),main->height());

    disconnect(books,SIGNAL(onBookClicked()),this,SLOT(on_currentNote_change()));
    connect(books,SIGNAL(onBookClicked()),this,SLOT(on_currentNote_change()));

    main->removeUnusedWidget(1);
    lock=1;
}

void SettingController::loadFileListener()
{
    QFileSystemWatcher *watcher=new QFileSystemWatcher;
    watcher->addPath(QCoreApplication::applicationDirPath()+"/setting.json");
    connect(watcher,SIGNAL(fileChanged(QString)),this,SLOT(on_setting_change()));
    connect(this,SIGNAL(workspaceChanged(QString)),this,SLOT(on_workSpacing_change()));
}

bool SettingController::hasNotebook()
{
    JsonData *datas=new JsonData(SettingHelper::workPath("notebooks.json").toUtf8(),"notebooks");
    if(datas->selectAll<NoteBook>().count()>0)
        return true;
    return false;
}

void SettingController::createTool(ToolFactory::Model model)
{
    if(main->getTool()!=NULL)
        main->getTool()->close();

    QDialog *tool=ToolFactory::createTool(main,model);

    tool->setGeometry(0,0,main->width(),ScreenFit::fitToScreen(54));

    main->setTool(tool);

    tool->show();

}



