#include "markdowncache.h"

MarkDownCache::MarkDownCache()
{

}

int MarkDownCache::id() const
{
    return m_id;
}

QString MarkDownCache::content() const
{
    return m_content;
}

QDateTime MarkDownCache::date() const
{
    return m_date;
}

QString MarkDownCache::title() const
{
    return m_title;
}

void MarkDownCache::setId(int id)
{
    m_id = id;
}

void MarkDownCache::setContent(QString content)
{
    m_content = content;
}

void MarkDownCache::setDate(QDateTime date)
{
    m_date = date;
}

void MarkDownCache::setTitle(QString title)
{
    m_title = title;
}
