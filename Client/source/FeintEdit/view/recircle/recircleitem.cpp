#include "recircleitem.h"
#include "recircleitemview.h"

#include <domain/recirclepage.h>

#include <graphic/screenhelper.h>

#include <util/appcolorhelper.h>
#include <util/screenfit.h>

RecircleItem::RecircleItem()
{

}

void RecircleItem::updateItem(QVariant item)
{
    RecirclePage page=qvariant_cast<RecirclePage>(item);
    RecircleItemView *view=new RecircleItemView();
    view->setObjectName("page");
 //   view->setStyleSheet("#page:hover{background:"+AppColorHelper::noteListShadow()+";}");
    view->setPage(&page);
    view->resize(ScreenHelper::getScreenSize().width()/5,ScreenFit::fitToScreen(64));
    setGraphic(view);
}
