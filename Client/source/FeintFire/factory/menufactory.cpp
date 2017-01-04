#include "menufactory.h"

#include <QDir>
#include <QDebug>
MenuFactory::MenuFactory()
{

}

FeintMenu *MenuFactory::createMenu(MainWindow *parent, FeintSetting::STYLE style)
{
    FeintMenu *menu=new FeintMenu(parent,style);
    menu->addTopItem("个人主页",QIcon(""));
   // menu->addTopItem("个人主页",QIcon(tr("%1/../Resources/main.png").arg(QDir::currentPath())));
    menu->addSubItem(0,"首页",QIcon());
    menu->addSubItem(0,"展示",QIcon());
    menu->addSubItem(0,"信息完善",QIcon());
    menu->finishSub(0);

    menu->addTopItem("本地",QIcon(""));
    menu->addSubItem(1,"个人笔记",QIcon());
    menu->addSubItem(1,"计划安排",QIcon());
    menu->addSubItem(1,"收藏",QIcon());
    menu->addSubItem(1,"资源管理",QIcon());
    menu->addSubItem(1,"设置",QIcon());
    menu->finishSub(1);

    menu->addTopItem("个性化",QIcon(""));
    menu->finishSub(2);

    menu->addTopItem("发布文章",QIcon(""));
    menu->addSubItem(3,"语言基础",QIcon());
    menu->addSubItem(3,"计划安排",QIcon());
    menu->addSubItem(3,"API文档",QIcon());
    menu->addSubItem(3,"源码分享",QIcon());
    menu->addSubItem(3,"问答",QIcon());
    menu->finishSub(3);

    menu->addTopItem("帮助",QIcon(""));
    menu->addSubItem(4,"支持",QIcon());
    menu->addSubItem(4,"关于",QIcon());
    menu->addSubItem(4,"使用说明",QIcon());
    menu->finishSub(4);
//    connect(menu,SIGNAL(menuItemClicked(int,int)),parent,SLOT(menuEvnent(int,int)));
    menu->setColorStyle(style);
    return menu;
}
