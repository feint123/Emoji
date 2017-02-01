#ifndef ABSTRACTTABBAR_H
#define ABSTRACTTABBAR_H

#include <QFrame>
#include <QPropertyAnimation>
#include <qpushbutton.h>



class AbstractTabBar:public QFrame
{
    Q_OBJECT
public:
    AbstractTabBar(QWidget *parent);
    void addTab(QPushButton *btn);

    void createView(int i);

signals:
    void itemClicked(int i);

private:
    QPropertyAnimation *anim;
protected:
    void dealCheck(QObject *watched);

    QList<QPushButton *> btnList;

    QPushButton *checkButton;

    bool isSameBtn=false;

    void updateBtnState(QObject *watched);

    virtual QPropertyAnimation *createAnim();

    virtual void startAnim(QPropertyAnimation *anim);



public:
    bool eventFilter(QObject *watched, QEvent *event);
};

#endif // ABSTRACTTABBAR_H
