#include "feintsetting.h"

FeintSetting::FeintSetting()
{

}

void FeintSetting::setColorStyle(FeintSetting::STYLE style)
{
    this->cstyle=style;
    switch(style)
    {
    case FeintSetting::Daily:
        createDailyStyle();
        break;
    case FeintSetting::Dark:
        createDarkStyle();
        break;
    default:
        break;
    }
}

FeintSetting::STYLE FeintSetting::getColorStyle()
{
    return this->cstyle;
}

void FeintSetting::createDailyStyle()
{

}

void FeintSetting::createDarkStyle()
{

}
