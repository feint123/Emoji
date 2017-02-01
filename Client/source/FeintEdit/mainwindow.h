#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <pane/markdown/markdownedit.h>

#include <view/menuline.h>
#include <view/notebooks.h>
#include <QVariant>
#include <plug/settingdialog.h>
#include <view/note/notes.h>
#include <view/tool/notebooktool.h>


class MainWindow : public QMainWindow
{
    Q_OBJECT
    Q_PROPERTY(int current READ current WRITE setCurrent NOTIFY currentChanged)

public:
    MainWindow(QWidget *parent = 0);

    ~MainWindow();

    // QWidget interface
    Notes *getEdit() const;
    void setEdit(Notes *value);

    MenuLine *getMenu() const;
    void setMenu(MenuLine *value);

    SettingDialog *getSetting() const;
    void setSetting(SettingDialog *value);

    int current() const;
    void removeUnusedWidget(int used);
    void removeWidget(int id);
    Notebooks *getNotebooks() const;

    void setNotebooks(Notebooks *value);

    QDialog *getTool() const;

    void setTool(QDialog *value);

public slots:
    void setCurrent(int current);
    void on_menu_clicked(int i);
signals:
    void currentChanged(int current);

protected:
    void resizeEvent(QResizeEvent *event);
private slots:

private:
    void loadController();
    void initSetting();
    void initColor();
    void initHigh();

    void initStatic();

    void resizeMarkdown(Notes *edit);
    void resizeMenuLine(MenuLine *menu);
    void resizeSetting(SettingDialog *dialog);
    void resizeNoteBooks(Notebooks *books);

    Notes *edit;
    MenuLine *menu;
    SettingDialog *setting;
    Notebooks *notebooks;
    QDialog *tool=NULL;
    int m_current=-1;

    QList<int> widgetStatus;
    QList<QWidget *> widgets;



    // QWidget interface
protected:
    void closeEvent(QCloseEvent *event);
};

#endif // MAINWINDOW_H
