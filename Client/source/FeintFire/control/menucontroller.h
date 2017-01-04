#ifndef MENUCONTROLLER_H
#define MENUCONTROLLER_H

#include <QWidget>

#include <pane/menu/feintmenu.h>

#include <main/mainwindow.h>



class MenuController:public QObject
{
    Q_OBJECT
public:
    enum WIDGETNAME{
        MainPart,
        Plan,
        Markdown,
        Setting
    };

    MenuController(FeintMenu *menu=0);
    void addWidget(WIDGETNAME name,QWidget* widget);
    FeintMenu *getMenu() const;
    void setMenu(FeintMenu *value);
    void setLeader(SearchLeader *leader);
    void start();
    QList<QWidget *> getWidgetList() const;

private:
    QHash<WIDGETNAME,QWidget*> widgetMap;
    QList<QWidget*> widgetList;
    FeintMenu *menu;
    SearchLeader *leader;

    void localAction(int i);
    void homeAction(int i);
    void refreshVisibleWidget(QWidget* widget);

private slots:
    void menuEvnent(int,int);
};

#endif // MENUCONTROLLER_H
