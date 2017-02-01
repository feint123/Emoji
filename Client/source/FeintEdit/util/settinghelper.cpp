#include "plughelper.h"
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

QString SettingHelper::currentBook()
{
    return setting()->currentNoteBook();
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
    return PlugHelper::loadPlug<Setting>(tr("%1/%2")
                                .arg(QCoreApplication::applicationDirPath())
                                .arg("setting.json").toUtf8());

}

void SettingHelper::saveSetting(Setting *setting)
{
    PlugHelper::savePlug(tr("%1/%2")
                                .arg(QCoreApplication::applicationDirPath())
                                .arg("setting.json").toUtf8(),setting);
}

bool SettingHelper::hasSetting()
{
    return PlugHelper::hasPlug(tr("%1/%2")
                                .arg(QCoreApplication::applicationDirPath())
                               .arg("setting.json").toUtf8());
}

void SettingHelper::initWorkspacing()
{

    initBasePlug("notebooks");
    initBasePlug("recircles");
    initBasePlug("lastedits");

}

void SettingHelper::initBasePlug(QString name)
{
    QFile file(SettingHelper::workPath(name+".json"));
    if(!file.exists())
    {
        file.open(QFile::WriteOnly);
        file.write(name.toUtf8());
        file.close();
    }

}
