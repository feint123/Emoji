#ifndef TRANSFRAME_H
#define TRANSFRAME_H

#include <QFrame>



class TransFrame:public QFrame
{
    Q_OBJECT
public:
    TransFrame(QWidget *parent=0);

private:
    void paintEvent(QPaintEvent *evnet);
};

#endif // TRANSFRAME_H
