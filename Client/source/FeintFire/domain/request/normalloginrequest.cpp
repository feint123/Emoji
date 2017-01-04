#include "normalloginrequest.h"

NormalLoginRequest::NormalLoginRequest()
{

}

QString NormalLoginRequest::acount() const
{
    return m_acount;
}

QString NormalLoginRequest::pwd() const
{
    return m_pwd;
}

QString NormalLoginRequest::mac() const
{
    return m_mac;
}

void NormalLoginRequest::setAcount(QString acount)
{
    m_acount = acount;
}

void NormalLoginRequest::setPwd(QString pwd)
{
    m_pwd = pwd;
}

void NormalLoginRequest::setMac(QString mac)
{
    m_mac = mac;
}
