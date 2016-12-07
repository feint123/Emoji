#include "textsetting.h"

TextSetting::TextSetting()
{
    textTypeList<<"firstmenu"<<"secondmenu"<<"maintitle"<<"type"<<"tag"<<"title"
               <<"tip"<<"other"<<"arti_title"<<"arti_info"<<"arti_text"
              <<"name"<<"com_info"<<"com_text";
}

void TextSetting::setColor(QString type, QColor color)
{
    this->colorMap.insert(type,color);
}

QColor TextSetting::getColor(QString type)
{
    return this->colorMap.value(type);
}

QString TextSetting::getTextType(Textype type) const
{
    return textTypeList.at(type);
}
