#include "request.h"

Request::Request()
{

}

QString Request::token() const
{
    return m_token;
}

QVariant Request::data() const
{
    return m_data;
}

void Request::setToken(QString token)

{
    m_token = token;
}

void Request::setData(QVariant data)
{
    m_data = data;
}
