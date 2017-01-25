#ifndef IMAGE_H
#define IMAGE_H

#include <QObject>
#include <qdatetime.h>

#include<QDebug>

class Image:public QObject
{
    Q_OBJECT
    Q_PROPERTY(int id READ id WRITE setId)
    Q_PROPERTY(QString alt READ alt WRITE setAlt)
    Q_PROPERTY(int width READ width WRITE setWidth)
    Q_PROPERTY(int height READ height WRITE setHeight)
    Q_PROPERTY(QString file READ file WRITE setFile)
    Q_PROPERTY(int uid READ uid WRITE setUid)
    Q_PROPERTY(QString tempPath READ tempPath WRITE setTempPath)
    Q_PROPERTY(QDateTime insertDate READ insertDate WRITE setInsertDate)
public:
    Image();
    Image(const Image &image){
        setId(image.id());
        setAlt(image.alt());
        setWidth(image.width());
        setHeight(image.height());
        setFile(image.file());
        setUid(image.uid());
        setTempPath(image.tempPath());
        setInsertDate(image.insertDate());
    }

    void operator =(const Image &image){
        setId(image.id());
        setAlt(image.alt());
        setWidth(image.width());
        setHeight(image.height());
        setFile(image.file());
        setUid(image.uid());
        setTempPath(image.tempPath());
        setInsertDate(image.insertDate());
    }

    int id() const;

    QString alt() const;

    int width() const;

    int height() const;

    QString file() const;

    int uid() const;

    QString tempPath() const;

    QDateTime insertDate() const;

public slots:
    void setId(int id);

    void setAlt(QString alt);

    void setWidth(int width);

    void setHeight(int height);

    void setFile(QString file);

    void setUid(int uid);

    void setTempPath(QString tempPath);

    void setInsertDate(QDateTime insertDate);

private:

    int m_id;
    QString m_alt;
    int m_width;
    int m_height;
    QString m_file;
    int m_uid;
    QString m_tempPath;
    QDateTime m_insertDate;
};
Q_DECLARE_METATYPE(Image)

#endif // IMAGE_H
