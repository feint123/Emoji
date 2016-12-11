#include "invitationfactory.h"
#include "networkhelper.h"

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
    NetworkHelper *helper=new NetworkHelper();
    connect(helper,SIGNAL(jsonOk(QJsonDocument)),this,SLOT(loadSuccess(QJsonDocument doc)));
    helper->getJsonData(tr("http://localhost:8080/index/totype/10001"),
                       QString("{\"type\":\"%1\"}").arg(type));
}

void InvitationFactory::loadSuccess(QJsonDocument doc)
{
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

