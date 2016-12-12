#include "articalarea.h"
#include "carditem.h"
#include "maincontent.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <pane/menu/feintmenu.h>

#include <pane/leader/searchleader.h>

#include <widget/view/listview.h>

#include <domain/articalcard.h>

#include <QPropertyAnimation>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    initLeader();
    initMenu();
    initMainPart();


  //  ui->main->addStretch();


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

void MainWindow::back(int)
{
    area->hide();
    mainPart->show();
    sLeader->show();
    backL->hide();
}

void MainWindow::loadArtical(int tid)
{
    area=new ArticalArea();
    this->mainPart->hide();
    area->load(tid);
    ui->main->addWidget(area);

    this->sLeader->hide();
    this->backL->show();
}



void MainWindow::initMenu()
{

    menu=new FeintMenu();
    menu->addTopItem("个人主页");
    menu->addSubItem(0,"展示",QIcon());
    menu->addSubItem(0,"信息完善",QIcon());
    menu->finishSub(0);

    menu->addTopItem("本地");
    menu->addSubItem(1,"个人笔记",QIcon());
    menu->addSubItem(1,"收藏",QIcon());
    menu->addSubItem(1,"资源管理",QIcon());
    menu->finishSub(1);

    menu->addTopItem("个性化");
    menu->finishSub(2);

    menu->addTopItem("发布文章");
    menu->finishSub(3);

    menu->addTopItem("帮助");
    menu->addSubItem(4,"支持",QIcon());
    menu->addSubItem(4,"关于",QIcon());
    menu->addSubItem(4,"使用说明",QIcon());
    menu->finishSub(4);
    ui->main->addWidget(menu);
    menuRect=menu->geometry();
    menu->hide();

}

void MainWindow::initMainPart()
{
    mainPart=new MainPart(this);

    QStringList tabTitles;

    tabTitles<<"首页"<<"Java"<<"PhP"<<"C语言"<<"JavaScript"<<"Qt"<<"问答";

    mainPart->addTabs(tabTitles);

    ui->main->addWidget(mainPart);

}

void MainWindow::initLeader()
{
    sLeader=new SearchLeader();
    backL=new BackLeader();
    ui->leader->addWidget(sLeader);
    ui->leader->addWidget(backL);
    backL->hide();

    connect(sLeader,SIGNAL(showMenu(bool)),this,SLOT(showMenu(bool)));
    connect(backL,SIGNAL(back(int)),this,SLOT(back(int)));
}


