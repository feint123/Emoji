#include "appmessage.h"

AppMessage::AppMessage()
{

}

QByteArray AppMessage::getFileName(AppMessage::TYPE type)
{
    switch (type) {
    case RECIRCLE:
        return "recircles";
    case ALL:
        return "all";
    case MSG:
        return "messages";
    case LASTEDIT:
        return "lastedits";
    default:
        break;
    }
}
