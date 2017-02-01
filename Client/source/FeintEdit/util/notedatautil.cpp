#include "notedatautil.h"
#include "settinghelper.h"

#include <util/json/jsondata.h>

#include <util/qvariantutil.h>

#include <domain/notebook.h>
#include <domain/notetip.h>

#include <QDebug>

NoteDataUtil::NoteDataUtil()
{

}

QList<QVariant> NoteDataUtil::getNotesByBookFile(QString file)
{
    QList<QVariant> notes;
    if(file=="&_&"){
        notes=getAllNotes();
        return notes;
    }

    JsonData *data=new JsonData(SettingHelper::workPath(file).toUtf8(),"notes");

    QList<NoteTip*> noteTip=data->selectAll<NoteTip>();

    QVariantUtil *qv=new QVariantUtil;
    QList<QVariant> qdata=qv->turn<NoteTip>(noteTip);

    delete qv;
    delete data;
    for(NoteTip *tip:noteTip)
        tip->deleteLater();
    return qdata;
}

QList<QVariant> NoteDataUtil::getAllNotes()
{
    QList<QVariant> all;
    JsonData *data=new JsonData(SettingHelper::workPath("notebooks.json").toUtf8(),"notebooks");
    QList<NoteBook*> bookList=data->selectAll<NoteBook>();
    for(NoteBook *book:bookList)
    {
        if(book->fileName()=="&_&")
            continue;
        all.append(getNotesByBookFile(book->fileName()));
        book->deleteLater();
    }
    delete data;
    return all;
}
