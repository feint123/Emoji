#include "menulinefactory.h"

MenuLineFactory::MenuLineFactory()
{

}

MenuLine *MenuLineFactory::create(QWidget *parent)
{
    MenuLine *line=new MenuLine(parent);
    line->setBgColor("#404244");
    line->addItem(QIcon(":/image/note.png"),QString("笔记"));
    line->addItem(QIcon(":/image/notebook.png"),QString("笔记本"));
//    line->addItem(QIcon(":/image/picture.png"),QString("图片集"));
    line->addItem(QIcon(":/image/setting.png"),QString("设置"));
    line->resize(54,80);
    return line;
}
