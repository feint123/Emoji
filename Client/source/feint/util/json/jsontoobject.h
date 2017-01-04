#ifndef JSONTOOBJECT_H
#define JSONTOOBJECT_H

#include <QByteArray>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QMetaObject>
#include <QMetaObject>
#include <QMetaProperty>

namespace feint{

class JsonToObject
{
public:
    JsonToObject();
//    template<typename T>
//     QObject* create(const QByteArray &json){
//        this->doc=QJsonDocument::fromJson(json);
//        if(doc.isObject()){
//            return createObject<T>(doc.object());
//        }
//        if(doc.isArray()){
//            return createObjectList<T>();
//        }

//    }
    template<typename T>
    static T *createObject(QJsonObject jsonObj){
        T *t = new T;
        const QMetaObject *meta=t->metaObject();
        int count = meta->propertyCount();
        for(int i=0;i<count;i++)
        {
            QMetaProperty property=meta->property(i);

            property.write(t,jsonObj.toVariantHash().value(
                               property.name()));
        }

        return t;
    }

//    template<typename T>
//    QList<T*> createObjectList(){
//        QJsonArray jsonArray=doc.array();
//        QList<T*> objList;
//        for(int i=0;i<jsonArray.count();i++){
//            objList.append(createObject<T>(jsonArray.at(i).toObject()));
//        }
//        return jsonArray;
//    }

//    QJsonDocument doc;
};
}

#endif // JSONTOOBJECT_H
