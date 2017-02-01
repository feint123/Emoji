#ifndef FLABELWIDGET_H
#define FLABELWIDGET_H

#include <view/pulldownlist/fwidget.h>

#include <QLabel>



class FLabelWidget:public FWidget
{
    Q_OBJECT
public:
    FLabelWidget(QWidget *parent=0);

public slots:
    void setData(QVariant data);

private:
    QLabel *text;

    // QWidget interface
protected:
    void resizeEvent(QResizeEvent *event);
};

#endif // FLABELWIDGET_H
