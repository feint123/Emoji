#include "abstracttabbar.h"

#include <QEvent>

#include <util/screenfit.h>

#include <QDebug>

AbstractTabBar::AbstractTabBar(QWidget *parent):
    QFrame(parent)
{

}

void AbstractTabBar::createView(int i)
{
    btnList.at(i)->setChecked(true);
    checkButton=btnList.at(i);
}

void AbstractTabBar::dealCheck(QObject *watched)
{

    QPropertyAnimation *anim=createAnim();

    updateBtnState(watched);

    if(!isSameBtn){
       startAnim(anim);
    }
}

void AbstractTabBar::addTab(QPushButton *btn)
{
    btn->setParent(this);
    btn->setCheckable(true);
    btn->setChecked(false);
    btn->installEventFilter(this);
    ScreenFit::fitFont(btn);
    btnList.append(btn);
}

QPropertyAnimation *AbstractTabBar::createAnim()
{

}

void AbstractTabBar::startAnim(QPropertyAnimation *anim)
{

}

void AbstractTabBar::updateBtnState(QObject *watched)
{
    for(int i=0;i<btnList.count();i++)
    {
        if(watched==btnList.at(i)){
            btnList.at(i)->setChecked(true);
            if(checkButton==watched)
                isSameBtn=true;
            else{
                isSameBtn=false;
                emit itemClicked(i);
            }
            checkButton=btnList.at(i);

            continue;
        }
        btnList.at(i)->setChecked(false);
    }
}

bool AbstractTabBar::eventFilter(QObject *watched, QEvent *event)
{
    if(event->type()==(QEvent::MouseButtonPress)){

        dealCheck(watched);
    }
}
