#ifndef TIMERMANAGER_H
#define TIMERMANAGER_H

#include <QHash>
#include <QObject>
#include <QTimer>



class TimerManager:public QObject
{
    Q_OBJECT
public:
    static TimerManager* getInstance(QObject *parent=0);
    void addTimer(QString tag);

    QTimer * getTimer(QString tag);
private:
    static TimerManager *manager;
    TimerManager(QObject *parent);

    QHash<QString,QTimer *> timerList;

};

#endif // TIMERMANAGER_H
