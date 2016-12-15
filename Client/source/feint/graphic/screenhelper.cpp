#include "screenhelper.h"

#include <QApplication>
#include <QDesktopWidget>

ScreenHelper::ScreenHelper()
{

}

/**
 * 获取屏幕的尺寸
 * @brief ScreenHelper::getScreenSize
 * @return
 */
QSize ScreenHelper::getScreenSize()
{
    QDesktopWidget* desktop=QApplication::desktop();
    QRect avaliable=desktop->availableGeometry();
    return QSize(avaliable.width(),avaliable.height());
}
