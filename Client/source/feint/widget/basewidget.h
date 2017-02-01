#ifndef BASEWIDGET_H
#define BASEWIDGET_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QWidget>

class BaseWidget:public QMainWindow
{
    Q_OBJECT

public:
    BaseWidget(QWidget *parent=0);


    void setDragRect(const QRect &value);

public slots:
    void maxWindow();
    void minWindow();
    void closeWindow();

private:
    QRect dragRect;

    QPoint dragStart;

    bool canDrag;

    QRect currentRegin;

    bool isMaxWindow=false;

    bool isInDragRect(QPoint p);
    // QWidget interface
protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseDoubleClickEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);


};

#endif // BASEWIDGET_H
