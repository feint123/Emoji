#ifndef EDITLOADER_H
#define EDITLOADER_H

#include <pane/markdown/markdownedit.h>



class EditLoader:public QObject
{
    Q_OBJECT
public:
    EditLoader(QString note);

    void load(MarkDownEdit* edit);

    bool loadLocal(MarkDownEdit* edit);

    bool loadNet(MarkDownEdit *edit);

private:
    QString note;
};

#endif // EDITLOADER_H
