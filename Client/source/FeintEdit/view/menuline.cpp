#include "menuline.h"

#include <QPainter>
#include <QDebug>

#include <util/appcolorhelper.h>
#include <util/screenfit.h>
MenuLine *MenuLine::line=NULL;
MenuLine *MenuLine::getInstance(QWidget *parent)
{
    if(line==NULL)
        line=new MenuLine(parent);
    return line;
}

MenuLine::~MenuLine()
{
    line=NULL;
}

MenuLine::MenuLine(QWidget *parent):
    AbstractTabBar(parent)
{
    setAutoFillBackground(false);
    setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);
}

void MenuLine::addItem(const QString icon, const QString tip)
{
    QPushButton *item=new QPushButton(this);

    item->setToolTip(tip);

    item->setStyleSheet(tr("QPushButton{border-image:url(%1);}").arg(icon));

    addTab(item);
}

void MenuLine::setClickItem(int i)
{ 
    dealCheck(btnList.at(i));
}


QString MenuLine::bgColor() const
{
    return m_bgColor;
}

QString MenuLine::checkColor() const
{
    return m_checkColor;
}

QRect MenuLine::checkRect() const
{
    return m_checkRect;
}

void MenuLine::setBgColor(QString bgColor)
{
    m_bgColor = bgColor;
    update();
}

void MenuLine::setCheckColor(QString checkColor)
{
    m_checkColor = checkColor;
}

void MenuLine::setCheckRect(QRect checkRect)
{
    if (m_checkRect == checkRect)
        return;

    m_checkRect = checkRect;
    update();
    emit checkRectChanged(checkRect);
}



void MenuLine::resizeEvent(QResizeEvent *event)
{
    int i=0;
    for(QPushButton *btn:btnList)
    {
        btn->setGeometry(0,i*this->width(),this->width(),this->width());
        i++;
    }

    setCheckRect(QRect(checkButton->x(),checkButton->y(),
                 checkButton->width(),checkButton->height()));
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
    painter.setBrush(QBrush(QColor(checkColor())));
    painter.drawRect(checkRect());
}

QPropertyAnimation *MenuLine::createAnim()
{
    QPropertyAnimation *anim=new QPropertyAnimation(this,"checkRect");
    anim->setStartValue(QRect(checkButton->x(),checkButton->y(),
                                      checkButton->width(),checkButton->height()));
    return anim;
}

void MenuLine::startAnim(QPropertyAnimation *anim)
{

    anim->setEndValue(QRect(checkButton->x(),checkButton->y(),
                            checkButton->width(),checkButton->height()));
    anim->setDuration(300);
    anim->setEasingCurve(QEasingCurve::InOutCirc);
    if(checkButton->isVisible())
        anim->start();
}
