#include "timertag.h"
QHash<int,QString> TimerTag::tagH=QHash<int,QString>();
TimerTag::TimerTag()
{

}

void TimerTag::init()
{
    tagH[NOTE_NUM_CHANGE]="num_change";
    tagH[NOTEBOOK_CHANGE]="notebook_change";
}

QString TimerTag::tag(int e)
{
    return tagH[e];
}
