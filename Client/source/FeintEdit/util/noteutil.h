#ifndef NOTEUTIL_H
#define NOTEUTIL_H

#include <QString>

#include <domain/notein.h>



class NoteUtil
{
public:
    NoteUtil();
    static QString createNoteFile(QString name, QString noteFile, QString imageFile, QStringList image, QString dir);
    static NoteIn *readNoteFile(QString filePath);
};

#endif // NOTEUTIL_H
