#ifndef NOTEBOOK_H
#define NOTEBOOK_H

#include <QObject>
#include <qdatetime.h>



class NoteBook:public QObject
{
    Q_OBJECT
    Q_PROPERTY(int id READ id WRITE setId)
    Q_PROPERTY(QString name READ name WRITE setName)
    Q_PROPERTY(QString fileName READ fileName WRITE setFileName)
    Q_PROPERTY(QDateTime createDate READ createDate WRITE setCreateDate)
    Q_PROPERTY(QDateTime updateDate READ updateDate WRITE setUpdateDate)
public:
    NoteBook();

    NoteBook(const NoteBook& book)
    {
        setId(book.id());
        setName(book.name());
        setFileName(book.fileName());
        setCreateDate(book.createDate());
        setUpdateDate(book.updateDate());
    }

    int id() const;

    QString name() const;

    QString fileName() const;

    QDateTime createDate() const;

    QDateTime updateDate() const;

public slots:
    void setId(int id);

    void setName(QString name);

    void setFileName(QString fileName);

    void setCreateDate(QDateTime createDate);

    void setUpdateDate(QDateTime updateDate);

private:
    int m_id;
    QString m_name;
    QString m_fileName;
    QDateTime m_createDate;
    QDateTime m_updateDate;
};
Q_DECLARE_METATYPE(NoteBook)
#endif // NOTEBOOK_H
