#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "mainpart.h"

#include <QMainWindow>
#include <QPaintEvent>
#include <artical/articalarea.h>
#include <pane/menu/feintmenu.h>
#include <plan/planframe.h>
#include <user/settingdialog.h>

#include <widget/view/listview.h>

#include <pane/leader/backleader.h>
#include <pane/leader/searchleader.h>

#include <pane/markdown/markdown.h>
#include <pane/markdown/markdownedit.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    int rWidth() const;

private slots:
    void showMenu(bool);
public slots:
    void loadArtical(int);

private:
    Ui::MainWindow *ui;

    QList<QStringList> menuInfo;
    /*****系统中的主要控件*****/
    FeintMenu *menu;
    SearchLeader *sLeader;
    MainPart *mainPart;
    MarkDown *markdown;
    PlanFrame *frame;
    SettingDialog *setting;
    ArticalArea *area;


    QRect menuRect;
    QSize screenSize;

    int lockLocal=-1;

    /****对系统中的主要控件进行初始化*****/
    void createView();

    void showSearchLeader();

    void createMarkDown();

    void createPlan();

    void createSetting();

    void refreshMenu(int index);

    void loadComponent();

    void loadSettingController();


    QList<QWidget*> funcList;

    void refreshMainGeometry(QRect rect,bool isAuto);

    void menuAction(bool isAuto=true);

    void menuAnim(bool show);

    int mainHeight;


protected:
    void resizeEvent(QResizeEvent *event);
};

#endif // MAINWINDOW_H
