#ifndef NOTEBOOKDIALOG_H
#define NOTEBOOKDIALOG_H

#include <QDialog>

namespace Ui {
class NotebookDialog;
}

class NotebookDialog : public QDialog
{
    Q_OBJECT

public:
     static NotebookDialog *getInstance(QWidget *parent=0);
    ~NotebookDialog();

     void setTitle(QString title);

private slots:

    void on_okBtn_clicked();

    void on_cancelBtn_clicked();
signals:
    void ready(QString);
private:
    Ui::NotebookDialog *ui;
    static NotebookDialog * dialog;
    explicit NotebookDialog(QWidget *parent = 0);
protected:
    void paintEvent(QPaintEvent *event);

    // QWidget interface
protected:
    void resizeEvent(QResizeEvent *event);
};

#endif // NOTEBOOKDIALOG_H
