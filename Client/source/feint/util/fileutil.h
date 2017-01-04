#ifndef FILEUTIL_H
#define FILEUTIL_H

#include <QIODevice>



class FileUtil
{
public:
    FileUtil();
    static bool isSame(QIODevice dev1,QIODevice dev2);
};

#endif // FILEUTIL_H
