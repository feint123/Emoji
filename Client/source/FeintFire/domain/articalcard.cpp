#include "articalcard.h"

ArticalCard::ArticalCard()
{

}



QString ArticalCard::getTname() const
{
    return tname;
}

void ArticalCard::setTname(const QString &value)
{
    tname = value;
}

QString ArticalCard::getTag() const
{
    return tag;
}

void ArticalCard::setTag(const QString &value)
{
    tag = value;
}

QDateTime ArticalCard::getDate() const
{
    return date;
}

void ArticalCard::setDate(const QDateTime &value)
{
    date = value;
}

bool ArticalCard::getCollected() const
{
    return collected;
}

void ArticalCard::setCollected(bool value)
{
    collected = value;
}

bool ArticalCard::getSupported() const
{
    return supported;
}

void ArticalCard::setSupported(bool value)
{
    supported = value;
}

int ArticalCard::getSupport() const
{
    return support;
}

void ArticalCard::setSupport(int value)
{
    support = value;
}

double ArticalCard::getHot() const
{
    return hot;
}

void ArticalCard::setHot(double value)
{
    hot = value;
}

QString ArticalCard::getTip() const
{
    return tip;
}

void ArticalCard::setTip(const QString &value)
{
    tip = value;
}

int ArticalCard::getTid() const
{
    return tid;
}

void ArticalCard::setTid(int value)
{
    tid = value;
}
