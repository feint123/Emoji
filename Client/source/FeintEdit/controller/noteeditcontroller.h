#ifndef NOTEEDITCONTROLLER_H
#define NOTEEDITCONTROLLER_H

#include <QObject>

#include <pane/markdown/markdownedit.h>

#include <widget/view/listview.h>

#include <view/note/notelist.h>

#include <view/markdowntitle.h>

#include <domain/notetip.h>



class NoteEditController:public QObject
{
    Q_OBJECT
public:

    ~NoteEditController();

    static NoteEditController* getInstance(QObject *parent=0);
    void init(const QString &noteFile,const QString& noteBookFile,MarkDownEdit *edit);
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
    void loadImageToTip(NoteTip *tip);
    void updateImageList();
    void updateLastEdit(NoteTip *tip);
    QTimer *timer;

    static NoteEditController *controller;
    NoteEditController(QObject *parent);
};

#endif // NOTEEDITCONTROLLER_H
