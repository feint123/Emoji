#include "listview.h"
#include <QDebug>
#include <QPushButton>
#include <QScrollBar>
#include <util/json/objecttojson.h>
ListView::ListView(QWidget *parent) :
    QFrame(parent)
{



}

ListView::~ListView()
{

}




void ListView::setOrientation(ListView::Orien orien)
{
    if(orien==ListView::Horizontal)
        this->box->setDirection(QBoxLayout::LeftToRight);

}


void ListView::setData(QList<QVariant> data)
{
    this->data=data;
}

void ListView::addData(QList<QVariant> data)
{
    this->data.clear();
    this->data=data;
    for(QWidget *widget:itemList)
        widget->deleteLater();
    itemList.clear();
    setItem(this->item);
    setScrollY(0);
    setFocusIndex(0);
    verticalLayout();
}



void ListView::setItem(ListItem* item)
{
    this->item=item;
    bool oneItem=true;
    foreach (QVariant dataitem, this->data) {
        item->updateItem(dataitem);
        item->getGraphic()->installEventFilter(this);
        item->getGraphic()->setMouseTracking(true);
        this->itemList.append(item->getGraphic());
        item->getGraphic()->setParent(this);
        item->getGraphic()->show();
        if(oneItem)
        {
            setFocusIndex(0);
            oneItem=false;
        }

    }
}


void ListView::setBackgroundColor(QColor color)
{

}

int ListView::firstVisibleItemIndex()
{
    return 0;
}



int ListView::scrollY() const
{
    return m_scrollY;
}

int ListView::focusIndex() const
{
    return m_focusIndex;
}

void ListView::setScrollY(int scrollY)
{
    m_scrollY = scrollY;

    emit scrollYChanged(scrollY);
}

void ListView::createFocus()
{
    QWidget *currentWidget=this->itemList.at(focusIndex());
    currentWidget->setObjectName("focus");
    currentWidget->setStyleSheet(selectStyle());
   // currentWidget->resize(currentWidget->width()+8,currentWidget->height()+8);
    //currentWidget->update();
    for(QWidget *widget:itemList)
    {
        if(widget!=currentWidget)
        {
            widget->setObjectName("noFocus");
            widget->setStyleSheet(unSelectStyle());
        }

    }
}

void ListView::changeFocus()
{
    while(true){
        if(itemList.count()==0){
            break;
        }
        else if(itemList.count()>=focusIndex()+1){
            if(useFocus())
                createFocus();
            break;
        }
        else {
            setFocusIndex(focusIndex()-1);
        }

    }
}

void ListView::setFocusIndex(int focusIndex)
{
    if(m_focusIndex==focusIndex)
        return;
    m_focusIndex = focusIndex;
    emit focusIndexChanged(focusIndex);
}

void ListView::setSelectStyle(QString selectStyle)
{
    m_selectStyle = selectStyle;
}

void ListView::setUnSelectStyle(QString unSelectStyle)
{
    m_unSelectStyle = unSelectStyle;
}

void ListView::addValue(QVariant variant)
{
    this->data.append(variant);
    item->updateItem(variant);
    item->getGraphic()->installEventFilter(this);
    item->getGraphic()->setMouseTracking(true);
    itemList.append(item->getGraphic());
    item->getGraphic()->setParent(this);
    item->getGraphic()->show();
    setFocusIndex(itemList.count()-1);
    verticalLayout();
}

void ListView::removeItem(int i)
{
    itemList.removeAt(i);
    verticalLayout();
}

void ListView::setMargin(QMargins margin)
{
    if (m_margin == margin)
        return;

    m_margin = margin;
    emit marginChanged(margin);
}

void ListView::setSpacing(int spacing)
{
    m_spacing = spacing;
}

void ListView::setContentsRect(QRect contentsRect)
{
    m_contentsRect = contentsRect;
}

void ListView::scrollContent(int scroll)
{
    verticalLayout();
    vScroll->setValue(scroll);
}

void ListView::setBgColor(QColor bgColor)
{
    m_bgColor = bgColor;
}

void ListView::setBg(Background value)
{
    bg = value;
}

void ListView::verticalLayout()
{
    for(int i=0;i<itemList.count();i++)
    {

        QWidget *widget=itemList.at(i);

        widget->resize(this->width()-(margin().left()+margin().right()),widget->height());

        widget->setGeometry((this->width()-widget->width())/2,
                            -scrollY()+margin().top()+i*(widget->height()+spacing()),
                            widget->width(),widget->height());

    }

    vScroll->resize(8,this->height());
    vScroll->setGeometry(this->width()-vScroll->width(),0,vScroll->width(),vScroll->height());
    if(getContentHeight()>this->height())
    {
        canScrollShow=true;
        if(!vScroll->isVisible())
            vScroll->show();
        vScroll->setRange(0,getContentHeight()-this->height());
        vScroll->setPageStep(this->height());
        vScroll->raise();

        if(scrollY()>getContentHeight()-this->height()){
            m_scrollY=getContentHeight()-this->height();
        }
    }
    else{
        canScrollShow=false;
        m_scrollY=0;
        vScroll->setRange(0,0);
        vScroll->setPageStep(this->height());
        vScroll->hide();
    }
}

int ListView::getContentHeight()
{
    int contentHeight=margin().top()+margin().bottom();
    for(QWidget *widget:itemList)
        contentHeight+=widget->height()+this->spacing();
    return contentHeight-spacing();
}

void ListView::createView()
{
    vScroll=new QScrollBar(this);

    vScroll->setOrientation(Qt::Vertical);

    vScroll->setStyleSheet(tr("QScrollBar:vertical::add-page,QScrollBar:vertical::add-page{background:%2;border-radius:4px;}"

                           "QScrollBar::handle{border-radius:4px;background:%1;}"

                           "QScrollBar::add-line{height:1px;width:0px;}"

                           "QScrollBar::sub-line{height:0px;}"
                           "QScrollBar:vertical{width:8px;}").arg(scrollHandle()).arg(scrollPage()));


    baseStyle=tr("#scrollAreaWidgetContents{background:%1}");

    setSelectStyle("#focus{border:4px solid #3176ff;}");
    setUnSelectStyle("#unFocus{border:none}");

    connect(this->vScroll,SIGNAL(valueChanged(int)),this,SLOT(setScrollY(int)));
    connect(this,SIGNAL(scrollYChanged(int)),this,SLOT(scrollContent(int)));
    connect(this,SIGNAL(focusIndexChanged(int)),this,SLOT(changeFocus()));
}

void ListView::resizeEvent(QResizeEvent *event)
{
    verticalLayout();
}

void ListView::mouseMoveEvent(QMouseEvent *event)
{
//    if(event->x()>(this->width()-vScroll->width()*2)&&canScrollShow)
//        vScroll->show();
//    else
//        vScroll->hide();
}

void ListView::wheelEvent(QWheelEvent *event)
{
    int scroll=scrollY()-event->delta();
    if(scroll>vScroll->maximum()) scroll=vScroll->maximum();
    if(scroll<vScroll->minimum()) scroll=vScroll->minimum();
    if(canScrollShow)
        setScrollY(scroll);
}

void ListView::paintEvent(QPaintEvent *event)
{
    if(bg!=NULL)
        (*bg)(this,QImage(),bgColor());
}


bool ListView::eventFilter(QObject *watched, QEvent *event)
{

    if(event->type()==QEvent::MouseMove)
        this->mouseMoveEvent((QMouseEvent *)event);

    for(int i=0;i<itemList.size();i++)
    {
        if(itemList.at(i)==watched)
        {
            if(event->type()==QEvent::MouseButtonPress)
            {

                setFocusIndex(i);

                emit this->selectItem(this->data.at(i));

                emit this->selectItemIndex(i);
            }
            if(event->type()==QEvent::MouseButtonDblClick)
            {
                emit this->selectItemDouble(this->data.at(i));
            }

        }
    }
}

QString ListView::selectStyle() const
{
    return m_selectStyle;
}

QString ListView::unSelectStyle() const
{
    return m_unSelectStyle;
}


int ListView::spacing() const
{
    return m_spacing;
}

QRect ListView::contentsRect() const
{
    return m_contentsRect;
}

QColor ListView::bgColor() const
{
    return m_bgColor;
}

QMargins ListView::margin() const
{
    return m_margin;
}

QVariant ListView::getCurrentItem() const
{
    return data.at(focusIndex());
}


QWidget *ListView::getCurrentWidget() const
{
    return itemList.at(focusIndex());
}

void ListView::createDailyStyle()
{
 //   ui->scrollAreaWidgetContents->setStyleSheet(baseStyle.arg("#f9f9f9"));
}

void ListView::createDarkStyle()
{
  //  ui->scrollAreaWidgetContents->setStyleSheet(baseStyle.arg("#404244"));
}
