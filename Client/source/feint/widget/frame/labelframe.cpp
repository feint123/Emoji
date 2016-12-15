#include "labelframe.h"

#include <QHBoxLayout>

LabelFrame::LabelFrame(QWidget *parent):
    QFrame(parent)
{
    edit=new QLineEdit();
    QHBoxLayout *hb=new QHBoxLayout();
    hb->addWidget(edit);
}
