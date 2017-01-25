#ifndef QVARIANTUTIL_H
#define QVARIANTUTIL_H

#include <QVariant>



class QVariantUtil
{
public:
    QVariantUtil();
    template<typename T>
    QList<QVariant> turn(QList<T*> tList){
        QList<QVariant> list;
        for(T* t:tList)
        {
            QVariant variant=QVariant::fromValue(*t);
            list.append(variant);
        }
        return list;
    }
};

#endif // QVARIANTUTIL_H
