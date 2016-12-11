#include "articalfactory.h"
#include "networkhelper.h"

#include <QJsonObject>

#include <domain/artical.h>

ArticalFactory::ArticalFactory()
{

}

void ArticalFactory::refreshArtical(long tid)
{
    NetworkHelper* helper=new NetworkHelper();
    connect(helper,SIGNAL(jsonOk(QJsonDocument)),this,SLOT(loadAritcalSuccess(QJsonDocument)));
    helper->getJsonData(tr("http://localhost:8080/artical/%1/10001").arg(tid),
                        QString(""));

}

void ArticalFactory::refreshComment(long cid)
{

}

void ArticalFactory::loadAritcalSuccess(QJsonDocument doc)
{
    QJsonObject root=doc.object();
    QJsonObject data=root["data"].toObject();
    Artical artical;
    artical.setTitle(data["title"].toString());
    artical.setContent(data["content"].toString());
    QJsonObject infoJ=data["info"].toObject();
    ArticalInfo info;
    info.setName(infoJ["name"].toString());
    info.setCreateTime(QDateTime::fromMSecsSinceEpoch(infoJ["create_time"].toDouble()));
    info.setSupported(infoJ["supported"].toInt());
    info.setCollected(infoJ["collected"].toInt());
    artical.setInfo(info);
    emit loadArtical(artical);
}

void ArticalFactory::loadCommentSuccess(QJsonDocument doc)
{

}
