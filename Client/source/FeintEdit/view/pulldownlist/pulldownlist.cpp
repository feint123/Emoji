#include "pulldownlist.h"

#include "widgetcreator.h"

#include <widget/view/listview.h>
#include <widget/view/listviewbeauti.h>
#include <QDebug>
#include <util/screenfit.h>
PullDownList::PullDownList(QWidget *parent):
    QFrame(parent)
{
    createView();
}

QVariant PullDownList::currentData() const
{
    return m_currentData;
}

void PullDownList::setCurrentData(const QVariant &currentData)
{

    m_currentData = currentData;
    list->hide();
    emit listItemSelect(currentData);
}

void PullDownList::showPushDownList()
{
    if(list!=NULL)
    {
        if(list->isVisible())
            list->hide();
        else
            list->show();
    }
}

void PullDownList::createView()
{
    this->setObjectName("pull-down");
    this->setStyleSheet("#pull-down{background:transparent;border-radius:10px;}");
    this->setMaximumHeight(ScreenFit::fitToScreen(24));
    pushBtn=new QPushButton(this);
    pushBtn->setFixedWidth(ScreenFit::fitToScreen(24));
    pushBtn->setStyleSheet("QPushButton{border:none;border-image:url(:/image/down_btn.png);}"
                           "QPushButton:pressed{border-image:url(:/image/down_btn_pressed.png)}");
    connect(pushBtn,SIGNAL(clicked(bool)),this,SLOT(showPushDownList()));
}

QString PullDownList::bgColor() const
{
    return m_bgColor;
}

void PullDownList::setBgColor(const QString &bgColor)
{
    m_bgColor = bgColor;
}

QString PullDownList::verticalScrollHandleColor() const
{
    return m_verticalScrollHandleColor;
}

void PullDownList::setVerticalScrollHandleColor(const QString &verticalScrollHandleColor)
{
    m_verticalScrollHandleColor = verticalScrollHandleColor;
}

QString PullDownList::verticalScrollPageColor() const
{
    return m_verticalScrollPageColor;
}

void PullDownList::setVerticalScrollPageColor(const QString &verticalScrollPageColor)
{
    m_verticalScrollPageColor = verticalScrollPageColor;
}

void PullDownList::createDataListFrame()
{
    list=new ListView(this);
    list->setWindowFlags(Qt::Popup);
    list->setUseFocus(false);
    list->setScrollHandle(verticalScrollHandleColor());
    list->setScrollPage(verticalScrollPageColor());
    list->setBgColor(bgColor());
    list->setBg(ListViewBeauti::colorBackground);
    list->createView();
    list->setData(m_listData);
    list->setItem(new PullDownListItem(widgetFactory()));
    list->setMaximumHeight(listMaxinumHeight());
    list->setGeometry(0,0,list->width(),listData().count()*item()->height());
    connect(list,SIGNAL(selectItem(QVariant)),this,SLOT(setCurrentData(QVariant)));
    list->hide();
}

WidgetFactory PullDownList::widgetFactory() const
{
    return m_widgetFactory;
}

void PullDownList::setWidgetFactory(const WidgetFactory &widgetFactory)
{
    m_widgetFactory = widgetFactory;
}

void PullDownList::resizeEvent(QResizeEvent *event)
{

    pushBtn->setGeometry(this->width()-pushBtn->width(),0,
                         pushBtn->width(),this->height());
    if(item()!=NULL)
        item()->setGeometry(0,0,
                        this->width()-pushBtn->width(),this->height());


}

void PullDownList::paintEvent(QPaintEvent *event)
{
    QPoint p=item()->mapToGlobal(item()->pos());
    if(list!=NULL)
        list->setGeometry(p.x(),p.y()+item()->height(),
                      item()->width(),list->height());
}

int PullDownList::listMaxinumHeight() const
{
    return m_listMaxinumHeight;
}

void PullDownList::setListMaxinumHeight(int listMaxinumHeight)
{
    m_listMaxinumHeight = listMaxinumHeight;
}


void PullDownList::setItem(FWidget *item)
{
    m_item = item;
}

QList<QVariant> PullDownList::listData() const
{
    return m_listData;
}

void PullDownList::setListData(const QList<QVariant> &listData)
{
    m_listData = listData;
    createDataListFrame();
}

FWidget *PullDownList::item() const
{
    return m_item;
}
