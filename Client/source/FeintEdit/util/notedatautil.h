#ifndef NOTEDATAUTIL_H
#define NOTEDATAUTIL_H

#include <QString>
#include <QVariant>



class NoteDataUtil
{
public:
    NoteDataUtil();
    static QList<QVariant> getNotesByBookFile(QString file);
    static QList<QVariant> getAllNotes();
};

#endif // NOTEDATAUTIL_H
