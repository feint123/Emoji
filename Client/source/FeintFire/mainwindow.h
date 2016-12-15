#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "articalarea.h"
#include "mainpart.h"

#include <QMainWindow>
#include <QPaintEvent>
#include <pane/menu/feintmenu.h>

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

private slots:
    void showMenu(bool);
    void back(int);
    void menuEvnent(int,int);
public slots:
    void loadArtical(int);

private:
    Ui::MainWindow *ui;
    FeintMenu *menu;
    QList<QStringList> menuInfo;
    BackLeader *backL;
    SearchLeader *sLeader;
    MainPart *mainPart;
    MarkDown *markdown;
    ArticalArea *area;
    QRect menuRect;

    QSize screenSize;
    void initMenu();
    void initMainPart();
    void initLeader();

    void reloadMain();

    void localAction(int i);

    void turnWindowAnim();
};

#endif // MAINWINDOW_H
