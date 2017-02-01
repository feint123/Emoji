#include "controlfloatbutton.h"

#include <util/graphic/animationutil.h>

ControlFloatButton::ControlFloatButton(QWidget *parent):
    QFrame(parent)
{
    this->controlBtn=createBasicButton();
    connect(controlBtn,SIGNAL(clicked(bool)),this,SLOT(onControlClicked()));

    setWindowFlags(Qt::FramelessWindowHint);
    setAutoFillBackground(false);
}

void ControlFloatButton::addBtn(const QIcon &icon)
{
    addBtn(icon,"");
}

void ControlFloatButton::addBtn(const QIcon &icon, QString tip)
{
    FButton *btn=createBasicButton();
    btn->setIcon(icon);
    btn->setToolTip(tip);
    btn->installEventFilter(this);
    btn->setVisible(false);
    btnList.append(btn);
    controlBtn->raise();
}

void ControlFloatButton::setIcon(const QIcon &showed, const QIcon &hide)
{
    controlBtn->setIcon(showed);
    this->hideIcon=hide;
    this->showedIcon=showed;
}

FButton *ControlFloatButton::createBasicButton()
{
    FButton *btn=new FButton(this);
    btn->setMaxShadow(15);
    btn->setBgColor("rgb(245,245,245,180)");
    btn->setBorderRadius(10);
    return btn;
}

void ControlFloatButton::onControlClicked()
{

    if(showed)
    {

        this->setGeometry(this->x(),this->y()-btnList.count()*this->width(),
                          this->width(),this->width()*btnList.count()+this->width());
        for(int i=0;i<btnList.count();i++)
        {
            btnList.at(i)->setVisible(true);
            AnimationUtil::GeometryAnim(btnList.at(i)->geometry(),
                                        QRect(0,i*this->width(),this->width(),this->width()),
                                        btnList.at(i),500);

        }
        controlBtn->setIcon(hideIcon);
        showed=!showed;
    }
    else{
        int i=0;
        for(;i<btnList.count()-1;i++){
            AnimationUtil::GeometryAnim(btnList.at(i)->geometry(),
                                        QRect(0,this->height()-this->width(),this->width(),this->width()),
                                        btnList.at(i),500);

        }
        QPropertyAnimation *anim=AnimationUtil::GeometryAnim(btnList.at(i)->geometry(),
                                                             QRect(0,this->height()-this->width(),this->width(),this->width()),
                                                             btnList.at(i),500);

        connect(anim,SIGNAL(finished()),this,SLOT(restore()));

        controlBtn->setIcon(showedIcon);
    }
}

void ControlFloatButton::restore()
{
    this->setGeometry(this->x(),this->y()+btnList.count()*this->width(),this->width(),this->width());
    for(FButton *btn:btnList)
        btn->setVisible(false);
    showed=!showed;
}

void ControlFloatButton::paintEvent(QPaintEvent *event)
{

}

void ControlFloatButton::resizeEvent(QResizeEvent *event)
{
    for(FButton *btn:btnList)
    {
        btn->setGeometry(0,this->height()-this->width(),this->width(),this->width());
    }
    controlBtn->setGeometry(0,this->height()-this->width(),this->width(),this->width());
}

bool ControlFloatButton::eventFilter(QObject *watched, QEvent *event)
{
    if(event->type()==QEvent::MouseButtonPress)
    {
        for(int i=0;i<btnList.count();i++)
        {
            if(btnList.at(i)==watched)
                emit controlClicked(i);
        }
    }
}


