#ifndef RECIRCLEPAGE_H
#define RECIRCLEPAGE_H

#include <qobject.h>



class RecirclePage:public QObject
{

    Q_OBJECT
    Q_PROPERTY(int id READ id WRITE setId)
    Q_PROPERTY(QString fileName READ fileName WRITE setFileName)
    Q_PROPERTY(QString name READ name WRITE setName)
    Q_PROPERTY(int type READ type WRITE setType)
    Q_PROPERTY(QString bookFile READ bookFile WRITE setBookFile)

public:
    enum TYPE{
        BOOK,
        NOTE,
    };

    RecirclePage();
    RecirclePage(const RecirclePage &page)
    {
        setId(page.id());
        setFileName(page.fileName());
        setName(page.name());
        setType(page.type());
        setBookFile(page.bookFile());
    }

    int id() const;

    QString fileName() const;

    QString name() const;

    int type() const;

    QString bookFile() const;

public slots:
    void setId(int id);

    void setFileName(QString fileName);

    void setName(QString name);

    void setType(int type);

    void setBookFile(QString bookFile);

private:
    int m_id;
    QString m_fileName;
    QString m_name;
    int m_type;
    QString m_bookFile;
};
Q_DECLARE_METATYPE(RecirclePage)
#endif // RECIRCLEPAGE_H
