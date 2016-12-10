#include "menubutton.h"

MenuButton::MenuButton(QWidget *parent):
    QPushButton(parent)
{
    borderColor="#0076FF";
    color="#0076FF";
    baseStyle=tr("MenuButton{border:1px solid %1;color:%2;border-radius:5px;width:150px;height:32px;text-align:center;}MenuButton:hover{background:%2;color:#fff}");
    currentStyle=baseStyle.arg(borderColor).arg(color);
    this->setStyleSheet(currentStyle);
}

int MenuButton::getTopId() const
{
    return topId;
}

void MenuButton::setTopId(int value)
{
    topId = value;
}

void MenuButton::setColor(const QString &value)
{
    color=value;
    borderColor=value;
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
