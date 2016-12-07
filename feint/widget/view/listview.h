#ifndef LISTVIEW_H
#define LISTVIEW_H

#include "listitem.h"

#include <QScrollArea>
#include <QBoxLayout>
#include <QVariant>


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
signals:
    void selectItemIndex(int index);

    void selectItem(void* item);
private:
    QList<QVariant> data;
    QBoxLayout *box;

};

#endif // LISTVIEW_H
