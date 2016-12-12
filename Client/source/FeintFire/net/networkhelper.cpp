#include "networkhelper.h"

#include <QHttpPart>
#include <QDebug>
void NetworkHelper::loadSuccess(QNetworkReply *reply)
{
    QJsonDocument doc=QJsonDocument::fromJson(reply->readAll());
    emit jsonOk(doc);
}

NetworkHelper::NetworkHelper()
{

}

void NetworkHelper::getJsonData(QString url, QString inputData)
{
    qDebug()<<"start request resource";
    QNetworkAccessManager *manager=new QNetworkAccessManager();
    connect(manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(loadSuccess(QNetworkReply*)));
    QNetworkRequest request;
    request.setUrl(QUrl(url));
    request.setHeader(QNetworkRequest::ContentTypeHeader,"application/json");
    QHttpMultiPart *multi=new QHttpMultiPart();
    QHttpPart part;
    QByteArray param=QString(inputData).toUtf8();
    part.setBody(param);
    multi->append(part);
    manager->post(request,param);
}
