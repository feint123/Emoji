#include "gridview.h"
#include <QDebug>
#include <QEvent>
#include <QHBoxLayout>
#include <QPainter>
#include <QPushButton>

GridView::GridView(QWidget *parent):
    QFrame(parent)
{
   setHasFocus(true);
   setFocusColor("#39b054");
   hScrollBar=new QScrollBar(this);
   hScrollBar->setOrientation(Qt::Horizontal);
   connect(hScrollBar,SIGNAL(valueChanged(int)),this,SLOT(setScroll(int)));
   connect(this,SIGNAL(scrollChanged(int)),this,SLOT(scrollView(int)));
}

GridView::~GridView()
{
    for(QWidget *widget:itemList)
        delete widget;
}

void GridView::setData(const QList<QVariant> &value)
{
    this->valueList=value;   
}

void GridView::setItem(ListItem *value)
{
    this->item=value;
    for(QVariant itemValue:this->valueList)
    {
        item->updateItem(itemValue);
        item->getGraphic()->setParent(this);
        item->getGraphic()->installEventFilter(this);
        itemList.append(item->getGraphic());
    }
}

QMargins GridView::padding() const
{
    return m_padding;
}

int GridView::spacing() const
{
    return m_spacing;
}

int GridView::horizontalSpacing() const
{
    return m_horizontalSpacing;
}

int GridView::verticalSpacing() const
{
    return m_verticalSpacing;
}

int GridView::scroll() const
{
    return m_scroll;
}

void GridView::setPadding(QMargins padding)
{
    m_padding = padding;
    updateResize();
}

void GridView::setSpacing(int spacing)
{
    m_spacing = spacing;
}

void GridView::setHorizontalSpacing(int horizontalSpacing)
{
    m_horizontalSpacing = horizontalSpacing;
}

void GridView::setVerticalSpacing(int verticalSpacing)
{
    m_verticalSpacing = verticalSpacing;
}

void GridView::setScroll(int scroll)
{
    m_scroll = scroll;
    emit scrollChanged(scroll);
}

void GridView::scrollView(int scroll)
{
    int i=0;
    int j=0;
    for(QWidget *widget:itemList)
    {

        int detaY=padding().top()+i*(widget->height()+verticalSpacing());
        if(detaY+widget->height()+padding().bottom()-verticalSpacing()
                >this->height()&&i>0)
        {
            j++;
            i=0;
            detaY=padding().top();
        }

        detaX=-scroll+padding().left()+j*(widget->width()+horizontalSpacing());

        widget->setGeometry(detaX,
                            detaY,
                            widget->width(),widget->height());
        i++;
        lastWidth=widget->width();
    }

}

void GridView::setFocusColor(QString focusColor)
{
    m_focusColor = focusColor;
}

void GridView::setHasFocus(bool hasFocus)
{
    m_hasFocus = hasFocus;
}

void GridView::setBgImage(const QImage &value)
{
    bgImage = value;
    updateResize();
}

void GridView::setBgFun(const bg &value)
{
    bgFun = value;
}


void GridView::paintEvent(QPaintEvent *event)
{
    (*bgFun)(this,bgImage,padding());

}

void GridView::setFocus(QWidget *focusWidget)
{

    for(QWidget *widget:itemList){
        widget->setObjectName("noFocus");
        widget->setStyleSheet("noFocus{border:none}");
    }
    focusWidget->setObjectName("focus");
    focusWidget->setStyleSheet(tr("#focus{border:2px solid %1}").arg(focusColor()));
}

void GridView::updateResize()
{
    hScrollBar->setGeometry(0,this->height()-hScrollBar->height(),this->width(),16);

    int contentWidth=detaX+(lastWidth+padding().right()+scroll());
    if(contentWidth>this->width())
    {
        hScrollBar->show();
        hScrollBar->setRange(0,contentWidth-this->width());
        hScrollBar->setPageStep(this->width());
    }
    else{
        hScrollBar->hide();
        setScroll(0);
    }
    scrollView(scroll());

    update();
}


void GridView::resizeEvent(QResizeEvent *event)
{
    updateResize();
}

bool GridView::eventFilter(QObject *watched, QEvent *event)
{
    for(int i=0;i<itemList.count();i++)
    {
            if(itemList.at(i)==watched)
            {
                if(event->type()==QEvent::MouseButtonPress)
                {
                    if(hasFocus())
                        setFocus((QWidget*)watched);
                    emit selectItem((QWidget*)watched);
                    emit selectItemValue(valueList.at(i));
                }
                if(event->type()==QEvent::MouseButtonDblClick)
                {
                    emit selectItemDouble((QWidget*)watched);
                    emit selectItemValueDouble(valueList.at(i));
                }
            }
    }

}

QString GridView::focusColor() const
{
    return m_focusColor;
}

bool GridView::hasFocus() const
{
    return m_hasFocus;
}
