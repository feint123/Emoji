#include "menubutton.h"

#include <QGraphicsDropShadowEffect>

MenuButton::MenuButton(QWidget *parent):
    QPushButton(parent)
{
//    QGraphicsDropShadowEffect *ef=new QGraphicsDropShadowEffect(this);
//    ef->setXOffset(2);
//    ef->setYOffset(0);
//    ef->setBlurRadius(8);
//    ef->setColor(QColor("#aaa"));
//    this->setGraphicsEffect(ef);
    borderColor="#0076FF";
    color="#0076FF";
    baseStyle=tr("MenuButton{border:1px solid %1;color:%2;border-radius:5px;width:60px;height:60px;"
                 "text-align:center;background:%1}MenuButton:hover{background:%2;color:#f5f5f5}");
    currentStyle=baseStyle.arg(borderColor).arg(color);
    this->setStyleSheet(currentStyle);
    this->resize(60,60);
}

int MenuButton::getTopId() const
{
    return topId;
}

void MenuButton::setTopId(int value)
{
    topId = value;
}

void MenuButton::setColor(const QString &bgColor, const QString &color)
{
    this->color=color;
    borderColor=bgColor;
    currentStyle=baseStyle.arg(borderColor).arg(color);
    this->setStyleSheet(currentStyle);
}



QString MenuButton::getColor() const
{
    return color;
}

int MenuButton::getId() const
{
    return id;
}

void MenuButton::setId(int value)
{
    id = value;
}
