#include "basetool.h"

#include <qpainter.h>

#include <util/appcolorhelper.h>

BaseTool::BaseTool(QWidget *parent):
    QDialog(parent)
{
    setObjectName("tool");
    setStyleSheet(tr("#tool{border-image:url(%4)}"
                  "QPushButton{border:none;"
                  "border-image:url(%1);color:%2;padding-left:8px;padding-right:8px;}"
                     "QPushButton:pressed{border-image:url(%3)}")
                  .arg(":/image/tool_btn_normal.png").arg(AppColorHelper::colorBot())
                  .arg(":/image/tool_btn_click.png").arg(":/image/tool_bar.svg"));


     setWindowFlags(Qt::FramelessWindowHint);
}

