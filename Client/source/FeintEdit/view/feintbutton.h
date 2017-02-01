#ifndef FEINTBUTTON_H
#define FEINTBUTTON_H

#include <QPushButton>



class FeintButton:public QPushButton
{
    Q_OBJECT

    Q_PROPERTY(QImage normal READ normal WRITE setNormal)
    Q_PROPERTY(QImage hover READ hover WRITE setHover)
    Q_PROPERTY(QImage click READ click WRITE setClick)
public:
    FeintButton(QWidget *parent);


    QImage normal() const
    {
        return m_normal;
    }

    QImage hover() const
    {
        return m_hover;
    }

    QImage click() const
    {
        return m_click;
    }

public slots:
    void setNormal(QImage normal)
    {
        m_normal = normal;
        state = normal;
    }

    void setHover(QImage hover)
    {
        m_hover = hover;
    }

    void setClick(QImage click)
    {
        m_click = click;
    }

private:


    QImage m_normal;
    QImage m_hover;
    QImage m_click;

    QImage state;

    // QWidget interface
protected:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void enterEvent(QEvent *event);
    void leaveEvent(QEvent *event);
};

#endif // FEINTBUTTON_H
