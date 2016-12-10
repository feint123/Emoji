#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <pane/menu/feintmenu.h>

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
    void initMenu();
};

#endif // MAINWINDOW_H
