#ifndef LISTVIEWBEAUTI_H
#define LISTVIEWBEAUTI_H

#include <QImage>
#include <QMargins>



class ListViewBeauti
{
public:
    ListViewBeauti();
    static void colorBackground(QPaintDevice *device, const QImage &image, const QColor &color);

};

#endif // LISTVIEWBEAUTI_H
