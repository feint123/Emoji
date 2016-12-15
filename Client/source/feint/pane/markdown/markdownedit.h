#ifndef MARKDOWNEDIT_H
#define MARKDOWNEDIT_H

#include "markdownhighlighter.h"

#include <QTextEdit>



class MarkDownEdit:public QTextEdit
{
    Q_OBJECT

public:
    enum Theme{
        DAILY,
        DARK
    };
    explicit MarkDownEdit(QWidget *parent=0);

    void setTheme(Theme theme);

private:
    MarkDownHighlighter *lighter;
    void initDarkTheme();
};

#endif // MARKDOWNEDIT_H
