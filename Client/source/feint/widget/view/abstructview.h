#ifndef ABSTRUCTVIEW_H
#define ABSTRUCTVIEW_H

#include "listitem.h"

#include <qframe.h>
#include <qscrollbar.h>



class AbstructView:public QFrame
{
    Q_OBJECT
    Q_PROPERTY(int scroll READ scroll WRITE setScroll NOTIFY scrollChanged)
    Q_PROPERTY(int focusIndex READ focusIndex WRITE setFocusIndex NOTIFY focusIndexChanged)
    Q_PROPERTY(QString selectStyle READ selectStyle WRITE setSelectStyle)
    Q_PROPERTY(QString unSelectStyle READ unSelectStyle WRITE setUnSelectStyle)
    Q_PROPERTY(QMargins margin READ margin WRITE setMargin NOTIFY marginChanged)
    Q_PROPERTY(int spacing READ spacing WRITE setSpacing)
    Q_PROPERTY(int horizontalSpacing READ horizontalSpacing WRITE setHorizontalSpacing)
    Q_PROPERTY(int verticalSpacing READ verticalSpacing WRITE setVerticalSpacing )
    Q_PROPERTY(QColor bgColor READ bgColor WRITE setBgColor)
    Q_PROPERTY(QString scrollHandle READ scrollHandle WRITE setScrollHandle)
    Q_PROPERTY(QString scrollPage READ scrollPage WRITE setScrollPage)

protected:
    virtual void layout();
    virtual int maxSize();
    virtual void createScroll();
public:
    AbstructView(QWidget *parent);
    void setDatas(QList<QVariant> datas);
    void addDatas(QList<QVariant> datas);
    void addData(QVariant data);
    bool deleteData(QVariant data);
    void setItem(ListItem* item);

    int scroll() const
    {
        return m_scroll;
    }

    int focusIndex() const
    {
        return m_focusIndex;
    }

    QString selectStyle() const
    {
        return m_selectStyle;
    }

    QString unSelectStyle() const
    {
        return m_unSelectStyle;
    }

    QMargins margin() const
    {
        return m_margin;
    }

    int spacing() const
    {
        return m_spacing;
    }

    int horizontalSpacing() const
    {
        return m_horizontalSpacing;
    }

    int verticalSpacing() const
    {
        return m_verticalSpacing;
    }

    QColor bgColor() const
    {
        return m_bgColor;
    }

    QString scrollHandle() const
    {
        return m_scrollHandle;
    }

    QString scrollPage() const
    {
        return m_scrollPage;
    }

public slots:
    void setScroll(int scroll)
    {
        if (m_scroll == scroll)
            return;

        m_scroll = scroll;
        emit scrollChanged(scroll);
    }

    void setFocusIndex(int focusIndex)
    {
        if (m_focusIndex == focusIndex)
            return;

        m_focusIndex = focusIndex;
        emit focusIndexChanged(focusIndex);
    }

    void setSelectStyle(QString selectStyle)
    {
        m_selectStyle = selectStyle;
    }

    void setUnSelectStyle(QString unSelectStyle)
    {
        m_unSelectStyle = unSelectStyle;
    }

    void setMargin(QMargins margin)
    {
        if (m_margin == margin)
            return;

        m_margin = margin;
        emit marginChanged(margin);
    }

    void setSpacing(int spacing)
    {
        m_spacing = spacing;
    }

    void setHorizontalSpacing(int horizontalSpacing)
    {
        m_horizontalSpacing = horizontalSpacing;
    }

    void setVerticalSpacing(int verticalSpacing)
    {
        m_verticalSpacing = verticalSpacing;
    }

    void setBgColor(QColor bgColor)
    {
        m_bgColor = bgColor;
    }

    void setScrollHandle(QString scrollHandle)
    {
        m_scrollHandle = scrollHandle;
    }

    void setScrollPage(QString scrollPage)
    {
        m_scrollPage = scrollPage;
    }

signals:
    void scrollChanged(int scroll);

    void focusIndexChanged(int focusIndex);

    void marginChanged(QMargins margin);

private:
    QList<QWidget *> itemList;
    QList<QVariant> datas;
    ListItem *item;
    QScrollBar *scrollBar;
    int m_scroll;
    int m_focusIndex;
    QString m_selectStyle;
    QString m_unSelectStyle;
    QMargins m_margin;
    int m_spacing;
    int m_horizontalSpacing;
    int m_verticalSpacing;
    QColor m_bgColor;
    QString m_scrollHandle;
    QString m_scrollPage;
};

#endif // ABSTRUCTVIEW_H
