#ifndef REQUEST_H
#define REQUEST_H

#include <QObject>
#include <QVariant>



class Request:public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString token READ token WRITE setToken)
    Q_PROPERTY(QVariant data READ data WRITE setData)
public:
    Request();
    QString token() const;

    QVariant data() const;

public slots:
    void setToken(QString token);

    void setData(QVariant data);

private:
    QString m_token;
    QVariant m_data;
};

#endif // REQUEST_H
