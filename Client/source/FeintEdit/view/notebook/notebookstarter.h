#ifndef NOTEBOOKSTARTER_H
#define NOTEBOOKSTARTER_H

#include <QFrame>
#include <fbutton.h>



class NotebookStarter:public QFrame
{
    Q_OBJECT
public:
    NotebookStarter(QWidget *parent);

    FButton *getStart() const;

private:
    FButton *start;
    void createView();

    // QWidget interface
protected:
    void resizeEvent(QResizeEvent *event);
};

#endif // NOTEBOOKSTARTER_H
