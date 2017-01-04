#ifndef MARKCONTENT_H
#define MARKCONTENT_H

#include <QObject>
#include <qdatetime.h>



class MarkContent:public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString content READ content WRITE setContent)
    Q_PROPERTY(QDateTime date READ date WRITE setDate)
    Q_PROPERTY(QString title READ title WRITE setTitle)
public:
    MarkContent();
    QString content() const;

    QDateTime date() const;

    QString title() const;

public slots:
    void setContent(QString content);

    void setDate(QDateTime date);

    void setTitle(QString title);

private:

    QString m_content;
    QDateTime m_date;
    QString m_title;
};

#endif // MARKCONTENT_H
