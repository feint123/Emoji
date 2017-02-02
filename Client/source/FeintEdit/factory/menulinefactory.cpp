#include "menulinefactory.h"

#include <util/appcolorhelper.h>
#include <util/screenfit.h>

#include <domain/wordstatic.h>

#include <plug/appstatic.h>

MenuLineFactory::MenuLineFactory()
{

}

MenuLine *MenuLineFactory::create(QWidget *parent)
{
    MenuLine *line=MenuLine::getInstance(parent);
    line->setBgColor(AppColorHelper::menuBg());
    line->setCheckColor(AppColorHelper::menuCheck());
    line->addItem(":/image/note_normal.png",WordStatic::note);
    line->addItem(":/image/notebook_normal.png",WordStatic::book);
//    line->addItem(QIcon(":/image/picture.png"),QString("图片集"));
    line->addItem(":/image/setting_normal.png",WordStatic::setting);
    line->createView(0);
    line->resize(AppStatic::toolHeight,80);
    ScreenFit::fit(line);
    return line;
}
