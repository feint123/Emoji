#include "fileutil.h"

#include <QCryptographicHash>

FileUtil::FileUtil()
{

}

bool FileUtil::isSame(QIODevice dev1, QIODevice dev2)
{

    QByteArray r1=QCryptographicHash::hash(dev1.readAll(),QCryptographicHash::Md5);
    QByteArray r2=QCryptographicHash::hash(dev2.readAll(),QCryptographicHash::Md5);
    if(r1==r2)
        return true;
    else
        return false;
}
