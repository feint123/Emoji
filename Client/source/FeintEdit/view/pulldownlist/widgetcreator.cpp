#include "widgetcreator.h"

#include <test/flabelwidget.h>

WidgetCreator::WidgetCreator()
{

}

FWidget* WidgetCreator::create(const QVariant &data)
{
    FLabelWidget *fw=new FLabelWidget;
    fw->setData(data);
    return fw;
}
