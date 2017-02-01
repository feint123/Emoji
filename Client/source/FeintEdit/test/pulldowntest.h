#ifndef PULLDOWNTEST_H
#define PULLDOWNTEST_H

#include <qwidget.h>

#include <view/pulldownlist/pulldownlist.h>



class PullDownTest:public QWidget
{
    Q_OBJECT
public:
    PullDownTest(QWidget *parent=0);

private:
    void createPullDown();
    PullDownList *pull;
    // QWidget interface
protected:
    void resizeEvent(QResizeEvent *event);
};

#endif // PULLDOWNTEST_H
