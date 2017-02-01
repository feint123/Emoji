#ifndef PLUGHELPER_H
#define PLUGHELPER_H

#include <QByteArray>
#include <qfile.h>
#include <qjsondocument.h>

#include <util/json/jsontoobject.h>



class PlugHelper
{
public:
    PlugHelper();

    template<typename T>
    static T* loadPlug(QByteArray path){
        QJsonDocument doc;
        QFile file(path);
        if(file.open(QIODevice::ReadOnly|QIODevice::Text))
        {
            doc=QJsonDocument::fromJson(file.readAll());
        }

        file.close();

        return feint::JsonToObject::createObject<T>(doc.object());
    }

    static void savePlug(QByteArray path, QObject *obj);

    static bool hasPlug(QByteArray path);
};

#endif // PLUGHELPER_H
