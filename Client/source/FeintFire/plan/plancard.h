#ifndef PLANCARD_H
#define PLANCARD_H

#include "plan.h"

#include <QPaintEvent>
#include <QPropertyAnimation>
#include <QWidget>

#include <widget/frame/fscaleframe.h>

#include <widget/view/listitem.h>

namespace Ui {
class PlanCard;
}

class PlanCard : public FScaleFrame
{
    Q_OBJECT
    Q_PROPERTY(QString circleColor READ circleColor WRITE setCircleColor NOTIFY circleColorChanged)
    Q_PROPERTY(QString typeTip READ typeTip WRITE setTypeTip NOTIFY typeTipChanged)
    Q_PROPERTY(QString content READ content WRITE setContent NOTIFY contentChanged)
    Q_PROPERTY(QString time READ time WRITE setTime NOTIFY timeChanged)
    Q_PROPERTY(QString title READ title WRITE setTitle NOTIFY titleChanged)
    Q_PROPERTY(int id READ id WRITE setId)

    Q_PROPERTY(qreal opacity READ opacity WRITE setOpacity)
public:
    explicit PlanCard(QWidget *parent = 0);
    ~PlanCard();

    QString circleColor() const;

    QString typeTip() const;

    QString content() const;

    QString time() const;

    QString title() const;

    qreal opacity() const;

    int id() const;

public slots:
    void setCircleColor(QString circleColor);

    void setTypeTip(QString typeTip);

    void setContent(QString content);

    void setTime(QString time);

    void setTitle(QString title);

    void setOpacity(qreal opacity);


    void setId(int id);

signals:
    void circleColorChanged(QString circleColor);

    void typeTipChanged(QString typeTip);

    void contentChanged(QString content);

    void timeChanged(QString time);

    void titleChanged(QString title);

    void deleteCard(int id);


private:
    Ui::PlanCard *ui;
    QString m_circleColor;
    QString m_typeTip;
    QString m_content;
    QString m_time;
    QString m_title;

    void paintEvent(QPaintEvent *event);



    QPropertyAnimation *prop;

    qreal m_opacity;

    bool delState=false;
    int m_id;

    // QWidget interface
protected:
    void enterEvent(QEvent *event);
    void leaveEvent(QEvent *event);
private slots:
    void on_delBtn_clicked();
};

#endif // PLANCARD_H
