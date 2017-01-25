#ifndef NOTELIST_H
#define NOTELIST_H

#include "noteheader.h"

#include <QWidget>

#include <widget/view/listview.h>



class NoteList:public QWidget
{
    Q_OBJECT
public:
    ~NoteList();

    void loadDate(QList<QVariant> datas);

    ListView *getListView() const;

    static NoteList *getInstance(QWidget *parent);
    NoteHeader *getNoteH() const;

private:
    NoteList(QWidget *parent);
    static NoteList *list;
    ListView *listView;
    NoteHeader *noteH;
    bool init=false;
    // QWidget interface
protected:
    void resizeEvent(QResizeEvent *event);
};

#endif // NOTELIST_H
