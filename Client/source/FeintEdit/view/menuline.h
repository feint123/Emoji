#ifndef MENULINE_H
#define MENULINE_H

#include <QFrame>
#include <QIcon>

#include <widget/button/menubutton.h>



class MenuLine:public QFrame
{
    Q_OBJECT

    Q_PROPERTY(QString bgColor READ bgColor WRITE setBgColor)
public:
    MenuLine(QWidget *parent);
    void addItem(const QIcon &icon,const QString tip);
    void setClickItem(int i);
signals:
    void menuClick(int);
private:
    QList<MenuButton *> itemList;


    QString m_bgColor;

public:
    bool eventFilter(QObject *watched, QEvent *event);




    QString bgColor() const;

public slots:


    void setBgColor(QString bgColor);

protected:
    void resizeEvent(QResizeEvent *event);

    // QWidget interface
protected:
    void paintEvent(QPaintEvent *event);
};

#endif // MENULINE_H
