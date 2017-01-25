#include "settingdialog.h"
#include "settinghelper.h"

#include <util/json/jsontoobject.h>

SettingHelper::SettingHelper()
{

}


QJsonDocument SettingHelper::readSetting()
{
    QFile file(SettingHelper::settingPath());
    if(file.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        QJsonDocument doc=QJsonDocument::fromJson(file.readAll());

        file.close();


        return doc;
    }
}

void SettingHelper::saveSetting(QJsonDocument setting)
{
    QFile file(SettingHelper::settingPath());
    if(file.open(QIODevice::WriteOnly|QIODevice::Text)){
        file.write(setting.toJson());
        file.flush();
        file.close();
    }
}

QString SettingHelper::settingPath()
{
    return  tr("/Users/feint/Desktop/setting.json");
}

FeintSetting::STYLE SettingHelper::getStyle()
{
    QJsonObject set=SettingHelper::readSetting().object();
    if(set["style"]=="daily")
        return FeintSetting::Daily;
    else
        return FeintSetting::Dark;
}

QString SettingHelper::workingPath()
{
    QJsonObject set=SettingHelper::readSetting().object();
    return set["workspacing"].toString();
}

QString SettingHelper::cachePath()
{
    QJsonObject set=SettingHelper::readSetting().object();
    return set["cache_area"].toString();
}

int SettingHelper::getFontSize()
{
    QJsonObject set=SettingHelper::readSetting().object();
    return set["font_size"].toInt();
}

QString SettingHelper::getFontFamily()
{
    QJsonObject set=SettingHelper::readSetting().object();
    return set["font_family"].toString();
}
