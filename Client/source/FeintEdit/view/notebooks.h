#ifndef NOTEBOOKS_H
#define NOTEBOOKS_H

#include <QFrame>
#include <qdialog.h>

#include <widget/view/gridview.h>

#include <util/json/jsondata.h>

#include <view/notebook/notebookstarter.h>

#include <view/recircle/recircle.h>



class Notebooks:public QFrame
{
    Q_OBJECT
public:
    ~Notebooks();
    static Notebooks *getInstance(QWidget *parent=0);
    void setTool(QDialog *value);
    void createView();
public slots:
    void intoNotebook(QVariant value);
    void loadData();
    void loadStart();
    void loadView();
    void ceateStart();
    void updateDatas();

signals:
    void onBookClicked();
private:
    static Notebooks *books;
    Notebooks(QWidget *parent);
    GridView *grid;
    NotebookStarter *starter=NULL;
    Recircle *recircle;
    void addFileListener();

    QList<QVariant> bookList();


    QDialog *tool;
    JsonData *data;

    bool isFileGrid=true;

    // QWidget interface
protected:
    void resizeEvent(QResizeEvent *event);


    // QWidget interface
protected:
    void paintEvent(QPaintEvent *event);
};

#endif // NOTEBOOKS_H
