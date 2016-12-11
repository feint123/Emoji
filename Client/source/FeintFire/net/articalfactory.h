#ifndef ARTICALFACTORY_H
#define ARTICALFACTORY_H

#include <QJsonDocument>
#include <QObject>

#include <domain/artical.h>



class ArticalFactory:public QObject
{
public:
    ArticalFactory();
    void refreshArtical(long tid);
    void refreshComment(long cid);

private slots:
    void loadAritcalSuccess(QJsonDocument doc);
    void loadCommentSuccess(QJsonDocument doc);
signals:
    void loadArtical(Artical);
    void loadComment(QVariant);
};

#endif // ARTICALFACTORY_H
