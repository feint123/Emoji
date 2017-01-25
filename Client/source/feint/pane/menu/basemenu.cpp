#include "basemenu.h"

BaseMenu::BaseMenu()
{

}

QList<QAction *> BaseMenu::getActionList() const
{
    return actionList;
}

void BaseMenu::setActionList(const QList<QAction *> &value)
{
    actionList = value;
}

void BaseMenu::addBaseAction(QAction *action)
{
    actionList.append(action);
}
