#ifndef PULLDOWNLIST_H
#define PULLDOWNLIST_H

#include "fwidget.h"
#include "pulldownlistitem.h"
#include <QLabel>
#include <QPushButton>
#include <QVariant>
#include <qframe.h>

#include <widget/view/listview.h>


class PullDownList:public QFrame
{
    Q_OBJECT
public:
    PullDownList(QWidget *parent=0);

    QVariant currentData() const;

    QList<QVariant> listData() const;


    FWidget *item() const;

    int listMaxinumHeight() const;


    QString verticalScrollPageColor() const;


    QString verticalScrollHandleColor() const;


    QString bgColor() const;

    void setWidgetFactory(const WidgetFactory &widgetFactory);

    WidgetFactory widgetFactory() const;

public slots:
    void setBgColor(const QString &bgColor);
    void setVerticalScrollHandleColor(const QString &verticalScrollHandleColor);
    void setVerticalScrollPageColor(const QString &verticalScrollPageColor);
    void setListData(const QList<QVariant> &listData);
    void setCurrentData(const QVariant &currentData);
    void setItem(FWidget *item);
    void setListMaxinumHeight(int listMaxinumHeight);
signals:
    void listItemSelect(QVariant item);
private slots:
    void showPushDownList();
private:
    FWidget *m_item=NULL;
    QList<QVariant> m_listData;
    QVariant m_currentData;
    QPushButton *pushBtn;
    QString m_verticalScrollPageColor="#f9f9f9";
    QString m_verticalScrollHandleColor="#ccc";
    QString m_bgColor="#f9f9f9";
    ListView *list=NULL;
    int m_listMaxinumHeight=300;
    void createView();
    void createDataListFrame();
    WidgetFactory m_widgetFactory;


    // QWidget interface
protected:
    void resizeEvent(QResizeEvent *event);

    void paintEvent(QPaintEvent *event);
};

#endif // PULLDOWNLIST_H
