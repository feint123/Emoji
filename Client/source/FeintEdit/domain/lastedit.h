#ifndef LASTEDIT_H
#define LASTEDIT_H

#include <QDateTime>
#include <qobject.h>



class LastEdit:public QObject
{
    Q_OBJECT
    Q_PROPERTY(int id READ id WRITE setId)
    Q_PROPERTY(QString title READ title WRITE setTitle)
    Q_PROPERTY(QString tip READ tip WRITE setTip)
    Q_PROPERTY(QString file READ file WRITE setFile)
    Q_PROPERTY(QString bookFile READ bookFile WRITE setBookFile)
    Q_PROPERTY(QDateTime updateDate READ updateDate WRITE setUpdateDate)
public:
    LastEdit();

    LastEdit(const LastEdit &last)
    {
        setId(last.id());
        setTip(last.tip());
        setTitle(last.title());
        setUpdateDate(last.updateDate());
        setFile(last.file());
        setBookFile(last.bookFile());
    }

    int id() const;

    QString title() const;

    QString tip() const;

    QString file() const;

    QDateTime updateDate() const;

    QString bookFile() const
    {
        return m_bookFile;
    }

public slots:
    void setId(int id);

    void setTitle(QString title);

    void setTip(QString tip);

    void setFile(QString file);

    void setUpdateDate(QDateTime updateDate);

    void setBookFile(QString bookFile)
    {
        m_bookFile = bookFile;
    }

private:
    int m_id;
    QString m_title;
    QString m_tip;
    QString m_file;
    QDateTime m_updateDate;
    QString m_bookFile;
};
Q_DECLARE_METATYPE(LastEdit)
#endif // LASTEDIT_H
