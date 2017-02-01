#ifndef MARKDOWNHOTKEY_H
#define MARKDOWNHOTKEY_H

#include <qobject.h>



class MarkdownHotKey:public QObject
{
    Q_OBJECT
    Q_PROPERTY(int id READ id WRITE setId)
    Q_PROPERTY(int key READ key WRITE setKey)
    Q_PROPERTY(QString value READ value WRITE setValue)
public:
    MarkdownHotKey();

    MarkdownHotKey(const MarkdownHotKey &key){
        setId(key.id());
        setKey(key.key());
        setValue(key.value());
    }

    int id() const;

    int key() const;

    QString value() const;

public slots:
    void setId(int id);

    void setKey(int key);

    void setValue(QString value);

private:

    int m_id;
    int m_key;
    QString m_value;
};
Q_DECLARE_METATYPE(MarkdownHotKey)
#endif // MARKDOWNHOTKEY_H
