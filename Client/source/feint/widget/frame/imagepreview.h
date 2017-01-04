#ifndef IMAGEPREVIEW_H
#define IMAGEPREVIEW_H

#include <QFrame>
#include <QPaintEvent>



class ImagePreview:public QFrame
{
    Q_OBJECT
    Q_PROPERTY(QString path READ path WRITE setPath)
public:
    ImagePreview(QWidget* parent=0,QSize size=QSize(0,0));
    QString path() const;
    void fixSize(QSize maxSize);
    void fixPosition(QRect imgBtn);

public slots:
    void setPath(QString path);

private:
    void paintEvent(QPaintEvent *event);
    QSize size;
    QString m_path;
    int deta;
    int tri=12;
};

#endif // IMAGEPREVIEW_H
