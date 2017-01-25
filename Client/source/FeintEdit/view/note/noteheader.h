#ifndef NOTEHEADER_H
#define NOTEHEADER_H

#include <QFrame>
#include <fbutton.h>

#include <domain/notebook.h>

#include <view/notebook/list/notebooknamedialog.h>



class NoteHeader:public QFrame
{
    Q_OBJECT
    Q_PROPERTY(QString currentNotebook READ currentNotebook WRITE setCurrentNotebook NOTIFY currentNotebookChanged)
public:
    NoteHeader(QWidget *parent);

    QString currentNotebook() const;

    void createView();
public slots:
    void setCurrentNotebook(QString currentNotebook);
    void setNotebookText(QString book);
    void showAllBooks();
    void loadAllNotes();
    void loadBooks(NoteBook* book);
signals:
    void currentNotebookChanged(QString currentNotebook);
private:
    FButton *notebookBtn;
    FButton *allNotesBtn;
    QString m_currentNotebook;
     NotebookNameDialog *dialog;



protected:
    void paintEvent(QPaintEvent *event);
};

#endif // NOTEHEADER_H
