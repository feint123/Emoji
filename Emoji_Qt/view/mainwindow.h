#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "filepart.h"
#include "imagepart.h"
#include "toolpart.h"

#include <QMainWindow>
#include <QSplitter>

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
};

#endif // MAINWINDOW_H
