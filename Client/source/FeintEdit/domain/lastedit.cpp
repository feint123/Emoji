#include "lastedit.h"

LastEdit::LastEdit()
{

}

int LastEdit::id() const
{
    return m_id;
}

QString LastEdit::title() const
{
    return m_title;
}

QString LastEdit::tip() const
{
    return m_tip;
}

QString LastEdit::file() const
{
    return m_file;
}

QDateTime LastEdit::updateDate() const
{
    return m_updateDate;
}

void LastEdit::setId(int id)
{
    m_id = id;
}

void LastEdit::setTitle(QString title)
{
    m_title = title;
}

void LastEdit::setTip(QString tip)
{
    m_tip = tip;
}

void LastEdit::setFile(QString file)
{
    m_file = file;
}

void LastEdit::setUpdateDate(QDateTime updateDate)
{
    m_updateDate = updateDate;
}
