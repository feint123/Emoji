#include "recircleheader.h"
#include "ui_recircleheader.h"

#include <util/appcolorhelper.h>
#include <util/screenfit.h>

#include <plug/appstatic.h>

#include <qevent.h>
#include <qpainter.h>
#include <qpropertyanimation.h>
#include<QDebug>

RecircleHeader::RecircleHeader(QWidget *parent) :
    AbstractTabBar(parent)
{
    setWindowFlags(Qt::FramelessWindowHint);
    setStyleSheet(tr("QPushButton{border:none;"
                     "height:%2;color:white;"
                     "background:%1}")
                  .arg("rgb(39, 84, 200,200)")
                  .arg(AppStatic::toolHeight));

    setUnderLineHeight(4);
}

RecircleHeader::~RecircleHeader()
{

}

int RecircleHeader::underLineHeight() const
{
    return m_underLineHeight;
}

QRect RecircleHeader::underLine() const
{
    return m_underLine;
}


void RecircleHeader::addItem(QString text)
{
    QPushButton *btn=new QPushButton(this);
    btn->setText(text);
    addTab(btn);
}



void RecircleHeader::setUnderLineHeight(int underLineHeight)
{
    m_underLineHeight = underLineHeight;
}

void RecircleHeader::setUnderLine(QRect underLine)
{
    if (m_underLine == underLine)
        return;

    m_underLine = underLine;
    update();
    emit underLineChanged(underLine);
}


void RecircleHeader::resizeEvent(QResizeEvent *event)
{

    for(int i=0;i<btnList.count();i++)
        btnList.at(i)->
                setGeometry(i*this->width()/4,0,this->width()/4,
                            this->height()-underLineHeight());

    setUnderLine(QRect(checkButton->x(),this->height()-underLineHeight(),
                       this->width()/btnList.count(),underLineHeight()));
}

void RecircleHeader::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setBrush(QBrush(QColor(39, 84,200,200)));
    painter.setPen(Qt::transparent);
    painter.drawRect(0,this->height()-underLineHeight(),
                     this->width(),underLineHeight());
    painter.setBrush(QBrush(Qt::white));

    painter.drawRect(underLine());
}



QPropertyAnimation *RecircleHeader::createAnim()
{
    QPropertyAnimation *anim=new QPropertyAnimation(this,"underLine");
    anim->setStartValue(QRect(checkButton->x(),this->height()-underLineHeight(),
                                      this->width()/btnList.count(),underLineHeight()));
    return anim;
}

void RecircleHeader::startAnim(QPropertyAnimation *anim)
{
    anim->setEndValue(QRect(checkButton->x(),this->height()-underLineHeight(),
                            this->width()/btnList.count(),underLineHeight()));
    anim->setDuration(500);
    anim->setEasingCurve(QEasingCurve::InOutCirc);
    anim->start();
}


