#include "uploadartical.h"

UploadArtical::UploadArtical()
{

}

QString UploadArtical::content() const
{
    return m_content;
}

QString UploadArtical::title() const
{
    return m_title;
}

QString UploadArtical::tip() const
{
    return m_tip;
}

QString UploadArtical::type() const
{
    return m_type;
}

QString UploadArtical::label() const
{
    return m_label;
}


void UploadArtical::setContent(QString content)
{
    m_content = content;
}

void UploadArtical::setTitle(QString title)
{
    m_title = title;
}

void UploadArtical::setTip(QString tip)
{
    m_tip = tip;
}

void UploadArtical::setType(QString type)
{
    m_type = type;
}

void UploadArtical::setLabel(QString label)
{
    m_label = label;
}
