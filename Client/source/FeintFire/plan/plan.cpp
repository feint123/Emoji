#include "plan.h"

Plan::Plan()
{

}

QString Plan::title() const
{
    return m_title;
}

QString Plan::content() const
{
    return m_content;
}

int Plan::level() const
{
    return m_level;
}

QDateTime Plan::startDate() const
{
    return m_startDate;
}

QDateTime Plan::endDate() const
{
    return m_endDate;
}

QString Plan::type() const
{
    return m_type;
}

int Plan::id() const
{
    return m_pid;
}

int Plan::status() const
{
    return m_status;
}

void Plan::setTitle(QString title)
{
    m_title = title;
}

void Plan::setContent(QString content)
{
    m_content = content;
}

void Plan::setLevel(int level)
{
    m_level = level;
}

void Plan::setStartDate(QDateTime startDate)
{
    m_startDate = startDate;
}

void Plan::setEndDate(QDateTime endDate)
{
    m_endDate = endDate;
}

void Plan::setType(QString type)
{
    m_type = type;
}

void Plan::setId(int pid)
{
    m_pid = pid;
}

void Plan::setStatus(int status)
{
    m_status = status;
}
