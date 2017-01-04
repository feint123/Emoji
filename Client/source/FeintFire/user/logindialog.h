#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include <QPaintEvent>

namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = 0);
    ~LoginDialog();

private slots:


    void on_travelBtn_clicked();

private:
    Ui::LoginDialog *ui;
    void paintEvent(QPaintEvent *event);


};


#endif // LOGINDIALOG_H
