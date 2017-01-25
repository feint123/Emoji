#ifndef SETTINGCONTROLLER_H
#define SETTINGCONTROLLER_H

#include <QObject>
#include <mainwindow.h>

#include <util/settinghelper.h>



class SettingController:public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString currentNote READ currentNote WRITE setCurrentNote NOTIFY currentNoteChanged)
    Q_PROPERTY(QString workspace READ workspace WRITE setWorkspace NOTIFY workspaceChanged)


public:
    SettingController(MainWindow *parent=0);

    QString currentNote() const;

    QString workspace() const;

public slots:
    void setCurrentNote(QString currentNote);

    void setWorkspace(QString workspace);

signals:
    void currentNoteChanged(QString currentNote);

    void workspaceChanged(QString workspace);

private slots:
    void on_menu_clicked(int i);
    void on_currentNote_change();
    void on_workSpacing_change();
    void on_setting_change();
private:
    MainWindow *main;
    MenuLine *menu;
    void createNotes();
    void createSetting();
    void createNoteBooks();
    void loadFileListener();
    bool hasNotebook();
    int lock=-1;
    QString m_currentNote=SettingHelper::currentNote();
    QString m_workspace=SettingHelper::workspacing();
};

#endif // SETTINGCONTROLLER_H
