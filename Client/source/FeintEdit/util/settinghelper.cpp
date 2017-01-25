#include "settinghelper.h"

#include <QCoreApplication>
#include <QJsonDocument>

#include <util/json/jsontoobject.h>
#include <util/json/objecttojson.h>

SettingHelper::SettingHelper()
{

}

int SettingHelper::fontSize()
{
    return setting()->fontSize();
}

QString SettingHelper::fontFamily()
{
    return setting()->fontFamily();
}

QString SettingHelper::workspacing()
{
    return setting()->workspacing();
}

QString SettingHelper::workPath(QString file)
{
    return tr("%1/%2").arg(workspacing()).arg(file);
}

QString SettingHelper::currentNote()
{
    return setting()->currentNote();
}

QString SettingHelper::currentBookName()
{
    return setting()->currentBookName();
}

int SettingHelper::isShareImage()
{
    return setting()->isShareImage();
}

int SettingHelper::autoSave()
{
    return setting()->autoSave();
}

Setting *SettingHelper::setting()
{
    Setting *setting=loadSetting();
    return setting;
}

Setting *SettingHelper::loadSetting()
{
    QJsonDocument doc;
    QFile file(tr("%1/%2").arg(QCoreApplication::applicationDirPath()).arg("setting.json"));
    if(file.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        doc=QJsonDocument::fromJson(file.readAll());
    }
    else{
        file.setFileName(":/config/setting.json");
        if(file.open(QIODevice::ReadOnly|QIODevice::Text))
        {
            doc=QJsonDocument::fromJson(file.readAll());

        }
    }
    file.close();

    return feint::JsonToObject::createObject<Setting>(doc.object());

}

void SettingHelper::saveSetting(Setting *setting)
{
    QFile file(tr("%1/%2").arg(QCoreApplication::applicationDirPath()).arg("setting.json"));
    if(file.open(QIODevice::WriteOnly|QIODevice::Text))
    {
        QJsonDocument doc=ObjectToJson::create(setting);
        file.write(doc.toJson());
        file.flush();
        file.close();
    }
}

bool SettingHelper::hasSetting()
{
    QFile file(tr("%1/%2").arg(QCoreApplication::applicationDirPath()).arg("setting.json"));
    if(file.open(QIODevice::ReadOnly|QIODevice::Text))
        return true;
    else return false;
}
