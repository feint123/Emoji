#include "fobject.h"

#include <QMetaProperty>
#include <string.h>
FObject::FObject()
{

}

QByteArray FObject::toString()
{

    const QMetaObject *meta=this->metaObject();
     QString str=tr(meta->className())+"[";
    for(int i=0;i<meta->propertyCount();i++)
    {
        QMetaProperty pro=meta->property(i);
        str+=(tr(pro.name())+":"+pro.read(this).toString()+", ");
    }
    str+="]";
    return str.toUtf8();
}
