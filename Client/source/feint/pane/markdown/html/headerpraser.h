#ifndef HEADERPRASER_H
#define HEADERPRASER_H

#include <QString>



class HeaderPraser
{
public:
    HeaderPraser();
    static QString praser(QString text);
private:
    QString hOneReg;
    QString hTwoReg;
};

#endif // HEADERPRASER_H
