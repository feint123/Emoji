#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "mainpart.h"

#include <QMainWindow>

#include <pane/menu/feintmenu.h>

#include <widget/view/listview.h>

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

private:
    Ui::MainWindow *ui;
    FeintMenu *menu;
    QList<QStringList> menuInfo;
    void initMenu();
    void initMainPart();

    MainPart *mainPart;
};

#endif // MAINWINDOW_H
