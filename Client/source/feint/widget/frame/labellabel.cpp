#include "labellabel.h"

LabelLabel::LabelLabel(QWidget *parent):
    QLabel(parent)
{
    this->setStyleSheet(tr("background:#404244;;color:#f9f9f9;border-radius:5px;padding:0px 4px;max-height:24px;"
                           "border:2px solid #f59d49;"));

}

LabelLabel::LabelLabel(const QString &text)
{
    this->text()=text;
}

LabelLabel::~LabelLabel()
{

}


void LabelLabel::mouseDoubleClickEvent(QMouseEvent *evnet)
{  
    emit removeLabel(this->realText);
    this->close();
}

QString LabelLabel::getRealText() const
{
    return realText;
}

void LabelLabel::setRealText(const QString &value)
{
    realText = value;
}
