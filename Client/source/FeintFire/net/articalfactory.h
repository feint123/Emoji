#ifndef ARTICALFACTORY_H
#define ARTICALFACTORY_H

#include <QJsonDocument>
#include <QObject>
#include <QVariant>

#include <domain/response/artical.h>



class ArticalFactory:public QObject
{
    Q_OBJECT
public:
    ArticalFactory();
    void refreshArtical(long tid);
    void refreshComment(long cid);

private slots:
    void loadAritcalSuccess(QJsonDocument doc);
    void loadCommentSuccess(QJsonDocument doc);
signals:
    void createArtical(Artical*);
};

#endif // ARTICALFACTORY_H
