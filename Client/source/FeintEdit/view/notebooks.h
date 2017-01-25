#ifndef NOTEBOOKS_H
#define NOTEBOOKS_H

#include <QFrame>

#include <widget/view/gridview.h>

#include <util/json/jsondata.h>

#include <view/notebook/notebookstarter.h>



class Notebooks:public QFrame
{
    Q_OBJECT
public:
    ~Notebooks();
    static Notebooks *getInstance(QWidget *parent=0);
public slots:
    void intoNotebook(QVariant value);
    void loadData();
    void loadStart();
    void ceateStart();
signals:
    void onBookClicked();
private:
    static Notebooks *books;
    Notebooks(QWidget *parent);
    GridView *grid;
    NotebookStarter *starter;

    void addFileListener();

    JsonData *data;

    bool isFileGrid=true;

    // QWidget interface
protected:
    void resizeEvent(QResizeEvent *event);
};

#endif // NOTEBOOKS_H
