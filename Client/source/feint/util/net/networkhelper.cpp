#include "networkhelper.h"

#include <QHttpPart>

NetworkHelper::NetworkHelper()
{

}
void NetworkHelper::loadSuccess(QNetworkReply *reply)
{
    QJsonDocument doc=QJsonDocument::fromJson(reply->readAll());
    emit jsonOk(doc);
}

void NetworkHelper::onLoadImage(QNetworkReply *reply)
{
    QImage image;
    image.load(reply,"PNG");
    emit imageOk(image);
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

void NetworkHelper::imageUrl(QString url)
{
    QNetworkAccessManager *manager=new QNetworkAccessManager();
    connect(manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(onLoadImage(QNetworkReply*)));
    QNetworkRequest request;
    request.setUrl(QUrl(url));
    manager->get(request);
}

