#include "card.h"

Card::Card()
{

}

long Card::getTid() const
{
    return tid;
}

void Card::setTid(long value)
{
    tid = value;
}

QString Card::getTname() const
{
    return tname;
}

void Card::setTname(const QString &value)
{
    tname = value;
}

QString Card::getTip() const
{
    return tip;
}

void Card::setTip(const QString &value)
{
    tip = value;
}

QDate Card::getDate() const
{
    return date;
}

void Card::setDate(const QDate &value)
{
    date = value;
}

float Card::getHot() const
{
    return hot;
}

void Card::setHot(float value)
{
    hot = value;
}
