#ifndef FOBJECT_H
#define FOBJECT_H

#include <QByteArray>
#include <QObject>



class FObject:public QObject
{
public:
    FObject();
    QByteArray toString();
};

#endif // FOBJECT_H
