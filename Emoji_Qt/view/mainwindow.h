#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "filepart.h"
#include "imagepart.h"

#include <QMainWindow>
#include <QSplitter>

#include <pane/normaltoolpane.h>
#include <pane/toolpart.h>

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

    void showCard(QVariant);
    void on_actionOpenFile_triggered();

private:
    Ui::MainWindow *ui;
    void initSplitter();
    void initSubParts();
    QSplitter *mainSpli;
    QSplitter *imageSpli;
    FilePart *fileP;
    ImagePart *imageP;
    ToolPart *toolP;
    NormalToolPane *normalP;
};

#endif // MAINWINDOW_H
