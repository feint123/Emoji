#ifndef IMAGEDIALOG_H
#define IMAGEDIALOG_H

#include "imagecontrol.h"
#include "imageframe.h"

#include <QFrame>
#include <QScrollArea>
#include <QScrollBar>



class ImageDialog:public QFrame
{
    Q_OBJECT
    Q_PROPERTY(int scalePercent READ scalePercent WRITE setScalePercent NOTIFY scalePercentChanged)
    Q_PROPERTY(QString imageAlt READ imageAlt WRITE setImageAlt)
    Q_PROPERTY(QString imageFile READ imageFile WRITE setImageFile NOTIFY imageFileChanged)
public:
    ImageDialog(QWidget *parent=0);

    int scalePercent() const;

    QString imageAlt() const;

    QString imageFile() const;

public slots:
    void setScalePercent(int scalePercent);

    void setImageAlt(QString imageAlt);

    void setImageFile(QString imageFile);

    void loadImage(QString imageFile);

    void showScalePercent(int scale);

signals:
    void scalePercentChanged(int scalePercent);

    void imageFileChanged(QString imageFile);

private:
    QScrollBar *vScroll;
    QScrollBar *hScroll;
    ImageControl *control;
    ImageFrame *image;
    int m_scalePercent;
    QString m_imageAlt;
    QString m_imageFile;

    QScrollArea *area;

    void createControl();

    // QWidget interface
protected:
    void resizeEvent(QResizeEvent *event);

};

#endif // IMAGEDIALOG_H
