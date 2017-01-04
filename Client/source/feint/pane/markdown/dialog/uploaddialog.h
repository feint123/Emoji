#ifndef UPLOADDIALOG_H
#define UPLOADDIALOG_H

#include <QDialog>
#include <QWidget>

class UploadDialog:public QDialog
{
    Q_OBJECT
public:
    UploadDialog(QWidget *parent=0);
    int getDelay() const;
    void setDelay(int value);

private:
    int delay;
};

#endif // UPLOADDIALOG_H
