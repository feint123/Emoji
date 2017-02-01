#ifndef GRIDVIEW_H
#define GRIDVIEW_H

#include <QScrollArea>
#include <QScrollBar>
#include <QVariant>
#include "listitem.h"

typedef void (*bg)(QPaintDevice *device,const QColor &color);
class GridView:public QFrame
{
    Q_OBJECT
    Q_PROPERTY(QMargins padding READ padding WRITE setPadding)
    Q_PROPERTY(int spacing READ spacing WRITE setSpacing)
    Q_PROPERTY(int horizontalSpacing READ horizontalSpacing WRITE setHorizontalSpacing)
    Q_PROPERTY(int verticalSpacing READ verticalSpacing WRITE setVerticalSpacing )
    Q_PROPERTY(int scroll READ scroll WRITE setScroll NOTIFY scrollChanged)
    Q_PROPERTY(bool hasFocus READ hasFocus WRITE setHasFocus)
    Q_PROPERTY(QString focusColor READ focusColor WRITE setFocusColor)
    Q_PROPERTY(QColor bgColor READ bgColor WRITE setBgColor)
public:
    GridView(QWidget *parent=0);

    ~GridView();
    void setData(const QList<QVariant> &value);
    
    void setItem(ListItem * value);
    
    void addData(const QList<QVariant> &data);

    QMargins padding() const;
    
    int spacing() const;
    
    int horizontalSpacing() const;

    int verticalSpacing() const;

    int scroll() const;

public slots:
    void setPadding(QMargins padding);
    
    void setSpacing(int spacing);
    
    void setHorizontalSpacing(int horizontalSpacing);

    void setVerticalSpacing(int verticalSpacing);

    void setScroll(int scroll);

    void scrollView(int scroll);
    void setFocusColor(QString focusColor);

    void setHasFocus(bool hasFocus);

    void setBgColor(QColor bgColor)
    {
        m_bgColor = bgColor;
    }

signals:
    void scrollChanged(int scroll);
    void selectItem(QWidget *widget);
    void selectItemValue(QVariant value);
    void selectItemDouble(QWidget *widget);
    void selectItemValueDouble(QVariant value);
private:
    bg bgFun;

    QImage bgImage;
    QList<QVariant> valueList;
    ListItem *item;
    QList<QWidget *> itemList;
    QScrollBar *hScrollBar;
    QMargins m_padding;
    
    int m_spacing;
    
    int m_horizontalSpacing;

    int m_verticalSpacing;

    int m_scroll=0;

    int detaX=0;

    int lastWidth=0;

    void setFocus(QWidget *focusWidget);
    QString m_focusColor;

    bool m_hasFocus;

    void updateResize();

    QColor m_bgColor;

protected:
    void resizeEvent(QResizeEvent *event);

    // QObject interface
public:
    bool eventFilter(QObject *watched, QEvent *event);
    QString focusColor() const;
    bool hasFocus() const;


    void setBgFun(const bg &value);

    void setBgImage(const QImage &value);

    QColor bgColor() const
    {
        return m_bgColor;
    }

protected:
    void paintEvent(QPaintEvent *event);
};

#endif // GRIDVIEW_H
