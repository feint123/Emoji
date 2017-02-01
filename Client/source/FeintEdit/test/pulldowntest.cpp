#include "flabelwidget.h"
#include "pulldowntest.h"

#include <view/pulldownlist/pulldownlist.h>
#include <view/pulldownlist/widgetcreator.h>

#include <util/qvariantutil.h>

PullDownTest::PullDownTest(QWidget *parent):
    QWidget(parent)
{
    createPullDown();
}

void PullDownTest::createPullDown()
{
    pull=new PullDownList(this);
    QStringList string;
    string<<"hello"<<"world"<<"welcome"<<"to"<<"this"<<"world";
    FLabelWidget *w=new FLabelWidget(pull);
    w->setData(QVariant::fromValue(tr("Markdown标签")));
    w->resize(100,24);
//    connect(pull,SIGNAL(listItemSelect(QVariant)),w,SLOT(setData(QVariant)));
    pull->setItem(w);
    pull->setWidgetFactory(WidgetCreator::create);
    pull->setListData(QVariantUtil::turnString(string));
    pull->show();
    pull->setGeometry(20,20,150,24);


}

void PullDownTest::resizeEvent(QResizeEvent *event)
{

}
