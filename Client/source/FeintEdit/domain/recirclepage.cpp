#include "recirclepage.h"

RecirclePage::RecirclePage()
{

}

int RecirclePage::id() const
{
    return m_id;
}

QString RecirclePage::fileName() const
{
    return m_fileName;
}

QString RecirclePage::name() const
{
    return m_name;
}

int RecirclePage::type() const
{
    return m_type;
}

QString RecirclePage::bookFile() const
{
    return m_bookFile;
}

void RecirclePage::setId(int id)
{
    m_id = id;
}

void RecirclePage::setFileName(QString fileName)
{
    m_fileName = fileName;
}

void RecirclePage::setName(QString name)
{
    m_name = name;
}

void RecirclePage::setType(int type)
{
    m_type = type;
}

void RecirclePage::setBookFile(QString bookFile)
{
    m_bookFile = bookFile;
}
