#ifndef NOTETOOL_H
#define NOTETOOL_H

#include "basetool.h"

#include <QDialog>

#include <action/markdownquick.h>
#include <action/noteaction.h>

#include <view/pulldownlist/pulldownlist.h>

namespace Ui {
class NoteTool;
}

class NoteTool : public BaseTool
{
    Q_OBJECT

public:
    explicit NoteTool(QWidget *parent = 0);
    ~NoteTool();
    void createMarkPull();

private slots:
    void on_outBookBtn_clicked();
    void on_quick_choosed(QVariant);
signals:
    void outNote(QString);

    void addHeader1();
    void addHeader2();
    void addHeader3();
    void addHeader4();
    void addHeader5();
    void addHeader6();
    void addBlod();
    void addItalic();
    void addCode();
    void addDelete();

    void addOrderList();
    void addUnOrderList();
    void addBlock();

    void insertUrl();
    void insertImage();

    void zoomInEdit();
    void zoomOutEdit();

    void addDevide();
private:
    Ui::NoteTool *ui;
    NoteAction *action;
    bool firstPull=true;
    void connectToQuick(MarkDownQuick *quick);


};

#endif // NOTETOOL_H
