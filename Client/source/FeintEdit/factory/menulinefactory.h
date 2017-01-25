#ifndef MENULINEFACTORY_H
#define MENULINEFACTORY_H

#include <view/menuline.h>



class MenuLineFactory
{
public:
    MenuLineFactory();
    static MenuLine* create(QWidget *parent);
};

#endif // MENULINEFACTORY_H
