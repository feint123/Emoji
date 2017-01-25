#ifndef IMAGEFRAME_H
#define IMAGEFRAME_H

#include <QFrame>



class ImageFrame:public QFrame
{
    Q_OBJECT
    Q_PROPERTY(int scalePercent READ scalePercent WRITE setScalePercent NOTIFY scalePercentChanged)
    Q_PROPERTY(QString imageAlt READ imageAlt WRITE setImageAlt)
    Q_PROPERTY(QString imageFile READ imageFile WRITE setImageFile)
public:
    ImageFrame(QWidget *parent=0);

    int scalePercent() const;

    QString imageAlt() const;

    QString imageFile() const;

public slots:
    void setScalePercent(int scalePercent);

    void setImageAlt(QString imageAlt);

    void setImageFile(QString imageFile);

    void scaleImage(int scalePercent);
signals:
    void scalePercentChanged(int scalePercent);

protected:
    void paintEvent(QPaintEvent *event);

private:

    int m_scalePercent;
    QString m_imageAlt;
    QString m_imageFile;

    QImage image;
    QPixmap pix;
};

#endif // IMAGEFRAME_H
