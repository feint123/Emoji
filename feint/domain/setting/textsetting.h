#ifndef TEXTSETTING_H
#define TEXTSETTING_H

#include <QColor>
#include <QHash>



class TextSetting
{
public:
    enum Textype{
        FIRSTMENU,
        SECONDMENU,
        MAINTILE,
        TYPE,
        TAG,
        TITLE,
        TIP,
        OTHER,
        ARTICAL_TITLE,
        ARTICAL_INFO,
        ARTICAL_TEXT,
        NAME,
        COMMENT_INFO,
        COMMENT_TEXT,
    };

    TextSetting();
    void setColor(QString,QColor color);
    QColor getColor(QString);
    QStringList textTypeList;
    QString getTextType(Textype) const;

private:
    QHash<QString,QColor> colorMap;
};

#endif // TEXTSETTING_H
