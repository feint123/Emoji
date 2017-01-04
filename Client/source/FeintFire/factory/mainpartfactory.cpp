#include "mainpartfactory.h"

MainPartFactory::MainPartFactory()
{

}

MainPart *MainPartFactory::create(MainWindow *parent, FeintSetting::STYLE style)
{
    MainPart *main=new MainPart(parent);

    main->setColorStyle(style);

    main->addTabs(createTabList());

    return main;
}

QStringList MainPartFactory::createTabList()
{
    QStringList tabTitles;

    tabTitles<<"语言基础"<<"计划安排"<<"API文档"<<"源码分享"<<"问答"<<"投票";

    return tabTitles;
}
