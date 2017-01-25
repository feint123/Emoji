#ifndef NOTECONTROLLER_H
#define NOTECONTROLLER_H

#include "noteeditcontroller.h"

#include <domain/notetip.h>

#include <pane/markdown/markdownmanager.h>

#include <view/note/notes.h>





class NoteController:public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString currentNote READ currentNote WRITE setCurrentNote NOTIFY currentNoteChanged)
    Q_PROPERTY(int noteNum READ noteNum WRITE setNoteNum NOTIFY noteNumChanged)

public:
    NoteController(Notes *note);
    NoteController();
    ~NoteController();
    QString currentNote() const;

    int noteNum() const;

public slots:
    void setCurrentNote(QString currentNote);
    void addNote();
    void setNoteNum(int noteNum);

signals:
    void currentNoteChanged(QString currentNote);
    void noteNumChanged(int noteNum);
    void onReadyLoadNote(QString);
private slots:
    void onNoteSelect(QVariant note);
    void onControlClicked(int i);
    void refreshNoteList();
    void loadNote();
    void readyLoadNote(QString noteFile);
    void onScrollLNoteList(int value);
    void checkNoteNum();
private:
    void createView();
    void chooseMark(QString path);

    void listWorkspacing();
    void initEditController();
    void saveNoteBeforeChange();
    Notes *notes;
    NoteEditController *editController;
    QTimer *timer;
    QTimer *loadtimer;

    int focusIndex=0;
    int currentScroll=0;

    QString m_currentNote;
    bool editControlLock=false;
    bool refreshLock=false;

    //utils
    QString getNoteBookFile();
    NoteTip * createBasicTip(QString fileName);
    int m_noteNum;
};

#endif // NOTECONTROLLER_H
