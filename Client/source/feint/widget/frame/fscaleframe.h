#ifndef FSCALEFRAME_H
#define FSCALEFRAME_H

#include <QFrame>



class FScaleFrame:public QFrame

{
    Q_PROPERTY(int shadow READ shadow WRITE setShadow)
    Q_OBJECT
public:
    FScaleFrame(QWidget* parent=0);
    double getScale() const;
    void setScale(double value=1.05);

    int shadow() const;

public slots:
    void setShadow(int shadow);

private:
    void enterEvent(QEvent*);
    void leaveEvent(QEvent*);
    bool isFirstIn=true;
    QRect frameRect;
    double scale;
    int m_shadow;
};

#endif // FSCALEFRAME_H
