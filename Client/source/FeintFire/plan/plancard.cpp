#include "plancard.h"
#include "ui_plancard.h"

#include <QPainter>
#include <QDebug>
#include <QPropertyAnimation>
#include <qgraphicseffect.h>
#include <QGraphicsRotation>
#include <QGraphicsScene>
#include <QGraphicsView>
PlanCard::PlanCard(QWidget *parent) :
    FScaleFrame(parent),
    ui(new Ui::PlanCard)
{
    ui->setupUi(this);
    this->setAutoFillBackground(false);
    QGraphicsOpacityEffect *effect=new QGraphicsOpacityEffect(this);
    effect->setOpacity(0.8);
    ui->toolFrame->setGraphicsEffect(effect);
    ui->toolFrame->hide();
}

PlanCard::~PlanCard()
{
    delete ui;
}

QString PlanCard::circleColor() const
{
    return m_circleColor;
}

QString PlanCard::typeTip() const
{
    return m_typeTip;
}

QString PlanCard::content() const
{
    return m_content;
}

QString PlanCard::time() const
{
    return m_time;
}

QString PlanCard::title() const
{
    return m_title;
}


qreal PlanCard::opacity() const
{
    return m_opacity;
}

int PlanCard::id() const
{
    return m_id;
}


void PlanCard::setCircleColor(QString circleColor)
{
    if (m_circleColor == circleColor)
        return;

    m_circleColor = circleColor;
    ui->typeCircle->setColor(circleColor);
    emit circleColorChanged(circleColor);
}

void PlanCard::setTypeTip(QString typeTip)
{
    if (m_typeTip == typeTip)
        return;

    m_typeTip = typeTip;
    ui->typeCircle->setFlag(typeTip);
    emit typeTipChanged(typeTip);
}

void PlanCard::setContent(QString content)
{
    if (m_content == content)
        return;

    m_content = content;
    ui->tipEdit->setText(content);
    emit contentChanged(content);
}

void PlanCard::setTime(QString time)
{
    if (m_time == time)
        return;

    m_time = time;
    ui->timeLab->setText(time);
    emit timeChanged(time);
}

void PlanCard::setTitle(QString title)
{
    if (m_title == title)
        return;

    m_title = title;
    ui->titleLab->setText(title);
    emit titleChanged(title);
}

void PlanCard::setOpacity(qreal opacity)
{
    m_opacity = opacity;
    QGraphicsOpacityEffect *effect=new QGraphicsOpacityEffect(this);
    effect->setOpacity(opacity);
    this->setGraphicsEffect(effect);
}

void PlanCard::setId(int id)
{
    m_id = id;
}

void PlanCard::paintEvent(QPaintEvent *event)
{
    //  FScaleFrame::paintEvent(event);
    QPainter painter(this);

    QBrush brush;
    brush.setColor(QColor(255,255,255));
    brush.setStyle(Qt::SolidPattern);

    painter.setBrush(brush);
    painter.drawRect(0,this->height()/2-20,this->width(),40);

}




void PlanCard::enterEvent(QEvent *event)
{
    ui->toolFrame->show();
}

void PlanCard::leaveEvent(QEvent *event)
{
    ui->toolFrame->hide();
}

void PlanCard::on_delBtn_clicked()
{
     emit deleteCard(this->id());
}
