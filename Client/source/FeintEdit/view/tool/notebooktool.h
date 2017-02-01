#ifndef NOTEBOOKTOOL_H
#define NOTEBOOKTOOL_H

#include <QDialog>

#include <action/notebookaction.h>

namespace Ui {
class NotebookTool;
}

class NotebookTool : public QDialog
{
    Q_OBJECT

public:
    explicit NotebookTool(QWidget *parent = 0);
    ~NotebookTool();

private:
    Ui::NotebookTool *ui;
    NotebookAction *action;
    // QWidget interface
signals:
    void newBook(QWidget *);
    void inBook(QWidget *);

private slots:
    void on_newBookBtn_clicked();
    void on_inBookBtn_clicked();
};

#endif // NOTEBOOKTOOL_H
