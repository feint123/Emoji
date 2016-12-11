#include "invitationfactory.h"

#include <QHttpPart>
#include <QJsonDocument>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QDebug>
#include <QJsonObject>
#include <QJsonArray>

InvitationFactory::InvitationFactory()
{

}

void InvitationFactory::requestCard(QString type)
{
    QNetworkAccessManager *manager=new QNetworkAccessManager();
    connect(manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(loadSuccess(QNetworkReply*)));
    QNetworkRequest request;
    request.setUrl(QUrl("http://localhost:8080/index/totype/10001"));
    request.setHeader(QNetworkRequest::ContentTypeHeader,"application/json");
    QHttpMultiPart *multi=new QHttpMultiPart();
    QHttpPart part;
    QByteArray param=QString("{\"type\":\"%1\"}").arg(type).toUtf8();
    part.setBody(param);
    multi->append(part);
  //  manager->post(request,multi);
    manager->post(request,param);
}

void InvitationFactory::loadSuccess(QNetworkReply *reply)
{
    QJsonDocument doc=QJsonDocument::fromJson(reply->readAll());
    QJsonObject all=doc.object();
    QJsonObject data=all["data"].toObject();
    QJsonArray text=data["text"].toArray();
    QList<QVariant> cardList;
    for(int i=0;i<text.count();i++)
    {
        QJsonObject item=text.at(i).toObject();
        ArticalCard card;
        card.setTid(item["tid"].toInt());
        card.setTname(item["tname"].toString());
        card.setSupported(item["support"].toDouble());
        QString content=item["content"].toString().mid(0,140);
        card.setTip(content);
        card.setDate(QDateTime::fromMSecsSinceEpoch(item["date"].toDouble()));
        cardList.append(QVariant::fromValue(card));
    }

    emit cardListLoadSuccess(cardList);
}

