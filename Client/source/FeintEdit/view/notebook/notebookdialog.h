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
    explicit NotebookDialog(QWidget *parent = 0);
    ~NotebookDialog();

private slots:

    void on_okBtn_clicked();

    void on_cancelBtn_clicked();

private:
    Ui::NotebookDialog *ui;

protected:
    void paintEvent(QPaintEvent *event);
};

#endif // NOTEBOOKDIALOG_H
