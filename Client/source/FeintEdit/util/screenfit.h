#ifndef SCREENFIT_H
#define SCREENFIT_H

#include <QWidget>



class ScreenFit
{
public:
    ScreenFit();

    static int fitToScreen(int value);

    static void fitFont(QWidget *widget);

    static void fit(QWidget *widget);

    static void fitWithFont(QWidget *widget);
};

#endif // SCREENFIT_H
