#ifndef NETWORKHELPER_H
#define NETWORKHELPER_H

#include <QJsonDocument>
#include <QNetworkReply>
#include <QObject>



class NetworkHelper:public QObject
{
    Q_OBJECT
public:
    NetworkHelper();
    void getJsonData(QString url,QString inputData);
signals:
    void jsonOk(QJsonDocument doc);
private slots:
    void loadSuccess(QNetworkReply* reply);


};

#endif // NETWORKHELPER_H
