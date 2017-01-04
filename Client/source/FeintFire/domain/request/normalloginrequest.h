#ifndef NORMALLOGINREQUEST_H
#define NORMALLOGINREQUEST_H

#include <QObject>

#include <QVariant>

class NormalLoginRequest:public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString acount READ acount WRITE setAcount)
    Q_PROPERTY(QString pwd READ pwd WRITE setPwd)
    Q_PROPERTY(QString mac READ mac WRITE setMac)
private:

    QString m_acount;

    QString m_pwd;

    QString m_mac;

public:
    NormalLoginRequest();
    NormalLoginRequest(const NormalLoginRequest& normal){
        this->setAcount(normal.acount());
        this->setMac(normal.mac());
        this->setPwd(normal.pwd());
    }

    QString acount() const;
    QString pwd() const;

    QString mac() const;

public slots:
    void setAcount(QString acount);
    void setPwd(QString pwd);
    void setMac(QString mac);
};
Q_DECLARE_METATYPE(NormalLoginRequest)
#endif // NORMALLOGINREQUEST_H
