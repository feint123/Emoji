#include "articalarea.h"
#include "carditem.h"
#include "maincontent.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <pane/menu/feintmenu.h>

#include <pane/leader/searchleader.h>

#include <widget/view/listview.h>

#include <domain/articalcard.h>

#include <QPainter>
#include <QPropertyAnimation>

#include <graphic/screenhelper.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    initLeader();
    initMenu();
    initMainPart();
    screenSize=ScreenHelper::getScreenSize();
    this->resize(screenSize.height()*0.8,screenSize.height()*0.85);


}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showMenu(bool showed)
{
    if(showed)
        menu->show();
    else
        menu->hide();
}

/**
 * 返回主页面时执行的事件
 * @brief MainWindow::back
 */
void MainWindow::back(int id)
{
    switch(id){
    case 1:
        area->hide();
        reloadMain();
        break;
    case 2:
        markdown->hide();
        reloadMain();
        break;
    default:
        break;
    }
}

/**
 * 重新加载主页面进行的操作
 * @brief MainWindow::reloadMain
 */

void MainWindow::reloadMain()
{
    mainPart->show();
    sLeader->show();
    backL->hide();
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
    this->sLeader->hide();

    this->backL->show();
    this->backL->setBackId(1);
    this->menu->hide();
    this->sLeader->setIsMenuShow(!sLeader->getIsMenuShow());

}


void MainWindow::menuEvnent(int top, int sub)
{
    switch(top){
    case 0:
        break;
    case 1:
        localAction(sub);
        break;
    case 2:
        break;
    default:
        break;
    }
}

/**
 * 菜单中一些事件
 * @brief MainWindow::localAction
 * @param i
 */
void MainWindow::localAction(int i)
{
    switch(i){
    case 0:

        mainPart->hide();
        this->sLeader->hide();
        menu->hide();
        markdown->show();
        this->sLeader->setIsMenuShow(!sLeader->getIsMenuShow());
        this->backL->setBackId(2);
        this->backL->show();

        turnWindowAnim();
        break;
    case 1:
        break;
    case 2:
        break;
    default:
        break;
    }

}

void MainWindow::turnWindowAnim()
{

//    QPropertyAnimation *anim=new QPropertyAnimation(markdown,"geometry");
//    anim->setDuration(300);
//    anim->setStartValue(markdown->geometry());
//    anim->setEndValue(QRect(markdown->geometry().x(),markdown->geometry().y()
//                            ,);
//    anim->start();
    qDebug()<<"MainWindow[tuenWindowAnim]:"<<screenSize.width();
    this->setGeometry(QRect(screenSize.width()/2-screenSize.height()*0.4,
                            screenSize.height()*0.075,
                          screenSize.height()*0.8,screenSize.height()*0.85));
//    connect(anim,SIGNAL(finished()),this,SLOT(repaint()));
}



void MainWindow::initMenu()
{

    menu=new FeintMenu();
    menu->addTopItem("个人主页",QIcon("://main.png"));
    menu->addSubItem(0,"展示",QIcon());
    menu->addSubItem(0,"信息完善",QIcon());
    menu->finishSub(0);

    menu->addTopItem("本地",QIcon("://local.png"));
    menu->addSubItem(1,"个人笔记",QIcon());
    menu->addSubItem(1,"收藏",QIcon());
    menu->addSubItem(1,"资源管理",QIcon());
    menu->finishSub(1);

    menu->addTopItem("个性化",QIcon("://beauty.png"));
    menu->finishSub(2);

    menu->addTopItem("发布文章",QIcon("://artical.png"));
    menu->finishSub(3);

    menu->addTopItem("帮助",QIcon("://help.png"));
    menu->addSubItem(4,"支持",QIcon());
    menu->addSubItem(4,"关于",QIcon());
    menu->addSubItem(4,"使用说明",QIcon());
    menu->finishSub(4);
    ui->main->addWidget(menu);
    menuRect=menu->geometry();
    menu->hide();
    connect(menu,SIGNAL(menuItemClicked(int,int)),this,SLOT(menuEvnent(int,int)));

}

void MainWindow::initMainPart()
{
    mainPart=new MainPart(this);

    QStringList tabTitles;

    tabTitles<<"首页"<<"Java"<<"PhP"<<"C语言"<<"JavaScript"<<"Qt"<<"问答";

    mainPart->addTabs(tabTitles);

    ui->main->addWidget(mainPart);

    markdown=new MarkDown();
   // markdown->setTheme(MarkDownEdit::DARK);

    ui->main->addWidget(markdown);
    markdown->hide();

}

void MainWindow::initLeader()
{
    sLeader=new SearchLeader();
    sLeader->setSettingIcon(QIcon("://set.png"));
    sLeader->setMenuIcon(QIcon("://Category.png"));

    backL=new BackLeader();
    ui->leader->addWidget(sLeader);
    ui->leader->addWidget(backL);
    backL->hide();

    connect(sLeader,SIGNAL(showMenu(bool)),this,SLOT(showMenu(bool)));
    connect(backL,SIGNAL(back(int)),this,SLOT(back(int)));
}





