#include "feintmenu.h"
#include "ui_feintmenu.h"
#include <QDebug>
#include <QGraphicsDropShadowEffect>
#include <QPushButton>
#include <QGridLayout>

FeintMenu::FeintMenu(QWidget *parent,QString color) :
    QWidget(parent),
    ui(new Ui::FeintMenu)
{
    ui->setupUi(this);

    QGraphicsDropShadowEffect *ef=new QGraphicsDropShadowEffect(this);
    ef->setXOffset(2);
    ef->setYOffset(0);
    ef->setBlurRadius(5);
    ef->setColor(QColor("#ccc"));
    this->setGraphicsEffect(ef);

    topItemCount=0;


    m_tabColor="#404244";
    m_boxColor="#f9f9f9";
    //tab的背景色
    m_tabBackgroundColor="#324d5c";
    m_boxBackgroundColor=color;
    setStyleSheet(tr("#basic{background:%1;}").arg(m_boxBackgroundColor));
    this->toolBox=new QToolBox;
    baseStyle=tr("QToolBox::tab{border-top:1px solid %2;color:%1;font-size:14pt;}QToolBoxButton{min-height:42px;}");
    setAllColor();
    this->toolBox->layout()->setSpacing(0);
    ui->basic->layout()->addWidget(toolBox);
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
    mb->setColor(m_boxColor,m_tabBackgroundColor);
    mb->setText(name);
    mb->setIcon(icon);
    mb->setTopId(topId);
    mb->setId(subId++);
    mb->installEventFilter(this);
    int count=widget->children().count();

    ((QGridLayout*)widget->layout())->addWidget(mb,count/2,count%2);
}

void FeintMenu::finishSub(int topId)
{

   //   QSpacerItem *spacer=new QSpacerItem(0,20,QSizePolicy::Expanding,QSizePolicy::Expanding);
      ((QGridLayout*)itemList.at(topId)->layout())->setRowStretch(0,0);
}

QWidget *FeintMenu::createItem()
{
    QWidget *widget=new QWidget();
    QGridLayout *gl=new QGridLayout(widget);
    gl->setSpacing(24);
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

