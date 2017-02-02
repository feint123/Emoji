#ifndef APPSTATIC_H
#define APPSTATIC_H

#include <qstring.h>



class AppStatic
{
public:
    AppStatic();
    static int bookScroll;
    static int noteScroll;
    static int recircleScroll;
    static QString currentNote;
    static QString currentBook;
    //note
    static int focusIndex;
    static int bookNum;
    static int noteNum;
    static int toolHeight;
    static int lastEdit;
    static int maxLastEdit;

    static int standardScreenWidth;
    static int standardBtnHeight;

    //纪录笔记本界面通知栏所在的选项卡位置
    static int recircleIndex;

    static int maxTipWordNum;

    static int maxTitleLength;

};

#endif // APPSTATIC_H
