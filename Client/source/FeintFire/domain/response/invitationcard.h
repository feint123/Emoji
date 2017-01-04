#ifndef INVITATIONCARD_H
#define INVITATIONCARD_H

#include <QObject>
#include <qdatetime.h>



class InvitationCard:public QObject
{
    Q_OBJECT
    Q_PROPERTY(int tid READ tid WRITE setTid)
    Q_PROPERTY(QString tname READ tname WRITE setTname)
    Q_PROPERTY(QString label READ label WRITE setLabel)
    Q_PROPERTY(QDateTime date READ date WRITE setDate)
    Q_PROPERTY(int collected READ collected WRITE setCollected)
    Q_PROPERTY(int support READ support WRITE setSupport)
    Q_PROPERTY(double hot READ hot WRITE setHot)
    Q_PROPERTY(QString tip READ tip WRITE setTip)
private:
    int m_tid;

    QString m_tname;

    QString m_label;

    QDateTime m_date;

    int m_collected;

    int m_support;

    double m_hot;

    QString m_tip;

public:
    InvitationCard();
    InvitationCard(const InvitationCard& card){
        this->setDate(card.date());
        this->setTip(card.tip());
        this->setHot(card.hot());
        this->setTid(card.tid());
        this->setTname(card.tname());
        this->setSupport(card.support());
        this->setCollected(card.collected());
        this->setLabel(card.label());
    }

    int tid() const;
    QString tname() const;

    QString label() const;

    QDateTime date() const;

    int collected() const;

    int support() const;

    double hot() const;

    QString tip() const
    {
        return m_tip;
    }

public slots:
    void setTid(int tid);
    void setTname(QString tname);
    void setLabel(QString label);
    void setDate(QDateTime date);
    void setCollected(int collected);
    void setSupport(int support);
    void setHot(double hot);
    void setTip(QString tip)
    {
        m_tip = tip;
    }
};
Q_DECLARE_METATYPE(InvitationCard)
#endif // INVITATIONCARD_H
