#ifndef LISTVIEW_H
#define LISTVIEW_H

#include "listitem.h"

#include <QScrollArea>
#include <QBoxLayout>
#include <QVariant>
#include <QMouseEvent>


class ListView:public QScrollArea
{
    Q_OBJECT
public:
    enum Orien{
        Horizontal,
        Vertical
    };
    ListView();
    void setOrientation(Orien orien=ListView::Vertical);

    void setData(QList<QVariant> data);

    void setItem(ListItem* item);

    void setBackgroundColor(QColor color);

    int firstVisibleItemIndex();



    void setItemSpacing(int space);

signals:
    void selectItemIndex(int index);

    void selectItem(QVariant dataItem);
private:
    QList<QVariant> data;
    QBoxLayout *box;
    QWidget *widget;
    QList<QWidget *> itemList;
    ListItem *item;
    void mousePressEvent(QMouseEvent *event);

};

#endif // LISTVIEW_H
