#ifndef FCIRCLE_H
#define FCIRCLE_H

#include <QLabel>
#include <QPaintEvent>

class FCircle : public QLabel
{
    Q_OBJECT
    Q_PROPERTY(QString color READ color WRITE setColor NOTIFY colorChanged)
    Q_PROPERTY(QString flag READ flag WRITE setFlag NOTIFY flagChanged)
    Q_PROPERTY(int radius READ radius WRITE setRadius NOTIFY radiusChanged)
    QString m_color;

    QString m_flag;

    int m_radius;

public:
    FCircle(QWidget *parent = 0);
    void paintEvent(QPaintEvent *event);
    QString color() const;
    QString flag() const;

    int radius() const;

public slots:
    void setColor(QString color);
    void setFlag(QString flag);

    void setRadius(int radius);

signals:
    void colorChanged(QString color);
    void flagChanged(QString flag);
    void radiusChanged(int radius);
};

#endif
