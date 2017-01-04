#include "objecttojson.h"

#include <QJsonObject>
#include <QMetaProperty>
#include <QDate>
#include <QDebug>
ObjectToJson::ObjectToJson()
{

}

QJsonDocument ObjectToJson::create(QObject *obj)
{
    QJsonDocument doc;
    QJsonObject jsonobj;
    const QMetaObject *meta=obj->metaObject();
    int count = meta->propertyCount();
    for(int i=0;i<count;i++)
    {
        QDateTime time;
        QMetaProperty property=meta->property(i);
        QVariant var=property.read(obj);
        if (QString(property.name())==QString("objectName")) continue;
        switch(property.type()){
        case QVariant::Double:
            jsonobj.insert(property.name(),var.toDouble());
            break;
        case QVariant::String:
            jsonobj.insert(property.name(),var.toString());
            break;
        case QVariant::Int:
            jsonobj.insert(property.name(),var.toInt());
            break;
        case QVariant::Bool:
            jsonobj.insert(property.name(),var.toBool());
        case QVariant::DateTime:
            jsonobj.insert(property.name(),var.toDateTime().toString("yyyy/MM/dd HH:mm"));
            break;
        default:
            jsonobj.insert(property.name(),ObjectToJson::create(qvariant_cast<QObject *>(var)).object());
            break;
        }
    }
    doc.setObject(jsonobj);
    return doc;
}
