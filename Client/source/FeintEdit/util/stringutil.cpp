#include "stringutil.h"

StringUtil::StringUtil()
{

}

QString StringUtil::fitToLength(QString str,int length)
{
    if(str.length()<length)
        return str;
    else
        return str.mid(0,length-3)+"...";
}
