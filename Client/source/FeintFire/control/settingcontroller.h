#ifndef SETTINGCONTROLLER_H
#define SETTINGCONTROLLER_H

#include <QObject>

#include <user/settingdialog.h>

#include <util/graphic/feintsetting.h>



class SettingController:public QObject
{
    Q_OBJECT
public:
    SettingController(SettingDialog *set);

    void setWidgetList(QList<FeintSetting*> widgetList);

    void start();

private slots:
    void on_setting_changed();

private:
    SettingDialog *set;
    QList<FeintSetting *> widgetList;
};

#endif // SETTINGCONTROLLER_H
