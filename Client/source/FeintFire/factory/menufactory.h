#ifndef MENUFACTORY_H
#define MENUFACTORY_H

#include <pane/menu/feintmenu.h>

#include <main/mainwindow.h>



class MenuFactory:QObject
{
    Q_OBJECT
public:
    MenuFactory();

    static FeintMenu* createMenu(MainWindow *parent,FeintSetting::STYLE style);
};

#endif // MENUFACTORY_H
