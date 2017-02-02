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
    void saveNoteBeforeChange();
signals:
    void currentNoteChanged(QString currentNote);
    void noteNumChanged(int noteNum);
    void onReadyLoadNote(QString);
    void notebookChanged();
private slots:
    void onNoteSelect(QVariant note);
    void refreshNoteList();
    void loadNote();
    void readyLoadNote();
    void onScrollLNoteList(int value);
    void checkNoteNum();

    void refersh();
private:
    void createView(int i);
    void startListenNoteNumChange();
    bool chooseMark(QString path);

    void listWorkspacing();
    void initEditController();

    void initNoteList();

    Notes *notes;
    NoteEditController *editController;
    QTimer *loadtimer=NULL;

    int focusIndex=0;
    int currentScroll=0;

    QString m_currentNote;
    bool editControlLock=false;
    bool refreshLock=false;

    //utils
    QString currentBookName();
    QString getNoteBookFile();

    void updateFocusIndex();

    NoteTip * createBasicTip(QString fileName);
    int m_noteNum;

    QList<QString> lookedNote;
    int lookedNum=-1;
};

#endif // NOTECONTROLLER_H
