#ifndef MARKIMAGESIMPLE_H
#define MARKIMAGESIMPLE_H

#include <QObject>
#include <qdatetime.h>



class MarkImageSimple:public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString tip READ tip WRITE setTip)
    Q_PROPERTY(QString path READ path WRITE setPath)
    Q_PROPERTY(int width READ width WRITE setWidth)
    Q_PROPERTY(int height READ height WRITE setHeight)
    Q_PROPERTY(QDateTime date READ date WRITE setDate)
public:
    MarkImageSimple();

    QString tip() const;

    QString path() const;

    int width() const;

    int height() const;

    QDateTime date() const;

public slots:
    void setTip(QString tip);

    void setPath(QString path);

    void setWidth(int width);

    void setHeight(int height);

    void setDate(QDateTime date);

private:

    QString m_tip;
    QString m_path;
    int m_width;
    int m_height;
    QDateTime m_date;
};

#endif // MARKIMAGESIMPLE_H
