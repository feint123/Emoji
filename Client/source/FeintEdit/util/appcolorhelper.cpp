#include "appcolorhelper.h"
#include "plughelper.h"

#include <qcoreapplication.h>
#include <qfile.h>
#include <qjsondocument.h>

#include <util/json/jsontoobject.h>
#include <util/json/objecttojson.h>

AppColorHelper::AppColorHelper()
{

}

AppColor *AppColorHelper::loadColor()
{
    return PlugHelper::loadPlug<AppColor>(tr("%1/%2")
                                   .arg(QCoreApplication::applicationDirPath())
                                   .arg("color.json").toUtf8());
}

void AppColorHelper::saveColor(AppColor *color)
{
    PlugHelper::savePlug(tr("%1/%2")
                         .arg(QCoreApplication::applicationDirPath())
                         .arg("color.json").toUtf8(),color);
}

QString AppColorHelper::menuBg()
{
    return loadColor()->menuBg();
}

QString AppColorHelper::menuCheck()
{
    return loadColor()->menuCheck();
}

QString AppColorHelper::editorBg()
{
    return loadColor()->editorBg();
}

QString AppColorHelper::noteList()
{
    return loadColor()->noteList();
}

QString AppColorHelper::noteListShadow()
{
    return loadColor()->noteListShadow();
}

QString AppColorHelper::editHeaderColor()
{
    return loadColor()->editHeaderColor();
}

QString AppColorHelper::colorTop()
{
    return loadColor()->colorTop();
}

QString AppColorHelper::colorMid()
{
    return loadColor()->colorMid();
}

QString AppColorHelper::colorBot()
{
    return loadColor()->colorBot();
}

QString AppColorHelper::scrollHandle()
{
    return loadColor()->scrollHandle();
}

QString AppColorHelper::scrollPage()
{
    return loadColor()->scrollPage();
}

bool AppColorHelper::hasColor()
{
    return PlugHelper::hasPlug(tr("%1/%2")
                               .arg(QCoreApplication::applicationDirPath())
                               .arg("color.json").toUtf8());
}
