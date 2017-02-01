#ifndef IMAGEPREVIEW_H
#define IMAGEPREVIEW_H

#include <QFrame>
#include <QPaintEvent>

#include <util/fileutil.h>



class ImagePreview:public QFrame
{
    Q_OBJECT
    Q_PROPERTY(QString path READ path WRITE setPath)
    Q_PROPERTY(QString store READ store WRITE setStore)
public:

    QString path() const;
    void fixSize(QSize maxSize);
    void fixPosition(QRect imgBtn);
    ~ImagePreview();
    static ImagePreview* getInstance(QWidget *parent=0);
    QString store() const;

    void setSize(const QSize &value);

public slots:
    void setPath(QString path);

    void setStore(QString store);

private:
    void paintEvent(QPaintEvent *event);
    QSize size;
    QString m_path;
    int deta;
    int tri=12;
    QPixmap loadImage();
    QString m_store;
    ImagePreview(QWidget* parent=0);
    static ImagePreview* preview;

};

#endif // IMAGEPREVIEW_H
