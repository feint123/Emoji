#include "tipdialog.h"

#include <QPainter>
#include <QTimer>
#include <QDebug>
#include <util/graphic/animationutil.h>
TipDialog * TipDialog::tipdialog=NULL;
TipDialog::TipDialog(QWidget *parent):
    QDialog(parent)
{
    setAutoFillBackground(false);
    setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_DeleteOnClose);
}

TipDialog *TipDialog::getInstance(QWidget *parent)
{
    if(tipdialog==NULL)
        tipdialog=new TipDialog(parent);
    else if(parent!=0&&tipdialog->parent()!=parent)
    {
        tipdialog->setParent(parent);
    }
    return tipdialog;
}

QString TipDialog::tip() const
{
    return m_tip;
}

TipDialog::~TipDialog()
{
    tipdialog=NULL;
}


int TipDialog::fontSize() const
{
    return m_fontSize;
}

int TipDialog::keep() const
{
    return m_keep;
}

void TipDialog::setTip(QString tip)
{
    m_tip = tip;
}


void TipDialog::showTip()
{
    QWidget *parent=(QWidget*)tipdialog->parent();
    timer=new QTimer(this);
    timer->setInterval(keep());
    connect(timer,SIGNAL(timeout()),this,SLOT(hideTip()));

    this->setGeometry(0,parent->height(),parent->width(),this->height());
    this->show();
    AnimationUtil::GeometryAnim(this->geometry(),
                                QRect(0,parent->height()-this->height(),parent->width(),this->height()),
                                this,500);
    timer->start();

}

void TipDialog::setFontSize(int fontSize)
{
    m_fontSize = fontSize;
}

void TipDialog::hideTip()
{
    this->close();
}

void TipDialog::setKeep(int keep)
{
    m_keep = keep;
}

void TipDialog::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QBrush brush;
    brush.setColor(QColor(0x11,0x11,0x11,0xbc));
    brush.setStyle(Qt::SolidPattern);
    painter.setBrush(brush);
    painter.drawRect(0,0,this->width(),this->height());

    QFont font;
    font.setPointSize(fontSize());
    QPen pen;
    pen.setColor(Qt::white);
    painter.setPen(pen);
    painter.setFont(font);
    painter.drawText(height()/2,height()/2+QFontMetrics(font).height()/2,tip());
}

void TipDialog::resizeEvent(QResizeEvent *event)
{
    //this->setGeometry(0,(parent->height()-this->height()),parent->width(),this->height());
}
