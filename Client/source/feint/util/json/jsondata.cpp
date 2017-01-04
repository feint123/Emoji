#include "jsondata.h"
#include "objecttojson.h"

#include <QFile>
#include <QJsonArray>
#include <QJsonObject>


JsonData::JsonData(const QByteArray &jsonPath, const QByteArray &arrayName)
{
    this->jsonPath=jsonPath;
    this->arrayName=arrayName;
}

void JsonData::deleteData(int id)
{
    loadData();
    QJsonObject planObj=currentDoc.object();
    QJsonArray plans=planObj["plans"].toArray();
    for(int i=0;i<plans.count();i++){
        int pid=plans.at(i).toObject()["id"].toInt();
        if(pid==id)
            plans.removeAt(i);
    }
    planObj["plans"]=plans;
    currentDoc.setObject(planObj);
    saveData();
}

QByteArray JsonData::data()
{
    loadData();
    return currentDoc.toJson();
}

int JsonData::autoId()
{
    loadData();
     QJsonObject root=currentDoc.object();
     return root["auto_id"].toInt();
}

void JsonData::loadData()
{
    QFile file(jsonPath);
    if(file.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        currentDoc=QJsonDocument::fromJson(file.readAll());

        file.close();
    }
}

void JsonData::saveData()
{
    QFile file(jsonPath);
    if(file.open(QIODevice::WriteOnly|QIODevice::Text))
    {
        file.write(currentDoc.toJson());

        file.flush();

        file.close();
    }
}
