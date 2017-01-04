#ifndef MARKDOWNCACHE_H
#define MARKDOWNCACHE_H

#include <QObject>
#include <qdatetime.h>



class MarkDownCache:public QObject
{
    Q_OBJECT
    Q_PROPERTY(int id READ id WRITE setId)
    Q_PROPERTY(QString content READ content WRITE setContent)
    Q_PROPERTY(QDateTime date READ date WRITE setDate)
    Q_PROPERTY(QString title READ title WRITE setTitle)
public:
    MarkDownCache();
    int id() const;

    QString content() const;

    QDateTime date() const;

    QString title() const;

public slots:
    void setId(int id);

    void setContent(QString content);

    void setDate(QDateTime date);

    void setTitle(QString title);

private:

    int m_id;
    QString m_content;
    QDateTime m_date;
    QString m_title;
};

#endif // MARKDOWNCACHE_H
