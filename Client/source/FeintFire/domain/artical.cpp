#include "artical.h"

Artical::Artical()
{

}

ArticalInfo Artical::getInfo() const
{
    return info;
}

void Artical::setInfo(const ArticalInfo &value)
{
    info = value;
}

QString Artical::getContent() const
{
    return content;
}

void Artical::setContent(const QString &value)
{
    content = value;
}

QString Artical::getTitle() const
{
    return title;
}

void Artical::setTitle(const QString &value)
{
    title = value;
}
