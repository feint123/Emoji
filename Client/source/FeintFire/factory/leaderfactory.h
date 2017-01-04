#ifndef LEADERFACTORY_H
#define LEADERFACTORY_H

#include <pane/leader/backleader.h>
#include <pane/leader/searchleader.h>



class LeaderFactory
{
public:
    LeaderFactory();
    static SearchLeader *createSearch(QWidget*parent=0,FeintSetting::STYLE style=FeintSetting::Daily);
    static BackLeader *creareBack(QWidget *parent=0,FeintSetting::STYLE style=FeintSetting::Daily);
};

#endif // LEADERFACTORY_H
