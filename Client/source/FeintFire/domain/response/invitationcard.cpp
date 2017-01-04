#include "invitationcard.h"

InvitationCard::InvitationCard()
{

}

int InvitationCard::tid() const
{
    return m_tid;
}

QString InvitationCard::tname() const
{
    return m_tname;
}

QString InvitationCard::label() const
{
    return m_label;
}

QDateTime InvitationCard::date() const
{
    return m_date;
}

int InvitationCard::collected() const
{
    return m_collected;
}

int InvitationCard::support() const
{
    return m_support;
}

double InvitationCard::hot() const
{
    return m_hot;
}

void InvitationCard::setTid(int tid)
{
    m_tid = tid;
}

void InvitationCard::setTname(QString tname)
{
    m_tname = tname;
}

void InvitationCard::setLabel(QString label)
{
    m_label = label;
}

void InvitationCard::setDate(QDateTime date)
{
    m_date = date;
}

void InvitationCard::setCollected(int collected)
{
    m_collected = collected;
}

void InvitationCard::setSupport(int support)
{
    m_support = support;
}

void InvitationCard::setHot(double hot)
{
    m_hot = hot;
}
