#include "leaderfactory.h"

#include <QIcon>

LeaderFactory::LeaderFactory()
{

}

SearchLeader *LeaderFactory::createSearch(QWidget *parent, FeintSetting::STYLE style)
{
    SearchLeader *sLeader=new SearchLeader(parent);
    sLeader->setMenuIcon(QIcon("://Category.png"));
    sLeader->setColorStyle(style);
    return sLeader;
}

BackLeader *LeaderFactory::creareBack(QWidget *parent, FeintSetting::STYLE style)
{
    BackLeader *backL=new BackLeader(parent);
    backL->setIcon(QIcon(":/back.png"),QIcon("://set.png"));
    backL->setColorStyle(style);

    return backL;
}


/**

    sLeader=new SearchLeader();
    sLeader->setSettingIcon(QIcon("://set.png"));
    sLeader->setMenuIcon(QIcon("://Category.png"));

    backL=new BackLeader();
    backL->setIcon(QIcon(":/back.png"),QIcon("://set.png"));
    ui->leader->addWidget(sLeader);
    ui->leader->addWidget(backL);
    backL->hide();

    connect(sLeader,SIGNAL(showMenu(bool)),this,SLOT(showMenu(bool)));
    connect(backL,SIGNAL(back(int)),this,SLOT(back(int)));


  **/
