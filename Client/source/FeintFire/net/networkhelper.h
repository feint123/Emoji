#ifndef NETWORKHELPER_H
#define NETWORKHELPER_H

#include <QJsonDocument>
#include <QNetworkReply>



class NetworkHelper:public QObject
{
    Q_OBJECT
signals:
    void jsonOk(QJsonDocument doc);
private slots:
    void loadSuccess(QNetworkReply* reply);
public:
    NetworkHelper();
    void getJsonData(QString url,QString inputData);
};

#endif // NETWORKHELPER_H
