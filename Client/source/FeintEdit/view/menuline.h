#ifndef MENULINE_H
#define MENULINE_H

#include "abstracttabbar.h"

#include <QFrame>
#include <QIcon>

#include <widget/button/menubutton.h>



class MenuLine:public AbstractTabBar
{
    Q_OBJECT

    Q_PROPERTY(QString bgColor READ bgColor WRITE setBgColor)
    Q_PROPERTY(QString checkColor READ checkColor WRITE setCheckColor)
    Q_PROPERTY(QRect checkRect READ checkRect WRITE setCheckRect NOTIFY checkRectChanged)
public:
    static MenuLine* getInstance(QWidget *parent=0);
    ~MenuLine();
    void addItem(const QString icon, const QString tip);
    void setClickItem(int i);
signals:
    void checkRectChanged(QRect checkRect);

private:

    static MenuLine *line;

    MenuLine(QWidget *parent);

    QString m_bgColor;

    QString m_checkColor;

    QRect m_checkRect;

public:

    QString bgColor() const;

    QString checkColor() const;

    QRect checkRect() const;

public slots:

    void setBgColor(QString bgColor);

    void setCheckColor(QString checkColor);

    void setCheckRect(QRect checkRect);

protected:
    void resizeEvent(QResizeEvent *event);

    // QWidget interface
protected:
    void paintEvent(QPaintEvent *event);

    // AbstractTabBar interface
protected:
    QPropertyAnimation *createAnim();
    void startAnim(QPropertyAnimation *anim);
};

#endif // MENULINE_H
