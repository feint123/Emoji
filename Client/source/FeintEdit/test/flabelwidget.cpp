#include "flabelwidget.h"
#include <QDebug>
FLabelWidget::FLabelWidget(QWidget *parent):
    FWidget(parent)
{
    setStyleSheet("background:#000;color:#fff;");
    text=new QLabel(this);
}

void FLabelWidget::setData(QVariant data)
{
    QString t=data.toString();
    text->setText(t);
    qDebug()<<"flabelWidget";
}

void FLabelWidget::resizeEvent(QResizeEvent *event)
{
    text->setGeometry(0,0,this->width(),this->height());
}
