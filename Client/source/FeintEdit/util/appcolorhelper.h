#ifndef APPCOLORHELPER_H
#define APPCOLORHELPER_H

#include <domain/appcolor.h>



class AppColorHelper:public QObject
{
public:
    AppColorHelper();

    static AppColor* loadColor();

    static void saveColor(AppColor *color);

    static QString menuBg();

    static QString menuCheck();

    static QString editorBg();

    static QString noteList();

    static QString noteListShadow();

    static QString editHeaderColor();

    static QString colorTop();

    static QString colorMid();

    static QString colorBot();

    static QString scrollHandle();

    static QString scrollPage();

    static bool hasColor();
};

#endif // APPCOLORHELPER_H
