#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "articalarea.h"
#include "mainpart.h"

#include <QMainWindow>

#include <pane/menu/feintmenu.h>

#include <widget/view/listview.h>

#include <pane/leader/backleader.h>
#include <pane/leader/searchleader.h>

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
public slots:
    void loadArtical(int);

private:
    Ui::MainWindow *ui;
    FeintMenu *menu;
    QList<QStringList> menuInfo;
    void initMenu();
    void initMainPart();
    void initLeader();
    BackLeader *backL;
    SearchLeader *sLeader;
    MainPart *mainPart;
    ArticalArea *area;
    QRect menuRect;
};

#endif // MAINWINDOW_H
