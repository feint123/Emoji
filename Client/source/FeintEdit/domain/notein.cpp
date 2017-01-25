#include "notein.h"

NoteIn::NoteIn()
{

}


QString NoteIn::getNote() const
{
    return note;
}

void NoteIn::setNote(const QString &value)
{
    note = value;
}

void NoteIn::addImage(QString name, QImage img)
{
    images[name]=img;
}

QHash<QString, QImage> NoteIn::getImages() const
{
    return images;
}

QString NoteIn::getNoteName() const
{
    return noteName;
}

void NoteIn::setNoteName(const QString &value)
{
    noteName = value;
}

QString NoteIn::getImageRName() const
{
    return imageRName;
}

void NoteIn::setImageRName(const QString &value)
{
    imageRName = value;
}

QString NoteIn::getImageR() const
{
    return imageR;
}

void NoteIn::setImageR(const QString &value)
{
    imageR = value;
}
