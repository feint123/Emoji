#ifndef APPMESSAGE_H
#define APPMESSAGE_H

#include <qstring.h>



class AppMessage
{
public:
    enum TYPE{
        RECIRCLE,
        MSG,
        ALL,
        LASTEDIT
    };
    AppMessage();
    static QByteArray getFileName(TYPE type);
};

#endif // APPMESSAGE_H
