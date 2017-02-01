#include "markdownhotkey.h"

MarkdownHotKey::MarkdownHotKey()
{

}

int MarkdownHotKey::id() const
{
    return m_id;
}

int MarkdownHotKey::key() const
{
    return m_key;
}

QString MarkdownHotKey::value() const
{
    return m_value;
}

void MarkdownHotKey::setId(int id)
{
    m_id = id;
}

void MarkdownHotKey::setKey(int key)
{
    m_key = key;
}

void MarkdownHotKey::setValue(QString value)
{
    m_value = value;
}
