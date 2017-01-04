
#include "maincontent.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <pane/menu/feintmenu.h>

#include <pane/leader/searchleader.h>

#include <widget/view/listview.h>

#include <QDesktopWidget>
#include <QFileSystemWatcher>
#include <QPainter>
#include <QPropertyAnimation>

#include <graphic/screenhelper.h>

#include <fileload/articaluploaddialog.h>

#include <factory/leaderfactory.h>
#include <factory/mainpartfactory.h>
#include <factory/markdownfactory.h>
#include <factory/menufactory.h>

#include <plan/planframe.h>

#include <user/settinghelper.h>

#include <util/json/jsontoobject.h>

#include <QJsonObject>
#include <QJsonDocument>
#include <domain/app/setting.h>
#include <util/graphic/animationutil.h>
#include <control/menucontroller.h>
#include <control/settingcontroller.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    screenSize=ScreenHelper::getScreenSize();
    this->resize(screenSize.height()*0.8,screenSize.height()*0.85);
    loadComponent();
    loadSettingController();
}
MainWindow::~MainWindow()
{
    delete ui;
}

/**
 * @brief MainWindow::showMenu
 * @param showed
 * 控制菜单的隐藏与显示
 */

void MainWindow::showMenu(bool showed)
{
    if(showed){
        menu->show();
    }
    else{
        menu->hide();
    }
    menuAnim(showed);
}


/**
 * 加载文章的具体内容
 * @brief MainWindow::loadArtical
 * @param tid
 */

void MainWindow::loadArtical(int tid)
{
    area=new ArticalArea();
    this->mainPart->hide();
    area->load(tid);
    ui->main->addWidget(area);
    this->sLeader->close();
    this->menu->hide();

}

void MainWindow::createView()
{
    this->mainPart=MainPartFactory::create(this,SettingHelper::getStyle());
}




/**
 * @brief MainWindow::showSearchLeader
 */
void MainWindow::showSearchLeader()
{
    sLeader=LeaderFactory::createSearch(this,SettingHelper::getStyle());
    connect(sLeader,SIGNAL(showMenu(bool)),this,SLOT(showMenu(bool)));
}


/**
 * @brief MainWindow::createMarkDown
 * 生成markDown编辑器窗口
 */

void MainWindow::createMarkDown()
{
    /*初始化Markdown，并与文章上传对话框相连接*/
    markdown=MarkDownFactory::create(SettingHelper::getStyle());
    markdown->setParent(this);
    connect(markdown,SIGNAL(titleChanged(QString)),this,SLOT(setWindowTitle(QString)));
}

void MainWindow::createPlan()
{
    frame=new PlanFrame(this);
}

void MainWindow::createSetting()
{
    setting=new SettingDialog(this);
    setting->setWindowFlags(Qt::FramelessWindowHint);
}

void MainWindow::refreshMenu(int index)
{
    this->menu=MenuFactory::createMenu(this,SettingHelper::getStyle());
    this->menu->setMenuIndex(index);
}

/**
 * @brief MainWindow::loadComponent
 * 添加所有的组件。并进行适当的初始化
 */
void MainWindow::loadComponent()
{
    refreshMenu(0);
    createSetting();
    createPlan();
    showSearchLeader();
    createView();
    createMarkDown();
    this->menu->hide();
    MenuController *menuController=new MenuController(this->menu);
    menuController->setLeader(this->sLeader);
    menuController->addWidget(MenuController::MainPart,this->mainPart);
    menuController->addWidget(MenuController::Plan,this->frame);
    menuController->addWidget(MenuController::Setting,this->setting);
    menuController->addWidget(MenuController::Markdown,this->markdown);
    menuController->start();
    funcList=menuController->getWidgetList();
}

void MainWindow::loadSettingController()
{
    QList<FeintSetting*> feintlist;
    feintlist.append(this->menu);
    feintlist.append(this->sLeader);
    feintlist.append(this->mainPart);
    feintlist.append(setting);
    feintlist.append(markdown);
    SettingController *settingCon=new SettingController(this->setting);
    settingCon->setWidgetList(feintlist);
    settingCon->start();
}


void MainWindow::refreshMainGeometry(QRect rect, bool isAuto)
{

        for(QWidget *w:funcList)
        {
            if(isAuto)
                w->setGeometry(rect);
            else
                AnimationUtil::GeometryAnim(w->geometry(),rect,w);
        }


}
/**
 * @brief MainWindow::menuAction
 * @param isAuto
 * 当菜单的显示状态发生改变时，主要组件发生的变化。
 */
void MainWindow::menuAction(bool isAuto)
{
    QRect menuRect;
    if(this->menu->isVisible())
    {

        menuRect=QRect(this->menu->width(),
                             this->sLeader->height(),
                             this->width()-this->menu->width(),
                             mainHeight);
    }
    else
    {
        menuRect=QRect(0,this->sLeader->height(),this->width(),
                           mainHeight);
    }
    refreshMainGeometry(menuRect,isAuto);
}

/**
 * @brief MainWindow::menuAnim
 * @param show
 * 设置菜单动画，以及受菜单影响的主要组件的动画。
 */
void MainWindow::menuAnim(bool show)
{
    QRect startR=QRect(0-this->menu->width(),this->menu->y(),
                       this->menu->width(),this->menu->height());
    QRect endR=this->menu->geometry();
    if(show)
        AnimationUtil::GeometryAnim(startR,endR,this->menu);

    menuAction(false);

}

void MainWindow::resizeEvent(QResizeEvent *event)
{

    mainHeight=this->height()-sLeader->height();

    this->menu->setGeometry(0,this->sLeader->height(),
                            menu->width(),mainHeight);

    menuAction();

    this->sLeader->setGeometry(0,0,this->width(),this->sLeader->height());
}








