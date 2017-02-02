#ifndef STRINGUTIL_H
#define STRINGUTIL_H

#include <QString>



class StringUtil
{
public:
    StringUtil();
    static QString fitToLength(QString str, int length);
};

#endif // STRINGUTIL_H
