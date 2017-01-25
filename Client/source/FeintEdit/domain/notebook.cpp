#include "notebook.h"

NoteBook::NoteBook()
{

}

int NoteBook::id() const
{
    return m_id;
}

QString NoteBook::name() const
{
    return m_name;
}

QString NoteBook::fileName() const
{
    return m_fileName;
}

QDateTime NoteBook::createDate() const
{
    return m_createDate;
}

QDateTime NoteBook::updateDate() const
{
    return m_updateDate;
}

void NoteBook::setId(int id)
{
    m_id = id;
}

void NoteBook::setName(QString name)
{
    m_name = name;
}

void NoteBook::setFileName(QString fileName)
{
    m_fileName = fileName;
}

void NoteBook::setCreateDate(QDateTime createDate)
{
    m_createDate = createDate;
}

void NoteBook::setUpdateDate(QDateTime updateDate)
{
    m_updateDate = updateDate;
}
