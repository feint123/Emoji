#ifndef FBUTTON_H
#define FBUTTON_H

#include <QWidget>
#include <QObject>
#include <QPushButton>
#include <QMouseEvent>
class FButton : public QPushButton
{
    Q_OBJECT
    Q_PROPERTY(int borderRadius READ borderRadius WRITE setBorderRadius NOTIFY borderRadiusChanged)
    Q_PROPERTY(QString bgColor READ bgColor WRITE setBgColor NOTIFY bgColorChanged)
    Q_PROPERTY(QString color READ color WRITE setColor NOTIFY colorChanged)
    Q_PROPERTY(int maxShadow READ maxShadow WRITE setMaxShadow)
    Q_PROPERTY(int shadow READ shadow WRITE setShadow)

public:
    FButton(QWidget *parent = 0);

    int borderRadius() const;

    int shadow() const;

    int maxShadow() const;

    QString bgColor() const;

    QString color() const;


public slots:

    void setBorderRadius(int borderRadius);

    void setShadow(int shadow);

    void setMaxShadow(int maxShadow=15);

    void setBgColor(QString bgColor);

    void setColor(QString color);


signals:
    void borderRadiusChanged(int borderRadius);

    void bgColorChanged(QString bgColor);

    void colorChanged(QString color);

private slots:
    void updateStyle();

private:
    int m_borderRadius;
    void enterEvent(QEvent* event);
    void leaveEvent(QEvent* enent);
    int m_shadow;
    int m_maxShadow;
    QString baseStyle;
    QString currentStyle;
    void setButtonStyle(QString bg, QString color, int radius);
    QString m_bgColor;
    QString m_color;
    QString m_pressColor;
};



#endif
