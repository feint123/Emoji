#include "notetip.h"

NoteTip::NoteTip()
{

}

QString NoteTip::title() const
{
    return m_title;
}

QString NoteTip::image() const
{
    return m_image;
}

QString NoteTip::tip() const
{
    return m_tip;
}

QDateTime NoteTip::updateDate() const
{
    return m_updateDate;
}

int NoteTip::id() const
{
    return m_id;
}

QString NoteTip::fileName() const
{
    return m_fileName;
}

QString NoteTip::notebook() const
{
    return m_notebook;
}

void NoteTip::setTitle(QString title)
{
    m_title = title;
}

void NoteTip::setImage(QString image)
{
    m_image = image;
}

void NoteTip::setTip(QString tip)
{
    QString _tip=tip.remove("\n");
    tip=_tip.length()>43?(_tip.mid(0,40)+"..."):_tip;
    m_tip = tip;
}

void NoteTip::setUpdateDate(QDateTime updateDate)
{
    m_updateDate = updateDate;
}

void NoteTip::setId(int id)
{
    m_id = id;
}

void NoteTip::setFileName(QString fileName)
{
    m_fileName = fileName;
}

void NoteTip::setNotebook(QString notebook)
{
    m_notebook = notebook;
}
