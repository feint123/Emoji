#include "menuline.h"

#include <QPainter>
#include <QDebug>
MenuLine::MenuLine(QWidget *parent):
    QFrame(parent)
{
    setAutoFillBackground(false);
    setWindowFlags(Qt::FramelessWindowHint);

}

void MenuLine::addItem(const QIcon &icon, const QString tip)
{
    MenuButton *item=new MenuButton(this);
    item->setIcon(icon);
    item->setToolTip(tip);
    item->setIconSize(QSize(24,24));
    item->setColor(bgColor(),"");
    item->setCheckColor("#39ae53");
    item->setId(itemList.count());
    item->installEventFilter(this);
    itemList.append(item);

}

void MenuLine::setClickItem(int i)
{
    for(int a=0;a<itemList.count();a++)
    {

        if(a==i){
            itemList.at(i)->setState(true);
            emit menuClick(i);
        }else
            itemList.at(a)->setState(false);
    }
}

bool MenuLine::eventFilter(QObject *watched, QEvent *event)
{
    if(event->type()==QEvent::MouseButtonPress)
    {
        MenuButton *mb=(MenuButton*)watched;
        mb->setState(true);
        for(MenuButton *btn:itemList)
        {
            if(btn!=mb)
            {
                btn->setState(false);
            }
        }
        emit menuClick(((MenuButton*)watched)->getId());
    }
}

QString MenuLine::bgColor() const
{
    return m_bgColor;
}

void MenuLine::setBgColor(QString bgColor)
{
    m_bgColor = bgColor;
    update();
}



void MenuLine::resizeEvent(QResizeEvent *event)
{
    for(MenuButton *btn:itemList)
    {
        btn->setGeometry(0,btn->getId()*this->width(),this->width(),this->width());
    }
}

void MenuLine::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QBrush brush;
    brush.setColor(QColor(bgColor()));
    brush.setStyle(Qt::SolidPattern);
    QPen pen;
    pen.setColor(Qt::transparent);
    painter.setBrush(brush);
    painter.setPen(pen);
    painter.drawRect(0,0,this->width(),this->height());
}
