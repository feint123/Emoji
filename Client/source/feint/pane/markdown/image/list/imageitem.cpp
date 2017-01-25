#include "imageitem.h"
#include "imageitemview.h"

#include <pane/image/domain/image.h>

ImageItem::ImageItem()
{

}

void ImageItem::updateItem(QVariant item)
{
    Image image=qvariant_cast<Image>(item);
    ImageItemView *view=new ImageItemView();
    view->resize(240,160);
    view->setImage(&image);
    setGraphic(view);
}
