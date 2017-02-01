#ifndef JSONDATA_H
#define JSONDATA_H

#include "jsontoobject.h"
#include "objecttojson.h"

#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QString>
#include <QDebug>


class JsonData
{
public:
    JsonData(const QByteArray& jsonPath="",const QByteArray& arrayName="");

    template<typename T>
    int addData(T* data){
        loadData();
        int currentId=1;
        QJsonObject root=currentDoc.object();
        if(!root["auto_id"].isNull())
        {
            currentId=root["auto_id"].toInt()+1;
        }
        root["auto_id"]=currentId;
        QJsonObject dataItem=ObjectToJson::create(data).object();
        dataItem["id"]=currentId;
        QJsonArray datas=root[arrayName].toArray();
        datas.append(dataItem);
        root[arrayName]=datas;
        currentDoc.setObject(root);
        saveData();
        return currentId;
    }

    template<typename T>
    void update(T* data, int id){
        loadData();
        QJsonObject root=currentDoc.object();
        QJsonArray datas=root[arrayName].toArray();
        for(int i=0;i<datas.count();i++)
        {
            if(datas.at(i).toObject()["id"].toInt()==id)
            {
                QJsonObject newItem=ObjectToJson::create(data).object();
                datas[i]=newItem;
            }
        }
        root[arrayName]=datas;
        currentDoc.setObject(root);
        saveData();
    }

    template<typename T>
    QJsonDocument createDoc(QList<T*> objs)
    {
        QJsonDocument doc;
        QJsonObject root;
        root["auto_id"]=objs.count();
        QJsonArray imgs;
        for(T *t:objs)
        {
            QJsonObject img=ObjectToJson::create(t).object();
            imgs.append(img);
        }
        root[arrayName]=imgs;
        doc.setObject(root);
        return doc;
    }

    template<typename T>
    QList<T*> selectAll()
    {
        loadData();
        QJsonObject root=currentDoc.object();
        QJsonArray datas=root[arrayName].toArray();
        QList<T*> tList;
        for(int i=0;i<datas.count();i++)
        {
            T *t=feint::JsonToObject::createObject<T>(datas.at(i).toObject());
            tList.append(t);
        }
        return tList;
    }

    int count();


    template<typename T>
    T* selectById(int id)
    {
        loadData();
        QJsonObject root=currentDoc.object();
        QJsonArray datas=root[arrayName].toArray();
        T* t=NULL;
        for(int i=datas.count()-1;i>=0;i--)
        {
            if(datas.at(i).toObject()["id"].toInt()==id)
                t=feint::JsonToObject::createObject<T>(datas.at(i).toObject());
        }
        return t;
    }

    template<typename T>
    T* selectByColumn(QByteArray column,QVariant value)
    {
        loadData();
        QJsonObject root=currentDoc.object();
        QJsonArray datas=root[arrayName].toArray();
        T* t=NULL;
        for(int i=datas.count()-1;i>=0;i--)
        {
            if(datas.at(i).toObject()[column].toVariant()==value)
                t=feint::JsonToObject::createObject<T>(datas.at(i).toObject());
        }
        return t;
    }

    template<typename T>
    QList<T*> selectAllByColumn(QByteArray column,QVariant value)
    {
        loadData();
        QList<T*> tList;
        QJsonObject root=currentDoc.object();
        QJsonArray datas=root[arrayName].toArray();
        T* t=NULL;
        for(int i=datas.count()-1;i>=0;i--)
        {
            if(datas.at(i).toObject()[column].toVariant()==value){
                t=feint::JsonToObject::createObject<T>(datas.at(i).toObject());
                tList.append(t);
            }
        }
        return tList;
    }
    template<typename T>
    T* addOnlyByColumn(QByteArray column,QVariant onlyValue,T* data)
    {

        T *t=selectByColumn<T>(column,onlyValue);
        if(t==NULL){
            addData<T>(data);
        }
    }



    template<typename T>
    T* selectFirst()
    {
        loadData();
        QJsonObject root=currentDoc.object();
        QJsonArray datas=root[arrayName].toArray();
        T* t=NULL;
        t=feint::JsonToObject::createObject<T>(datas.at(0).toObject());
        return t;
    }

    void deleteData(int id);
    QByteArray data();
    int autoId();

    template<typename T>
    QList<T*> sort(QString column)
    {
        QList<T*> tList;
        return tList;
    }

    int indexByColumn(QString column,QVariant value);

    template<typename T>
    QList<T*> desc(QList<T*> list){
        QList<T*> tList;
        for(int i=0;i<list.count();i++){
           tList.append(list.at(list.count()-i-1));
        }
        return tList;
    }

private:

    QByteArray jsonPath;
    QByteArray arrayName;
    QJsonDocument currentDoc;
    void loadData();
    void saveData();
};

#endif // JSONDATA_H
