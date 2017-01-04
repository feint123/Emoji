#ifndef INNERDIALOGRECT_H
#define INNERDIALOGRECT_H

#include <QWidget>



class InnerDialogRect
{
public:
    enum DIR{
        UP,
        DOWN,
        RIGHT,
        LEFT
    };

    InnerDialogRect(DIR dir);
    void draw(QWidget *parent,int delay);

    void setTri(int value);

private:
    DIR dir;
    void drawRight(QPainter *painter);
    void drawUp(QPainter *painter);
    void drawDown(QPainter *painter);
    QWidget *parent;
    int delay;
    int tri;
};

#endif // INNERDIALOGRECT_H
