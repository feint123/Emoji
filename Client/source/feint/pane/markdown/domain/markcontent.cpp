#include "markcontent.h"

MarkContent::MarkContent()
{

}

QString MarkContent::content() const
{
    return m_content;
}

QDateTime MarkContent::date() const
{
    return m_date;
}

QString MarkContent::title() const
{
    return m_title;
}

void MarkContent::setContent(QString content)
{
    m_content = content;
}

void MarkContent::setDate(QDateTime date)
{
    m_date = date;
}

void MarkContent::setTitle(QString title)
{
    m_title = title;
}
