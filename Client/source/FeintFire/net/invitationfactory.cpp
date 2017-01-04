#include "invitationfactory.h"
#include "networkhelper.h"

#include <QHttpPart>
#include <QJsonDocument>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QDebug>
#include <QJsonObject>
#include <QJsonArray>

#include <util/json/jsontoobject.h>

#include <domain/response/invitationcard.h>

using namespace feint ;
InvitationFactory::InvitationFactory()
{

}

void InvitationFactory::requestCard(QString type)
{
    NetworkHelper *helper=new NetworkHelper();
    connect(helper,SIGNAL(jsonOk(QJsonDocument)),this,SLOT(loadSuccess(QJsonDocument)));
    helper->getJsonData(tr("http://localhost:8080/index/totype/10001/1"),
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
        InvitationCard *card=JsonToObject::createObject<InvitationCard>(item);
   //     qDebug()<<"InvitationFactory[loadSuccess]:"<<card->tip();
        cardList.append(QVariant::fromValue(*card));
    }


    emit cardListLoadSuccess(cardList);
}

