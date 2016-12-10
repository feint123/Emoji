#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <pane/menu/feintmenu.h>

#include <pane/leader/searchleader.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    SearchLeader *sLeader=new SearchLeader();
    ui->leader->addWidget(sLeader);

    initMenu();

    ui->main->addStretch();

    connect(sLeader,SIGNAL(showMenu(bool)),this,SLOT(showMenu(bool)));
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

    ui->main->addWidget(menu);
    menu->hide();

}
