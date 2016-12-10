#include "feintmenu.h"
#include "ui_feintmenu.h"
#include <QDebug>
#include <QPushButton>

FeintMenu::FeintMenu(QWidget *parent,QString color) :
    QWidget(parent),
    ui(new Ui::FeintMenu)
{
    ui->setupUi(this);



    topItemCount=0;

    m_tabColor="#368afc";
    m_boxColor="#368afc";
    m_tabBackgroundColor="#f9f9f9";
    m_boxBackgroundColor=color;
    setStyleSheet(tr("QWidget{background:%1;}").arg(m_boxBackgroundColor));
    this->toolBox=new QToolBox;
    baseStyle=tr("QToolBox::tab{border-top:1px solid %1;border-bottom:1px solid %1;color:%1;background:%2;font-size:14pt;}QToolBoxButton{min-height:32px;}");
    setAllColor();
    this->layout()->addWidget(toolBox);
}

FeintMenu::~FeintMenu()
{
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
    mb->setColor(m_boxColor);
    mb->setText(name);
    mb->setIcon(icon);
    mb->setTopId(topId);
    mb->setId(subId++);
    mb->installEventFilter(this);
    widget->layout()->addWidget(mb);
}

void FeintMenu::finishSub(int topId)
{
    ((QVBoxLayout*)itemList.at(topId)->layout())->addStretch();
}

QWidget *FeintMenu::createItem()
{
    QWidget *widget=new QWidget();

    QVBoxLayout *vb=new QVBoxLayout(widget);
    vb->setSpacing(32);
    return widget;
}

void FeintMenu::setAllColor()
{
    currentStyle=baseStyle.arg(m_tabColor).arg(m_tabBackgroundColor);
    toolBox->setStyleSheet(currentStyle);
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
    setAllColor();
    emit boxBackgroundColorChanged(boxBackgroundColor);
}

void FeintMenu::setTabColor(QString tabColor)
{
    if (m_tabColor == tabColor)
        return;

    m_tabColor = tabColor;
    setAllColor();
    emit tabColorChanged(tabColor);
}

void FeintMenu::setTabBackgroundColor(QString tabBackgroundColor)
{
    if (m_tabBackgroundColor == tabBackgroundColor)
        return;

    m_tabBackgroundColor = tabBackgroundColor;
    setAllColor();
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
        emit menuItemClicked(mb->getTopId(),mb->getId());
        return true;
    }
    return false;
}

