#include "articalinfo.h"

ArticalInfo::ArticalInfo()
{

}

int ArticalInfo::getCollected() const
{
    return collected;
}

void ArticalInfo::setCollected(int value)
{
    collected = value;
}

int ArticalInfo::getSupported() const
{
    return supported;
}

void ArticalInfo::setSupported(int value)
{
    supported = value;
}

long ArticalInfo::getRead() const
{
    return read;
}

void ArticalInfo::setRead(long value)
{
    read = value;
}



QString ArticalInfo::getName() const
{
    return name;
}

void ArticalInfo::setName(const QString &value)
{
    name = value;
}

QDateTime ArticalInfo::getCreateTime() const
{
    return createTime;
}

void ArticalInfo::setCreateTime(const QDateTime &value)
{
    createTime = value;
}
