#include "mainwindow.h"

#include <factory/markdownfactory.h>
#include <factory/menulinefactory.h>

#include <domain/highlighter.h>
#include <domain/notebook.h>
#include <domain/timertag.h>

#include <controller/notecontroller.h>
#include <controller/settingcontroller.h>

#include <QDebug>
#include <QDir>
#include <QStandardPaths>

#include <util/appcolorhelper.h>
#include <util/highlighterhelper.h>
#include <util/settinghelper.h>
#include <util/timermanager.h>
#include <util/wordhelper.h>

#include <view/notebook/notebookdialog.h>

#include <plug/appstatic.h>

#include <graphic/screenhelper.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setAttribute(Qt::WA_TranslucentBackground);
    setMinimumWidth(ScreenHelper::getScreenSize().width()/2);
    setMinimumHeight(ScreenHelper::getScreenSize().width()/3);
    initColor();
    initHigh();
    initSetting();
    SettingHelper::initWorkspacing();

    initStatic();

    TimerTag::init();
    TimerManager *m=TimerManager::getInstance(this);

    setWindowIcon(QIcon(":/image/feint.icns"));
    this->resize(800,1000);
    widgetStatus<<0<<0<<0<<0;
    for(int i=0;i<4;i++)
        widgets.append(new QWidget);
    loadController();
    this->setObjectName("win");
    this->setStyleSheet(tr("#win{background:%1;}").arg(AppColorHelper::menuBg()));
}

MainWindow::~MainWindow()
{

}

void MainWindow::resizeEvent(QResizeEvent *event)
{

    resizeMenuLine(menu);
    switch(current())
    {
    case 0:
        resizeMarkdown(this->edit);
        break;
    case 1:
        resizeNoteBooks(this->notebooks);
        break;
//    case 2:
//        break;
    case 2:
        resizeSetting(this->setting);
        break;
    default:
        break;
    }

    NotebookDialog *dialog=NotebookDialog::getInstance();
    if(dialog!=NULL)
        dialog->setGeometry((this->width()-menu->width())/2-dialog->width()/2,0,dialog->width(),dialog->height());

    TipDialog *tDialog=TipDialog::getInstance();
    if(tDialog!=NULL)
        tDialog->setGeometry(0,this->height()-tDialog->height(),
                             this->width()-menu->width(),tDialog->height());


}

void MainWindow::on_menu_clicked(int i)
{
    setCurrent(i);
}

void MainWindow::loadController()
{
    SettingController *menu=new SettingController(this);
}

void MainWindow::initSetting()
{
    if(SettingHelper::hasSetting())
       return;
    Setting *setting=new Setting;
    setting->setAutoSave(60);
    setting->setCurrentBookName("");
    setting->setCurrentNoteBook("");
    QDir dir(QStandardPaths::standardLocations(QStandardPaths::DocumentsLocation).at(0));
    dir.mkdir("FeintEdit");
    setting->setWorkspacing(dir.path()+"/"+"FeintEdit");
    setting->setFontSize(15);
    SettingHelper::saveSetting(setting);


}

void MainWindow::initColor()
{
//    if(AppColorHelper::hasColor())
//        return;
    AppColor *color=new AppColor;
    color->setMenuBg("#2470ff");
    color->setMenuCheck("#1d59c6");
    color->setEditorBg("#fff");
    color->setNoteList("#eef2f6");
    color->setNoteListShadow("#aaa");
    color->setColorTop("#0d161f");
    color->setColorMid("#404244");
    color->setColorBot("#787878");
    color->setScrollHandle("#ccc");
    color->setScrollPage("#f9f9f9");
    AppColorHelper::saveColor(color);
}

void MainWindow::initHigh()
{
    Highlighter *high=new Highlighter();
    high->setBold("#c87c36");
    high->setOrderList("#39ae53");
//    high->setHeader("#eade96");
    high->setHeader("#a3671e");
    high->setUnOrderList("#2d631f");
    high->setDevide("#e82121");
    high->setCode("#368afc");
//    high->setBlock("#adf05d");
    high->setBlock("#8a2793");
    high->setItalic("#f59d49");
    high->setImg("#2064db");
    high->setDel("#de5145");
    HighlighterHelper::saveHighlighter(high);
}

void MainWindow::initStatic()
{
    JsonData *data=new JsonData(SettingHelper::workPath("notebooks.json").toUtf8(),"notebooks");
    AppStatic::bookNum= data->count();
    data=new JsonData(SettingHelper::workPath(AppMessage::getFileName(AppMessage::LASTEDIT)+".json").toUtf8(),
                      AppMessage::getFileName(AppMessage::LASTEDIT));
    AppStatic::lastEdit=data->count();
    Setting *setting=SettingHelper::loadSetting();
    AppStatic::currentBook=setting->currentNoteBook();
    AppStatic::currentNote=setting->currentNote();

    WordHelper::initWord();

    delete data;
}

void MainWindow::resizeMarkdown(Notes *edit)
{
    edit->setGeometry(this->menu->width(),0,
                      this->width()-this->menu->width(),this->height());
}

void MainWindow::resizeMenuLine(MenuLine *menu)
{
    menu->setGeometry(0,0,menu->width(),this->height());
}

void MainWindow::resizeSetting(SettingDialog *dialog)
{
    dialog->setGeometry(this->menu->width(),0,
                        this->width()-this->menu->width(),this->height());
}

void MainWindow::resizeNoteBooks(Notebooks *books)
{
    books->setGeometry(this->menu->width(),0,
                       this->width()-this->menu->width(),this->height());
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    Setting *setting=SettingHelper::loadSetting();
    setting->setCurrentNoteBook(AppStatic::currentBook);
    setting->setCurrentNote(AppStatic::currentNote);
    SettingHelper::saveSetting(setting);
}

void MainWindow::setTool(QDialog *value)
{
    tool = value;
}

QDialog *MainWindow::getTool() const
{
    return tool;
}

void MainWindow::setNotebooks(Notebooks *value)
{
    notebooks = value;
    widgetStatus[1]=1;
    widgets[1]=value;
}

Notebooks *MainWindow::getNotebooks() const
{
    return notebooks;
}

void MainWindow::removeUnusedWidget(int used)
{
    for(int i=0;i<widgets.count();i++)
    {
        if(i!=used)
        {
            if(widgetStatus[i]==1){
                widgets[i]->close();
                widgetStatus[i]=0;
            }
        }
    }
}

void MainWindow::removeWidget(int id)
{
    if(widgetStatus[id]==1)
    {
        widgets[id]->close();
        widgetStatus[id]=0;
    }
}

SettingDialog *MainWindow::getSetting() const
{
    return setting;
}

void MainWindow::setSetting(SettingDialog *value)
{
    setting = value;
    widgetStatus[3]=1;
    widgets[3]=value;
}

int MainWindow::current() const
{
    return m_current;
}

void MainWindow::setCurrent(int current)
{
    if (m_current == current)
        return;

    m_current = current;
    emit currentChanged(current);
}

MenuLine *MainWindow::getMenu() const
{
    return menu;
}

void MainWindow::setMenu(MenuLine *value)
{
    menu = value;
}

Notes *MainWindow::getEdit() const
{
    return edit;
}

void MainWindow::setEdit(Notes *value)
{
    edit = value;
    widgetStatus[0]=1;
    widgets[0]=edit;
}


