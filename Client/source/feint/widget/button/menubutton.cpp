#include "menubutton.h"

#include <QGraphicsDropShadowEffect>
#include <QDebug>
MenuButton::MenuButton(QWidget *parent):
    QPushButton(parent)
{

    bgColor="#0076FF";
    color="#0076FF";
    baseStyle=tr("MenuButton{border:0px solid %1;color:%2;border-radius:1px;width:60px;height:40px;"
                 "text-align:left;background:%1;padding-left:16px;}");
    currentStyle=baseStyle.arg(color).arg(bgColor);
    this->setStyleSheet(currentStyle);
    connect(this,SIGNAL(stateChanged(bool)),this,SLOT(on_toggled(bool)));
    this->setState(false);
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
    this->bgColor=bgColor;
    currentStyle=baseStyle.arg(bgColor).arg(color);
    this->setStyleSheet(currentStyle);

    if(state())
    {
        setCheckBgColor();
    }
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

void MenuButton::on_toggled(bool checked)
{
  if(checked)
  {
      this->setCheckBgColor();
  }
  else
  {
      this->setColor(this->bgColor,this->color);
  }
}

void MenuButton::setCheckBgColor()
{
    currentStyle=baseStyle.arg(this->checkColor).arg(color);
    this->setStyleSheet(currentStyle);
}

QString MenuButton::getCheckColor() const
{
    return checkColor;
}

void MenuButton::setCheckColor(const QString &value)
{
    checkColor = value;
}

bool MenuButton::state() const
{
    return m_state;
}

void MenuButton::setState(bool state)
{
    if (m_state == state)
        return;

    m_state = state;
    emit stateChanged(state);
}

