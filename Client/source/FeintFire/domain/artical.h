#ifndef ARTICAL_H
#define ARTICAL_H

#include "articalinfo.h"



class Artical
{
public:
    Artical();
    ArticalInfo getInfo() const;
    void setInfo(const ArticalInfo &value);

    QString getContent() const;
    void setContent(const QString &value);

    QString getTitle() const;
    void setTitle(const QString &value);

private:
    QString title;
    QString content;
    ArticalInfo info;

};

#endif // ARTICAL_H
