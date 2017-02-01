#ifndef MARKITEM_H
#define MARKITEM_H

#include <qlabel.h>

#include <view/pulldownlist/fwidget.h>



class MarkItem:public FWidget
{
    Q_OBJECT
public:
    MarkItem(QWidget *parent=0);
    void setData(QVariant data);
    void setText(const QString &text);
private:
    QLabel *label;


    // QWidget interface
protected:
    void resizeEvent(QResizeEvent *event);
};

#endif // MARKITEM_H
