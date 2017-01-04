#ifndef ARTICALINFO_H
#define ARTICALINFO_H

#include <qdatetime.h>



class ArticalInfo
{
public:
    ArticalInfo();
    int getCollected() const;
    void setCollected(int value);

    int getSupported() const;
    void setSupported(int value);

    long getRead() const;
    void setRead(long value);



    QString getName() const;
    void setName(const QString &value);

    QDateTime getCreateTime() const;
    void setCreateTime(const QDateTime &value);

private:
    QString name;
    QDateTime createTime;
    long read;
    int supported;
    int collected;
};

#endif // ARTICALINFO_H
