#include "qvariantutil.h"

QVariantUtil::QVariantUtil()
{

}

QList<QVariant> QVariantUtil::turnString(QStringList sList)
{
    QList<QVariant> qList;
    for(QString str:sList)
        qList.append(QVariant::fromValue(str));

    return qList;
}
