#include "markimagesimple.h"

MarkImageSimple::MarkImageSimple()
{

}

QString MarkImageSimple::tip() const
{
    return m_tip;
}

QString MarkImageSimple::path() const
{
    return m_path;
}

int MarkImageSimple::width() const
{
    return m_width;
}

int MarkImageSimple::height() const
{
    return m_height;
}

QDateTime MarkImageSimple::date() const
{
    return m_date;
}

void MarkImageSimple::setTip(QString tip)
{
    m_tip = tip;
}

void MarkImageSimple::setPath(QString path)
{
    m_path = path;
}

void MarkImageSimple::setWidth(int width)
{
    m_width = width;
}

void MarkImageSimple::setHeight(int height)
{
    m_height = height;
}

void MarkImageSimple::setDate(QDateTime date)
{
    m_date = date;
}
