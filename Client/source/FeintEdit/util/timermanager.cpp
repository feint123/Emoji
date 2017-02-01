#include "timermanager.h"
TimerManager *TimerManager::manager=NULL;
TimerManager::TimerManager(QObject *parent):
    QObject(parent)
{

}

TimerManager *TimerManager::getInstance(QObject *parent)
{
    if(manager==NULL)
        manager=new TimerManager(parent);
    return manager;
}

void TimerManager::addTimer(QString tag)
{
    QTimer *timer=new QTimer();
    timerList[tag]=timer;
}

QTimer *TimerManager::getTimer(QString tag)
{
    return timerList[tag];
}
