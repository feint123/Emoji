#ifndef IMAGEPREVIEWDIALOG_H
#define IMAGEPREVIEWDIALOG_H

#include <QFrame>

#include <widget/view/gridview.h>

#include <pane/image/domain/image.h>

#include <pane/markdown/image/list/imageinfodialog.h>
#include <pane/markdown/image/list/imageitemview.h>



class ImagePreviewDialog:public QFrame
{
    Q_OBJECT
public:
    ImagePreviewDialog(QWidget *parent=0);
    void setDatas(QList<Image *> imageList);
    void createView();
public slots:
    void imageSelect(QVariant qvariant);
signals:
    void createImageInfo(Image *image);
private:
    GridView *grid=NULL;
    ImageInfoDialog *info;
    ImageItemView *imageView;
    QSize size=QSize(400,300);
    void updateResize();

protected:
    void resizeEvent(QResizeEvent *event);
};

#endif // IMAGEPREVIEWDIALOG_H
