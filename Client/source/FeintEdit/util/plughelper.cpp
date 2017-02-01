#include "plughelper.h"

#include <util/json/objecttojson.h>

PlugHelper::PlugHelper()
{

}

void PlugHelper::savePlug(QByteArray path,QObject *obj)
{
    QFile file(path);
    if(file.open(QIODevice::WriteOnly|QIODevice::Text))
    {
        QJsonDocument doc=ObjectToJson::create(obj);
        file.write(doc.toJson());
        file.flush();
        file.close();
    }
}

bool PlugHelper::hasPlug(QByteArray path)
{
    QFile file(path);
    if(file.open(QIODevice::ReadOnly|QIODevice::Text))
        return true;
    else return false;
}
