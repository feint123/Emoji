#ifndef NOTEITEMVIEW_H
#define NOTEITEMVIEW_H

#include <QMenu>
#include <QWidget>

#include <domain/notetip.h>

#include <widget/frame/fscaleframe.h>

#include <pane/menu/basemenu.h>

#include <pane/markdown/image/imageframe.h>

namespace Ui {
class NoteItemView;
}

class NoteItemView : public QFrame
{
    Q_OBJECT
    Q_PROPERTY(QString tip READ tip WRITE setTip )
    Q_PROPERTY(QString title READ title WRITE setTitle)
public:
    explicit NoteItemView(QWidget *parent = 0);
    ~NoteItemView();

    void setNote(NoteTip *note);

    QString tip() const;

    QString title() const;

    void createActions();

public slots:
    void setTip(QString tip);

    void setTitle(QString title);

    void onDeleteNote();
    void onEmitMoveNote();
    void onEmitCopyNote();
    void onEmitInNote();

signals:
    void deleteNoteAction(int id,QString notebook);
    void moveNoteAction(NoteTip *tip);
    void copyNoteAction(NoteTip *tip);
    void inNoteAction(QString notebook);

private:
    Ui::NoteItemView *ui;
    QVariant noteq;
    // QWidget interface
    QString m_tip;

    QString m_title;

    QMenu * menu;


    void addShortCuts();

    QAction *deleteNote;
    QAction *moveToNotebook;
    QAction *copyToNotebook;
    QAction *shareNote;
    QAction *newNote;
    QAction *inNote;
    QAction *outNote;

protected:
    void paintEvent(QPaintEvent *event);

    bool hover=false;

protected:
    void contextMenuEvent(QContextMenuEvent *event);
};

#endif // NOTEITEMVIEW_H
