#include "lastedititem.h"
#include "lastedititemview.h"

#include <domain/lastedit.h>

#include <plug/appstatic.h>

#include <graphic/screenhelper.h>

#include <util/screenfit.h>

LastEditItem::LastEditItem()
{

}

void LastEditItem::updateItem(QVariant item)
{
    LastEdit edit=qvariant_cast<LastEdit>(item);
    LastEditItemView *view=new LastEditItemView();
    view->setLastEdit(&edit);
    view->resize(200,ScreenFit::fitToScreen(AppStatic::toolHeight*2));
    setGraphic(view);
}
