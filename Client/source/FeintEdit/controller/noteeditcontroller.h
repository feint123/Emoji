#ifndef NOTEEDITCONTROLLER_H
#define NOTEEDITCONTROLLER_H

#include <QObject>

#include <pane/markdown/markdownedit.h>

#include <widget/view/listview.h>

#include <view/note/notelist.h>

#include <view/markdowntitle.h>



class NoteEditController:public QObject
{
    Q_OBJECT
public:
    NoteEditController(const QString &noteFile,const QString& noteBookFile,
                       MarkDownEdit *edit);
    ~NoteEditController();


    void setList(NoteList *value);
    void startEdit();
    void setTitle(MarkDownTitle *value);

public slots:
    void onEditChange();
    void onTitleChange(QString title);
    void onAutoSave();
private:
    QString noteFile;
    QString noteBookFile;
    MarkDownEdit *edit;
    MarkDownTitle *title;
    NoteList* list;

    QTimer *timer;
};

#endif // NOTEEDITCONTROLLER_H
