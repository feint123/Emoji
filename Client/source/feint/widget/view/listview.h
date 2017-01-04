#ifndef LISTVIEW_H
#define LISTVIEW_H

#include "listitem.h"

#include <QBoxLayout>
#include <QMouseEvent>
#include <QWidget>

#include <util/graphic/feintsetting.h>

namespace Ui {
class ListView;
}

class ListView : public QWidget,public FeintSetting
{
    Q_OBJECT
public:
    enum Orien{
          Horizontal,
          Vertical
      };
      explicit ListView(QWidget * parent=0);
      ~ListView();
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
      QList<QWidget *> itemList;
      ListItem *item;
      void mousePressEvent(QMouseEvent *event);
      Ui::ListView *ui;

      QString baseStyle;

      // FeintSetting interface
public:
      void createDailyStyle();
      void createDarkStyle();
};

#endif // LISTVIEW_H
