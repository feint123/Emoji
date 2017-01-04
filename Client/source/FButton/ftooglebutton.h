#ifndef FTOOGLEBUTTON_H
#define FTOOGLEBUTTON_H

#include <QLabel>
#include <QMouseEvent>
#include <QPaintEvent>
#include <QPushButton>
#include <QWidget>

class FToogleButton : public QPushButton
{
    Q_OBJECT
    Q_PROPERTY(QString toggleColor READ toggleColor WRITE setToggleColor NOTIFY toggleColorChanged)
    Q_PROPERTY(QRect toggleRect READ toggleRect WRITE setToggleRect NOTIFY toggleRectChanged)
    Q_PROPERTY(QString onBgColor READ onBgColor WRITE setOnBgColor NOTIFY onBgColorChanged)
    Q_PROPERTY(QString offBgColor READ offBgColor WRITE setOffBgColor NOTIFY offBgColorChanged)
    Q_PROPERTY(int arcRadius READ arcRadius WRITE setArcRadius)
public:
    FToogleButton(QWidget *parent = 0);


    QString toggleColor() const;

    QRect toggleRect() const;

    int arcRadius() const;

    QString toggleBgColor() const;

    QString onBgColor() const;

    QString offBgColor() const;

public slots:
    void setFChecked(bool checked);

    void setToggleColor(QString toggleColor);

    void setToggleRect(QRect toggleRect);

    void setArcRadius(int arcRadius);

    void setToggleBgColor(QString toggleBgColor);

    void setOnBgColor(QString onBgColor);

    void setOffBgColor(QString offBgColor);

signals:
    void toggleColorChanged(QString toggleColor);

    void toggleRectChanged(QRect toggleRect);

    void toggleBgColorChanged(QString toggleBgColor);

    void onBgColorChanged(QString onBgColor);

    void offBgColorChanged(QString offBgColor);

private:
    void paintEvent(QPaintEvent *event);
    QString m_toggleColor;
    QRect m_toggleRect;
    int m_arcRadius;
    QString m_toggleBgColor;
    QString m_onBgColor;
    QString m_offBgColor;
    int detaX,detaY;
};

#endif
