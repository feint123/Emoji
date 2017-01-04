#ifndef PLAN_H
#define PLAN_H

#include <QObject>
#include <qdatetime.h>



class Plan:public QObject
{
    Q_OBJECT
    Q_PROPERTY(int id READ id WRITE setId)
    Q_PROPERTY(QString title READ title WRITE setTitle)
    Q_PROPERTY(QString content READ content WRITE setContent)
    Q_PROPERTY(int level READ level WRITE setLevel)
    Q_PROPERTY(QDateTime startDate READ startDate WRITE setStartDate)
    Q_PROPERTY(QDateTime endDate READ endDate WRITE setEndDate)
    Q_PROPERTY(QString type READ type WRITE setType)
    Q_PROPERTY(int status READ status WRITE setStatus)


public:

    Plan();
    QString title() const;
    QString content() const;

    int level() const;

    QDateTime startDate() const;

    QDateTime endDate() const;

    QString type() const;

    int id() const;

    int status() const;

public slots:
    void setTitle(QString title);
    void setContent(QString content);
    void setLevel(int level);
    void setStartDate(QDateTime startDate);
    void setEndDate(QDateTime endDate);
    void setType(QString type);
    void setId(int id);

    void setStatus(int status);

private:
    QString m_title;

    QString m_content;

    int m_level;

    QDateTime m_startDate;

    QDateTime m_endDate;

    QString m_type;
    int m_pid;
    int m_status;
};

#endif // PLAN_H
