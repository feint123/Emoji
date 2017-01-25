#ifndef NETWORKHELPER_H
#define NETWORKHELPER_H

#include <QImage>
#include <QJsonDocument>
#include <QNetworkReply>
#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>


class NetworkHelper:public QObject
{
    Q_OBJECT
public:
    NetworkHelper();
    void getJsonData(QString url,QString inputData);

    void imageUrl(QString url);
signals:
    void jsonOk(QJsonDocument doc);
    void imageOk(QImage image);
private slots:
    void loadSuccess(QNetworkReply* reply);
    void onLoadImage(QNetworkReply* reply);

};

#endif // NETWORKHELPER_H
