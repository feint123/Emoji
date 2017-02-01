#include "noteutil.h"

#include <QFile>
#include <QImage>
#include <QDebug>
#include <QDir>
#include <domain/notein.h>
#include <util/fileutil.h>

NoteUtil::NoteUtil()
{

}

QString NoteUtil::createNoteFile(QString name,QString noteFile, QString imageFile, QStringList image,QString dir)
{
    QFile file(name);
    QDataStream out(&file);
    if(file.open(QIODevice::WriteOnly|QIODevice::Truncate))
    {
        QFile note(dir+"/"+noteFile+".fei");
        if(note.open(QFile::ReadOnly|QFile::Text))
        {

            out<<QString(noteFile);
            out<<QString(note.readAll());
            note.close();
        }else return NULL;
        QFile imageF(dir+"/"+imageFile);
        if(imageF.open(QFile::ReadOnly|QFile::Text)){
            out<<QString(imageFile);
            out<<QString(imageF.readAll());
            imageF.close();
        }else
        {
            out<<qint32(-1);
            return file.fileName();
        }


        out<<qint32(image.count());

        for(QString img:image){
            out<<QString(img);
            out<<QImage(FileUtil::imageTempPath(dir,img));
        }
    }else
        return NULL;
    file.close();
    return file.fileName();
}

NoteIn * NoteUtil::readNoteFile(QString filePath)
{
    QFile file(filePath);
    QDataStream in(&file);
    NoteIn *noteIn=new NoteIn;
    if(file.open(QFile::ReadOnly|QFile::Truncate))
    {
        QString noteName;
        QString note;
        QString imageRName;
        QString imageR;
        int imageCount;
        in>>noteName>>note>>imageRName>>imageR>>imageCount;

        for(int i=0;i<imageCount;i++)
        {
            QString imageName;
            QImage image;
            in>>imageName>>image;
            noteIn->addImage(imageName,image);
        }
        file.close();
        noteIn->setNoteName(noteName);
        noteIn->setNote(note);
        noteIn->setImageRName(imageRName);
        noteIn->setImageR(imageR);
        return noteIn;
    }
    else return NULL;
}
