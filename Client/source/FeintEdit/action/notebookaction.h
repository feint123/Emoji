#ifndef NOTEBOOKACTION_H
#define NOTEBOOKACTION_H

#include "noteaction.h"

#include <QObject>

#include <domain/notetip.h>



class NotebookAction:public QObject
{
    Q_OBJECT
public:
    NotebookAction(QWidget *parent=0);

public slots:
    void newBook(QWidget *parent);
    void deleteBook(int nid);
    void outBook(int nid, QWidget *parent);
    void inBook(QWidget *parent);


private:
    QStringList getNoteFileList(QList<NoteTip*> tips);
    NoteAction *action;

    void inBook(QString dir,QString book);


};

#endif // NOTEBOOKACTION_H
