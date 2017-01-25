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

    ControlFloatButton *getFloatBtn() const;

    void setFloatBtn(ControlFloatButton *value);

    void setMark(MarkDownPlace *value);

    void createMark(QString noteFile="");


private:
    static Notes *notes;
    NoteList *list;
    MarkDownEdit *edit;
    QFrame *editArea;
    MarkDownPlace *mark;
    ControlFloatButton *floatBtn;
    void createView();
    QString m_currentNote;
    Notes(QWidget *parent=0);
    bool hasMark=false;

protected:
    void resizeEvent(QResizeEvent *event);

};

#endif // NOTES_H
