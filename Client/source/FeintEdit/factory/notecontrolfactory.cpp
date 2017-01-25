#include "notecontrolfactory.h"

NoteControlFactory::NoteControlFactory()
{

}

ControlFloatButton *NoteControlFactory::create(QWidget *parent)
{
    ControlFloatButton *floatBtn=new ControlFloatButton(parent);
    floatBtn->addBtn(QIcon(":/image/add.png"),"添加笔记");

    floatBtn->resize(50,50);
    floatBtn->setIcon(QIcon(":/image/showed.png"),QIcon(":/image/hide.png"));
    return floatBtn;
}
