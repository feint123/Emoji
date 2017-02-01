#ifndef FWIDGET_H
#define FWIDGET_H

#include <QWidget>
#include <qvariant.h>



class FWidget:public QWidget
{
    Q_OBJECT
public:
    FWidget(QWidget *parent);

    QVariant data() const;

public slots:
    void setData(QVariant data);

private:
    QVariant m_data;
};

#endif // FWIDGET_H
