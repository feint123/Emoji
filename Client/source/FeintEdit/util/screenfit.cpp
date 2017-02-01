#include "screenfit.h"

#include <graphic/screenhelper.h>

#include <plug/appstatic.h>

ScreenFit::ScreenFit()
{

}

int ScreenFit::fitToScreen(int value)
{
    return value*(ScreenHelper::getScreenSize().width()
                  /(float)AppStatic::standardScreenWidth);
}

void ScreenFit::fitFont(QWidget *lab)
{
    QFont font=lab->font();
    font.setPixelSize(ScreenFit::fitToScreen(font.pointSize()));
    lab->setFont(font);
}

void ScreenFit::fit(QWidget *widget)
{
    widget->resize(fitToScreen(widget->width()),fitToScreen(widget->height()));
}

void ScreenFit::fitWithFont(QWidget *widget)
{
    fitFont(widget);
    fit(widget);
}
