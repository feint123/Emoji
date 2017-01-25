#ifndef BASEMENU_H
#define BASEMENU_H

#include <QMenu>



class BaseMenu
{
public:
    BaseMenu();

    QList<QAction *> getActionList() const;
    void setActionList(const QList<QAction *> &value);
    void addBaseAction(QAction *action);
private:
    QList<QAction *> actionList;
};

#endif // BASEMENU_H
