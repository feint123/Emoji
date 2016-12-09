#ifndef CARD_H
#define CARD_H

#include <QDate>
#include <QVariant>


class Card
{

public:
    Card();
    long getTid() const;
    void setTid(long value);

    QString getTname() const;
    void setTname(const QString &value);

    QString getTip() const;
    void setTip(const QString &value);

    QDate getDate() const;
    void setDate(const QDate &value);

    float getHot() const;
    void setHot(float value);

private :
    long tid;
    QString tname;
    QString tip;
    QDate date;
    float hot;
};
Q_DECLARE_METATYPE(Card)
#endif // CARD_H

