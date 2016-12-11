#ifndef INVITATIONFACTORY_H
#define INVITATIONFACTORY_H

#include <QNetworkReply>
#include <QString>
#include <QObject>
#include <domain/articalcard.h>



class InvitationFactory:public QObject
{
    Q_OBJECT
public:
    InvitationFactory();
    void requestCard(QString type);
signals:
    void cardListLoadSuccess(QList<QVariant>);
private slots:
    void loadSuccess(QNetworkReply * reply);

};

#endif // INVITATIONFACTORY_H