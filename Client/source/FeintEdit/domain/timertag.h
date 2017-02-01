#ifndef TIMERTAG_H
#define TIMERTAG_H

#include <QHash>



class TimerTag
{
public:
    enum{
        NOTE_NUM_CHANGE,
        NOTEBOOK_CHANGE,
    };
    TimerTag();
    static void init();
    static QString tag(int e);
private:
    static QHash<int,QString> tagH;
};

#endif // TIMERTAG_H
