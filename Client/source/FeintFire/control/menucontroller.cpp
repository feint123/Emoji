#include "menucontroller.h"

#include <pane/markdown/markdown.h>



MenuController::MenuController(FeintMenu *menu)
{
    this->menu=menu;
}

void MenuController::addWidget(WIDGETNAME name, QWidget *widget)
{
    this->widgetMap[name]=widget;
    this->widgetList.append(widget);
}

FeintMenu *MenuController::getMenu() const
{
    return menu;
}

void MenuController::setMenu(FeintMenu *value)
{
    menu = value;
}

void MenuController::setLeader(SearchLeader *leader)
{
    this->leader=leader;
}

void MenuController::start()
{
    connect(menu,SIGNAL(menuItemClicked(int,int)),this,SLOT(menuEvnent(int,int)));
    refreshVisibleWidget(widgetMap[MainPart]);
}

QList<QWidget *> MenuController::getWidgetList() const
{
    return widgetList;
}

void MenuController::localAction(int i)
{
    switch(i){
    // 进入编辑个人笔记的功能
    case 0:
            refreshVisibleWidget(widgetMap[Markdown]);
        break;
    case 1:
            refreshVisibleWidget(widgetMap[Plan]);
            this->menu->parentWidget()->setWindowTitle("计划安排");
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
            refreshVisibleWidget(widgetMap[Setting]);
            this->menu->parentWidget()->setWindowTitle("设置");
        break;

    default:
        break;
    }
}

void MenuController::homeAction(int i)
{
    switch(i)
    {
    case 0:
            refreshVisibleWidget(widgetMap[MainPart]);
        break;

    default:
        break;
    }
}

void MenuController::refreshVisibleWidget(QWidget *widget)
{
    widget->show();
    for(QWidget* w:widgetList)
    {
        if(widget!=w)
            w->hide();
    }
}



void MenuController::menuEvnent(int top, int sub)
{
    switch(top){
    case 0:
        homeAction(sub);
        break;
    case 1:
        localAction(sub);
        break;
    case 2:
        break;
    default:
        break;
    }
    emit this->leader->showMenu(false);
    this->leader->setIsMenuShow(false);
}


