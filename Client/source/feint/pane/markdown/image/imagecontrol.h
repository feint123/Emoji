#ifndef IMAGECONTROL_H
#define IMAGECONTROL_H

#include <QFrame>
#include <fbutton.h>



class ImageControl:public QFrame

{
    Q_OBJECT
    Q_PROPERTY(int scale READ scale WRITE setScale NOTIFY scaleChanged)
    Q_PROPERTY(int increase READ increase WRITE setIncrease)
public:
    ImageControl(QWidget *parent);

    int scale() const;

    int increase() const;

public slots:
    void setScale(int scale);

    void setIncrease(int increase);

    void zoomInImage();
    void zoomOutImage();
    void restoreImage();
    void outImage();

signals:
    void scaleChanged(int scale);

private:
    FButton *zoomIn;
    FButton *zoomOut;
    FButton *restore;
    FButton *out;

    void createView();

    FButton *createBasicBtn(QIcon icon);
    int m_scale;
    int m_increase;

    QList<FButton *> btnList;

    // QWidget interface
protected:
    void paintEvent(QPaintEvent *event);
    void resizeEvent(QResizeEvent *event);

};

#endif // IMAGECONTROL_H
