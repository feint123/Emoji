#ifndef MARKDOWNFACTORY_H
#define MARKDOWNFACTORY_H

#include <pane/markdown/markdownedit.h>



class MarkDownFactory
{
public:
    MarkDownFactory();
    static MarkDownEdit* create(QWidget* parent);

};

#endif // MARKDOWNFACTORY_H
