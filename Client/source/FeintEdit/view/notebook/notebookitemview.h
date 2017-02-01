#ifndef NOTEBOOKITEMVIEW_H
#define NOTEBOOKITEMVIEW_H

#include <QDialog>
#include <QFrame>
#include <QLabel>
#include <QMenu>
#include <qevent.h>

#include <domain/notebook.h>


class NotebookItemView : public QFrame
{
    Q_OBJECT

public:
    explicit NotebookItemView(QWidget *parent = 0);
    ~NotebookItemView();
    NoteBook *getNotebook() const;
    void setNotebook(NoteBook *value);
    void createView();

signals:
    void newNoteBook(QWidget *parent);
    void deleteNoteBook(int id);
    void outNoteBook(int id,QWidget *parent);
    void inBookAction(QWidget* parent);
    void updateBookAction(QWidget *parent,int id);
private slots:
    void onEmitNewBook();
    void onEmitDeleteBook();
    void onEmitOutBook();
    void onEmitInBook();
    void onEmitUpdateBook();

private:
    NoteBook *notebook;

    QVariant bookQ;

    QImage img;
    QLabel *bookName;

    QLabel *noteCount;

    QAction *newBook;

    QAction *deleteBook;

    QAction *outBook;

    QAction *inBook;

    QAction *shareBook;

    QAction *updateBook;

    QMenu *menu;

    void createActions();

    void addShortCuts();

    int countNote();

    int padding;

    int pagePadding=3;

    int maxPage=4;
protected:
    void resizeEvent(QResizeEvent *event);

    void contextMenuEvent(QContextMenuEvent *event);

    void paintEvent(QPaintEvent *event);
};

#endif // NOTEBOOKITEMVIEW_H
