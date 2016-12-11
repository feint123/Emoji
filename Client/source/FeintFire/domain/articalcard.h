#ifndef ARTICALCARD_H
#define ARTICALCARD_H
#include <QDate>
#include <QVariant>

class ArticalCard
{
public:
    ArticalCard();


    QString getTname() const;
    void setTname(const QString &value);

    QString getTag() const;
    void setTag(const QString &value);

    QDateTime getDate() const;
    void setDate(const QDateTime &value);

    bool getCollected() const;
    void setCollected(bool value);

    bool getSupported() const;
    void setSupported(bool value);

    int getSupport() const;
    void setSupport(int value);

    double getHot() const;
    void setHot(double value);

    QString getTip() const;
    void setTip(const QString &value);

    int getTid() const;
    void setTid(int value);

private:
    int tid;
    QString tip;
    QString tname;
    QString tag;
    QDateTime date;
    bool collected;
    bool supported;
    int support;
    double hot;
};
Q_DECLARE_METATYPE(ArticalCard)
#endif // ARTICALCARD_H
