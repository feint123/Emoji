#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <pane/markdown/markdownedit.h>

#include <view/menuline.h>
#include <view/notebooks.h>
#include <QVariant>
#include <plug/settingdialog.h>
#include <view/note/notes.h>

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

    Notebooks *getNotebooks() const;

    void setNotebooks(Notebooks *value);

public slots:
    void setCurrent(int current);

signals:
    void currentChanged(int current);

protected:
    void resizeEvent(QResizeEvent *event);
private slots:
    void on_menu_clicked(int i);
private:
    void loadController();

    void resizeMarkdown(Notes *edit);
    void resizeMenuLine(MenuLine *menu);
    void resizeSetting(SettingDialog *dialog);
    void resizeNoteBooks(Notebooks *books);

    Notes *edit;
    MenuLine *menu;
    SettingDialog *setting;
    Notebooks *notebooks;
    int m_current=-1;

    QList<int> widgetStatus;
    QList<QWidget *> widgets;
};

#endif // MAINWINDOW_H
