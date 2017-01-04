#ifndef SETTINGHELPER_H
#define SETTINGHELPER_H

#include <domain/app/setting.h>

#include <QJsonDocument>

#include <QJsonObject>
#include <pane/menu/feintmenu.h>

class SettingHelper:public QObject
{
    Q_OBJECT
public:
    SettingHelper();
    static QJsonDocument readSetting();
    static void saveSetting(QJsonDocument json);
    static QString settingPath();
    static FeintSetting::STYLE getStyle();
    static QString workingPath();
    static QString cachePath();
    static int getFontSize();
    static QString getFontFamily();
private:
    Setting set;

};

#endif // SETTINGHELPER_H
