#ifndef TOOLFACTORY_H
#define TOOLFACTORY_H

#include <qwidget.h>



class ToolFactory
{
public:
    enum Model{
        Note,
        NoteBook
    };

    ToolFactory();

    static QDialog *createTool(QWidget *parent, Model model);


};

#endif // TOOLFACTORY_H
