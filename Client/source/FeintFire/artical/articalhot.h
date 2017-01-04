#ifndef ARTICALHOT_H
#define ARTICALHOT_H

#include <QLabel>



class ArticalHot:public QLabel
{
    Q_OBJECT
    Q_PROPERTY(double hot READ hot WRITE setHot NOTIFY hotChanged)
public:
    ArticalHot(QWidget* parent);


    double hot() const;
public slots:
    void setHot(double hot);
signals:
    void hotChanged(double hot);
private:
    double m_hot;
    QStringList colorList;
    void paintEvent(QPaintEvent *event);
    int minWidth;
};

#endif // ARTICALHOT_H
