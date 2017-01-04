#include "fbutton.h"

#include <QGraphicsDropShadowEffect>
#include <QPropertyAnimation>
#include <QDebug>
FButton::FButton(QWidget *parent) :
    QPushButton(parent)
{

    baseStyle=tr("QPushButton{background:%1;color:%2;border-radius:%3;border:none;padding:2px;}");

    connect(this,SIGNAL(bgColorChanged(QString)),this,SLOT(updateStyle()));
    connect(this,SIGNAL(colorChanged(QString)),this,SLOT(updateStyle()));
    connect(this,SIGNAL(borderRadiusChanged(int)),this,SLOT(updateStyle()));


    setBgColor("#1b7cff");
    setColor("#f9f9f9");
    setBorderRadius(0);

}

int FButton::borderRadius() const
{
    return m_borderRadius;
}

int FButton::shadow() const
{
    return m_shadow;
}

int FButton::maxShadow() const
{
    return m_maxShadow;
}

void FButton::setBorderRadius(int borderRadius)
{
    m_borderRadius = borderRadius;
    emit borderRadiusChanged(borderRadius);
}

void FButton::setShadow(int shadow)
{
    m_shadow = shadow;
    QGraphicsDropShadowEffect *drop=new QGraphicsDropShadowEffect(this);
    drop->setBlurRadius(shadow);
    drop->setOffset(0,0);
    drop->setColor(QColor("#666"));
    this->setGraphicsEffect(drop);
}

void FButton::setMaxShadow(int maxShadow)
{
    m_maxShadow = maxShadow;
}

void FButton::setBgColor(QString bgColor)
{
    if (m_bgColor == bgColor)
        return;

    m_bgColor = bgColor;
    emit bgColorChanged(bgColor);
}

void FButton::setColor(QString color)
{
    if (m_color == color)
        return;

    m_color = color;
    emit colorChanged(color);
}




void FButton::updateStyle()
{
    setButtonStyle(this->bgColor(),this->color(),this->borderRadius());
}

void FButton::enterEvent(QEvent *event)
{
    QPropertyAnimation *prop=new QPropertyAnimation(this,"shadow");
    prop->setStartValue(0);
    prop->setEndValue(maxShadow());
    prop->setDuration(300);
    prop->start();
}

void FButton::leaveEvent(QEvent *enent)
{
    QPropertyAnimation *prop=new QPropertyAnimation(this,"shadow");
    prop->setStartValue(maxShadow());
    prop->setEndValue(0);
    prop->setDuration(300);
    prop->start();
}



void FButton::setButtonStyle(QString bg, QString color, int radius)
{
    currentStyle=baseStyle;
    currentStyle=currentStyle.arg(bg).arg(color).arg(QString::number(radius));
    this->setStyleSheet(currentStyle);
}


QString FButton::bgColor() const
{
    return m_bgColor;
}

QString FButton::color() const
{
    return m_color;
}

