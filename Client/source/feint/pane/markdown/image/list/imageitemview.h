#ifndef IMAGEITEMVIEW_H
#define IMAGEITEMVIEW_H

#include <QFrame>
#include <qvariant.h>

#include <pane/image/domain/image.h>

class ImageItemView:public QFrame
{
    Q_OBJECT
public:
    ImageItemView(QWidget *parent=0,Image *image=0);

    void setImage(Image *value);

private:
    Image *image=NULL;

    QString path;

    Image imageC;

    QImage img;

protected:
    void paintEvent(QPaintEvent *event);

    // QWidget interface
protected:
    void mouseDoubleClickEvent(QMouseEvent *event);
};

#endif // IMAGEITEMVIEW_H
