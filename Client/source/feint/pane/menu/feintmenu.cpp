#include "feintmenu.h"
#include "ui_feintmenu.h"
#include <QDebug>
#include <QGraphicsDropShadowEffect>
#include <QPainter>
#include <QPushButton>


FeintMenu::FeintMenu(QWidget *parent,FeintSetting::STYLE style) :
    QWidget(parent),
    ui(new Ui::FeintMenu)
{
    flag=true;
    ui->setupUi(this);

    setAutoFillBackground(false);
    setAttribute(Qt::WA_TranslucentBackground, true);

    topItemCount=0;
    this->toolBox=new QToolBox;

    this->toolBox->layout()->setSpacing(0);
    ui->basic->layout()->addWidget(toolBox);

    setColorStyle(style);
}

FeintMenu::~FeintMenu()
{
    flag=false;
    delete ui;
}


void FeintMenu::addTopItem(const QString &name)
{
    addTopItem(name,QIcon());

}

void FeintMenu::addTopItem(const QString &name, const QIcon &icon)
{
    topItemCount++;
    QWidget* widget=createItem();
    itemList.append(widget);
    toolBox->addItem(widget,icon,name);
    subId=0;
}

void FeintMenu::addSubItem(int topId,const QString &name,const QIcon &icon)
{

    QWidget *widget=itemList.at(topId);
    MenuButton *mb=new MenuButton(widget);

    mb->setText(name);
    mb->setIcon(icon);
    mb->setTopId(topId);
    mb->setId(subId++);
    mb->installEventFilter(this);
    this->menuBtnList.append(mb);
    ((QVBoxLayout*)widget->layout())->addWidget(mb);
}

void FeintMenu::finishSub(int topId)
{
    ((QVBoxLayout*)itemList.at(topId)->layout())->addStretch(0);
}

void FeintMenu::setMenuIndex(int i)
{
    this->toolBox->setCurrentIndex(i);
}

QWidget *FeintMenu::createItem()
{
    QWidget *widget=new QWidget();

    QVBoxLayout *vb=new QVBoxLayout(widget);
    vb->setContentsMargins(0,0,0,0);
    vb->setSpacing(4);
    return widget;
}

void FeintMenu::setAllColor()
{
    setStyleSheet(tr("#basic{background:%1;}").arg(this->tabBackgroundColor()));
    baseStyle=tr("QToolBox::tab{border:0px solid #ccc;color:%1;font-size:12pt;font-weight:bold;"
                 "padding-left:8px}QToolBoxButton{min-height:42px;}");

    currentStyle=baseStyle.arg(m_tabColor);
    toolBox->setStyleSheet(currentStyle);
    setSubBgColor();
    setMenuBtnColor();
}

void FeintMenu::createDailyStyle()
{

    m_tabColor="#404244";
    m_boxColor="#252526";

    m_tabBackgroundColor="#dcdbdc";
    m_boxBackgroundColor="#c0c3c4";

    setAllColor();
}

void FeintMenu::createDarkStyle()
{
    //一级菜单的字体颜色
    m_tabColor="#999";
    //二级菜单字体颜色
    m_boxColor="#ccc";
    //一级菜单背景色,二级菜单的背景色
    m_tabBackgroundColor="#1d181f";
    //二级菜单中按钮的背景色
    m_boxBackgroundColor="#666";
    //设置一级菜单的背景色

    setAllColor();
}

void FeintMenu::setSubBgColor()
{
    for(QWidget *widget:itemList)
    {
        widget->setStyleSheet(tr("background:%1;").arg(this->tabBackgroundColor()));
    }
}

void FeintMenu::setMenuBtnColor()
{
    for(MenuButton *mb:menuBtnList)
    {
         mb->setCheckColor(this->boxBackgroundColor());
         mb->setColor(this->tabBackgroundColor(),this->boxColor());
    }
}


QString FeintMenu::boxColor() const
{
    return m_boxColor;
}

QString FeintMenu::boxBackgroundColor() const
{
    return m_boxBackgroundColor;
}

QString FeintMenu::tabColor() const
{
    return m_tabColor;
}

QString FeintMenu::tabBackgroundColor() const
{
    return m_tabBackgroundColor;
}

QString FeintMenu::name() const
{
    return m_name;
}

QString FeintMenu::intro() const
{
    return m_intro;
}

void FeintMenu::setBoxColor(QString boxColor)
{
    if (m_boxColor == boxColor)
        return;

    m_boxColor = boxColor;
    emit boxColorChanged(boxColor);
}

void FeintMenu::setPortrait(QString url)
{
    QPixmap map;
    map.load(url);
    ui->portrait->setPixmap(map);
    ui->portrait->update();
}

void FeintMenu::setBoxBackgroundColor(QString boxBackgroundColor)
{
    if (m_boxBackgroundColor == boxBackgroundColor)
        return;

    m_boxBackgroundColor = boxBackgroundColor;
    emit boxBackgroundColorChanged(boxBackgroundColor);
}

void FeintMenu::setTabColor(QString tabColor)
{
    if (m_tabColor == tabColor)
        return;

    m_tabColor = tabColor;
    emit tabColorChanged(tabColor);
}

void FeintMenu::setTabBackgroundColor(QString tabBackgroundColor)
{
    if (m_tabBackgroundColor == tabBackgroundColor)
        return;

    m_tabBackgroundColor = tabBackgroundColor;
    emit tabBackgroundColorChanged(tabBackgroundColor);
}

void FeintMenu::setName(QString name)
{
    if (m_name == name)
        return;

    m_name = name;
    ui->nameLab->setText(name);
    emit nameChanged(name);
}

void FeintMenu::setIntro(QString intro)
{
    if (m_intro == intro)
        return;

    m_intro = intro;
    ui->introLab->setText(intro);
    emit introChanged(intro);
}

bool FeintMenu::eventFilter(QObject *watched, QEvent *event)
{
    if(event->type()==QEvent::MouseButtonPress)
    {
        MenuButton *mb=(MenuButton*)watched;
        mb->setState(true);
        for(MenuButton *btn:this->menuBtnList)
        {
            if(btn!=mb)
            {
                btn->setState(false);
            }
        }
        emit menuItemClicked(mb->getTopId(),mb->getId());
        return true;
    }
    return false;
}

