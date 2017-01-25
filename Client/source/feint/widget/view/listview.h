#ifndef LISTVIEW_H
#define LISTVIEW_H

#include "listitem.h"

#include <QBoxLayout>
#include <QFrame>
#include <QMouseEvent>
#include <QScrollBar>
#include <QWidget>

#include <util/graphic/feintsetting.h>
typedef void (*Background)(QPaintDevice *device,const QImage &image,const QColor &color);
class ListView : public QFrame,public FeintSetting
{
    Q_OBJECT
    Q_PROPERTY(int scrollY READ scrollY WRITE setScrollY NOTIFY scrollYChanged)
    Q_PROPERTY(int focusIndex READ focusIndex WRITE setFocusIndex NOTIFY focusIndexChanged)
    Q_PROPERTY(QString selectStyle READ selectStyle WRITE setSelectStyle)
    Q_PROPERTY(QString unSelectStyle READ unSelectStyle WRITE setUnSelectStyle)
    Q_PROPERTY(QMargins margin READ margin WRITE setMargin NOTIFY marginChanged)
    Q_PROPERTY(int spacing READ spacing WRITE setSpacing)
    Q_PROPERTY(QColor bgColor READ bgColor WRITE setBgColor)
    Q_PROPERTY(QRect contentsRect READ contentsRect WRITE setContentsRect)
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

      void createDailyStyle();
      void createDarkStyle();
      QWidget *getCurrentWidget() const;
      QVariant getCurrentItem() const;
      int scrollY() const;
      int focusIndex() const;
      bool eventFilter(QObject *watched, QEvent *event);
      QString selectStyle() const;
      QString unSelectStyle() const;

      QMargins margin() const;

      int spacing() const;

      QRect contentsRect() const;

      QColor bgColor() const;

      void setBg(Background value);

public slots:
      void setScrollY(int scrollY);
      void createFocus();
      void changeFocus();
      void setFocusIndex(int focusIndex);

      // QObject interface
      void setSelectStyle(QString selectStyle);

      void setUnSelectStyle(QString unSelectStyle);

      void addValue(QVariant variant);

      void removeItem(int i);

      void setMargin(QMargins margin);

      void setSpacing(int spacing);

      void setContentsRect(QRect contentsRect);

      void scrollContent(int scroll);
      void setBgColor(QColor bgColor);

signals:
      void selectItemIndex(int index);

      void selectItem(QVariant dataItem);

      void selectItemDouble(QVariant dataItem);

      void scrollYChanged(int scrollY);

      void focusIndexChanged(int focusIndex);

      void marginChanged(QMargins margin);

private:
      QScrollBar *vScroll;
      ListItem *item;
      QList<QVariant> data;
      QBoxLayout *box;
      QList<QWidget *> itemList;
      QString baseStyle;
      Background bg=NULL;
      // FeintSetting interface
      int m_scrollY=-1;

      int m_focusIndex=-1;

      QString m_selectStyle;

      QString m_unSelectStyle;

      QMargins m_margin=QMargins(0,0,0,0);

      void horizontalLayout();

      void verticalLayout();

      int getContentHeight();

      int m_spacing=0;

      bool canScrollShow=false;
      // QWidget interface
      QRect m_contentsRect;

      QColor m_bgColor;

protected:
      void resizeEvent(QResizeEvent *event);

      void mouseMoveEvent(QMouseEvent *event);

      void wheelEvent(QWheelEvent *event);

      void paintEvent(QPaintEvent *event);
};

#endif // LISTVIEW_H
