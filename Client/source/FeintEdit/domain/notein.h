#ifndef NOTEIN_H
#define NOTEIN_H

#include <QHash>
#include <QImage>



class NoteIn
{
public:
    NoteIn();

    QString getImageR() const;
    void setImageR(const QString &value);

    QString getNote() const;
    void setNote(const QString &value);

    void addImage(QString name,QImage img);
    QHash<QString, QImage> getImages() const;

    QString getNoteName() const;
    void setNoteName(const QString &value);

    QString getImageRName() const;
    void setImageRName(const QString &value);

private:
    QHash<QString,QImage> images;
    QString note;
    QString imageR;
    QString noteName;
    QString imageRName;
};

#endif // NOTEIN_H
