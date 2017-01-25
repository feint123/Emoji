#include "image.h"

Image::Image()
{

}

int Image::id() const
{
    return m_id;
}

QString Image::alt() const
{
    return m_alt;
}

int Image::width() const
{
    return m_width;
}

int Image::height() const
{
    return m_height;
}

QString Image::file() const
{
    return m_file;
}

int Image::uid() const
{
    return m_uid;
}

QString Image::tempPath() const
{
    return m_tempPath;
}

QDateTime Image::insertDate() const
{
    return m_insertDate;
}

void Image::setId(int id)
{
    m_id = id;
}

void Image::setAlt(QString alt)
{
    m_alt = alt;
}

void Image::setWidth(int width)
{
    m_width = width;
}

void Image::setHeight(int height)
{
    m_height = height;
}

void Image::setFile(QString file)
{
    m_file = file;
}

void Image::setUid(int uid)
{
    m_uid = uid;
}

void Image::setTempPath(QString tempPath)
{
    m_tempPath = tempPath;
}

void Image::setInsertDate(QDateTime insertDate)
{
    m_insertDate = insertDate;
}
