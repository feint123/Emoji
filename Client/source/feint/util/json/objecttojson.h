#ifndef OBJECTTOJSON_H
#define OBJECTTOJSON_H

#include <QJsonDocument>
#include <QObject>



class ObjectToJson
{
public:
    ObjectToJson();
    static QJsonDocument create(QObject* obj);
};

#endif // OBJECTTOJSON_H
