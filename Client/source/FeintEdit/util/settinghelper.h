#ifndef SETTINGHELPER_H
#define SETTINGHELPER_H

#include <domain/setting.h>

#include<QDir>
#include<QFile>

class SettingHelper:public QObject
{
    Q_OBJECT
public:
    SettingHelper();
    static int fontSize();
    static QString fontFamily();
    static QString workspacing();
    static QString workPath(QString file);
    //最近一次打开的笔记本
    static QString currentBook();
    static QString currentBookName();
    static int isShareImage();
    static int autoSave();
    static Setting* setting();
    static Setting* loadSetting();
    static void saveSetting(Setting *setting);
    static bool hasSetting();

    static void initWorkspacing();

    static void initBasePlug(QString name);

};

#endif // SETTINGHELPER_H
