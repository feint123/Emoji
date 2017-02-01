#include "fwidget.h"
#include <QDebug>
FWidget::FWidget(QWidget *parent):
    QWidget(parent)
{

}

void FWidget::setData(QVariant data)
{

}

QVariant FWidget::data() const
{
    return m_data;
}
