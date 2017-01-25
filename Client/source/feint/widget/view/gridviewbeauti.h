#ifndef GRIDVIEWBEAUTI_H
#define GRIDVIEWBEAUTI_H

#include <QPaintDevice>



class GridViewBeauti
{
public:
    GridViewBeauti();

    static void imageWithPane(QPaintDevice *device, const QImage &bgImage, const QMargins &padding);

};

#endif // GRIDVIEWBEAUTI_H
