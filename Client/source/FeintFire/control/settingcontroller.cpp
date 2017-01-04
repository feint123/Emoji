#include "settingcontroller.h"

#include <QFileSystemWatcher>

#include <user/settinghelper.h>

#include <QDebug>


SettingController::SettingController(SettingDialog *set)
{
    this->set=set;
}

void SettingController::setWidgetList(QList<FeintSetting *> widgetList)
{
    this->widgetList=widgetList;
}

void SettingController::start()
{
    QFileSystemWatcher *watcher=new QFileSystemWatcher;
    watcher->addPath(SettingHelper::settingPath());
    connect(watcher,SIGNAL(fileChanged(QString)),this,SLOT(on_setting_changed()));
}

void SettingController::on_setting_changed()
{
   for(FeintSetting* feint:widgetList)
   {
       feint->setColorStyle(SettingHelper::getStyle());
   }
}
