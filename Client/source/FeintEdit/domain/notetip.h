#ifndef NOTETIP_H
#define NOTETIP_H

#include <QObject>
#include <qdatetime.h>

#include <QVariant>

class NoteTip:public QObject
{
    Q_OBJECT
    Q_PROPERTY(int id READ id WRITE setId)
    Q_PROPERTY(QString title READ title WRITE setTitle)
    Q_PROPERTY(QString image READ image WRITE setImage)
    Q_PROPERTY(QString tip READ tip WRITE setTip)
    Q_PROPERTY(QDateTime updateDate READ updateDate WRITE setUpdateDate)
    Q_PROPERTY(QString fileName READ fileName WRITE setFileName )
    Q_PROPERTY(QString notebook READ notebook WRITE setNotebook )
public:
    NoteTip();

    NoteTip(const NoteTip &note)
    {
        construtor(note);
    }

    void operator =(const NoteTip &note)
    {
        construtor(note);
    }

    QString title() const;

    QString image() const;

    QString tip() const;

    QDateTime updateDate() const;

    int id() const;

    QString fileName() const;

    QString notebook() const;

public slots:
    void setTitle(QString title);

    void setImage(QString image);

    void setTip(QString tip);

    void setUpdateDate(QDateTime updateDate);

    void setId(int id);

    void setFileName(QString fileName);

    void setNotebook(QString notebook);

private:

    QString m_title;
    QString m_image;
    QString m_tip;
    QDateTime m_updateDate;


    int m_id;
    QString m_fileName;
    QString m_notebook;

    void construtor(const NoteTip &note){
        setId(note.id());
        setImage(note.image());
        setTip(note.tip());
        setTitle(note.title());
        setUpdateDate(note.updateDate());
        setFileName(note.fileName());
        setNotebook(note.notebook());
    }
};
Q_DECLARE_METATYPE(NoteTip)
#endif // NOTETIP_H
