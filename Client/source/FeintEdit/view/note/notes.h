#ifndef NOTES_H
#define NOTES_H



#include "noteheader.h"

#include <pane/markdown/markdownedit.h>

#include <QSplitter>

#include <view/note/controlfloatbutton.h>
#include <view/note/notelist.h>


#include <view/markdownplace.h>

class Notes:public QFrame
{
    Q_OBJECT
public:
    static Notes* getInstance(QWidget *parent=0);

    NoteList *getList() const;

    ~Notes();

    MarkDownPlace *getMark() const;

    void setMark(MarkDownPlace *value);

    void createMark(QString noteFile="");


private:
    static Notes *notes;
    QDialog *tool;
    NoteList *list;
    MarkDownEdit *edit;
    QFrame *editArea;
    MarkDownPlace *mark;
    void createView();
    QString m_currentNote;
    Notes(QWidget *parent=0);
    bool hasMark=false;

protected:
    void resizeEvent(QResizeEvent *event);

public:
    bool eventFilter(QObject *watched, QEvent *event);
    void setTool(QDialog *value);
};

#endif // NOTES_H
