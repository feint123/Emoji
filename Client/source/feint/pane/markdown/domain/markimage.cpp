#include "markimage.h"

MarkImage::MarkImage()
{

}

int MarkImage::id() const
{
    return m_id;
}

QString MarkImage::tip() const
{
    return m_tip;
}

QString MarkImage::path() const
{
    return m_path;
}

int MarkImage::width() const
{
    return m_width;
}

int MarkImage::height() const
{
    return m_height;
}

int MarkImage::posX() const
{
    return m_posX;
}

int MarkImage::posY() const
{
    return m_posY;
}

int MarkImage::anchor() const
{
    return m_anchor;
}

QString MarkImage::mark() const
{
    return m_mark;
}

void MarkImage::setId(int id)
{
    m_id = id;
}

void MarkImage::setTip(QString tip)
{
    m_tip = tip;
}

void MarkImage::setPath(QString path)
{
    m_path = path;
}

void MarkImage::setWidth(int width)
{
    m_width = width;
}

void MarkImage::setHeight(int height)
{
    m_height = height;
}

void MarkImage::setPosX(int posX)
{
    m_posX = posX;
}

void MarkImage::setPosY(int posY)
{
    m_posY = posY;
}

void MarkImage::setAnchor(int anchor)
{
    m_anchor = anchor;
}

void MarkImage::setMark(QString mark)
{
    m_mark = mark;
}
