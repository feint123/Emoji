#ifndef NOTEBOOKLISTLOADER_H
#define NOTEBOOKLISTLOADER_H

#include <QObject>



class NoteBookListLoader:public QObject
{
    Q_OBJECT
public:
    NoteBookListLoader();
    QList<QVariant> load(QString notebook);
    QList<QVariant> loadLocal(QString notebook);
    QList<QVariant> loadNet(QString notebook);
};

#endif // NOTEBOOKLISTLOADER_H
