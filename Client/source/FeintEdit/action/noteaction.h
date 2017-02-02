#ifndef NOTEACTION_H
#define NOTEACTION_H

#include <QObject>

#include <domain/notebook.h>
#include <domain/notein.h>
#include <domain/notetip.h>

#include <view/notebook/list/notebooknamedialog.h>



class NoteAction:public QObject
{
    Q_OBJECT
public:
    NoteAction(QWidget *parent=0);
    void setParent(QWidget *value);
    void outNote(QString noteName,QString dir);
    void copyFile(NoteIn *in);
    void createTip(QString desc,QString path);
public slots:
    void deleteNote(int id, QString notebook);
    void addNote();
    void moveToNotebook(NoteTip *tip);
    void copyToNotebook(NoteTip *tip);
    void outNote(QString noteName);
    void inNote(QString notebook);
    void outImages(QString noteName);
private slots:
    void moveNote(NoteBook* noteBook);
    void copyNote(NoteBook* noteBook);
    void onOutDirChanged(QString file);
    void onOutSuccess(QString);
    void onOutImagesSuccess(QString);
private:
    NoteTip tip;
    NotebookNameDialog *dialog;
    QString dir;
    void moveNoteTo(NoteTip *tip, QString title);

    void deleteNote(int id, QString notebook,bool move);
    QWidget *parent;
};

#endif // NOTEACTION_H
