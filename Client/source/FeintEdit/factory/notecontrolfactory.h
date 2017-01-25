#ifndef NOTECONTROLFACTORY_H
#define NOTECONTROLFACTORY_H

#include <view/note/controlfloatbutton.h>



class NoteControlFactory
{
public:
    NoteControlFactory();
    static ControlFloatButton *create(QWidget *parent);
};

#endif // NOTECONTROLFACTORY_H
