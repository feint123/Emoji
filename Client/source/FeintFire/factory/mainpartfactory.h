#ifndef MAINPARTFACTORY_H
#define MAINPARTFACTORY_H

#include <main/mainwindow.h>



class MainPartFactory
{
public:
    MainPartFactory();
    static MainPart *create(MainWindow *parent,FeintSetting::STYLE style);
    static QStringList createTabList();
};

#endif // MAINPARTFACTORY_H
